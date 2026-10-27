# NitroSDK context helpers and touch callback

Public-source identification used
[pret/pokediamond CP_context.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/CP_context.c),
[CP_context.h](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/include/CP_context.h),
[SPI_tp.s](https://github.com/pret/pokediamond/blob/master/arm9/asm/SPI_tp.s), and
[tp.h](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/include/tp.h).
Original symbol names remain unchanged because symbol configuration is human-owned.

## func_0200d084 — CP_SaveContext (64 bytes; hard)

Saves four division operand words from 0x04000290, two square-root operand
words from 0x040002b8, and the masked division/square-root modes to a
caller-owned 28-byte context. The public implementation is handwritten assembly
with exactly the same instructions. No matching C definition is included.

Tried aggregate copies of four-word/two-word structures, scalar operand loads
followed by stores, and volatile versus ordinary operand reads. Aggregate C
produced 68 bytes versus 64, moved the output pointer to lr, and copied through
r0-r3 instead of r2-r4/ip. Scalar versions produced 80 or 88 bytes. The original
post-incrementing multiple loads/stores and register preservation remain unresolved.

## func_0200d0c4 — CPi_RestoreContext (60 bytes; hard)

Restores the division operands, then both modes, then the square-root operand
from a caller-owned context. The public assembly is instruction-identical.
No matching C definition is included.

Tried aggregate copies, scalar temporaries, register-qualified pointer parameters,
volatile operand pointers, and pointer increments versus indexed stores. Aggregate
C reached 60 bytes but saved r3/lr instead of r4, moved the input to lr, and used
different copy registers and mode-load ordering. Scalar variants produced 72 or
76 bytes. Neither mismatch was retained in production code.

## func_0200d100 — TPi_TpCallback (640 bytes; 100%)

Typed parameters are FIFO tag, reply word, and transport error flag. The callback
records errors, clears completed busy bits, decodes packed 12-bit x/y coordinates,
contact and two validity bits, advances the automatic sample ring, and calls the
registered completion handler. Unexpected reply status calls the existing SDK
termination provider. The tag is unused by the original implementation.

The private borrowed state view at data_02154290 has callback +4, latest sample
+8, ring index +0x10, ring pointer +0x14, count +0x18, and state/error/busy halfwords
+0x36/+0x38/+0x3a. The provider owns all storage and must initialize a valid ring
before automatic sampling. Packed input is read as two volatile halfwords at
0x027fffaa/0x027fffac. The bitfield layout follows the ARM compiler's wire layout;
no simulation or game-layer dependency is introduced.

Objdiff reports 100%; the standalone comparison also verifies all instruction
words and symbol relocations against the ROM. No new tests are required by the
card; the match gate checks the reconstructed function directly.

## Hard list

- func_0200d084: CP_SaveContext; needs C register/copy scheduling matching public assembly.
- func_0200d0c4: CPi_RestoreContext; needs C register/copy scheduling matching public assembly.

Both remain supplied by the original delinked object. A human can use
`tools/decompme.py` for these functions; no scratch was uploaded.
