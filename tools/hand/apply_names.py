"""apply_names.py : apply tools/hand/planned_names.json (old=new) to symbols.txt, src/, include/, docs/, tasks/.
Whole-word replacement; skips names already applied. Run on main, then gate + commit."""
import os, re, json, glob, sys; sys.path.insert(0, os.path.dirname(__file__))
from hl import SJ
p = f'{SJ}/tools/hand/planned_names.json'
pl = json.load(open(p)) if os.path.exists(p) else {}
files = [f'{SJ}/config/arm9/symbols.txt'] + [f for d in ('src', 'include', 'docs', 'tasks') for f in glob.glob(f'{SJ}/{d}/**/*', recursive=True) if os.path.isfile(f)]
sym = open(files[0]).read(); todo = {o: n for o, n in pl.items() if re.search(rf'^{o}\b', sym, re.M) and not re.search(rf'^{n}\b', sym, re.M)}
if todo:
    pat = re.compile(r'\b(' + '|'.join(map(re.escape, todo)) + r')\b')
    for f in files:
        s = open(f).read(); t = pat.sub(lambda m: todo[m[1]], s)
        if t != s: open(f, 'w').write(t)
print(len(todo))
