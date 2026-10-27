# sdk_02003e3c

All eight card functions match the original ARM instruction streams, including
literal pools and provider relocations. Original symbol names are retained.
No allocation or ownership transfer occurs. The register and provider declarations
are private to this TU; public callers supply borrowed matrix/table storage.

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

## Hard list

None of the eight requested functions remain deferred. Other functions in this
partial translation unit remain supplied by the delinked original.
