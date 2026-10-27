# sdk_020116a8

Public-source lookup: checked the published NitroSDK/MSL sources and the
pret/pokeplatinum and zeldaret decompositions for these exact helpers. The
function shapes match the standard MSL family of `bsearch`, `memcmp`, `mbtowc`,
`fabs`/absolute-value, and locale-dispatch routines, but no published copy with
this toolchain's exact register allocation was found. The split's NitroSDK
direction alone does not prove SDK provenance. Existing `func_` symbols are
retained because symbol configuration is human-owned. All contracts below are
from the original ARM instructions and the surrounding data tables.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_020116a8` | Waits on the borrowed work pointer at +0xc0, copies the 36-byte message into a stack buffer, restores interrupts, runs the +0 handler with the buffer and stores its result at +8, reloads the interrupt state, clears `data_02155908` byte +0x26, runs the +4 handler, then clears the work pointer and repeats while `data_02155908` word +0 remains nonzero. Falls through to `func_02006318` when the word is zero. | 100% |
| `func_02011798` | Compares `n` bytes, returning the unsigned byte difference at the first mismatch; equal ranges return zero. The loop guard is entered through a shared zero result, and `n` is signed in the original. Callers in `unit_02111400` use it as a byte-range comparison. | 100% |
| `func_020117d8` | Loads the word at `data_0213cf94` (stored as the float NaN pattern `0x7fffffff`) and tail-calls the MSL float-to-double entry point `_f2d` at `0x0201e9e8`. | 100% |
| `func_020117f0` | Discards null input; otherwise tail-forwards the block to `func_0201cfd8`, documented as the MSL arena free path in `libs/MSL/msl_02017850.c`, and ignores its result. | 100% |
| `func_02011804` | Returns the magnitude of a signed word: only negative values are negated. Used by lookup and index helpers as a signed-magnitude conversion. | 100% |
| `func_02011810` | Sorted-array search over `count` records of `size` bytes. It rejects any null argument, compares the key with the first record, then narrows the inclusive `[1, count - 1]` range by unsigned halves. The comparator at the fifth argument returns the ordering sign. Returns the matching record or null. | 100% |
| `func_020118a4` | Loads the active locale at `data_0213cff4`, follows its +8 codeset pointer, and tail-calls the first codeset entry with the caller's three arguments unchanged. This is the locale-dispatched `mbtowc` wrapper. | 100% |
| `func_020118c0` | Single-byte-locale `mbtowc` implementation: null source returns the stateless result zero, zero length returns -1, an optional output receives the zero-extended byte as a halfword, and the return is one for any nonzero byte. The paired entry at `data_0213cfb0` +4 is the inverse single-byte `wctomb` in the next split unit. | 100% |

## Hard list

None. All eight functions match byte-for-byte in objdiff.

The work object and the global flag/byte at `data_02155908` are borrowed views:
the work pointer is declared `volatile` because the interrupt-disabled loop
re-reads it after each wait call, and the global view spans the following BSS
symbol only to describe the byte at +0x26 that the original clears.
