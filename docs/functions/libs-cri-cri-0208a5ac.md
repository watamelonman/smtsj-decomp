# libs/CRI/cri_0208a5ac — MSB-first bit reader (M2-T305)

The delinked range 0208a5ac..0208a978 is one self-contained CRI bit reader: a
byte source is consumed through a small dispatch table, whole bytes are appended
big-endian to a 32-bit shift register, and callers take fields of up to 32 bits
from the front of that register. No string or caller names the subsystem, so
every symbol keeps its `func_<addr>` name; only the private struct fields and
helpers below are named from the instruction evidence.

## Layout

`CriBitStream` is 0x2c bytes. Offsets come from the loads/stores in this unit:
+0x04 source object, +0x08 shift register, +0x0c valid bits in it, +0x10 bits
returned so far, +0x18 byte count requested from the source, +0x1c/+0x20 the
buffer the source granted (a `CriBitStreamChunk`), +0x24 unread bytes in it and
+0x28 the read cursor. The source's table entries at +0x18..+0x24 are the four
`blx` call sites in 0208a5ac/0208a898 (see `include/libs/CRI/cri_0208a5ac.h`).

The mask table at 0x0212ed10 holds `(1 << n) - 1` for n = 0..31; entry 12 is
0xfff. The literal that points at it carries no relocation and has no configured
symbol (same case as DEC-028), so the two deferred readers read it through its
observed address with `opt_propagation off` (DEC-036); the five matched
functions do not touch it.

## Matched

| Function | Contract and evidence from the original ARM instructions |
| --- | --- |
| `func_0208a7b0` | Carves `bytes` off the front of one 2-word buffer record into `part` and leaves the tail in `rest`. The original copies both words with one `stm`, which is the aliasing struct copy `*part = *source` (0208a5ac passes the same record as source and part), then clamps `part->size`, subtracts it from `rest->size`, and stores `part->data + part->size`, or null when nothing is left. |
| `func_0208a890` | Returns the count of bits returned so far (word +0x10). The single `ldr`/`bx lr` pair is the whole function. |
| `func_0208a7f4` | Refills once when +0x0c holds fewer than `bits` valid bits, then reports whether `bits` are now available. The two original conditional moves are `bits > count ? 0 : 1`, written as an early `return 0` so mwccarm predicates them in that order. |
| `func_0208a5ac` | Refills the shift register. `(32 - count) / 8` is the number of whole bytes still needed; the fill only runs when fewer than four bytes remain, first returning the already-consumed prefix and the unread tail of the current buffer through table entries +0x20/+0x1c, then requesting a new buffer through +0x18 and latching +0x1c/+0x20 into the cursor/remaining pair. The byte count is clamped with a signed `>=` (the original is `movge`), and each of the four arms appends through one cached cursor/register pair, so a whole arm costs one load and one store. |
| `func_0208a898` | End-of-stream test: the source's table entry +0x24 reports its end, the register is empty and no unread bytes remain. The three `ldreq`/`cmpeq` pairs are the `&&` chain of the returned boolean. |

## Hard list

| Function | What is still different |
| --- | --- |
| `func_0208a824` | Reads `bits` bits and retires the leftover into +0x10 when the source cannot supply them. A readable reconstruction reproduces the size (108 bytes) and the whole prologue/error path, and the tail differs only in how mwccarm schedules and colours it: the original loads +0x08 first and keeps the mask in `r0`, while every source form tried emits the pooled mask address first and colours the result in `r3`. Tried: the mask as a local pointer, an inline address, file-scope constant, and 11 statement permutations of "load mask / shift / subtract count" with `opt_propagation off`; 23 of 27 instructions match at best. All ten mwccarm 2.0 service packs emit identical code. |
| `func_0208a8d4` | Byte-aligns, scans for the stream sync and returns 1 (low 12 bits all ones), 2 (the exact pattern 0x8001000c) or -1 at end of stream. The reconstruction matches the size (164 bytes) and every instruction's form and order; the only difference is the callee-saved colouring: the original keeps `masks[12]` in `r4` and the stream in `r5`, mwccarm keeps the stream in `r4` and the mask in `r8` (26 of 41 words match). Tried: mask as local/inline/const/`u32`, declaration and initialisation order, `do`/`while` and `for` loop shapes, and the `opt_propagation`/`opt_lifetimes` pragmas. |

Both functions stay in the delinked object; the header only declares them. A
human can use `tools/decompme.py` (platform `nds_arm9`) to try the register
allocation interactively.

No tests are required by this card: validation is objdiff at 100% for the five
C functions plus the full-image checksum.
