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

## M1-T183

All eight functions match at 100% in objdiff. The TU now reads the work object
through a typed local struct `Unk0a23f4Work` (named fields at +0x00, +0x14, +0x2c,
+0x210, +0x24c, +0x428) instead of raw offsets. `ScanVisor.c` keeps its own local
view of what may be the same object; the two are not folded because the evidence
is only matching offsets. Every predicate below returns 0 when there is no work.

| Function | Entry | Contract and evidence |
| --- | --- | --- |
| `Unk0a23f4_Unk_0a2490` | `0x020a2490` | Passes the embedded block at +0x428 (adds of +40 and +1024) to `Unk0a7d54_Unk_0a8648` and returns its result. |
| `Unk0a23f4_IsField210Zero` | `0x020a24b4` | 1 when the s32 at +0x210 is 0. |
| `Unk0a23f4_IsField2cZero` | `0x020a24dc` | 1 when the s32 at +0x2c is 0. |
| `Unk0a23f4_IsField14Zero` | `0x020a2510` | 1 when the s32 at +0x14 is 0. |
| `Unk0a23f4_IsField210Is50` | `0x020a2538` | 1 when the s32 at +0x210 is 50. |
| `Unk0a23f4_IsField2cIs81` | `0x020a2560` | 1 when the s32 at +0x2c is 81. |
| `Unk0a23f4_IsField14IsM54` | `0x020a2594` | 1 when the s32 at +0x14 is -54 (`cmn r0, #54`). |
| `func_020a25e0` | `0x020a25e0` | 1 only when the word at +0x00 is 0 or 2 and `IsField210Is50`, `IsField2cIs81`, `Thunk_020fd450`, `IsField14IsM54` and `Unk_0a25c0` all pass, checked in that order with early exit. It keeps its symbols.txt name because renaming would mean editing a protected config. Matching it needed the mode test written as an enclosing `if` and the last check written as `if (!x) return 0; return 1;`. |

## Hard list

None for M1-T182 or M1-T183.
