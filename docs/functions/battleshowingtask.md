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

## Other pending functions
- `BattleShowingTask_Unk_11a8dc`: decompiler-derived

## Not done in M1-T1032
- `BattleShowingTask_Unk_11c670`
- `BattleShowingTask_Unk_11c5d0`
- `func_02119a10`
- `ExpGauge_GetExpForNextLevel`
- `BattleShowingTask_Unk_11c610`
- `func_02119658`
- `func_0211c4e0`

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
- `BattleShowingTask_Unk_11c670`: decompiler-derived (proto cleanup)
- `BattleShowingTask_Unk_11c5d0`: decompiler-derived (proto cleanup)
- `BattleShowingTask_Unk_11c610`: decompiler-derived (proto cleanup)
- `BattleShowingTask_Unk_11b4e4`: decompiler-derived (plain cleanup)
- `ExpGauge_GetExpForNextLevel`: hand-matched (ExpGauge)

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
