# libs/unknown/lib_02090068

This card recreates six of the seven functions in the delinked
`libs/unknown/lib_02090068.c` range (`0x02090068..0x020907a0`). The unit is
still linked from its delinked original until a human marks it `complete` in
`config/arm9/delinks.txt`.

## Identification and public source

The surrounding `sdk_0208e1f0` unit parses `MODS`/`N3` video headers and
contains the decoder's frame buffers and blit tables; `data_02132c90`,
`data_0213b9f8`, `data_0213b878` and `data_02134d90` (used by
`lib_020907a0.c`) are its shared assets. The `[SDK+Actimagine:Mobiclip SDK
V1.1.0]` string in `sdk_02000b9c.c` identifies the codec. A public
NitroSDK/MSL source was not available. The C# Mobiclip decoder by Gericom
(`LibMobiclip/Codec/Mobiclip/MobiclipDecoder.cs`) documents the DS file format
and the YUV-to-RGB blit contract, but it is a reconstruction, not the original
SDK source. The six entry points below are written from the delinked ARM
instructions and the relocations; existing `func_` linker names are retained
because the symbol configuration is human-owned.

## Shared layout

The six routines operate on one borrowed stream wrapper. `func_02090030`
(not in this card) initialises it from a file object:

| Offset | Meaning |
| ---: | --- |
| 0x00 | method-table pointer; slot 5 (+0x14) is the dispatch target of `func_020901c8` |
| 0x04 | file-object base word copied from the file |
| 0x08 | current byte position |
| 0x0c | file-object pointer used by the FS primitives |
| 0x10 | one-byte "read window open" flag |

`func_0200bdec`, `func_0200bf14`, `func_0200bf04` and `func_0200bef4` are the
close, seek, buffered-read and direct-read primitives documented in
`docs/functions/libs-nitrosdk-sdk-02051378.md`. The method table at
`0x0214c684` (load relocations at `0x0214c684..0x0214c69c`) lists the sibling
methods, which fixes the vtable interpretation. The wrapper and the file stay
provider owned; these helpers only borrow them.

## func_02090068 — 76 bytes

Seeks the wrapped file to `size` from the start and records `size` as the new
position. It first closes the file and clears the open flag when the flag is
one, so a pending read window is discarded. A failed seek (result 0) returns 0;
success stores `size` at +8 and returns 1. Evidence: the conditional close at
02090084, the seek with origin 0 at 0209009c, and the conditional `str`/`mov`
pair at 020900a8. Matches 100%.

## func_020900b4 — 112 bytes

Reads `size` bytes into the caller's buffer and advances the recorded position.
When the open flag is set it closes, re-seeks to the stored position and clears
the flag; then the buffered read runs. A read result of -1 returns 0; otherwise
the position grows by `size` and the function returns 1. Evidence: the seek of
the +8 word at 020900e4, the -1 comparison at 02090100..02090108, and the +8
store at 0209011c. Matches 100%.

## func_02090124 — 124 bytes

Reads the 0x200-byte aligned block containing the recorded position and returns
the byte offset of that position inside the block. The mask is `~0x1ff`; when
`size + offset` is not block aligned it is rounded up to the next 0x200 block.
The seek uses the aligned base and the direct read fills the caller's buffer
with the rounded length. On success the position advances by the unrounded
`size`, the open flag is set and `offset` is returned; a -1 read returns 0.
Evidence: the `0xfffffe00` mask and rounding at 0209012c..02090154, the seek at
02090160, the direct read at 02090170, and the flag/return stores at
02090184..02090198. Matches 100%.

## func_020901a0 — 40 bytes

Closes the wrapped file when the open flag is one, then clears the flag
unconditionally. Evidence: the conditional close at 020901b8 and the
unconditional byte store at 020901c0. Matches 100%.

## func_020901c8 — 20 bytes

Virtual dispatch helper: loads the object's method-table pointer from +0x00,
loads slot 5 (+0x14) and tail-calls it with the object unchanged. The
`blx r1` at 020901d4 and the sibling table at 0x0214c684 establish the vtable
shape. Matches 100%.

## func_020901dc — 4 bytes

Empty function; the delinked body is exactly `bx lr`. Matches 100%.

## func_020901e0 — 1472 bytes (hard list)

The function is the Mobiclip 2x2-pixel YUV-to-BGR555 blit. It walks the luma
plane (stride 0x100), the U/V planes (V at +0x80) and two output rows whose
stride comes from the wrapper (+0x0c), using a 0x300-byte table at +0x18 as
three 256-byte component tables centred on +0x100:

- `G = table[0x100 + V + Y]`
- `B = table[0x100 + U - V + Y]`
- `R = table[0x100 - U - V + Y]`

Each 2x2 block writes two 16-bit BGR555 pixels with the alpha bit set
(`0x8000`). Two of the four block pixels use `Y - 4`; the bias alternates with
the pixel parity. The loop bounds are `width` (+0x10) and `height` (+0x14);
the inner loop advances 16 pixels per iteration, the outer loop advances two
rows per iteration. The counters and the observed pointer deltas
(`luma += 512 - width`, `chroma += 256 - width/2`,
`dst += (stride - width) * 2`) all fit this contract.

A behavioural C reconstruction was written and its generated instructions were
compared against the original: the per-block sequence, the table pointer
arithmetic and the output words agree, but the register allocation and
addressing differ. The original object contains eight identical inlined 2x2
blocks per inner iteration with post-increment addressing
(`ldrb r5,[r1],#128`, `ldrb r4,[r0],#255`, `str r8,[r2],#4`). The pinned
mwccarm 2.0/sp1p5 never unrolls a loop, and for an explicitly written
eight-block body it strength-reduces every pointer update into base+immediate
offsets; the resulting function is 1580 bytes against the original 1472.
Every mwccarm release in `tools/mwccarm` (1.2 and 2.0) produced the same
base+offset form, so no source spelling reproduces the original addressing
with the configured compiler. This unit is SDK code and was probably built
with a different CodeWarrior release. The non-matching definition was therefore
left out; the delinked original still supplies `func_020901e0`. A human can
upload it to a decomp.me scratch with `tools/decompme.py` (platform `nds_arm9`).

## Validation

The six retained functions report 100% in objdiff against
`build/delinks/libs/unknown/lib_02090068.o`. The full build and checksum gate
still use the delink object, so the image is unchanged. No assembly, byte
blobs or instruction-selection pragmas were used.

## Hard list

- `func_020901e0` (1472 bytes): see above. Tried explicit eight-block expansion,
  `static inline` block helper, post-increment source forms, `u32*` versus
  `u8*` destinations, array-index and pointer-walk iterators, and every
  mwccarm version in `tools/mwccarm`. None reproduce the original unrolled
  post-increment form with the configured flags.
