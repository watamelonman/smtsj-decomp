# sdk_02008b9c

The TU remains linked from the delinked original until a human marks it complete.
Only the byte-matching card DMA routine is defined in the C replacement.

## func_02008b9c — Huffman decompression (248 bytes; hard)

The header's low nibble selects the symbol width and its upper 24 bits give the
output byte count. The tree follows the header, with six-bit child offsets and
leaf flags in the high two bits. Compressed words are consumed most-significant
bit first; decoded symbols accumulate into 32-bit output words.

A typed C trial reconstructed header parsing, tree traversal, leaf packing and
word output. It compiled to 220 bytes instead of 248, with different register
allocation and loop branches. No matching implementation is included.
The original remains in the delinked object. Candidate signature:
`void func_02008b9c(const u32 *source, u32 *destination)`; source and destination
are caller-owned and word-aligned, with valid compressed input required.

## func_02008c94 — byte run-length decompression (108 bytes; hard)

The header gives the output length. Each control byte specifies either a literal
run of `(control & 127) + 1` bytes or a repeated-byte run of
`(control & 127) + 3` bytes. The original writes every output byte using `swpb`.

A typed C trial implementing both run types compiled to 112 bytes instead of
108 and emitted byte stores rather than the original byte swaps. The public
[pokediamond decompression source](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/MI_uncompress.c)
also uses hand-written assembly and `swpb` for its byte-output LZ routine;
it supplied no matching C substitute for this instruction pattern.
No nonmatching implementation is included. Candidate signature:
`void func_02008c94(const u32 *source, u8 *destination)`; input must be valid
and word-aligned, and output storage is caller-owned.

## func_02008d00 — differential unfilter (96 bytes; hard)

The low header nibble selects byte deltas when equal to one, otherwise halfword
deltas. The upper 24 bits give the byte count. Deltas accumulate modulo the
output element width. The original uses a single-register `ldm` header load,
saves r4, and uses preincrement loads and stores.

A typed C trial with separate byte and halfword loops compiled to 84 bytes.
A second trial explicitly using preincrement pointers reached 96 bytes, but
still used `ldr`, different registers, separate decrement/comparison operations,
and different returns. No nonmatching implementation is included. Candidate
signature: `void func_02008d00(const u32 *source, void *destination)`; source
is word-aligned, destination has the selected element alignment, and valid
input has a positive output count divisible by the selected element size.

## func_02008d60 — card DMA setup (116 bytes; matched 100%)

Typed parameters are the DMA channel, borrowed source and destination pointers,
and transfer size in bytes. Performs DMA conflict/source checks even for zero
size. Otherwise waits for the channel to become idle and programs card-receive
DMA with control word `0xaf000001` through the existing ITCM provider.

Identification and C structure come from
[pret/pokediamond MI_dma_card.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/MI_dma_card.c),
with the channel-control address expression from its MI_dma.h. The original
symbol name is retained for the protected symbol configuration. Objdiff verifies
100%, including the relocation to `func_01ff8480` in ITCM (the standalone hand
comparison helper only loads main ARM9 symbols and cannot resolve that call).

## Hard list

- `func_02008b9c`: Huffman traversal and packing; 220-byte C trial versus 248-byte original.
- `func_02008c94`: byte run-length decoder; original uses `swpb`.
- `func_02008d00`: differential decoder; 96-byte preincrement trial still differs in instructions/registers.

These three need human investigation or decomp.me scratches via
`tools/decompme.py`. No scratch was published and no assembly was added.
