"""asm.py fn... : one-line target disassembly with symbolized calls/literals."""
import sys, re, os; sys.path.insert(0, os.path.dirname(__file__))
from hl import *
for fn in sys.argv[1:]:
    a = BYNAME[fn][0]; n = size(fn); out = []
    for ad, w, t in dis(a, n):
        m = re.match(r'(bl?|b\w\w)\s+0x([0-9a-f]+)', t)
        if m: t = f"{m[1]} {SYM.get(int(m[2],16)+0x2000000,('?',))[0]}"
        elif w in SYM and 0x2000000 <= w < 0x2400000 and ad >= a + n - 16 and not t.startswith(('push','pop','mov','ldr','str','add','sub','cmp','b')):
            t = '.word ' + SYM[w][0]
        out.append(t)
    print(f'{fn}({n:#x}): ' + ' ; '.join(out))
