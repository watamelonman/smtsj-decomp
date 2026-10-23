# src/game/unit_020e651c.c

## M1-T146

All eight targets match at 100% in the local objdiff report. Evidence below is
from the original ARM instructions and named call relocations; no gameplay
meaning is inferred for the neutral wrappers. Data-block addresses use `u32`,
consistent with the existing bit-helper interfaces.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0e651c_Unk_0e654c` | 20 B | Passes the caller index to `Unk0e5fb8_Unk_0e61b0`, then calls `Unk094fe0_Call_0209502c` with value 1. |
| `Unk0e651c_Unk_0e6560` | 20 B | Passes the caller index to `Unk0e5fb8_Unk_0e61bc`, then calls `Unk094fe0_Call_0209502c` with value 1. |
| `Unk0e651c_Unk_0e666c` | 24 B | Obtains the current data block from `Unk094fe0_Thunk_0202e8cc` and passes it with the requested index to `Unk0e651c_TestBitChecked`. |
| `Unk0e651c_Unk_0e66c0` | 24 B | Obtains the current data block and forwards it and the caller argument to `func_020e66d8`. The reader ignores that second argument. |
| `func_020e66d8` | 24 B | Calls `Unk0e5fb8_GetBits(data, 0xFB0, 5)` and masks the result to eight bits. The unused second parameter preserves the observed wrapper interface. |
| `Unk0e651c_Unk_0e66f0` | 24 B | Forwards its second argument to `Unk0e5fb8_SetBits(0xFB0, 5, value)`; the first argument is unused. |
| `Unk0e651c_TestFlagIn` | 28 B | Returns zero for unsigned column >=64; otherwise calls `Unk094fe0_TestBit200(data, column + row * 128)`. The call and bit indexing support the existing flag name. |
| `Unk0e651c_SetFlag` | 28 B | Ignores unsigned columns >=64; otherwise forwards `column + row * 128` and the value to `Unk094fe0_Unk_095204`. The shared indexing with the flag tester supports the existing name. |

## Other existing functions

The file also contains `Unk0e651c_Unk_0e651c`, `Unk0e651c_TestFlag`,
`Unk0e651c_Get2Bits`, `Unk0e651c_Get2BitsIn`, `Unk0e651c_Set2Bits`,
`Unk0e651c_TestBitChecked`, and `Unk0e651c_SetBitChecked`. Their bodies
are unchanged by this card; the match gate verifies all 15 definitions at 100%.

## Hard list

None of the M1-T146 targets remain deferred. `func_020e6708` remains outside
this card and is not implemented in this translation unit.
