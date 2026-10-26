# game/unit_020f6250

The seven implemented functions retain their original neutral symbols: their
state-machine mechanics are established, but a broader feature name is not.
`include/game/unit_020f6250.h` describes borrowed, partial views of the scene,
parent, global work, cells, and eight-byte resource records. No ownership transfers.
Offsets and contracts below come from the ARM disassembly at each function address.
The global direction remains volatile because 020f6998 explicitly reloads it after
its direction switch; caching it changes the original instructions.

| Function | Evidence and behavior | Status |
| --- | --- | --- |
| `func_020f6250` | Reads 020ea438's object, returns for zero; computes `(counter * 180 / 60) % 180`, converts a 20.12 degree angle to a turn index, reads the sine halfword at 0212629c, and passes its scaled alpha to 0205de40. | Hard; original delink retained |
| `func_020f6354` | Signed phase at +7481 selects four preparation steps. Unsigned coordinate bytes query the +35c area, create kind 13 when absent, then wait on 020654cc/02065cd0. Returns a completion flag. | Exact |
| `func_020f6454` | Increments +7484 and the current cell's +2 halfword; thresholds 40, 10, and 2 gate the transitions. Calls the existing ScanVisor helpers and initializes embedded +7550/+7598 work, then sets state 2. | Exact |
| `func_020f6604` | Four phases: drains the mode operation until completion or mode-7 success, prepares unless +73e0 is set, lists enabled alternative variants using message IDs 27..29, then encodes the selected variant as state `variant+4`. If none is selected, state 2 becomes 3. | Exact |
| `func_020f6998` | Increments the timer, switches parent words to 4/3, offsets signed x/y by one according to global direction, calls 02034b7c with trailing arguments 3/0/0/1, and waits on +7440. | Exact |
| `func_020f6af0` | Chooses mode 1/2 by comparing the current resource variant with state-4. After input past frame 20 or timeout past frame 200, requests the selected destination, handles map kind 13, then waits on transition predicates and +7440. | Exact |
| `func_020f6d0c` | Looks up resource kind 2 via the cell header's +1 byte. The first matching low-nibble variant ends the search regardless of its direction bit. An enabled bit selects state 1 and triggers the eight-byte copy and current-cell setup. | Exact |
| `func_020f6ef8` | Jump-table dispatch of signed +7480: states 0..3 invoke the first four handlers, all other values invoke 020f6af0. Forwards the handler's result. | Exact |

## Hard list

- `func_020f6250`: tried signed 64-bit multiply/subtract for the remainder,
  then ordinary signed `% 180` (which reproduced the original SMULL sequence),
  inline degree/index and sine helpers, flat/interleaved table views, and combined
  versus separate expressions. The best candidate had the exact 260-byte size,
  arithmetic, constants and calls, but allocated the initial product to r9 instead
  of lr and used different registers for the literal sine-table base and scale.
  No candidate is included in production. The sine table has no symbol at
  0212629c in the current symbol map, so the candidate used a typed data pointer.
  A human can use `tools/decompme.py` for a scratch; no upload was made.

The original delink supplies omitted code. This DS project does not use
`INCLUDE_ASM` in new source, and its anticheat gate forbids adding it. The unit's
completion flag remains human-owned and unchanged.
