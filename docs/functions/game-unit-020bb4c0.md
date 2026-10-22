# src/game/unit_020bb4c0.c

## M1-T104

All seven functions match at 100% in objdiff. Each takes no C parameters: script
arguments are read with `func_0203ac00(index)` and the result is published with
`Unk03aae8_Unk_03acf4`, after which the handler returns command status 1. The
symbol names stay as `func_020bb*` because they are the names in
`config/arm9/symbols.txt`.

Evidence comes from the delinked original's ARM instructions and call
relocations. The lookup records are borrowed; this unit never allocates or frees
them. `Unk0bb2b0_Thunk_020a1428` and `Unk0bb2b0_Thunk_020a1740` are the
interworking thunks defined by the preceding TU's `src/game/unit_020bb2b0.c`.

| Function | Observed behavior and evidence |
| --- | --- |
| `func_020bb4c0` | Reads argument 0 (`mov r0,#0` before `bl func_0203ac00`), truncates it to 16 bits (`lsl #16` / `lsr #16`), looks it up with the 0x020a1428 thunk, and publishes unsigned byte +0x62 (`ldrb [r0,#0x62]`) plus 205 (`add #0xcd`). |
| `func_020bb4ec` | Same argument-0 lookup, but publishes unsigned byte +0x63 (`ldrb [r0,#0x63]`) plus 205. |
| `func_020bb518` | Same argument-0 lookup, but publishes unsigned byte +0x02 (`ldrb [r0,#2]`). |
| `func_020bb540` | Same argument-0 lookup through the 0x020a1740 thunk, then publishes the word at +0x60 (`ldr [r0,#0x60]`). |
| `func_020bb568` | Passes the truncated argument-0 id to `Unk0a163c_Unk_0a17d8` and publishes 1 when the result is nonzero, otherwise 0 (`cmp r0,#0` / `beq`). |
| `func_020bb5a4` | Walks three 6-byte entries at record +0x48 (`add r4,r0,#72`, `add ip,ip,#6`). An entry counts when its halfword +0x00 is nonzero and halfword +0x04 is zero (`ldrh` / `cmp` pairs). The first loop records the last counting key and adds the first entry's +0x02 halfword on every match (`ldrheq [r4,#2]`, with `r4` fixed at the table base). With a zero total it publishes -1 (`mvn r0,#0`). Otherwise it takes `func_02050074(0, total)`, subtracts each counting entry's +0x02 halfword, and publishes the key of the first entry whose running value becomes non-positive (`sub` / `cmp #0` / `bgt`). |
| `func_020bb67c` | Same three-entry walk, but keeps the smallest +0x02 halfword among counting entries and publishes that entry's +0x00 key (`cmp r1,ip` / `movcc` twice). Starts with key -1 and limit 100, so a table with no counting entry publishes -1. |

`func_020bb5a4`'s first loop uses the first entry's +0x02 field for the running
total on every qualifying entry; that is what the fixed-base `[r4,#2]` load in
the original does. The second loop reads per-entry +0x02 fields. The field
meaning is not established, so the comments describe the observed weights only.

## Hard list

None.
