# src/game/unit_0202e000.c

M1-T649: all eight functions verified at **100% objdiff**. Existing candidates
were retained and the global-word accessors cleaned up using typed array indexing.
Evidence below is from the delinked ARM instructions; returned views remain borrowed.

| Function | Address / bytes | Evidence and contract |
| --- | --- | --- |
| `Unk02e000_Nop_02e3e0` | 0x0202e3e0 / 4 | `bx lr` only; intentional empty callback. |
| `Unk02e000_GetAddr_data_02140ac8` | 0x0202e0c0 / 12 | Loads relocated symbol address and returns it as a 32-bit address; no ownership transfer. |
| `Unk02e000_Thunk_0202e788` | 0x0202e798 / 12 | Loads GetWorkArea into ip and tail-jumps; identical borrowed return contract. |
| `Unk02e000_Set_data_0215dd24` | 0x0202e0f4 / 16 | Stores r0 at global offset zero; accepts any 32-bit word. |
| `Unk02e000_Get_data_0215dd24` | 0x0202e104 / 16 | Loads global offset zero without interpretation. |
| `Unk02e000_Unk_02e170` | 0x0202e170 / 16 | Loads global offset four; EnsureAlloc7718 stores the allocation here. Neutral name retained. |
| `Unk02e000_GetWorkArea` | 0x0202e788 / 16 | Calls Unk_02e774 and adds four; GetAreaRecord and TestFlag use the returned work view. Requires allocation. |
| `Unk02e000_GetSubBlock3a4` | 0x0202e8e0 / 16 | Calls GetWorkArea and adds 0x3a4; requires allocation, sub-block purpose unknown. |

## M1-T650

All eight targets verified at **100% objdiff**. Existing candidates already
matched; retained their arithmetic and call order, typed the initialization
callee argument, and replaced raw global-word loads with array indexing.
Address-valued `int` returns retain the existing TU ABI (32-bit ARM addresses).
No allocation ownership transfers and no bounds checks occur in these helpers.

| Function | Address / bytes | Instruction evidence and contract |
| --- | --- | --- |
| `Unk02e000_Unk_02e0ac` | 0x0202e0ac / 20 | Calls `func_0205a9d0(0xa0)` then `Unk_02e0cc`; purpose unconfirmed. |
| `Unk02e000_Unk_02e228` | 0x0202e228 / 20 | Calls `Unk_02e774`, adds 0x3c8 then 0x5c00; borrowed address at +0x5fc8. |
| `Unk02e000_Unk_02e774` | 0x0202e774 / 20 | Loads `data_0215dd24[1]`, adds 0x98; requires the allocation established by EnsureAlloc7718. |
| `Unk02e000_Unk_02e8b8` | 0x0202e8b8 / 20 | Calls `Unk_02e774`, adds 0x2fc then 0x800; borrowed address at +0xafc. |
| `Unk02e000_GetUnk094fe0Work` | 0x0202e8cc / 20 | Calls `Unk_02e774`, adds 0xfc then 0xc00. `Unk094fe0_Thunk_0202e8cc` in unit_02094fe0 returns this as its work block, supporting the existing name. |
| `Unk02e000_Unk_02e8f0` | 0x0202e8f0 / 20 | Loads `data_0215dd24[1]`, adds 0x90; Unk_02e180 initializes eight bytes at this borrowed address. |
| `Unk02e000_Call_02e4dc` | 0x0202e578 / 24 | Adds 500 to base, multiply-adds index times 100, tail-calls func_0202e4dc. Caller supplies valid record storage/index. |
| `Unk02e000_Call_02e520` | 0x0202e590 / 24 | Same record computation, tail-calls func_0202e520; caller retains storage ownership. |

## Hard list

No M1-T650 targets remain. Historical unresolved candidate:
- `Unk02e000_Unk_02e144`: decompiler-derived

## Not done in M1-T652
- `Unk02e000_SetMgrUnk38`
- `Unk02e000_HasField36`
- `Unk02e000_Unk_02e0cc`
- `Unk02e000_GetTier`
- `Unk02e000_EnsureAlloc7718`
- `Unk02e000_AddCounter5fc4`
- `Unk02e000_SetSlot`
- `Unk02e000_Unk_02e75c`: decompiler-derived
- `Unk02e000_Unk_02e884`: decompiler-derived
- `Unk02e000_Unk_02e89c`: decompiler-derived

## Not done in M1-T651
- `Unk02e000_Unk_02e5c4`
- `Unk02e000_ClearMgrUnk38`
- `Unk02e000_Call_02008848`
- `Unk02e000_Unk_02e740`
- `Unk02e000_GetAreaRecord`

## Not done in M1-T653
- `Unk02e000_Unk_02e7c0`
- `Unk02e000_Unk_02e180`
- `Unk02e000_GetSlot`
- `Unk02e000_GetRecordUnk1c`
- `func_0202e1b8`
- `func_0202e4dc`
- `Unk02e000_Unk_02e840`
- `Unk02e000_TestFlag`

## Not done in M1-T654
- `Unk02e000_GetRecordUnk1e`
- `Unk02e000_GetRecordUnk1f`
- `Unk02e000_SetRecord`
- `Unk02e000_FindEntryIndex`
- `Unk02e000_IsRecordAvailable`
- `Unk02e000_GetRecordFlag0`
- `Unk02e000_GetRecordFlag1`
- `Unk02e000_SetSlot40`

## Not done in M1-T655
- `Unk02e000_SetRecordUnk1c`
- `func_0202e520`
- `Unk02e000_GetRecord`
- `Unk02e000_FindIndex_02e3e4`
- `Unk02e000_SetBit_02e968`
- `Unk02e000_SetRecordFlag1f`
- `Unk02e000_SetRecordFlag1f_1`
- `Unk02e000_SetRecordUnk1e`

## Not done in M1-T656
- `Unk02e000_SetRecordUnk1f_2`
- `Unk02e000_GetSlotPtr`
- `func_0202e5dc`
- `func_0202e23c`
- `Unk02e000_Unk_02e0cc`: decompiler-derived (plain cleanup)
- `Unk02e000_Unk_02e180`: decompiler-derived (plain cleanup)
- `Unk02e000_Unk_02e5c4`: decompiler-derived (proto+fix cleanup)
- `Unk02e000_Unk_02e740`: decompiler-derived (plain+fix cleanup)
- `Unk02e000_ClearMgrUnk38`: hand-matched
- `Unk02e000_GetAreaRecord`: hand-matched
- `Unk02e000_SetSlot`: hand-matched
- `Unk02e000_GetSlot`: hand-matched
- `Unk02e000_SetMgrUnk38`: hand-matched
- `Unk02e000_EnsureAlloc7718`: hand-matched
- `Unk02e000_AddCounter5fc4`: hand-matched
- `Unk02e000_GetTier`: hand-matched
- `Unk02e000_Call_02008848`: hand-matched
- `Unk02e000_Unk_02e7c0`: hand-matched
- `Unk02e000_FindEntryIndex`: hand-matched
- `Unk02e000_Unk_02e840`: hand-matched
- `Unk02e000_HasField36`: hand-matched
- `Unk02e000_TestFlag`: hand-matched
- `Unk02e000_SetRecord`: hand-matched
- `Unk02e000_SetSlot40`: hand-matched
- `Unk02e000_GetRecordUnk1c`: hand-matched
- `Unk02e000_GetRecordUnk1e`: hand-matched
- `Unk02e000_IsRecordAvailable`: hand-matched
- `Unk02e000_GetRecordFlag0`: hand-matched
- `Unk02e000_GetRecordFlag1`: hand-matched
- `Unk02e000_GetRecordUnk1f`: hand-matched
- `Unk02e000_FindIndex_02e3e4`: hand-matched
- `Unk02e000_GetSlotPtr`: hand-matched
- `Unk02e000_SetBit_02e968`: hand-matched
- `Unk02e000_GetRecord`: hand-matched
- `Unk02e000_SetRecordUnk1c`: hand-matched
- `Unk02e000_SetRecordUnk1e`: hand-matched
- `Unk02e000_SetRecordFlag1f`: hand-matched
- `Unk02e000_SetRecordFlag1f_1`: hand-matched
- `Unk02e000_SetRecordUnk1f_2`: hand-matched
