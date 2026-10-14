#!/usr/bin/env python3
"""Propose translation units for ALL of ARM9 main .text (human-run; output is reviewed).

Signals (after zeldaret/ph+st and pret pokeplatinum practice):
  0. Library ZONES: long runs of functions that never (transitively) call game code.
  1. Inside a zone, which library: per-function labels from content, filled from neighbours.
     sdk   = touches IO registers (0x04000000..) or the shared work area (0x027FF000..)
     msl   = MSL printf/strtod constant strings (INFINITY, long digit tables)
     cri   = CRI middleware strings (cri*, ADX, AHX, E<digits> error codes)
     wifi  = NitroWiFi/WH strings (WH_, WM_, WCM, DWC)
     game  = game asset paths / formats (Data/, .tbb, .bin, Camp/, ...) or a __FILE__ anchor
  2. Inside each region, TU cuts go where no call edge crosses the gap between neighbouring
     functions within a window (static helpers sit next to their callers in MWCC output,
     and link order keeps each object's functions contiguous).
  3. __FILE__ anchors from Ghidra ("BattleTask.c") name the TU that contains them.
  4. Ranges are snapped to dsd function boundaries (which include literal pools).
.data/.rodata/.bss are NOT assigned (left in dsd gap objects); .text only.

  tools/segment_tus.py [--min-size 0x200] [--window 24] [--out config/arm9/delinks.segmented.txt]
"""
import argparse, bisect, collections, json, pathlib, re, struct

SYM = re.compile(r'^(\S+) kind:function\((arm|thumb),size=(0x[0-9a-f]+)[^)]*\) addr:(0x[0-9a-f]+)')
LABELS = [
    ("msl", re.compile(r'INFINITY|\d{20,}')),
    ("cri", re.compile(r'(?i)\bcri|ADX|AHX|^E\d{8,}|criSs|NITROCI')),
    ("wifi", re.compile(r'WH_|WM_|WCM|DWC')),
    ("game", re.compile(r'Data/|\.tbb|\.bf\b|\.gfn|\.cmp|\.mbb|Camp/|Cave/|Battle/|Visor/|Scan/|snd/|Snd/|map_parts|%03d')),
]


def load(cfg_dir, arm9, ghidra):
    fns = []
    for line in open(cfg_dir / "symbols.txt"):
        m = SYM.match(line)
        if m:
            fns.append({"name": m.group(1), "addr": int(m.group(4), 16), "size": int(m.group(3), 16)})
    fns.sort(key=lambda f: f["addr"])
    # keep only main .text
    text = re.search(r'\.text\s+start:(0x[0-9a-f]+) end:(0x[0-9a-f]+)', open(cfg_dir / "delinks.txt").read())
    lo, hi = int(text.group(1), 16), int(text.group(2), 16)
    fns = [f for f in fns if lo <= f["addr"] < hi]
    gh = {int(f["addr"], 16): f for f in json.load(open(ghidra))} if pathlib.Path(ghidra).exists() else {}
    data = pathlib.Path(arm9).read_bytes()
    base = 0x02000000
    for f in fns:
        o = f["addr"] - base
        ws = [w for (w,) in struct.iter_unpack("<I", data[o:o + f["size"] // 4 * 4])]
        f["io"] = sum(0x04000000 <= w < 0x04800000 or 0x027FF000 <= w < 0x02800000 for w in ws)
        g = gh.get(f["addr"], {})
        f["strings"], f["callees"], f["hint"] = g.get("strings", []), g.get("callees", []), g.get("source_file_hint", "")
        lab = ""
        for name, rx in LABELS:
            if any(rx.search(s) for s in f["strings"]):
                lab = name; break
        if not lab and f["hint"]:
            lab = "game"
        if not lab and f["io"]:
            lab = "sdk"
        f["label"] = lab
    return fns, lo, hi


def game_reaching(fns):
    """Library code never calls game code. Seeds = functions with game strings/anchors;
    everything that (transitively) calls a seed is game too."""
    callers = collections.defaultdict(set)
    for f in fns:
        for c in f["callees"]:
            callers[c].add(f["name"])
    g = {f["name"] for f in fns if f["label"] == "game"}
    stack = list(g)
    while stack:
        for c in callers[stack.pop()]:
            if c not in g:
                g.add(c); stack.append(c)
    return g


def zones(fns, min_lib_funcs):
    """Long runs of functions that never reach game code are library zones."""
    g = game_reaching(fns)
    out, i = ["game"] * len(fns), 0
    while i < len(fns):
        if fns[i]["name"] in g:
            i += 1; continue
        j = i
        while j < len(fns) and fns[j]["name"] not in g:
            j += 1
        if j - i >= min_lib_funcs:
            sub = [f["label"] if f["label"] in ("cri", "msl", "wifi", "sdk") else "" for f in fns[i:j]]
            known = [k for k, l in enumerate(sub) if l]
            for k in range(len(sub)):
                if not sub[k]:
                    near = min(known, key=lambda q: abs(q - k)) if known else None
                    sub[k] = sub[near] if near is not None and abs(near - k) <= 40 else "lib"
            # middleware glue that touches IO (CRI's NITRO layer) stays with the middleware
            for lib in ("cri", "msl"):
                ks = [k for k, l in enumerate(sub) if l == lib]
                if ks:
                    for k in range(ks[0], ks[-1] + 1):
                        if sub[k] in ("sdk", "lib"):
                            sub[k] = lib
            # smooth single strays inside a library zone
            for k in range(len(sub)):
                win = sub[max(0, k - 8): k + 9]
                c = collections.Counter(win).most_common(1)[0]
                if c[1] >= 12:
                    sub[k] = c[0]
            out[i:j] = sub
        i = j
    return out


def regions(fns):
    """Fill unlabeled functions from neighbours: a gap between two equal labels takes that
    label; between different labels it is split at the largest call-free cut later."""
    labs = [f["label"] for f in fns]
    known = [i for i, l in enumerate(labs) if l]
    out = list(labs)
    for a, b in zip(known, known[1:]):
        fill = labs[a] if labs[a] == labs[b] else None
        for i in range(a + 1, b):
            out[i] = fill or (labs[a] if i - a <= b - i else labs[b])
    if known:
        for i in range(known[0]): out[i] = labs[known[0]]
        for i in range(known[-1] + 1, len(out)): out[i] = labs[known[-1]]
    # majority smoothing removes single stray labels (e.g. a game function using one IO reg)
    sm = list(out)
    for i in range(len(out)):
        win = out[max(0, i - 6): i + 7]
        c = collections.Counter(win).most_common(1)[0]
        if c[1] >= 9 and out[i] != c[0]:
            sm[i] = c[0]
    return sm


def cuts(fns, idx, window):
    """Indices j (cut between j-1 and j) inside idx-range with no call edge crossing nearby."""
    pos = {f["name"]: i for i, f in enumerate(fns)}
    edges = []
    for i in idx:
        for c in fns[i]["callees"]:
            j = pos.get(c)
            if j is not None and abs(j - i) <= window:
                edges.append((min(i, j), max(i, j)))
    cross = collections.Counter()
    for a, b in edges:
        for k in range(a + 1, b + 1):
            cross[k] += 1
    # objects are linked with ALIGNALL(4): a TU can only start on a 4-byte boundary
    return [j for j in idx[1:] if cross[j] == 0 and fns[j]["addr"] % 4 == 0]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--config", default="config/arm9")
    ap.add_argument("--arm9", default="extract/arm9/arm9.bin")
    ap.add_argument("--ghidra", default="build/ghidra/functions.json")
    ap.add_argument("--min-size", type=lambda x: int(x, 0), default=0x200)
    ap.add_argument("--window", type=int, default=24)
    ap.add_argument("--min-lib-funcs", type=int, default=120,
                    help="a run of this many functions that never reach game code is a library zone")
    ap.add_argument("--out", default="config/arm9/delinks.segmented.txt")
    a = ap.parse_args()
    fns, lo, hi = load(pathlib.Path(a.config), a.arm9, a.ghidra)
    labs = zones(fns, a.min_lib_funcs)
    # crt0 + BIOS SVC thunks precede main() in every NITRO ROM; they are SDK code
    mi = next((k for k, f in enumerate(fns) if f["name"] == "main"), None)
    if mi is not None:
        for k in range(mi):
            labs[k] = "sdk"
    # crt0/SDK prologue: everything before `main` belongs to crt0 (Entry etc.)
    tus, i = [], 0
    while i < len(fns):
        j = i
        while j + 1 < len(fns) and labs[j + 1] == labs[i]:
            j += 1
        idx = list(range(i, j + 1))
        cs = set(cuts(fns, idx, a.window))
        start = i
        for k in idx[1:] + [j + 1]:
            size = (fns[k]["addr"] if k < len(fns) else hi) - fns[start]["addr"]
            hint_here = any(fns[m]["hint"] for m in range(start, k))
            aligned = k >= len(fns) or fns[k]["addr"] % 4 == 0
            if (k == j + 1 and aligned) or (k in cs and size >= a.min_size):
                tus.append((labs[i] or "unk", start, k))
                start = k
        i = j + 1
    lines, names, stats = [], collections.Counter(), collections.Counter()
    for lab, s, e in tus:
        start = fns[s]["addr"]
        end = fns[e]["addr"] if e < len(fns) else hi
        hints = [fns[m]["hint"] for m in range(s, e) if fns[m]["hint"]]
        if hints:
            stem = pathlib.Path(collections.Counter(hints).most_common(1)[0][0]).stem
            path = f"src/{stem}.c"
        elif lab == "game" or lab == "unk":
            path = f"src/game/unit_{start:08x}.c"
        else:
            path = f"libs/{ {'sdk': 'NitroSDK', 'msl': 'MSL', 'cri': 'CRI', 'wifi': 'NitroWiFi', 'lib': 'unknown'}[lab] }/{lab}_{start:08x}.c"
        names[path] += 1
        if names[path] > 1:
            path = path.replace(".c", f"_{names[path]}.c")
        stats[lab] += end - start
        lines.append(f"{path}:\n    .text       start:{start:#010x} end:{end:#010x}\n")
    pathlib.Path(a.out).write_text("# PROPOSED by tools/segment_tus.py (.text only) - review before use\n\n" + "\n".join(lines))
    total = hi - lo
    print(f"{len(tus)} TUs covering {sum(stats.values()):#x} of {total:#x} bytes of main .text")
    for k, v in stats.most_common():
        print(f"  {k or 'unk':5s} {v:#9x} ({100 * v / total:.1f}%)")
    print(f"-> {a.out}")


if __name__ == "__main__":
    main()
