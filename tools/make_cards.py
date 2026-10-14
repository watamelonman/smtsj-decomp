#!/usr/bin/env python3
"""Turn the split + objdiff report into forge task cards (one card per translation unit,
listing its unmatched functions, smallest first). Human-run, not a gate.

  tools/make_cards.py --report build/report.json [--milestone 1] [--max-funcs 8] [--limit 50]

Each card owns src/<unit>.c (+ its header) and docs/functions/<unit>.md, needs the match gate,
and gets Ghidra names/comments from build/ghidra/functions.json when present.
Units with more unmatched functions than --max-funcs are split into several cards that run
in sequence (deps), since two cards may not own the same file concurrently.
"""
import argparse, json, os, pathlib, re


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--report", default="build/report.json")
    ap.add_argument("--ghidra", default="build/ghidra/functions.json")
    ap.add_argument("--milestone", type=int, default=1)
    ap.add_argument("--max-funcs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=50)
    ap.add_argument("--hard-pct", type=float, default=0.0,
                    help="also list functions whose last attempt stalled below this % in build/hard.txt")
    a = ap.parse_args()
    rep = json.load(open(a.report))
    gh = {}
    if os.path.exists(a.ghidra):
        gh = {f["name"]: f for f in json.load(open(a.ghidra))}
    out = pathlib.Path("tasks"); out.mkdir(exist_ok=True)
    n = len(list(out.glob("*.md")))
    made = 0
    units = sorted(rep.get("units", []), key=lambda u: int(u.get("measures", {}).get("total_code", 0)))
    for u in units:
        todo = [f for f in u.get("functions", []) if float(f.get("fuzzy_match_percent", 0)) < 100]
        if not todo:
            continue
        todo.sort(key=lambda f: int(f.get("size", 0)))
        unit = re.sub(r'^(src/|asm/)', '', u["name"])
        prev = None
        for i in range(0, len(todo), a.max_funcs):
            if made >= a.limit:
                break
            n += 1; made += 1
            cid = f"M{a.milestone}-T{n:03d}"
            chunk = todo[i:i + a.max_funcs]
            lines = []
            for f in chunk:
                g = gh.get(f["name"], {})
                hint = f" (Ghidra: `{g['suggested']}`)" if g.get("suggested") else ""
                lines.append(f"- [ ] `{f['name']}` size {f.get('size', '?')}, now "
                             f"{float(f.get('fuzzy_match_percent', 0)):.1f}%{hint}")
            slug = re.sub(r'[^a-z0-9]+', '-', unit.lower()).strip('-')[:40]
            body = f"""+++
id = "{cid}"
title = "Match {unit} ({len(chunk)} functions)"
milestone = {a.milestone}
deps = {json.dumps([prev] if prev else [])}
agent = "any"
owns = ["src/{unit}.c", "include/{unit}.h", "docs/functions/{slug}.md"]
docs = ["docs/functions/{slug}.md"]
tests_required = false
may_edit_tests = false
scene_edits = false
+++
## Goal
Replace the `INCLUDE_ASM` stubs for these functions in `src/{unit}.c` with readable C that
compiles to byte-identical code.

## Functions
{chr(10).join(lines)}

## Acceptance criteria
- [ ] objdiff reports 100% for every function above (gate `match`).
- [ ] Full build still produces the original image (gate `checksum`).
- [ ] No inline asm, asm includes or byte blobs added (gate `anticheat`).
- [ ] Every function has a descriptive name, typed params and a comment saying what it
      does; `docs/functions/{slug}.md` has one entry per function.

## Notes
If a function will not match after real effort, leave its `INCLUDE_ASM` in place, explain
what you tried in the doc, and add it to the hard list in the doc so a human can open a
decomp.me scratch (tools/decompme.py). Do not fake a match.
"""
            (out / f"{cid}-{slug}.md").write_text(body)
            prev = cid
    print(f"wrote {made} cards to tasks/")


if __name__ == "__main__":
    main()
