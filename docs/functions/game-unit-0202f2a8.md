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

## M1-T1109: 8 functions

These were already byte-matching in the TU; this card replaced the raw
`FIELD`/pointer-offset accesses with typed struct views (`Unk02f2a8GameStateTail`
now covers +0x73DC and +0x7470..+0x748B, `Unk02f2a8Action` gains +0x9C, new
`Unk02f2a8Slots6138`), gave them real prototypes and comments. All 8 are 100%.

- `Unk02f2a8_Unk_02f8ac` (`0x0202F8AC`, 68 bytes): action type 3 of the
  dispatcher (type 4 is `Unk02f2a8_Unk_02fc10`, same `Unk02f2a8Action` object).
  Clears +0x1C, runs `ScanVisor_Unk_0a2b38` + `Unk095560_Unk_09615c`; if
  `func_021214e0(+0x18)` is nonzero, sets +0x9C to 1 and calls `func_021215d4`
  (a `GetGameState` call with unused result sits in between). Posts event 0x1B.
- `Unk02f2a8_SetField6138` (`0x0202F330`, 72 bytes): stores `v` in slot `k`
  (1..3) of the `Unk02e000_Unk_02e774` block at +0x6138/+0x613C/+0x6140; the
  setter of `Unk02f2a8_GetSlot_02f2dc`. Other `k` are ignored.
- `Unk02f2a8_ResetField7478Ex` (`0x020333B4`, 76 bytes): clears GameState
  +0x7478, +0x7480, +0x7481, +0x7484, +0x7488; unless +0x73DC is nonzero, calls
  `func_020a269c(0)`, `func_0205257c(3)`, `Unk0a4e48_Unk_0a4e9c(2)` and
  `Unk0a0ce4_Unk_0a0da4(5)`.
- `GameState_Shutdown` (`0x02034244`, 72 bytes): releases the sub-objects at
  +0x314C, +0x3140, +0x3134 and +0x73D0 in that order, then nulls `gGameState`
  (so `GameState_Exists` returns 0). Does not free the GameState block itself.
- `Unk02f2a8_SetField7470` (`0x02034D5C`, 68 bytes): sets gGameState +0x7470 to
  1 and stores the (u16, u8, u8) argument triple at +0x7474/+0x7476/+0x7477.
  The triple's meaning is not established.
- `Unk02f2a8_Unk_035a70` (`0x02035A70`, 72 bytes): fills a zeroed 8-byte
  `Unk02f2a8Pos` through `func_02035890(&pos, a)`, applies its id via
  `Unk02f2a8_SetField35c` and its x/y/word via `Unk02f2a8_SetGridPos`, and
  returns `func_02035890`'s result.
- `Unk02f2a8_Unk_035c14` (`0x02035C14`, 72 bytes): reads the signed id byte
  +0x1B+j of resource-36 entry i; negative gives 0, otherwise returns
  `Unk0e5fb8_Unk_0e63c8(id)`.
- `Unk02f2a8_DirToAngle` (`0x020360D8`, 68 bytes): direction index to 16-bit
  binary angle (1→0, 2→0x4000, 3→0x8000, 0→0xC000, else 0). Name evidence:
  `Unk02f2a8_Unk_035ec4` stores the result in a u16 angle field at +0x18.

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
- `Unk02f2a8_Unk_032f3c`: rewritten with typed state fields in M1-T1112
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

## M1-T1110: eight state, grid and dispatch helpers

All eight C bodies are at 100% objdiff and read their fields through typed views:
the work area, `Unk02f2a8Action`, `Unk02f2a8State`/`Unk02f2a8StateRoot` (034b24,
03064c, 0306a8), `Unk02f2a8Slots6138` (GetSlot_02f2dc) and `Unk02f2a8Body` with its
s8 id array at +0x30 and two `Unk02f2a8MapBlock`s at +0x23c/+0x2c8 (034970, cell
bits via `Unk02f2a8Obj39160`). In 0302f4 the empty `case 5` is kept so the jump
table spans 0..5 like the original. The names are retained;
neutral names indicate that field semantics are not established. No hard functions
remain for this card. No module boundary changes were needed.

- `Unk02f2a8_SetField35c` (80 bytes): rejects unsigned ids >=90, stores the id
  at work-area +0x35c, tests its flag and sets it when clear. Returns one only
  when setting a previously clear flag. The store offset supports the name.
- `Unk02f2a8_SetGridPos` (80 bytes): `IsInGrid45x40` validates x/y before stores
  to signed bytes +0x364/+0x365 and +0x366/+0x367, followed by the direction
  word at +0x358. Returns one on success and zero without stores on failure.
  The validation and paired coordinate stores support the grid name.
- `Unk02f2a8_GetSlot_02f2dc` (84 bytes): reads words +0x6138/+0x613c/+0x6140
  from the borrowed 02e774 block for selectors 1/2/3; other selectors return
  zero. The paired `SetField6138` writes the same offsets.
- `Unk02f2a8_Unk_034970` (84 bytes): returns borrowed p+572 by default. The
  grid object at x/y supplies bits 16..19 of its +4 word; a nonzero value n
  selects signed byte p+48+n-1. When that id is nonnegative and 0e63c8 returns
  nonzero, returns p+712 instead. The map-block semantics remain unknown.
- `Unk02f2a8_Unk_0302f4` (88 bytes): dispatches action +0x10: zero sets +0x14
  to one; 1/2/3/4 call 030204/02f530/02f8f0/02fc50 respectively. All other
  selectors return without a handler. Requires a valid action pointer.
- `Unk02f2a8_Unk_034b24` (88 bytes): returns zero if state +0x73e0 equals
  one, +0x73c8 differs from two, or root +0x10 differs from one; otherwise
  returns whether root +4 is nonzero. Requires the singleton and its root.
- `Unk02f2a8_Unk_03064c` (92 bytes): sets state +0x73e0 to one, clears root
  +4/+0x4c, sets state +0x757c to four, resets the object at +0x7598, calls
  the visor refresh pair, then calls 0a2a8c for indices 0 through 6.
- `Unk02f2a8_Unk_0306a8` (92 bytes): sets root +0x4c/+0x54/+0x44/+0x50
  to one, clears root +0x38/+0x34 and state +0x73e0/+0x73e4, then calls
  0caf78, 0a0d30(1) and 0caf88 in order. The caller 032a08 uses this before
  invoking 0305a8 with type one; no stronger semantic name is established.

## M1-T1111: eight counter, dispatch and forwarding helpers

All eight inherited C bodies already matched at the start of this card. Their
instruction output remains 100% after documenting contracts and replacing the
integer context addresses in 02f378 and 030d20 with byte pointers. The latter is
void: it has no result of its own, and caller 033c94 discards the call result.
No module boundary changes or new semantic names are introduced. The evidence
below is the delinked instruction/field access sequence verified by objdiff.

- `Unk02f2a8_Unk_02f378` (96 bytes): when context +0x60 equals one,
  increments the unsigned counter +0x6c only below limit +0x68. Otherwise
  decrements it only when positive as a signed word. Calls 036368 with
  +0x7c and words +0x64/+0x68/+0x6c, then 035edc with +0x7c/+0x70.
  The context and both sub-blocks must exist; their gameplay meaning is unknown.
- `Unk02f2a8_ApplyPending` (96 bytes): copies pending word +0x14 to current
  +0x10, then resets +0x14 to -1. Action one sets +0x5c/+0x50 to one;
  actions two, three and four call 02f3d8, 02f8ac and 02fc10. Other values
  do nothing after the copy. The pending check in 03034c and this dispatch
  support the existing descriptive name. Requires a valid action context.
- `Unk02f2a8_Unk_0308c0` (100 bytes): copies 16 bytes from context +0x40
  into a zero-initialized 17-byte stack buffer and calls 039520 with the
  context and buffer. The last byte stays zero; the source need not contain
  a terminator. The callee borrows the buffer for the call.
- `Unk02f2a8_Unk_030d20` (100 bytes): calls the visor helper 0a2b38,
  selects mode one for argument one and mode two otherwise, calls 03480c
  with context +4 and one, then resets +0x7550 and +0x7598 through 09974c
  and 11f2d0. Calls 096130, 065eac, 0964f8 and 0a2414 in that order.
  Requires a live context; caller 033c94 invokes this before releasing it.
- `Unk02f2a8_Unk_0313a4` (100 bytes): obtains cell bits through
  GetObj39160Bits16 using context +0x240 and signed coordinates
  +0x744e/+0x744f. Reads 02e8b8 and work-area halfword +0x35c, then
  calls 0a7474 with context +0x5508, that result, +0x240, +0x18,
  the halfword, cell bits and one. Context and work-area storage are borrowed.
- `Unk02f2a8_Unk_035b74` (100 bytes): opens resource 36, obtains its data
  and row count, and counts rows whose signed byte +0x19 equals the argument.
  The stride is 40 bytes. Its u8 index wraps at 256, so termination requires
  fewer than 256 rows; no new bound or fallback is added.
- `Unk02f2a8_Unk_030704` (104 bytes): copies exactly 16 readable signed
  bytes into a zero-initialized 17-byte stack buffer, then calls 038ff8
  with arguments one, the buffer, four and five. Argument three is unused;
  argument five is a byte. The buffer is borrowed only during the call.
- `Unk02f2a8_Unk_030198` (108 bytes): returns zero if 04b4c4 rejects the
  context. Otherwise 04ca1c selects which word to set to one: +0x20 for
  selectors 0/1/2, +0x28 for five, +0x2c for four. Returns one for these
  selectors and zero for all others. Requires writable context storage.

Validation: match gate (all eight 100%), full build through match/checksum,
anticheat, nine existing unit tests, and byte-identical checksum artifacts.
No new tests are required by this matching card; objdiff checks the original
instruction output. Hard list for M1-T1111: none.

## M1-T1112: resource lookups, map-cell queries and one point helper
Seven of these were already matched by a hand wave but used raw `FIELD`
offsets; they now use typed local views. Extended `Unk02f2a8Res36` (+0x18
byte), `Unk02f2a8Action` (+0 word), `Unk02f2a8StateRoot` (+0x14..+0x1c),
`Unk02f2a8State` (+0x7478..+0x748b) and `Unk02f2a8MapBlock` (+0 word, +4
table pointer). `Unk02f2a8StateBody` is gGameState as root plus
`Unk02f2a8Body`, so `gGameState + 0x240/0x244` are block +0x23c words.

- `Unk02f2a8_Unk_03550c` (108 bytes): clears n halfwords at dst (008644),
  then copies resource 38's record for key (04fe68 row 0, 04fed8 lookup)
  into dst, at most 5 halfwords. Returns 1 when copied, 0 otherwise.
- `Unk02f2a8_Unk_035b08` (108 bytes): first resource 36 row whose signed
  bytes +0x19/+0x1a equal a/b; returns 0 when none matches.
- `Unk02f2a8_Unk_035820` (112 bytes): first resource 36 row with byte
  +0x18 == 1 and signed byte +0x19 == a; u8 index (wraps at 256), 0 if none.
- `func_02036068` (112 bytes): dx/dz between words +0/+8 of two points; zero
  when both are zero, else 020024f8(dz, dx) is passed by address to 02051b18
  with -step, -0x8000, 0x8000 and 2; returns the low 16 bits signed. It looks
  like an angle step, but the callees are unnamed, so the symbol stays as is.
  The `dx` local must be declared first or the two loads swap.
- `Unk02f2a8_Unk_03034c` (124 bytes): if an action is pending (+0x14 != -1)
  and 04b710 returns 1 or 04ca1c returns -1, ApplyPending runs. Then calls
  0302f4 and 02f378, then 0209aca0 with word +0 and work-area bytes
  +0x364/+0x365, then 116598.
- `Unk02f2a8_Unk_032f3c` (124 bytes): calls 05257c(4), 0a4e9c(3), 05e590(9)
  and ScanVisor 0a2660, then arms the root request with (0x800, 15). Clears
  state +0x7478..+0x748b, sets root +0x14/+0x18/+0x1c to 1/2/0, and ends
  with 0a0da4(8).
- `Unk02f2a8_Unk_0349c4` (128 bytes): defaults to work-area id +0x35c. A
  cell in block +0x23c with nonzero bits 16..19 selects signed id
  `unk_0030[n-1]`; a nonnegative id with a positive 0e63c8 count m returns
  `id*2 + 90 + m - 1`.
- `Unk02f2a8_Unk_0351b4` (128 bytes): needs gGameState and a nonzero block
  +0x23c word. Positive 034a8c result n (block chosen by 034970) indexes byte
  n+15 of block +0x23c's table, which goes to 0987ac(3, byte). Otherwise 0.
  The index must be written as `(table + n)[15]` to keep `add; ldrb #15`.

Validation: match gate (all 205 functions in the changed file 100%), checksum
byte-identical, anticheat clean, 9 unit tests pass. Hard list for M1-T1112: none.
