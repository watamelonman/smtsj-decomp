# game/unit_020f4c50

All eight M1-T384 functions match at 100% with mwccarm 2.0/sp1p5,
using the project compiler flags. Evidence below refers to the delinked ARM
instructions at the named addresses; no higher-level gameplay meaning is assumed.

| Function | Observed behavior and contract |
| --- | --- |
| `func_020f4c50` | Writes a descriptor: work size 20, word 04 = 4, callback addresses at 0c/10/14/1c/20, and zero at 18. Word 08 remains untouched. Caller supplies writable descriptor storage. |
| `Unk0f4c50_Unk_0f4ca8` | Clears 20 bytes through `func_02008848`, stores the work pointer in `data_02176e04`, then calls the initializer. Caller retains ownership of the work area. |
| `Unk0f4c50_Unk_0f4cd4` | Sets work words 00/04/08/0c to 35/0/9/1. Word 10 is untouched. |
| `Unk0f4c50_Nop_0f4cf8` | Empty descriptor callback; original consists solely of a return. |
| `func_020f4cfc` | Switches on unsigned work word 0c. Case 6 calls `func_020f7de4`, case 7 calls `Unk0bc1a8_Unk_0bc9b4`; both receive word 00 and zero. Cases 0–5, 8–10 and out-of-range values return without action. |
| `Unk0f4c50_Nop_0f4d5c` | Empty descriptor callback; original consists solely of a return. |
| `Unk0f4c50_Nop_0f4d60` | Empty descriptor callback; original consists solely of a return. |
| `Unk0f4c50_Unk_0f51b0` | Nonzero mode converts work word 10 through `func_020ea630` and forwards the result with -1 to `Unk0d1c98_Unk_0d1d94`. Zero mode calls `func_020d1e94(1)`. |

The local structures describe observed word offsets, not recovered game types.
Callback signatures describe the inputs consumed here; empty callbacks consume none.
The slot at 20 references `func_020f4d64`, whose implementation belongs to M1-T385
and remains supplied by the delinked original. No module boundary changed.

## Hard list

None for M1-T384.
