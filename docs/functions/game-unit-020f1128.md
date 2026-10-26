# game/unit_020f1128 — M1-T876

All eight requested functions match at 100% with the configured mwccarm compiler.
Names are retained from the symbol configuration; behavior below is grounded in
original ARM instructions rather than inferred game semantics. The TU remains
linked from its delinked object until a human marks it complete.

| Function | Size | Instruction evidence and contract |
| --- | ---: | --- |
| `Unk0f1128_Nop_0f21ac` | 4 | Bare return; intentionally empty callback. |
| `Unk0f1128_Unk_0f2d60` | 32 | Copies its word argument to a local and passes its address to `Unk0bd5f0_Unk_0c7f70(7, 0, ..., 1)`. Callee must consume the local synchronously. Taking the parameter address instead creates a different stack frame. |
| `Unk0f1128_Unk_0f2d30` | 48 | Adds 200 to argument 1 and passes a pointer to that local to `CampStatus_Unk_0dde3c` with command pair 12/23 and count 1. Arguments 2 and 3 are unused. |
| `func_020f1490` | 92 | Writes descriptor size 0x500, zero flags and six callback addresses at +0x0c through +0x20; preserves +0x08. Callback slots retain the original symbol addresses. |
| `func_020f2e1c` | 92 | Reads count at +0x28 and halfword ids from twelve-byte records starting +0x2c. Looks up each id, conditionally forwards the returned entry after the predicate call, then stores the final helper result at byte +0x24. |
| `func_020f2bfc` | 148 | Conditionally releases +0/+4, unconditionally releases two handles at +0x4dc/+0x4e0, and clears those slots. Calls the release helper on +8/+0x0c even for null handles, then conditionally clears them. |
| `func_020f2d80` | 156 | If +0x4f0 is nonzero, calls three helpers and writes state 12 at +0x4e4. Otherwise clears two bytes and sixteen words of a local control structure, submits it for indices 1 then 0, and forwards `(work, 1)`. The two alignment bytes are not initialized or interpreted here. |
| `func_020f2c90` | 160 | Calls setup, obtains context `(6, 0)`, and processes rows from signed +0x20 while the unsigned count bound and signed start-plus-18 bound allow. Submits only the final result, when nonnull, using handle +8 and arguments -1/0/0. Count/start are reread after calls as in the original. |

The work view names only fields used here. The fixed hundred-row extent follows
from the interval +0x2c..+0x4dc and twelve-byte stride; callers must supply valid
row bounds and a full work allocation. The callback descriptor and control views
are local to this TU; no module boundary changes were required.

## Hard list

None for M1-T876. Other functions in this translation unit are outside this card.
