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
    ap.add_argument("--skip-libs", action="store_true", help="no cards for libs/ units (SDK/middleware)")
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
    skipped_gaps = 0
    units = sorted(rep.get("units", []), key=lambda u: int(u.get("measures", {}).get("total_code", 0)))
    for u in units:
        if u["name"].startswith("_dsd_gap@") or "/_dsd_gap@" in u["name"]:
            skipped_gaps += 1   # dsd gap object: not a real TU (run tools/propose_tus.py)
            continue
        todo = [f for f in u.get("functions", []) if float(f.get("fuzzy_match_percent", 0)) < 100]
        if not todo:
            continue
        todo.sort(key=lambda f: int(f.get("size", 0)))
        upath = re.sub(r'\.(c|cpp)$', '', re.sub(r'^asm/', 'src/', u["name"]))
        if not upath.startswith(("src/", "libs/")):
            upath = "src/" + upath
        unit = re.sub(r'^src/', '', upath)
        is_lib = upath.startswith("libs/")
        if is_lib and a.skip_libs:
            continue
        prev = None
        for i in range(0, len(todo), a.max_funcs):
            if made >= a.limit:
                break
            n += 1; made += 1
            cid = f"M{a.milestone + (1 if is_lib else 0)}-T{n:03d}"
            chunk = todo[i:i + a.max_funcs]
            lines = []
            for f in chunk:
                g = gh.get(f["name"], {})
                hint = f" (Ghidra: `{g['suggested']}`)" if g.get("suggested") else ""
                lines.append(f"- [ ] `{f['name']}` size {f.get('size', '?')}, now "
                             f"{float(f.get('fuzzy_match_percent', 0)):.1f}%{hint}")
            GOAL = (("Library code (SDK/middleware): first look for the matching public/known source\n"
                     "(e.g. NitroSDK/MSL code reconstructed in pret/pokeplatinum, zeldaret) before writing new C.\n")
                    if is_lib else "") + (f"Write `{upath}.c` (create it) with readable C for these functions so that\n"
                    "objdiff shows them identical to the delinked original. The TU is linked from the\n"
                    "delink until a human marks it `complete` in config/arm9/delinks.txt."
                    if pathlib.Path("config/arm9/delinks.txt").exists() else
                    f"Replace the `INCLUDE_ASM` stubs for these functions in `src/{unit}.c` with readable C\n"
                    "that compiles to byte-identical code.")
            slug = re.sub(r'[^a-z0-9]+', '-', unit.lower()).strip('-')[:40]
            body = f"""+++
id = "{cid}"
title = "Match {upath.removeprefix('src/')} ({len(chunk)} functions)"
milestone = {a.milestone + (1 if is_lib else 0)}
deps = {json.dumps([prev] if prev else [])}
agent = "any"
owns = ["{upath}.c", "{upath}.cpp", "include/{unit}.h", "docs/functions/{slug}.md"]
docs = ["docs/functions/{slug}.md"]
tests_required = false
may_edit_tests = false
scene_edits = false
+++
## Goal
{GOAL}

## Functions
{chr(10).join(lines)}

## Acceptance criteria
- [ ] objdiff reports 100% for every function above (gate `match`).
- [ ] Full build still produces the original image (gate `checksum`).
- [ ] No inline asm, asm includes or byte blobs added (gate `anticheat`).
- [ ] Every function has a descriptive name, typed params and a comment saying what it
      does; `docs/functions/{slug}.md` has one entry per function.

## Notes
If a function will not match after real effort, leave it out (PS2: keep its `INCLUDE_ASM`), explain
what you tried in the doc, and add it to the hard list in the doc so a human can open a
decomp.me scratch (tools/decompme.py). Do not fake a match.
"""
            (out / f"{cid}-{slug}.md").write_text(body)
            prev = cid
    print(f"wrote {made} cards to tasks/" + (f"; skipped {skipped_gaps} dsd gap units (define TUs first)" if skipped_gaps else ""))


if __name__ == "__main__":
    main()
