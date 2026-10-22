# src/BattleShowingTask.c

- `BattleShowingTask_Nop_11982c` (4 B): empty task callback (`bx lr`); its address is in
  `func_02119658`'s literal pool at `0x021196b4`, which passes it to `func_020611dc`
  (the call that returns the new task object).
- `BattleShowingTask_Nop_119830` (4 B): empty task callback (`bx lr`); passed to
  `func_020611dc` from `func_02119658` (literal `0x021196b8`).
- `BattleShowingTask_Nop_11984c` (4 B): empty task callback (`bx lr`); slot 1 of the callback
  descriptor at `0x0213d7f4`.
- `BattleShowingTask_Nop_119850` (4 B): empty task callback (`bx lr`); slot 2 of the callback
  descriptor at `0x0213d7f4`.
- `BattleShowingTask_GetUnkField28` (8 B): returns the dword at work `+0x28`; its callers
  (`0x0211adbc`, `0x0211ae70`) compare it with 1 and 3, so it is a state value.
- `BattleShowingTask_Unk_119834` (24 B): descriptor entry 0 at `0x0213d7f4`; calls
  `func_02119658` to create the battle-showing task and stores the handle in
  `data_02176e70` (cleared by `BattleShowingTask_Unk_1196c0` on teardown).
- `BattleShowingTask_Unk_1196e0` (28 B): clears words `+0x00`/`+0x04` of a fresh task (typed as
  `BattleShowingTask`) and forwards 1 to `Unk0a0ce4_Unk_0a0d30`; sole caller `func_02119658`
  (at `0x021196a0`) passes the object returned by `func_020611dc`.
- `BattleShowingTask_Unk_11c230` (28 B): bounds-checked lookup of `unk_0004[unk_000c]` (a
  `u32 *` record table) while the index is below count `unk_0008`, else 0; callers
  `Unk_11c5d0`/`11c610`/`11c670` read u16 fields at `+0x08`, `+0x1c` and `+0x1e` from the
  returned record.
- `ExpGauge_Update`: hand-written (see comment in source)

## M1-T1035 — verified matches

All eight targets are 100% in objdiff; the full-image checksum still matches. The
existing hand-written `ExpGauge_Update` and `BattleShowingTask_Unk_11b4e4` were
already present and remain instruction-identical. Evidence is the original ARM
instruction stream at each entry address.

- `func_021196fc` (`0x021196fc`, 304 B): eight-state setup machine installed as
  the task update callback. It wraps a 16-bit frame counter, then advances
  through initialization, gate checks, the 0x2F resource dispatch and the
  save/load selection before running the final teardown calls.
- `func_0211a504` (`0x0211a504`, 272 B): computes one party member's EXP award.
  Areas of kind 1 and 7 award zero; flags 0x18E and 0x18F add 25%/50% of the
  bonus-base parameter (minimum one for a nonzero base); entries with +0x1A bit 0 set instead scale the
  amount through `func_020b8240`, unless global +0x40 bit 15 bypasses scaling.
- `func_0211a6e4` (`0x0211a6e4`, 384 B): computes the two result-screen EXP
  gauges. A nonzero entry +2 fills both; otherwise the global +0x60/+0x3C gate
  and area kinds 1/7 suppress the award, script flags 0xAD/0xAE add 10 EXP and
  one level-up, and the party ID scan maps resource +0x26 bits 2..4 to +10 EXP,
  +1 level-up, or full gauges.
- `func_0211c350` (`0x0211c350`, 372 B): copies the five-entry rank table from
  `data_0213cce0`, replaces each value with the delta between the source and
  destination rank bytes, publishes the nonzero entries, then selects their IDs
  through the alternating 02063A30/02063A44 helpers (resource 9 when empty).
- `func_0211ccf8` (`0x0211ccf8`, 280 B): screen dispatch for states 6, 7 and 9.
  States 7/9 wait on the 020654CC/02065E28 gates and 02053800(0, 0x800), post
  the type-37 options message with field 12, and clear slot 37; state 6 waits
  on 02053800(0, 1) and continues through `func_0211c6ac`.
- `func_0211ceb4` (`0x0211ceb4`, 412 B): collects the nonzero selectable
  entries (the caller's first entry plus the `count` 0x28-byte entries),
  allocates and sorts the pointer list with `func_0211c160`, then starts the
  current-record dispatch and resets the work state.
- `BattleShowingTask_Unk_11b4e4` (`0x0211b4e4`, 416 B): submits either the
  six-animation display path for states 2/9 or the six-entry auxiliary path
  for the other states, then forwards the state-selected scale to
  `func_0211b100`/`func_0211b2ac`.
- `ExpGauge_Update` (`0x021198fc`, 544 B): per-frame EXP-gauge state machine:
  fade in, count up with per-level pauses, level-up animation, done, and fade
  out, plus the independent level-up animation restart.

Hard list for M1-T1035: none.

## M1-T1033 — verified matches

All eight targets below are 100% in objdiff and the full-image checksum still matches.
Evidence is the original ARM instruction stream at each entry; names stay neutral where the
behaviour is only structural.

- `func_02119940` (`0x02119940`, 208 B): switch on action 0..4. Actions 0/4 store the
  incoming frame count in +0x2C and select fade-in/fade-out; action 1 zeroes the timer and
  selects count-up; action 2 does nothing. Action 3 zeroes the timer, selects DONE, seeds
  shown EXP from info +4 and level-ups from info +2, starts the normal gauge animation, then
  computes total EXP from the area record +0x24 (or the work area +0x20 when info +0 is
  negative) and refreshes the next-level threshold.
- `func_0211a474` (`0x0211a474`, 144 B): counts the three non-negative slot indices at
  work+0x354 (starting from one), divides the current area object's +0x64 value by that
  count with a floor of one, then adds one tenth (also floored at one) when script flag
  0xAB is set. Returns the resulting EXP step.
- `func_0211a864` (`0x0211a864`, 120 B): searches the 15 six-byte entries at work+0x268;
  reuses the first entry with the incoming ID or fills the first empty entry, then adds the
  third argument to the entry's +2 counter.
- `func_0211aa24` (`0x0211aa24`, 132 B): selects even animation sequences 0,2,4,6,8,10 on
  the six handles at work+0x2D4, then resets and starts each.
- `func_0211aaa8` (`0x0211aaa8`, 132 B): same as `func_0211aa24` with odd sequences
  1,3,5,7,9,11.
- `func_0211b1f4` (`0x0211b1f4`, 184 B): maps an entry ID to a category byte through the
  Unk09974c tables. Zero returns 6, type 7 returns 7, types 0/2/3..6/8/9 read byte +3 from
  their respective record, type 1 reads byte +0x2C, and every other type returns 6.
- `func_0211c548` (`0x0211c548`, 136 B): publishes record ID and resource +2 in slots 6/7,
  dispatches resource +0x24 bits 21..27 with second argument 1 when record +0x24 is nonzero
  (else 0), forwards the result and finishes with the signed record ID.
- `func_0211ce10` (`0x0211ce10`, 112 B): when a current record exists, work +0xA4 is
  present and its +0x59 flag is set, submits a display list built from work +0xA8 offset
  +0x7C (mode 5, eight entries, alpha 1.0 from literal 0x3F800000) between the
  `func_02057524(0)`/`func_02057534()` pair.

Review follow-up: area-work, area-object, area-record and category-loader accesses now
use typed fields with explicit padding. The three signed slot entries are sized from the
loop bound in `func_0211a474`; the two 02e000 work helpers share that area-work layout.
`func_0211ce10` passes alpha as `1.0f`. The duplicated dispatch branches in
`func_0211c548` preserve original code generation. All eight targets remain 100%.

Hard list for M1-T1033: none.

## M1-T1034 — verified matches and hard list

Four targets are implemented and verified at 100% in objdiff. The original ARM
instruction streams at the listed addresses are the evidence; identifiers remain
neutral. The existing source file was extended rather than recreated.

- `func_0211a058` (`0x0211a058`, 232 B): allocates a 0x44-byte EXP gauge
  with update/draw/cleanup callbacks, stores the six incoming arguments,
  initializes its EXP step and next-level threshold, then creates and starts the
  gauge and level-up animations. Requires successful allocation, as the original
  immediately dereferences the result. Callback casts adapt the existing generic
  allocator declaration; the actual callbacks receive the allocated gauge.
- `func_0211a380` (`0x0211a380`, 244 B): cleans up seven handles at +0x2D4,
  alternating resource handles at +0x2C4..+0x2D0, six resource-stack entries,
  four entries at +0x2F0, two handles at +0x310/+0x314, and one final stack entry.
  Nonzero checked fields are cleared after cleanup. The existing caller
  `BattleShowingTask_Unk_11b684` now explicitly forwards its incoming work pointer.
  `func_0205bb68` takes no argument: its callee `func_0205b724` obtains the
  resource stack from global `data_0216a730`, ignoring incoming r0.
- `func_0211a924` (`0x0211a924`, 256 B): scans the fifteen six-byte entries
  at +0x268. For nonempty IDs, loads resource thresholds and the stored counter.
  Resource flag bit 2 skips further processing. Otherwise an existing area's
  +8 counter is transferred from the stored counter into entry +2; bits 0/1/2
  mark newly crossed resource +0x5A/+0x5B/100 thresholds, and the total is stored.
- `func_0211c160` (`0x0211c160`, 208 B): compares two record pointers by
  signed record +0 IDs. A negative left ID returns -1; a negative right ID
  returns 1. Finds each nonnegative ID first among three party slots at +0x354,
  then among twelve reserve slots at +0x348 (offsetting their ranks by three).
  Returns the rank difference; unfound ranks remain -1.

### Hard list for M1-T1034

These four functions remain linked from the original delinked object. No
unmatched candidate bodies were retained. A human can use `tools/decompme.py`
for a scratch with the following instruction-level findings and trial results.

- `func_0211a614` (`0x0211a614`, 208 B): derives an adjustment from signed
  area byte +0x19 and unsigned byte +0x6E, multiplies an incoming integer in
  20.12 fixed point by `func_020491cc`'s result, applies multiplier 0x1266 when
  script flag 0xAC is set, then adds a randomly signed perturbation with range
  0..0x19A before shifting to integer units. Tried signed 64-bit rounded
  multiplication, an inline fixed-point helper, operand reversal, signed and
  unsigned constant suffixes, and an explicit high/low reconstruction.
  Ordinary C produced 216 B versus 208 B: constant multiplication retained
  an extra zero-high-word multiply-accumulate. Explicit reconstruction grew
  further (228/232 B). Candidate omitted.
- `func_0211b100` (`0x0211b100`, 244 B): optional work +0x50 display;
  computes an alpha byte from scale times 0x1F000, clamps it to 1..31, draws
  `data_02151cbc` at x+62, and draws resource 0x611B (0x611A when flag 0x701
  is clear) at x+107. Tried the same fixed-point expression/helper and
  constant variants as above. Ordinary C produced 252 B versus 244 B due to
  the same redundant high-word multiplication; explicit reconstruction was
  264/268 B. Candidate omitted.
- `BattleShowingTask_Unk_11d050` (`0x0211d050`, 208 B): event switch 0..4. Event 3 dispatches
  work states 7/9 through the existing 0x0211C5D0/0x0211C610 helpers after resetting
  dispatch state. Event 1 initializes two flag bytes and sixteen words on the
  stack, then calls `Unk0bc1a8_Unk_0bc514(work, 1)`. Explicit initialization
  loops, including an inline initializer, were optimized away because this
  local is unused (128 B). Aggregate zero initialization retained the local
  but emitted block stores (200 B). A volatile initializer retained loops
  but differed in register allocation; volatile was not retained in source.
- `BattleShowingTask_Unk_11c24c` (`0x0211c24c`, 260 B): current-record dispatch preparation.
  Initializes the same options shape, calls `CampStatus_Copy176(record+0x10)`,
  loads alternate resources for negative record IDs or initializes the
  embedded work +0x10 object for other IDs, then calls `func_020bcbc4(3, options)`.
  Trial loops/inline initialization and aggregate initialization differed in
  stack layout and stores. Aggregate initialization plus temporary value
  arrays produced 252 B with block zero stores instead of the original loops;
  scalar argument trials produced 288 B. Original extra stack copies likely
  require recovering the original option-construction/setter idiom. Candidate
  omitted rather than retaining artificial stack writes.

## M1-T1031 — verified matches

All eight functions below are 100% in the objdiff report. Existing C bodies already
matched; this card makes cleanup parameters and helper contracts explicit without
changing instructions. Neutral names remain because the helper semantics are not
established. Evidence is the original ARM disassembly at each entry address.

- `BattleShowingTask_Unk_11c4c4` (`0x0211c4c4`, 28 B): obtain resource 0x29
  through `func_020445f4`, then pass that result and the incoming word to
  `func_0204fed8`.
- `BattleShowingTask_Unk_1196c0` (`0x021196c0`, 32 B): clear the live-task
  handle `data_02176e70`, then tail-call `Unk02cad4_Unk_02cbdc(1)`.
- `BattleShowingTask_Unk_11b684` (`0x0211b684`, 36 B): call `func_0211a380`,
  then `Unk044394_Unk_044534` with 0x17, 0x21 and 0x29 in order.
- `ExpGauge_PlayGaugeNormal` (`0x0211985c`, 44 B): select sequence 17 on
  the +0x18 gauge animation, reset its frame to zero and start it. The count-up
  update at `0x02119a60` calls this after the level-up pause.
- `ExpGauge_PlayGaugeLevelUp` (`0x02119888`, 44 B): select sequence 16 on
  the same animation, reset its frame to zero and start it. The level-up path
  at `0x02119a60` supplies the behavioral evidence for this name.
- `ExpGauge_UpdateToNextLevel` (`0x02119910`, 48 B): store the next-level
  threshold minus (base EXP + shown EXP - accumulated thresholds) at +0x40.
  The count-up and level-up paths at `0x02119a60` call it after changing EXP.
- `BattleShowingTask_Unk_11ce80` (`0x0211ce80`, 52 B): pass the +0x04
  record-table pointer to `func_02053000`, clear it, clean up the embedded
  +0x10 object through `Unk0a163c_Unk_0a1ae0`, then clear `data_02176e74`.
  Requires a live work object; no null check precedes the first helper call.
- `BattleShowingTask_Unk_11a01c` (`0x0211a01c`, 60 B): pass each nonzero
  +0x18/+0x1c handle to `func_0205c3dc`, clearing each after its call.
  These offsets are the gauge and level-up animations used by `ExpGauge_Update`.

Hard list for M1-T1031: none of the eight requested functions remain unmatched.

## M1-T1032 — verified matches

All eight targets match at 100% in objdiff. Evidence below is the original ARM
instruction stream at each entry; unknown helper semantics retain neutral names.

- `BattleShowingTask_Unk_11c670` (`0x0211c670`, 60 B): requires a current
  record, publishes its unsigned +8 ID in slot 6, resets dispatch state, obtains
  resource 10, forwards its result and finishes with arguments (1, 0).
- `BattleShowingTask_Unk_11c5d0` (`0x0211c5d0`, 64 B): publishes the same
  record ID, resets dispatch state and passes resource 5 to `func_02065864`
  with mode 1 before finishing with (1, 0).
- `BattleShowingTask_Unk_11a8dc` (`0x0211a8dc`, 72 B): scans 15 six-byte
  entries starting at +0x268, setting flag bit 3 at entry +4 for the first ID
  matching the incoming word. No match leaves the flags unchanged.
- `func_02119a10` (`0x02119a10`, 80 B): sets the EXP increment to zero
  when gained EXP is zero, otherwise signed next-level EXP divided by 60,
  clamped to at least one. Called after a level-up by `ExpGauge_Update`.
- `ExpGauge_GetExpForNextLevel` (`0x021198b4`, 92 B): negative info +0
  selects `func_020b80c8` at initial level plus level-ups. Otherwise uses the
  curve ID and `func_020b8154`; its third argument includes level-ups only
  when state is DONE or info +2 equals the level-up count. EXP use is evidenced
  by the count-up caller `ExpGauge_Update` at `0x02119a60`.
- `BattleShowingTask_Unk_11c610` (`0x0211c610`, 96 B): publishes current
  record +8/+0x1c in slots 6/10 and converted +0x1e in slot 1, resets dispatch
  state and forwards resource 6 before finishing with (1, 0).
- `func_02119658` (`0x02119658`, 104 B): allocates an eight-byte task
  with four callback addresses from its literal pool and trailing arguments
  (8, 0, 0, 1), returning zero on allocation failure; otherwise initializes
  its two words through `BattleShowingTask_Unk_1196e0` and returns the handle.
- `func_0211c4e0` (`0x0211c4e0`, 104 B): requires a current record,
  looks up its resource, publishes ID/resource byte +2 in slots 6/7, dispatches
  resource word +0x24 bits 21..27 through `BattleShowingTask_Unk_11c4c4`
  with second argument 2, forwards the return value and finishes with the
  signed record ID. The helper's unused second argument and returned word
  are now explicit; its existing instructions remain identical.

Hard list for M1-T1032: none.

M1-T1035 review follow-up: rank sources share a typed padded rank view embedded
at work +0x12 / record +0x0A; the five ranks occupy +0x16..+0x1A /
+0x0E..+0x12. Destination ranks use the existing record fields. The draw callback
uses a dedicated typed work/handle view and a structured switch, submits six
animations, and passes floating-point unity. Message dispatch uses the shared
clear helper. Scheduler cleanup accepts either task layout via `void *`.
Direct `cmp.py` checks preserve exact matches for rank publication, drawing and
message dispatch. The fixed delink translation-unit boundary is retained.

## M1-T1036 — verified matches and hard list

Three targets are implemented in readable C and match the original ARM instructions
exactly. The four remaining targets are omitted, so they continue to link from the
original delinked object. This card is incomplete; a successful match gate checks
retained C definitions and does not imply that all seven targets were recovered.

- `func_0211b2ac` (`0x0211b2ac`, 568 B): three six-entry drawing passes.
  Entries with nonzero +6 counts submit resource 12, an ID-derived label,
  per-entry text, resource 0x6117 and their count. Entries with nonzero +0x0C
  submit the animation at work +0x2EC. Coordinates come from `data_0213ccc8`;
  scale is converted from 20.12 to float. The second pass uses explicit
  entry pointers; separate loop scopes preserve the original register allocation.
- `func_02119c80` (`0x02119c80`, 924 B): EXP-gauge drawing callback installed
  by `func_0211a058`. Draws four background parts, the clipped EXP bar (or
  sequence 7 during the level-up state), labels, level and remaining EXP,
  and an optional level-up animation. Sequence 9 supplies a 24-byte clipping
  record whose signed width is scaled by gained/required EXP and floored at
  one for a nonzero gain. Resource byte +5 chooses label color. The level-up
  count controls the level color and overlay; the level number is always drawn.
- `func_0211c960` (`0x0211c960`, 920 B): sixteen-state record-screen update.
  Initializes the negative-ID display or the embedded loader's animation,
  interpolates entrance/exit over ten frames, publishes ranks, waits for
  message/confirmation gates and calls `func_0211c6ac`. Confirmation copies
  record +0x1E into the area selection indexed by signed record +0x1B,
  updates saved coordinates and advances through the record list on exit.
  The trailing selection array has an unknown bound, and the original trusts
  the index. Separate identical dispatch cases preserve the original branches.

### Hard list for M1-T1036

A human can use `tools/decompme.py` to open scratches for these targets. No
unmatched candidate bodies, fabricated stack stores or assembly were retained.

- `func_0211a140` (`0x0211a140`, 576 B): resource/animation initialization.
  Recovered two text allocations, party label selection, formatted resource
  paths, six 24-byte entry registrations, four animation sources and seven
  animation handles. A full C candidate compiled to 572 B: the original
  computes the empty two-code-unit label's address before its two halfword
  stores, whereas C addresses the stack directly. Tried a struct, inline
  initializer and explicit pointer stores (572 B), and a two-element loop
  (592 B). Candidate omitted; the empty-label initialization idiom remains
  unresolved. The same pattern occurs in `func_0211b6a8`.
- `func_0211c6ac` (`0x0211c6ac`, 692 B): transition dispatcher for states
  4..12, using record +0x1A bits 1/2, signed +0x1B selection and +0x20/+0x24
  resource values. A complete switch candidate using the shared message
  initializer and pointer-based message submission compiled to 664 B. The
  original retains extra stack copies around the two message submissions,
  as in the M1-T1034 hard functions. A by-value message declaration conflicts
  with the existing helper contract; it was rejected and removed. Recover
  the option setter/construction contract before further instruction tuning.
- `func_0211ab2c` (`0x0211ab2c`, 1492 B): thirteen-state result-screen
  update. Instruction analysis identifies six-animation completion loops,
  four EXP-gauge creations at work +0x300, staggered fade timers, count-up
  sound handle +0x320 and final selectable-record dispatch. Two message
  blocks retain the same unresolved initialization/stack-copy pattern as
  `func_0211c6ac`. No complete C candidate or matching claim is made; full
  recovery of this function remains outstanding.
- `func_0211b6a8` (`0x0211b6a8`, 2744 B): allocates the 804-byte task,
  initializes resources, processes six reward entries, constructs text,
  aggregates fifteen auxiliary entries and computes party/reserve result
  records before publishing the task. Instruction analysis identifies
  twelve-byte source entries and twelve reserve slots. It shares both the
  empty-label initialization above and the message-construction pattern;
  the record-building and randomized award loops still need complete type
  recovery. No complete C candidate was produced; recovery remains outstanding.
- `BattleShowingTask_Unk_11c24c`: hand-matched
- `BattleShowingTask_Unk_11d050`: hand-matched
