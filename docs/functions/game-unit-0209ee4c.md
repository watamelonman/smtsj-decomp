# src/game/unit_0209ee4c.c

## M1-T766

All eight functions match at 100% objdiff. Evidence below is the target ARM
instruction sequence at the address encoded in each symbol (accessor: 0x0209eff8;
thunk: 0x0209f028; call wrappers: 0x0209f0c0 and 0x0209f534).
Existing symbol names are retained; unknown state transitions are not assigned
speculative gameplay meanings.

| Function | Contract and evidence |
| --- | --- |
| `Unk09ee4c_Thunk_02118c6c` | Tail-calls `func_02118c6c`; target loads its address into ip and branches through ip. No arguments. |
| `Unk09ee4c_Unk_0a03b8` | Returns `data_0213c190 + index * 24` as a target-width integer address; target literal and MLA establish base and stride. Index validity belongs to the caller. |
| `Unk09ee4c_Call_0204f1f8` | Adds unsigned byte d[1] to base, clamps a negative sum to zero, and forwards all four arguments. Target LDRB, ADDS and MOVMI establish this behavior. d requires two readable bytes. |
| `Unk09ee4c_Call_0204f68c` | Calls the helper with the address of object word +0x64 only if that word is nonzero. Object must be valid; helper can mutate the word. Target LDR, conditional return and ADD establish the contract. |
| `Unk09ee4c_Unk_09ef50` | If state exists, calls `ScanVisor_Unk_0a2ae8(arg0, 2)` then sets state +0x73e8 to 0x14. Target BL and STR provide the evidence. |
| `Unk09ee4c_GetField3c0Bits` | Returns bits 10..19 of state word +0x73c0, or zero without state. Target shifts left 12 then right 22 and narrows to u16. The typed local view records only this observed word. |
| `Unk09ee4c_Unk_09ee4c` | If state exists, clears +0x7400, sets root word +0x5c to 1, then sets state +0x73e8 to 0x12. Target stores establish the ordering; live state requires a valid root. |
| `Unk09ee4c_Unk_09ef80` | If state exists, calls `Unk11f2d0_Unk_11f308` on embedded object +0x7598 with arg0, then sets +0x73e8 to 0x15. Target address additions, BL and STR establish the behavior. |

### Hard list

None for M1-T766.

## Not done in M1-T767
- `Unk09ee4c_Unk_09efb4`
- `func_0209f298`
- `Unk09ee4c_Unk_09f5d8`
- `Unk09ee4c_Unk_09fd14`
- `func_0209f550`
- `func_0209f034`
- `func_0209f480`
- `func_0209ee80`
- `Unk09ee4c_Unk_09efb4`: hand-matched
- `Unk09ee4c_Unk_09f5d8`: hand-matched
- `Unk09ee4c_Unk_09fd14`: hand-matched
