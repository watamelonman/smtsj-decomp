# game/unit_021218d0 — M1-T615 and M1-T616

All thirteen requested functions match the original ARM instructions and relocations.
Names are retained from the symbol map; the observed field operations do not establish
more specific gameplay meanings. Layouts are borrowed partial views, not allocation sizes.
The six-element ID arrays and 32 counter bytes follow the loop bounds and five-bit index.
No module boundary changes are introduced.

| Function | Evidence and contract |
| --- | --- |
| `func_021218d0` | Iterates six halfword IDs at object +0x18c, skipping zero IDs and null lookup results. For category bits 6–10 equal to 5, increments the byte at +0x198 indexed by bits 11–15: subtype 5 adds one, subtype 6 adds two, all others do nothing. Counters retain byte wraparound. |
| `func_02121970` | Iterates six IDs at +0x1b8. The first non-null lookup whose +0x26 low two bits are nonzero latches bit zero at object +0x282; other bits are preserved. It does not clear an already latched bit. |
| `func_02121d2c` | Initializes manager +0x320 and its embedded object at +0x8c, sets object ID 0x10000, stores the persistent-work +0x48 pointer, copies the tier byte to manager +0x269, initializes fields via `func_021219d0`, refreshes flags, and returns 1. |
| `func_02121d84` | Clears persistent-work +0x6c. Looks up the signed low byte of manager +0x1fc, copying the original value to that halfword only when lookup byte +3 bit zero is set. Saves manager +0xb8/+0xc4 to work +0x1c/+0x1e, calls `func_02096c8c`, and returns 1. |
| `func_02122188` | Null object returns 0. Otherwise selects area record `(u16)object->ID - 1`, validates object +0x170 through the same signed-byte lookup, saves it to record +0x34 when valid, copies object +0x2c/+0x38 to record +0x1e/+0x20, calls `func_0209786c`, and returns 1. Caller must supply an ID accepted by the area lookup. |
| `func_02122200` | Saves three manager slot IDs as zero-based bytes at persistent-work +0x354, with -1 for null slots. The low halfword of each occupied slot ID is decremented before byte conversion. |
| `Unk1218d0_Unk_122544` | Obtains an inactive slot, combines the manager +0x3c counter with 0x20000, increments that halfword with wraparound, forwards the ID and both arguments to `func_02122494`, refreshes flags and returns the ID. Requires an available slot. |
| `Unk1218d0_Unk_122590` | Requires a live object; forwards its current ID and the supplied value with mode -1 to `func_02122494`, refreshes flags and returns the resulting object ID. |

Matching used typed partial structures and packed bitfields: the original low-bit tests
use shift pairs, while ordinary integer masks produced different instructions.

Hard list: none.

## M1-T616

All five additional functions match at 100% in objdiff, including their relocations.
The original symbol names remain neutral: the instructions establish record and field
operations but do not prove gameplay-specific names. All input pointers are borrowed.
The field initializer storage starts at object +0x2c, while the flag and slot routines
receive the outer object. The existing counter helper also receives the field base
from these initializers, as in the original calls.

| Function | Evidence and contract |
| --- | --- |
| `func_02122494` | Returns 0 for a null object or either missing ID lookup, before modifying the object. Otherwise clears object +0x294, resets the object, stores the supplied ID, value and mode at +0/+0x1d8/+0x1da, binds the value lookup pointer at +0x28, copies definition byte +5 to +0x1dd, and initializes fields. A final lookup condition latches bit 2 at +0x282. Returns 1. Value/mode halfwords retain truncation. |
| `func_02122074` | Selects saved area record `index` and the 736-byte object at manager +0x36c + index*736. Requires valid record and definition lookups. Resets the object and assigns `(u16)(index+1) | 0x10000`, copies its definition ID and byte +5, and initializes fields. Checks six IDs at object +0x1b8 using `func_020e6948` and lookup +0x26 bit 5, clearing rejected IDs, then refreshes the flag latch and returns 1. |
| `func_02122258` | Requires field storage and both valid lookup records. Fills six IDs at fields +0x18c and obtains a 40-byte packed buffer. Populates 27 twelve-byte statistic entries: the first three duplicate source values, the next five use limit 999, and entries 8–26 use packed ten-bit current/six-bit extra values with limit 300. Runs the counter helper, clears the 52-byte state block at fields +0x158, fills the first 24-byte state from source fields +0x0c–0x1e, duplicates it, and writes twice source +0x0e into the trailing signed halfword. |
| `func_02121de4` | Requires saved record, definition and field storage. Copies six saved IDs and obtains the packed buffer. Populates the same 27 entries with signed saved currents and maxima, limit 99 for entries 2–7, and limit 300 for packed entries. Runs the counter helper, clears and fills the state pair from definition +0x0a–0x12 and signed saved bytes +0x0e/+0x0f. Nonzero saved ID +0x34 is looked up through its signed low byte; lookup byte +3 bit 1 enables an initialization at fields +0x144, with amount 50 for ID 3 and 25 otherwise. |
| `func_021219d0` | Requires field storage and persistent work. Reads the 40-byte packed buffer and initializes the same entries using work +0x12–0x1e/+0x6e. Clears the state block, fills six IDs via `Unk096754_Unk_097204`, and visits four halfword item IDs at work +0/+2/+4/+6. Missing items are ignored. Items 0 and 1 populate the first and second states from packed item +4/+8 and bytes +9–+0x0e; every found item adds its middle ten-bit value to the trailing signed halfword with halfword truncation. Runs the counter helper, then validates work +0x6c with the same signed-byte flag test and amount rule as `func_02121de4`. |

Matching preserves explicit cases 8–26 so the jump table has the original bound.
Packed bitfield views retain the original shift-pair instructions. The slot ID
conversion retains the observed halfword cast and unsigned shift pair. Defining
`func_02122494` last avoids the documented objdiff local-call placement artifact
in the existing `Unk1218d0_Unk_122590` wrapper; the generated instructions still match.
The extended object view reaches +0x2e0, so manager +0x320 is expressed as the
embedded object's +0x294 storage rather than as a separate non-overlapping field.

Hard list: none. No functions remain omitted from this card.
