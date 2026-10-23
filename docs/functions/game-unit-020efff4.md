# game/unit_020efff4 — M1-T360

All eight card functions match at 100% in objdiff. The local work-area view is
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

## Hard list

None for M1-T360.

## Outside this card

`func_020f0264`, `func_020f00dc`, `func_020f019c`, and `func_020f0330`
remain in the delinked original (M1-T361).
