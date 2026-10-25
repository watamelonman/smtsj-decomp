# src/game/unit_020ff030.c

All eight M1-T613 functions match the delinked ARM object at 100% with the
configured mwccarm 2.0/sp1p5 flags. Names remain neutral because the call
sequence and field accesses do not establish a higher-level purpose.

| Function | Observed contract and evidence |
| --- | --- |
| `Unk0ff030_Nop_0ff030` | Empty callback; original is a return instruction. |
| `func_020ff034` | Requires nonzero state at +0x14; state 2 consumes +0x20. Calls the setup helper, submits two operations with the observed offsets and order, then calls the finish helper. |
| `Unk0ff030_Unk_0ff0ec` | Sets call state to 31, -1, and 4; applies the signed +0x18 value only if nonnegative. |
| `func_020ff120` | Sends -1 to func_02057eb8 when +0x18 is nonnegative, then calls func_020572d8. |
| `func_020ff248` | Writes size 64, zero flags, and callback pointers identified by the original relocations. Leaves +0x08 untouched. |
| `func_020ff5c0` | Only processes state 4 when func_02052728 returns zero. Updates three counters through CampStatus_Unk_0dd308; adopts +0x28 as state when +0x30 <= 0 and both other counters >= 10. |
| `Unk0ff030_Unk_0ffa60` | Releases nonzero +0x00 and clears it; always passes +0x04 to func_020629c4 and then clears it if nonzero. |
| `func_020ffbcc` | Copies four halfwords from Unk02e000_Thunk_0202e788 into local words, replaces zeros with ones, and passes the array with count four to CampStatus_Unk_0dde3c. |

The work structure records observed word offsets, without assigning speculative
field meanings. External callbacks remain linked from the delinked original.
The message callback accepts a borrowed message pointer, as evidenced by the
original loads through r1; its payload layout is outside this card.

## Hard list

None for M1-T613.

## Outside this card (M1-T614)

- `func_020ffc44`
- `func_020ff140`
- `func_020ffa9c`
- `func_020ff29c`
- `func_020ff638`
