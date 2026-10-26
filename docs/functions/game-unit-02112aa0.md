# game/unit_02112aa0

All seven functions match at 100% objdiff using mwccarm 2.0/sp1p5.
Names retain the neutral `func_` symbols in the human-owned symbol configuration;
no application-level purpose is asserted. Evidence below is the original ARM
instruction stream at each function's address.

The work pointer addresses a payload with byte state and phase at +0/+1,
22 resource pointers at +0x30, and further resource groups through +0xc4.
Cleanup also reads a mode word immediately before the payload. Callers must
supply that preceding word when invoking cleanup. The storage at +0xd8 has an
unknown extent and is passed to an external transfer helper without inspection.
The 60-byte stack transfer object is opaque; its size follows the original
stack allocation, not an inferred application record format.

| Function | Size | Behavior and evidence |
| --- | ---: | --- |
| `func_02112aa0` | 324 | Releases the resource groups at +0x94 and +0xa0 and individual resources, clears nullable resource slots, drains seven updates, and clears global +4. The preceding mode word controls whether +0x28 is released. Evidence: release calls, null checks, and stores in the ARM body. |
| `func_02112be4` | 132 | Dispatches byte states 1, 3, 4, 5, 6 to their handlers; states 0 and 2 have no handler. Updates all 22 slots if the resulting state is nonzero. Evidence: seven-entry branch table and loop bound 22. |
| `func_02112c68` | 464 | Sequences animation calls across four phases, waits for external completion, increments the float at +0xcc by 1.334f, and enters state 2 after the +0xc8 counter reaches five. Evidence: slot/index argument pairs, float-add relocation and literal, and byte state stores. |
| `func_02112e38` | 384 | Waits for slots 20 and 21, chooses the byte at +8 using mode and two external tables, then returns to state 2. Evidence: tables at 0x0213cb92 and 0x0213cb8c, indexed as pairs of bytes; mode comparisons against -1, 0, 1. |
| `func_02112fb8` | 584 | Polls external readiness over five phases and handles codes 120 through 125. Code 121 can transfer a 60-byte temporary, publish completion, or retry with code 124. Evidence: halfword +0x14, result word +0x18, branch tables, and global completion store. The helper at 0x021150c8 receives both zero and the current code. |
| `func_02113200` | 88 | Starts an external transition at phase zero, waits at phase one, then clears phase and selects state 6. Evidence: calls to 0x0205257c/0x02052728 and byte stores. |
| `func_02113258` | 60 | Copies IDs and sets the global completion word in mode zero, then clears external slot 39 for every mode. Evidence: call to the already named CopyIds function, global store, and common trailing call. |

Validation: standalone instruction/relocation comparison for every function,
full objdiff match gate, anticheat, unit tests, and original-image checksum.
The unit remains linked from the delinked object until a human marks it complete.

## Hard list

None.
