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

## M1-T444 matches

All eight requested functions are 100% in the generated objdiff report.
The two pre-existing matches were retained; six new C definitions were added.
Offsets and callback identities below come from the original ARM instructions.

| Function | Size | Behavior and contract evidence |
| --- | ---: | --- |
| `Unk0ef248_Unk_0ef2ec` | 68 | Clamps signed percentages below zero to 0.0 and above 100 to 1.0; otherwise divides the float conversion by 100. Caller supplies one writable float. |
| `Unk0ef248_Unk_0ef6fc` | 80 | Initializes embedded work at +0x50 using the query of +0x44, invokes `func_020ef8d0`, selects mode 3 for unsigned counts >=6 or mode 2 otherwise, and clears the six +0xf4 words. Requires the full writable work block. |
| `func_020ef248` | 88 | Writes size 0x10c, kind 4, and callback addresses into a borrowed descriptor at +0xc through +0x20, retaining +8. Callback field types reflect the corresponding C entry points. |
| `func_020ef8d0` | 136 | Gets embedded start/count fields and clamps count against the unsigned global entry count; forwards each indexed entry to `func_020ea208`. In published states 9 and 10, forwards the selected entry through `Unk09974c_Unk_099bd4` and `Unk0fedd4_Unk_0fee38`. |
| `func_020ef4b8` | 144 | Calls `func_020f7188`, updates ramps unless state +8 is 1, then handles states 11 (submit +0x40 with zero), 2 (set state 1), and 9 (update embedded work and set state 10). Other states return. |
| `func_020ef330` | 192 | If +0x10 is zero, fills six floats at +0xf4 with 1.0. Otherwise computes signed `(+0x18 - +0x10) * 300 / +0x18` and applies clamped ramps at thresholds 250/180/120/70/30/0. The caller must provide a nonzero +0x18 divisor on this path and values whose signed arithmetic is representable. |
| `func_020ef3f0` | 196 | Stores 32, 8, 0, 0 at +0x40..+0x4c, configures the outer work with the observed scalar arguments and +0xef6fc callback, then registers predicate/selection/submission/entry callbacks for embedded work +0x50 and installs +0xef8d0 as its final callback. Requires writable storage through +0x10b. |
| `func_020ef78c` | 236 | Snapshots published work, queries the borrowed record, submits its +0x22 halfword, and clears the query mode. A zero halfword branches on bit 7 at +0x2a and the kind predicate to select callbacks using work +0x40; a nonzero halfword is converted by `func_020cb1a0` and submitted with the saved work. The byte bitfield models the original shift/extract access. |

No broader gameplay names are inferred. The descriptor and record prefix views
are private to this translation unit; providers retain ownership.

## Hard list

None for M1-T443 or M1-T444. `func_020ef578` belongs to the remaining
neighboring work and stays linked from the original delinked object.
No assembly, instruction blobs, or new tests were needed; objdiff checks the
complete emitted instruction sequences and relocations.
