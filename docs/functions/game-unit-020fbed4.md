# src/game/unit_020fbed4.c

All eight functions match at 100% with the configured mwccarm compiler and
objdiff. Names retain their configured neutral symbols; the instruction-level
behavior below does not establish a game-level purpose. Layouts are private to
this translation unit and follow observed offsets. No module boundary changed.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `func_020fbed4` | 592 | Initializes a writable 0x28c0-byte work block. Clears the global pointer during initialization, conditionally loads resources when the id-6 descriptor is available, sets up 76 entries with 96-byte strides, submits 16 palette entries at 32-byte strides, draws entries 12–14, and publishes the work pointer. Evidence: descriptor offsets 0/0x24, loop bounds, resource calls, and final global store. |
| `func_020fc124` | 88 | Fills callback metadata: size 0x28c0, flags 4, update/no-op/draw/cleanup/event slots; clears slot 0x18 and leaves slot 8 untouched. Evidence: stores to offsets 0, 4, and 0x0c–0x20. |
| `Unk0fbed4_Nop_0fc17c` | 4 | Empty callback with no arguments or side effects. Evidence: sole return instruction. |
| `func_020fc180` | 184 | Returns early for state 0 without readiness. Otherwise initializes handle fields 0x2c/0x37 on the eligible first frame, changes states 0/2 to 1 when the external query clears, and increments the frame word. Evidence: state comparisons, conditional calls, and final increment. |
| `func_020fc238` | 360 | Requires a writable work block. When ready, marks and draws six wrapping entries, advances the signed offset through 0–384, and submits fixed entries at the observed coordinates. Preserves the original OR condition for vertical bounds, even though it admits every signed 16-bit position. Evidence: signed halfword accesses, wrap subtraction, branch conditions, and draw calls. |
| `func_020fc3a0` | 104 | Releases resource fields 0x0c and 0x28a4–0x28ac, releases the handle at 0x28b0, conditionally clears that handle, and clears the global pointer. Evidence: five release calls and following stores. |
| `func_020fc408` | 108 | Accepts a work block and readable event word. Dispatches events 0 and 1 to external calls; event 1 also clears global-work readiness. Event 4 sets state 2 and requests transition 2. Events 2/3 and out-of-range words do nothing. Evidence: five-way jump table and associated stores/calls. |
| `func_020fc474` | 272 | Draws vertical lines from x=-4 through x<256 and horizontal lines from y=-4 through y<192, spaced by 8. Uses value 66 for indices divisible by five and 46 otherwise; indices start at -1. Evidence: signed remainder sequence, loop bounds, and six-argument drawing calls. |

## Representation notes

The two entry submission paths preserve different address expressions because
the original computes a work-relative flag address and a separately based entry
address. See DEC-008 in `docs/DECISIONS.md`. Unknown fields retain offset names;
resource strings are used through their existing symbols without inferring UI names.

## Hard list

None. No functions were omitted.
