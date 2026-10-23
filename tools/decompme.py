#!/usr/bin/env python3
"""decomp.me helper: build scratch payloads from this project and (opt-in only) upload them.

  tools/decompme.py list [-n 40] [--max-size 0x200] [--min-size 0] [--tu CampStatus]
        unmatched functions (build/report.json), smallest first, with complexity rank if ranked
  tools/decompme.py scratch FUNC [--write DIR] [--check] [--stub] [--dry-run]
        asm + context + current C for FUNC, assembled automatically:
          target_asm  from `dsd dis` (cached in build/asm/), rewritten for decomp.me's
                      nds_arm9 prelude (arm_func_start defines the label; `;` comments dropped)
          context     m2ctx-style: the TU's source run through cpp (-P -dD, include/ + src/),
                      non-inline function bodies replaced by prototypes
          source_code the function's current definition from the TU if it has one, else empty
                      (decomp.me then runs its decompiler on the asm); --stub sends a prototype stub
        --check assembles the asm with the decomp.me prelude and compares it byte-for-byte with the
        delinked target (relocated words masked), and compiles context + source (or a stub) with
        the project's mwccarm through tools/wibo (nice'd). --write saves asm.s/ctx.c/code.c/payload.json.
  tools/decompme.py create --func NAME --asm X.s [--src x.c] [--ctx ctx.h]   (raw files)
  tools/decompme.py create-many --from list.tsv                             (NAME<TAB>asm[<TAB>src])
  --dry-run (before the subcommand) prints the payload and sends nothing.

API (decomp.me source, backend/coreapp/serializers.py + views/scratch.py, cromper platforms.py):
  POST https://decomp.me/api/scratch with name, compiler, platform, compiler_flags, diff_label,
  source_code, target_asm, context. Empty source_code + asm => decomp.me decompiles (m2c).
  nds_arm9 assembles with `arm-none-eabi-as -march=armv5te -mthumb` plus its prelude.
  Response has `slug` and `claim_token`; claim URL is /scratch/<slug>/claim?token=...
  decomp.me sits behind Cloudflare; anonymous creation may be rate limited.
Scratches are PUBLIC. Asm of retail code gets uploaded: the maintainer must opt in
(FORGE_DECOMPME_OK=1), and agents may not set it. Results are appended to config/scratches.tsv.
Payloads are scanned for local identifiers (home paths, user, hostname, git identity) and refused
if any appear; add extra words with DECOMPME_REDACT="word1,word2".
"""
import argparse, getpass, json, os, pathlib, re, shutil, socket, subprocess, sys, tempfile, tomllib
import urllib.error, urllib.request

ROOT = pathlib.Path(__file__).resolve().parent.parent
API = os.environ.get("DECOMPME_API", "https://decomp.me/api")
UA = os.environ.get("DECOMPME_UA", "re-forge/0.1 (+matching decomp pipeline)")
ASM_DIR = ROOT / "build/asm"
DSD_CFG = "config/arm9/config.yaml"
# decomp.me cromper/asm_preludes/nds_arm9.s (verbatim, 2026-10-22)
PRELUDE = """.macro glabel label
    .global \\label
    .thumb
    \\label:
.endm

.macro arm_func_start name
    .arm
    \\name:
.endm
.macro arm_func_end name
.endm
.macro thumb_func_start name
    .thumb
    \\name:
.endm
.macro non_word_aligned_thumb_func_start name
    .thumb
    \\name:
.endm
.macro thumb_func_end name
.endm
"""


def cfg():
    p = ROOT / "config/decompme.toml"
    c = tomllib.loads(p.read_text()) if p.exists() else {}
    tc = tomllib.loads((ROOT / "config/toolchain.toml").read_text())
    c.setdefault("compiler", tc.get("decompme_compiler", "mwcc_30_131"))
    c.setdefault("compiler_flags", tc["cflags"])
    c.setdefault("platform", "nds_arm9")
    return c


def toolchain():
    return tomllib.loads((ROOT / "config/toolchain.toml").read_text())


# ---------------------------------------------------------------- project lookups
def report():
    p = ROOT / "build/report.json"
    if not p.exists():
        raise SystemExit("build/report.json missing: run ninja, then objdiff-cli report generate -o build/report.json")
    return json.loads(p.read_text())


def objdiff_units():
    return {u["name"]: u for u in json.loads((ROOT / "objdiff.json").read_text())["units"]}


def find_func(name):
    """(unit report entry, function entry) for a function name or 0x address."""
    addr = None
    if re.fullmatch(r"(0x)?[0-9a-fA-F]{7,8}", name):
        addr = int(name, 16)
    for u in report()["units"]:
        for f in u.get("functions", []):
            if f["name"] == name or (addr and f["name"].endswith(f"{addr:08x}")):
                return u, f
    raise SystemExit(f"{name}: not in build/report.json")


def ranks():
    p = ROOT / "docs/complexity_ranking.md"
    out = {}
    if p.exists():
        for line in p.read_text().splitlines():
            m = re.match(r"\|\s*(\d+)\s*\|\s*`([^`]+)`", line)
            if m:
                out[m[2]] = int(m[1])
    return out


def skips():
    p = ROOT / "tools/hand/skips.json"
    try:
        return set(json.loads(p.read_text()))
    except Exception:
        return set()


# ---------------------------------------------------------------- asm
def asm_file(unit):
    src = ROOT / "config/arm9/delinks.txt"
    stamp = ASM_DIR / ".stamp"
    if not stamp.exists() or stamp.stat().st_mtime < src.stat().st_mtime:
        shutil.rmtree(ASM_DIR, ignore_errors=True)
        tc = toolchain()
        subprocess.run(["nice", "-n", "10", tc.get("dsd", "./dsd"), "dis", "-c", DSD_CFG,
                        "-a", str(ASM_DIR), "-u"], cwd=ROOT, check=True, capture_output=True)
        stamp.touch()
    p = ASM_DIR / f"{unit}.s"
    if not p.exists():
        raise SystemExit(f"no disassembly for unit {unit} ({p})")
    return p


def strip_comment(line):
    return line.split(";", 1)[0].rstrip()


def func_asm(unit, func):
    lines = asm_file(unit).read_text().splitlines()
    start = end = None
    for i, l in enumerate(lines):
        s = l.strip()
        if re.fullmatch(rf"(arm|thumb|non_word_aligned_thumb)_func_start {re.escape(func)}", s):
            start = i
        elif start is not None and re.fullmatch(rf"(arm|thumb)_func_end {re.escape(func)}", s):
            end = i; break
    if start is None or end is None:
        raise SystemExit(f"{func}: not found in {asm_file(unit)}")
    head = ["    .syntax unified", "    .text", f"    .global {func}"]
    body = []
    for l in lines[start:end + 1]:
        if re.match(rf"\s*{re.escape(func)}:", l):   # the prelude macro defines the label
            continue
        l = strip_comment(l)
        if l.strip():
            body.append(l)
    return "\n".join(head + body) + "\n"


# ---------------------------------------------------------------- C scanning
def _skip(text, i):
    """Index after a comment/string/char literal starting at i, or i if none starts there."""
    if text.startswith("//", i):
        j = text.find("\n", i); return len(text) if j < 0 else j
    if text.startswith("/*", i):
        j = text.find("*/", i + 2); return len(text) if j < 0 else j + 2
    if text[i] in "\"'":
        q, j = text[i], i + 1
        while j < len(text) and text[j] != q:
            j += 2 if text[j] == "\\" else 1
        return j + 1
    return i


def top_level_bodies(text):
    """Yield (header_start, brace_open, brace_close) for top-level function definitions."""
    i, depth, stmt = 0, 0, 0
    n = len(text)
    while i < n:
        j = _skip(text, i)
        if j != i:
            i = j; continue
        c = text[i]
        if depth == 0 and c == "#" and (i == 0 or text[i - 1] == "\n"):
            j = text.find("\n", i)
            while j > 0 and text[j - 1] == "\\":
                j = text.find("\n", j + 1)
            i = n if j < 0 else j + 1; stmt = i; continue
        if c == "{":
            if depth == 0:
                k = i - 1
                while k >= 0 and text[k].isspace():
                    k -= 1
                if k >= 0 and text[k] == ")" and "=" not in text[stmt:i]:
                    d, m = 0, i
                    while m < n:
                        mm = _skip(text, m)
                        if mm != m:
                            m = mm; continue
                        if text[m] == "{": d += 1
                        elif text[m] == "}":
                            d -= 1
                            if d == 0: break
                        m += 1
                    yield stmt, i, m
                    i = m + 1; stmt = i; continue
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0: stmt = i + 1
        elif c == ";" and depth == 0:
            stmt = i + 1
        i += 1


def func_name_of(header):
    m = re.search(r"([A-Za-z_]\w*)\s*\([^()]*(\([^()]*\)[^()]*)*\)\s*$", header.strip())
    return m[1] if m else None


def strip_bodies(text):
    out, last = [], 0
    for s, o, c in top_level_bodies(text):
        header = text[s:o]
        if re.search(r"\binline\b", header):
            continue
        out.append(text[last:o].rstrip() + ";\n"); last = c + 1
    out.append(text[last:])
    return "".join(out)


def func_definition(text, func):
    for s, o, c in top_level_bodies(text):
        if func_name_of(text[s:o]) == func:
            return text[s:c + 1].strip() + "\n"
    return None


def preprocess(path):
    tc = toolchain()
    cmd = ["cpp", "-P", "-dD", "-nostdinc", "-undef", "-D__MWERKS__=0x4000", "-D__arm",
           "-I", str(ROOT / "include"), "-I", str(ROOT / "src"), str(path)]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f"cpp failed on {path}:\n{r.stderr[:1000]}")
    keep = [l for l in r.stdout.splitlines()
            if not re.match(r"#(define|undef)\s+(__\w+|_\w+__)\b", l)]
    return "\n".join(keep) + "\n"


def context_for(unit_entry):
    src = unit_entry.get("metadata", {}).get("source_path")
    if src and (ROOT / src).is_file():
        return strip_bodies(preprocess(ROOT / src)), ROOT / src
    with tempfile.NamedTemporaryFile("w", suffix=".c", delete=False) as t:
        t.write('#include "types.h"\n')
    try:
        return preprocess(t.name), None
    finally:
        os.unlink(t.name)


def prototype(func):
    """A declaration of func from any src/ file, as (ret, args), else None."""
    pat = re.compile(rf"^\s*(?:extern\s+)?([\w \*]+?)\s*\b{re.escape(func)}\s*\(([^;{{]*?)\)\s*;", re.M)
    for p in sorted((ROOT / "src").rglob("*.c")):
        m = pat.search(p.read_text(errors="replace"))
        if m and "static" not in m[1]:
            return m[1].strip(), m[2].strip()
    return None


def stub(func, ctx):
    proto = None
    m = re.search(rf"([\w \*]+?)\s*\b{re.escape(func)}\s*\(([^;{{]*?)\)\s*;", ctx)
    if m:
        proto = (m[1].strip().split("\n")[-1].strip(), m[2].strip())
    proto = proto or prototype(func) or ("void", "void")
    ret, args = proto
    if not args:
        args = "void"
    body = "" if re.fullmatch(r"(static\s+)?void", ret) else "    return 0;\n"
    return f"{ret} {func}({args}) {{\n{body}}}\n"


# ---------------------------------------------------------------- payload
def redaction_words():
    words = set()
    for w in (os.environ.get("USER"), getpass.getuser(), socket.gethostname().split(".")[0],
              str(pathlib.Path.home())):
        if w and len(w) > 2:
            words.add(w)
    for k in ("user.name", "user.email"):
        r = subprocess.run(["git", "config", "--global", k], capture_output=True, text=True)
        if r.stdout.strip():
            words.add(r.stdout.strip())
    words |= {w.strip() for w in os.environ.get("DECOMPME_REDACT", "").split(",") if w.strip()}
    return words


def leak_check(data):
    blob = json.dumps(data)
    bad = [w for w in redaction_words() if re.search(rf"(?<![\w]){re.escape(w)}(?![\w])", blob, re.I)]
    if re.search(r"/(home|Users)/\w", blob):
        bad.append("/home/ or /Users/ path")
    if str(ROOT) in blob:
        bad.append(str(ROOT))
    return bad


def build(func, use_stub=False):
    c = cfg()
    unit, f = find_func(func)
    func = f["name"]
    ou = objdiff_units()[unit["name"]]
    asm = func_asm(unit["name"], func)
    ctx, src_path = context_for(ou)
    code = ""
    if src_path:
        code = func_definition(src_path.read_text(errors="replace"), func) or ""
    if not code and use_stub:
        code = stub(func, ctx)
    game = c.get("game", "")
    if game:
        # Tag every scratch with the game: the name decomp.me lists, and a header in context.
        ctx = f"/* {game}: {unit['name']} ({func}) */\n" + ctx
    data = {"name": f"{c.get('name_prefix', '')}{func}", "diff_label": func, "platform": c["platform"], "compiler": c["compiler"],
            "compiler_flags": c["compiler_flags"], "target_asm": asm, "source_code": code,
            "context": ctx, **({"preset": c["preset"]} if c.get("preset") else {})}
    info = {"unit": unit["name"], "size": int(f.get("size", 0)), "match": f.get("fuzzy_match_percent", 0.0),
            "target_obj": ou.get("target_path"), "source": str(src_path.relative_to(ROOT)) if src_path else None}
    return data, info


def sh(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def text_bytes(obj, td, name):
    out = pathlib.Path(td) / name
    r = sh(["arm-none-eabi-objcopy", "-O", "binary", "-j", ".text", str(obj), str(out)])
    return out.read_bytes() if r.returncode == 0 and out.exists() else b""


def reloc_offsets(obj):
    r = sh(["arm-none-eabi-readelf", "-rW", str(obj)])
    offs, cur = set(), None
    for l in r.stdout.splitlines():
        m = re.match(r"Relocation section '\.rel\.(\S+)'", l)
        if m: cur = m[1]; continue
        m = re.match(r"\s*([0-9a-f]{8})\s+[0-9a-f]+\s+R_ARM_", l)
        if m and cur == "text": offs.add(int(m[1], 16) & ~3)
    return offs


def sym_range(obj, func):
    r = sh(["arm-none-eabi-readelf", "-sW", str(obj)])
    shdr = sh(["arm-none-eabi-readelf", "-SW", str(obj)]).stdout
    text_idx = None
    for l in shdr.splitlines():
        m = re.match(r"\s*\[\s*(\d+)\]\s+\.text\s", l)
        if m: text_idx = m[1]
    for l in r.stdout.splitlines():
        p = l.split()
        if len(p) >= 8 and p[7] == func:
            return int(p[1], 16) & ~1, int(p[2]), p[6] == text_idx
    return None


def check(data, info):
    """Assemble target_asm like decomp.me and compile context+source with mwccarm. Returns problems."""
    probs = []
    tc = toolchain()
    with tempfile.TemporaryDirectory(prefix="dme") as td:
        tdp = pathlib.Path(td)
        (tdp / "prelude.s").write_text(PRELUDE)
        (tdp / "asm.s").write_text(data["target_asm"].replace(";", ";@"))
        r = sh(["arm-none-eabi-as", "-march=armv5te", "-mthumb", "-o", "asm.o", "prelude.s", "asm.s"], cwd=td)
        if r.returncode:
            probs.append("asm does not assemble:\n" + r.stderr[:1500])
        else:
            got = text_bytes(tdp / "asm.o", td, "got.bin")
            tgt_obj = ROOT / info["target_obj"]
            rng = sym_range(tgt_obj, data["diff_label"])
            if not rng or not rng[2]:
                probs.append("could not locate target symbol in .text of the delinked object (byte check skipped)")
            else:
                off, size, _ = rng
                want = text_bytes(tgt_obj, td, "want.bin")[off:off + size]
                mask_t = {o - off for o in reloc_offsets(tgt_obj) if off <= o < off + size}
                mask_g = reloc_offsets(tdp / "asm.o")
                if len(got) != len(want):
                    probs.append(f"assembled size {len(got)} != target size {len(want)}")
                else:
                    diff = [o for o in range(0, size, 4) if o not in mask_t | mask_g and got[o:o + 4] != want[o:o + 4]]
                    if diff:
                        probs.append(f"assembled bytes differ at offsets {[hex(o) for o in diff[:8]]}")
                info["asm_bytes_ok"] = not diff if len(got) == len(want) else False
                info["masked_words"] = len(mask_t | mask_g)
        code = data["source_code"] or stub(data["diff_label"], data["context"])
        (tdp / "t.c").write_text(data["context"] + "\n" + code)
        mw = ROOT / tc["mwcc_dir"] / "mwccarm.exe"
        wine = ROOT / tc.get("wine", "tools/wibo")
        r = sh(["nice", "-n", "10", str(wine), str(mw), *tc["cflags"].split(), "-c", "t.c", "-o", "t.o"], cwd=td)
        if r.returncode or not (tdp / "t.o").exists():
            probs.append("context + source does not compile:\n" + (r.stdout + r.stderr)[:2000])
        info["compiled"] = "stub" if not data["source_code"] else "source"
    return probs


# ---------------------------------------------------------------- upload
def post(data):
    req = urllib.request.Request(f"{API}/scratch", data=json.dumps(data).encode(), method="POST",
                                 headers={"Content-Type": "application/json",
                                          "Accept": "application/json", "User-Agent": UA})
    try:
        with urllib.request.urlopen(req, timeout=60) as r:
            body = json.loads(r.read())
    except urllib.error.HTTPError as e:
        raise SystemExit(f"decomp.me HTTP {e.code}: {e.read()[:300]!r}")
    slug = body["slug"]
    return f"https://decomp.me/scratch/{slug}", body.get("claim_token", "")


def show(data):
    print(json.dumps({k: (v[:200] + f"... [{len(v)} chars]" if isinstance(v, str) and len(v) > 200 else v)
                      for k, v in data.items()}, indent=1))


def send(data, dry):
    if not data["platform"] or not data["compiler"]:
        raise SystemExit("config/decompme.toml needs platform and compiler")
    bad = leak_check(data)
    if bad:
        raise SystemExit(f"refusing: payload contains local identifiers {bad}")
    if dry:
        show(data); return
    if os.environ.get("FORGE_DECOMPME_OK") != "1":
        raise SystemExit("refusing: set FORGE_DECOMPME_OK=1 to upload (scratches are public)")
    url, tok = post(data)
    with open(ROOT / "config/scratches.tsv", "a") as f:
        f.write(f"{data['name']}\t{url}\t{url}/claim?token={tok}\n")
    print(url)


def raw_payload(func, asm, src=None, ctx=None):
    c = cfg()
    return {"name": func, "diff_label": func, "platform": c["platform"], "compiler": c["compiler"],
            "compiler_flags": c["compiler_flags"],
            "target_asm": pathlib.Path(asm).read_text(errors="replace"),
            "source_code": pathlib.Path(src).read_text(errors="replace") if src else "",
            "context": pathlib.Path(ctx).read_text(errors="replace") if ctx else "",
            **({"preset": c["preset"]} if c.get("preset") else {})}


def cmd_list(a):
    rk, sk = ranks(), skips()
    rows = []
    for u in report()["units"]:
        if u["name"].startswith("_dsd_gap") or (a.tu and a.tu.lower() not in u["name"].lower()):
            continue
        if not a.libs and u["name"].startswith("libs/"):
            continue
        for f in u.get("functions", []):
            m = f.get("fuzzy_match_percent", 0.0)
            size = int(f.get("size", 0))
            if m >= 100.0 or size < a.min_size or size > a.max_size:
                continue
            rows.append((size, f["name"], u["name"], m))
    rows.sort()
    print(f"{'size':>6}  {'match':>6}  {'rank':>4}  function{'':24}unit")
    for size, name, unit, m in rows[:a.n]:
        r = rk.get(name, "")
        flag = "  (hand-skip)" if name in sk else ""
        print(f"{size:#6x}  {m:5.1f}%  {r!s:>4}  {name:32}{unit}{flag}")
    print(f"-- {len(rows)} unmatched functions in range; showing {min(a.n, len(rows))}")


def cmd_scratch(a):
    data, info = build(a.func, a.stub)
    print(f"# {data['name']}: unit {info['unit']}, {info['size']:#x} bytes, current match {info['match']:.1f}%, "
          f"source {'from ' + info['source'] if data['source_code'] else ('stub' if a.stub else 'empty (decomp.me will decompile)')}",
          file=sys.stderr)
    if a.write:
        d = pathlib.Path(a.write); d.mkdir(parents=True, exist_ok=True)
        (d / "asm.s").write_text(data["target_asm"]); (d / "ctx.c").write_text(data["context"])
        (d / "code.c").write_text(data["source_code"]); (d / "payload.json").write_text(json.dumps(data, indent=1))
        print(f"# wrote {d}/{{asm.s,ctx.c,code.c,payload.json}}", file=sys.stderr)
    if a.check:
        probs = check(data, info)
        print(f"# check: asm bytes {'match' if info.get('asm_bytes_ok') else 'MISMATCH/unchecked'} "
              f"({info.get('masked_words', 0)} relocated words masked), compile ({info.get('compiled')}) "
              f"{'ok' if not any('compile' in p for p in probs) else 'FAILED'}", file=sys.stderr)
        for p in probs:
            print("# problem: " + p, file=sys.stderr)
        if probs:
            raise SystemExit(1)
    send(data, a.dry_run)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true")
    sub = ap.add_subparsers(dest="cmd", required=True)
    l = sub.add_parser("list"); l.add_argument("-n", type=int, default=40)
    l.add_argument("--max-size", type=lambda s: int(s, 0), default=0x200)
    l.add_argument("--min-size", type=lambda s: int(s, 0), default=0)
    l.add_argument("--tu"); l.add_argument("--libs", action="store_true", help="include libs/ (SDK) units")
    s = sub.add_parser("scratch"); s.add_argument("func")
    s.add_argument("--write"); s.add_argument("--check", action="store_true")
    s.add_argument("--stub", action="store_true", help="send a prototype stub instead of letting decomp.me decompile")
    s.add_argument("--dry-run", action="store_true", dest="dry_run_sub")
    c = sub.add_parser("create"); c.add_argument("--func", required=True)
    c.add_argument("--asm", required=True); c.add_argument("--src"); c.add_argument("--ctx")
    m = sub.add_parser("create-many"); m.add_argument("--from", dest="src_list", required=True)
    a = ap.parse_args(argv)
    if getattr(a, "dry_run_sub", False):
        a.dry_run = True
    if a.cmd == "list":
        cmd_list(a)
    elif a.cmd == "scratch":
        cmd_scratch(a)
    elif a.cmd == "create":
        send(raw_payload(a.func, a.asm, a.src, a.ctx), a.dry_run)
    else:
        for line in open(a.src_list):
            parts = line.rstrip("\n").split("\t")
            if len(parts) >= 2:
                send(raw_payload(parts[0], parts[1], parts[2] if len(parts) > 2 else None), a.dry_run)


if __name__ == "__main__":
    main()
