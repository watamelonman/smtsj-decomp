# game/unit_0211fc20

All eight card functions are implemented in ARM C. Layouts describe only the
accessed fields; unknown fields retain neutral names. Evidence is the delinked
ARM instruction stream at the function addresses below. The global pointer is
external, so its storage remains owned by the original image.

| Function | Evidence and contract |
| --- | --- |
| `Unk11fc20_Unk_11fc20` | 0211fc20: null-checks `data_02176e7c`, calls 0211fcb0 and stores the result. |
| `Unk11fc20_Unk_11fc48` | 0211fc48: calls 02061424 only for non-null global work. |
| `Unk11fc20_IsState4` | 0211fc68: returns true for absent work or first word equal to 4. |
| `Unk11fc20_Unk_11fc94` | 0211fc94: returns work offset 16, or zero if absent. |
| `Unk11fc20_Clear_data_02176e7c` | 0211fd24: stores zero to the global pointer without a release call. |
| `Unk11fc20_Unk_120650` | 02120650: subtracts 4096 from signed offset 40 and returns whether it is at most 8192. Requires valid work. |
| `Unk11fc20_Unk_12066c` | 0212066c: calls 020a0da4 with 3, clears offset 64, subtracts 4096 from offset 68; at most 4096 clears offset 28 and returns 1, otherwise sets offset 24 to 15 and returns 0. Requires valid work. |
| `Unk11fc20_Unk_120944` | 02120944: counts nonzero words at offset 424 with stride 44 over 32 entries. Requires valid work. |

No module boundary changes. Existing C helpers outside this card are retained. Remaining undefined functions
in this delink unit remain supplied by the original object, per the task card.

## Hard list

None.
