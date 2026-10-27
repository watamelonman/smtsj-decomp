# CRI unit 0208d5ac

## Evidence and interpretation

A public-source search for CRI/ADX Nintendo DS middleware found no matching
implementation. The original ARM instructions are the reconstruction evidence.
Existing neutral linker symbols are retained because the instructions do not
support specific CRI API names beyond the helper shapes described below.

The first sixteen reconstructed entries are complete no-op implementations:
each original is a single `bx lr` (four bytes), with no reads, writes, calls or
return-value assignment. The explicit `void` parameter lists express that these
implementations consume no arguments; they do not establish historical callback
signatures. These are not unfinished replacements.

The later entries implement the string and formatted-output helpers used by the
adjacent CRI code. Their shapes are established by the callers and by the MSL
implementations already reconstructed in `libs/MSL/msl_02012aa4.c`:
`func_02015134` is strcpy, `func_020151fc` strncpy, `func_0201524c` strcat,
`func_0201527c` strncat and `func_02013bfc` vsprintf. The wrappers drop the
second argument of their own signature (the original does not forward r1) and
tail-call the corresponding MSL entry point. No module boundary changes.

| Function | Original evidence and behavior |
| --- | --- |
| `func_0208d62c` | `bx lr` at `0x0208d62c`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d630` | `bx lr` at `0x0208d630`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d634` | `bx lr` at `0x0208d634`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d638` | `bx lr` at `0x0208d638`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d63c` | `bx lr` at `0x0208d63c`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d640` | `bx lr` at `0x0208d640`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d644` | `bx lr` at `0x0208d644`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d648` | `mov r0, #0; bx lr` at `0x0208d648`: returns the constant zero and has no side effects. |
| `func_0208d650` | `bx lr` at `0x0208d650`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d654` | `bx lr` at `0x0208d654`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d658` | `bx lr` at `0x0208d658`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d65c` | `bx lr` at `0x0208d65c`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d660` | `bx lr` at `0x0208d660`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d664` | `bx lr` at `0x0208d664`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d668` | `bx lr` at `0x0208d668`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d66c` | `bx lr` at `0x0208d66c`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d670` | `bx lr` at `0x0208d670`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d674` | Loads the constant `0x0212eddc`, stores it in the global at `data_02149544` (`0x02149544`), and returns the stored value. The value is also the natural result because r0 is loaded first and left in place; the neighbouring data at `0x0214953c` begins with "RIFF". |
| `func_0208d68c` | Tail-calls `func_02015134` (strcpy) with `(destination, source)`; the second argument is not forwarded (`mov r1, r2; bx ip`). |
| `func_0208d69c` | Tail-calls `func_020151fc` (strncpy) with `(destination, source, count)`; the second argument is not forwarded (`mov r1, r2; mov r2, r3; bx ip`). |
| `func_0208d6b0` | Tail-calls `func_0201524c` (strcat) with `(destination, source)`; the second argument is not forwarded. |
| `func_0208d6c0` | Tail-calls `func_0201527c` (strncat) with `(destination, source, count)`; the second argument is not forwarded. |
| `func_0208d6d4` | Variadic wrapper: builds the AAPCS argument-list pointer from the rounded address of the third fixed argument (`format`) and calls `func_02013bfc` (vsprintf). The second argument is not forwarded. The prologue matches the MSL `sprintf` at `0x02013c3c`. |
| `func_0208d6fc` | Tail-calls `func_02013bfc` (vsprintf) with `(buffer, format, args)`; the second argument is not forwarded (`mov r1, r2; mov r2, r3; bx ip`). |

## Validation

The build and objdiff match gate passed: all twenty-five reconstructed functions
report 100%. The checksum gate reports all artifacts byte-identical to the
original. Anticheat passed, and all nine existing unit tests passed. No new
behavioral tests are required by this card: exact instruction matching verifies
each implementation.

## Hard list

None for the twenty-five reconstructed functions. Other functions in the TU
remain provided by the delinked original, as required by the card.
