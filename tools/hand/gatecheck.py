#!/usr/bin/env python3
"""Gate-equivalent check (covers cmp.py's blind spot: a new same-file callee can drop an existing caller).
usage: gatecheck.py CANDIDATE.c [CANDIDATE.c ...]  (each replaces the tracked src file with the same basename)
Temporarily copies the candidates into src/game, builds, runs ./objdiff-cli report generate
(as tools/match_gate.py does), prints every function below 100% in those units, then restores the
originals and rebuilds. Exit 1 if any C-defined function in them is below 100%."""
import json, os, shutil, subprocess, sys
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from match_gate import c_functions
env = dict(os.environ, PATH=os.path.expanduser('~/.local/bin') + ':' + os.environ['PATH'])
saved, bad = {}, []
try:
    for c in sys.argv[1:]:
        dst = subprocess.run(['git','ls-files','src/*/'+os.path.basename(c)],capture_output=True,text=True).stdout.split()[0]
        saved[dst] = open(dst).read(); shutil.copy(c, dst)
    subprocess.run('nice ninja', shell=True, env=env, check=True, capture_output=True)
    subprocess.run(['./objdiff-cli', 'report', 'generate', '-o', '/tmp/handwork/gc_report.json'], check=True, capture_output=True)
    rep = {u['name']: u for u in json.load(open('/tmp/handwork/gc_report.json'))['units']}
    for dst in saved:
        cf = set(c_functions(dst))
        for f in rep[dst[:-2]].get('functions', []):
            p = f.get('fuzzy_match_percent', 0)
            if f['name'] in cf and p < 100: bad.append(f"{dst}: {f['name']} {p:.2f}%")
finally:
    for dst, s in saved.items(): open(dst, 'w').write(s)
    subprocess.run('nice ninja', shell=True, env=env, capture_output=True)
print('\n'.join(bad) or 'gatecheck: all 100%'); sys.exit(1 if bad else 0)
