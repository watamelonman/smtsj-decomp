# unit_0202f2a8

## M1-T1104: 8 small functions

- `Unk02f2a8_Nop_0303c8` (4 bytes): empty callback; compiles to a bare return.
- `Unk02f2a8_Nop_0303cc` (4 bytes): empty callback paired with the slot above.
- `Unk02f2a8_Nop_035430` (4 bytes): empty callback at 0x035430.
- `Unk02f2a8_Thunk_0203428c` (12 bytes): forwarder to `func_0203428c`; name is the
  address of the target, no semantic evidence.
- `Unk02f2a8_Thunk_0206146c` (12 bytes): forwarder to `func_0206146c`; same rationale.
- `GetGameState` (16 bytes): returns the global game-state pointer `gGameState`
  (BSS 0x0215DD2C); callers at 0x0202F378 and 0x020352F4 rely on the singleton.
- `Unk02f2a8_Call_02057660` (20 bytes): invokes `func_02057660(2, 0)`; the constants
  are the SDK call's fixed range, so the name stays neutral.
- `GameState_GetUnkField74f4` (24 bytes): reads the u16 at `gGameState + 0x74F4`; a null
  check would add code, so the original clearly assumes the singleton exists.

All eight are hand-matched and at 100% in objdiff. The `Not done in ...` lists below
record the other cards that worked on this translation unit.

## M1-T1105: 8 small functions

Earlier hand-match waves had already brought all eight to 100%. This card gives the four
decompiler-derived ones typed parameters (small local structs, no raw `int` offsets) and
comments. All eight are still at 100% in objdiff.
- `GameState_GetUnkField74f6` (24 bytes): returns the u16 `gGameState->unk_74f6`.
- `Unk02f2a8_Unk_035ec4` (24 bytes): `obj->unk_0018 = Unk02f2a8_DirToAngle(dir)`. This stores
  a 16-bit angle for a direction code 0..3. The name stays neutral because the object type is unknown.
- `Unk02f2a8_Unk_030478` (28 bytes): if `obj` is non-null, sets `obj->unk_0014 = 5` and calls
  `func_02061424` (obj still in r0). Its only caller is `Unk02f2a8_Unk_033c94`.
- `Unk02f2a8_Unk_030578` (28 bytes): calls 035ec4 on `&obj->unk_007c` with the work-area
  direction word at +0x358.
- `GameState_GetBody` (28 bytes): returns `gGameState->unk_0004`, or 0 when no GameState exists.
- `GameState_Exists` (28 bytes): `gGameState != 0`.
- `GameState_ClearRootUnk60` (28 bytes): `gGameState->root->unk_60 = 0`. It undoes
  `Unk02f2a8_SetRootUnk60`, which sets the flag to 1 and stores two args at +0x64/+0x68.
- `Unk02f2a8_Unk_033890` (32 bytes): zeroes the GameState fields at +0x7478, +0x7480,
  +0x7481, +0x7484 and +0x7488. It uses `FIELD` because `include/GameState.h` (not owned by this
  card) still pads that range.

## M1-T1106: 8 small functions

All eight were already hand-matched; this card verified them at 100% in objdiff,
gave each a typed signature and replaced the remaining raw offsets. Names stay
neutral/hedged because no string or caller establishes a gameplay meaning
beyond the observed field and grid uses below.
- `Unk02f2a8_Unk_033ac8` (`0x02033ac8`, 32 bytes): zeroes the five grid fields at
  +0x7478, +0x7480, +0x7481, +0x7484 and +0x7488 on the game state passed in r0
  (offset 0x7000 plus 0x478/0x480/0x481/0x484/0x488 in the instruction stream).
  The body is byte-identical to `Unk02f2a8_Unk_033890`; both addresses are kept
  as separate symbols.
- `Unk02f2a8_ResetField7478` (`0x02032df4`, 36 bytes): clears the u32 at +0x7478,
  the byte at +0x7481 and the u32 at +0x7484, then calls
  `Unk0a4e48_Unk_0a4e9c(2)`. Unlike `...ResetField7478Ex` it leaves +0x7480 and
  +0x7488 untouched.
- `Unk02f2a8_GetCell38e8` (`0x02034a44`, 36 bytes): calls `GridIndex45` and
  returns a borrowed pointer to the 4-byte cell at `gGameState + 0x38E8 +
  index * 4`. Out-of-range coordinates therefore alias cell 0.
- `Unk02f2a8_GetCurrentCell38e8` (`0x02034a68`, 36 bytes): loads the signed
  bytes at +0x7482/+0x7483 as the current coordinates and tail-calls
  `Unk02f2a8_GetCell38e8`.
- `Unk02f2a8_Unk_034a8c` (`0x02034a8c`, 36 bytes): grid lookup through
  `Unk038fbc_Unk_039160`, then returns bits 12..15 of the looked-up object's u32
  at +4 (`lsl #16; lsr #28`), or 0 when there is no object.
- `Unk02f2a8_GetObj39160Bits16` (`0x02034ab0`, 36 bytes): the same lookup and
  null handling, returning bits 16..19 instead (`lsl #12; lsr #28`). The bit
  field meaning is not established, hence the neutral name.
- `Unk02f2a8_GridIndex45` (`0x02035c90`, 36 bytes): returns `y * 45 + x` when
  `Unk02f2a8_IsInGrid45x40` accepts the pair, else 0. Callers cannot distinguish
  the valid cell (0, 0) from an out-of-range pair.
- `Unk02f2a8_GetRes36Unk19` (`0x02035ab8`, 40 bytes): opens resource 36 with
  `func_020445d0(36, 0)`, gets its 40-byte entry table from `func_0204fde0`
  and returns the signed byte at +0x19 of entry `i`. The field meaning is not
  established; callers use it as a small id/selector.

## M1-T1107: 8 small functions

All eight are at 100% in objdiff, with typed signatures and behaviour comments in
`src/game/unit_0202f2a8.c`. The names stay neutral because no string or caller
establishes a gameplay meaning beyond the observations below.
- `Unk02f2a8_GetRes36Unk1a` (`0x02035ae0`, 40 bytes): opens resource 36 with
  `func_020445d0(36, 0)`, fetches the 40-byte entry table via `func_0204fde0`
  and returns the signed byte at +0x1a of entry `i`. The caller in
  `src/game/unit_021124f0.c` compares it with 1, so it acts as a small
  selector; the field itself is unnamed.
- `Unk02f2a8_GetOptSub240` (`0x020353cc`, 44 bytes): returns a borrowed pointer
  to `gGameState + 0x240` when the game state exists and its word at +0x240 is
  nonzero; otherwise null. A local typed view covers +0x240 because
  `include/GameState.h` (not owned by this card) pads that range.
- `Unk02f2a8_GetOptSub2cc` (`0x020353f8`, 44 bytes): the same optional-block
  contract for `gGameState + 0x2cc`, through the same local typed view.
- `Unk02f2a8_Unk_035440` (`0x02035440`, 44 bytes): maps selector 0 to 1, calls
  `Unk02f2a8_Unk_035a70(selector)` with `0x24` passed to
  `Unk044394_Unk_044428` before it and to `Unk044394_Unk_044534` after it, then
  calls `func_020f43d4`. Its callers pass the work word at +8
  (`src/ImageBgDual3D.c`, `src/game/unit_02116598.c`); the selector and channel
  meanings are not established.
- `Unk02f2a8_Call_02035db8` (`0x02030548`, 48 bytes): calls `func_02035db8`
  with `p + 0x70` and the signed work bytes at +0x364/+0x365, read through a
  local typed view of the work area. The work-area accessor is called twice,
  once per coordinate, matching the original instruction stream.
- `Unk02f2a8_ClearEntry5e12Bit0` (`0x0202f2a8`, 52 bytes): clears bit 0 of
  byte `i` in the 64-entry table at the `Unk02e000_Unk_02e774` block +0x5e12.
  Ids outside 0..63 are ignored.
- `Unk02f2a8_SetRootUnk60` (`0x02034ad4`, 52 bytes): sets the root flag at
  +0x60 to 1 via `gGameState->root->unk_60` and stores the two arguments at
  +0x64/+0x68 through a local typed view of the root tail. It is the setter
  paired with `GameState_ClearRootUnk60`.
- `Unk02f2a8_IsInGrid45x40` (`0x02035c5c`, 52 bytes): returns 1 exactly when
  `0 <= x < 45` and `0 <= y < 40`; both comparisons are signed, so negative
  coordinates are rejected before `Unk02f2a8_GridIndex45` multiplies them.

## M1-T1108: 8 functions

All eight are at 100% in objdiff. The bodies were decompiler-derived; they now use
typed local views and carry behaviour comments. Names stay neutral because no string or
caller establishes a gameplay meaning beyond the observations below.
- `Unk02f2a8_Unk_036488` (`0x02036488`, 52 bytes): resets the two 16-bit work-area
  fields at +0xAF2/+0xAF4; the value at +0xAF2 becomes 0 and +0xAF4 is reseeded with
  `func_02050088(1, 50, 100)`, the shared random helper called with an inclusive
  50..100 range (same helper as `func_02044488` in `unit_02044394.c`).
- `Unk02f2a8_Unk_032a08` (`0x02032A08`, 56 bytes): takes the task pointer `p`; calls
  `func_0209e0b0`, bails out when `Unk095560_Thunk_020961a0` reports busy, otherwise
  arms the task through `Unk02f2a8_Unk_0306a8`, runs the type-1 branch of
  `func_020305a8(p, 1)` and notifies subsystem 1.
- `Unk02f2a8_Unk_0343b4` (`0x020343B4`, 56 bytes): releases the counted entries of an
  object whose count is the signed word at +8, calling `func_0205bb68` once per live
  entry, then zeroes the count. The count is re-read every iteration.
- `Unk02f2a8_Unk_033c94` (`0x02033C94`, 60 bytes): cleanup path for a task context.
  It calls `Unk02f2a8_Unk_030d20(ctx, 1)`, `Unk095560_Unk_0956a8`,
  `Unk044394_Unk_044534(0x24)`, resets the object in the context's first word through
  `Unk02f2a8_Unk_030478`, releases the context with `func_02061424`, then calls
  `func_020572c0` and `func_0205e590(0)`.
- `Unk02f2a8_GetRes36Unk1b` (`0x02035BD8`, 60 bytes): returns the signed byte at
  +0x1B + j of entry i in resource 36's 40-byte entry table. This is the indexed
  sibling of `GetRes36Unk19`/`GetRes36Unk1a`; a negative byte becomes the -1 invalid-id
  sentinel (`Unk02f2a8_Unk_035c14` applies the same test but maps it to 0).
- `Unk02f2a8_Unk_02fc10` (`0x0202FC10`, 64 bytes): folds the action's +0x18 word into
  the work-area direction word at +0x358 through `func_020361ec`, clears the action's
  +0x1C word, then calls `ScanVisor_Unk_0a2b38`,
  `Unk095560_Unk_09615c` and posts event 0x2C through `Unk0a0ce4_Unk_0a0da4`.
  The work area accessor is called twice, once for the destination and once for the
  source word, matching the original instruction stream.
- `Unk02f2a8_Call_02036318` (`0x02031408`, 64 bytes; delink name retained): forwards
  the signed grid coordinates cached at GameState +0x744E/+0x744F to
  `Unk02f2a8_SetGridPos`. The direction word at +0x7450 overrides the work-area word
  at +0x358 unless it equals the -1 sentinel.
- `Unk02f2a8_Unk_03538c` (`0x0203538C`, 64 bytes): samples the shared 0..15 table slot
  from `Unk03e43c_Unk_03fa28`, stores it at GameState +0x74F0, advances the frame
  counter, and samples the slot again. If the slot changed, it calls
  `Unk094fe0_Unk_0952ac` to tick the slot timers; both the game state and slot are
  re-read after the advancing call.

## Not done in M1-T1109
- `Unk02f2a8_Unk_02f8ac`
- `Unk02f2a8_SetField7470`
- `Unk02f2a8_DirToAngle`
- `Unk02f2a8_SetField6138`
- `GameState_Shutdown`
- `Unk02f2a8_Unk_035a70`
- `Unk02f2a8_Unk_035c14`
- `Unk02f2a8_ResetField7478Ex`

## Not done in M1-T1110
- `Unk02f2a8_SetField35c`
- `Unk02f2a8_SetGridPos`
- `Unk02f2a8_GetSlot_02f2dc`
- `Unk02f2a8_Unk_034970`
- `Unk02f2a8_Unk_0302f4`
- `Unk02f2a8_Unk_034b24`
- `Unk02f2a8_Unk_03064c`
- `Unk02f2a8_Unk_0306a8`

## Not done in M1-T1111
- `Unk02f2a8_Unk_02f378`
- `Unk02f2a8_ApplyPending`
- `Unk02f2a8_Unk_0308c0`
- `Unk02f2a8_Unk_030d20`
- `Unk02f2a8_Unk_0313a4`
- `Unk02f2a8_Unk_035b74`
- `Unk02f2a8_Unk_030704`
- `Unk02f2a8_Unk_030198`

## Not done in M1-T1112
- `Unk02f2a8_Unk_03550c`
- `Unk02f2a8_Unk_035b08`
- `Unk02f2a8_Unk_035820`
- `func_02036068`
- `Unk02f2a8_Unk_03034c`
- `Unk02f2a8_Unk_032f3c`
- `Unk02f2a8_Unk_0349c4`
- `Unk02f2a8_Unk_0351b4`

## Not done in M1-T1113
- `Unk02f2a8_Unk_0366dc`
- `func_02036654`
- `func_02030204`
- `func_0203721c`
- `func_02032adc`
- `func_02032c0c`
- `func_02037054`
- `func_0202fe08`

## Not done in M1-T1114
- `func_020352f4`
- `func_02032a40`
- `func_02032b70`
- `func_02036fb8`
- `func_0203546c`
- `func_0202fd64`
- `func_020305a8`
- `func_020303d0`

## Not done in M1-T1115
- `func_02032d4c`
- `func_020300ec`
- `func_02032ca0`
- `func_02030494`
- `func_02034e90`
- `func_02034dd0`
- `func_02035234`
- `func_02034f44`

## Not done in M1-T1116
- `func_0203611c`
- `func_020361ec`
- `func_0203572c`
- `func_02030d84`
- `func_0203428c`
- `func_02035cb4`
- `func_02035db8`
- `func_0202fc50`

## Not done in M1-T1117
- `func_02033e08`
- `func_02034128`
- `func_02036368`
- `func_02032e18`
- `func_02031274`
- `func_02031628`
- `func_020370e8`
- `func_02033cd0`

## Not done in M1-T1118
- `func_0203480c`
- `func_0203076c`
- `func_0202f3d8`
- `func_02030bb0`
- `func_02035edc`
- `func_0203675c`
- `func_020368e8`
- `func_020364bc`
- `Unk02f2a8_Unk_035ec4`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_030578`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_030478`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_033890`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_033ac8`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_034a8c`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_036488`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_0343b4`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_033c94`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_02fc10`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_02f8ac`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_0302f4`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_03064c`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_0306a8`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_02f378`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_032f3c`: decompiler-derived (plain cleanup)
- `Unk02f2a8_Unk_03538c`: decompiler-derived (plain+fix cleanup)
- `Unk02f2a8_Unk_030d20`: decompiler-derived (plain+fix cleanup)
- `GameState_Shutdown`: hand-written. GameState_Shutdown + GameState_Exists (gGameState teardown / null check).
- `GameState_GetBody`: hand-matched
- `GameState_ClearRootUnk60`: hand-matched
- `GameState_GetUnkField74f6`: hand-matched
- `Unk02f2a8_SetField6138`: hand-matched
- `Unk02f2a8_Call_02036318`: hand-matched
- `Unk02f2a8_Unk_032a08`: hand-matched
- `Unk02f2a8_ResetField7478`: hand-matched
- `Unk02f2a8_ResetField7478Ex`: hand-matched
- `Unk02f2a8_GetCell38e8`: hand-matched
- `Unk02f2a8_GetCurrentCell38e8`: hand-matched
- `Unk02f2a8_GetObj39160Bits16`: hand-matched
- `Unk02f2a8_SetField7470`: hand-matched
- `Unk02f2a8_Unk_035a70`: hand-matched
- `Unk02f2a8_GetRes36Unk19`: hand-matched
- `Unk02f2a8_GetRes36Unk1b`: hand-matched
- `Unk02f2a8_Unk_035c14`: hand-matched
- `Unk02f2a8_GridIndex45`: hand-matched
- `Unk02f2a8_DirToAngle`: hand-matched
- `Unk02f2a8_SetField35c`: hand-matched
- `Unk02f2a8_SetGridPos`: hand-matched
- `Unk02f2a8_GetSlot_02f2dc`: hand-matched
- `Unk02f2a8_Unk_030198`: hand-matched
- `Unk02f2a8_ApplyPending`: hand-matched
- `Unk02f2a8_Unk_03034c`: hand-matched
- `Unk02f2a8_Unk_030704`: hand-matched
- `Unk02f2a8_Unk_0308c0`: hand-matched
- `Unk02f2a8_Unk_0313a4`: hand-matched
- `Unk02f2a8_Unk_034970`: hand-matched
- `Unk02f2a8_Unk_0349c4`: hand-matched
- `Unk02f2a8_Unk_034b24`: hand-matched
- `Unk02f2a8_Unk_0351b4`: hand-matched
- `Unk02f2a8_Unk_03550c`: hand-matched
- `Unk02f2a8_Unk_035820`: hand-matched
- `Unk02f2a8_Unk_035b08`: hand-matched
- `Unk02f2a8_Unk_035b74`: hand-matched
- `Unk02f2a8_Unk_0366dc`: hand-matched
