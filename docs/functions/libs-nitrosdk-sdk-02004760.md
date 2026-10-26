# sdk_02004760

Known-source reference: [pret/pokediamond GX_load2d.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_load2d.c).
The hardware addresses, argument order and inline OBJ mapping accessors agree with
this TU. Configured symbol names are retained because symbol configuration is human-owned.
All offsets and lengths are bytes; callers must provide valid source/destination
ranges and two-byte alignment for palettes or four-byte alignment for OAM/OBJ.
Transfers use the configured DMA channel unless it is -1 or the length is at most
the listed CPU threshold. No module boundaries change.

| Function | Known SDK equivalent | Destination base | CPU threshold | objdiff |
| --- | --- | --- | --- | --- |
| `func_02004760` | `GX_LoadOBJPltt` | `0x05000200` | 28 | 100% |
| `func_020047b8` | `GXS_LoadOBJPltt` | `0x05000600` | 28 | 100% |
| `func_02004810` | `GX_LoadOAM` | `0x07000000` | 48 | 100% |
| `func_02004864` | `GXS_LoadOAM` | `0x07000400` | 48 | 100% |
| `func_020048bc` | `GX_LoadOBJ` | `0x06400000` | 48 | 100% |
| `func_02004914` | `GXS_LoadOBJ` | `0x06600000` | 48 | 100% |

Each function copies from the supplied source to its destination base plus offset.
The palette functions use the 16-bit DMA/CPU routines; the others use 32-bit copies.
The inline mapping accessors follow the known source and preserve its compiler
constant propagation behavior. The TU remains linked from the delink pending human completion.

Hard list: none.
