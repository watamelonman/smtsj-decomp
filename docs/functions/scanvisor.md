# ScanVisor

- `ScanVisor_Nop_0a34a4`, `ScanVisor_Nop_0a34a8`: empty callbacks.
- `ScanVisor_GetConst20`: returns 20. `ScanVisor_GetConst6`: returns 6.
- `ScanVisor_Unk_0a45f8`: get u32 at 0x14.
- `ScanVisor_Thunk_020fc6b8`: forwards to `Unk0fc584_SetDir`.
- `ScanVisor_GetSlot`: read `slots[index]` (table at 0x1C0).
- `ScanVisor_SetRange`: set the pair at 0x1C/0x20.
- `ScanVisor_SetUnkFields24_28`: decompiler-derived
- `ScanVisor_Unk_0a4904`: decompiler-derived
- `ScanVisor_ClearUnkField198`: decompiler-derived
- `ScanVisor_Thunk_020a4600`: decompiler-derived
- `ScanVisor_Get_data_02176b04`: decompiler-derived
- `ScanVisor_Unk_0a3620`: decompiler-derived
- `ScanVisor_Unk_0a465c`: decompiler-derived
- `ScanVisor_Unk_0a4a30`: decompiler-derived
- `ScanVisor_Unk_0a4644`: decompiler-derived
- `ScanVisor_Unk_0a2a1c`: decompiler-derived
- `ScanVisor_Unk_0a2ab0`: decompiler-derived
- `ScanVisor_Unk_0a2acc`: decompiler-derived
- `ScanVisor_Unk_0a27e0`: decompiler-derived
- `ScanVisor_Unk_0a2800`: decompiler-derived

## Not done in M1-T985
- `ScanVisor_Unk_0a4a18`
- `ScanVisor_Unk_0a2980`
- `ScanVisor_Unk_0a2b18`: decompiler-derived
- `ScanVisor_Unk_0a2b38`: decompiler-derived
- `ScanVisor_Unk_0a29a0`: decompiler-derived
- `ScanVisor_Unk_0a29c4`: decompiler-derived
- `ScanVisor_Unk_0a2a8c`: decompiler-derived
- `ScanVisor_Unk_0a2a38`: decompiler-derived

## Not done in M1-T986
- `ScanVisor_Unk_0a3254`
- `ScanVisor_Unk_0a2b58`
- `ScanVisor_Unk_0a28f4`: decompiler-derived
- `ScanVisor_Unk_0a2a60`: decompiler-derived
- `ScanVisor_Unk_0a42c4`: decompiler-derived

## Not done in M1-T987
- `ScanVisor_SetField34`
- `ScanVisor_SetRangeA`
- `ScanVisor_SetField214`
- `ScanVisor_Unk_0a4a44`
- `ScanVisor_Unk_0a2920`
- `ScanVisor_Unk_0a2ae8`: decompiler-derived
- `ScanVisor_Unk_0a29e8`: decompiler-derived
- `ScanVisor_Unk_0a2b7c`: decompiler-derived
- `ScanVisor_Unk_0a4544`: decompiler-derived
- `ScanVisor_Unk_0a27a8`: decompiler-derived

## Not done in M1-T988
- `ScanVisor_Unk_0a2950`
- `ScanVisor_Unk_0a379c`
- `ScanVisor_FindEnt20`
- `ScanVisor_Unk_0a284c`: decompiler-derived
- `ScanVisor_Unk_0a28b0`: decompiler-derived
- `ScanVisor_Unk_0a2660`: decompiler-derived
- `ScanVisor_Unk_0a273c`: decompiler-derived

## Not done in M1-T989
- `ScanVisor_FindSlotByKey`
- `ScanVisor_Unk_0a4950`
- `ScanVisor_AllSlotsF28Is80`
- `ScanVisor_Unk_0a3760`

## Not done in M1-T990
- `ScanVisor_Unk_0a4910`
- `ScanVisor_SetById`
- `func_020a3ac0`
- `ScanVisor_AnySlotField14`
- `ScanVisor_ResetBits`
- `ScanVisor_Unk_0a4578`
- `ScanVisor_Unk_0a4864`
- `ScanVisor_Unk_0a48b4`

## Not done in M1-T991
- `func_020a4df0`
- `ScanVisor_LoadSearchParts`
- `ScanVisor_Unk_0a3274`
- `func_020a30b4`
- `func_020a466c`
- `func_020a2c90`
- `func_020a4370`
- `ScanVisor_Unk_0a42f0`
- `ScanVisor_Unk_0a2e5c`: decompiler-derived

## Not done in M1-T992
- `func_020a2c00`
- `func_020a269c`
- `func_020a3008`
- `func_020a2f3c`
- `func_020a3630`
- `ScanVisor_Draw`
- `func_020a2d0c`
- `ScanVisor_LoadSearchParts`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4a44`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4950`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4864`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4910`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Unk_0a48b4`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Unk_0a42f0`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Draw`: hand-matched
- `ScanVisor_SetById`: hand-matched
- `ScanVisor_Unk_0a4a18`: hand-matched
- `ScanVisor_SetField34`: hand-matched
- `ScanVisor_SetRangeA`: hand-matched
- `ScanVisor_SetField214`: hand-matched
- `ScanVisor_Unk_0a2920`: hand-matched
- `ScanVisor_Unk_0a2950`: hand-matched
- `ScanVisor_Unk_0a2980`: hand-matched
- `ScanVisor_Unk_0a2b58`: hand-matched
- `ScanVisor_ResetBits`: hand-matched
- `ScanVisor_Unk_0a3254`: hand-matched
- `ScanVisor_Unk_0a3760`: hand-matched
- `ScanVisor_Unk_0a379c`: hand-matched
- `ScanVisor_FindEnt20`: hand-matched
- `ScanVisor_Unk_0a4578`: hand-matched
- `ScanVisor_FindSlotByKey`: hand-matched
- `ScanVisor_AnySlotField14`: hand-matched
- `ScanVisor_AllSlotsF28Is80`: hand-matched
- `ScanVisor_Unk_0a3274`: hand-matched
