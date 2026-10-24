# game/unit_0206dddc

## M1-T338: eight matching accessors

All eight functions are 100% in the objdiff report. Evidence is the ARM code
and data relocations in `build/delinks/src/game/unit_0206dddc.o`.
Record and subrecord meanings are unproven, so neutral names are retained.
Indices must be valid; returned pointers borrow the table storage.

| Function | Address | Observed contract and evidence |
| --- | --- | --- |
| `Unk06dddc_Get_data_0216bac4` | 0x0206dfa0 | Loads and returns the count word at `data_0216bac4`. |
| `Unk06dddc_Unk_06e058` | 0x0206e058 | Returns `data_0216bac8 + index * 328`, using multiply-add. |
| `Unk06dddc_Unk_06dfb0` | 0x0206dfb0 | Loads a word from `data_0216baf0 + index * 328`, record offset +0x28. |
| `Unk06dddc_Unk_06e0c4` | 0x0206e0c4 | Calls the record accessor and conditionally adds one to its returned pointer; returns null unchanged. |
| `Unk06dddc_Unk_06dfc8` | 0x0206dfc8 | Loads the pointer from `data_0216bc04 + index * 328`, then sign-extends the halfword at subindex * 20 + 4. |
| `Unk06dddc_Unk_06dfec` | 0x0206dfec | Uses the same pointer and returns the word at subindex * 20. |
| `Unk06dddc_Unk_06e010` | 0x0206e010 | Uses the same pointer and returns borrowed bytes at subindex * 20 + 8. |
| `Unk06dddc_Unk_06e034` | 0x0206e034 | Uses the same pointer and sign-extends the halfword at subindex * 20 + 6. |

`data_0216bc04` is +0x13c relative to the record base. Pointer arithmetic
preserves the original byte strides without assigning speculative field meanings.

Hard list for M1-T338: none.

## Not done in M1-T339
- `Unk06dddc_Unk_06dee8`
- `Unk06dddc_GetEntryUnk24`
- `Unk06dddc_Unk_06e06c`
- `func_0206de10`
- `func_0206de7c`
- `func_0206df10`
- `func_0206e0dc`
- `Unk06dddc_Unk_06dee8`: decompiler-derived (plain cleanup)
- `Unk06dddc_GetEntryUnk24`: hand-matched
- `Unk06dddc_Unk_06e06c`: hand-matched
