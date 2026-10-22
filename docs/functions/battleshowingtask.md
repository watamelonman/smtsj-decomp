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
- `BattleShowingTask_Unk_11c4c4`: decompiler-derived
- `BattleShowingTask_Unk_11b684`: decompiler-derived
- `BattleShowingTask_Unk_11ce80`: decompiler-derived
- `BattleShowingTask_Unk_11a01c`: decompiler-derived

## Not done in M1-T1031
- `BattleShowingTask_Unk_1196c0`
- `ExpGauge_PlayGaugeNormal`
- `ExpGauge_PlayGaugeLevelUp`
- `ExpGauge_UpdateToNextLevel`
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
- `ExpGauge_PlayGaugeNormal`: hand-matched (ExpGauge)
- `ExpGauge_PlayGaugeLevelUp`: hand-matched (ExpGauge)
- `ExpGauge_GetExpForNextLevel`: hand-matched (ExpGauge)
- `ExpGauge_UpdateToNextLevel`: hand-matched (ExpGauge)
- `BattleShowingTask_Unk_1196c0`: hand-matched
