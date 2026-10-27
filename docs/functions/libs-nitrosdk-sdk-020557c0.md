# sdk_020557c0 — M2-T484 / M2-T485

The sixteen requested ARM functions are implemented in readable C and each reports
100% in `build/report.json`. Remaining functions stay in the delinked object;
this change does not mark the translation unit complete.

Public-source reconnaissance searched pret/pokeplatinum and NitroSDK/NitroSystem
background/palette APIs before reconstruction. No matching public implementation
was identified for these wrappers. Names remain the original neutral symbols;
the contracts below come from the target instructions and immediate providers,
not an assumed SDK API identity. No allocation or ownership transfer is added.

| Function | Contract and instruction evidence | Match |
| --- | --- | --- |
| `func_020557c0` | Forwards borrowed source pointer, byte offset and byte count unchanged to `func_02004aec`; the original loads that address into IP and tail-calls it. The provider adds the offset to its selected destination base. | 100% |
| `func_02055874` | Looks up the selected record through `0205410c`, obtains its byte count through `020557cc`, then passes index, borrowed source and count to `0205589c`. The helper's size depends on record words +0 and +4. | 100% |
| `func_02055990` | Forwards engine selector, slot and borrowed source to `020559a0` with count one. That provider converts slot/count to bytes by shifting five, flushes the source cache range, and chooses the main/sub palette transfer. | 100% |
| `func_020559e8` | Forwards engine selector, slot and borrowed source to `020559f8` with count one. Its provider shifts slot/count nine and chooses normal or extended palette loading. | 100% |
| `func_02055ab0` | ORs flags into caller-owned byte +0x10. Only the low eight result bits are stored; all other record bytes remain untouched. Evidence: LDRB/ORR/STRB. | 100% |
| `func_02055d2c` | Calls `02055ce4` for indices 0 through 7 in ascending order. That provider checks the pointer at record +0x20 and dispatches using flag bits at +0x10. Evidence: increment, compare with eight, signed less-than loop. | 100% |
| `func_02055d84` | Returns 32768 for selector zero, otherwise 65536. Evidence: CMP and conditional immediate moves. Selector meaning and result units remain unproven. | 100% |
| `func_02055d94` | Returns 32 for selector zero, otherwise 64. Evidence: CMP and conditional immediate moves. Selector meaning and result units remain unproven. | 100% |

## Validation

The card explicitly sets `tests_required = false`; instruction matching is the
acceptance test for these small wrappers. The match gate built the project and
verified all eight implementations at 100%. Anticheat, the repository unit tests
and checksum verification were also run. The checksum uses the existing delink
selection, as required until a human marks this unit complete.

## Hard list

None of the eight requested functions is deferred.

## M2-T485

Public-source reconnaissance checked the related [pret/pokeplatinum background
APIs](https://github.com/pret/pokeplatinum/blob/main/docs/2d_rendering.md).
No identical implementation was identified; these routines were reconstructed
from target instructions. Private record views describe only observed offsets;
records and buffers remain provider-owned. Original neutral symbols are retained.

| Function | Contract and evidence | Match |
| --- | --- | --- |
| `func_020558dc` | Reads stride from 0212e2ec indexed by kind; doubles it for kinds 2/8 when format +0xc equals one. Caller supplies a valid kind/table index. | 100% |
| `func_02055cb0` | If pixels +0x24 exist, fills size +0x20 bytes with zero using 02008848, then sets dirty mask two through 02055ab0. | 100% |
| `func_02055d4c` | Maps unsigned x/y boundaries strictly greater than 32 to pages 0..3; the y-only case returns two for layout three, otherwise one. | 100% |
| `func_02055ac0` | If kind and map +0x1c are nonzero, uploads the map through 02055874 and clears dirty mask one. | 100% |
| `func_02055fcc` | Uses layout +4 to index width/height halfword tables 0212e310/0212e328; stores the low value byte at pixels[y*width+x] only inside bounds. Caller supplies a valid layout and allocated pixels. | 100% |
| `func_0205589c` | Performs record lookup, cache flush 02006c94 and indexed 02143b70 transfer with offset zero. Source remains borrowed; index must be valid for both providers. | 100% |
| `func_02055afc` | If kind and pixels +0x24 are nonzero, uploads size +0x20 at slot zero through 0205590c and clears dirty mask two. | 100% |
| `func_020559a0` | Converts slot/count to bytes with unsigned shifts by five, flushes source, then calls main 020046b4 for engine zero or sub 02004708 otherwise. | 100% |

All eight report 100% in the objdiff match gate; no functions are added to the
hard list. Tests are not required by this card: matching instructions provide
the acceptance check. The full build, checksum, anticheat and repository tests
are run with the TU still linked from the delink.

### Symbol integration prerequisite

The protected symbol configuration does not currently declare data_0212e2ec,
data_0212e310 or data_0212e328 (nor relocations at 02055908, 02056000 and
02056004). The C declarations name those observed table addresses. A human must
establish those symbols/relocations before marking the whole TU complete; the
current match gate accepts their relocations and checksum uses the delink.
