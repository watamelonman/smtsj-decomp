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

## M2-T102: remaining five functions

The public CRI reconstruction search above was repeated for CRI ADX Nintendo DS
wrappers; no matching public implementation was established. Existing neutral
symbols are retained. The mode tables and call order come directly from ARM
instructions; worker-row meanings remain unknown.

| Function | Bytes | Instruction evidence and contract |
| --- | ---: | --- |
| `func_0208a988` | 88 | Resolve the global mode through 0208aa68; mode 1 calls all eight rows through 0208aa3c, mode 2 calls row 5, mode 3 calls rows 6 and 7. Other modes do nothing. Always return zero. |
| `func_0208a9e0` | 92 | Resolve the global mode; mode 2 calls row 0, mode 3 calls rows 0, 1, 2, 3 and 5 in that order. Other modes do nothing. Always return zero. |
| `func_0208aa3c` | 44 | Calls 02082608 through 02082678 in address order, discards worker results, and returns zero. Those wrappers select rows 0 through 7. |
| `func_0208aac8` | 52 | Preserve three arguments across 0208ae78, forward through 0208aafc, call 0208ae7c, and preserve the returned opaque pointer. |
| `func_0208aafc` | 44 | Prepend the borrowed global state to an opaque signed argument, storage pointer and signed byte capacity for 0208afe8. Return its opaque result without inspection. |

The storage/capacity interpretation follows 0208afe8: it advances the third
argument by 224 bytes and reduces the fourth by 224 before forwarding both to
0208b4fc. Its result is a provider entry pointer also passed to 0208b0c4.
The provider retains its existing ownership contract; these wrappers do not
inspect storage or validate its capacity. No module boundary changes are needed.

All thirteen functions in the unit now report 100% objdiff, including all five
M2-T102 targets. Anticheat, all nine repository tests, and the full build checksum
gate pass. The unit remains linked from the delink pending human completion.

## Hard list

None of the requested functions remain unmatched.
