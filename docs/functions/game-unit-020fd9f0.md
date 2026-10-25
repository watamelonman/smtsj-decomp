# game/unit_020fd9f0 — M1-T508

All eight card functions match the delinked ARM object at 100%. Evidence below
refers to `build/delinks/src/game/unit_020fd9f0.o`; addresses are ARM9 addresses.
The pre-existing C bodies already matched; this task makes their argument flow
explicit and documents the observed contracts. Unknown semantic roles retain
neutral names. Work pointers are borrowed and must be valid.

| Function | Evidence and contract |
| --- | --- |
| `Unk0fd9f0_Unk_0fdc0c` | 020fdc0c stores all-one bits at work +0x14. No other fields change. |
| `Unk0fd9f0_Get_data_02176e20` | 020fdb04 loads the word at data_02176e20. Returns the singleton address as a 32-bit value, or zero when absent. |
| `Unk0fd9f0_Unk_0fe2b0` | 020fe2b0 calls 02057eb8 with -1, then 020572d8. The subsystem meaning is unconfirmed. |
| `Unk0fd9f0_Unk_0fda14` | 020fda14 reads the singleton and forwards its nonzero address to 02061424. The null case does nothing. |
| `Unk0fd9f0_Unk_0fd9f0` | 020fd9f0 checks the singleton; only when absent, calls 020fdb14 and stores its result at data_02176e20. |
| `Unk0fd9f0_Unk_0fe33c` | 020fe33c loads work +0x24, forwards the nonzero handle to 02061424, then clears the field. Repeated calls with a cleared field do nothing. |
| `Unk0fd9f0_SetDir` | Existing symbol; 020fda28 writes +1 to singleton +0x14 for a nonzero flag, otherwise -1. An absent singleton is ignored. |
| `Unk0fd9f0_GetColor` | Existing symbol; 020fe1c8 selects 0x00ff0000 for 1, 0xff000000 for 2, otherwise 0x299ce700. At 020fe300 the result is passed to Unk065e88_SetUnkField28, supporting the color interpretation. |

No new runtime tests are required by this card. Exact object comparison checks
instruction selection and relocations; checksum verifies the image still linked
from the delinked TU. No module boundary changes are introduced.

## Hard list

None for M1-T508.

## Other existing C outside M1-T508

- `Unk0fd9f0_Unk_0fdb80`
- `Unk0fd9f0_Unk_0fe278`

## Not done in M1-T509
- `Unk0fd9f0_Update`
- `Unk0fd9f0_Unk_0fda58`
- `Unk0fd9f0_LoadBattleHelpTalk`
- `func_020fdaa8`
- `func_020fdb14`
- `Unk0fd9f0_Unk_0fdc18`

## Not done in M1-T510
- `func_020fe2c4`
- `func_020fdd90`
- `func_020fe1f8`
- `func_020fdc88`
- `func_020fde4c`
- `func_020fe004`
