# src/game/unit_0211f0a0.c

`func_0211f0a0` matches the delinked ARM original at 100% in objdiff with
mwccarm 2.0/sp1p5. The unit remains delink-backed until a human marks it complete.

| Function | Evidence and contract |
| --- | --- |
| `func_0211f0a0` | 0x0211f0a0–0x0211f2d0 (560 B). Bails out unless the work pointer's fields +0x00, +0x08, +0x0c and signed halfword +0x24 are nonzero and its float +0x20 is not 0.0. Clears three 24-byte entries returned by `func_0205e318`, sets their x at +8 from width +0x24 around 128 (with the middle entry's +0x0c set to the width), and submits them through `func_0205e048` with flag words 0x01000001, 0x02000001 and 1. In state +0x0c == 2 it also draws a line through `func_02060b60` with flag word 0x05000001. |

The 24-byte entry layout (`index` +0, position +8/+10, size +12/+14, flags
+16, word +20) is inferred from `func_0205e048`'s field accesses. The local work
layout records only the fields this function touches; the padding is unknown.

## Hard list
- none
