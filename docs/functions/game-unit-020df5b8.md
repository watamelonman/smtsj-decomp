# game/unit_020df5b8

All seven functions match at 100% in objdiff with mwccarm 2.0/sp1p5.
The unit remains delink-backed until a human marks it complete.
Names are retained from the symbol configuration; no additional purpose is inferred.

| Function | Evidence and contract |
| --- | --- |
| `Unk0df5b8_GetEntry42` | Looks up resource kind 32, index 0, calls its preparation routine, and returns the caller-selected 42-byte record. The multiply by 42 supports the existing name. No bounds check is present. |
| `func_020df5e8` | Tests entry zero's signed condition, then checks three pairs of signed halfwords at offsets 30–40 against `func_0209993c`. On the first satisfied threshold, sets the bit from offset 2, passes the payload at offset 6 to `Unk0de678_Unk_0dec94`, and returns 1; otherwise returns 0. |
| `Unk0df5b8_Nop_0df668` | Empty callback, established by the sole `bx lr` instruction; installed as the finish callback in descriptors 4 and 5. |
| `func_020df66c` | Tail-calls `func_ov000_02176ea0`; the delink object's ABS32 relocation identifies the overlay target. |
| `func_020df678` | Tail-calls `func_ov001_0217797c`; the delink object's ABS32 relocation identifies the overlay target. |
| `Unk0df5b8_Unk_0df684` | Obtains the buffer from `Unk108bc8_Unk_108c60` and forwards destination, buffer, and size to `func_02008904`. The middle incoming argument is unused. |
| `func_020df6a8` | Initializes six 24-byte descriptors at `data_02176be8`. Sets data pointers, byte sizes, rounded-up 128-byte block counts, callbacks, and flags according to index, then returns the array base. The sizes and offsets are directly visible in the instruction stream. |

`Entry42` and `Record` are private layouts inferred from stride and field accesses.
The first contains only the observed 42 bytes; payload contents and condition meanings
remain unknown. The descriptor count is established by the initializer loop bound.
No module boundary changes are introduced.

## Hard list

None.
