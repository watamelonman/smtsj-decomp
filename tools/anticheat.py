#!/usr/bin/env python3
"""Anti-cheat gate for matching decomp: scans lines ADDED since $FORGE_BASE in src/**.

Rejects, in C/C++ sources and headers:
  ASM      inline asm (asm/__asm__/__asm/asm volatile, MWCC `asm {}` / `asm void f()`)
  INCASM   INCLUDE_ASM / INCLUDE_RODATA / GLOBAL_ASM / #pragma GLOBAL_ASM / .incbin
  BLOB     raw byte/word arrays: a brace initializer (`= { ... }`) with >= BLOB_MIN numeric literals on
           added lines (catches code-as-data). Call arguments and code blocks are not counted.
           Self-test: tools/anticheat.py --selftest. Data tables are legitimate; mark a reviewed one with
           a trailing `// forge:data-ok <reason>` on its opening line (the reviewer audits it).
  FNPTR    casting a data array to a function pointer (executing a blob)
  NONMATCH NONMATCHING/#ifdef NON_MATCHING blocks counted as matched

Pre-existing INCLUDE_ASM lines (from the split) are fine; only additions are checked, and
removing them is the point of each card. Exit 0 = pass.
"""
import os, re, subprocess, sys

BLOB_MIN = int(os.environ.get("FORGE_BLOB_MIN", "16"))
SRC_EXT = (".c", ".cpp", ".cc", ".h", ".hpp", ".inc")
RULES = [
    ("ASM", re.compile(r'\b(__asm__|__asm|asm)\b\s*(volatile\b|__volatile__\b)?\s*[({]|\basm\s+(void|int|u32|s32)\b')),
    ("INCASM", re.compile(r'\b(INCLUDE_ASM|INCLUDE_RODATA|GLOBAL_ASM|INCLUDE_BIN)\b|#\s*pragma\s+GLOBAL_ASM|\.incbin\b')),
    ("FNPTR", re.compile(r'\(\s*\w+\s*\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*&?\s*\w*(code|blob|bytes|data|buf)\w*', re.I)),
    ("NONMATCH", re.compile(r'\bNON_?MATCHING\b')),
]
NUM = re.compile(r'\b(0x[0-9a-fA-F]+|\d+)[uUlL]*\b')


def added_lines(base):
    out = subprocess.run(["git", "diff", "-U0", f"{base}...HEAD", "--", "src", "libs", "include"],
                         capture_output=True, text=True, check=True).stdout
    path, ln = None, 0
    for line in out.splitlines():
        if line.startswith("+++ "):
            path = line[6:] if line.startswith("+++ b/") else None
        elif line.startswith("@@"):
            ln = int(re.search(r'\+(\d+)', line).group(1))
        elif line.startswith("+") and path:
            yield path, ln, line[1:]
            ln += 1


INIT_START = re.compile(r'=\s*\{')


def _init_text(st, code):
    """Return the part of `code` inside a brace initializer (`= { ... }`), updating st.

    st["depth"] > 0 while inside an initializer that spans lines. Plain blocks, call
    argument lists and other braces are ignored, so only real data initializers count."""
    out, i = [], 0
    while i < len(code):
        if st["depth"] == 0:
            m = INIT_START.search(code, i)
            if not m:
                break
            st["depth"], i = 1, m.end()
            continue
        c = code[i]
        if c == '{':
            st["depth"] += 1
        elif c == '}':
            st["depth"] -= 1
            if st["depth"] == 0:
                i += 1
                continue
        out.append(c)
        i += 1
    return ''.join(out)


def scan(lines):
    """Return failure strings for an iterable of (path, lineno, text)."""
    fails, state = [], {}
    for path, n, text in lines:
        if not path.endswith(SRC_EXT):
            continue
        code = re.sub(r'//.*$', '', text) if 'forge:data-ok' not in text else ''
        for tag, rx in RULES:
            if rx.search(code):
                fails.append(f"{tag}: {path}:{n}: {text.strip()[:100]}")
        st = state.setdefault(path, {"depth": 0, "count": 0})
        if 'forge:data-ok' in text:
            st["count"] = -10**9  # reviewed table: exempt until file end
            continue
        was_in = st["depth"] > 0
        inner = _init_text(st, code)
        if not was_in and not inner and st["depth"] == 0:
            if st["count"] >= 0:
                st["count"] = 0
            continue
        st["count"] += len(NUM.findall(inner))
        if st["count"] >= BLOB_MIN:
            fails.append(f"BLOB: {path}:{n}: {st['count']}+ numeric literals in an initializer; "
                         "raw bytes are not decompiled C (mark real data tables `// forge:data-ok <why>`)")
            st["count"] = -10**9
        elif st["depth"] == 0 and st["count"] >= 0:
            st["count"] = 0  # initializer ended below the threshold
    return fails


def selftest():
    blob = [("src/a.c", 1, "static const u8 data[] = {"),
            ("src/a.c", 2, "    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,"),
            ("src/a.c", 3, "    0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10,"),
            ("src/a.c", 4, "};")]
    one = [("src/b.c", 1, "u32 t[] = {" + ", ".join(str(i) for i in range(20)) + "};")]
    calls = [("src/c.c", i, f"  tmp1 = func_020445f4(0xe,{i}); func_0204fcb0({i},tmp1);")
             for i in range(1, 12)]
    calls += [("src/c.c", 20, "  if (tmp4 != tmp6) {"), ("src/c.c", 21, "    func_0204faf0(1,2,3,4);")]
    small = [("src/d.c", 1, "s32 v[3] = {1, 2, 3};"), ("src/d.c", 2, "f(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17);")]
    ok = [("src/e.c", 1, "u8 x[] = { // forge:data-ok palette"), ("src/e.c", 2, " " + ",".join(["1"] * 30))]
    assert any(f.startswith("BLOB") for f in scan(blob)), "multi-line blob not caught"
    assert any(f.startswith("BLOB") for f in scan(one)), "one-line blob not caught"
    assert not scan(calls), scan(calls)
    assert not scan(small), scan(small)
    assert not scan(ok), scan(ok)
    print("anticheat selftest: ok")
    return 0


def main():
    base = os.environ.get("FORGE_BASE", "HEAD~1")
    fails = scan(added_lines(base))
    for f in fails[:40]:
        print(f)
    if fails:
        print("anticheat: matched C must be real C. No inline asm, asm includes or byte blobs.")
    return 1 if fails else 0


if __name__ == "__main__":
    sys.exit(selftest() if "--selftest" in sys.argv else main())
