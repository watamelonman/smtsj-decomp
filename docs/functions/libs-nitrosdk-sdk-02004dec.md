# NitroSDK 02004dec: 2D character and extended palette uploads

All five functions match at **100%** in objdiff using mwccarm 2.0/sp1p5.
The original delink symbols are retained so callers and relocation matching
continue to use the existing symbol configuration. This TU remains linked from
the delink pending the human completion step.

## Public source evidence

The implementations correspond to pret/pokediamond's
[GX_load2d.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load2d.c)
and its inline
[GX_dma.h](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/include/GX_dma.h)
helpers. The four base-pointer callees access BG2/BG3 control registers at
`0x0400000c`, `0x0400100c`, `0x0400000e`, and `0x0400100e` respectively,
supporting the main/sub engine and background assignments below.

## Function entries

| Original symbol | SDK equivalent | Contract and behavior | Match |
| --- | --- | --- | --- |
| `func_02004dec` | `GX_LoadBG2Char` | Copies `size` bytes from `src` to the current main BG2 character base plus byte `offset`. Uses configured DMA when the channel is not `-1` and size exceeds 48 bytes; otherwise uses CPU word copy. | 100% (96 bytes) |
| `func_02004e4c` | `GXS_LoadBG2Char` | Same transfer selection and byte arguments, using the sub BG2 character base. | 100% (96 bytes) |
| `func_02004eac` | `GX_LoadBG3Char` | Same transfer selection and byte arguments, using the main BG3 character base. | 100% (96 bytes) |
| `func_02004f0c` | `GXS_LoadBG3Char` | Same transfer selection and byte arguments, using the sub BG3 character base. | 100% (96 bytes) |
| `func_02004f6c` | `GX_BeginLoadBGExtPltt` | Resets and saves the BG extended palette bank. Bank `0x10` selects LCDC base `0x06880000`, offset 0; `0x40` selects `0x06894000`, offset `0x4000`; `0x20` or `0x60` selects `0x06890000`, offset 0. Other values preserve the old base/offset. | 100% (160 bytes) |

Upload callers must provide valid, word-copy-compatible source/destination ranges
and arrange the appropriate VRAM bank configuration; these SDK routines do not
validate arguments. The shared load state is declared as a partial typed view:
only offsets 12 (palette offset), 16 (LCDC base), and 20 (saved bank) are used here.

## Validation

The original object provides the executable reference in place of new unit tests
(the card sets `tests_required = false`). The match gate verifies each of the five
compiled function bodies, including transfer branches, register allocation,
switch cases, literal pools, and relocations. The checksum gate verifies the
original linked image while this TU awaits human completion.

## Hard list

None.
