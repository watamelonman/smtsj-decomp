# sdk_020580ec

Public-source lookup: searched the reconstructed NNS G2D font, NFT loader and
renderer sources in pret/pokediamond for the `Plt:` marker and an A-I flag
parser; no implementation with this contract was identified. The split's
NitroSDK directory alone does not prove SDK provenance. Existing `func_` symbols
are retained because symbol configuration is human-owned. All contracts below
come from the original ARM instructions.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_020580ec` | Sets bit 15 of the word at `0x02168b24` when the argument is exactly one, otherwise clears it. Returns nothing; callers pass zero and one around graphics setup. | 100% |
| `func_0205811c` | Finds the marker string through the pointer word at `0x02143ba4` (the literal `Plt:`), clears both caller-owned flag words, then walks the name one signed byte at a time. Letters A-I set bits 0-8 of the first word; after the marker is reached those letters set the second word instead and the four marker bytes are skipped. Returns one when the marker was present, zero otherwise. See DEC-034 for the per-iteration byte reads. | 100% |
| `func_02058258` | Parses the name with `func_0205811c`; a missing marker calls the non-returning fatal routine at `0x02007e94`. Forwards the character flags to `func_0200303c` and the palette flags to `func_02003214`. | 100% |
| `func_02058290` | Parses the name, applies the character flags through `func_02002ab0` for mode zero or `func_0200331c` otherwise, and returns early when no marker was found. When a marker exists it applies the palette flags through `func_02002e90` or `func_020033c4` for the same mode split. | 100% |
| `func_02058300` | Same control flow and marker rule as `func_02058290`, with the second accessor pair: `func_02002d40`/`func_02002f90` for mode zero and `func_02003434`/`func_020034b4` otherwise. | 100% |

No hard-list entries: all five functions match at 100%.

## Notes

`func_020580ec` and the three flag appliers use `int` mode/argument types while
`func_0205811c` takes `u32` flag outputs, matching the register use at every
call site. The marker pointer is copied to a local before the substring search
because the original keeps it in a callee-saved register across both calls.

No assembly stub is added: incomplete TUs link from their original delinks.
