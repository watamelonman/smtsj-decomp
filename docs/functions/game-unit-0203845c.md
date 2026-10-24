# game/unit_0203845c (M1-T283)

All four original address-based symbols are retained: their broader game purpose
is not established. Parameters use partial local structure views; padding denotes
unexamined storage, and one-byte embedded arrays mark storage beginnings rather
than known object sizes. No module boundary changed.

| Function | Contract and instruction evidence | Match |
| --- | --- | --- |
| `func_0203845c` | Requires a valid work object. Calls the two embedded reset helpers at offsets 0x205c and 0x2084. Saves `func_02007a58`'s result; when `func_02052624() < 31`, polls volatile VCOUNT (0x04000006) until 191–213 inclusive. Calls `func_0202546c`, then restores the saved value via `func_02007a6c` and calls `func_02007ad4`. Resolves the first resource-relative offset, stores the borrowed pointer at 0x54 (null for missing data/table entry), and calls `func_0202172c`. | 100% |
| `func_02038538` | Requires a valid work object. Allocates from the embedded pool at 0x24a4 using `func_02058a64`; -1 returns immediately. Otherwise passes the index, embedded address 0x418, entry/value/channel integers and an unsigned byte to `func_02058944`, then returns the index. The byte's broader meaning is unknown. | 100% |
| `func_020385a4` | Requires valid work/header/record storage. Reads unsigned count at header+7 and signed IDs at offsets 0–2 of each 36-byte record. Submits each ID other than -1 on its corresponding channel, with final byte 1. Reloads count after each iteration. Appends three channels each for count+5/value 5/byte 1, count+6/value 6/byte 0, and count+7/value 7/byte 0, reloading count before each latter group. Allocation failures are ignored as in the original. | 100% |
| `func_0203875c` | Requires a valid work object. Makes three submissions with entry/value zero, channels 0, 1 and 2, and final byte 1. Allocation failures are ignored. | 100% |

The inline table helper preserves the original null-table and unsigned bounds
checks before reading the relative offset. The explicit byte stride in the record
loop preserves the original independently incremented index and record offset.
Definitions follow original address order; the full objdiff report confirms
all callers and their relocations as well as the allocator.

No new behavioral tests are required by this card. Validation uses the original
object as the instruction/relocation oracle, plus repository tests and ROM checksum.

## Hard list

None.
