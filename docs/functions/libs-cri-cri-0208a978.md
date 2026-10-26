# CRI unit 0208a978

The eight card targets retain their existing neutral `func_` symbols: no
verified public-source counterpart or semantic naming evidence was found.
Public-source searches included CRI ADX/Nintendo DS and the related
[crowded-street CRI reconstruction inventory](https://github.com/crowded-street/3s-decomp/blob/main/cri-progress.md).
Implementation follows the delinked ARM instructions, with borrowed opaque
state and argument types. No provider layout or ownership is inferred.

| Function | Bytes | Instruction evidence and contract |
| --- | ---: | --- |
| `func_0208a978` | 16 | Store the supplied signed mode word at `data_02148da4`; no validation. |
| `func_0208aa68` | 36 | Return every mode other than -1 unchanged; for -1, probe `func_02083708`, returning 2 only for result 1, otherwise 1. |
| `func_0208aa8c` | 36 | Tail-call `func_0208ae80` with global borrowed state and the signed word read at absolute address 0212ed94; return its word. See DEC-028. |
| `func_0208aab0` | 24 | Tail-call `func_0208af40` with the global borrowed state; no result is consumed. |
| `func_0208ab28` | 28 | Call 0208ae78, forward the borrowed argument through 0208ab44, then call 0208ae7c. Both bracketing helpers currently contain only a return. |
| `func_0208ab44` | 28 | Tail-call 0208b0c4 with global state followed by the borrowed argument; no result is consumed. |
| `func_0208ab60` | 36 | Call 0208ae78, forward through 0208ab84, call 0208ae7c, and preserve the signed result across the trailing call. |
| `func_0208ab84` | 28 | Tail-call 0208b10c with global state followed by the borrowed argument; return its signed word. |

All eight targets match at 100% objdiff. The unit remains linked from its
original delink pending human completion marking. Tests are not required by
the card; instruction matching and full-image checksum verify this change.

## Hard list

None of the eight requested functions remain unmatched. Other functions in
the unit were outside this card.
