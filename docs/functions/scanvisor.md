# ScanVisor

## M1-T983: small ARM helpers

Names retain the configured symbols. Evidence below comes from the delinked
`src/ScanVisor.o`; field descriptions do not imply established gameplay meaning.
The source and the eight implementations already existed when this card began.

- `ScanVisor_Nop_0a34a4` (0x020a34a4, 4 bytes): only `bx lr`.
  `ScanVisor_Draw` passes its visor pointer; this callback intentionally does nothing.
- `ScanVisor_Nop_0a34a8` (0x020a34a8, 4 bytes): only `bx lr`.
  The second empty callback also receives the pointer from `ScanVisor_Draw`.
- `ScanVisor_GetConst20` (0x020a2bb0, 8 bytes): `mov r0, #20; bx lr`.
  No parameters; the query returns 20 without accessing state.
- `ScanVisor_Unk_0a45f8` (0x020a45f8, 8 bytes): `ldr r0, [r0, #0x14]; bx lr`.
  Requires a valid object and returns its unsigned word at +0x14; semantic name unknown.
- `ScanVisor_GetConst6` (0x020a4e40, 8 bytes): `mov r0, #6; bx lr`.
  No parameters; the query returns 6 without accessing state.
- `ScanVisor_Thunk_020fc6b8` (0x020a28e8, 12 bytes): loads `ip` from a
  literal with an ABS32 relocation to `Unk0fc584_SetDir`, then `bx ip`.
  The C no-argument forwarding call preserves this tail-call implementation.
- `ScanVisor_GetSlot` (0x020a42b8, 12 bytes): adds `index << 2` to the
  object pointer and loads the word at +0x1c0. Caller supplies a valid table
  index and object; no check exists in the original. The declaration's 16-word
  extent is inherited and is not established by this accessor alone.
- `ScanVisor_SetRange` (0x020a43dc, 12 bytes): stores r1 at +0x1c and r2
  at +0x20, then returns. Requires a valid writable record. The existing range
  symbol is retained; units and ordering constraints are unknown.

Validation: all eight functions report 100% in `build/report.json`; the match
gate, anticheat gate, nine unittest tests, and original-image checksum gate pass.
No new tests were required by this card; objdiff checks the instruction behavior.

No hard functions for M1-T983.

## M1-T984: setters, thunks and work-object getter

Names retain the configured symbols. Field stores and call shapes come from the
delinked `src/ScanVisor.o`; they do not establish further gameplay meaning.

- `ScanVisor_SetUnkFields24_28` (0x020a43e8, 12 bytes): `str r1,[r0,#36];
  str r2,[r0,#40]; bx lr`. Stores the caller's pair in a slot record at
  +0x24/+0x28. `ScanVisor_Unk_0a4864` passes (8, 0) and `ScanVisor_Unk_0a42f0`
  passes (0, 0); the value units remain unknown.
- `ScanVisor_Unk_0a4904` (0x020a4904, 12 bytes): `mov r1,#1;
  str r1,[r0,#444]; bx lr`. Sets the word at +0x1bc to 1 on the list object;
  `ScanVisor_Unk_0a2920` passes base+0x24c.
- `ScanVisor_ClearUnkField198` (0x020a4988, 12 bytes): `mov r1,#0;
  str r1,[r0,#408]; bx lr`. Clears +0x198 on the list object passed at
  base+0x24c by `ScanVisor_Unk_0a2acc` and `ScanVisor_Unk_0a2b7c`.
- `ScanVisor_Thunk_020a4600` (0x020a49cc, 12 bytes): `ldr ip,[pc]; bx ip`
  with an ABS32 relocation to `ScanVisor_AnySlotField14` (0x020a4600). The
  typed `u8 *` parameter explicitly forwards the borrowed list pointer and
  the thunk returns the callee's integer 0/1 result. The caller at 0x020a35bc
  passes base+0x24c, calls at 0x020a35c0, and compares r0 with zero at
  0x020a35c4, establishing that the return value must be preserved.
- `ScanVisor_Get_data_02176b04` (0x020a2cfc, 16 bytes): `ldr r0, literal;
  ldr r0,[r0]; bx lr`, returning the bss word at 0x02176b04. Callers
  null-check it before using the result as the work-object base.
- `ScanVisor_Unk_0a3620` (0x020a3620, 16 bytes): `ldr ip,[pc,#4];
  add r0,r0,#588; bx ip` to `ScanVisor_Unk_0a4a44`. Forwards the list object
  at base+0x24c; `ScanVisor_Draw` supplies the visor pointer.
- `ScanVisor_Unk_0a465c` (0x020a465c, 16 bytes): `mov r1,#0;
  str r1,[r0,#16]; str r1,[r0,#20]; bx lr`. Clears the two words at
  +0x10/+0x14 on the idle slot returned by `ScanVisor_FindSlotByKey`.
- `ScanVisor_Unk_0a4a30` (0x020a4a30, 20 bytes): `ldr ip,[pc,#8];
  mov r1,#1; mov r2,r1; bx ip` to `ScanVisor_Unk_0a4950`. Forwards the list
  object at base+0x24c with arguments (1, 1); the callee owns all stores.

Validation: all eight functions report 100% in `build/report.json` after
re-typing their parameters; the match gate, anticheat gate and original-image
checksum gate pass. No new tests were required by this card.

No hard functions for M1-T984.

## M1-T985: work-object wrappers, list updates and slot helpers

Names retain the configured symbols; the wrappers all use the work-object word
returned by `ScanVisor_Get_data_02176b04` and no-op when it is null. Evidence is
from the delinked `src/ScanVisor.o`; none of these functions establishes a
higher-level gameplay meaning.

- `ScanVisor_Unk_0a4644` (0x020a4644, 24 bytes): `cmp r1,#0; movne r1,#13;
  strne r1,[r0,#16]; mov r1,#1; str r1,[r0,#20]; bx lr`. Requires a valid slot
  record and marks it active by storing 1 at +0x14; when the second parameter
  is non-zero it also stores 13 at +0x10. `ScanVisor_SetById` passes the slot
  returned by `ScanVisor_FindSlotByKey` and its own `on` flag.
- `ScanVisor_Unk_0a4a18` (0x020a4a18, 24 bytes): looks up `id` with
  `ScanVisor_FindSlotByKey` on the supplied list and, when found, calls
  `ScanVisor_Unk_0a465c` to clear the slot's +0x10/+0x14 words. A missing slot
  is a no-op. The caller at 0x020a2a8c passes work+0x24c.
- `ScanVisor_Unk_0a2a1c` (0x020a2a1c, 28 bytes): forwards work+0x78 to
  `Unk0c855c_Unk_0c9d8c`; a null work object returns before the call.
- `ScanVisor_Unk_0a2ab0` (0x020a2ab0, 28 bytes): forwards work+0x24c to
  `ScanVisor_Unk_0a4a30`, which applies the fixed (1, 1) list update; null work
  returns early.
- `ScanVisor_Unk_0a2acc` (0x020a2acc, 28 bytes): clears the +0x198 word of the
  list at work+0x24c through `ScanVisor_ClearUnkField198`; null work returns
  early.
- `ScanVisor_Unk_0a27e0` (0x020a27e0, 32 bytes): forwards its argument to
  `Unk0fd268_SetDir` after checking the work object. `ScanVisor_Unk_0a2660`
  passes 0 and `ScanVisor_Unk_0a273c` passes the same value it gives the sibling
  helper at 0x020a2800.
- `ScanVisor_Unk_0a2800` (0x020a2800, 32 bytes): forwards its argument to
  `Unk0fd268_Unk_0fd3f0` after checking the work object; the same caller pair
  supplies the value.
- `ScanVisor_Unk_0a2980` (0x020a2980, 32 bytes): returns 1 when the work object
  is null; otherwise forwards work+0x78 to `Unk0c855c_Unk_0c9bac` and returns
  that callee's integer result (`moveq r0,#1` on the null path).

Validation: all eight functions report 100% in `build/report.json`; the match
gate, anticheat gate, unittest suite and original-image checksum gate pass. No
new tests were required by this card; objdiff checks the instruction behavior.

No hard functions for M1-T985.

## M1-T986: work-object forwarding and threshold helper

The eight implementations already existed when this card began. Names retain
configured symbols; evidence comes from the delinked `src/ScanVisor.o`.
Work-object wrappers borrow the getter result and never free its storage.

- `ScanVisor_Unk_0a2b18` (0x020a2b18, 32 bytes): null-check the work
  pointer, then call `Unk0a7d54_Unk_0a8b44` with work+0x428. The original
  forms the address with adds of 0x28 and 0x400.
- `ScanVisor_Unk_0a2b38` (0x020a2b38, 32 bytes): the same null-guarded
  address calculation, forwarding to `Unk0a7d54_Unk_0a8b70` instead.
- `ScanVisor_Unk_0a3254` (0x020a3254, 32 bytes): requires a valid visor;
  load signed word +0x210, compare against 50, and return on signed greater
  or equal. Otherwise call `Unk0c855c_Unk_0c9890` on visor+0x78 with 12.
  Threshold and argument units remain unknown.
- `ScanVisor_Unk_0a29a0` (0x020a29a0, 36 bytes): preserve the caller's
  unsigned value across the getter in r4, then forward work+0x78 and that
  value to `func_020c9bd8`; null work returns without calling.
- `ScanVisor_Unk_0a29c4` (0x020a29c4, 36 bytes): the same argument and
  null handling, forwarding to `Unk0c855c_Unk_0c9c5c`.
- `ScanVisor_Unk_0a2a8c` (0x020a2a8c, 36 bytes): forward the caller id
  and work+0x24c to `ScanVisor_Unk_0a4a18`, which finds the slot and clears
  +0x10/+0x14; null work returns without calling.
- `ScanVisor_Unk_0a2b58` (0x020a2b58, 36 bytes): return 1 for null work
  (`moveq r0,#1`); otherwise return the integer query result from
  `Unk0a7d54_Unk_0a8c04` on work+0x428. The caller at 0x020a2b7c compares
  the result with zero before performing further updates.
- `ScanVisor_Unk_0a2a38` (0x020a2a38, 40 bytes): forward work+0x24c,
  the caller id, and fixed 1 to `ScanVisor_SetById`, activating the selected
  slot; null work returns without calling.

Validation: all eight functions report 100% in `build/report.json`; the match,
anticheat, unittest and original-image checksum gates pass. This card requires
no new tests; objdiff verifies the compiled instruction behavior.

No hard functions for M1-T986.

Carried forward for later cards: `ScanVisor_Unk_0a28f4`,
`ScanVisor_Unk_0a2a60`, and `ScanVisor_Unk_0a42c4` remain decompiler-derived.

## M1-T987: work-field selectors, slot allocation and list refresh

These eight bodies were already present from the earlier hand-match commits in
`src/ScanVisor.c`; this card re-typed them, replaced the decompiler-style locals
and added the per-function evidence comments below. Names remain the configured
symbols. Field stores and call shapes come from the delinked `src/ScanVisor.o`;
they do not establish higher-level gameplay meaning beyond the cited callers.
All setter helpers borrow the work-object word returned by
`ScanVisor_Get_data_02176b04` and are no-ops when it is null.

- `ScanVisor_SetField34` (0x020a277c, 44 bytes): stores -3 at work+0x34 when
  `on` is non-zero and 3 otherwise. Original uses `mvnne #2` / `moveq #3`.
  `unit_0203c474` calls both arms and names the +0x34 value.
- `ScanVisor_SetRangeA` (0x020a2820, 44 bytes): stores 2 at work+0x1c when
  `on` is non-zero and -2 otherwise. Original uses `movne #2` / `mvneq #1`;
  `unit_0203c474` calls both arms and names the +0x1c range value.
- `ScanVisor_SetField214` (0x020a2884, 44 bytes): stores -3 at work+0x214 when
  `on` is non-zero and 3 otherwise. `unit_0203c474` calls both arms.
- `ScanVisor_Unk_0a28f4` (0x020a28f4, 44 bytes): forwards its argument to
  `Unk0fd9f0_SetDir` only when the work object exists and its +0x00 word is 1.
  Both the null work pointer and a different mode word return without calling.
- `ScanVisor_Unk_0a2920` (0x020a2920, 48 bytes): toggles the list at
  work+0x24c. Non-zero selects `ScanVisor_Unk_0a4904`, which stores 1 at the
  list's +0x1bc; zero selects `ScanVisor_Unk_0a4864`, which writes (8, 0) into
  the +0x24/+0x28 fields of each occupied entry and stores 0 at +0x1bc.
  `CampStatus` and several game units pass 0/1 as an enable flag.
- `ScanVisor_Unk_0a2a60` (0x020a2a60, 44 bytes): forwards `id` and `on` to
  `ScanVisor_SetById` on the list at work+0x24c. `game/unit_0202f2a8` calls it
  with `(i, mode)`, matching the SetById contract.
- `ScanVisor_Unk_0a42c4` (0x020a42c4, 44 bytes): scans seven 52-byte entries
  starting at base+0x20 and returns the first whose leading word is zero, or
  null when all seven are occupied. `ScanVisor_Unk_0a42f0` uses the returned
  pointer to fill a new entry; the allocation meaning comes from that caller.
- `ScanVisor_Unk_0a4a44` (0x020a4a44, 44 bytes): calls
  `ScanVisor_Unk_0a4578` first, then, only when the list's +0x198 word is
  non-zero, calls `func_02057eb8(1)` and `func_020a4a70` on the same list.
  `ScanVisor_Unk_0a3620` passes the visor's list at base+0x24c.

Validation: all eight report 100% in `build/report.json`; the match, anticheat,
unittest and original-image checksum gates pass. No new tests were required by
this card; objdiff checks the compiled instruction behavior.

No hard functions for M1-T987.

Carried forward from the old M1-T987 planning list; not part of this card:
`ScanVisor_Unk_0a2ae8`, `ScanVisor_Unk_0a29e8`, `ScanVisor_Unk_0a2b7c`,
`ScanVisor_Unk_0a4544` and `ScanVisor_Unk_0a27a8` were decompiler-derived
at that point; M1-T988 below now verifies and documents them.

## M1-T988: eight verified helpers

These existing C implementations were checked against the delinked original,
then given typed call declarations, readable locals and instruction evidence.
Names follow the configured symbols; opaque operations retain neutral names.
All object and table pointers are borrowed and retain their provider ownership.

- `ScanVisor_Unk_0a2950` (0x020a2950, 48 bytes): null-checks the work
  getter, then passes work+0x24c to `ScanVisor_Unk_0a4910` for nonzero
  `on`, or `ScanVisor_Unk_0a48b4` for zero. The original branch/call pair
  establishes the selection; higher-level meaning remains unknown.
- `ScanVisor_Unk_0a2ae8` (0x020a2ae8, 48 bytes): preserves two caller
  values across the getter, then forwards them with work+0x428 to
  `Unk0a7d54_Unk_0a8b00`. Null work returns without calling.
- `ScanVisor_Unk_0a29e8` (0x020a29e8, 52 bytes): preserves three caller
  values across the getter and supplies them as r1-r3 to `func_020c9cbc`
  with work+0x78 in r0. Null work returns without calling.
- `ScanVisor_Unk_0a2b7c` (0x020a2b7c, 52 bytes): requires nonnull work
  and a nonzero `ScanVisor_Unk_0a2b58` result, then calls
  `Unk0a7d54_Unk_0a8c40` on work+0x428 before clearing the +0x198
  field on the list at work+0x24c. The assembly establishes call order.
- `ScanVisor_Unk_0a379c` (0x020a379c, 52 bytes): calls `func_020c9eb0`
  on work+0x78 with two caller values and submits its result to
  `func_020616ec`. The original reloads the global work pointer after the
  first call; valid work is required, with no null check.
- `ScanVisor_FindEnt20` (0x020a4284, 52 bytes): compares the caller ID
  with the leading word of six 20-byte records at `data_0214ce2c`;
  returns the first matching record address or zero. This table traversal
  supports the configured descriptive name. The returned address is borrowed.
- `ScanVisor_Unk_0a4544` (0x020a4544, 52 bytes): visits seven 52-byte
  entries at list+0x20 and calls `func_020a4370` for each nonzero leading
  word. The caller must supply the full list; no allocation occurs here.
- `ScanVisor_Unk_0a27a8` (0x020a27a8, 56 bytes): null-checks work and
  writes zero to +0x2c for a nonzero argument. Zero instead writes 0x51
  to +0x2c and zero to +0x34. The stores establish behavior, not units.

Validation: all eight functions report 100% objdiff. The full match gate,
anticheat, unittest suite and original-image checksum were run locally.
No new tests are required by this card; objdiff verifies compiled behavior.
No hard functions or omissions for M1-T988.

Earlier planning entries outside this card: `ScanVisor_Unk_0a284c`,
`ScanVisor_Unk_0a28b0`, `ScanVisor_Unk_0a2660`, `ScanVisor_Unk_0a273c`.

## M1-T989: eight verified state and slot helpers

All eight implementations already existed and matched when this card began.
Names retain configured symbols; evidence is from the delinked ScanVisor object.
Pointers are borrowed, and opaque field values have no established units.

- `ScanVisor_Unk_0a284c` (0x020a284c, 56 bytes): null work returns;
  nonzero `on` clears work+0x14, while zero writes -54 there and clears +0x1c.
- `ScanVisor_Unk_0a28b0` (0x020a28b0, 56 bytes): null work returns;
  nonzero `on` clears work+0x210, while zero writes 50 there and clears +0x214.
- `ScanVisor_FindSlotByKey` (0x020a45c0, 56 bytes): scans seven 52-byte
  slots at list+0x20, returning the first with nonzero +0x00 and matching
  +0x04 key, or null. These loads support the configured descriptive name.
- `ScanVisor_Unk_0a4950` (0x020a4950, 56 bytes): writes the caller value
  at list+0x190. Nonzero `on` writes 1 at +0x198 and the GetConst6 result
  at +0x194; zero writes 2 and 4096 respectively. Requires a valid list.
- `ScanVisor_AllSlotsF28Is80` (0x020a4994, 56 bytes): scans seven 52-byte
  slots at list+0x20; returns zero if any occupied slot's +0x1c word differs
  from 80, otherwise one. The configured F28 denotes decimal offset 28.
- `ScanVisor_Unk_0a2660` (0x020a2660, 60 bytes): null work returns;
  calls SetField34, 0a27e0, SetRangeA and SetField214 with zero, in that
  order, then 0a4864 on the saved work+0x24c list.
- `ScanVisor_Unk_0a3760` (0x020a3760, 60 bytes): passes work+0x78 and
  three caller values to func_020c9db4, then submits its result to
  func_020616ec with the reloaded work pointer. Requires valid work;
  the original reload permits the first provider to change the global.
- `ScanVisor_Unk_0a273c` (0x020a273c, 64 bytes): null work returns;
  forwards its value to 0a27a8, 0a2800, 0a284c, 0a28b0 and 0a2950,
  preserving this original call order.

Validation: all eight report 100% objdiff. The full match, anticheat,
unittest and original-image checksum gates were run locally.
No new tests are required by the card; objdiff checks compiled behavior.
No hard functions or omissions for M1-T989.

## Not done in M1-T990
- `ScanVisor_Unk_0a4910`
- `ScanVisor_SetById`
- `func_020a3ac0`
- `ScanVisor_AnySlotField14`
- `ScanVisor_ResetBits`
- `ScanVisor_Unk_0a4578`
- `ScanVisor_Unk_0a4864`
- `ScanVisor_Unk_0a48b4`

## Not done in M1-T991
- `func_020a4df0`
- `ScanVisor_LoadSearchParts`
- `ScanVisor_Unk_0a3274`
- `func_020a30b4`
- `func_020a466c`
- `func_020a2c90`
- `func_020a4370`
- `ScanVisor_Unk_0a42f0`
- `ScanVisor_Unk_0a2e5c`: decompiler-derived

## Not done in M1-T992
- `func_020a2c00`
- `func_020a269c`
- `func_020a3008`
- `func_020a2f3c`
- `func_020a3630`
- `ScanVisor_Draw`
- `func_020a2d0c`
- `ScanVisor_LoadSearchParts`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4a44`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4950`: verified in M1-T989
- `ScanVisor_Unk_0a4864`: decompiler-derived (plain cleanup)
- `ScanVisor_Unk_0a4910`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Unk_0a48b4`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Unk_0a42f0`: decompiler-derived (plain+fix cleanup)
- `ScanVisor_Draw`: hand-matched
- `ScanVisor_SetById`: hand-matched
- `ScanVisor_Unk_0a4a18`: hand-matched
- `ScanVisor_SetField34`: hand-matched
- `ScanVisor_SetRangeA`: hand-matched
- `ScanVisor_SetField214`: hand-matched
- `ScanVisor_Unk_0a2920`: hand-matched
- `ScanVisor_Unk_0a2950`: hand-matched
- `ScanVisor_Unk_0a2980`: hand-matched
- `ScanVisor_Unk_0a2b58`: hand-matched
- `ScanVisor_ResetBits`: hand-matched
- `ScanVisor_Unk_0a3254`: hand-matched
- `ScanVisor_Unk_0a3760`: hand-matched
- `ScanVisor_Unk_0a379c`: hand-matched
- `ScanVisor_FindEnt20`: hand-matched
- `ScanVisor_Unk_0a4578`: hand-matched
- `ScanVisor_FindSlotByKey`: hand-matched
- `ScanVisor_AnySlotField14`: hand-matched
- `ScanVisor_AllSlotsF28Is80`: hand-matched
- `ScanVisor_Unk_0a3274`: hand-matched
