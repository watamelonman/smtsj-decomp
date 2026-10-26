# game/unit_020a93e8

The six C definitions retain their original neutral symbol names. Evidence is the
ARM instruction stream, including graphics register writes and packet field use;
no game-specific purpose is inferred. The unit remains linked from the delinked
original until a human changes its completion status. No new behavioral tests are
required by the card; verification compares the compiled functions to the original.

| Function | Reconstruction and contract |
| --- | --- |
| `func_020a93e8` | Rejects nonpositive bounds, constructs a 56-byte packet, submits it under graphics mode 2, and writes the submission register. Bounds use signed integer differences. |
| `func_020a94bc` | Equivalent packet submission with caller flags ORed with `0x20001` and caller-selected handle. |
| `func_020a9588` | Submits entries 2 and 3 with opposing offsets and a floating scale derived from level; level 9 uses unit scale. |
| `func_020a966c` | Submits entry 14 and two clipped entry-3072 packets; signed phase wraps modulo 30. |
| `func_020a97b4` | Forwards the handle at offset `0x14` and coordinates to entry 26 at unit scale. |
| `func_020a97fc` | Submits entries 5 and 7, then two spans of width `amount * 80 / 140` for positive amounts, and restores state. |
| `func_020a98fc` | Omitted: equal values return early; otherwise scales a ratio to 64 and submits a remaining span through `func_020a93e8`. Denominator must be nonzero. See hard list. |
| `func_020a996c` | Omitted: copies three four-word coordinate/flag tables and submits up to four ratio-dependent packets through `func_020a94bc`. See hard list. |

## Hard list

- `func_020a98fc` (112 bytes): reconstructed ratio and all call arguments.
  Both multiplication and shift forms compile to 108 bytes: the compiler folds
  the coordinate base 17 into an immediate add, whereas the original materializes
  17 in a register and adds the doubled ratio. Needs a decomp.me scratch.
- `func_020a996c` (292 bytes): reconstructed all tables, the early equality return,
  signed half comparison, and the upper-half loop's skip of the first two packets.
  Candidate reached 292 bytes, but array-copy instruction scheduling and allocation
  of ratio, loop index, width, and complementary spans differ. Tried declaration
  permutations, signed/unsigned flag tables, explicit shifted handle local, and
  alternative conditional layouts. Needs a decomp.me scratch.

The omitted functions continue to come from the original delink; no assembly
stubs or nonmatching definitions have been added.
