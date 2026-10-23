# game/unit_0209e72c

Names remain neutral because instruction/data use establishes operations but not
higher-level gameplay meanings. All implemented functions ignore absent game state.
Evidence below is from the original ARM instructions at each symbol's address.

- `Unk09e72c_Unk_09e72c` (48 bytes, 100%): accepts a 32-bit value,
  stores it at GameState +0x73D0, sets +0x73CC to 12 and mode +0x73E8 to 7.
- `func_0209e75c` (160 bytes): see hard list below.
- `func_0209e7fc` (160 bytes, 100%): four unsigned word arguments are value,
  count, kind and flag. Clamp count to 1..4; map kinds 0/1 to 3 and 2 to 4,
  preserving other values. Call `func_02052590(kind, value, count)`.
  Flag exactly 1 also calls `func_020a4eb0` with kind 2 for mapped kind 3,
  otherwise 3, and requests mode 9. Other flags request mode 8.
- `Unk09e72c_Unk_09e89c` (84 bytes, 100%): reset the body through
  `func_0203480c(body, 0)` and invoke the +0x7550/+0x7598 work helpers;
  set +0x73E4 to 1, +0x73D8 to 0 and mode to 10.
- `Unk09e72c_Unk_09e8f0` (48 bytes, 100%): set +0x73E4 to 0,
  +0x73D8 to 1 and mode to 11.
- `Unk09e72c_Unk_09e920` (76 bytes, 100%): accepts a word selector,
  sets +0x73CC to 6, clears root +4, stores the selector's low byte at
  +0x7480, calls the bit setter with the full selector and 1, then selects mode 13.

## Hard list

- `func_0209e75c`: left linked from the original delink. Readable C with the
  same count clamp and kind switch as `func_0209e7fc`, calling `func_020525e0`
  and using paired kinds 0/1, reached 99.70%. Only two conditional moves
  were reversed: original `moveq r0, #0; movne r0, #1`, compiler emitted
  `movne r0, #1; moveq r0, #0`. Tried ternary, direct inequality, signed and
  unsigned locals, explicit if/else, initialized locals, switch and separate
  call branches. None matched (91.45–99.72%). A decomp.me scratch can focus
  on the boolean request-kind expression; no nonmatching definition is retained.
