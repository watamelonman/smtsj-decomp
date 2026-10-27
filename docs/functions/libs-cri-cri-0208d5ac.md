# CRI unit 0208d5ac

## Evidence and interpretation

A public-source search for CRI/ADX Nintendo DS middleware found no matching
implementation. The original ARM instructions are the reconstruction evidence.
Each requested entry consists solely of `bx lr` (four bytes), with no reads,
writes, calls, or return-value assignment. The explicit `void` parameter lists
express that these implementations consume no arguments; they do not establish
historical callback signatures. No return-value contract is inferred from the
unchanged r0. Existing neutral linker symbols are retained because the
instructions do not support specific CRI API names.

These are complete no-op implementations, not unfinished replacements. The
adjacent `func_0208d648` explicitly sets r0 to zero before returning; that
behavior must not be added to these functions. No module boundary changes.

| Function | Original evidence and behavior |
| --- | --- |
| `func_0208d62c` | `bx lr` at `0x0208d62c`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d630` | `bx lr` at `0x0208d630`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d634` | `bx lr` at `0x0208d634`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d638` | `bx lr` at `0x0208d638`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d63c` | `bx lr` at `0x0208d63c`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d640` | `bx lr` at `0x0208d640`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d644` | `bx lr` at `0x0208d644`: returns immediately, consumes no arguments, changes no memory, and defines no result. |
| `func_0208d650` | `bx lr` at `0x0208d650`: returns immediately, consumes no arguments, changes no memory, and defines no result. |

## Validation

The build and objdiff match gate passed: all eight requested functions report
100%. The checksum gate reports all artifacts byte-identical to the original.
Anticheat passed, and all nine existing unit tests passed. No new behavioral
tests are required by this card: exact instruction matching verifies the
specified no-op behavior.

## Hard list

None for the eight requested functions. Other functions in the TU remain
provided by the delinked original, as required by the card.
