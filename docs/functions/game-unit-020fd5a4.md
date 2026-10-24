# game/unit_020fd5a4 — M1-T324

All eight card functions match at 100% with the configured mwccarm toolchain.
The local struct is a borrowed view of the accessed work fields; no allocation
or full object size is inferred. Neutral names are retained because the assembly
establishes operations but does not establish their higher-level purpose.

| Function | Contract and evidence from original ARM code |
| --- | --- |
| `Unk0fd5a4_Unk_0fd5a4` | Accepts a writable resource slot; passes its non-null value to `0205ddb4`, clears it, calls `0205bb68` twice, and clears `data_02176e1c` (020fd5a8–020fd5d4). |
| `func_020fd5e0` | Advances signed coordinates at +8/+12 using deltas at +16/+20. Negative movement clamps to the first two bounds; positive movement clamps to the last two. Reaching a bound clears that delta (020fd5e4–020fd684). |
| `func_020fd68c` | Increments the signed counter at +32 and resets it at 65535; a nonzero `020e666c(0x700)` result latches +40 to one. Calls the movement helper with bounds -81, 0, 0, 0 (020fd698–020fd6dc). |
| `Unk0fd5a4_Unk_0fd6ec` | Calls `020fd71c` unless the state at +44 equals zero (020fd6f0–020fd6fc). |
| `Unk0fd5a4_Unk_0fd704` | Calls `020fd71c` unless the state at +44 equals one (020fd708–020fd714). |
| `func_020fd71c` | Brackets mode dispatch with `0fd9b4`/`0fd9dc`. Mode +28 selects fixed setup triples (1,40,10), (2,48,10), (0,5,10), or the no-argument `02057fd8`; each valid mode invokes `020fd7d8`. Other modes only execute the bracketing calls (020fd724–020fd7d0). |
| `Unk0fd5a4_Unk_0fd9b4` | Establishes settings through `020580ec(0)`, `02057e18(31)`, `02057ddc(-1)`, and `02057524(4)` (020fd9b8–020fd9d4). |
| `Unk0fd5a4_Unk_0fd9dc` | Restores selector -1 with `02057eb8`, then calls `020572d8` (020fd9e0–020fd9e8). |

The dispatcher initially emitted an extra argument load for `02057fd8`.
Its existing declarations/callers in `src/UniteEvent.c` confirm the no-argument
contract; correcting the prototype removes that instruction and matches exactly.

## Hard list

None for M1-T324. `func_020fd7d8` belongs to the separate M1-T325 card and
continues to link from the original delinked object.
