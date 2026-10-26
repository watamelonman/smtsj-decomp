# CRI unit 0208256c — M2-T071

The public-source search for Nintendo DS CRI/ADX middleware did not identify
matching source. These functions are reconstructed from the original ARM code.
The configured `func_` symbols are retained because the middleware API names and
the meaning of the two stored pairs are not established. All parameters and
results are 32-bit words; no pointer or callback signature is assumed for the
opaque pair values.

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

The worker's original instructions select a 72-byte row, iterate over six
12-byte entries, call each non-null entry callback with the adjacent word, and
OR the results. This supports the unsigned word return declaration and the row
terminology, without assigning a middleware-level meaning to these wrappers.

## Validation

The card does not require new tests. `python3 tools/match_gate.py` built the
project and reported all eight functions at 100%. `python3 tools/anticheat.py`
passed; `python3 -m unittest discover -s tests -t . -q` passed all nine tests.
`python3 tools/checksum.py` reported all artifacts byte-identical to the
original. The unit remains linked from the delink pending human completion.

## Hard functions

None of the eight functions assigned by M2-T071 are left out. Other functions
in this translation unit belong to a separate task card.
