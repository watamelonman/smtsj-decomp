# src/game/unit_0206fb70.c

## M1-T934 — verified against original ARM

All eight functions match at 100% in objdiff. Parameters use signed words for
arithmetic, a typed animation view for channel updates, and object pointers for
field forwarding. Names retain their configured neutral meanings.

- `Unk06fb70_Unk_0717c0` (0x020717c0, 36 bytes): adds the result of
  `func_0206d68c(2, value, 100)` to the signed word at object +0x120.
- `Unk06fb70_Unk_06fb70` (0x0206fb70, 44 bytes): calls 0x02007e94 on a
  zero time delta, then divides the value delta shifted by 12 by the time delta
  shifted by 12 using 0x0200219c. Arithmetic follows the original ARM word operations.
- `Unk06fb70_AddClamped` (0x020713fc, 48 bytes): adds a signed delta to a
  writable accumulator and clamps above the limit for nonnegative deltas or
  below it for negative deltas. The name is supported by the compare/store sequence.
- `Unk06fb70_Call_07142c` (0x02071508, 52 bytes): forwards seven word
  arguments to 0x0207142c, inserting zero as the sixth argument.
- `Unk06fb70_Call_071898` (0x02071974, 52 bytes): the same argument
  contract for target 0x02071898. Both names follow their observed BL targets.
- `Unk06fb70_Call_0703b4` (0x02071d28, 68 bytes): forwards object views at
  +0x16c, +0x2c, +0x28, +0x30, +0, +0xc, +0x18, +0x34 to 0x020703b4.
  The caller supplies a live object covering those offsets.
- `Unk06fb70_Unk_070114` (0x02070114, 84 bytes): advances channel 1 only
  when its signed state is below four. Expired ticks reset tick and velocity
  before calling 0x02070758; otherwise it clamps the position increment.
- `Unk06fb70_Unk_070168` (0x02070168, 84 bytes): channel 2 counterpart,
  selecting the next key through 0x02070834 on expiry.

Evidence: original instructions at each address, including field offsets,
signed comparisons, constants and BL targets. No higher-level effect semantics
are inferred. Existing C bodies were already present when this card started.

### Hard list for M1-T934

None.

## M1-T935 — verified against original ARM

All eight functions match at 100% in objdiff. The six per-channel advances reuse
the `Unk06fb70Anim` view: each returns when its signed key state is at least 4,
otherwise increments its tick, and either selects the next key on expiry or
clamps the channel position. The two manager teardowns use the same
`Unk06fb70Mgr` layout. Evidence is the original instruction sequence at each
address (field offsets, signed compares, loop bound 50 and BL targets).

- `Unk06fb70_Unk_0701bc` (0x020701bc, 84 bytes): advances channel 3. It exits
  when `state[3] >= 4`; when `tick[3]` exceeds `limit[3]` it resets the tick and
  velocity and calls 0x02070950 to pick the next key, otherwise it clamps
  `pos[5]` by `vel[5]` within `max[5]`.
- `Unk06fb70_Unk_070210` (0x02070210, 84 bytes): channel 4 counterpart using
  `state[4]`, `tick[4]`, `limit[4]`, `pos[6]`, `vel[6]`, `max[6]` and selecting
  the next key through 0x02070a6c.
- `Unk06fb70_Unk_070264` (0x02070264, 84 bytes): channel 5 counterpart using
  `state[5]`, `tick[5]`, `limit[5]`, `pos[7]`, `vel[7]`, `max[7]` and selecting
  the next key through 0x02070b88.
- `Unk06fb70_Unk_0702b8` (0x020702b8, 84 bytes): channel 6 counterpart using
  `state[6]`, `tick[6]`, `limit[6]`, `pos[8]`, `vel[8]`, `max[8]` and selecting
  the next key through 0x02070cc0.
- `Unk06fb70_Unk_07030c` (0x0207030c, 84 bytes): channel 7 counterpart using
  `state[7]`, `tick[7]`, `limit[7]`, `pos[9]`, `vel[9]`, `max[9]` and selecting
  the next key through 0x02070df8.
- `Unk06fb70_Unk_070360` (0x02070360, 84 bytes): channel 8 counterpart using
  `state[8]`, `tick[8]`, `limit[8]`, `pos[10]`, `vel[10]`, `max[10]` and
  selecting the next key through 0x02070f30.
- `Unk06fb70_Unk_071844` (0x02071844, 84 bytes): null-checked manager teardown.
  It calls 0x0206c0b0 for each of the 50 object words at +0x234, zeroes the
  words at +0x24, +0x28, +0x2c and +0x30, clears the word reached through
  +0x224 when non-null, then calls func_02061424 on the manager.
- `func_02071d6c` (0x02071d6c, 84 bytes): the same null-checked manager teardown
  for a second manager instance. The name is neutral because only the address
  identifies it; the caller in `unit_0206ae94.c` iterates `arg0[6]` entries from
  +0x44 and passes each one here. Its instruction sequence is byte-identical to
  0x02071844, but it is a separate original symbol, so it is emitted as its own
  C function rather than an alias.

### Hard list for M1-T935

None.

## Not done in M1-T936
- `func_020717e4`
- `func_02071cc8`
- `func_0207153c`
- `func_020719a8`
- `Unk06fb70_Unk_070500`
- `Unk06fb70_Unk_07057c`

## Not done in M1-T937
- `Unk06fb70_Unk_070094`
- `func_0206fb9c`
- `func_020703b4`
- `func_02070440`
- `func_02071068`
- `func_0207126c`
- `func_02071334`
- `Unk06fb70_Unk_070758`

## Not done in M1-T938
- `func_0207142c`
- `func_02071898`
- `func_0206ff9c`
- `Unk06fb70_Unk_070834`
- `Unk06fb70_Unk_070950`
- `Unk06fb70_Unk_070a6c`
- `Unk06fb70_Unk_070b88`
- `Unk06fb70_Unk_070cc0`
- `Unk06fb70_AddClamped`: hand-matched
- `Unk06fb70_Call_07142c`: hand-matched
- `Unk06fb70_Call_071898`: hand-matched
- `Unk06fb70_Call_0703b4`: hand-matched
- `Unk06fb70_Unk_0705f8`: hand-matched
- `Unk06fb70_Unk_070758`: hand-matched
- `Unk06fb70_Unk_070094`: hand-matched
- `Unk06fb70_Unk_070114`: hand-matched
- `Unk06fb70_Unk_070168`: hand-matched
- `Unk06fb70_Unk_0701bc`: hand-matched
- `Unk06fb70_Unk_070210`: hand-matched
- `Unk06fb70_Unk_070264`: hand-matched
- `Unk06fb70_Unk_0702b8`: hand-matched
- `Unk06fb70_Unk_07030c`: hand-matched
- `Unk06fb70_Unk_070360`: hand-matched
- `Unk06fb70_Unk_070834`: hand-matched
- `Unk06fb70_Unk_070950`: hand-matched
- `Unk06fb70_Unk_070a6c`: hand-matched
- `Unk06fb70_Unk_070b88`: hand-matched
- `Unk06fb70_Unk_070cc0`: hand-matched
- `Unk06fb70_Unk_070df8`: hand-matched
- `Unk06fb70_Unk_070f30`: hand-matched
- `Unk06fb70_Unk_070500`: hand-matched
- `Unk06fb70_Unk_07057c`: hand-matched
- `Unk06fb70_Unk_071844`: hand-matched
