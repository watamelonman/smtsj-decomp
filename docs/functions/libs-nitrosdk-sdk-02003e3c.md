# sdk_02003e3c

All sixteen implemented functions match the original ARM instruction streams, including
literal pools and provider relocations. Original symbol names are retained.
No allocation or ownership transfer occurs. The hardware/provider declarations remain private to this TU. Public callers
supply borrowed matrix/table storage; matrix construction permits null output.

Reference sources consulted before implementation:
- [pret/pokediamond GX_g2.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g2.c)
- [pret/pokediamond GX_g3imm.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g3imm.c)
- [pret/pokediamond GX_g3x.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g3x.c)

| Symbol | Evidence and contract |
| --- | --- |
| `func_02003e3c` | `G2x_SetBlendAlpha_` in GX_g2.c: pack plane masks, alpha mode and two coefficients into the supplied 32-bit blend register. Coefficients are 0..16. |
| `func_02003e58` | `G2x_SetBlendBrightness_` in GX_g2.c: sign selects darken/brighten; magnitude goes to control +4. Brightness is -16..16. |
| `func_02003e80` | `G3_LoadMtx44`: original FIFO opcode 0x16 and 64-byte sender identify a sixteen-word Q12 matrix load. |
| `func_02003e9c` | `G3_LoadMtx43` in GX_g3imm.c: opcode 0x17 followed by the existing 48-byte FIFO sender. |
| `func_02003eb8` | `G3_MultMtx43` in GX_g3imm.c: opcode 0x19 followed by the existing 48-byte FIFO sender. |
| `func_02003ed4` | `G3_MultMtx33` in GX_g3imm.c: opcode 0x1a and existing 36-byte copy provider. |
| `func_02004068` | `G3X_ClearFifo` in GX_g3x.c: call the existing 128-no-op FIFO provider, then poll volatile GXSTAT bit 27 until idle. |
| `func_02004270` | `G3X_SetFogTable`: original destination 0x04000360 identifies the hardware fog-density table; existing 32-byte copy provider uploads eight caller-owned words. |

## M2-T438

Reference also consulted: [pret/pokediamond GX_g3_util.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g3_util.c).
This older SDK combines construction/loading; the original here delegates matrix
construction to existing providers before optionally loading GX. Symbols remain
neutral original names. All eight additions score 100% in objdiff.

| Symbol | Evidence and contract |
| --- | --- |
| `func_020041b8` | `G3X_SetFog`: enable writes fog offset at 0x0400035c and mode/slope bits in DISP3DCNT; disable clears fog enable and status bits. Arguments must fit hardware fields. |
| `func_02004210` | `G3X_GetClipMtx`: GXSTAT busy bit 27 returns -1 without writing; otherwise existing 64-byte copy provider reads sixteen clip-matrix words into caller storage and returns zero. |
| `func_02004240` | `G3X_GetVectorMtx`: same readiness contract, with nine words from 0x04000680 via the 36-byte copy provider. |
| `func_02004284` | `G3X_SetClearColor`: pack 15-bit color, five-bit alpha, six-bit polygon ID and boolean fog, then write 15-bit clear depth. |
| `func_0200434c` | `G3X_GetMtxStackLevelPV`: stack-busy bit 14 returns -1 without writing; otherwise write GXSTAT bits 8..12 to caller-owned output and return zero. |
| `func_0200437c` | `G3X_GetMtxStackLevelPJ`: same readiness contract, reading projection level bit 13. |
| `func_02004440` | Perspective-W wrapper: provider 0x02001e48 computes cosine/sine and writes -scale at matrix word 11, corroborating `G3i_PerspectiveW_`. Six Q12 inputs are half-angle sine/cosine, aspect, near/far distances and W scale. Optional sixteen-word output defaults to stack storage; nonzero draw selects projection mode zero and loads the matrix. Divisors must be nonzero. |
| `func_02004500` | Look-at wrapper: provider 0x0200167c normalizes position minus target, crosses with up and computes negative dot-product translation, corroborating `G3i_LookAt_`. Three caller-owned Q12 vectors must define a valid basis. Optional twelve-word output defaults to stack storage; nonzero draw selects position/vector mode two and loads it. |

## Hard list

None of the sixteen requested functions remain deferred. Other functions in this
partial translation unit remain supplied by the delinked original.
