# libs/unknown/lib_02049620

All ten functions in this unit match at 100% with the configured mwccarm 2.0/sp1p5.
The unit is game-side code, not NitroSDK/MSL: its queue scan calls the
name-registration routine `func_0209d44c` (see `docs/functions/game-unit-0209d42c.md`),
which formats 32-byte name slots. There is therefore no public NitroSDK/MSL
source to copy; the C below is reconstructed from the original instructions.
The existing `func_` linker names are kept because the symbol and delink
configuration is human-owned.

The queue layout is the same 0x3800-byte array documented for
`libs/unknown/lib_02049398`: 256 records of 56 (0x38) bytes, then two
bookkeeping words at +0x3800/+0x3804 and the live count at +0x3808. The
sort routine in that unit already treats a +0 word of 1 as a run terminator and
reads the +4 word as an unsigned key, which matches the record scan here. Only
the fields this unit touches are named in the header: the +0 kind/tag word, the
+4 key word, the +0x10 byte and the name at +0x14. The record array is
caller-owned and never allocated here.

`func_02049620` (176 bytes) and `func_0204980c` (396 bytes) complete the unit.
`func_0204980c` works on a different object than the queue: a 3-axis state whose
packed halfword at +4 holds fields of width 2,2,2,2,2,3,3 (bits 0..15). The
caller `func_0204a720` passes `object + 0x17c` as that state. The source update
is borrowed and has the same layout, which is why one `Unk04980cState` type is
used for both arguments.

## func_02049620 — 176 bytes

Takes the caller-owned queue and returns when the count at +0x3808 is zero.
Otherwise it walks `count` records from the start. A record whose +0x10 byte is
zero has its +4 word made relative to the first such record (the baseline is
stored the first time and reused); every other record retires itself when its
kind is 2, 3, 4, 13 or 17, resets the baseline when the kind is (still) 1, and
clears +4. Evidence: the `for (i = 0; i < count; i++)` entry guard
`cmp #0`/`popls`, the `ldrb r2, [r0, #16]`, the signed switch tree
`cmp #13`/`#17`/`#4`/`#3`/`#2`, the `ldreq` baseline, the `sub`/`str` of +4,
`str lr` for the kind clear and `moveq r4, ip` for the baseline reset. The
queue is borrowed. Objdiff: 100%.

## func_020496d0 — 84 bytes

Takes the caller-owned queue. Reads the cursor at +0x3800 and returns
immediately when it is not below the count at +0x3808. Otherwise it walks the
56-byte records from the cursor: a record whose +0 word is 1 ends the scan
without advancing the cursor, a record whose +0 word is 2 passes its +0x14 name
to `func_0209d44c`, and every other record is skipped. The count is reloaded
after each call, because the name registration may change it. Evidence: the
`cmp #1`/`cmp #2` dispatch, the `add r0, r6, #0x14` argument, the 0x38 `mla`
and the count reload at 0204970c. The queue is borrowed. Objdiff: 100%.

## func_02049724 — 32 bytes

Takes the queue and returns the address of the record at the cursor, or null
when the cursor is at or past the count. The original computes the address with
a conditional 0x38 `mla`, so the cursor/count compare is unsigned. The returned
record is borrowed. Objdiff: 100%.

## func_02049744 — 40 bytes

Takes the queue, increments the cursor at +0x3800 and compares it with the count
at +0x3808. When the new cursor is at or past the count it stores the count back
and returns 0; otherwise it returns 1. The conditional store and the 0/1 returns
are the original's `strhs`/`movhs`/`movlo`. Objdiff: 100%.

## func_0204976c — 64 bytes

Takes a caller-owned base and a count. Starting at the newest slot, it clears
`count` 12-byte slots through the SDK byte-fill `func_02008848` and then stores
zero to the leading word, exactly the two stores in the original (the word store
is redundant after the fill but changes no behaviour). The countdown is written
as `while (--count >= 0)`: that form produces the original's pre-test `subs`/
`popmi` plus the bottom-test `subs`/`bpl`. Objdiff: 100%.

## func_020497ac — 16 bytes

Takes one 12-byte slot and clears it by tail-calling `func_0204976c` with a
count of one. Evidence: the literal `func_0204976c` address and `mov r1, #1` in
the original thunk. Objdiff: 100%.

## func_020497bc — 20 bytes

Takes one 6-byte slot and clears it by tail-calling the SDK byte fill with a
zero value and a size of six. Evidence: the `func_02008848` literal and the
`mov r1, #0`/`mov r2, #6` arguments. Objdiff: 100%.

## func_020497d0 — 44 bytes

Takes a caller-owned base and a count. Starting at the newest slot, it clears
`count` 6-byte slots by calling `func_020497bc` and advancing the cursor by six
bytes. The `while (--count >= 0)` form reproduces the original's pre-test and
bottom-test decrements; the slot stride is the `add r5, r5, #6` step. Objdiff:
100%.

## func_020497fc — 16 bytes

Takes one 6-byte slot and clears it by tail-calling `func_020497d0` with a count
of one. Evidence: the `func_020497d0` literal and `mov r1, #1`. Objdiff: 100%.

## func_0204980c — 396 bytes

Takes a destination state and a source update with the same layout and first
applies the three signed axis bytes. An update byte of -5 stops positive
motion (a positive destination axis is cleared) and -6 stops negative motion
(a negative axis is cleared); any other nonzero byte is added to the axis and
the result is clamped to [-4, 4]. It then merges the packed halfword at +4 field
by field (widths 2,2,2,2,2,3,3), copying only fields whose source value is
nonzero. Evidence: the `ldrsb` axis loads, the -4/-5/-6 constants built from
`mvn #3`, the clamps against 4 and -4, and the seven `ldrh [r1, #4]`
extract/insert sequences. Both objects are borrowed. Objdiff: 100%.

## Validation

The card sets `tests_required = false`. The hand comparator checked every
function's instructions and relocations against the ROM. `python3
tools/match_gate.py` reported all ten C functions at 100%, `python3
tools/checksum.py` reported the linked image byte-identical to the original,
and the anticheat gate and unittest suite passed. The TU remains linked from the
delink until a human marks it `complete` in `config/arm9/delinks.txt`.

## Hard list

None.
