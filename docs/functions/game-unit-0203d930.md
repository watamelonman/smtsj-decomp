# game/unit_0203d930

All seven functions match the original ARM instructions, including call relocations.
Names remain neutral because the instruction evidence establishes control flow and
field access, but does not establish the operations' game-facing meanings.
The local struct views describe borrowed storage; they neither allocate nor own it.
No module boundary changes were needed.

| Function | Evidence and contract |
| --- | --- |
| `Unk03d930_Unk_03d930` | Reads manager word `0x3bc`; zero returns 0. Otherwise calls `Unk09ee4c_Unk_09ef80(90)`, writes 15 to the work word `0x18`, and returns 3. Manager and work pointers must be valid. |
| `Unk03d930_Unk_03d968` | Reads command argument 0, sign-extends its low 16 bits into `Unk09d42c_Unk_09e2a4`, writes work word `0x18` to 15, and returns 3. |
| `Unk03d930_Unk_03d998` | Forwards argument 0 to two operations. Calls `func_02065c10` only when `func_02065544` returns zero; forwards the result of the call with 1 alongside -1. Writes 30 through the previously fetched work pointer, calls the helpers with 1 and 40, and returns 3. |
| `Unk03d930_Unk_03da00` | Calls `Unk02dcfc_SetField64` with no arguments and returns 3. The field description comes from the existing callee symbol. |
| `Unk03d930_Unk_03da10` | Narrows argument 0 to signed 16 bits and argument 1 to unsigned 8 bits before `func_020d2b98`. Uses 24 for the result-producing helper, then fetches the current work pointer to write 30. Remaining calls follow the same guarded sequence as `03d998`. Returns 3. |
| `func_0203da90` | Fetches the work pointer twice. Signed byte `0x5c` selects start (0), poll (1), or completion (other). Start increments the byte and returns 0; an unfinished poll returns 0. A finished poll retrieves a result and destroys its operation. Completion calls `Unk0fc584_SetDir(0)`, clears the byte, forwards the result (zero on an unknown phase), and returns 3. |
| `func_0203db2c` | Fetches the work pointer twice. Phase 0 calls the argument-selected helpers and increments byte `0x5c`; phase 1 updates and polls, destroying the operation when ready. Start and unfinished poll return 0. Completion, including other phase values, calls `Unk0fc584_SetDir(0)`, clears the phase, and returns 3. |

## Validation

Direct compiler-to-ROM instruction comparisons pass for all seven functions.
The objdiff gate checks their full object matches; checksum validates the image
while this unit remains linked from its delinked object, as required by the card.
Tests are not added for this instruction-matching task (`tests_required = false`).

## Hard list

None.
