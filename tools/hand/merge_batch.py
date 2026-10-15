"""merge_batch.py spec.py 'fn=Name,...' [msg] : hmerge every TU of a passing batch (one card each), then
apply names on main, rebuild, checksum + match_gate, commit. Stops on the first failure."""
import sys, os, subprocess, json; sys.path.insert(0, os.path.dirname(__file__))
from hl import SJ, WORK
ns = {}; exec(open(sys.argv[1]).read(), ns); ren = dict(x.split('=') for x in sys.argv[2].split(',') if x)
msg = sys.argv[3] if len(sys.argv) > 3 else f'Name hand matches ({os.path.basename(sys.argv[1])})'
res = json.load(open(f'{WORK}/b/res.json'))
env = dict(os.environ, PATH=os.path.expanduser('~/.local/bin') + ':' + os.environ['PATH'])
run = lambda c: subprocess.run(c, shell=True, cwd=SJ, capture_output=True, text=True, env=env)
for tu, items, *_ in ns['SPECS']:
    if not res.get(tu): print(tu, 'not OK in last batch; skipped'); continue
    names = ','.join(f'{fn}={ren.get(fn, fn)}' for fn, _ in items)
    r = run(f'python3 tools/hand/hmerge.py {tu} {WORK}/b/{os.path.basename(tu)} "{names}"')
    last = r.stdout.strip().splitlines()[-1:] or ['?']; print(tu, last[0])
    if 'merged' not in last[0]: sys.exit(1)
print('names', run('python3 tools/hand/apply_names.py').stdout.strip())
run('nice ninja')
c = run('python3 tools/checksum.py').stdout.strip().splitlines()[-1]; print(c)
g = run('FORGE_BASE=HEAD python3 tools/match_gate.py'); print(g.stdout.strip().splitlines()[-1])
if 'byte-identical' not in c or g.returncode: sys.exit(1)
run(f'git add -A && git commit -qm "{msg}"'); print(run('git log --oneline -1').stdout.strip())
