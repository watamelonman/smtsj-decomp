# NitroSDK geometry and palette helpers (0x0200454c)

All six functions match the original ARM instructions, literal pools and call
relocations. Original `func_` symbols are retained for objdiff and linking.

Reference source inspected before implementation:
[nitro-decomp/nitro g3.c](https://github.com/nitro-decomp/nitro/blob/main/src/gx/g3.c)
(`G3_RotZ`) and
[gx_load.c](https://github.com/nitro-decomp/nitro/blob/main/src/gx/gx_load.c)
(`GX_LoadVram16`, `GX_LoadBGPltt`, `GXS_LoadBGPltt`). The rotation axis
identifications also follow directly from the nine matrix coefficients sent to
MULT_3x3 at 0x04000468. No assembly from the reference is used.

| Original symbol | Contract and evidence | Match |
| --- | --- | --- |
| `func_0200454c` | X rotation: sends `[1,0,0; 0,cos,sin; 0,-sin,cos]`, with one represented by 4096. Inputs are 20.12 sine and cosine. | 100% |
| `func_02004588` | Y rotation: sends `[cos,0,-sin; 0,1,0; sin,0,cos]` to the same FIFO. | 100% |
| `func_020045c4` | Z rotation: sends `[cos,sin,0; -sin,cos,0; 0,0,1]`, matching reference `G3_RotZ`. | 100% |
| `func_02004600` | Selects texture matrix mode 3 at 0x04000440; streams sixteen words to LOAD_4x4 at 0x04000458. Entries 8–15 shift left four bits. The input matrix is borrowed and unmodified. | 100% |
| `func_020046b4` | Main BG palette copy to 0x05000000 plus byte offset. Uses configured DMA channel `data_0213ce44` for sizes above 28 unless channel is -1; otherwise uses the halfword CPU copy. Matches reference `GX_LoadBGPltt`. | 100% |
| `func_02004708` | Same dispatch, targeting sub BG palette at 0x05000400 plus byte offset. Matches reference `GXS_LoadBGPltt`. | 100% |

Palette sources and lengths require halfword alignment and valid destination
ranges, as for the called halfword transfer routines. No bounds checks are added
because the originals delegate these requirements to callers.

Validation uses direct ROM instruction comparison and the repository objdiff,
checksum, anticheat and unit-test gates. The task card explicitly requires no new
behavioral tests; instruction and relocation comparison is the acceptance oracle.

Hard list: none.
