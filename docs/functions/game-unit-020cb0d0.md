# game/unit_020cb0d0 — M1-T165

All eight targets match the delinked ARM instructions at 100% objdiff with
mwccarm 2.0/sp1p5, using the configured build flags. Neutral names are retained
because the table contents' domain meaning has not been established.

| Function | Observed behavior and contract |
| --- | --- |
| `Unk0cb0d0_Unk_0cb190` | Subtracts the unsigned halfword keys at +0x20 of two non-null records. Both lookup functions pass this comparator to `func_02011810`. |
| `func_020cb1a0` | Resolves group 11/table 0 with `020445d0`, obtains its base with `0204fde0` and count with `0204fe18`, then searches with stride 0x40. Only the input's low 16 bits initialize the comparison key. Returns a borrowed record pointer or null. |
| `Unk0cb0d0_Unk_0cb1f8` | Resolves group 11/table 0, invokes the base and count helpers and discards their results. |
| `func_020cb21c` | Same lookup sequence as `020cb1a0`, for table 1 and stride 0x2a. Returns a borrowed record pointer or null. The key is truncated to 16 bits. |
| `Unk0cb0d0_Unk_0cb274` | Requires the halfword at +0x32 to have high nibble 14 or 1 and the byte at +0x23 to equal 3 or 7. The input must cover +0x33. |
| `func_020cb2a8` | Returns true for values 0, 1, 5 and 6 in bits 5–8 of the word at +0x24. The switch reproduces the original seven-entry branch table. |
| `Unk0cb0d0_IsAbove15e` | Signed comparison against 0x15e. Callers `020cb0d0` and `020cb12c` choose table 1 when true and table 0 otherwise; this is evidence for the existing boundary-test name. |
| `Unk0cb0d0_Unk_0cb304` | Looks up its input through `020cb1a0`, returning true only for a non-null record with byte +0x23 equal to 7. |

The local record type describes accessed offsets, not a common table stride:
table 1 records end before +0x32. Separate search-key types preserve the exact
0x40/0x2a stack allocations without initializing unused bytes, since the comparator
reads only +0x20. No module boundary changes were needed.

## Hard list

None for M1-T165.
