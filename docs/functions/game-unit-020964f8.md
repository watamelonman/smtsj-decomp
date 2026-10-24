# game/unit_020964f8

All three functions match at 100% with the configured mwccarm toolchain.
Names remain neutral because instruction/data-use evidence establishes behavior,
but not the game meaning of the manager word, record categories, or selectors.

## `Unk0964f8_Unk_0964f8` (0x020964f8, 16 bytes)

No arguments. Calls `ImageObj_Unk_0773bc` and returns one unconditionally.
Evidence: the original consists of the call, constant return, and prologue/epilogue.

## `Unk0964f8_Unk_096508` (0x02096508, 64 bytes)

Borrows the manager from `Unk095560_GetManager`. Short-circuits three state
queries, clearing the manager word at +0x3b8 only when all return zero. Calls
`func_02077314` regardless and returns one. The local manager view documents
only that observed word; it does not assert the manager's full size.

## `func_02096548` (0x02096548, 524 bytes)

Takes a readable array of at least six `u16` IDs and an unsigned selector.
Skips zero IDs, missing records, and records whose +0x26 bits 6–10 are not five.
The resolver's record is borrowed. Its local view covers only observed fields.

When +0x28 bits 0–3 are zero, selectors 6/7 test bit 4, and selectors 8–17
respectively test bits 5–14. A set bit returns one immediately. Other selectors
leave the accumulated result unchanged on this path.

Otherwise, +0x26 bits 11–15 must equal the selector. Low-nibble values 1, 2, 3,
and 4 map to candidates 5, 1, 3, and 4; all others map to zero. A nonzero result
from `Unk02f078_IsAllowed_02f190(current, candidate)` replaces the accumulated
result. The result starts at zero and is returned after all six entries.

Evidence: halfword loads at +0x26/+0x28, shift-based field extraction, both
original jump tables, and the comparison-helper call. Unsigned halfword
bitfields preserve the original extraction instructions and shared loads.

## Hard list

None.
