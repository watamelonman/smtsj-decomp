"""cmp.py fn file.c [-v] : compile file standalone, compare fn with the ROM."""
import sys, os, subprocess, re; sys.path.insert(0, os.path.dirname(__file__))
from hl import *
fn, path = sys.argv[1], sys.argv[2]
if not os.path.exists(path): path = os.path.join(WORK, 'b', os.path.basename(path))  # bare name -> batch output
obj, err = compile_(open(path).read())
if not obj: print(err); sys.exit(1)
ok, msg = compare(fn, obj); print(fn, 'OK' if ok else 'FAIL', msg)
if '-v' in sys.argv:
    a = BYNAME[fn][0]; T = [t for _, _, t in dis(a, size(fn))]
    o = subprocess.run(['arm-none-eabi-objdump', '-dz', obj], capture_output=True, text=True).stdout
    B, on = [], False
    for l in o.splitlines():
        if re.match(r'[0-9a-f]+ <', l): on = f'<{fn}>' in l; continue
        if on and re.match(r'\s+[0-9a-f]+:\t', l): B.append(l.split('\t', 2)[-1].split('@')[0].strip())
    for i in range(max(len(T), len(B))):
        x = T[i] if i < len(T) else ''; y = B[i] if i < len(B) else ''
        print(('   ' if x == y else '>> ') + f'{x[:40]:40s}| {y[:40]}')
sys.exit(0 if ok else 1)
