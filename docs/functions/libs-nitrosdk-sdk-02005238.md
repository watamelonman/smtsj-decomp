# NitroSDK extended palette and texture loaders (0x02005238)

All six functions match the original ARM instructions, literal pools and call
relocations at **100%** in objdiff. The original `func_` symbols are retained for
objdiff and linking. This TU remains linked from the delink until a human marks
it `complete` in `config/arm9/delinks.txt`.

## Public source evidence

The implementations were checked against two known reconstructions before writing
new C:

- [nitro-decomp/nitro `src/gx/gx_load.c`](https://github.com/nitro-decomp/nitro/blob/main/src/gx/gx_load.c)
  (`GXS_EndLoadBGExtPltt`, `GXS_BeginLoadOBJExtPltt`, `GXS_LoadOBJExtPltt`,
  `GXS_EndLoadOBJExtPltt`) for the extended palette tail.
- [pret/pokediamond `GX_load3d.c`](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load3d.c)
  (`GX_BeginLoadTex`, `GX_LoadTex`) for the texture loaders. Its
  `sTexStartAddrTable` values match the ROM table at `0x0212a3b0` entry by entry.

No assembly from either reference is used. The ROM is the final authority: the
code below follows the observed instruction order, including the independent
`mul`/`ldrh` addressing of the three table columns.

## State and table evidence

`data_021521c0` is the GX palette load state already used by `sdk_0200500c.c`.
This unit reads offset 0 (`sSubBGExtPltt`) and writes offset 24
(`sSubOBJExtPltt`); both offsets are established by the original `ldr`/`str`
instructions.

`data_021521dc` is a separate 32-byte texture state. The original stores set
`+0x14` to the saved bank mask, `+0x04`/`+0x18` to the two LCDC block bases and
`+0x1c` to the first-block size. `GX_LoadTex` reads those same fields and uses
`+0x18` as the non-zero "two-block window" flag.

The texture start table at `0x0212a3b0` is 16 records of three 16-bit values
(block 1, block 2, block 1 size) in 4 KiB units. The delinked original references
its three columns with absolute literals and no relocation, so the C table is
kept private and its address arithmetic follows the original loads.

## Function entries

| Original symbol | SDK equivalent | Contract and behavior | Match |
| --- | --- | --- | --- |
| `func_02005238` | `GXS_EndLoadBGExtPltt` | Waits for the configured upload DMA channel (`func_02008178`) when it is not `-1`, restores the saved sub-engine BG extended palette bank with `func_02003434`, then clears the saved slot. | 100% (64 bytes) |
| `func_02005278` | `GXS_BeginLoadOBJExtPltt` | Saves the current sub-engine object extended palette bank returned by `func_02003628` for the matching end call. | 100% (24 bytes) |
| `func_02005290` | `GXS_LoadOBJExtPltt` | Uploads `size` bytes from `src` to `0x068a0000 + offset`, using the asynchronous DMA path (`func_020080e0`) when the channel is not `-1`, otherwise the CPU word copy (`func_020086bc`). | 100% (100 bytes) |
| `func_020052f4` | `GXS_EndLoadOBJExtPltt` | Waits for the configured DMA channel when set, restores the saved sub-engine object extended palette bank with `func_020034b4`, then clears the saved slot. | 100% (64 bytes) |
| `func_02005334` | `GX_BeginLoadTex` | Resets the texture VRAM banks (`func_020035b0`), saves the returned mask, and programs both LCDC block bases and the first-block size from that mask's start-address table entry. | 100% (92 bytes) |
| `func_02005390` | `GX_LoadTex` | Uploads `size` bytes of texture data at `offset`. With a single block it copies straight to `lcdc_blk1 + offset`. With two blocks it copies a range wholly inside either block directly, and splits a straddling range into a synchronous first part (`func_02007f40` above 48 bytes, else the CPU copy) and a DMA or CPU remainder to `lcdc_blk2`. | 100% (320 bytes) |

Callers must supply valid source ranges, word-multiple sizes for the word-copy
helpers, and `offset + size` within the mapped texture window. The original
routines perform no bounds checks beyond the block-size split described above.

## Validation

The card sets `tests_required = false`: exact object comparison against the
delinked original is the acceptance oracle. Local results:

- `python3 tools/match_gate.py`: all six functions 100%.
- `python3 tools/checksum.py`: all artifacts byte-identical to the original.
- `python3 tools/anticheat.py`: passed.
- `python3 -m unittest discover -s tests -t . -q`: nine tests passed.

## Hard list

None. All six functions in this TU are implemented and match.
