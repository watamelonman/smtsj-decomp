"""candidates.py [maxsize=0x50] : small ARM functions in C TUs not yet defined in src -> tools/hand/small.json"""
import re, json, sys, os
SJ = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
mx = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x50
tus = []; cur = None
for l in open(f'{SJ}/config/arm9/delinks.txt'):
    m = re.match(r'^(\S+\.c):', l)
    if m: cur = m[1]; continue
    m = re.search(r'\.text\s+start:0x(\w+) end:0x(\w+)', l)
    if m and cur: tus.append((int(m[1], 16), int(m[2], 16), cur)); cur = None
SKIP = set(json.load(open(f'{SJ}/tools/hand/skips.json'))) if os.path.exists(f'{SJ}/tools/hand/skips.json') else set()
out = []
for l in open(f'{SJ}/config/arm9/symbols.txt'):
    m = re.match(r'(\S+) kind:function\((\w+),size=0x(\w+)\) addr:0x(\w+)', l)
    if not m or m[2] != 'arm': continue
    n, sz, a = m[1], int(m[3], 16), int(m[4], 16)
    if sz > mx or n in SKIP: continue
    tu = next((t for s, e, t in tus if s <= a < e), None)
    if not tu or not os.path.exists(f'{SJ}/{tu}'): continue
    if re.search(r'\b%s\s*\([^;]*\)\s*\{' % re.escape(n), open(f'{SJ}/{tu}').read()): continue
    out.append(dict(fn=n, addr=hex(a), size=hex(sz), tu=tu))
json.dump(out, open(f'{SJ}/tools/hand/small.json', 'w'), indent=0)
print(len(out), 'candidates')
