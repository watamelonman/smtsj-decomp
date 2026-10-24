# game/unit_020ef248

M1-T443: all eight requested functions match at 100% in the objdiff report.
Evidence below refers to the original ARM instructions at the listed addresses.
Work pointers are borrowed; initialization requires writable storage of at least
0x10c bytes. Global callbacks require `data_02176df0` to have been initialized.
Neutral names remain because the broader gameplay purpose is unproven.

| Function | Size | Behavior and evidence |
| --- | ---: | --- |
| `Unk0ef248_Nop_0ef4b4` | 4 | Bare return at 0x020ef4b4; intentionally empty callback. |
| `Unk0ef248_Thunk_020f7248` | 12 | At 0x020ef6f0, loads the address of `func_020f7248` and branches to it. No arguments are consumed. |
| `Unk0ef248_ClearArrF4` | 32 | At 0x020ef2cc, loops over six words, storing zero at work +0xf4 + index * 4. This directly supports the existing descriptive name. |
| `Unk0ef248_Unk_0ef8ac` | 36 | Passes its input object to `Unk0f8448_GetUnkField10`, then forwards the result with the published work's +0x44 word to `Unk0e8228_Unk_0e8d90`. The global is read after the getter call. |
| `Unk0ef248_Unk_0ef2a0` | 44 | Calls `func_02008848(work, 0, 0x10c)`, publishes the pointer, then calls `func_020ef3f0(work)`. |
| `Unk0ef248_Unk_0ef548` | 48 | Returns if `Unk0f7188_Unk_0f7210` is zero; otherwise updates work +0x50 through `func_020f82e0`, then calls `Unk0fedd4_SetState2` only if the signed word at +8 equals 10. |
| `Unk0ef248_Unk_0ef878` | 52 | Snapshots the global work pointer, calls `Unk0e8228_Unk_0e8c80` and `func_02044ec4`, then submits +4 to `func_020f7d14` and (+0x40, 0, 1) to `func_020f7e48`. |
| `Unk0ef248_Unk_0ef74c` | 64 | Short-circuits two predicates. If either is nonzero, queries `Unk0e8228_Unk_0e8fe4(Unk0e8228_GetArr88Field20(index))`; returns zero only when that query equals one, otherwise one. |

## Existing neighboring matches

`Unk0ef248_Unk_0ef2ec` and `Unk0ef248_Unk_0ef6fc` were already present
and remain at 100%. They clamp a percentage and initialize embedded work,
respectively. Other functions in this translation unit remain delinked.

## Hard list

None for M1-T443. No assembly, instruction blobs, or new tests were needed;
objdiff checks the complete emitted instruction sequences and relocations.
