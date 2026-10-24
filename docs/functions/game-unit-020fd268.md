# game/unit_020fd268 — M1-T273, M1-T274

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
| `Unk0fd268_IsField8Neg81` | `020fd450` | Returns false if absent, otherwise tests the word at offset 8 for -81 (the value `Unk0fd268_Unk_0fd540` stores). |
| `Unk0fd268_Unk_0fd574` | `020fd574` | Calls `Unk05b82c_Unk_05b82c(13)` and `(14)`, then stores `func_0205dcd4(data_021510a4, 1)` in work word 0. |
| `Unk0fd268_Unk_0fd540` | `020fd540` | Initialises a new work: word 8 = -81, word 0x1c = arg1, word 0x2c = 1, words 0xc/0x10/0x24/0x28/0x30/0x34 = 0. |
| `Unk0fd268_Unk_0fd3f0` | `020fd3f0` | If the singleton exists: a nonzero flag clears word 8; zero sets word 8 to -81 and clears word 0x10. |
| `func_020fd2fc` | `020fd2fc` | When byte 0xa of its `Unk0fd268Fade` object is set, runs one `func_02057xxx` draw sequence with word 4 as an argument and a 0,0,256,192 rectangle (the DS screen size). |
| `func_020fd4c4` | `020fd4c4` | Creates a 0x38-byte work through `func_020611dc` with four callbacks from unit_020fd5a4 (args 3, 0, 1), returns 0 on failure, otherwise initialises it with `Unk_0fd540(work, arg0)` and `Unk_0fd574` and returns it. `Unk0fd268_Unk_0fd380` stores the result in `data_02176e1c`. |
| `func_020fd268` | `020fd268` | Byte state machine at offset 0xc. State 0 counts byte 8 up to byte 9, then resets it and toggles byte 0xa, decrementing byte 0xb when the toggle reaches 0; when 0xa and 0xb are both 0 it advances to state 1. State 1 releases the object with `func_02061424` and clears `data_02176e18`. |

## Validation

Baseline and updated C both match. Typed pointers and field accesses replace
integer address arithmetic without changing generated instructions. The objdiff
match gate covers the other existing C bodies in this TU as well.
No new runtime tests are required by this card; objdiff checks the exact code.

## Hard list

None. M1-T274 matched the last three functions, so all 15 functions in the TU are now
C at 100%. `func_020fd268` needed an `int` temporary for the next counter value: with a `u8`
temporary mwcc emits an extra `and r1, r1, #255`. `func_020fd268`/`func_020fd2fc` take a
separate `Unk0fd268Fade` layout (byte fields at 8..0xc) because they use byte accesses where
`Unk0fd268Work` has a word at offset 8. No completion flag was changed.
