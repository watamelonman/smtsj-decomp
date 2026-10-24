# game/unit_02071dc0 — M1-T328

All eight functions below match the delinked ARM object at 100% objdiff.
Offsets and calls cited here come from that object's disassembly. Neutral names
are retained because the higher-level resource lifecycle is not established.

| Function | Contract and evidence |
| --- | --- |
| `Unk071dc0_Unk_071dc0` | Calls `func_0205ad2c(data_021459b0)`, then `func_0205ad78(data_021458d8, 9)`. The two literal addresses and immediate count establish the context and fixed-record setup. |
| `Unk071dc0_Unk_071de4` | Runs the preceding setup, then calls `Unk05b82c_Unk_05b82c` with unsigned indices 0 through 8. |
| `Unk071dc0_Unk_071e08` | Calls `func_0205bb68` exactly nine times; the loop at 0x02071e10 supplies no arguments. |
| `Unk071dc0_Clear` | Clears 0x1608 bytes at `data_02170d14` using `func_02008848` with fill value zero. Those call arguments support the existing descriptive name. |
| `func_02071e44` | Returns a borrowed pointer to the first qualifying 24-byte record, or null. Searches nine records at `data_021458d8`, then the signed count at `data_02171d14 + 0x600` in `data_02170d14`. Each record must pass `func_0205b36c`; comparison through `func_020152cc` uses the pointer at record +0x14, offset by 0x2c, and the caller's name. The same comparison helper is used for name lookup in `game/unit_0206dddc`. Callers must supply a valid name; qualifying records must contain a valid object pointer. |
| `Unk071dc0_Unk_071fcc` | Stores mode 0 at `data_02171d14 + 0x604`; returns 1 at the first dynamic record with zero predicate result. Otherwise stores mode 4 and returns 0. Count is signed and reread after each call. |
| `Unk071dc0_GetMode604Sign` | Reads the word at +0x604 and maps 4 to 1, 5 to -1, and all other values to 0. These comparisons support the existing descriptive name. |
| `Unk071dc0_Unk_072200` | Calls `func_0205bb68` once per current dynamic count, rereading the signed count after each call, then invokes `Unk071dc0_Clear`. Nonpositive counts skip the loop. |

## Hard list

None for M1-T328. `func_02071efc` and `func_02072068` belong to M1-T329
and remain linked from the delinked original. The unit's completion flag remains
human-owned.
