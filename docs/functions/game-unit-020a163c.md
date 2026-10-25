# game/unit_020a163c — M1-T627

All eight functions below match the delinked ARM object at 100% objdiff.
Names remain neutral: the instructions establish field and resource operations,
but do not establish a gameplay meaning. Source comments cite original addresses.
The remaining functions in this TU continue to come from the delinked object;
no completion flag or module boundary changed.

| Function | Original address | Contract and instruction evidence |
| --- | --- | --- |
| `Unk0a163c_Unk_0a1718` | `0x020a1718` | Loads the first u16 from each nonnull record and returns their signed difference (`ldrh`, `ldrh`, `sub`). |
| `Unk0a163c_Unk_0a1728` | `0x020a1728` | Selects resource (19, 1) through `func_020445d0`, then returns `func_0204fe18`'s query result. Its units are not established. |
| `Unk0a163c_Unk_0a1814` | `0x020a1814` | Selects resource (18, 1) through `func_020445f4`, then forwards the caller's index to `func_0204fed8`. Returned storage is borrowed. |
| `Unk0a163c_Unk_0a1834` | `0x020a1834` | Same lookup sequence with resource (18, 0); the resource routines govern index validity. |
| `Unk0a163c_Call_020a1b08` | `0x020a1ba0` | Adds 500 to the u16 id, truncates back to u16 using the original shift pair, and tail-calls `func_020a1b08` with the list and value unchanged. |
| `Unk0a163c_Unk_0a21f8` | `0x020a21f8` | Stores 1 at work +0x0c and tail-calls `func_020a208c`, returning its result. Work remains caller-owned. |
| `Unk0a163c_Thunk_020a208c` | `0x020a220c` | Tail-calls `func_020a208c` with the borrowed work pointer and returns its result. |
| `Unk0a163c_Call_020a2218` | `0x020a22c8` | Adds 500 to the u16 id with truncation, then tail-calls `func_020a2218`. The callee scans the list and returns a borrowed matching entry or null. |

The list view follows the count load at +0 and entry-pointer load at +4 in
`func_020a1b08` and `func_020a2218`. The work view represents only the three
unknown words before the state field; it does not claim a complete object layout.

## Validation

`python3 tools/match_gate.py` verifies all eight compiled definitions at 100%.
No new behavioral tests are required by this card; binary matching checks the
exact instructions and relocations against the original implementation.

## Hard list

None of the eight requested functions remain unmatched.
