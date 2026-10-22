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

## Existing M1-T051 bodies

These existing definitions remain at 100%; they were not newly implemented here.

- `Unk124c5c_IsKind31`: tests the signed byte at +8 against 31, returning false for null work.
- `Unk124c5c_Unk_124e04`: dispatches on word +4: 0 selects `IsKind0`, 1 selects `IsKind31`; absent work and other values return 1.
- `func_02124c5c` and `func_02124ce8`: external declarations only; original implementations remain in the delink.

## Hard list

None for M1-T050. No unmatched implementation was added.
