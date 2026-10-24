# src/game/unit_0202cad4.c

## M1-T418 — verified at 100% objdiff

The original ARM instructions and relocations in the delinked object supply the
contracts below. Neutral names retain uncertainty about the surrounding subsystem.

- `Unk02cad4_Thunk_Unk065e88_Unk_065eac` (0x0202cee0, 12 bytes): calls
  `Unk065e88_Unk_065eac` without arguments; no return value is consumed.
- `Unk02cad4_Thunk_0206148c` (0x0202d150, 12 bytes): calls `func_0206148c`
  without arguments. The relocation supplies the destination evidence.
- `Unk02cad4_Unk_02cbdc` (0x0202cbdc, 16 bytes): stores its unsigned argument
  at `data_0213d338 + 8`; no validation or ownership transfer.
- `Unk02cad4_GetUnk00` (0x0202cbec, 16 bytes): returns the word at
  `data_0213d338 + 0`, including any sentinel value.
- `Unk02cad4_Unk_02ce80` (0x0202ce80, 20 bytes): calls
  `Unk065e88_Unk_065e88`, then selects entry zero through address 0x020e13ac.
- `Unk02cad4_ResetGlobals` (0x0202cbc0, 28 bytes): writes unsigned -1
  to the first three words at `data_0213d338`. The global view describes only
  these accessed fields, not the full allocation.
- `Unk02cad4_Unk_02ce94` (0x0202ce94, 76 bytes): returns immediately when
  `Unk0e1648_Unk_0e1648` is zero. Otherwise reads borrowed records 0 and 1,
  publishes the unsigned maximum of their +0x38 words through
  `Unk02e000_Set_data_0215dd24`, and stores state 1 through the +8 setter.
- `func_0202cdf4` (0x0202cdf4, 140 bytes): short-circuits four index-zero
  `func_020537b8` calls with masks 0x200, 0x100, 4, 8. When all succeed,
  changes a zero byte at `data_0215dd1c` to 1 and returns 1; an already
  nonzero byte returns 0. A failed test clears exactly a byte value of 1
  and returns 0. Other byte values remain unchanged. Returning the zero
  assignment in the clear branch reproduces the original register reuse.

## Other functions (outside M1-T418)

`Unk02cad4_SetupDisplayMode` retains its existing matching implementation.
`func_0202cad4`, `func_0202cbfc`, and `func_0202cd14` remain delinked.

## Hard list

None for M1-T418.
