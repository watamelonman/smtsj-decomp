# src/game/unit_0202d15c.c

## M1-T575: verified matches

All eight functions below match the delinked ARM original at 100% objdiff.
The existing C bodies already matched; this task verifies them and adds typed
manager declarations and contracts. Manager storage is borrowed, never allocated
or freed here. Evidence is the original instructions and the manager accessors
in `src/game/unit_02095560.c`; unknown field meanings retain neutral names.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk02d15c_Unk_02d934` | 16 B | Calls `Unk095560_GetManagerSub3a8` and loads its word at +4 (0x0202d93c). |
| `Unk02d15c_Unk_02d944` | 16 B | Calls the same accessor and loads its word at +0 (0x0202d94c). |
| `Unk02d15c_Call_02d91c` | 20 B | Tail-calls the pair setter with 0 and -1 (0x0202d15c–0x0202d16c), resetting the second and first words respectively. |
| `Unk02d15c_Unk_02d81c` | 20 B | Writes the -1 sentinel to `data_0213d898` (0x0202d824). `Unk02d15c_ReleaseImage` tests this sentinel before releasing the stored image handle. |
| `Unk02d15c_Unk_02d91c` | 24 B | Stores argument 1 at +0 and argument 0 at +4 of the manager subarea, using STM at 0x0202d92c. No field semantics are inferred. |
| `Unk02d15c_GetManagerRecord` | 28 B | Returns manager + 0xb4 + index * 0x54 (ADD/MLA at 0x0202dc50–0x0202dc58). No bounds check; callers must supply a valid index. `Unk095560_GetManager` supplies the manager base. |
| `Unk02d15c_IsStatus1OrNeg` | 36 B | Returns 1 for negative indices; otherwise compares `Unk094fe0_Call_020950b4(index)` with 1 at 0x0202d35c. This comparison supports the existing status-predicate name. |
| `Unk02d15c_IsStatus0OrNeg` | 36 B | Returns 1 for negative indices; otherwise compares the same status result with 0 at 0x0202d380. Both predicates return exactly 0 or 1. |

No new behavioral tests are required by this card: objdiff checks the generated
instructions against the original, and checksum verifies the linked image.
The TU remains linked from the delink until a human marks it complete.

## Hard list

None for M1-T575. Entries below describe other cards and are outside this task.

## M1-T576: verified matches

All eight functions below match the delinked ARM original at 100% objdiff.
Seven bodies already existed and were verified; `func_0202d170` was added from
its original instructions. Helper declarations now specify the observed argument
and return types. No new module boundary or ownership contract is introduced.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `func_0202d170` | 40 B | Tests `Unk095560_Unk_095d1c()` against -1 at 0x0202d17c. Returns 1 for other values; otherwise resets the manager pair through `Unk02d15c_Call_02d91c` at 0x0202d18c and returns 0. Index semantics remain unknown. |
| `Unk02d15c_ReleaseImage` | 40 B | At 0x0202d7f4, tests the stored image handle against -1 and calls `ImageObj_Unk_077894(handle, 0)` for other values. Does not clear the stored handle. The image helper call supports the existing name. |
| `Unk02d15c_IsMode0Match` | 60 B | At 0x0202d330, calls `func_0202d668(managerIndex, a, 0, 0, -1)` and returns whether the result equals 1. The dispatcher mode argument supports the existing name. |
| `Unk02d15c_IsMode1Match` | 60 B | At 0x0202d854, calls the same dispatcher with `(managerIndex, 0, 1, a, -1)` and returns whether the result equals 1. |
| `Unk02d15c_Setup` | 60 B | Helper sequence at 0x0202d880, 0x0202d894, and 0x0202d89c: call `Unk02dcfc_SetField68`, forward `(a,c,b,0)` to `Unk095560_Unk_095cd8`, then forward d to `Unk095560_Unk_095d08`. Always returns 1. This initialization sequence supports the existing name. |
| `Unk02d15c_ResetRecord` | 76 B | Stores at 0x0202dc84..0x0202dc9c zero word 6 and words 1..5 of the auxiliary record, copy b to word 0 and manager-record offset 0x50, then return 1. The caller supplies an index valid for both borrowed records. These reset stores support the existing name. |
| `Unk02d15c_Unk_02d9a8` | 80 B | Unsigned switch at 0x0202d9a8 maps 0..4 to 26,29,20,23,32 and defaults to 26. Constant semantics remain unknown. |
| `Unk02d15c_Unk_02d9f8` | 80 B | Unsigned switch at 0x0202d9f8 maps 0..4 to 27,30,21,24,33 and defaults to 27. Constant semantics remain unknown. |

Validation: match gate passes, anticheat passes, all nine unit tests pass,
and checksum reports all artifacts byte-identical. No behavioral tests were
added (`tests_required = false`); instruction matching checks every target body.
No M1-T576 hard functions remain. The TU remains linked from the delink.
`Unk02d15c_Unk_02da48` is outside this card.

## M1-T577: verified matches

All eight functions match the delinked ARM original at 100% objdiff.
Seven existing bodies were verified; `func_0202d710` was added from the original
instructions. The dispatcher now has a typed eight-word request and borrowed
record return pointer. No storage ownership or module boundary changes.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk02d15c_Unk_02da48` | 80 B | Unsigned switch at 0x0202da48 maps 0..4 to 28,31,22,25,0; defaults to 28. Constant meanings remain unknown. |
| `Unk02d15c_FindRecordEntry` | 80 B | At 0x0202dcac, obtains the manager record, loads count +8 and pointer +12, and scans unsigned first bytes at stride 0x30. Returns the first matching index or -1, including for a null record. The scan supports the existing name. |
| `Unk02d15c_Unk_02d954` | 84 B | Tests signed condition +20: zero succeeds; one compares helper result with signed +24 using the unsigned work-area value +0x35c and signed key +22. Other conditions succeed. Record is borrowed. |
| `Unk02d15c_Unk_02d794` | 96 B | Dispatches eight words `(managerIndex,-1,1,13,-1,managerPairFirst,a,b)` and returns whether the result is non-null. Stack stores at 0x0202d7b4 onward establish the layout. |
| `Unk02d15c_MapKind_02d2a0` | 108 B | Switch at 0x0202d2a0 reverses the kind mapping for supported values: 0,1,2,5,6,7,4 map to 0,2,1,3,4,5,7. Defaults to zero. |
| `Unk02d15c_MapKind_02d22c` | 116 B | Switch at 0x0202d22c maps 0,2,1,3,4,5,7 to 0,1,2,5,6,7,4; defaults to zero. Caller 0x0202d710 loads signed record kind +6 and stores the mapped output at +40, supporting the existing name. |
| `Unk02d15c_Unk_02d8a8` | 116 B | Resolves c using record a +16, returning zero for null record or negative result. Finds the entry and calls setup with either `(a,b,entry,-1)` or `(a,b,-1,resolvedIndex)`; the latter returns one. Calls and branches at 0x0202d8a8 establish the behavior. |
| `func_0202d710` | 132 B | Dispatches `(managerIndex,-1,0,-1,-1,managerPairFirst,a,b)`; null returns zero. Otherwise maps signed result +6 into caller +40, copies result +8 into the stored image handle, and returns one. The loads and stores at 0x0202d76c..0x0202d784 establish the contract. Caller storage must be writable through byte 43. |

Validation: match gate reports 100% for every defined function in this TU;
anticheat, unit tests and checksum pass. Behavioral tests are not required by
this card; instruction matching checks the target implementations directly.
No M1-T577 hard functions remain. The TU remains linked from the delink until
a human marks it complete.

## Not done in M1-T578
- `func_0202d198`
- `func_0202d668`
- `func_0202da98`
- `func_0202d390`
