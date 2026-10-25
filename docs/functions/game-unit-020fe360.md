# game/unit_020fe360 (M1-T479)

All seven original symbols are retained as neutral names: the assembly establishes
field operations and call sequencing, but does not establish the broader gameplay
meaning. Each implementation has typed parameters and borrowed struct views.
No module boundary changes or dependencies are introduced.

| Function | Evidence and contract |
| --- | --- |
| `func_020fe360` | Returns one when leader values at +28/+30 are below signed limits at +18/+20, or flags at +108 are set. Otherwise scans signed slots at global +840, using count +855 and 60-byte member records at +116; negative slots and null computed records are ignored. Member comparisons use +30/+32 against +10/+12 and flags +52. |
| `func_020fe430` | Mode-zero handler for phases 0..5 and 10. Resolves the selected cell and group-three element on each call. Element bits 4..7 select the priced path, bits 8..23 supply the price key. Confirmation can charge global +836 and select mode 1, 2 or 3. Message calls use IDs 17/18/39/62 and option mask 0x101. Unknown phases return one. |
| `func_020fe7b0` | Six-phase handler restoring the compared leader/member values to their limits and clearing their flags. Preserves repeated cell-resolution calls even though the resulting element is unused. Waits until timer exceeds ten before the closing call. Unknown phases return one. |
| `func_020fe9c4` | Three-phase handler: starts call 0206597c with 19, polls 02065cd0 for exactly one, performs cleanup and direction zero, then polls 020654cc for exactly one. Phase advances clear timer. Unknown phases return one. |
| `func_020fea70` | Two-phase direction-zero handler; clears timer, advances phase, and polls 020654cc for exactly one. Unknown phases return one. |
| `func_020feadc` | Resolves cell coordinates from signed bytes +0x7482/+0x7483 twice, fetches group-three element indexed by descriptor byte one, then clears mode +0x7480. Does not advance phase. |
| `func_020feb40` | Dispatches signed mode +0x7480 values 0..3 to the four handlers; all other modes return zero. |

The party record array extent of twelve is a layout view inferred from the gap
between +116 and +836; the fifteen slot bytes similarly span +840 through +854.
These extents do not add runtime validation absent from the original. Inputs must
refer to valid engine-owned work and selected cells. Timer units are update calls.

Validation uses original machine code as the acceptance oracle (this card does
not require new tests). Standalone relocation-aware comparison matches all seven
functions. The full objdiff, checksum, anticheat and repository test gates are run
before handoff.

## Hard list

None.
