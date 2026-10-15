"""next.py [n=8] [after_fn] : show next n candidates from small.json with branch-target disassembly and TU."""
import sys, os, json, subprocess; sys.path.insert(0, os.path.dirname(__file__))
from hl import *
n = int(sys.argv[1]) if len(sys.argv) > 1 else 8
c = json.load(open(f'{SJ}/tools/hand/small.json'))
if len(sys.argv) > 2: a = BYNAME[sys.argv[2]][0]; c = [x for x in c if int(x['addr'], 16) > a]
for x in c[:n]:
    print(f"== {x['fn']} {x['size']} {x['tu']}")
    print(subprocess.run([sys.executable, f'{SJ}/tools/hand/asm.py', x['fn']], capture_output=True, text=True).stdout.split(': ', 1)[1].replace(' ; ', '\n   ').rstrip())
