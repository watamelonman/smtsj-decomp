# src/game/unit_0203ca38.c

All six functions match the delinked original at 100% in objdiff.

- `Unk03ca38_Unk_03ca38` (72 bytes): runs the mode setup, then returns 3 when the
  mode lookup and distance check both succeed, otherwise 1.
- `Unk03ca38_Unk_03ca80` (84 bytes): dispatches on `func_0203ac00(0)` and forwards
  the mode-0 field-110 byte or the mode 1-3 table value to `Unk03aae8_Unk_03acf4`.
- `Unk03ca38_Unk_03cad4` (84 bytes): same dispatch as `Unk03ca38_Unk_03ca80`, using
  the second mode-indexed table (`Unk0979d8_Unk_09813c`).
- `Unk03ca38_Unk_03cb28` (84 bytes): same dispatch as `Unk03ca38_Unk_03ca80`, using
  the third mode-indexed table (`Unk0979d8_Unk_098154`).
- `func_0203cb7c` (136 bytes): switches on the active mode (0-5) and clamps
  `func_0203ac00(1)` through the per-mode setter; modes 1-3 share
  `Unk0979d8_Unk_09816c`. Always returns 1.
- `Unk03ca38_Unk_03cc04` (84 bytes): same dispatch as `Unk03ca38_Unk_03ca80`, using
  the fourth mode-indexed table (`Unk0979d8_Unk_09818c`).

## Hard list

None.
