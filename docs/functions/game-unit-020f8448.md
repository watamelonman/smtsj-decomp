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

- `Unk0f8448_GetEntry`: existing matching implementation retained unchanged.
- `func_020f84f4` and `func_020f8558`: outside this card.

## Hard list

None for M1-T150.
