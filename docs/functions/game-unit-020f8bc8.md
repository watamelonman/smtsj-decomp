# game/unit_020f8bc8

All six functions match at 100% in objdiff. Names remain the original neutral
address names because the assembly establishes field operations but does not
establish a game-facing name for this subsystem. Local structures describe only
the fields accessed here; pointers are borrowed and no ownership transfers.
Negative record indices select `Unk02e000_Thunk_0202e788`; nonnegative indices
select `Unk02e000_GetAreaRecord`. Callers must provide valid entry pointers and,
for the cost deduction helper, a valid selected record.

## func_020f8bc8 (380 bytes)

Calculates an amount using the entry's low 12 effect bits, or its byte at +0x3d
when those bits are zero. Evidence: calls to `func_020b0b5c` and `func_020b0bd4`.
Six halfword entry IDs come from `Unk096754_Unk_097204` or record +0x28.
Entries whose +0x26 bits 11..15 equal 19 contribute one or two to the multiplier
index when their +0x28 low nibble is 5 or 6, respectively. The multiplier is read
from `data_02150ec8`; thus the index is 0..12. Record bytes +0x6e/+0x38 and signed
bytes +0x1a/+0x12 feed the calculation. Returns zero for an empty amount or a
missing nonnegative record. Bitfields preserve the original shift extraction.

## func_020f8d44 (96 bytes)

Filters a status using the upper nibble at entry +0x32. Evidence: nibble shifts
and comparisons in the original. Returns -1 for zero selector/status. Selector
12 accepts statuses other than 1; 13 accepts 2 or 8; 14 accepts any nonzero
status; other selectors require equality. It returns the accepted status.

## func_020f8da4 (96 bytes)

Deducts the unsigned byte at entry +0x22 from a signed halfword resource at
main-record +0x1e or area-record +0x20, then clamps negative stored results to
zero. Evidence: subtract, halfword store/reload, and signed comparison.

## func_020f8e04 (496 bytes)

Applies an entry to a selected target, returning zero when it changes a status
or increases the current value. A missing area record returns one.
Evidence: accesses to status +0x6c/+0x34, current +0x1c/+0x1e and maximum
+0x12/+0x0a. When `Unk0cb0d0_Unk_0cb274` succeeds, status 1 is cleared and the
calculated amount is added, with a minimum stored value of one. Otherwise status
1 exits unchanged; the status filter may clear another status, and status 7
prevents amount processing. A nonzero amount is added only below maximum;
clamping to maximum follows even when the calculated amount is zero. The source
index, rather than the target index, selects the calculation's supporting record.

## func_020f8ff4 (156 bytes)

Looks up an entry with `func_020cb1a0`, applies it to the main record and all
nonnegative signed slot indices at work-area +0x348..+0x353, and deducts cost
once from the source if any application returned zero. Evidence: twelve-slot
loop and calls to the application/deduction helpers. Returns one for lookup
failure or no changes, otherwise zero.

## func_020f9090 (76 bytes)

Looks up an entry and applies it to one target, deducting cost from the source
only when application returns zero. Evidence: direct calls to the three helpers
above. A failed lookup returns one; otherwise the application result is preserved.

## Validation and hard list

Each function passed standalone relocation-aware instruction comparison and the
objdiff match gate. No hard functions remain. The unit continues linking from
the original delinked object until a human changes its completion status.
