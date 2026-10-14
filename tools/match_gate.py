#!/usr/bin/env python3
"""objdiff match gate.

1. Builds (FORGE_BUILD_CMD, default `ninja`) and generates an objdiff report with
   `objdiff-cli report generate -o build/report.json` (objdiff.json must exist).
2. For every src/ C file changed since $FORGE_BASE, finds its objdiff unit and requires each
   function that is *defined in C* in that file (i.e. not an INCLUDE_ASM stub) to be at
   100% fuzzy_match_percent.
3. Requires overall matched_code to not decrease vs. build/report.base.json when present.

Report JSON field names follow objdiff's report format (units[].functions[].name /
fuzzy_match_percent; measures.matched_code). Verify against your objdiff-cli version: the
format has changed across releases (see docs/ENGINE.md "assumed").
"""
import json, os, re, subprocess, sys

BUILD = os.environ.get("FORGE_BUILD_CMD", "ninja")
OBJDIFF = os.environ.get("OBJDIFF_CLI", "./objdiff-cli" if os.path.exists("objdiff-cli") else "objdiff-cli")
FUNC_DEF = re.compile(r'^[A-Za-z_][\w\s\*]*?\b([A-Za-z_]\w*)\s*\([^;{]*\)\s*(\{.*)?$')


def changed_c(base):
    # committed changes since base, plus uncommitted/untracked ones (manual runs before commit)
    out = subprocess.run(["git", "diff", "--name-only", f"{base}...HEAD", "--", "src", "libs"],
                         capture_output=True, text=True, check=True).stdout
    out += subprocess.run(["git", "status", "--porcelain", "-uall", "--", "src", "libs"],
                          capture_output=True, text=True).stdout.replace("??", "").replace(" M ", " ").replace("A  ", " ")
    paths = dict.fromkeys(p for p in out.split() if p.endswith((".c", ".cpp")) and os.path.exists(p))
    return list(paths)


def c_functions(path):
    names = []
    for line in open(path, encoding="utf-8", errors="replace"):
        if line.startswith((" ", "\t", "#", "}", "/")) or "INCLUDE_ASM" in line:
            continue
        m = FUNC_DEF.match(line.rstrip())
        if m and m.group(1) not in ("if", "while", "for", "switch", "return"):
            names.append(m.group(1))
    return names


def main():
    import wtenv; wtenv.ensure()
    global OBJDIFF
    if OBJDIFF == "objdiff-cli" and os.path.exists("objdiff-cli"):
        OBJDIFF = "./objdiff-cli"
    base = os.environ.get("FORGE_BASE", "HEAD~1")
    r = subprocess.run(BUILD, shell=True, capture_output=True, text=True)
    if r.returncode:
        print("match: build failed:\n" + (r.stdout + r.stderr)[-3000:]); return 1
    os.makedirs("build", exist_ok=True)
    r = subprocess.run([OBJDIFF, "report", "generate", "-o", "build/report.json"],
                       capture_output=True, text=True)
    if r.returncode:
        print("match: objdiff report failed:\n" + (r.stdout + r.stderr)[-2000:]); return 1
    rep = json.load(open("build/report.json"))
    by_unit = {u.get("name", ""): u for u in rep.get("units", [])}
    exc = set()
    if os.path.exists("config/match_exceptions.txt"):  # human-owned, protected
        exc = {l.split()[0] for l in open("config/match_exceptions.txt") if l.strip() and not l.startswith("#")}
    fails, checked = [], 0
    for path in changed_c(base):
        stem = os.path.splitext(path)[0].removeprefix("src/")
        unit = next((u for n, u in by_unit.items() if n.endswith(stem)), None)
        if unit is None:
            fails.append(f"{path}: no objdiff unit (is it in objdiff.json / the split config?)"); continue
        funcs = {f.get("name"): f for f in unit.get("functions", [])}
        for name in c_functions(path):
            checked += 1
            f = funcs.get(name)
            if f is None:
                fails.append(f"{path}: {name} not found in target object (wrong name/split?)")
            elif float(f.get("fuzzy_match_percent", 0)) < 100.0 and name not in exc:
                fails.append(f"{path}: {name} is {f.get('fuzzy_match_percent', 0):.2f}% (need 100)")
    if os.path.exists("build/report.base.json"):
        old = json.load(open("build/report.base.json")).get("measures", {}).get("matched_code", 0)
        new = rep.get("measures", {}).get("matched_code", 0)
        if int(new) < int(old):
            fails.append(f"overall matched_code dropped {old} -> {new}")
    if not checked:
        fails.append("no C function definitions found in changed src/ or libs/ files (nothing was checked)")
    for f in fails[:40]:
        print("match:", f)
    if not fails:
        print(f"match: all {checked} C functions in changed files are 100%")
    return 1 if fails else 0


if __name__ == "__main__":
    sys.exit(main())
