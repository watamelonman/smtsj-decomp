# CRI unit 0208cf94

This unit reconstructs the CRI record glue and its handle-forwarding wrappers
from the delinked ARM code (M2-T174 and M2-T175). A search of the repository and
of the known Nintendo DS CRI/ADX public reconstructions did not locate matching
source, so the functions are written from their instruction and relocation
evidence. The unit stays linked from the delink until a human marks it
`complete` in `config/arm9/delinks.txt`.

The shared view is a borrowed record whose second word is the handle passed to
the underlying CRI worker. Every wrapper loads that word with `LDR r0, [r0, #4]`
and then branches through the literal pool, which is the compiler's tail-call
shape for the external worker. The incoming argument registers are forwarded
unchanged; the worker's word result is returned unchanged. The address table at
`0212ed98` stores these wrappers, so the caller owns the record.

| Function | Instruction evidence and contract | Match |
| --- | --- | --- |
| `func_0208cfdc` | Resets the record with `func_0208d1e0` when the pointer is non-null; a null pointer skips the call (`popeq`). | 100% |
| `func_0208d07c` | Loads the offset-4 handle and tail-forwards it plus one word to `func_0207f7e8`; literal at `0208d088` (`LDR ip; LDR r0,[r0,#4]; BX ip`). | 100% |
| `func_0208d08c` | Same tail call with three forwarded words to `func_0207f740`; literal at `0208d098`. | 100% |
| `func_0208d09c` | Same tail call with two forwarded words to `func_0207f628`; literal at `0208d0a8`. | 100% |
| `func_0208d0ac` | Same tail call with two forwarded words to `func_0207f824`; literal at `0208d0b8`. | 100% |
| `func_0208d0bc` | Same tail call with two forwarded words to `func_0207f8d4`; literal at `0208d0c8`. | 100% |
| `func_0208d0cc` | Same tail call with no additional arguments to `func_0207efa0`; literal at `0208d0d8`. | 100% |
| `func_0208d0dc` | Same tail call with one forwarded word to `func_0207f504`; literal at `0208d0e8`. | 100% |
| `func_0208d0ec` | Same tail call with no additional arguments to `func_0207f538`; literal at `0208d0f8`. | 100% |
| `func_0208d160` | Clamps the caller's `r1` up to `-960` (`mov #0x3c0; rsb`, signed `cmp`/`movlt`) and tail-forwards it with the handle to `func_0207f214`; literal at `0208d17c`. | 100% |
| `func_0208d180` | Same tail call with no additional arguments to `func_0207f288`; literal at `0208d18c`. | 100% |
| `func_0208d190` | Calls `func_0207f214(handle, r2)` only when `r1 == 0` (`cmp`/`popne`, `mov r1, r2`); returns nothing. | 100% |
| `func_0208d1ac` | Returns 0 when `r1 != 0` (`movne r0, #0`); otherwise calls `func_0207f288(handle)` and returns its word result. | 100% |
| `func_0208d1c8` | Same tail call with one forwarded word to `func_0207f404`; literal at `0208d1d4`. | 100% |
| `func_0208d1d8` | Returns the borrowed offset-4 handle without calling anything (`LDR r0,[r0,#4]; BX lr` at `0208d1d8..0208d1dc`). | 100% |
| `func_0208d1e0` | Writes the `0212ed98` wrapper-table address to offset 0 and zeroes the words at offsets 4 and 8 (three stores plus `bx lr`, literal at `0208d1f8`). | 100% |

No module boundary changed. The record's offset-0 word is the dispatch table
because `func_0208d1e0` stores the literal `0212ed98`, the table named in the
unit evidence; offsets 4 and 8 hold the worker handle and a glue word.

## Validation

The card does not require new tests. All sixteen implemented functions are
instruction- and relocation-identical to the delinked originals, and the build,
objdiff, anticheat, unittest and checksum gates are run before finishing.

## Hard functions

None; all eight functions assigned to this card (and the eight from M2-T174)
are implemented.
