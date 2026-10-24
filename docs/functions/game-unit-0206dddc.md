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

## M1-T339: seven matching table operations

All seven functions match at 100% in objdiff against the delinked ARM object.
Names remain neutral where record semantics are unknown. The typed layouts
encode only offsets and strides observed in that object.

| Function | Address | Observed contract and evidence |
| --- | --- | --- |
| `Unk06dddc_Unk_06dee8` | 0x0206dee8 | Copies 0x90 bytes to record +0x2c, six slots of 24 bytes. |
| `Unk06dddc_GetEntryUnk24` | 0x0206dddc | Returns the borrowed entry pointer at +0x24, or null when count - 1 - index is negative. Negative indices are not separately rejected. |
| `func_0206de10` | 0x0206de10 | Rejects counts above 16; positive counts allocate and copy count * 552 bytes to +0x24; accepted counts are stored at +0x20. Existing allocations are not freed. |
| `func_0206de7c` | 0x0206de7c | Corresponding operation for up to 64 subentries of 20 bytes, pointer +0x13c and count +0x28. |
| `func_0206df10` | 0x0206df10 | Frees both arrays in each counted record, clears their fields, then clears 0x5200 bytes and the table count. |
| `Unk06dddc_Unk_06e06c` | 0x0206e06c | Searches record bytes at +1 using func_020152cc; returns the first index narrowed to a byte, or 255. |
| `func_0206e0dc` | 0x0206e0dc | Takes the maximum over six unsigned slot words at +0x30, signed subentry calculations, and four unsigned func_020943dc results. Each subentry selects a 552-byte entry; selector +0x224 chooses the low signed halfword of +0xfc (0) or +0x16c (1–3), otherwise zero. Calculation is base + max(multiplier, 1) * value. Returns zero for count - 1 - index < 0. |

The two copy setters and slot copy require valid record indices and readable
source buffers. The maximum calculation requires valid referenced entry indices.
The source preserves the original mixed signed/unsigned comparisons and repeated
external calls; no additional bounds policy is inferred.

Hard list for M1-T339: none.
