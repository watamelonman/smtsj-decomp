#!/usr/bin/env python3
"""Anti-cheat gate for matching decomp: scans lines ADDED since $FORGE_BASE in src/**.

Rejects, in C/C++ sources and headers:
  ASM      inline asm (asm/__asm__/__asm/asm volatile, MWCC `asm {}` / `asm void f()`)
  INCASM   INCLUDE_ASM / INCLUDE_RODATA / GLOBAL_ASM / #pragma GLOBAL_ASM / .incbin
  BLOB     raw byte/word arrays: an initializer with >= BLOB_MIN numeric literals on added
           lines (catches code-as-data). Data tables are legitimate; mark a reviewed one with
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
    out = subprocess.run(["git", "diff", "-U0", f"{base}...HEAD", "--", "src", "include"],
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


def scan(lines):
    """Return failure strings for an iterable of (path, lineno, text)."""
    fails, blob = [], {}
    for path, n, text in lines:
        if not path.endswith(SRC_EXT):
            continue
        code = re.sub(r'//.*$', '', text) if 'forge:data-ok' not in text else ''
        for tag, rx in RULES:
            if rx.search(code):
                fails.append(f"{tag}: {path}:{n}: {text.strip()[:100]}")
        if 'forge:data-ok' in text:
            blob[path] = -10**9  # reviewed table: exempt until file end
            continue
        blob[path] = blob.get(path, 0) + len(NUM.findall(code)) if re.search(r'[{,]', code) else 0
        if blob[path] >= BLOB_MIN:
            fails.append(f"BLOB: {path}:{n}: {blob[path]}+ numeric literals in an initializer; "
                         "raw bytes are not decompiled C (mark real data tables `// forge:data-ok <why>`)")
            blob[path] = -10**9
    return fails


def main():
    base = os.environ.get("FORGE_BASE", "HEAD~1")
    fails = scan(added_lines(base))
    for f in fails[:40]:
        print(f)
    if fails:
        print("anticheat: matched C must be real C. No inline asm, asm includes or byte blobs.")
    return 1 if fails else 0


if __name__ == "__main__":
    sys.exit(main())
