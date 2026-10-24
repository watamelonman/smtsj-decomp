# game/unit_020f0be0

## func_020f0be0

196 bytes, ARM. Returns an option's prerequisite result as 0 or 1. The first
callback argument is unused. Options 0 and 1 test the borrowed work area's
halfwords at offsets 0 and 2; option 2 tests `Unk0e8228_Unk_0e84e4`.
Option 3 requires check 0x703, a positive `Unk0e8228_Unk_0e8488` result,
and zero results from both remaining checks. Option 4 and out-of-range
options return 1. The accessor is called even for options that do not use it.
Names remain neutral because instruction and call evidence does not establish
what these options represent. Standalone byte/relocation comparison: identical.

## func_020f0ca4

520 bytes, ARM. Reads the selection through `Unk0f8448_GetUnkField10`, captures
`data_02176dfc`, obtains the current context, and performs two common resets.
Selections 0..4 dispatch to the original helper sequences. Selection 0 branches
on `Unk0e8228_IsField4One`; selections 1 and 2 use handles 31 and 32 and
conditionally set values 4 and 8. Selection 3 forwards value 5. Selection 4
passes the context's embedded record at offset 0x1e8 and its first word to
`func_020e8d38`, conditionally calls `Unk0e8228_Unk_0e8d18`, and updates the
shared handle. Other selections have no additional effects. Pointers are borrowed;
record extent and option semantics are unknown. Standalone byte/relocation
comparison: identical.

## Hard list

None.
