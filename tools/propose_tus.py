#!/usr/bin/env python3
"""Propose translation-unit boundaries for a fresh dsd project (human-run, reviewed).

dsd init leaves each module as one gap object, so there are no TUs to make cards from yet.
Atlus code keeps __FILE__ strings ("BattleTask.c") for asserts; Ghidra's export records the
first such string each function references (`source_file_hint`). Runs of consecutive
functions whose hints agree (unhinted functions in between are absorbed) become a candidate
`src/<file>:` entry with a .text range.

  tools/propose_tus.py [--ghidra build/ghidra/functions.json] [--min-funcs 2]
Writes config/arm9/delinks.proposed.txt; nothing is applied. Review, then paste chosen entries
into config/arm9/delinks.txt (WITHOUT `complete`) and re-run ./configure.py && ninja; each
entry becomes an objdiff unit that tools/make_cards.py turns into a card.
Only main-module .text is proposed; .rodata/.data/.bss ranges must be added by hand.
"""
import argparse, bisect, json, pathlib, re

SYM = re.compile(r'kind:function\((?:arm|thumb),size=(0x[0-9a-f]+)[^)]*\) addr:(0x[0-9a-f]+)')


def dsd_functions(path):
    """(start, end) of every function in a dsd symbols.txt, sorted. dsd's ranges include the
    literal pool after a function; Ghidra's don't, so TU ranges are snapped to dsd's."""
    out = []
    for line in open(path):
        m = SYM.search(line)
        if m:
            a = int(m.group(2), 16); out.append((a, a + int(m.group(1), 16)))
    return sorted(out)


def snap(fns, start, end):
    starts = [f[0] for f in fns]
    i = bisect.bisect_right(starts, start) - 1
    j = bisect.bisect_right(starts, end - 1) - 1
    s = fns[i][0] if i >= 0 and fns[i][1] > start else start
    e = max(fns[j][1], end) if j >= 0 else end
    return s, e


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ghidra", default="build/ghidra/functions.json")
    ap.add_argument("--min-funcs", type=int, default=2)
    ap.add_argument("--out", default="config/arm9/delinks.proposed.txt")
    ap.add_argument("--symbols", default="config/arm9/symbols.txt")
    a = ap.parse_args()
    fns = sorted(json.load(open(a.ghidra)), key=lambda f: int(f["addr"], 16))
    runs, cur = [], None
    for f in fns:
        hint, start = f.get("source_file_hint", ""), int(f["addr"], 16)
        end = start + int(f["size"])
        if hint and cur and hint != cur["file"]:
            runs.append(cur); cur = None
        if hint and cur is None:
            cur = {"file": hint, "start": start, "end": end, "n": 1, "hinted": 1}
        elif cur:
            cur["end"], cur["n"] = max(cur["end"], end), cur["n"] + 1
            cur["hinted"] += bool(hint)
            cur["last_hint_end"] = end if hint else cur.get("last_hint_end", cur["end"])
    if cur:
        runs.append(cur)
    dfns = dsd_functions(a.symbols)
    out, seen = [], {}
    for r in runs:
        end = r.get("last_hint_end", r["end"])  # don't absorb unhinted tail past last hint
        if r["hinted"] < a.min_funcs and r["n"] < a.min_funcs:
            continue
        start, end = snap(dfns, r["start"], end)
        name = r["file"]
        seen[name] = seen.get(name, 0) + 1
        if seen[name] > 1:  # same file name in two places: keep both, flag for review
            name = f"{name}  # DUPLICATE #{seen[name]}: non-contiguous, check by hand"
        out.append(f"src/{name}:\n    .text       start:{start:#010x} end:{end:#010x}\n")
    pathlib.Path(a.out).write_text(
        "# PROPOSED by tools/propose_tus.py - review before copying into delinks.txt\n\n" + "\n".join(out))
    print(f"{len(out)} candidate TUs from {sum(1 for f in fns if f.get('source_file_hint'))} hinted functions -> {a.out}")


if __name__ == "__main__":
    main()
