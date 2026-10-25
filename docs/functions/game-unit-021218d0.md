# game/unit_021218d0 — M1-T615

All eight requested functions match the original ARM instructions and relocations.
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

## Outside this card (M1-T616)

The following remain in the delinked original: `func_02122494`, `func_02122074`,
`func_02122258`, `func_02121de4`, and `func_021219d0`.
