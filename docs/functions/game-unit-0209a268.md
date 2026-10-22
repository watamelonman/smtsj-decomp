# src/game/unit_0209a268.c

- `Unk09a268_Nop_09b3c8` (4 B): empty callback
- `func_0209a48c` (20 B): bit test. Returns 1 when bit `bit` of the byte at `p` is set, else 0;
  callers use bits 0-2 as a 3-value state selector and bits 3-5 as flags.
- `Unk09a268_Unk_09a7fc` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a820` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09c498` (16 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a80c` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a830` (20 B): decompiler-derived (Ghidra output, cleaned)
- `Unk09a268_Unk_09a870` (20 B): decompiler-derived (Ghidra output, cleaned)

## M1-T1010
- `Unk09a268_Unk_09c484` (20 B): returns the address of record `arg0` (stride 0x1c) in table
  `data_0213be64`.
- `Unk09a268_SetCtxUnk38` (24 B): stores its argument at +0x38 of the global context when present.
- `func_0209b720` (28 B): returns the global context's +0x34 word, or 0 when it is null.
- `Unk09a268_SetCtxUnk2c30` (32 B): stores two arguments at +0x2c and +0x30 of the global context
  when present.
- `Unk09a268_IsType1` (32 B): returns 1 when the pointer is non-null and its first byte is 1.
- `Unk09a268_SetBit` (36 B): sets or clears bit `bit` of the byte at `p` depending on `on`.
- `Unk09a268_Unk_09a844` (44 B): returns bit 5 of the state byte when GameState body +0x3e0 is
  nonzero, otherwise 1.
- `Unk09a268_Unk_09b3cc` (44 B): reloads the palette from the work's +0xc field when +0x2c is 0.

## Hard list
- `func_0209a4fc` (64 B): not implemented in C. The original scans 128 records
  (24-byte stride) at work +0x24a4, compares each +8 word to the supplied ID,
  and calls `func_02058a1c(table, index)` for every match. Indexed struct, explicit
  cursor, byte/word addressing, split-base, integer-address and embedded-table
  formulations were compiled with mwccarm 2.0/sp1p5. The closest builds were
  68 B: they retain the full table address and emit an extra register move;
  the original retains work +0xa4 and adds 0x2400 at the call. Leave the delinked
  implementation in place; a human can use `tools/decompme.py` for a scratch.

## M1-T1011
- `Unk09a268_Unk_09bb38` (48 B): returns 1 when slots 0 and 9 are both empty,
  using the two `Unk0bc1a8_IsSlotEmpty` calls. Verified 100%.
- `Unk09a268_Unk_09a458` (52 B): forwards the index from `func_0209a3ec`
  to `func_02058b14`, with the table at work +0x24a4. Verified 100%.
- `Unk09a268_FindEntry` (56 B): scans the 128 records for the first pair of
  matching +8/+16 words; returns the index or -1. Verified 100%.
- `Unk09a268_Unk_09c4a8` (56 B): null handle returns 0; otherwise looks up an
  entry, maps its first byte through `func_0209bb68` (or uses index 0 when
  absent), then returns that 0x1c-byte table record. Verified 100%.
- `func_0209a4fc` (64 B): unmatched; see the hard list above.
- `Unk09a268_Unk_09a77c` (64 B): tests bits 0-2 and returns the first set
  index, defaulting to 0 when none is set. Verified 100%.
- `Unk09a268_SetOnlyBit` (64 B): selects one of bits 0-2 using `SetBit`,
  preserving bits 3-7; values outside 0-2 clear all three. Verified 100%.
- `func_0209c4e0` (72 B): nullable record classifier. Its original jump table
  returns 1 for first-byte values 1, 3, 4, 5 and 6, otherwise 0. Grouping shared
  switch cases reproduces the original jump targets. Verified 100%.
- No new descriptive names were introduced; unknown record semantics remain neutral.

## M1-T1012
- `Unk09a268_Unk_09a3a0` (76 B): returns the first record whose +8/+16 words
  match both arguments, forwarded to `func_02058af8` by index; returns 1 when
  the 128-record table has no match. Verified 100%.
- `func_0209a53c` (76 B): scans the 128 records for the +8 word equal to the
  argument and returns the s32 pointed to by the record's first word,
  arithmetically shifted right by 12, or 0 when
  no record matches. Verified 100%.
- `func_0209a3ec` (108 B): allocates a free 128-record slot through
  `func_02058a64`, fills it from the four arguments plus a byte through
  `func_02058944`, and returns the index (or -1 when the table is full).
  Verified 100%.
- `func_0209a970` (144 B): classifies a position from the work area's +0x364/
  +0x365 coordinates. The (first argument - 30) jump table selects a distance
  limit of 0, 1 or 2, and a Manhattan distance at or below that limit returns
  2, otherwise 0. Verified 100%.
- `Unk09a268_Unk_09ae60` (92 B): fills the 60-byte handler table's size, zero
  word and six callbacks. Verified 100%.
- `Unk09a268_Unk_09beb0` (80 B): returns byte +0x1B of the record selected for
  the two arguments, or 0 when that record is absent. Verified 100%.
- `func_0209be20` (144 B): returns byte +0x1A of the record selected for the
  two arguments; kinds 20 and 23 are served by `Unk1122bc_Unk_112460` and
  `Unk1124f0_Unk_1125ac` instead, and an absent record returns 0. Verified 100%.
- `Unk09a268_Unk_09cb10` (88 B): sets bit 3, clears bit 4, selects
  the state bit from record 5 byte +0x19, then writes current-cell byte +1 = 1
  and halfword +2 = 0, and runs `func_0209c548` on its argument. Verified 100%.

## Not done in M1-T1013
- `func_0209cb68`
- `func_0209a588`
- `func_0209a884`
- `func_0209c768`
- `func_0209cd24`
- `func_0209cf54`
- `func_0209aebc`
- `func_0209c090`

## Not done in M1-T1016
- `func_0209c548`
- `func_0209aa00`
- `func_0209c1a0`

## Not done in M1-T1014
- `func_0209bd08`
- `func_0209ce30`
- `func_0209cbf8`
- `func_0209a268`
- `func_0209a638`
- `func_0209b5d8`
- `func_0209c9bc`
- `func_0209c854`
- `Unk09a268_Unk_09beb0`: hand-matched
- `Unk09a268_SetCtxUnk38`: hand-matched
- `Unk09a268_Unk_09a3a0`: hand-matched
- `Unk09a268_Unk_09a458`: hand-matched
- `Unk09a268_SetBit`: hand-matched
- `Unk09a268_FindEntry`: hand-matched
- `Unk09a268_Unk_09a77c`: hand-matched
- `Unk09a268_SetOnlyBit`: hand-matched
- `Unk09a268_SetCtxUnk2c30`: hand-matched
- `Unk09a268_Unk_09c4a8`: hand-matched
- `Unk09a268_IsType1`: hand-matched
- `Unk09a268_Unk_09ae60`: hand-matched

## M1-T1010 review corrections
- `Unk09a268_SetBit` now accepts `u8 *` with a full forward prototype; existing
  integer-address callers convert explicitly at the call boundary.
- `Unk09a268_Unk_09a844` uses a typed partial GameState body layout for +0x3e0
  and returns the bit-test result directly. `include/GameState.h` represents the
  body as opaque bytes, so the accessed body field is described locally.
- `Unk09a268_Unk_09c484` has a full index prototype. Its exceptional index-free
  call in `Unk09a268_Unk_09c498` preserves the original ABI (see DEC-002).
- All eight card functions and all 26 defined functions retain 100% objdiff matches.

- M1-T1012 review: work-area +0x35c/+0x364/+0x365 and table-record byte
  accesses now use typed partial layouts; the entry lookup shares a local base.
