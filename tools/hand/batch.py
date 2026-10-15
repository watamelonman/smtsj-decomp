"""batch.py spec.py : SPECS=[(tu, [(fn, code)], prelude)]. Inserts each fn in address order into a copy of
the TU (creating it if absent), compiles once, compares every fn. Writes candidates to $TMP/handwork/b/."""
import sys, os, json; sys.path.insert(0, os.path.dirname(__file__))
from hl import *
ns = {}; exec(open(sys.argv[1]).read(), ns)
outd = os.path.join(WORK, 'b'); os.makedirs(outd, exist_ok=True); res = {}
for tu, items, prelude in ns['SPECS']:
    p = f'{SJ}/{tu}'
    s = open(p).read() if os.path.exists(p) else f'/* {tu}: matched functions. */\n#include "types.h"\n'
    for i, (fn, code) in enumerate(items):
        s = insert(s, (prelude + '\n' if i == 0 and prelude else '') + code, fn)
    out = f'{outd}/{os.path.basename(tu)}'; open(out, 'w').write(s)
    obj, err = compile_(s)
    if not obj: print(tu, 'FAIL compile\n   ', err.replace('\n', '\n    ')); res[tu] = False; continue
    bad = [(fn, m) for fn, _ in items for ok, m in [compare(fn, obj)] if not ok]
    print(tu, 'OK' if not bad else 'FAIL', ''.join(f'\n    {f}: {m}' for f, m in bad)); res[tu] = not bad
json.dump(res, open(f'{outd}/res.json', 'w'))
