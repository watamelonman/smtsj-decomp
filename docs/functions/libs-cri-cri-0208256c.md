# CRI unit 0208256c — M2-T071 / M2-T072

The public-source search for Nintendo DS CRI/ADX middleware did not identify
matching source. These functions are reconstructed from the original ARM code.
The configured `func_` symbols are retained because the middleware API names and
the meaning of the two stored pairs are not established. The stored pairs remain opaque words. The dispatcher establishes a callback
contract taking and returning one 32-bit word; callback storage is borrowed.
A renewed public-source search for CRI/ADX Nintendo DS source found no match.

| Function | Instruction evidence and contract |
| --- | --- |
| `func_0208256c` | Stores the two argument words at `data_021742c4` and `+4`, respectively (`ldr r2; stm r2, {r0, r1}; bx lr`). |
| `func_0208257c` | Stores the two argument words at `data_021742bc` and `+4`, respectively (same store sequence). |
| `func_02082608` | Tail-calls `func_0208258c(0)` and returns its word result (`ldr ip; mov r0, #0; bx ip`). |
| `func_02082618` | Tail-calls `func_0208258c(1)` and returns its word result (same sequence, immediate 1). |
| `func_02082628` | Tail-calls `func_0208258c(2)` and returns its word result (immediate 2). |
| `func_02082638` | Tail-calls `func_0208258c(3)` and returns its word result (immediate 3). |
| `func_02082648` | Tail-calls `func_0208258c(4)` and returns its word result (immediate 4). |
| `func_02082658` | Tail-calls `func_0208258c(5)` and returns its word result (immediate 5). |

| `func_02082668` | Tail-calls worker row 6, returning its combined result (immediate 6 at 02082670). |
| `func_02082678` | Tail-calls worker row 7, returning its combined result (immediate 7 at 02082680). |
| `func_0208258c` | Uses a 72-byte row and six 12-byte entries; calls non-null callbacks with the adjacent argument word, brackets each call with active flag 1/0, ORs results, and increments the row counter. Index must be 0..7. |
| `func_02082688` | Clears eight active words, four opaque word pairs, the first six row counters, and `data_02173ff0`; does not clear the callback table. Evidence: stores and six-iteration loop at 02082690..020826f8. |
| `func_02082718` | Resets state when the count at `data_02173fd4+4` is zero, then increments it (0208271c..0208273c). |
| `func_02082748` | Decrements that count, reloads it, and on zero resets state and clears `data_02173ff4` (02082750..02082778). Caller must balance acquisitions. |

The worker's original instructions select a 72-byte row, iterate over six
12-byte entries, call each non-null entry callback with the adjacent word, and
OR the results. This supports the unsigned word return declaration and the row
terminology, without assigning a middleware-level meaning to these wrappers.

The counter array has eight addressable words, although the original reset loop
clears only six. This asymmetry is preserved. The reference count is volatile to
retain the original reload after decrement. Builtin clears express the fixed-size
zeroing without adding code blobs or assembly.

## Validation

No new tests are required by the card. All fourteen C functions, including the
six M2-T072 functions, match at 100% in objdiff. The anticheat, unittest and
checksum gates pass. The unit remains linked from the delink pending human
completion.

## Hard functions

None; all functions assigned by M2-T071 and M2-T072 are implemented.
