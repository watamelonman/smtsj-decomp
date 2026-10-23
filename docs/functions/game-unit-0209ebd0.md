# game/unit_0209ebd0

The partial state and cell layouts are local to this unit. Pointers returned by
lookup helpers are borrowed; neither function allocates or transfers ownership.
Names remain neutral because the precise gameplay operation is not established.

| Function | Size | Behavior and evidence | Match |
| --- | --- | --- | --- |
| `func_0209ebd0` | 424 bytes | Looks up map and cell entries for two signed coordinates; returns early for absent state or entries. Cell types 4–7, 8–9, 24–25, and 26–27 query helper categories 4, 5, 16, and 17 respectively. A successful query updates the cell flags, byte +1 and halfword +2, then writes state mode 16 at +0x73e8. Type-1 entries use zero flags; other entries in the last two groups use byte value 2 and flag 1. Evidence: original dispatch and field accesses; caller 0203d85c forwards signed 16-bit script arguments. | 100% |
| `func_0209ed78` | 212 bytes | Returns early without state. Initializes state work at +0x7404 with coordinates narrowed to signed bytes, sets work at +0x7410 from the third argument, and sets +0x7400 to 1. Calls 0203721c with the original coordinates, the halfword at +0x7428, the byte at +0x5b, and kind 2, then writes mode 17. Evidence: original call sequence and caller 0203c0ec forwarding three signed 16-bit arguments. | 100% |

Validation uses the delinked original as the executable reference. No new tests
are required by the card. Both compiled functions match all original instructions
and relocations through objdiff. The unit remains linked from the delink pending
the human-owned completion flag.

Hard functions: none.
