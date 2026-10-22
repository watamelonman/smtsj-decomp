#!/usr/bin/env python3
"""Create decomp.me scratches for hard functions (stdlib only).

  tools/decompme.py create --func NAME --asm asm/path/NAME.s [--src src/x.c] [--ctx ctx.h]
  tools/decompme.py create-many --from build/hard.txt      # lines: NAME<TAB>asm_path[<TAB>src]
  tools/decompme.py --dry-run create ...                   # print payload, send nothing

VERIFIED (2026-10-13, decomp.me source on GitHub, backend/coreapp/serializers.py and
cromper/cromper/compilers.py; objdiff-core create_scratch.rs):
  * POST https://decomp.me/api/scratch, fields name, compiler, platform, compiler_flags,
    diff_flags, preset, source_code, target_asm|target_obj, context, diff_label, libraries.
  * Response JSON has `slug` and `claim_token`; claim URL is /scratch/<slug>/claim?token=...
  * Platform ids `ps2`, `nds_arm9`; compiler ids like `ee-gcc2.96`, `mwcps2-3.0.1b210-060308`,
    `mwcc_30_131` exist in the compiler table.
ASSUMED / UNTESTED:
  * Not exercised end to end: decomp.me is behind Cloudflare and rejected requests from the
    build box (HTTP 403 challenge). Run from a local machine; may need a browser-like UA.
  * Whether the API is rate-limited for anonymous creation.
Scratches are PUBLIC. Asm of retail code gets uploaded: the maintainer must opt in (FORGE_DECOMPME_OK=1),
and agents may not set it. Results are appended to config/scratches.tsv.
"""
import argparse, json, os, pathlib, sys, tomllib, urllib.error, urllib.request

API = os.environ.get("DECOMPME_API", "https://decomp.me/api")
UA = os.environ.get("DECOMPME_UA", "re-forge/0.1 (+matching decomp pipeline)")


def cfg():
    p = pathlib.Path("config/decompme.toml")
    return tomllib.loads(p.read_text()) if p.exists() else {}


def payload(func, asm, src=None, ctx=None, c=None):
    c = c or cfg()
    return {
        "name": func, "diff_label": func,
        "platform": c.get("platform", ""), "compiler": c.get("compiler", ""),
        "compiler_flags": c.get("compiler_flags", ""),
        "target_asm": pathlib.Path(asm).read_text(errors="replace"),
        "source_code": pathlib.Path(src).read_text(errors="replace") if src else "",
        "context": pathlib.Path(ctx).read_text(errors="replace") if ctx else "",
        **({"preset": c["preset"]} if c.get("preset") else {}),
    }


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


def create(func, asm, src, ctx, dry):
    data = payload(func, asm, src, ctx)
    if not data["platform"] or not data["compiler"]:
        raise SystemExit("config/decompme.toml needs platform and compiler")
    if dry:
        print(json.dumps({k: (v[:200] + "..." if isinstance(v, str) and len(v) > 200 else v)
                          for k, v in data.items()}, indent=1)); return
    if os.environ.get("FORGE_DECOMPME_OK") != "1":
        raise SystemExit("refusing: set FORGE_DECOMPME_OK=1 to upload (scratches are public)")
    url, tok = post(data)
    with open("config/scratches.tsv", "a") as f:
        f.write(f"{func}\t{url}\t{url}/claim?token={tok}\n")
    print(url)


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    sub = ap.add_subparsers(dest="cmd", required=True)
    c = sub.add_parser("create"); c.add_argument("--func", required=True)
    c.add_argument("--asm", required=True); c.add_argument("--src"); c.add_argument("--ctx")
    m = sub.add_parser("create-many"); m.add_argument("--from", dest="src_list", required=True)
    a = ap.parse_args(argv)
    if a.cmd == "create":
        create(a.func, a.asm, a.src, a.ctx, a.dry_run)
    else:
        for line in open(a.src_list):
            parts = line.rstrip("\n").split("\t")
            if len(parts) >= 2:
                create(parts[0], parts[1], parts[2] if len(parts) > 2 else None, None, a.dry_run)


if __name__ == "__main__":
    main()
