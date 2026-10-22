# src/game/unit_020bd5f0.c

## M1-T1134 (all 100% in objdiff)
- `Unk0bd5f0_Unk_0bd5f0` (36 B): predicate over two words of the object in r0; true only when the
  word at +8 is 2 and the word at +4 is >= 2.
- `Unk0bd5f0_Unk_0bd614` (28 B): loads the word at `data_0213c4d4[index]` and forwards it to
  `func_02057ddc`, which stores it into four consecutive words of `data_02168b24`; returns 0.
- `Unk0bd5f0_Unk_0c1ad8` (28 B): tail-calls `func_020c8008(0, 0, 0, 0)`.
- `Unk0bd5f0_IsSpecialId` (28 B): membership test for ids 5, 6, 8 and 22.
- `Unk0bd5f0_Unk_0c20f0` (32 B): calls `func_020c1b94` with the object in `data_02176bb0` when that
  pointer is non-null.
- `Unk0bd5f0_Unk_0c7588` (32 B): lexicographic comparison of two 16-bit key pairs (word at +2 first,
  then word at +0); returns the difference.
- `Unk0bd5f0_SetCtxUnk1b8` (24 B): sets the word at +0x1b8 of the context in `data_02176bb4` to 1.
- `func_020c1968` (40 B): returns whether the signed byte at offset `0x348 + index` of the shared
  work area (`Unk02e000_GetWorkArea`) is non-negative.

## Not done in M1-T1135
- `Unk0bd5f0_IsState22or24`
- `Unk0bd5f0_Unk_0c8510`
- `Unk0bd5f0_Unk_0c20bc`
- `Unk0bd5f0_AnyIdWithFlagsMid`
- `Unk0bd5f0_AnyIdWithoutFlagsMid`
- `Unk0bd5f0_Unk_0c7f70`
- `Unk0bd5f0_Unk_0c7fbc`
- `Unk0bd5f0_Unk_0c842c`
- `Unk0bd5f0_Unk_0c75a8`: decompiler-derived

## Not done in M1-T1136
- `Unk0bd5f0_Unk_0c1870`
- `Unk0bd5f0_Unk_0c1918`
- `func_020c84c0`
- `func_020bd9c4`
- `func_020c18c0`
- `func_020c2578`
- `func_020c72a4`
- `Unk0bd5f0_Unk_0c2050`: decompiler-derived

## Not done in M1-T1137
- `func_020c1f40`
- `func_020c7bc8`
- `func_020c1c4c`
- `func_020c83a0`
- `func_020c1d88`
- `func_020c7b30`
- `func_020c1af4`

## Not done in M1-T1138
- `func_020c1fb0`
- `func_020c1414`
- `func_020c1b94`
- `func_020c1cd0`
- `func_020c67a0`
- `func_020c0c5c`
- `func_020c1770`
- `func_020c7304`
- `Unk0bd5f0_SetCtxUnk1b8`: hand-matched
- `Unk0bd5f0_IsSpecialId`: hand-matched
- `Unk0bd5f0_Unk_0bd5f0`: hand-matched
- `Unk0bd5f0_Unk_0c1870`: hand-matched
- `Unk0bd5f0_Unk_0c1918`: hand-matched
- `Unk0bd5f0_Unk_0c20bc`: hand-matched
- `Unk0bd5f0_AnyIdWithFlagsMid`: hand-matched
- `Unk0bd5f0_AnyIdWithoutFlagsMid`: hand-matched
- `Unk0bd5f0_Unk_0c7f70`: hand-matched
- `Unk0bd5f0_Unk_0c7fbc`: hand-matched
- `Unk0bd5f0_Unk_0c842c`: hand-matched
- `Unk0bd5f0_IsState22or24`: hand-matched
- `Unk0bd5f0_Unk_0c8510`: hand-matched
