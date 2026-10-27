# sdk_020557c0 — M2-T484

The eight requested ARM functions are implemented in readable C and each reports
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
