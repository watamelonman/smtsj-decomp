# src/game/unit_020f470c.c

## M1-T370 — all eight functions match at 100%

The contracts below come from the ARM instructions at each function's address.
Work pointers are borrowed. The observed work area is 0xf8 bytes, with a state
word at +8, a flag at +0x50, and an embedded object beginning at +0x54.
Neutral names remain because these instructions do not establish game semantics.

- `Unk0f470c_Nop_0f4874` (4 bytes): immediately returns; no arguments or effects.
- `Unk0f470c_Thunk_020f7248` (12 bytes): interworking tail thunk to
  `func_020f7248`; the target literal and `bx ip` establish forwarding.
- `Unk0f470c_Unk_0f4908` (32 bytes): calls `0f7210` and, only for a
  nonzero result, passes work +0x54 to `func_020f82e0`.
- `func_020f4928` (36 bytes): calls the field-10 and field-0 accessors on
  work +0x54, then compares the state at +8 against 1. The original has
  an unconditional return after the comparison; the C early return preserves
  this otherwise redundant comparison under the project compiler.
- `Unk0f470c_Unk_0f4b80` (36 bytes): passes the incoming pointer to the
  field-10 accessor, then passes singleton +0x44 and that result to `0e8d90`.
  Returns the final callee's register result without assigning game semantics.
- `Unk0f470c_Unk_0f49f4` (40 bytes): calls `0ea70c`; states 1 and 2 return,
  while all other states call `func_020d1e94(1)`.
- `Unk0f470c_Unk_0f4764` (44 bytes): passes the work area, zero, and 0xf8
  to `func_02008848`, stores its address in `data_02176e00`, then calls
  `func_020f4790` on it. The zero-fill interpretation is supported by the
  explicit fill arguments and subsequent initialization.
- `Unk0f470c_Unk_0f4c20` (48 bytes): a nonzero `0e8bac` result gates
  `0f4b80(work)` followed by `0d1d94(func_020ea630(8), -1)`.

Validation: project build and objdiff match gate. Binary instruction equivalence
is the acceptance test; the card does not require additional host tests.

Hard list for M1-T370: none.

## Not done in M1-T372
- `func_020f4878`
- `func_020f4790`
- `Unk0f470c_Unk_0f4958`: decompiler-derived
- `Unk0f470c_Unk_0f4b44`: decompiler-derived
- `Unk0f470c_Unk_0f4ac0`: decompiler-derived

## Not done in M1-T371
- `Unk0f470c_Unk_0f4a1c`
- `func_020f470c`
- `func_020f4994`
- `func_020f4a60`
- `func_020f4ba4`
- `Unk0f470c_Unk_0f4a1c`: hand-matched
