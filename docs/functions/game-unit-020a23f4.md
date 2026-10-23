# game/unit_020a23f4

## M1-T182

All eight functions match at 100% in objdiff. Evidence below is from the
original ARM instructions at the listed entry points and their symbol relocations.
The work accessor returns the pointer stored in `data_02176b04`; queries borrow it.
Neutral names retain uncertainty about the larger lifecycle and block semantics.

| Function | Entry | Contract and evidence |
| --- | --- | --- |
| `Unk0a23f4_Thunk_020fd428` | `0x020a2504` | Literal-load/interworking branch to `Unk0fd268_IsField8Zero`; preserves its integer predicate result. |
| `Unk0a23f4_Thunk_020fd450` | `0x020a2588` | Literal-load/interworking branch to `Unk0fd268_IsField8Neg81`; preserves its integer predicate result. |
| `Unk0a23f4_Unk_0a2414` | `0x020a2414` | Calls `func_02061424` with the getter result still in r0 only when non-null. No work means no call. |
| `Unk0a23f4_IsSet_data_02176b04` | `0x020a242c` | Loads the global word and returns exactly zero or one according to whether it is nonzero. |
| `Unk0a23f4_Unk_0a23f4` | `0x020a23f4` | Saves the opaque 32-bit argument across the getter and passes it to `func_020a2d0c` only when work is absent. |
| `Unk0a23f4_Unk_0a25c0` | `0x020a25c0` | Returns zero without work; otherwise returns `ScanVisor_AllSlotsF28Is80(work + 0x24c)`. |
| `Unk0a23f4_Unk_0a2448` | `0x020a2448` | Returns zero without work; otherwise passes the embedded block at +0x428 to `Unk0a7d54_HasField8`. The ARM adds are +40 and +1024. |
| `Unk0a23f4_Unk_0a246c` | `0x020a246c` | Same null contract and +0x428 block, queried through `Unk0a7d54_IsField8Is3`. |

## Other existing definitions (M1-T183)

The existing `Unk0a23f4_Unk_0a2490`, `Unk0a23f4_IsField210Zero`,
`Unk0a23f4_IsField2cZero`, `Unk0a23f4_IsField14Zero`,
`Unk0a23f4_IsField210Is50`, `Unk0a23f4_IsField2cIs81`, and
`Unk0a23f4_IsField14IsM54` bodies are retained and also match at 100%.
`func_020a25e0` remains outside this card.

## Hard list

None for M1-T182.
