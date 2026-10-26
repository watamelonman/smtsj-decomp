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

## M1-T614

Four additional functions match at 100% with mwccarm 2.0/sp1p5. Existing
symbol names are retained; no higher-level naming claim is made.

| Function | Observed contract and evidence |
| --- | --- |
| `func_020ffc44` | Requires selection +0x10 minus +8 in 0..3. Selects the corresponding halfword from `Unk02e000_Thunk_0202e788`; zero returns immediately. Reads entry byte +2 and packed bits 10..19 of +4, then submits the selected word through `Unk0bd5f0_Unk_0c7f70`. The byte range 3..4 selects `Unk09974c_Unk_099cc4` instead of the packed field. Evidence: 020ffc54..020ffd08. |
| `func_020ff140` | Initializes state 4, next state 11, byte +0x2c, counters and latch; allocates two handles; initializes the selection prefix at +8 with arguments 4,4,1; sends optional words 2 and 3 as 1 and 2, and submits the initial selection. Evidence: stores and call arguments at 020ff140..020ff238. The presence bytes and sixteen words are initialized, but alignment padding is untouched. |
| `func_020ff29c` | Processes only state 11. A selection change sets +0x3c and refreshes the selected entry and index. The latch waits for masks 64,128,32,16. When the shared state permits input, masks 1,2,2048 dispatch the original slot messages and transitions. Evidence: 020ff29c..020ff5b0 and the four range pairs 211..260 through 361..410. |
| `func_020ff638` | Submits resource indices 39,40,42,41,45, four labels at 13-unit row spacing, and optional value rows for nonzero halfwords. States 7 and 11 draw resource 43 at the selected row; state 11 also uses the shared word at data_0215f05c+0x18 for drawing state. Evidence: 020ff638..020ffa54. The draw alpha reads the raw floating-point view of work +0x38, without a numeric integer conversion. |
| `func_020ffa9c` | **Unmatched, left in the delink.** Dispatches kinds 0..4. Kind 0 sends optional word 1 to slot 3; kind 1 forwards work and zero; kind 2 sets state 7; kind 3 sets state 11 and refreshes selection; kind 4 reads optional word 7, refreshing the four-word display for value 1 or the selected index for value 2. Evidence: jump table 020ffac4 and presence check 020ffb68..020ffb80. |

## Hard list

- `func_020ffa9c` (304 bytes): reconstructed all five switch cases and the
  optional-word reader. Tried pointer and integer command cursors, direct and
  inline cursor readers, scalar and one-element aggregate output initialization,
  inline message clearing, and pointer/address optional-word helpers. The closest
  304-byte candidate still allocates the shared zero/loop counter in r3 instead
  of ip and delays advancing the command cursor to case 4 instead of generating
  the original post-indexed load before the switch. No nonmatching definition
  is retained. A human can investigate compiler scheduling with
  `tools/decompme.py`; no public scratch was uploaded.
