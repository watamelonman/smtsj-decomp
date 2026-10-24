# src/game/unit_020d1a18.c

All four functions match the delinked ARM object at 100% with the configured compiler.
Names remain neutral because the resource identities and surrounding feature are unknown.

- `func_020d1a18` (140 bytes): initializes two flag bytes and sixteen payload
  words, sets mask 0x28 with words 3 = 21 and 5 = 1, and calls
  `Unk0bc1a8_Unk_0bc928(3, 21, &options)`. Then sets word 1 = 1 and mask
  bit 1 before submitting to `func_020bcbc4(3, &options)`. Stack offsets
  establish the payload layout; other callers and the callee's use of r1/r2
  support the three-argument helper declaration. The block is stack-owned and
  consumed during these calls; padding bytes are not initialized in the original.
- `Unk0d1a18_Unk_0d1aa4` (16 bytes): calls `Unk02e000_Unk_02e0cc`
  followed by `CampStatus_Unk_0d51cc`, with no arguments or returned value.
- `func_020d1ab4` (160 bytes): updates a borrowed five-word state block.
  Phase 2 decrements a positive delay and enters phase 4 with timer 2 when it
  expires. Phase 3 increments its timer and enters phase 2 at 2. Phase 4
  decrements its timer; at zero it clears the phase, releases the handle via
  `func_02062a00`, then passes the owner to `func_02061730`. No owner access
  follows that final call. Phases 0, 1 and out-of-range phases do nothing.
- `func_020d1b54` (324 bytes): returns for inactive phase 0. Otherwise rounds
  width + 32 upward to an even integer, computes the signed half of width - 32,
  and submits resource IDs 0x5f80/0x5f82/0x5f81 at opposing horizontal offsets
  and vertical coordinate -111. Phase 2 additionally submits the state handle
  at (128, 13). The draw interpretation follows the repeated coordinate/scale
  arguments and resource calls; exact resource identities remain unknown.
  Width arithmetic must stay within signed-int range. The state is borrowed.

## Validation

`tools/match_gate.py` verifies all four functions at 100%; `ninja` builds the
image. The checksum, anticheat and Python test gates are also run locally.
No hard functions remain. The delink completion flag remains human-owned.
