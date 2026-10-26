# game/unit_020efff4 — M1-T360 / M1-T361

All twelve card functions match at 100% in objdiff. The local work-area view is
0x110 bytes; field names remain neutral where the original instructions establish
only an offset, not a game-level meaning. Pointers are borrowed.

| Function | Evidence and contract |
| --- | --- |
| `Unk0efff4_Nop_0f0260` | A single `bx lr`; empty callback with no arguments. |
| `Unk0efff4_Thunk_020f7248` | Its only call targets `func_020f7248`; forwards without arguments. |
| `Unk0efff4_ClearArrF8` | Store loop clears six words at +0xf8 through +0x10c; requires the full writable work area. |
| `Unk0efff4_Unk_0f004c` | Calls `func_02008848(work, 0, 0x110)`, stores work in `data_02176df8`, then calls `func_020f019c`. Caller retains ownership. |
| `Unk0efff4_Unk_0f0300` | Enable-query call guards update of the embedded +0x50 object; field +8 equal to 10 triggers `Unk0fedd4_SetState2`. |
| `Unk0efff4_Unk_0f0098` | Signed comparisons clamp values below 0/above 100 to floating 0/1; the remaining path divides by 100.0f. Destination must be writable. |
| `func_020efff4` | Original stores establish size 0x110, field +4 = 4, five callback addresses, and zero at +0x18. Other fields are retained. |
| `func_020f04a4` | Original calls select a flag from field +0x28 == 3, store a query result at +0xf4, initialize embedded +0x50 with count 6 and the +0x44 lookup result, perform further setup, and clear the six slots. |
| `func_020f00dc` | Loads +0x10/+0x18 as signed values, computes `300 * (duration - counter) / duration`, then feeds six float slots through the clamp helper at thresholds 0, 30, 70, 120, 180, 250. Zero counter sets all six to 1. The nonzero-counter path requires nonzero duration; arithmetic must remain representable. |
| `func_020f019c` | Stores 31/4/0/0 at +0x40..+0x4c, passes the original constants and callback addresses to `func_020f711c` and `func_020f81cc`, and registers `func_020f06f4` at embedded +0x9c. Requires writable 0x110-byte work storage; callbacks retain borrowed work pointers. |
| `func_020f0264` | Calls `func_020f7188`, updates float slots outside state 1, and dispatches state 11 to `Unk0bc1a8_Unk_0bc9b4`, state 9 to embedded-object setup then state 10, and state 2 to `func_020f7de4` then state 1. Other states return. |
| `func_020f0330` | Queries the embedded object and submits entries using x=74 and y=25+15*i. Entry values select kind and flag through the original switch; float slots supply the fourth/fifth call arguments. Iteration is bounded by the signed minimum of +0xf4 and the embedded count; callers must keep that within the six-slot capacity. State 1 returns after the queries. |

The shared prefix has phase-dependent uses: +0x10 is installed as a callback by
`func_020efff4` but read as a signed counter by the update and submission functions;
+0x18 supplies the duration. No game-level name is inferred for these phases.
All four M1-T361 functions match the original ARM instructions and relocations.

## Hard list

None for M1-T360 or M1-T361.
