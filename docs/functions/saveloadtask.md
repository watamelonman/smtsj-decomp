# src/SaveLoadTask.c

- `SaveLoadTask_Draw`: hand-written (see comment in source)

## Not done in M1-T896
- `func_020dfd9c`
- `SaveLoadTask_SelectEntry`
- `func_020e0080`
- `func_020dfc64`
- `func_020e1490`
- `func_020df99c`
- `func_020e0168`

## Existing functions outside M1-T894
- `SaveLoadTask_Unk_0df94c`: decompiler-derived
- `SaveLoadTask_Unk_0df86c`: decompiler-derived
- `SaveLoadTask_Unk_0dff68`: decompiler-derived

## Not done in M1-T895
- `func_020e0034`
- `func_020dff20`
- `func_020dfe80`
- `SaveLoadTask_Unk_0df814`
- `func_020df8c4`

- `SaveLoadTask_SelectEntry`: save/load menu entry dispatch (cases 0-7).
- `SaveLoadTask_Unk_0df814`: decompiler-derived (plain cleanup)

## M1-T894: verified matching helpers

All eight functions below match at 100% with the configured ARM compiler.
Evidence is the original ARM instructions in the delinked SaveLoadTask object;
neutral symbol names are retained because the broader field semantics are unknown.
The work pointer is borrowed, must be valid, and addresses the original layout.
No new behavioral tests are required by this card: objdiff checks the generated
instructions and relocations, while checksum checks the linked original image.
The TU remains linked from its delink pending human completion.

| Function | Size | Contract and instruction evidence |
| --- | ---: | --- |
| `SaveLoadTask_Unk_0e006c` | 20 | Stores 8 at work +8, then the two supplied words at +0xc/+0x10. |
| `SaveLoadTask_Unk_0dfed4` | 24 | Calls `func_020dfd9c` with the borrowed work pointer, selector, and flags (1, 0, 0). The fifth argument is passed on the stack. |
| `SaveLoadTask_Unk_0df7f8` | 28 | Indexes `data_02176bf0` with stride 24, loads its signed first word, and multiplies by three. Caller supplies a valid table index and a value whose product fits a signed word. |
| `SaveLoadTask_Unk_0dffec` | 36 | Stores arg1+1 and arg1+4 at +0x18/+0x1c, 6 at +0x20, and 0 at +0x34. Caller supplies additions representable as signed words. |
| `SaveLoadTask_Unk_0e0010` | 36 | Stores fixed values 1, 2, 6, 0 at +0x18, +0x1c, +0x20, +0x34. |
| `SaveLoadTask_Unk_0e137c` | 48 | Calls `Unk0bc1a8_Unk_0bc6d4(1)`, passes work +0xe8 to `func_02053000`, then clears that word and `data_02176c78` +4. Callee ownership semantics remain unconfirmed. |
| `SaveLoadTask_Unk_0df7c4` | 52 | Returns 1 if `func_02050628(4)` or, when that returns zero, `func_02050628(5)` is nonzero; otherwise returns 0. |
| `func_020dfeec` | 52 | Calls `func_020dfd9c(work, selector, 1, 1, flag)`. Flag is zero only when selector is 20 or 17 and work +0 is 3; otherwise it is one. Original conditional comparisons and the stack argument establish this behavior. |

### M1-T894 hard list

None; all requested functions match.
