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

## Not done in M1-T1106
- `Unk02f2a8_Unk_033ac8`
- `Unk02f2a8_ResetField7478`
- `Unk02f2a8_GetCell38e8`
- `Unk02f2a8_GetCurrentCell38e8`
- `Unk02f2a8_Unk_034a8c`
- `Unk02f2a8_GetObj39160Bits16`
- `Unk02f2a8_GridIndex45`
- `Unk02f2a8_GetRes36Unk19`

## Not done in M1-T1107
- `Unk02f2a8_GetRes36Unk1a`
- `Unk02f2a8_GetOptSub240`
- `Unk02f2a8_GetOptSub2cc`
- `Unk02f2a8_Unk_035440`
- `Unk02f2a8_Call_02035db8`
- `Unk02f2a8_ClearEntry5e12Bit0`
- `Unk02f2a8_SetRootUnk60`
- `Unk02f2a8_IsInGrid45x40`

## Not done in M1-T1108
- `Unk02f2a8_Unk_036488`
- `Unk02f2a8_Unk_032a08`
- `Unk02f2a8_Unk_0343b4`
- `Unk02f2a8_Unk_033c94`
- `Unk02f2a8_GetRes36Unk1b`
- `Unk02f2a8_Unk_02fc10`
- `Unk02f2a8_Call_02036318`
- `Unk02f2a8_Unk_03538c`

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
- `Unk02f2a8_Unk_035440`: decompiler-derived (plain cleanup)
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
- `Unk02f2a8_ClearEntry5e12Bit0`: hand-matched
- `Unk02f2a8_SetField6138`: hand-matched
- `Unk02f2a8_Call_02035db8`: hand-matched
- `Unk02f2a8_Call_02036318`: hand-matched
- `Unk02f2a8_Unk_032a08`: hand-matched
- `Unk02f2a8_ResetField7478`: hand-matched
- `Unk02f2a8_ResetField7478Ex`: hand-matched
- `Unk02f2a8_GetCell38e8`: hand-matched
- `Unk02f2a8_GetCurrentCell38e8`: hand-matched
- `Unk02f2a8_GetObj39160Bits16`: hand-matched
- `Unk02f2a8_SetRootUnk60`: hand-matched
- `Unk02f2a8_SetField7470`: hand-matched
- `Unk02f2a8_GetOptSub240`: hand-matched
- `Unk02f2a8_GetOptSub2cc`: hand-matched
- `Unk02f2a8_Unk_035a70`: hand-matched
- `Unk02f2a8_GetRes36Unk19`: hand-matched
- `Unk02f2a8_GetRes36Unk1a`: hand-matched
- `Unk02f2a8_GetRes36Unk1b`: hand-matched
- `Unk02f2a8_Unk_035c14`: hand-matched
- `Unk02f2a8_IsInGrid45x40`: hand-matched
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
