# game/unit_021159f8

All six task M1-T220 functions match the original ARM instructions and relocations.
Names are retained from the symbol map. Coordinates, ids, and field offsets below
are observed in the original instructions; no gameplay interpretation is assumed.
All pointers returned by external accessors are borrowed and assumed valid.

| Function | Observed behavior and contract | Match |
| --- | --- | --- |
| `func_021159f8` | Compares area against selector `(8,3)`. Queries 346 for `(23,18)`, 347 for `(22,17)`, or 348 for `(24,17)`; returns zero otherwise. Query results are preserved without boolean normalization. | 100% |
| `func_02115a80` | Uses `(23,18)` by default, `(22,17)` for selector 6, `(24,17)` for 7. Passes GameState blocks at 0x38e8 and 4 to `func_0209a884`; calls cell helpers with 1 and 0 and copies record 19's byte at 0x19 through `SetOnlyBit`. Stores cell state 1 and clears its 16-bit counter. | 100% |
| `func_02115b1c` | Uses the same coordinate selection, with selector from GameState+0x73ec. Increments the cell counter modulo 65536. If `Unk09a268_Unk_09a844` returns exactly 1, calls both cell helpers with 1, applies record 19's byte, stores state 2, clears the counter, and returns 1; otherwise returns 0. | 100% |
| `Unk1159f8_IsCurrent` | Boolean equality with selector `(8,3)`. The existing name is supported by that selector comparison; no particular kind of area is inferred. | 100% |
| `func_02115bf4` | Returns 1 outside `(23,17)` in the selected area. At that position, queries 346, 347, 348 in order with short circuit evaluation and returns 0 if any query returns zero. | 100% |
| `Unk1159f8_Unk_115c68` | Reads the work area's halfword at 0x35c as the area argument to `func_021159f8`, forwards the two coordinates, and maps exactly 1 to 2 and all other values to 0. | 100% |

The local padded structures describe only observed accesses, not complete shared
layouts. There is no module boundary change. Selector values other than 5, 6,
and 7 retain the default pair, as in the original.

## Hard list

None.
