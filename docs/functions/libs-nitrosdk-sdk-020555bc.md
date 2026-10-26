# sdk_020555bc

M2-T030 covers eight ARM functions and M2-T031 adds the seven remaining functions, so
all fifteen functions in this translation unit now match. Original `func_` symbols are
retained because symbol configuration is human-owned. Behavioral names below describe
instruction evidence, without assigning undocumented SDK entry-point names.

Public-source lookup: [pret/pokediamond GX_g2.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g2.c)
contains `G2x_SetBlendAlpha_` and related blend helpers, which supports the
blend/`BLDCNT` interpretation of `func_0205571c`, `func_02055740` and `func_0205577c`.
It has no BG scroll-set wrappers, so the scroll-setter interpretation of
`func_020555bc`, `func_020555e4`, `func_0205560c`, `func_02055634`, `func_0205565c`,
`func_02055684`, `func_020556ac`, `func_020556d4` and the `data_02143b10` table is
instead justified by their register addresses (`0x0400101c`, `0x04001018`,
`0x04001014`, `0x04001010`, `0x0400001c`, `0x04000018`, `0x04000014`, `0x04000010`
and the neighbouring main/sub BG0-3 scroll registers) and by caller `func_02055058`.
The implementations here follow the original instructions and register literals.

| Function | Contract and evidence | Verification |
| --- | --- | --- |
| `func_020555bc` | Writes sub BG3 scroll at `0x0400101c`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_020555e4` | Writes sub BG2 scroll at `0x04001018`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_020556fc` | Dispatches `data_02143b10[index](x, y)`: table entries 0–7 are the main/sub BG0–3 scroll setters (index 0→main BG0 `0x04000010`, 3→main BG3 `0x0400001c`, 4→sub BG0 `0x04001010`, 7→sub BG3 `0x0400101c`), so `index` selects the background and the arguments are its x/y coordinates. No bounds check. Evidence: table entries at `config/arm9/relocs.txt:38372-38379` and caller `func_02055058` (`0x02055148`), which passes `(index, 0, 0)`. | 100% objdiff |
| `func_0205571c` | Clears main BLDCNT (`0x04000050`) for engine zero, sub BLDCNT (`0x04001050`) otherwise. | 100% objdiff |
| `func_0205577c` | Calls `func_02055740(engine, 0, second, weight, 16-weight)`; intended alpha weights are 0–16. | 100% objdiff |
| `func_0205579c` | Tail-forwards source, destination offset and byte count to `func_02004c0c`; preserves that routine's buffer requirements. | 100% objdiff |
| `func_020557a8` | Tail-forwards source, destination offset and byte count to `func_02004b4c`; preserves that routine's buffer requirements. | 100% objdiff |
| `func_020557b4` | Tail-forwards source, destination offset and byte count to `func_02004bac`; preserves that routine's buffer requirements. | 100% objdiff |

### M2-T031 additions

| Function | Contract and evidence | Verification |
| --- | --- | --- |
| `func_0205560c` | Writes sub BG1 scroll at `0x04001014`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_02055634` | Writes sub BG0 scroll at `0x04001010`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_0205565c` | Writes main BG3 scroll at `0x0400001c`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_02055684` | Writes main BG2 scroll at `0x04000018`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_020556ac` | Writes main BG1 scroll at `0x04000014`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_020556d4` | Writes main BG0 scroll at `0x04000010`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_02055740` | Selects main `BLDCNT` (`0x04000050`) when `engine` is zero, sub `BLDCNT` (`0x04001050`) otherwise, then forwards `first`, `second`, `eva`, `evb` to `func_02003e3c` with that register. The BLDCNT addresses and the direct five-argument call are the evidence; `func_02003e3c` keeps its neutral name. | 100% objdiff |

The dispatch table and forwarding targets remain external; other functions in the
original translation unit remain supplied by the delinked object. No module
boundary changes or new dependencies are introduced.

## Hard list

None for the fifteen functions in this translation unit.
