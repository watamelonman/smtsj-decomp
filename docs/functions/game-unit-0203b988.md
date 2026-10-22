# src/game/unit_0203b988.c

All six functions in this translation unit (`0x0203b988`-`0x0203bba4`) are matched
at 100% in objdiff.

- `Unk03b988_Unk_03b9b8` (36 bytes): reads selection 0, applies it through
  `func_0204fb14`, runs the unit `03aae8` callback, and returns 1.
- `func_0203b9dc` (216 bytes, ARM): reads selection 0; when it is 12, writes 0, 2,
  or 1 via `Unk118b04_Set_data_02151b28` depending on the `0x404`/`0x405` flags
  queried through `Unk0e651c_Unk_0e666c`. It then dispatches on
  `func_02095818()`: mode 0 calls `Unk09e72c_Unk_09e72c`, 2 calls
  `func_020df330`, 3 calls `Unk116598_Unk_116700`, 4 calls
  `Unk116598_Unk_117968`, and 5 calls `ImageBgDual3D_Unk_1259c4`; all except the
  default path then call `Unk02dcfc_SetCode25`. Returns 3.
- `Unk03b988_Unk_03b988` (48 bytes): reads selections 0 and 1, forwards both to
  `func_0204faf0`, and returns 1.
- `Unk03b988_Unk_03bab4` (76 bytes): reads selection 0 and, for modes 2 and 3,
  forwards it through `Unk0de678_Unk_0df348` or `Unk116598_Unk_116738` into
  `Unk02dcfc_SetCode25`. Returns 3.
- `Unk03b988_Call_0e66f0` (44 bytes): reads selections 0 and 1 and forwards
  selection 1 plus the low byte of `selection 0 - 1` to
  `Unk0e651c_Unk_0e66f0`. Returns 1.
- `Unk03b988_Unk_03bb2c` (120 bytes): reads selections 0 through 4. If
  `func_020baba4()` is set, restores the `Unk11fc20` state and returns 1;
  otherwise it clears the state, stores 27 at offset `+24` of the object at
  `Unk03aae8_Unk_03ad14() + 232`, and returns 0.

## Hard list

None.
