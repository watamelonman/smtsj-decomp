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

## M1-T509

Seven card functions match at 100%; the remaining function stays in the delink.
All pointers below borrow valid work storage.

| Function | Evidence and contract |
| --- | --- |
| `Unk0fd9f0_Unk_0fdb80` | 020fdb80 initializes +0x0c to -27, +0x14/+0x28/+0x2c to 1 and +0x24/+0x30 through +0x40 to zero. |
| `Unk0fd9f0_Unk_0fe278` | 020fe278 calls five subsystem setters with 31, -1, (2,48,10), 2 and 4 in that order. |
| `Unk0fd9f0_Update` | 020fde0c dispatches +0x2c: state 1 calls 020fde4c then 020fe004; state 2 calls 020fe1f8; others do nothing. |
| `Unk0fd9f0_Unk_0fda58` | 020fda58 ignores an absent singleton. State 1 stores the argument at +0x28; state 2 sets +0x34/+0x38 to 1, resets direction and releases +0x24. |
| `Unk0fd9f0_LoadBattleHelpTalk` | 020fdbb8 acquires IDs 0xd5/0xd6 and loads resource paths data_021510b8/cc/e0 into +0/+0x1c/+0x20. Battle/battle_help and battle_talk strings support the existing name. |
| `func_020fdb14` | Allocates 0x44 bytes through 020611dc with callbacks 020fdd90, Update and 020fdc18, group 3 and flags 0/1; returns zero on failure, otherwise initializes fields and resources. |
| `Unk0fd9f0_Unk_0fdc18` | Releases +0x24, then nonzero handles +0x20/+0/+0x1c, clearing each; calls 0205bb68 twice and clears the singleton. |
| `func_020fdaa8` | Unmatched: stores the second argument at +0x40; state 1 writes 1 at +0x28/+0x34, 2 at +0x38, the first argument at +0x30, then resets direction; state 2 writes only +0x30. |

### Hard list for M1-T509

- `func_020fdaa8`: readable switch implementations using struct fields and offset views,
  signed/unsigned state, case ordering, explicit defaults, and break/return forms
  produce an 84-byte function rather than the original 92 bytes. The compiler
  predicates the state-2 store instead of branching to a separate store/return block.
  No nonmatching definition retained; a human can investigate in decomp.me.

## Not done in M1-T510
- `func_020fe2c4`
- `func_020fdd90`
- `func_020fe1f8`
- `func_020fdc88`
- `func_020fde4c`
- `func_020fe004`
