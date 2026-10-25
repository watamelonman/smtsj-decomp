# game/unit_020a163c — M1-T627 / M1-T628 / M1-T629

All twenty-four functions below match the delinked ARM object at 100% objdiff.
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

| `func_020a1740` | `0x020a1740` | Searches resource (19, 1) through `func_02011810`, using a 128-byte stack key, a 128-byte stride, and the leading-u16 comparator. Returns a borrowed resource record. |
| `Unk0a163c_Unk_0a1798` | `0x020a1798` | Reads signed selector +0x6a. Negative selectors return their magnitude, truncated to u16, through `func_02011804` (whose instructions implement absolute value). Nonnegative selectors index byte tables `data_0213c258` then `data_0213c244`; table bounds follow the original resource contract. |
| `Unk0a163c_Unk_0a17d8` | `0x020a17d8` | Returns 1 for negative selectors at record +0x6a; otherwise compares `Unk02e000_GetRecordUnk1e(id)` against the unsigned byte at +0x5a with signed ordering. |
| `Unk0a163c_Unk_0a1ae0` | `0x020a1ae0` | Calls list cleanup, frees the borrowed entry allocation through `func_02053000`, clears pointer and count, and returns 1. The list container survives. |
| `func_020a1b68` | `0x020a1b68` | Looks up the record selector, converts negative selectors to 500 minus the selector, truncates the resulting id to u16, and forwards the list and value to `func_020a1b08`. |
| `func_020a2218` | `0x020a2218` | Scans count entries of stride 928 for a matching leading u16 id, returning the borrowed entry or null. A zero count avoids loading the entry pointer. |
| `func_020a22e0` | `0x020a22e0` | Looks up an entry via `func_020a2250`; absent entries return null. Otherwise constructs an output from entry +0x194/+0x190 and the caller value, then negates metadata signed halfwords +2/+4 into output words +0xc/+0x10. Metadata is borrowed through entry +0x18c. |
| `func_020a239c` | `0x020a239c` | Gets an object view via `func_0205f41c`, constructs an output from view +0xc, copies the two coordinate-query results into output +0xc/+0x10, and selects `func_0205b9a0` for a nonzero flag or `func_0205b900` otherwise. The second argument is forwarded to the view query. |


| `func_020a1854` | `0x020a1854` | Reads signed selector +0x6a; -5 maps to zero, -1 through -4 map to their magnitude, and nonnegative selectors index `data_0213c258`. Other negative selectors have no defined result in the original. |
| `func_020a19b4` | `0x020a19b4` | Allocates and clears count times 928 bytes, clears list +8, and initializes each leading entry id to 0xffff. Caller must release the allocation. |
| `func_020a1b08` | `0x020a1b08` | Scans entries for the id or first 0xffff slot, storing id and value at +8 in an unused slot. Returns 1 on success and 0 when full. |
| `func_020a1bb8` | `0x020a1bb8` | Uses cursor +0x10 to select an entry; rejects 0xffff. When flagged, resolves its object using context +0x14 and rejects null. Queries its view with argument zero into +0x18c, stores query count minus three at +2, and accumulates that count into list +8 when entry +8 is zero. |
| `func_020a1c50` | `0x020a1c50` | Formats a resource name in 64 stack bytes using `data_0214cd28` for ids at least 500, otherwise `data_0214cd48`. A flagged call requests the resource; an unflagged call resolves the object and calls `func_020a1bb8`. Unused entries return 0; others return 1. |
| `func_020a2004` | `0x020a2004` | Iterates the list twice with shared cursor +0x10, calling `func_020a1c50` then `func_020a1d00` with flag zero. Returns 1. |
| `func_020a2250` | `0x020a2250` | Searches using the record selector, translating negatives to 500 minus selector and truncating to u16. If absent, searches again using the negative selector magnitude or the two byte-table mapping, plus 500 through the wrapper. Returns a borrowed entry or null. |
| `func_020a2334` | `0x020a2334` | Returns null for an absent entry; otherwise forwards value, mode and u16 flags to `func_02065fc0` with entry +0x194/+0x190. Negates metadata signed offsets +2/+4 into output +0xc/+0x10. |

The list view follows the count load at +0 and entry-pointer load at +4 in
`func_020a1b08` and `func_020a2218`. The entry and metadata views expose only offsets and stride established by loads
and pointer increments; they do not claim gameplay identities. The work view represents only the three
unknown words before the state field; it does not claim a complete object layout.

## Validation

`python3 tools/match_gate.py` verifies all twenty-four compiled definitions at 100%.
No new behavioral tests are required by this card; binary matching checks the
exact instructions and relocations against the original implementation.

## Hard list

None of the twenty-four requested functions remain unmatched.
