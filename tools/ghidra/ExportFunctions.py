# Headless Ghidra post-script (Jython or PyGhidra; only the flat API is used).
# @category re-forge
# Writes $REFORGE_OUT/functions.json: per function address, size, name, a suggested name
# (from referenced debug/assert strings), referenced strings, callers/callees and Ghidra's C
# as a starting point for the worker. It does not rename symbols in the split config; names
# go into symbol files only through reviewed task cards.
import json, os, re
from ghidra.app.decompiler import DecompInterface

out_dir = os.environ.get("REFORGE_OUT", "build/ghidra")
if not os.path.isdir(out_dir):
    os.makedirs(out_dir)
ifc = DecompInterface()
ifc.openProgram(currentProgram)
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()
res = []


def strings_referenced(fn):
    found = []
    for ins in listing.getInstructions(fn.getBody(), True):
        for ref in ins.getReferencesFrom():
            d = getDataAt(ref.getToAddress())
            if d is not None and d.hasStringValue():
                found.append(str(d.getValue())[:80])
    return found


def suggest(strs):
    for s in strs:
        m = re.search(r'([A-Za-z_][A-Za-z0-9_]{3,})\s*\(', s)
        if m:
            return m.group(1)
    return ""

for fn in fm.getFunctions(True):
    if monitor.isCancelled():
        break
    strs = strings_referenced(fn)
    r = ifc.decompileFunction(fn, 60, monitor)
    c = r.getDecompiledFunction().getC() if r and r.decompileCompleted() else ""
    res.append({
        "name": fn.getName(), "addr": "0x%08x" % fn.getEntryPoint().getOffset(),
        "size": fn.getBody().getNumAddresses(),
        "suggested": suggest(strs), "strings": strs[:8],
        "callers": [f.getName() for f in fn.getCallingFunctions(monitor)][:20],
        "callees": [f.getName() for f in fn.getCalledFunctions(monitor)][:20],
        "ghidra_c": c[:8000],
    })
with open(os.path.join(out_dir, "functions.json"), "w") as f:
    json.dump(res, f, indent=1)
print("re-forge: exported %d functions" % len(res))
