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

## Not done in M1-T1035
- `func_0211a504`
- `func_0211ccf8`
- `func_021196fc`
- `func_0211c350`
- `func_0211a6e4`
- `func_0211ceb4`
- `BattleShowingTask_Unk_11b4e4`

## Not done in M1-T1033
- `func_0211ce10`
- `func_0211a864`
- `func_0211aa24`
- `func_0211aaa8`
- `func_0211c548`
- `func_0211a474`
- `func_0211b1f4`
- `func_02119940`

## Not done in M1-T1034
- `func_0211a614`
- `func_0211c160`
- `func_0211d050`
- `func_0211a058`
- `func_0211a380`
- `func_0211b100`
- `func_0211a924`
- `func_0211c24c`
- `BattleShowingTask_Unk_11b4e4`: decompiler-derived (plain cleanup)

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
