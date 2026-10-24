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

## M1-T1113: predicates, action handling and grid initialization

Names remain neutral: instruction-level field and call evidence establishes the
operations below, but not their gameplay meanings. All pointers are borrowed.

- `Unk02f2a8_Unk_0366dc` (128 bytes): converts one tenth of the signed input
  through soft float, divides by two/three when predicates on ids 152/163 equal
  one, and clamps to at least one. Existing matched implementation retained.
- `func_02036654` (136 bytes): checks the key with 118c6c and visits seven signed
  bytes at resource-36 row offsets +0x1c..+0x22. Negative bytes are skipped;
  nonnegative n requires both 118c6c(2*n+90) and 118c6c(2*n+91). The first
  failed derived check stops traversal. Returns one only if all checks pass.
- `func_02030204` (144 bytes): returns for singleton flags +0x73e0/+0x743c equal
  to one, action +4 unequal to one, or 04b710 unequal to one. Otherwise compares
  work id +0x35c with 04bb9c's context id, selects 02fea0/0300ec and calls 0441ec
  on result one, or 030198 otherwise. Requires a writable action and singleton.
- `func_0203721c` (144 bytes): skips null position/cells, clears 0x794 work
  bytes, calls 036c48 with position, halfword id, coordinates and flag, then
  036fb8. A non-null map also invokes 0370e8 with the cell buffer. Its final
  argument is unused; the repeated position check matches the original.
- `func_02032adc` (148 bytes): polls descriptor +4 for state id +0x7478, defaulting
  to success when absent. On result one clears +0x7478/+0x7480/+0x7481/+0x7484/
  +0x7488, sets +0x73cc to two, root +0x14/+0x18/+0x1c to 1/2/0, and root
  +0x44/+0x50/+0x4c to one. State and root must be writable.
- `func_02032c0c` (148 bytes): identical callback and state-reset operation to
  032adc at a separate original address; kept as a distinct function.
- `func_02037054` (148 bytes): missing grid object accepts. Otherwise descriptor
  +0x14 selects a filter on cell byte +1: zero accepts, one requires 1, two
  accepts 1 or 3, three rejects; other selectors accept. Coordinates use the
  existing GridIndex45 contract. Map and cell storage must remain readable.
- `func_0202fe08` (152 bytes): selectors other than two return one. Selector
  two offsets the cached coordinates by direction (0: -y, 1: +x, 2: +y,
  3: -x). Out-of-grid returns one; otherwise returns 09c090(x,y,direction,1).

Hard list for M1-T1113: none. Matching uses original instruction comparisons;
no new test files are required by this card.

Validation: all eight card functions are 100% in the generated objdiff report;
match gate passes for the changed C file, checksum reports all artifacts
byte-identical, anticheat passes, and all nine existing unit tests pass.

## M1-T1114: grid handlers, counters, a task creator and a record sort

Names stay `func_<addr>`: no strings or callers establish a purpose, and
renaming would touch config/arm9/symbols.txt (protected).

- `func_0202fd64` (164 bytes): turns the cached heading by `turn` via
  `func_020361ec`, steps one cell from the cached work-area position (same
  direction table as `func_0202fe08`), returns 0 out of grid, 1 when
  `probe == 0`, else `func_0209be20(x, y)`.
- `func_020303d0` (168 bytes): allocates a 0xa0-byte task through
  `func_020611dc` with `Unk02f2a8_Unk_03034c` and the two empty callbacks,
  stores the argument and initial words (+8/+0xc = 1, +0x18 = 2), then runs
  `Call_02035db8`, `Unk_030578` and `Unk_02f378` on it. Returns 0 on failure.
- `func_020305a8` (164 bytes): picks an id from the s16 table at body+0x24 by
  bits 20..23 of the current cell word; ids >= 29 are ignored. Forced (1) calls
  `func_0205e484(id, 9)` and latches the id at +0x73d4; otherwise skipped when
  +0x73e0 is 1 or the id is already latched.
- `func_02032a40`, `func_02032b70` (156 bytes each, identical bodies): look up
  the handler slot for the cached cell (+0x7482/+0x7483) with
  `Unk09a268_Unk_09c4a8`, latch the cell's leading byte at +0x7478, clear
  +0x7480..+0x7488 and call the handler if set.
- `func_020352f4` (152 bytes): kind 0 bumps the u16 at +0x754e; other kinds
  bump row `kind`, column `slot` of the u16[3] rows at +0x751e when the enable
  byte at +0x33+kind is nonnegative; both report through `func_02030d84` with
  the work-area id at +0x35c.
- `func_0203546c` (160 bytes): zeroes `count` u16s at `dst`, then (resource 37
  loaded) copies up to 15 u16s from entry `GetRes36Unk19(idx) - 1`, holding
  resource 36 during the lookup. Returns 1 when copied.
- `func_02036fb8` (156 bytes): stable insertion sort of the 16-byte records
  after the count word, ascending by their +4 key.

Shared types: the map-block/body typedefs moved above their first use, the
body gained the s16 table at +0x24 (size guessed), `Unk02f2a8Obj39160` names
bits 20..23, and the new `Unk02f2a8GridState` view types the state that
`Unk02f2a8_Unk_034970` callers pass. The sort only matched without an explicit
`count <= 1` early return (the loop's entry test produces it).

Hard list for M1-T1114: none.

Validation: match gate (all 175 C functions in the changed file 100%), checksum
byte-identical, anticheat clean, 9 unit tests pass.

## M1-T1115: action flags, descriptor transitions and map work

All eight functions match the delinked ARM instructions at 100%. Names remain
address-based because field access and call evidence does not establish gameplay
semantics. Pointers and embedded buffers are borrowed; no ownership changes.

- `func_020300ec` (172 bytes): tests channel-zero masks in priority order:
  0xf3, 0x800, 0x400, 0x100, 0x200. A predicate result of one sets action
  +0x30/+0x20/+0x24/+0x28/+0x2c respectively and returns one. The 0x800
  and 0x400 branches also call 0441ec; no match returns zero.
- `func_02030494` (180 bytes): rejects a zero input word, looks up the map
  and cell at cached coordinates, then requires 0364bc(cell low five bits)
  to equal one and cell bit five to equal one. Missing cells reject.
- `func_02032ca0` (172 bytes): obtains the descriptor for state +0x747c,
  clears the active cell fields, then calls optional descriptor +4. Return
  zero restores root flags, clears +0x747c too, and sets +0x73cc to two.
- `func_02032d4c` (168 bytes): polls descriptor +8, treating an absent
  callback as one. Result one restores the same root and state fields;
  nonzero state +0x7498 additionally sets root +0x54 to one.
- `func_02034dd0` (192 bytes): unless +0x7400 is nonzero, rebuilds map work
  through 03721c with byte +0x5b minus one, clamped to one. Always finishes
  with ScanVisor 0a2b18. Root +0x94 supplies the halfword argument.
- `func_02034e90` (180 bytes): rebuilds the same +0x3154 work with the
  unmodified byte +0x5b; nonzero +0x7400 suppresses the call.
- `func_02034f44` (196 bytes): enters state seven, clears root +4, pins
  resource nine, selects the map table's signed halfword +0x20 or a cell's
  non-sentinel signed halfword +2, and calls 09da38 for state +0x7330.
  Releases resource nine afterward. Declaring the signed id before the
  state pointer preserves the original register assignment.
- `func_02035234` (192 bytes): absent singleton does nothing. Otherwise
  clears +0x631c/+0x7130, calls 0a6ac0 to rebuild them, then checks seven
  slots via 035c14 and appends each enabled slot through 0a7474.

Typing (attempt 2): all eight use named members, not raw offsets.
`Unk02f2a8State` now embeds `Unk02f2a8Body` at +4 (level byte `body.unk_0057` =
state +0x5b, buffer `body.unk_0214` = +0x218) and names the buffers +0x358,
+0x3134, +0x3154, +0x38e8, +0x631c, +0x7130, +0x7330 and words +0x7400,
+0x7494, +0x7498. Buffer sizes run to the next known field (guessed).
`Unk02f2a8StateRoot` gains `unk_007c`/`unk_0094`, `Unk02f2a8Action` gains
`unk_0020`..`unk_0030`. `Unk02f2a8MapEntry` (s16 +0x20) and `Unk02f2a8CellId`
(s16 +2, -1 = no override) type the records read by `func_02034f44`.

Hard list for M1-T1115: none. No new tests are required by the card; objdiff
compares every instruction against the original implementation.

## M1-T1116: direction tables, counter targets, start-up and fixed-point helpers

- `func_0203611c` (208 bytes): maps a pair of 0..3 directions to 0..3 through a
  fixed 4x4 table, 2 for pairs outside it. Written as a switch whose cases sit
  in handler-address order (1, 2, 3, 0); the `r = 2` assignments are kept so the
  compares and early exits stay as in the original.
- `func_020361ec` (220 bytes): rotates direction `dir` by `amount` through a
  second 4x4 table; callers (Unk02f2a8_Unk_02fc10 and the step helper) pass the
  cached heading. Out-of-range input returns `dir`, which is what the original
  leaves in r0.
- `func_0203572c` (244 bytes): loads a temporary map block (`Unk02f2a8MapBlock`,
  zero-initialised on the stack) keyed by the 16-byte name of resource-36 row
  `row`, reads bits 20..23 of the cell at (x, y), releases the block and returns
  the row's s16 at +0x10 for that value. C99 block-order declarations put the two
  stack initialisers after the resource call, as in the original.
- `func_02030d84` (252 bytes): counter-target check behind func_020352f4. When
  the kind-0 target (+0x7522) is set and reached and every kind 1..7 column-0
  counter reached its target, it calls 118bec(id, 1) and 0953f0; with kind 1 it
  also calls 118bec(90 + 2e + j - 1, 1) for each reached column j of a kind whose
  id e (resource-36 row copy at +0x18, byte +0x1b + kind) is nonnegative. The id
  formula is the same as in func_02036654.
- `func_0203428c` (252 bytes): creates gGameState once: 0x75c0-byte task with
  GameState_Shutdown as teardown, the three sub-objects at +0x3134/+0x3140/+0x314c,
  default words +0x73c8..+0x73ec, the root task over body +0x23c, then the
  start-up calls (resource 36, work-area id +0x35c, 052634(1, 3, 32)).
- `func_02035cb4` (260 bytes): 20.12 fixed-point interpolation
  `from + (to - from) * t / n`, with t and n converted through rounded float
  (`x * 4096 +/- 0.5`); returns `to` for n == 0 or t >= n and `from` for t <= 0.
- `func_02035db8` (268 bytes): stores the position of grid cell (x, z):
  x and z in 20.12 fixed point times 4.0, height 0x8cd.

Typing: `Unk02f2a8Res36` names the 16-byte key and the s16 table at +0x10.
`Unk02f2a8Tally` now holds the resource-36 row copy at +0x18 and a union for the
target (+0x74f2) and counter (+0x751e) tables. Both are indexed by kind with
row 0 unused, so the unused counter row overlaps the end of the target table.
`Unk02f2a8State` gains +0x3140/+0x314c and +0x73d0/+0x73d8/+0x73e8/+0x73ec.

Hard list for M1-T1116:
- `func_0202fc50` (276 bytes, action type 4 step): the structure matches
  (counter +0x1c, sub-type swing through 0205eae0 around the heading angle,
  flags +0x48/+0x4c/+0x44 at steps 3/6/8, `% 0x10000` then `+0x10000` if
  negative). It still fails because mwcc builds the negative swing constants as
  `sub rX, rZero, #K` from the zero-initialised local, while the original uses
  `mov #K; rsb` and leaves the sub-type-0 branch unpredicated. Tried: if/else
  chain, switch with and without default, else-branch zero init, swapped
  declaration order, `amp = len` copy, s16 amplitude, and the negative constants
  written as `-(int)16384.0f`, `-(0x10000 / 4)` and `0x8000 * -1`. Needs a
  decomp.me scratch.

Attempt 2 review verification: the map-work and direction-table comments now sit
directly above their respective definitions, and the fixed-point interpolation
comment explains why both helpers retain inline rounding expressions. Local
validation passed: `ninja`, anticheat, all nine unit tests, match (all 102 C
functions considered by the gate at 100%), and checksum (all artifacts identical).

## M1-T1117: 8 functions

All eight are at 100% in objdiff (match gate, checksum and anticheat pass). Every caller
(func_02031758, func_02032020, func_02032fb8, func_02033400, func_02033f1c, func_0203428c)
passes the game-state task object, so all but the last two take `Unk02f2a8State *`. Names stay
neutral: the evidence covers the shape of each function but not what it is for in the game.
- `func_02031274` (304 bytes): rebuilds the +0x5508 buffer against the Unk02e000_Unk_02e8b8
  buffer. It clears it, adds sub-objects +0x3134/+0x3140 over body map block +0x23c for
  work-area id +0x35c, then adds the seven slots that Unk02f2a8_Unk_035c14 enables.
  The 45x40 cell table at +0x38e8 ends exactly at +0x5508, and +0x5508 has the same 0xe14
  size as +0x631c, so the state view now splits there.
- `func_02031628` (304 bytes): visor refresh, called with `mode`. It is gated on +0x73e0/+0x7498
  being clear, on mode 4 not having event 12/14/37, and on body +0 being 1. It links
  +0x3134/+0x3140 for the current 04bb9c context id. Then, for each of the seven entries, it
  shows the entry (0a2a60) if its 0a03b8 descriptor +0 predicate returns 1, or hides it (0a2a8c).
- `func_02032e18` (292 bytes): mode-6 handler. A 4-step sequence on +0x7481, with frame counter
  +0x7484 (signed compare, so `s32`): free map block +0x358, reload for id +0x7480 after 3
  frames, call 0a4e9c(0) after 6 frames, then request mode 2.
- `func_02033cd0` (312 bytes): latches requested mode +0x73cc into +0x73c8 (the request resets
  to -1) and runs that mode's entry action through a jump table; case 0 is an empty case.
- `func_02033e08` (276 bytes): per-frame dispatch on +0x73c8, one helper per mode. Mode 1 arms
  root +0x44/+0x4c/+0x50/+0x54 and starts +0x7598 with 180. Mode 12 is an empty case.
- `func_02034128` (284 bytes): the second callback of the task that func_0203428c creates.
  It runs the 037d50 rebuild, updates +0x7550/+0x7598, then runs the event/visor descriptor
  callbacks (+8 for modes 3/4, +0xc for mode 5) and 12168c.
- `func_02036368` (288 bytes): writes `to * t / n` in 20.12 fixed point to obj +0x1c and
  returns 0, using the same rounded-float conversion as func_02035cb4. The out-of-range
  cases return 1. The ROM places the `t >= n` store after the main path, so the code is
  written as `if (t < n) { ...; return 0; }`.
- `func_020370e8` (308 bytes): marks records in the sorted 16-byte list whose
  [+8, +0xa] range (clamped to +-0x1555) is closed off by earlier unmarked records.
  Unk02f2a8SortEntry now types +8/+0xa as s16 and +0xc/+0xd as the s8 grid x/y;
  func_02036fb8 is still at 100%.

Shared view changes: Body +0/+0x14, Root +0x9c, State +0x5508/+0x7410/+0x7490/+0x7550,
s8 +0x7480/+0x7481, Descriptor +0 and +0xc are now function pointers, a new Unk02f2a8Lerp
view, and a real `void *Unk02e000_Unk_02e8b8(void)` prototype.

Not done in this card: none. Hard list: none.
