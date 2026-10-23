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

## M1-T147

All eight targets are at 100% in the local objdiff report (`match_gate.py`: 417 functions OK;
`checksum.py`: image byte-identical). Seven were already in the file with bodies that matched;
this card adds comments to them and adds `func_020e6708`.

| Function | Size | Behavior and evidence |
| --- | --- | --- |
| `Unk0e651c_SetBitChecked` | 28 B | Ignores indices > 0x7FF; otherwise forwards `(index, value)` to `Unk094fe0_Call_0209502c`. |
| `Unk0e651c_TestFlag` | 32 B | Passes the current data block (`Unk094fe0_Thunk_0202e8cc`) and both args to `Unk0e651c_TestFlagIn`. |
| `Unk0e651c_Get2Bits` | 32 B | Passes the current data block and both args to `Unk0e651c_Get2BitsIn`. |
| `Unk0e651c_TestBitChecked` | 32 B | Returns 0 for indices > 0x7FF; otherwise returns `Unk094fe0_TestBit(data, index)`. |
| `Unk0e651c_Unk_0e651c` | 48 B | Gets base `Unk0e5fb8_GetOffsetD80()` and writes bit 0 of its second argument to bit base+2 and bit 1 to bit base+3. The first argument is unused. |
| `Unk0e651c_Set2Bits` | 60 B | Ignores slots >= 32; otherwise writes `v & 1` and `(v & 2) >> 1` to bits `row*128 + 64 + slot*2` and the bit after it via `Unk094fe0_Unk_095204`. |
| `Unk0e651c_Get2BitsIn` | 68 B | Returns 0 for slots >= 32; otherwise reads the same two bits with `Unk094fe0_TestBit200` and returns them packed as a byte. |
| `func_020e6708` | 84 B | Ring buffer with 5 entries. It stores `(index, value)` at the cursor `data_02176cac` in `data_02176cb0[5]` / `data_02176cc4[5]`, then sets the cursor to `(cursor + 1) % 5`. The array size comes from the 0x14 gap between the two arrays and the modulo. Its only caller, `Unk094fe0_Unk_09502c`, passes the bit index and value it is writing, so this keeps a short history of recent bit writes. The name is kept neutral and unchanged, because renaming it would mean editing the caller's file, which this card does not own. |

Matching note for `func_020e6708`: a version that loads the cursor into a local and then
writes `(cur + 1) % 5` swaps r4/r5. Writing `data_02176cac++; data_02176cac %= 5;` directly on the
global gives the ROM's register order.

## Hard list

None. No M1-T146 or M1-T147 target is deferred.
