# game/unit_020a03cc

All seven functions are ARM C implementations. Names remain the original neutral
symbols because the instructions establish data operations but do not establish a
specific gameplay purpose. Context and work-area pointers are borrowed; no function
allocates or frees them. Array spans in the context view mark the observed subobject
boundaries, not independently established array element counts.

| Function | Size | Contract and instruction evidence |
| --- | ---: | --- |
| `func_020a03cc` | 48 | Returns 1 only when `func_02053800(0,3)` and then `ScanVisor_Unk_0a2b58()` each return exactly 1; otherwise 0. The two compare/branch sequences establish the short circuit. |
| `func_020a03fc` | 84 | Acquires the table block, calls the visor helper with 1, clears byte 14 in sixteen stride-16 records, calls the helper with 0, then clears byte 15 in the next sixteen records. Evidence: stores at base+14 and base+271, with index shifted by four. |
| `func_020a0450` | 1236 | Requires a valid context and selected cell/element. Resolves the element before dispatching signed substate +7481. States 0..2 poll queries and update the current cell; state 3 sets the selected two-bit entry to 3 and updates matching-area data; states 4..6 drive the completion queries. State 100 resets task/root state and the current cell, then sets substate 3. Unknown states return 1. The jump table, separate case-100 branch, +7484 counter, and packed-field shifts establish these operations. |
| `func_020a0924` | 188 | Substate 0 waits for readiness, starts operation 10 or 40 according to query 2, then increments +7481. Substate 1 waits for completion, acknowledges and increments. Substate 2 reports readiness; other states return 1. Evidence: three signed-byte cases and exact-one comparisons. |
| `func_020a09e0` | 424 | Uses signed work coordinates +364/+365 and heading +358: 0 decrements y, 1 increments x, 2 increments y, 3 decrements x. Probes kinds 24/25, checks direction nibble and mode permission. Two-bit state 3 is rejected; states below 2 are promoted to 2 and notified; state 2 is accepted unchanged. Area-matched notifications narrow coordinates to signed 16 bits. Returns 0/1. Evidence: unsigned byte range test, four-bit shifts, unsigned state comparison and signed narrowing shifts. |
| `func_020a0b88` | 312 | Requires valid selected cell/element. Rejects kinds other than 24/25. Permission query sets mode +7480 to 1 and calls the mode helper, or clears it and ensures the selected two-bit state is at least 1, notifies the matching area, and calls the refresh helper. Returns 1 for either supported kind. Evidence: paired kind comparisons, mode-nibble extraction, signed state comparison and branch around the fallback path. |
| `func_020a0cc0` | 36 | Dispatches to 020a0450 only when signed mode +7480 equals 1; otherwise to 020a0924, forwarding its result. Evidence: signed byte load and the two calls. |

The element bitfield view preserves the original word loads and extraction shifts.
The signed context bytes and unsigned packed state checks are intentionally distinct.
No module boundary changes or new dependencies are introduced.

## Hard list

None. All seven standalone instruction and relocation comparisons match the original.

Validation: the full objdiff report scores all seven functions at 100%. The
match, checksum, anticheat and nine repository unit tests pass. Checksum reports
all artifacts byte-identical to the original.
