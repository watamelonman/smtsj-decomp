# game/unit_020fd268 — M1-T273

All eight card functions match the delinked ARM instructions at 100% objdiff.
The work view follows observed word accesses through offset 0x34; returned
pointers are borrowed. Neutral names remain where field semantics are unknown.

| Function | Original address | Observed behavior / evidence |
| --- | --- | --- |
| `Unk0fd268_Get_data_02176e1c` | `020fd4b4` | Loads and returns the singleton pointer from `data_02176e1c`. |
| `Unk0fd268_Unk_0fd3ac` | `020fd3ac` | Calls `func_02061424` with the singleton in r0 only when present; does not clear the global. |
| `Unk0fd268_Unk_0fd47c` | `020fd47c` | Conditionally stores zero at work offset 0x2c. |
| `Unk0fd268_GetField0` | `020fd364` | Reads the first signed word of the separate `data_02176e18` singleton, returning -1 if absent. |
| `Unk0fd268_Unk_0fd494` | `020fd494` | Conditionally stores the two supplied words at offsets 0x30 and 0x34. Caller `unit_0209a268` supplies -3 and 58; their broader meaning remains unknown. |
| `Unk0fd268_IsField8Zero` | `020fd428` | Returns false if absent, otherwise tests the word at offset 8 for zero. |
| `Unk0fd268_Unk_0fd380` | `020fd380` | If absent, forwards the supplied word to `func_020fd4c4` and stores its returned work pointer. Existing work is preserved. |
| `Unk0fd268_SetDir` | `020fd3c4` | Stores +3 for a nonzero flag or -3 for zero at offset 0x10, if present. The existing direction name agrees with these signed stores and the `ScanVisor` forwarding caller. |

## Validation

Baseline and updated C both match. Typed pointers and field accesses replace
integer address arithmetic without changing generated instructions. The objdiff
match gate covers the other existing C bodies in this TU as well.
No new runtime tests are required by this card; objdiff checks the exact code.

## Hard list

None for M1-T273. The existing additional C bodies remain in place;
`func_020fd268`, `func_020fd2fc`, and `func_020fd4c4` are outside this card
and remain supplied by the delinked original. No completion flag was changed.
