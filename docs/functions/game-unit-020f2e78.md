# game/unit_020f2e78 — M1-T684 / M1-T685

These functions borrow a state whose signed kind and phase bytes are at
`+0x7480/+0x7481`, and whose signed tick counter is at `+0x7484`. Names remain
address-based because the overall transition purposes are not established.
Partial local layouts describe only accessed fields; the 16-entry selector
array extent is inferred from the four-bit index. No module boundary changes.

| Function | Contract and evidence |
| --- | --- |
| `func_020f2e78` | Advances five timed phases; increments the current cell's u16 timer, waits over 40/10/2 ticks, clears seven visor slots, calls the body reset routines and finishes by setting kind 1. Returns 1 for phases outside 0..4, otherwise 0. Evidence: counter comparisons, seven-iteration loop and root +0x14/+0x18 stores. |
| `func_020f307c` | Advances nine selection phases, drains pending mode entries until mode 7, and waits for the root operation to finish. Flags 0x73c/0x73b gate resources 50/51, while flag 0x73a selects resource 14 or 15. Low-byte choices select kinds 2/4/5 or open resource 52; its confirmation selects kind 3 and sets root +0x54. Returns 1 only for phases outside 0..8. Evidence: flag calls, resource ids, choice switches and state stores. Matches all 1,024 bytes. |
| `func_020f347c` | Advances five phases, selects entry 6, waits on readiness, and uses cell word bits 20..23 to index signed halfwords at state +0x28. Calls `0205e484` with ids below 29 and caches that id at +0x73d4. Returns 0. Evidence: packed-field extraction and matching sound call/cache pattern in `020305a8`. |
| `func_020f362c` | Advances three phases, waiting for four subsystem predicates before clearing kind, phase and timer, setting +0x73dc to 1 and +0x73cc to 8. Returns 0. Evidence: signed phase comparisons and reset stores. |
| `func_020f370c` | Advances six phases, initializes the body operation, waits over 60 ticks, then borrows the work-area resource and reverses direction 0/1/2/3 to 2/3/0/1 before relocation. Waits on subsystem predicates and reports completion when +0x7440 is nonzero in phase 5, or for phases outside 0..5. Evidence: direction switch, relocation arguments and signed phase dispatch. Matches all 532 bytes. |
| `func_020f3920` | Advances three phases; waits for readiness, sets root words to 4/3, moves the cached cell by one square according to work-area direction 0..3, and calls `02034b7c`. Returns completion for nonzero +0x7440 in phase 2 or any unrecognized phase. Evidence: coordinate arithmetic and call arguments. The direction member preserves two observed reads, including the reload for the call. |
| `func_020f3a78` | Disables two subsystems, resets 128 entries at +0x24a8, copies vectors from `data_0213c888/894`, restores matrix/global state, performs geometry MMIO writes and reenables the subsystem. Evidence: fixed loop bound, vector copies, nine-word matrix, and stores to 0x04000444/448. The 16-word context layout follows the identical call sequence in `unit_020f6f48`. |
| `func_020f3be0` | Configures the current cell from resource record 5, resets its timer and applies the state id at +0x58, or starts phase 3 in alternate mode. Both branches set +0x748c/+0x7490 to 1 and clear kind. Evidence: record byte +0x19, cell byte/halfword stores and common tail. |
| `func_020f3ca8` | Dispatches kinds 0..5 to the six update handlers, returns their result, and returns zero for other kinds. Evidence: six-entry jump table. |
| `func_020f3d28` | Runs `020f3a78` for kind 1/4, kind 2 except phase 3, and kinds 3/5 only for signed phases 0..1; other kinds do nothing. Evidence: signed phase checks and jump table. |

All state pointers must refer to the original full state allocation. The borrowed
cell, resource, root and work-area pointers follow the original non-null contract.
No new runtime dependencies or tests: this card requires object identity and ROM
checksum validation rather than a headless behavior harness.

Hard list: none.

Validation: objdiff reports 100% for all ten functions. The match and checksum
gates pass (all artifacts byte-identical); anticheat passes, and all nine
repository unit tests pass.
