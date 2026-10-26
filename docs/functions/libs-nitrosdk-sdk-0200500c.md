# NitroSDK extended palette uploads (0x0200500c)

All seven functions match the original ARM instructions, literal pools and call
relocations at **100%** in objdiff using mwccarm 2.0/sp1p5. The original
`func_` symbols are retained for objdiff and linking. This TU remains linked
from the delink until a human marks it `complete`.

## Public source evidence

The implementations correspond to
[pret/pokediamond's GX_load2d.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load2d.c)
and the inline DMA helpers in
[GX_dma.h](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/include/GX_dma.h).
The extended palette functions there use the same shared load-state fields and
the same 0x06880000/0x06890000/0x06894000/0x06898000 LCDC blocks observed in
this ROM. No assembly from the reference is used.

The preceding TU (`sdk_02004dec.c`, `GX_BeginLoadBGExtPltt`) establishes the
main-engine BG extended palette fields at offsets 12 (LCDC offset), 16 (LCDC
block) and 20 (saved bank). The observed stores in this TU place the sub-engine
BG bank at 0, the object extended palette LCDC block at 4, and the saved object
bank at 8. `data_021521c0` is therefore declared as a partial typed view; the
first three words are shared with other upload paths.

## Function entries

| Original symbol | SDK equivalent | Contract and behavior | Match |
| --- | --- | --- | --- |
| `func_0200500c` | `GX_LoadBGExtPltt` | Uploads `size` bytes from `src` to `bg_ext_pltt_lcdc + offset - bg_ext_pltt_offset` using the configured DMA channel, or the CPU word copy when the channel is `-1`. | 100% (112 bytes) |
| `func_0200507c` | `GX_EndLoadBGExtPltt` | Waits for the upload channel when configured, restores the saved BG extended palette bank, then clears the saved bank, LCDC block and offset. | 100% (72 bytes) |
| `func_020050c4` | `GX_BeginLoadOBJExtPltt` | Saves the object extended palette bank and selects LCDC block `0x06894000` for bank `0x40` or `0x06890000` for bank `0x20`; bank 0 leaves the block unchanged. | 100% (72 bytes) |
| `func_0200510c` | `GX_LoadOBJExtPltt` | Uploads `size` bytes from `src` to `obj_ext_pltt_lcdc + offset`, using DMA or the CPU word copy under the same channel rule. | 100% (108 bytes) |
| `func_02005178` | `GX_EndLoadOBJExtPltt` | Waits for the upload channel when configured, restores the saved object extended palette bank, then clears the saved bank and LCDC block. | 100% (68 bytes) |
| `func_020051bc` | `GXS_BeginLoadBGExtPltt` | Saves the sub-engine BG extended palette bank for the matching end call. | 100% (24 bytes) |
| `func_020051d4` | `GXS_LoadBGExtPltt` | Uploads `size` bytes from `src` to the fixed sub-engine BG extended palette block `0x06898000 + offset`, using DMA or the CPU word copy. | 100% (100 bytes) |

Upload callers must provide valid source/destination ranges and arrange the
appropriate VRAM bank configuration; these SDK routines perform no bounds
checks, matching the originals. Sizes passed to the DMA helper must be word
multiples, as for the called transfer routine.

## Validation

The original object provides the executable reference in place of new unit
tests (the card sets `tests_required = false`). The match gate verifies every
compiled function body, including DMA/CPU branches, switch cases, literal pools
and relocations. The checksum gate verifies the original linked image, and the
anticheat and unit-test gates also pass.

## Hard list

None.
