# game/unit_02124e68

All seven functions match the delinked ARM object at 100% with the configured
mwccarm 2.0/sp1p5 compiler. Names are retained from the symbol configuration;
unknown callees and state fields remain neutral.

- `Unk124e68_Set`: writes state word 0 and bytes 0x18/0x19, and resets
  the interval counter at 0x1a. The byte parameters are truncated on store.
- `func_02124e9c`: clears the global state pointer, registers four callbacks
  through `func_020611dc` with arguments 28, 4, 101, 1, and initializes the
  returned state if allocation succeeds. Words 0x0c/0x10 start enabled,
  word 0x14 starts at 7, and the step byte at 0x19 starts at 3.
- `Unk124e68_Nop_124f48`: empty fourth callback registered by the initializer.
- `func_02124f4c`: compares the interval counter against byte 0x18. At the
  interval, updates signed byte 8 by byte 0x19, decreasing toward 0 when
  word 4 is zero and increasing toward 31 otherwise, then resets the
  counter. The original truncates to a signed byte before testing the bound;
  the C preserves that behavior rather than imposing a wider clamp.
- `Unk124e68_Unk_124fbc`: when word 0x0c is nonzero, brackets a call to
  `func_02125024` with `func_02057524`/`func_02057534`. Passes word 0,
  byte 8 interpreted unsigned, and 22 to the shared operation.
- `Unk124e68_Unk_124ff0`: same sequence, guarded by word 0x10.
- `func_02125024`: skips zero values; otherwise sets the supplied value,
  calls `func_02057fd8`, selects four 255 or four -1 arguments according to
  the mode, invokes `func_02057b50` with 0, 0, 256, 192 and the third
  parameter, and finishes with `func_02057df8`, `func_02057e30(0)` and
  `func_02057e18(31)`. The dimensions suggest a screen-sized operation,
  but its precise semantics are not established here.

The state layout is evidenced by the original load/store offsets in
`func_02124e9c` and `func_02124f4c`; the enable words and callback relationships
are evidenced by the two guarded callbacks and registration arguments.

## Hard functions

None.
