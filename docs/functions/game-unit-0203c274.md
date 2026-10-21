# src/game/unit_0203c274.c

Script command handlers; each reads its arguments with `func_0203ac00(i)`. All four are hand-matched (100%).
Symbol names are unchanged (renaming means editing config/arm9/symbols.txt, which is protected; no evidence
yet for descriptive names).

- `func_0203c274`: hand-matched. Reads a BGR555 colour, then byte args `a` and `b`. If `b` is non-zero, it
  clamps `b` to 2 when `a <= 10`, converts the colour to RGBA8888 (each channel `<< 3`, alpha 0xFF), calls
  `func_020fd190(rgba, a, b)`, then `Unk02dcfc_Unk_02df00(owner->unk_00e8, (s16)((a + 1) * b))`.
  Returns 3. The channels have to be `u8` locals: with `u32` they compile to lsl/lsr pairs instead of and/lsl/and.
- `func_0203c320`: hand-matched. Reads `id` (u8) and a flag (s16), then switches on `func_02095818()`
  (mode 0..5, mode 1 does nothing). `id == 0` calls the mode's no-arg routine, otherwise `(id, flag != 0)`.
  Returns 1.
- `Unk03c274_Unk_03c434`: hand-matched. Forwards arg 0 to `Unk0a0ce4_Unk_0a0da4`; reads arg 1 and ignores it. Returns 1.
- `Unk03c274_Unk_03c45c`: hand-matched. Forwards arg 0 to `Unk0caea8_Unk_0caf98`. Returns 1.

## Hard list
- none
