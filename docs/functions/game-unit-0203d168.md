# game/unit_0203d168

## Unk03d168_Unk_03d168

Matched 20-byte ARM function. Calls `Unk03e43c_Unk_03fa28` and
`Unk03aae8_Unk_03acf4`, then returns 1. The original object's call relocations
establish this ordering; the underlying gameplay purpose is unproven.

## Unk03d168_Unk_03d17c

Matched 32-byte ARM function. Consumes command argument zero through
`func_0203ac00`, calls `Unk03e43c_Unk_03fa3c`, then runs the same two callbacks
as the preceding function and returns 1. Neutral names retained because the
call sequence alone does not establish a gameplay name.

## func_0203d19c — hard list

Remains supplied by the delinked original, with no C definition in this TU.
A readable C candidate reached 99.89% in objdiff, but was removed as required
by the card. A human can create a scratch with `tools/decompme.py`.

The 760-byte ARM function consumes four command arguments: a signed-16-bit
selector, signed-16-bit decrement, signed-16-bit field selector, and boolean
ScanVisor flag. Negative decrements return 1 immediately. The pending visor
path writes 15 through the context pointer at offset 0xe8 to offset 0x18,
calls `ScanVisor_SetField214(1)`, and returns zero. Otherwise selectors 0–5
choose the primary entry, three active slots, or all entries; field selector
zero decrements one field and other values decrement the adjacent field.
Reserve entries have stride 0x3c from work-area offset 0x74, with signed-byte
indices at offset 0x348, bounded by 12 entries and a negative sentinel.

The candidate matched the instruction sequence after moving zero initialization
past early returns and separating the three selection-array stores. The remaining
difference was register allocation in the pending visor path: the original loads
the nested pointer into r2 and materializes 15 in r1; the candidate reverses r1
and r2. Explicit temporaries, signed/unsigned field types, pointer indexing, and
inline setter variants did not resolve that difference. No inline assembly or
binary data was used.
