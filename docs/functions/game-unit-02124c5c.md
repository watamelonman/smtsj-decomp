# src/game/unit_02124c5c.c

## M1-T050

All eight functions below match the delinked ARM object at 100% in objdiff.
Evidence is the instruction sequence and relocations in
`build/delinks/src/game/unit_02124c5c.o`. Neutral names are retained where the
higher-level purpose is unknown. The partial work layout models the observed
word accesses and signed byte at +8; the remaining three bytes are padding.

| Function | Observed behavior and contract |
| --- | --- |
| `Unk124c5c_Thunk_02124e9c` | No-argument forwarding thunk; literal relocation targets `func_02124e9c`. |
| `Unk124c5c_Unk_124cb0` | Calls `func_02124c5c()`, then `func_02124ce8(2)` in that order. |
| `Unk124c5c_Unk_124cc4` | Calls `func_020e7f44` with four zero words, then `func_02124ce8(2)`. |
| `Unk124c5c_Unk_124d54` | Forwards the pointer in `data_02176e88` to `func_02061424`, without a null check. No ownership claim is inferred. |
| `Unk124c5c_Set_124d6c` | If work exists, stores the two arguments as words at +0x0c and +0x10. The STR offsets support the existing setter name. |
| `Unk124c5c_Set_124d8c` | If work exists, stores a word at +4 and the low byte of the second argument at +8. STR/STRB support the existing setter name. |
| `Unk124c5c_IsKind0` | Returns 1 exactly when work exists and its signed byte at +8 is zero; otherwise 0. LDRSB and comparison with zero support the existing name. |
| `Unk124c5c_Unk_124e50` | If work exists, stores its word argument at +0x14. |

## M1-T051

All four task functions match at 100% in objdiff; the full unit now has twelve
matching C functions. Evidence is the ARM instructions and relocations in
`build/delinks/src/game/unit_02124c5c.o`, checked against the compiled object.

| Function | Observed behavior and contract |
| --- | --- |
| `Unk124c5c_IsKind31` | Existing implementation verified: returns 1 exactly when work exists and signed byte +8 equals 31, otherwise 0. The LDRSB/CMP supports the existing name. |
| `Unk124c5c_Unk_124e04` | Existing implementation verified: null work returns 1; word +4 selects `IsKind0` for 0 and `IsKind31` for 1; other values return 1. |
| `func_02124c5c` | Starts with arguments 13, 7, 10. Calls `Unk0d297c_Unk_0d3138`, `Unk0e651c_Unk_0e666c(0x705)`, and `Unk0cb32c_Unk_0cb7f0` in order, clearing the first, third, and second arguments respectively when the corresponding result is zero. Passes those arguments and a fourth zero to `func_020e7f44`. Higher-level meanings remain unknown. |
| `func_02124ce8` | Builds a stack payload: clears two flag bytes and sixteen words at +4, sets flag bit 1, stores the input at +8, then calls `func_020bcbc4(10, &payload)`. Padding bytes +2/+3 are untouched, as in the original. The local payload type models only this observed layout. |

Validation: standalone instruction/relocation comparisons for both newly added
bodies, objdiff for all twelve C functions, nine repository unit tests,
anticheat, and full-image checksum all pass. No new tests are required by the
card; binary comparison supplies the behavior equivalence check.

## Hard list

None. All M1-T050 and M1-T051 functions match.
