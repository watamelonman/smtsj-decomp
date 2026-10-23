# src/game/unit_020f8448.c

## M1-T150

All eight targets match at 100% in objdiff. Evidence below comes from the
original ARM instructions, with caller evidence where stated. The work object
must provide storage through its callback at +0x94. Field meanings remain
neutral where the instructions establish only offsets.

- `Unk0f8448_GetUnkField10` (8 B): returns the word at +0x10, as shown by
  `ldr r0, [r0, #16]`. The unsigned API preserves its bits.
- `Unk0f8448_GetUnkField0` (8 B): returns the word at +0x00. Callers in
  `unit_020ee6dc.c` and `unit_020f09b4.c` use it as an entry-loop bound.
- `Unk0f8448_GetUnkField4` (8 B): returns the word at +0x04; the original
  load establishes the accessor name without assigning a semantic field name.
- `Unk0f8448_GetUnkField8` (8 B): returns the word at +0x08 through the
  existing unsigned API, preserving the original load behavior.
- `Unk0f8448_Thunk_020bcc7c` (12 B): calls `func_020bcc7c` without arguments.
  The original BL relocation supports the target-specific thunk name.
- `Unk0f8448_Thunk_020bccec` (12 B): calls `func_020bccec` without arguments.
  The original BL relocation supports the target-specific thunk name.
- `Unk0f8448_Unk_0f8468` (16 B): loads +0x10 and +0x08 and subtracts the
  latter from the former; the neutral name avoids inferring its use.
- `Unk0f8448_Init` (48 B): calls `func_020bcfc4(work, value)`, then
  `func_020bd1a8(work + 0x1C, work, work + 0x64, 1)`, then invokes the
  callback at +0x94 with the work pointer. The original BLs, address additions,
  and BLX establish this sequence. `func_020bcfc4` clamps the signed index
  against the +0x04 field and updates index-related fields; `func_020bd1a8`
  walks 12-byte entries and reads words from its third argument. The caller
  must initialize these fields and install the callback before calling.
  Opaque storage and the inferred word-array extent express these offsets
  without guessing entry semantics. The existing initializer name is retained.

## Other functions (M1-T151)

All three targets match at 100% (tools/hand/cmp.py and match_gate).

- `Unk0f8448_GetEntry` (52 B): returns 0 when `i < 0` or `i >= count` (+0x00,
  read through `Unk0f8448_GetUnkField0`); otherwise the first word of the
  12-byte entry `i` at +0x1C (`ldr [r0, i*12 + 28]`). The entry array is now a
  typed `Unk0f8448Entry unk_001c[6]` instead of a raw `FIELD` offset; the count
  of 6 is inferred from the 0x48-byte gap before +0x64.
- `func_020f84f4` (100 B): reads the s8 position at ctx+0x7482/+0x7483, passes
  ctx+0x04 and the position to `Unk02f2a8_Unk_034970`, then the result and the
  position to `Unk038fbc_Unk_039160`; maps the returned cell's first byte through
  `Unk10b4d0_Unk_10b71c`, then `func_0203611c(workArea+0x358, that)`, stores the
  result to state+0x18 (state = word at ctx+0x00) and sets state+0x14 to 4.
  The same +0x7482/+0x7483 cell position appears in CampStatus.c's lookups.
- `func_020f8558` (308 B): switch on s8 ctx+0x7481. Case 0, when state+0x14
  is 1: state+0x18 = state+0x14 = 2, state+0x08 = 0, `Unk0a0ce4_Unk_0a0da4(55)`,
  step++. Case 1, when state+0x14 is 1: looks up the cell at the work-area
  position (+0x364, +0x365); returns 1 unless the cell exists and its first byte
  is 16..19, in which case the position is copied to +0x7482/+0x7483,
  `func_020f84f4` runs, the step is reset and 0 is returned. Other steps return 0.
  Matching note: the range test must be written `(u8)(*cell + 0xF0) <= 3`;
  `*cell - 16` emits `sub` instead of the original `add #240`.

No descriptive names: no strings or callers establish what the step machine does.

## Hard list

None.
