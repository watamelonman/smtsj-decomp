# game/unit_020ca69c

All seven functions match the original ARM instructions (mwccarm 2.0/sp1p5).
Names remain neutral because the instruction/data evidence does not establish a
complete gameplay purpose. Parameters and pointers are borrowed; callers must
provide valid map/work objects and valid coordinates. Partial struct arrays mark
uninterpreted spans, not inferred element counts.

| Function | Size | Contract and evidence |
| --- | ---: | --- |
| `Unk0ca69c_Unk_0ca69c` | 8 | Adds 0x6200 to its integer argument; immediate addition at 0x020ca69c. |
| `Unk0ca69c_Unk_0ca6a4` | 12 | Adds 0xc5 and scales by 128; add/shift at 0x020ca6a4. |
| `func_020ca6b0` | 1144 | Advances signed state +0x7481 through 0–6 or timeout state 100; increments +0x7484, looks up the selected cell using signed +0x7482/+0x7483, updates current-cell bytes and packed two-bit map state. Returns completion as 0/1. Evidence: jump table at 0x020ca728, timeout arm at 0x020caa34, cell helper calls and stores. The metadata lookup is unconditional, so its result must be valid even for terminal states. |
| `func_020cab28` | 188 | Advances states 0–2 at +0x7481 through readiness checks and calls with IDs 11 or 41; returns 1 for completion/default. Evidence: comparisons at 0x020cab3c–0x020cab50 and byte increments. |
| `func_020cabe4` | 376 | Steps signed work-area coordinates +0x364/+0x365 according to direction +0x358. Accepts cell kinds 26/27 and condition ID 5, ignores packed state 3, promotes states below 2 to 2, and conditionally notifies the current map. Returns whether an eligible cell was found. Evidence: direction table at 0x020cac1c and packed-state comparisons at 0x020cacd8. |
| `func_020cad5c` | 296 | Checks selected cell kinds 26/27, writes +0x7480 from the ID-5 condition and initializes packed state to 1 in the false branch when below 1. Returns 0 for other kinds, otherwise 1. Evidence: kind checks at 0x020cadb8 and flag stores at 0x020cadf0/0x020cae00. |
| `Unk0ca69c_Unk_0cae84` | 36 | Dispatches to `func_020ca6b0` iff signed byte +0x7480 equals 1, otherwise to `func_020cab28`; forwards the result. Evidence: signed load and branch at 0x020cae84. |

Metadata bits 4–7 are extracted with unsigned left/right shifts, preserving the
original instruction sequence. No module boundary changes or new dependencies.

## Hard list

None.
