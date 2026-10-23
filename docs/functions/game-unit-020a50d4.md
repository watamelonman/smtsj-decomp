# game/unit_020a50d4

All seven functions match at 100% with the configured mwccarm 2.0/sp1p5 flags.
Evidence is the delinked ARM instructions and relocation targets for this unit.
Names without an established purpose remain neutral; state and layout field names
only describe their observed use. Context and map pointers are borrowed.

| Function | Size | Behavior and evidence |
| --- | ---: | --- |
| `Unk0a50d4_Unk_0a50d4` | 16 | Returns the word at global `data_02176b08 + 8`, evidenced by `ldr [r0,#8]`. Its broader meaning remains unknown. |
| `Unk0a50d4_GetUnk06` | 16 | Returns the signed global byte at +6 (`ldrsb`). |
| `Unk0a50d4_IsSubBrightnessMax` | 48 | Calls `func_02002954` with sub-screen MASTER_BRIGHT address `0x0400106c`, then tests for either +16 or -16. |
| `func_020a5124` | 876 | Updates the sequence selected by signed state +0x7481. Retrieves an entry using signed coordinates +0x7482/+0x7483. State 0 updates the current cell, sets the entry flag, and selects states 10 or 20 based on entry byte +25. States 10–12 process five four-byte id/count records, using (51,1) when no record qualifies. States 20–23 use the word at entry +20 and direction helpers. Returns 1 on completion or unknown states, otherwise 0. The caller must supply a valid entry and initialized state/index. |
| `func_020a5490` | 188 | Four-state sequence calling `func_02065bc0`, readiness helper `func_020654cc`, `func_0206597c(8)`, and completion helper `func_02065cd0` followed by `func_02065c58`. Returns 1 for completion or unknown states. |
| `func_020a554c` | 252 | Validates that the coordinate lookup is nonnull and type 3, then tests the flag indexed by entry byte +26. On an unset flag, initializes current-cell fields through the original helper calls, sets byte +1 to 1 and halfword +2 to 0, calls `Unk0a0ce4_Unk_0a0da4(42)`, and selects mode 0; otherwise selects mode 1. |
| `Unk0a50d4_Unk_0a5648` | 56 | Dispatches signed mode +0x7480 to `func_020a5124` (0) or `func_020a5490` (1), returning 1 for other modes. |

The context view preserves map storage beginning at +4 and state fields beginning
at +0x7480. The entry view preserves five signed-halfword/byte pairs with stride
4, followed by the word at +20 and the observed kind/flag bytes at +25/+26.
These views reproduce the original field loads without retaining addresses of
individual raw byte fields across helper calls.

## Hard list

None.
