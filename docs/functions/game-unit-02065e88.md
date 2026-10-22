# unit_02065e88

Setters on a shared game object (layout `GameObj`, field meanings unknown).

## M1-T1017 (verified at 100% objdiff)
- `Unk065e88_Nop_066c90`: empty body (bare `bx lr`, 4 bytes); address is stored in the
  callback table built by `Unk065e88_Unk_06646c`. No direct callers. Neutral name: nothing
  in the callers or data says what the callback does.
- `Unk065e88_SetPair04`: stores the two arguments in the adjacent u32 pair at +0x04/+0x08.
- `Unk065e88_SetUnkField20`: stores the u32 argument at +0x20.
- `Unk065e88_SetUnkField24`: stores the u32 argument at +0x24.
- `Unk065e88_SetUnkField28`: stores the u32 argument at +0x28.
- `Unk065e88_SetUnkField2C`: stores the u32 argument at +0x2C.
- `Unk065e88_SetUnkField30`: stores the u32 argument at +0x30.
- `Unk065e88_SetUnkField34`: stores the u32 argument at +0x34.

All eight are single `str r1,[r0,#off]` stores (or two for the pair) and were already present
and matching when the card started; this task added per-function contracts and re-verified
them with objdiff.
- `Unk065e88_SetUnkField3c`: decompiler-derived
- `Unk065e88_SetUnkFieldsc_10`: decompiler-derived
- `Unk065e88_Unk_068554`: decompiler-derived
- `Unk065e88_Unk_065eac`: decompiler-derived
- `Unk065e88_Unk_0663bc`: decompiler-derived

## Not done in M1-T1018
- `Unk065e88_Call_02065fc0`
- `Unk065e88_SetFlag3a`
- `Unk065e88_GetTable`
- `Unk065e88_Unk_06644c`: decompiler-derived
- `Unk065e88_Unk_065e88`: decompiler-derived
- `Unk065e88_Unk_066258`: decompiler-derived
- `Unk065e88_Unk_067d30`: decompiler-derived

## Not done in M1-T1019
- `Unk065e88_GetTableCount`
- `Unk065e88_GetTableEntry`
- `Unk065e88_SetMode`
- `Unk065e88_Unk_068564`
- `Unk065e88_Unk_065f30`: decompiler-derived

## Not done in M1-T1020
- `Unk065e88_Unk_066078`
- `Unk065e88_Unk_06646c`
- `Unk065e88_Unk_065ec0`
- `Unk065e88_Unk_0672fc`
- `func_02067418`
- `func_020684c0`
- `func_02066c94`

## Not done in M1-T1021
- `func_02067370`
- `func_02067c88`
- `func_020685b0`
- `func_02068658`
- `func_02065fc0`
- `func_02067b28`
- `func_02067bd8`
- `func_020674a4`

## Not done in M1-T1022
- `func_02067564`
- `func_020662d4`
- `func_02068bf8`
- `func_02067780`
- `func_020666bc`
- `func_02067888`
- `func_02067634`
- `func_02066d30`
- `Unk065e88_Call_02065fc0`: hand-matched
- `Unk065e88_SetFlag3a`: hand-matched
- `Unk065e88_GetTable`: hand-matched
- `Unk065e88_GetTableCount`: hand-matched
- `Unk065e88_GetTableEntry`: hand-matched
- `Unk065e88_SetMode`: hand-matched
- `Unk065e88_Unk_068564`: hand-matched
- `Unk065e88_Unk_065ec0`: hand-matched
- `Unk065e88_Unk_066078`: hand-matched
- `Unk065e88_Unk_06646c`: hand-matched
- `Unk065e88_Unk_0672fc`: hand-matched
