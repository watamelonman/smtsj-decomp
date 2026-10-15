"""batch.py spec.py : SPECS=[(tu, [(fn, code)], prelude[, fixups])]; fixups = [(old, new)] exact
replacements applied to the TU first (e.g. correcting a stale `int f();` declaration the card owns). Inserts each fn in address order into a copy of
the TU (creating it if absent), compiles once, compares every fn. Writes candidates to $TMP/handwork/b/."""
import sys, os, json, re; sys.path.insert(0, os.path.dirname(__file__))
from hl import *
ns = {}; exec(open(sys.argv[1]).read(), ns)
outd = os.path.join(WORK, 'b'); os.makedirs(outd, exist_ok=True); res = {}
for tu, items, prelude, *fx in ns['SPECS']:
    p = f'{SJ}/{tu}'
    s = open(p).read() if os.path.exists(p) else f'/* {tu}: matched functions. */\n#include "types.h"\n'
    for old, new in (fx[0] if fx else []):
        assert s.count(old) == 1, f'fixup not unique: {old!r}'; s = s.replace(old, new)
    for fn, code in items:  # auto-fix a stale implicit-int declaration when the definition is void
        if re.match(rf'void\s+{fn}\s*\(', code.strip()) and s.count(f'int {fn}();\n') == 1:
            s = s.replace(f'int {fn}();\n', f'void {fn}();\n')
    for i, (fn, code) in enumerate(items):
        s = insert(s, (prelude + '\n' if i == 0 and prelude else '') + code, fn)
    out = f'{outd}/{os.path.basename(tu)}'; open(out, 'w').write(s)
    obj, err = compile_(s)
    if not obj: print(tu, 'FAIL compile\n   ', err.replace('\n', '\n    ')); res[tu] = False; continue
    bad = [(fn, m) for fn, _ in items for ok, m in [compare(fn, obj)] if not ok]
    print(tu, 'OK' if not bad else 'FAIL', ''.join(f'\n    {f}: {m}' for f, m in bad)); res[tu] = not bad
# gate-equivalent check (objdiff via gatecheck.py): catches an existing caller dropping below 100%
import subprocess
for tu, ok in list(res.items()):
    if ok and subprocess.run(['git', '-C', SJ, 'ls-files', '--error-unmatch', tu], capture_output=True).returncode == 0:
        r = subprocess.run([sys.executable, f'{SJ}/tools/hand/gatecheck.py', f'{outd}/{os.path.basename(tu)}'],
                           cwd=SJ, capture_output=True, text=True)
        if r.returncode: print(tu, 'GATE FAIL\n   ', (r.stdout + r.stderr).strip().replace('\n', '\n    ')); res[tu] = False
json.dump(res, open(f'{outd}/res.json', 'w'))
