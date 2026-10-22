# game/unit_0203e02c

All six functions retain their configured neutral `func_*` symbols. The evidence
below is the ARM instruction stream at each function's original address; the
underlying game actions have not been identified. Parameters are `void` because
arguments come from `func_0203ac00(index)`, rather than the handler's caller.
All six match the original instruction bytes and relocations with mwccarm 2.0/sp1p5.

| Function | Size | Observed contract and evidence |
| --- | ---: | --- |
| `func_0203e02c` | 76 | Reads arguments 0/1, masks each to a byte, calls `Unk02f2a8_Unk_035b08`, then `Unk09ee4c_Thunk_02118c6c`; publishes Boolean 0/1 via `Unk03aae8_Unk_03acf4`. Returns 1. |
| `func_0203e078` | 96 | Reads arguments 0/1 as bytes and 2 as an unsigned halfword. Calls `func_020953c4`, then publishes the Boolean result of `Unk094fe0_Unk_0953f0`. Returns 1. |
| `func_0203e0d8` | 48 | Queries slot 24 using `Unk0bc1a8_IsSlotEmpty`; if nonzero, calls `Unk0bc1a8_Unk_0bc928(24, 0xffff, NULL)` with a null request block. The request-pointer declaration agrees with `src/game/unit_021250a8.c`. Returns 1. |
| `func_0203e108` | 68 | Reads a full-width argument 0. Mode (`func_02095818`) 3 forwards it to `func_02116758`; mode 4 forwards to `func_021179a0`. Other modes do nothing. Returns 1. |
| `func_0203e14c` | 64 | Mode 3 calls `Unk116598_Unk_1167e0`; mode 4 calls `Unk116598_Unk_117a28`; other modes call `Unk0bc1a8_Unk_0bc9b4(24, 0)`. Returns 1. |
| `func_0203e18c` | 176 | Loads the worker pointer from context +0xe8. Outside modes 0/2, publishes 1 and returns 1. An active worker is reset, with the same result. Otherwise reads argument 0 as a signed halfword and queries mode again: mode 2 calls `func_020df520`, mode 0 calls `func_0209e3a8`, then starts the worker through `Unk02dcfc_Unk_02dd9c` and returns 0. A changed mode outside 0/2 publishes 1 and returns 1. |

The context layout exposes only the observed pointer at +0xe8; worker internals
remain opaque. No module boundary changes or new dependencies are introduced.

## Hard list

None.
