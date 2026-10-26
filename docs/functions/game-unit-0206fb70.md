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

## M1-T936 — verified against original ARM

Seven of the eight functions match at 100% in objdiff. `func_020717e4` is
left in the delink because its C form could not be made to match exactly; see
the hard list below.

- `func_02071cc8` (0x02071cc8, 96 bytes): adds
  `func_0206d68c(2, delta, 100)` to each of the signed words at +0x120,
  +0x124 and +0x128. Evidence is the three repeated BL/load/add/store groups
  and the three field offsets.
- `func_0207153c` (0x0207153c, 108 bytes): starts at the manager cursor
  +0x22c and advances it while the corresponding `objs` entry at +0x234 is
  null, stopping at the end sentinel +0x230 or at the first non-null entry.
  Evidence is the signed cursor check, the `% 50` magic constant
  (0x51eb851f), the `objs` index scale by four, and the two return paths.
- `func_020719a8` (0x020719a8, 108 bytes): the same cursor-advance loop for
  a second manager instance; its instruction sequence is identical to
  0x0207153c but it is a separate symbol.
- `Unk06fb70_Unk_06feb4` (0x0206feb4, 116 bytes): calls the eight
  per-channel advance functions 0x02070094 through 0x02070360, one per
  channel, with the two animation objects. Evidence is the eight BL targets
  and the matching per-channel bodies.
- `Unk06fb70_Unk_06ff28` (0x0206ff28, 116 bytes): the same dispatcher for
  the second set of channels, calling 0x020705f8 through 0x02070f30.
- `Unk06fb70_Unk_070500` (0x02070500, 124 bytes): advances one animation
  channel described by separate tick/state/limit/pos/vel/max pointers; on
  tick expiry it resets tick and velocity and selects the next key through
  0x0207126c, otherwise it clamps `pos` by `vel` within `max`.
- `Unk06fb70_Unk_07057c` (0x0207057c, 124 bytes): the same channel update
  through 0x02071334.

### Hard list for M1-T936

- `func_020717e4` (0x020717e4, 96 bytes). It forwards the eight object
  views at +0x16c, +0x2c, +0x28, +0x30, +0, +0xc, +0x18 and +0x34 to
  `func_020703b4`, then zeroes five words at `sp+0x10` before the call.
  The surrounding sequence and frame size show a five-word zero-initialised
  local/outgoing argument area. Writing it as `u32 scratch[5] = {0};`
  reproduces every instruction except that mwcc assigns the zero block's
  base to `r2` and the zero to `r1` (target uses `r1`/`r2`), giving 97.5%.
  Tried: unused and used arrays (u32/s32/void*/struct), pointer locals with
  several types and read/write uses, volatile arrays, explicit element
  stores, compound literals, 13-argument call forms, variadic and fixed
  prototypes, empty-init and nested/aggregate array forms, and every bundled
  mwccarm 1.2/2.0/dsi version and target proc. No source form produced the
  retail register assignment without adding instructions, so the original
  body is left to the delink rather than faking a match.

## M1-T937 — verified against original ARM

All eight functions match at 100% in objdiff. The two channel helpers
0x02070094 and 0x02070758 were already defined and verified by earlier work in
this TU; they remain the bodies already listed above. The remaining six use the
second animation view (`Unk06fb70Anim2`), whose four 24-byte keys hold three
value/time pairs. Evidence throughout is the original `mla` sequences
(`+0x44 + key * 24 + channel * 8`), signed-byte state loads, four-key bound and
the exact BL targets.

- `Unk06fb70_Unk_070094` (0x02070094, 128 bytes): channel 0 advance for the
  first animation view. Already matched before this card; it gates on state
  four, advances tick, and either resets tick/velocities and selects the next
  key through 0x020705f8 or clamps the three position components.
- `func_0206fb9c` (0x0206fb9c, 136 bytes): converts the float delta
  `f1 - f0` over `(t1 - t0) * 4096` into a 20.12 result via 0x0200219c, rounding
  by half a unit away from zero. A zero time delta calls 0x02007e94. Evidence
  is the `_fsub`/`_fgr`/`_fmul`/`_fadd`/`_ffix` call sequence and shared
  conversion path.
- `func_020703b4` (0x020703b4, 140 bytes): advances the first channel of the
  second animation view. State gates at four; tick expiry clears tick,
  position, velocity and the extra word before calling 0x02071068, otherwise
  the position is clamped by velocity.
- `func_02070440` (0x02070440, 192 bytes): advances the three value channels of
  the second view. A completed state clears four position words; tick expiry
  clears tick and four velocity words before calling 0x0207112c, otherwise each
  of the three positions is clamped by its velocity.
- `func_02071068` (0x02071068, 196 bytes): channel 0 key selector for the second
  view, using the value/time pair at key +0/+4. It sets the time-delta limit and,
  on a positive limit, stores velocity from 0x0206fb70 and maximum from the
  current key's value, then advances state. Evidence is the original load at
  +0x44 where the later channels use the next key.
- `func_0207126c` (0x0207126c, 200 bytes): channel 1 key selector for the second
  view, using the value/time pair at key +8/+12. Velocity uses both endpoints
  through 0x0206fb70 and maximum is the next key's value shifted by 12.
- `func_02071334` (0x02071334, 200 bytes): channel 2 key selector for the second
  view, using the value/time pair at key +16/+20, with the same state and
  four-key bounds as channel 1.
- `Unk06fb70_Unk_070758` (0x02070758, 220 bytes): channel 1 key selector for the
  first animation view. Already matched before this card; it resets state to
  four at the bound and otherwise updates the +4/+12 limit and value pair.

### Hard list for M1-T937

None.

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
