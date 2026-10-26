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

- `SaveLoadTask_SelectEntry`: save/load menu entry dispatch (cases 0-7).

## M1-T895: verified matching helpers

All eight requested functions match at 100% in the generated objdiff report.
Evidence for the contracts below is the original ARM loads, stores, comparisons,
and provider calls, as recorded in the source comments. Existing neutral symbols
are retained because the broader provider semantics are unconfirmed. Work storage
is borrowed and must cover every listed offset. The TU still links from the
delinked original until a human marks it complete.

| Function | Size | Contract and instruction evidence |
| --- | ---: | --- |
| `func_020e0034` | 56 | Writes 1 through 6 to six words starting at work +0x18, then clears +0x34. Requires writable storage through +0x37. |
| `func_020dff20` | 72 | Increments the signed index at +0xdc, scans six byte flags starting at +0xe0, and stores/returns the next flagged index or -1 on exhaustion. The incoming index must be at least -1 and incrementable without signed overflow. |
| `SaveLoadTask_Unk_0df94c` | 80 | Calls `SaveLoadTask_Unk_0df814` unless the kind is 5 through 9 and `Unk124c5c_IsKind0` returns nonzero. No arguments or result. |
| `func_020dfe80` | 84 | Selectors 2/6 first pass work +0x4c/+0x48 and words +0xf0/+0xf4 to `func_02109f94`, then pass its result to `func_020616ec`. All selectors dispatch through `func_020dfd9c` with three zero flags. Requires storage through +0xf7 and the dispatcher's work contract. |
| `SaveLoadTask_Unk_0df814` | 88 | Kinds 5 through 9 call `Unk124c5c_Set_124d8c(0, 31)`; other kinds call `func_020525cc(3)`. No arguments or result. |
| `SaveLoadTask_Unk_0df86c` | 88 | Kinds 5 through 9 call `Unk124c5c_Set_124d8c(1, 0)`; other kinds call `func_0205257c(3)`. No arguments or result. |
| `SaveLoadTask_Unk_0dff68` | 132 | Scans using `func_020dff20`; exhaustion returns 0. Slot 0 selects transition 12, others 13; slots 1/4 and 2/5 call provider group 1 with values 1 and 2 respectively. Dispatches with flags (1, 0, 0) and returns 1. Inherits scan and dispatcher work contracts. |
| `func_020df8c4` | 136 | For kinds 5 through 9 returns the negated kind-0 predicate when its integer flag is nonzero, otherwise the negated kind-31 predicate. Other kinds return whether `func_02052728` is nonzero. Result is always 0 or 1. |

Validation: anticheat passes; all nine unit tests pass; the match gate reports all
20 checked C functions at 100%; checksum reports every artifact byte-identical.
The match gate also runs the full build. This card requires no new test files;
instruction comparison verifies the requested behavior and relocations directly.

### M1-T895 hard list

None; all eight requested functions match. Attempt 2 corrects the stale function
status documentation left by the previous attempt without changing matching C.

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
