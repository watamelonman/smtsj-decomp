# sdk_020555bc

M2-T030 covers eight ARM functions. Original `func_` symbols are retained because
symbol configuration is human-owned. Behavioral names below describe instruction
evidence, without assigning undocumented SDK entry-point names.

Public-source lookup: [pret/pokediamond GX_g2.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g2.c)
contains `G2x_SetBlendAlpha_` and related blend helpers. This supports the register
family interpretation, but does not contain these exact wrapper implementations.
The implementations here follow the original instructions and register literals.

| Function | Contract and evidence | Verification |
| --- | --- | --- |
| `func_020555bc` | Writes sub BG3 scroll at `0x0400101c`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_020555e4` | Writes sub BG2 scroll at `0x04001018`; masks both unsigned coordinates to nine bits. | 100% objdiff |
| `func_020556fc` | Calls `data_02143b10[index]` with source and byte count; callers must supply a valid table index and callback-compatible buffer. | 100% objdiff |
| `func_0205571c` | Clears main BLDCNT (`0x04000050`) for engine zero, sub BLDCNT (`0x04001050`) otherwise. | 100% objdiff |
| `func_0205577c` | Calls `func_02055740(engine, 0, second, weight, 16-weight)`; intended alpha weights are 0–16. | 100% objdiff |
| `func_0205579c` | Tail-forwards source, destination offset and byte count to `func_02004c0c`; preserves that routine's buffer requirements. | 100% objdiff |
| `func_020557a8` | Tail-forwards source, destination offset and byte count to `func_02004b4c`; preserves that routine's buffer requirements. | 100% objdiff |
| `func_020557b4` | Tail-forwards source, destination offset and byte count to `func_02004bac`; preserves that routine's buffer requirements. | 100% objdiff |

The dispatch table and forwarding targets remain external; other functions in the
original translation unit remain supplied by the delinked object. No module
boundary changes or new dependencies are introduced.

## Hard list

None for the eight functions assigned to this card.
