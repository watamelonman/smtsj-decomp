# sdk_02003e3c

All twenty-two implemented functions match the original ARM instruction streams, including
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

## M2-T439

Reference sources consulted: [pret/pokediamond GX_g3x.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g3x.c)
and [GX_g3_util.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g3_util.c).
The delinked image is an older SDK revision than those files: the stack-unwind helper here
pops the projection level in matrix mode 0 and the position level in mode 2, the init routine
writes the 16-bit clear-image offset at `0x04000356`, and the orthographic provider takes the
matrix directly instead of a `load` flag. The C follows the delinked instruction stream in each
case. Six of the seven additions score 100% in objdiff; the FIFO filler is deferred (below).

| Symbol | Evidence and contract |
| --- | --- |
| `func_02003ef0` | `G3X_Init`: drains the FIFO through `func_02004068`, waits on GXSTAT bit 27, clears DISP3DCNT/GXSTAT/BG0OFS, applies the DISP3DCNT mode bits, resets GXSTAT stack bits, unwinds the matrix stack, clears the clear-color/fog registers, resets BG0CNT priority, fills the tables and restores the default polygon/texture attributes. The extra halfword write at `0x04000356` is the 16-bit clear-image offset. Geometry hardware must be powered. |
| `func_02003ffc` | `G3X_ResetMtxStack`: waits for the engine, sets the GXSTAT stack bit, enables fog/edge display bits, calls the shared stack unwind and restores the polygon/texture attributes. |
| `func_02004090` | `G3X_InitMtxStack`: reads both stack levels with retry loops, then pops the projection stack in matrix mode 0 and the position stack in mode 2, clearing identity state between modes. |
| `func_02004128` | `G3X_ResetMtxStack_2`: identical unwind to `func_02004090` but omits the polygon/texture attribute writes; caller `func_02003ffc` restores those. |
| `func_020042ac` | `G3X_InitTable`: clears the 16-byte edge-color and 96-byte fog tables through `MI_DmaFill32Async`/`MI_DmaFill32` when `data_0213ce44` (GXi_DmaId) is configured, otherwise through `MIi_CpuClear32`; then writes zero to the shininess port 32 times. |
| `func_0200449c` | Orthographic wrapper: provider `func_02001f94` writes a Q12 4x4 matrix with the W scale at word 15, off-diagonal zeros and three diagonal extents, matching `G3i_OrthoW_`. Arguments are top, bottom, left, right, near, far and scale. Optional null output uses sixteen temporary words; nonzero draw selects projection mode zero and loads the matrix via `func_02003e80`. Extents must be nonzero. |

## Hard list

`func_020043ac` (148 bytes, `GXi_NopClearFifo128_`) remains supplied by the delinked
original. NitroSDK implements it as a hand-written assembly block (32 `stmia` of four zero
registers to the FIFO port); the reference source itself is asm. C cannot reproduce the
required `mov`-four-zero-registers-then-`stm` shape with this compiler: 128 scalar stores
compile to 520 bytes of `str`; repeated same-address 16-byte struct assignments compile to
`str` pairs or `ldm`+`stm` copies (300-1044 bytes); a 512-byte aggregate zero assignment
compiles to an inline `stmia` loop (84 bytes). None of these are the 148-byte original and
adding inline asm is forbidden, so it is deferred for a human to decide whether the gate
should treat it as an assembly-only function.

None of the sixteen earlier requested functions remain deferred. Other functions in this
partial translation unit remain supplied by the delinked original.

