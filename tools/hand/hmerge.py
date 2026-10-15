"""hmerge.py tu newsrc 'fn=Name,...' [desc] : merge a hand-written TU through its forge card.
Worktree off main -> write TU + docs line -> match_gate -> commit -> anticheat -> forge regate.
On MERGED, planned renames go to tools/hand/planned_names.json (apply later with apply_names.py)."""
import sys, os, re, json, subprocess; sys.path.insert(0, os.path.dirname(__file__))
from hl import SJ
sh = lambda c, cwd=SJ: subprocess.run(c, shell=True, cwd=cwd, capture_output=True, text=True)
tu, src, ren = sys.argv[1:4]; desc = sys.argv[4] if len(sys.argv) > 4 else 'hand-matched'
ren = dict(x.split('=') for x in ren.split(',') if x); fns = list(ren); new = open(src).read()
card = None
for x in sorted(os.listdir(f'{SJ}/tasks')):
    s = open(f'{SJ}/tasks/{x}').read()
    if f'Write `{tu}`' in s and any(f'`{f}`' in s for f in fns): card = x; break
if not card: print('nocard'); sys.exit(1)
tid = '-'.join(card.split('-')[:2]); docp = re.search(r'docs = \["(\S+)"\]', open(f'{SJ}/tasks/{card}').read())[1]
wt = f'{SJ}/.forge/worktrees/{tid}'
sh(f'git worktree remove --force {wt} 2>/dev/null; git worktree prune; git branch -D forge/{tid} 2>/dev/null')
r = sh(f'git worktree add -q -b forge/{tid} {wt} main')
if r.returncode: print(r.stderr); sys.exit(1)
os.makedirs(os.path.dirname(f'{wt}/{tu}'), exist_ok=True); open(f'{wt}/{tu}', 'w').write(new)
d = open(f'{wt}/{docp}').read() if os.path.exists(f'{wt}/{docp}') else f'# {tu}\n\n'
open(f'{wt}/{docp}', 'w').write(d.rstrip('\n') + '\n' + ''.join(f'- `{f}`: {desc}\n' for f in fns))
g = sh('FORGE_BASE=main nice -n 10 python3 tools/match_gate.py', cwd=wt); print(g.stdout.strip()[-200:])
sh(f'git add -A && git commit -qm "{tid}: hand-match {len(fns)} in {os.path.basename(tu)}"', cwd=wt)
a = sh('FORGE_BASE=main python3 tools/anticheat.py', cwd=wt)
if g.returncode or a.returncode:
    print('GATE FAIL', a.stdout[-200:]); sh(f'git worktree remove --force {wt}; git branch -D forge/{tid}'); sys.exit(1)
r = sh(f'nice -n 10 timeout 700 /workspace/re-forge/bin/forge regate {tid}'); out = (r.stdout + r.stderr).strip()
print(out.splitlines()[-1] if out else 'no output')
if 'MERGED' in out.upper():
    p = f'{SJ}/tools/hand/planned_names.json'; pl = json.load(open(p)) if os.path.exists(p) else {}
    pl.update({k: v for k, v in ren.items() if v and v != k}); json.dump(pl, open(p, 'w'), indent=1)
