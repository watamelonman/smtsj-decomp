# src/UniteEvent.c

Fusion ("Unite") event translation unit, `0x0210B98C`-`0x0210FE28`. The eight M1-T1051 functions
and six M1-T1052 functions match the delinked ARM code; `UniteEvent` is the object reached
through `data_02176e48`, and `EventMsg` is its message format (flags byte + optional
32-bit values).

- `func_0210b98c` — initialises one descriptor: writes `852` at +0x00, `3` at +0x04,
  and six handler pointers at +0x0C..+0x20 (including `UniteEvent_HandleMessage`).
  The load relocation at `0x021503E0` points to this initialiser. Neutral name: no
  string or caller identifies its role beyond the table shape.
- `UniteEvent_HandleMessage` — message handler for the event. Message 0 sets state 1
  and reads mode (argument 3, mode 3 sets `skipRequested` and resets mode) and icon
  (argument 4). Message 3 moves state 18 to 19 when argument 0 is 7. Messages 1, 2 and
  4 do nothing.
- `UniteEvent_SetState` — stores the new state and clears the +0x25C progress field.
- `UniteEvent_CopyIds` — copies `n` 16-bit ids into +0x266 through `func_0200866c`
  and records the count at +0x27E; does nothing when `data_02176e48` is null.
- `UniteEvent_SetId` — marks the id valid at +0x330 and stores the 16-bit id at
  +0x280; does nothing when `data_02176e48` is null.
- `UniteEvent_SetCtxUnk32c` — sets the +0x32C flag when `data_02176e48` is non-null.
- `UniteEvent_LoadEffects` — formats `"Data/Effect/%s"` twice (`data_02151418` for the
  medium, `data_02151428` for the effect), converts each result with `func_0206f6e4`
  and stores the bytes at destination +4.
- `func_0210fa60` — called by the state machine in `func_0210bc2c` with the slots at
  `UniteEvent+0x1E0`/`+0x21C`; zeroes +0x14..+0x1C, loads a resource with constant
  `0x3F800000`/`5` arguments, looks up an entry with `func_02044618` and applies up
  to two id pairs with `Unk06ae94_SetPair`. Always returns 1. Neutral name: no string
  identifies it.

## M1-T1052

Six of seven targets match at 100% in objdiff. Existing M1-T1051 matches remain
at 100%. All implemented callbacks keep their original symbols because the
specific event-hook names are not established by callers or strings.

- `func_0210baf8` (308 bytes) — initializes the 852-byte owner, publishes it through
  `data_02176e48`, clears the id arrays and work groups, sets the two 0x40000
  defaults, and starts the shared subsystems. Evidence: stores and calls at
  0x0210BAF8–0x0210BC24. Matched on the first compiled candidate.
- `func_0210f6cc` (660 bytes) — releases the UI handle groups, optional id resources,
  context work, effect-slot handles and shared subsystems, then clears the global
  owner. Evidence: descriptor callback 4 and calls at 0x0210F6CC–0x0210F95C.
  The eight consecutive argument-free `func_0205bb68` calls are present in the
  original; they are preserved explicitly. Matched on the first candidate.
- `func_0210e064` (704 bytes) — polls input masks 1 and 2, accepts the transition
  only in states 3–13 with `skipRequested` clear, and switches to state 14. It
  releases active effect resources and restores retained UI groups. Evidence:
  input/state checks at 0x0210E064–0x0210E0F8 and cleanup through 0x0210E320.
  Matched on the first candidate.
- `func_0210fb04` (804 bytes) — fills two nine-word coordinate arrays for the
  selected count, optionally incremented with byte wraparound. Positive entries
  receive the (16,8) origin offset and conversion to 20.12 fixed point. Unsupported
  counts leave both arrays zero. Evidence: switch constants and conversion loop
  at 0x0210FB04–0x0210FE24. Matched on the first candidate.
- `func_0210e324` (1568 bytes) — draws state-dependent fusion effects, four scrolling
  overlays, and retained id resources using fixed-point positions, float scales
  and byte opacity. Evidence: state dispatch at 0x0210E354 and submissions through
  0x0210E924. Trials: 92.30% initially; explicit no-op switch cases restored the
  jump table; signed shifting before halfword narrowing removed redundant shifts;
  declaring the scrolling position at function scope resolved the final r9/r10
  allocation difference. Final: 100%.
- `func_0210e944` (3464 bytes) — draws the background, color ramps, clipped frame
  overlays and state-dependent full-screen shading. Evidence: frame ids, rectangle
  writes and draw calls at 0x0210E944–0x0210F6C8. Ten local frame copies preserve
  the original scratch lifetimes, including the duplicated initial copy. Trials:
  93.52% initially, then 96.92% and 99.14% after recovering the state-15 fade and
  placing each color-channel clamp before calculating the next channel. Matching
  the branch-specific rectangle assignments resolved the final branch target.
  Final: 100%.
- `func_0210bc2c` (9272 bytes) — event update callback with states 0–19, resource
  setup, animated id presentation, two effect slots and common scrolling/timer
  updates. Evidence: descriptor callback 0, switch at 0x0210BC40, helper calls at
  0x0210BF20/0x0210D1A8/0x0210D658/0x0210DA5C, and timer increment at
  0x0210E02C. Remains supplied by the delink; see the hard list below.

## Hard list

### `func_0210bc2c` — 9272 bytes, not implemented

Hand-traced the 20-way dispatch, early resource initialization and states 2–8,
then followed the state-12 mixed float/fixed-point loop and common update tail.
This analysis supplied the shared field layouts used by the six matched functions,
but did not produce a complete C candidate. No full-function matching percentage
is claimed. The original delink definition remains untouched.

Useful scratch boundaries and contracts for a human using `tools/decompme.py`:

- Entry 0x0210BC2C saves r4–r11/lr and reserves 0x1B4 stack bytes. State 1 starts
  resources after progress exceeds 5; states 2–5 wait for resources/animations,
  advancing to state 6 after progress reaches 90 in state 5.
- State 6 has separate +0x334 resource and context-loading paths. Both populate
  +0x310; context callbacks also read the record pointer at returned object +0x18C.
  The complete external record/resource layouts remain unreconstructed.
- State 12 begins at 0x0210D044. It staggers each slot by 15 updates, adds/subtracts
  the float constant referenced at 0x0210CCD8 to +0x184, and independently adds
  0x18CD to fixed-point opacity at +0x1A8, clamped to 0x1F000. Preserve native
  float arithmetic so the compiler emits the original `_fadd`/`_fsub` calls.
- States 13, 15 and 16 load the work slots through `func_0210fa60`; these paths
  combine additional resource contracts, float comparisons and timed transitions.
- The common tail at 0x0210DEA8 updates four +0x1D0 positions by subtracting
  0x2222 and wrapping negative results to 0x100000. It also updates +0x340/+0x34C
  over several disjoint timer ranges, updates +0x348 for states 9–10, and increments
  +0x25C unconditionally. A partial switch must not replace this callback.

The remaining work is a full reconstruction of the setup/resource paths and all
state bodies, followed by whole-function register/stack matching. No partial body,
assembly include, or stub was added.

### `func_0210bc2c`: cloud giants batch

A full C candidate exists in `docs/candidates/func_0210bc2c.md`, together with the retyped
`UniteEvent` layout: typed `UniteDrawHandle *` handles, `Unk10fa60Work` slots, `UniteTextWork`
at +0x284 and `u16 iconId`. All 14 matched functions in the TU still match with that layout.
The candidate is 9,260 of 9,272 bytes, and states 1 to 11 and 13 to 19 are instruction-identical
except for the issues below. It cannot be merged yet:

1. **Needs a symbols.txt entry**: state 13 indexes NitroSDK's `FX_SinCosTable_` (sin/cos
   `s16` pairs) at 0x0212629c, which has no symbol, so the delinked literal is unrelocated.
   With a constant address, mwcc folds `table + 2` into a second base register. The original
   code indexed one symbol base (`add r5, r0, r5, lsl #2; ldrsh r5, [r5, #2]`). Needed entry:
   `data_0212629c kind:data(any) addr:0x0212629c` (or the name `FX_SinCosTable_`).
2. Stack: the original keeps a dead store of each request argument value in its own 4-byte
   slot (sp+4/8/12/16 for states 19/17/16/15) before writing `req.values[i]`. The frame is
   0x1B4 bytes. Every probed form either removes the slot (address-taken scalar, array, inline
   parameter, union) or adds a second slot or a template load (aggregate initializer,
   struct-return inline). Unresolved; this costs 16 bytes of frame.
3. State 13's second loop: the original computes `0x578 + (t - 260) * 18` as `mla` with
   0x578 already in a register. State 12's `start` counter is initialised after the loop guard.

