# src/game/unit_020aa118.c

- `Unk0aa118_Nop_0ae054` (4 B): empty callback used as a no-op function pointer.
- `Unk0aa118_Thunk_020af8d8` (12 B): forwards its three arguments to `Unk0aa118_Unk_0af8d8`.
- `Unk0aa118_Unk_0ab454` (20 B): clears the +0x18 word of the object returned by `Unk044904_Unk_04509c`.
- `Unk0aa118_Clear814` (24 B): zero-fills the 0x814-byte structure at `p`.
- `Unk0aa118_PeekItem` (24 B): returns the item at the list cursor, or 0 once the cursor is at or past the end.
- `Unk0aa118_Unk_0ab4b8` (28 B): returns non-zero when the +0x18 word of the `Unk044904_Unk_04509c` object is set.
- `func_020ab4d4` (32 B): looks up the record for id `a`, then applies bit `b` (masked to 8 bits) through `func_02049aec(record, mask, 1)` and returns its result.
- `Unk0aa118_Unk_0afb40` (36 B): returns the table base for record id `data_0214d380[i]`, or 0 when `i` is 0.

## Hard list
- `Unk0aa118_Unk_0afb64`: decompiler-derived

## Not done in M1-T1077
- `Unk0aa118_SortRemaining`
- `Unk0aa118_Unk_0ab34c`
- `Unk0aa118_Unk_0af7cc`
- `Unk0aa118_Unk_0af7f8`
- `Unk0aa118_Advance`
- `Unk0aa118_Unk_0af8d8`
- `Unk0aa118_Unk_0ab8f8`
- `Unk0aa118_Unk_0af824`: decompiler-derived

## Not done in M1-T1078
- `Unk0aa118_GetTableD2f4`
- `Unk0aa118_CompareItems`
- `Unk0aa118_Unk_0afab0`
- `Unk0aa118_Unk_0afaf8`
- `Unk0aa118_Unk_0ab930`
- `Unk0aa118_Unk_0acb28`
- `Unk0aa118_FindRecord`
- `Unk0aa118_Unk_0afb90`: decompiler-derived
- `Unk0aa118_Unk_0ab4f4`: decompiler-derived

## Not done in M1-T1079
- `func_020afbdc`
- `Unk0aa118_AddUniqueId`
- `Unk0aa118_Unk_0afa60`
- `func_020aa130`
- `func_020aa188`
- `func_020aa298`

## Not done in M1-T1080
- `func_020ae270`
- `func_020af9f4`
- `func_020ae16c`
- `func_020af85c`
- `func_020ae058`
- `func_020ab2c8`
- `func_020ae1e8`
- `func_020ae0d8`

## Not done in M1-T1081
- `func_020ae978`
- `func_020aca7c`
- `func_020aea20`
- `func_020aad08`
- `func_020aeacc`
- `func_020aa42c`
- `func_020af90c`
- `func_020ab374`

## Not done in M1-T1082
- `func_020ab54c`
- `func_020ae888`
- `func_020aa4f4`
- `func_020ac97c`
- `func_020aabf4`
- `Unk0aa118_Unk_0acb74`
- `func_020aa2f0`
- `func_020aeb90`
- `Unk0aa118_Unk_0acb74`: decompiler-derived (plain+fix cleanup)
- `Unk0aa118_PeekItem`: hand-matched
- `Unk0aa118_Clear814`: hand-matched
- `Unk0aa118_CompareItems`: hand-matched
- `Unk0aa118_SortRemaining`: hand-matched
- `Unk0aa118_Advance`: hand-matched
- `Unk0aa118_Unk_0ab34c`: hand-matched
- `Unk0aa118_AddUniqueId`: hand-matched
- `Unk0aa118_Unk_0ab8f8`: hand-matched
- `Unk0aa118_Unk_0ab930`: hand-matched
- `Unk0aa118_Unk_0acb28`: hand-matched
- `Unk0aa118_GetTableD2f4`: hand-matched
- `Unk0aa118_FindRecord`: hand-matched
- `Unk0aa118_Unk_0af7cc`: hand-matched
- `Unk0aa118_Unk_0af7f8`: hand-matched
- `Unk0aa118_Unk_0af8d8`: hand-matched
- `Unk0aa118_Unk_0afa60`: hand-matched
- `Unk0aa118_Unk_0afab0`: hand-matched
- `Unk0aa118_Unk_0afaf8`: hand-matched
- `Unk0aa118_Unk_0afb40`: hand-matched
