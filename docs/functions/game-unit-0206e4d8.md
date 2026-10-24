# game/unit_0206e4d8 — M1-T386

All eight requested functions match at 100% in objdiff. The C bodies already
matched in the starting worktree; this card verifies them and records their
contracts. Evidence below comes from the delinked ARM `.text` and relocations.
Integer address returns preserve the existing TU interface on the 32-bit target.
Table indices must identify valid slots; these helpers do not check bounds.
No domain meaning beyond these accesses is established, so neutral names remain.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `Unk06e4d8_Get_data_02170cc8` | 16 | Returns the nullable borrowed work address: literal load of `data_02170cc8`, then word load. |
| `Unk06e4d8_Unk_06e4d8` | 24 | Returns slot address +0xbc; MLA uses index, stride 0x148 and `data_0216bac8`, then ADD 0xbc. |
| `Unk06e4d8_Unk_06e4f0` | 24 | Same table contract, ADD 0xdc. |
| `Unk06e4d8_Unk_06e508` | 24 | Same table contract, ADD 0xfc. |
| `Unk06e4d8_Unk_06e520` | 24 | Same table contract, ADD 0x11c. |
| `Unk06e4d8_Reset` | 28 | Requires non-null writable work. Clears word +0x08, byte +0x6c, word +0x68, then tail-calls `Unk06e4d8_Unk_06e814`. |
| `Unk06e4d8_Unk_06e680` | 36 | Passes the global word to `func_02061424`, then stores zero in the global. The original has no null check. Callee semantics remain unnamed. |
| `Unk06e4d8_GetFlag6c` | 44 | Returns 0 for absent work; otherwise calls the accessor again, reads byte +0x6c and returns normalized 0/1. Both calls are retained to match the original. |

## Hard list for M1-T386

None. All requested functions are identical; no scratch is needed.

## Other cards (pre-existing status)
Notes left by other cards that touch this TU; kept for reference.

## Not done in M1-T388
- `func_0206e8b0`
- `Unk06e4d8_Unk_06e6a4`: decompiler-derived
- `Unk06e4d8_Unk_06e814`: decompiler-derived

## Not done in M1-T387
- `Unk06e4d8_Unk_06ea0c`
- `Unk06e4d8_Unk_06e854`
- `Unk06e4d8_Unk_06e538`
- `func_0206e790`
- `func_0206e6e4`
- `func_0206e5bc`
- `Unk06e4d8_Unk_06ea0c`: hand-matched
- `Unk06e4d8_Unk_06e538`: hand-matched
- `Unk06e4d8_Unk_06e854`: hand-matched
