# bl01: func_020937a0 (-> Unk090e60_Unk_0937a0) was merged with tools/hand/hmerge.py from a
# candidate that defines it above its caller func_020934c8; in its address-order slot (end of
# file) objdiff scored the caller at 99.92%. Built from wip/u90.c via the spec below:
#   TU = 'src/game/unit_02090e60.c'; FIX replaces the partial work struct with the full layout
#   (Unk090e60Group/Pair/Bytes/Meta/Result/Entry/Area/Work) and adds the callee prototypes.
SPECS = [('src/game/unit_02090e60.c', [], '')]
