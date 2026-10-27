# libs/unknown/lib_02049398

All nine functions keep the original `func_` symbol names because the human-owned
symbol/delink configuration requires them. The group/slot offsets and the 38- and
56-byte record strides below come from the original ARM loads, multiplies and calls.

## Source search

These are thin game-side wrappers over the already reconstructed NitroSDK TBB1/TBL1/MTBL
accessors in `libs/NitroSDK/sdk_0204fce8.c` and `sdk_0204ff30.c`. The public NitroSDK
sources supply those accessors, not these wrappers, so the wrappers are reconstructed
from the original instructions. `data_0215eea0` is the same borrowed singleton used by
`lib_0204915c`; this unit reads its +0x7994, +0x79a4 and +0x79a8 resource slots and
takes no ownership of the singleton, tables or returned entries.

## func_02049398 — 72 bytes

Takes an unsigned id. Looks up MTBL group one at singleton +0x7994 and returns its entry
for the id. If that entry is absent (zero), retries with id zero. The table and returned
entry are borrowed. Objdiff: 100%.

## func_020493e0 — 72 bytes

Same as `func_02049398` for MTBL group two. Callers pass small numeric ids; the fallback
to entry zero is the original absent-entry behaviour. Objdiff: 100%.

## func_02049428 — 92 bytes

Takes an unsigned id and resolves MTBL group zero at +0x79a4. Returns the entry only
when `func_0204ff30`/`func_0204ff64` show the id lies within the table's inclusive first
and last indexes. Otherwise returns zero without calling `func_0204fed8`. Objdiff: 100%.

## func_02049484 — 76 bytes

Takes an unsigned record index. Resolves TBL1 table zero at +0x79a8, reads its record
count and base through `func_0204fe18`/`func_0204fde0`, and clamps the index to
`count - 1` using the original unsigned compare. Returns `base + index * 38`, a borrowed
38-byte record. The table is assumed nonempty, as in the original clamp. Objdiff: 100%.

## func_020494d0 — 32 bytes

Takes a record id and signed delta. Obtains the current battle area through
`Unk044904_Unk_04502c` and forwards `(area, id, delta)` to `Unk044904_AddRecUnk08`, which
adds to the record's halfword at +8. Callers in the script and showing code pass an id
and the change of that record field. No ownership is transferred. Objdiff: 100%.

## func_020494f0 — 44 bytes

Takes the caller-owned list. Fills its first 0x3800 bytes with zero through the SDK byte
fill, then clears the three trailing words: the two bookkeeping words at +0x3800/+0x3804
and the record count at +0x3808. The chained assignment reproduces the original zero
materialised before the +0x3000 base adjustment. Objdiff: 100%.

## func_0204951c — 88 bytes

Takes the list and a readable 56-byte record. When the count at +0x3808 is already 256 the
function returns zero without writing. Otherwise it copies the record to
`list + count * 56`, increments the count and returns one. The 256 limit equals the
0x3800-byte array divided by 56. Objdiff: 100%.

## func_02049574 — 32 bytes

Takes two borrowed records and returns `a->unk_04 - b->unk_04`, or `a->unk_00 - b->unk_00`
when those words are equal. `func_02049594` passes this function to the sort helper
`func_02013c68` with a 56-byte element size, which establishes it as the record
comparator. Objdiff: 100%.

## func_02049594 — 140 bytes

Takes the caller-owned list. Scans the records in order; a record whose +0 word equals 1
ends the current run. For each such marker it sorts the run from `j` up to but excluding
the marker with 56-byte records through `func_02013c68` and comparator `func_02049574`,
then sets `j` to the marker index, so the marker is the first record of the next run.
When the scan ends it sorts the trailing run `[j, count)`, unless `j` already equals the
count. An empty list is untouched. Evidence: the `cmp #1` test, the two 56-stride `mla`
address computations, both `func_02013c68` calls and the `func_02049574` literal at
02049594..0204961c. The list is borrowed and its count is reloaded after each sort call
in case the helper changes it. Objdiff: 100%.

## Validation

The card sets `tests_required = false`. The hand comparator checked all nine functions
against the ROM instructions and relocations. `python3 tools/match_gate.py` reported every
C function in the changed file at 100%; `python3 tools/checksum.py` reported the linked
image byte-identical to the original; `python3 tools/anticheat.py` and the unittest suite
passed. The TU remains linked from the delink until a human marks it complete.

## Hard list

None.
