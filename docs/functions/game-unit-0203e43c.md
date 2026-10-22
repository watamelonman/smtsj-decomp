# src/game/unit_0203e43c.c

- `Unk03e43c_Thunk_0203fa84` (12 B): tail-call thunk that forwards to `func_0203fa84`.
- `Unk03e43c_Unk_03f2ac` (16 B): returns a pointer `offset` bytes into the shared
  table at `data_0215e85e`; `Unk03e43c_Unk_044194` consumes the result as a u16 array.
- `Unk03e43c_Unk_03fa28` (20 B): returns the work-area byte at +0x360 mapped through
  `Unk03e43c_Div10Clamp16` (a 0..15 table slot, or the -1 sentinel).
- `Unk03e43c_Unk_03f2bc` (24 B): sets bit 1 of the byte at +0x10 in the object returned
  by `func_0205410c`.
- `Unk03e43c_Call_02056cc0` (28 B): calls `func_02056cc0(1, 0, data_0215e85e)` to
  register the 512-byte table.
- `Unk03e43c_CountDown` (28 B): decrements the u16 count at +0x58 of the passed object;
  returns 1 when it was already zero and 0 after a decrement.
- `Unk03e43c_Unk_03fa3c` (28 B): stores `value * 10` in the work-area counter byte at
  +0x360 (the inverse of the `/10` mapping above).
- `Unk03e43c_Div10Clamp16` (32 B): returns `x / 10`, or -1 when the quotient is >= 16
  (so a 0..159 counter maps to a 0..15 slot).

All eight match the delinked original at 100% in objdiff.

## M1-T1087

All eight functions below match the delinked original at 100% in objdiff.
Existing matching bodies were retained and given explicit contracts and typed
parameters; the table-copy routine now uses byte pointers rather than integers.

- `Unk03e43c_SetMode30` (40 B): stores the mode word at `data_0215ee60 + 0x30`;
  calls `func_0204b6d0` only when mode is 1 and the word at +0x34 is zero.
  The stores and conditional comparisons support the existing name.
- `Unk03e43c_AdvanceCounter360` (44 B): increments the work-area byte at +0x360
  with byte wrap, then subtracts 160 if the stored value is at least 160.
  The byte access and comparison support the existing name.
- `Unk03e43c_ClearTable` (48 B): calls `func_02020f8c`, clears 512 bytes at
  `data_0215e85e`, then clears the leading u16 at `data_0215e85c`.
  The clear call's length and the separate halfword store establish the extent.
- `Unk03e43c_Unk_03e5a4` (56 B): obtains a value with `func_02051610(arg1)`;
  returns it if `func_02020974(value, arg0)` succeeds. Releases rejected values
  with `func_020516d0` and returns zero on failure.
- `Unk03e43c_Unk_03e5dc` (56 B): same acquire/validate/release contract, using
  `func_020207d0` as the validator. The resource and argument meanings are unknown.
- `Unk03e43c_Unk_03e614` (56 B): same contract, using `func_02020ac0`.
- `Unk03e43c_Unk_03e64c` (56 B): same contract, using `func_02020a74`.
- `Unk03e43c_Unk_03e794` (56 B): copies 32 bytes from source +0x28 to
  `data_0215e85c + index * 32 + 2`, in pairs of byte loads/stores. The caller
  supplies a readable source and a valid destination slot; no bounds check exists.

## M1-T1088

All eight functions below match the delinked original at 100% in objdiff.
The bodies came from the earlier hand-matching pass in this file; this card
verified them, added explicit contracts and typed parameters, and checked the
caller-supplied table/index contracts.

- `Unk03e43c_CopyEntry32` (56 B): copies a 32-byte entry into table slot
  `slot` (`data_0215e85c + slot*32 + 2`) in byte pairs, leaving the u16 header
  at `data_0215e85c` intact. Callers such as `func_020b5e2c` load consecutive
  resource entries into consecutive slots.
- `Unk03e43c_Unk_03e894` (56 B): derives a value with
  `func_0202092c(resource, index)`, passes it with the setup pointer `a` to
  `func_020211d8`, then clears the u16 countdown at `entry + 0x58`. The
  original truncates `index` to u16; callers pass two resource handles from a
  setup record (`func_020b28e8`).
- `Unk03e43c_UpdatePos18` (64 B): recomputes the s16 coordinates at
  `+0x18/+0x1a` through `Unk03e43c_Unk_043450` (forwarding the
  `+0x2000:+0x8dc` word as its third argument), then sets the dirty word at
  `+0x04` when either coordinate changed.
- `Unk03e43c_MergeTable` (68 B): copies the nonzero u16 entries of the
  512-byte source table into the shared table at `data_0215e85c` (payload at
  `+2`), leaving zero source entries unchanged.
- `Unk03e43c_Unk_03e8cc` (84 B): advances the u16 counter at `+0x58` until it
  reaches the sum of the u16 durations at `+4` of every entry in the table
  referenced at `+0x1c`; returns 1 when already at/above the total, 0 after
  incrementing. The animation/timing meaning is unknown.
- `Unk03e43c_Unk_044194` (88 B): clears the seven per-slot bytes at
  `p+0x2000:+0x982`, writes `0x73f5` to the four u16 table slots 1..4, merges
  those entries, and re-registers the table via
  `Unk03e43c_Call_02056cc0`.
- `Unk03e43c_Unk_043450` (96 B): computes two s16 screen coordinates from the
  signed map bytes at `work+0x300:+100/+101` and the matching GameState
  fields: base 128/96 minus `(mapByte - gameField) * 8`. `UpdatePos18`
  forwards a third argument that this body does not read.
- `Unk03e43c_Unk_043560` (104 B): counts the 37 flags tested by
  `Unk02f078_TestFlag380` and maps the total to 48 (`>20`), 24 (`>16`),
  23 (`>12`), 22 (`>8`), 21 (`>4`), otherwise 20.

## Hard list

None for M1-T1087 or M1-T1088.

## Not done in M1-T1089
- `func_0203e684`
- `Unk03e43c_Unk_03f234`
- `Unk03e43c_Unk_0441ec`
- `Unk03e43c_Unk_041ce4`
- `func_02044114`
- `func_0203fa84`
- `func_02044264`
- `func_020442fc`
- `Unk03e43c_Unk_0434b0`: decompiler-derived

## Not done in M1-T1090
- `func_0203e6f0`
- `func_0203f960`
- `func_0203eaf8`
- `func_0203f394`
- `func_0203f174`
- `func_0203f2d4`
- `func_02043340`
- `Unk03e43c_Call_02056cc0`: decompiler-derived (plain cleanup)
- `Unk03e43c_CountDown`: hand-matched
- `Unk03e43c_CopyEntry32`: hand-matched
- `Unk03e43c_MergeTable`: hand-matched
- `Unk03e43c_Unk_03e894`: hand-matched
- `Unk03e43c_Div10Clamp16`: hand-matched
- `Unk03e43c_UpdatePos18`: hand-matched
- `Unk03e43c_Unk_03e8cc`: hand-matched
- `Unk03e43c_Unk_03f234`: hand-matched
- `Unk03e43c_Unk_041ce4`: hand-matched
- `Unk03e43c_Unk_043450`: hand-matched
- `Unk03e43c_Unk_043560`: hand-matched
- `Unk03e43c_Unk_044194`: hand-matched
- `Unk03e43c_Unk_0441ec`: hand-matched

## M1-T1089

Five of the eight card functions match the delinked original at 100% in objdiff
(match gate, checksum and anticheat pass). Three are left as delinked asm (see hard list).

- `func_0203e684` (108 B): gets a table from `func_02056110(id)`, calls its
  callback at +0x201c with (4, b, c), and passes the args block
  `{a, d, result, 0, 0, 0, 0}` plus the table's list at +8 to `func_0205bf18`.
- `Unk03e43c_Unk_03f234` (120 B): unwraps two periodic s16 coordinates toward a
  target (period 512 for the first, 256 for the second). Was already matched; comment added.
- `Unk03e43c_Unk_0441ec` (120 B): resets fields of the object at
  `data_0215ee60+0x34`, re-runs `Unk03e43c_Unk_044194` and calls
  `Unk04bb9c_SetCtxUnka14(-1)`. Was already matched; comment added.
- `Unk03e43c_Unk_041ce4` (128 B): cleanup callback registered by `func_0203fa84`;
  releases four handles and clears the `data_0215ee60` +0x30/+0x34 words.
  Was already matched; comment added.
- `func_0203fa84` (144 B): creates a 0x299c-byte task via `func_020611dc`
  (callbacks `func_02040064`, `func_020416bc`, -, `Unk03e43c_Unk_041ce4`), stores
  the work area at +0x28dc, then calls `func_0203fb14` with either
  `Unk04bb9c_GetCtxUnka20()` or the work-area u16 at +0x35c.
- `func_02044114` (128 B): NOT MATCHED (see hard list).
- `func_02044264` (152 B): NOT MATCHED (see hard list).
- `func_020442fc` (152 B): NOT MATCHED (see hard list).

### Hard list (for a decomp.me scratch)

- `func_02044114(work, i)`: sets `work[0x2982 + i] = 1`, returns unless 0 <= i <= 3,
  then clears one u16 of the table from `Unk03e43c_Unk_03f2ac(0)` via a 4-way
  switch (0->[4], 1->[2], 2->[3], 3->[1]), then `Unk03e43c_MergeTable` and
  `Unk03e43c_Call_02056cc0`. The ROM keeps a second `cmp r4,#3` before the jump
  table; every form tried (`i < 0 || i > 3`, separate ifs, nested `if`, switch
  in an inline helper) drops it (124 vs 128 B). `i >= 4` keeps it but emits `cmp #4`.
- `func_02044264(work)`: switch on +0x28c4 (cases 1-5, 10-12) then
  `if (+0x4 == 0 && (+0x28cc != 0 || (state == 1 && (q->+0x10 == 2 || == 4 || q->+0x4 == 0))))`
  with `q = *(+0x28d8)`, calls `Unk03e43c_Unk_0441ec`. Ours reuses the
  `w+0x2000` base for +0x28d8; the ROM recomputes it and uses r2/r3 instead of
  r0/r2 (148 vs 152 B). Tried nested ifs, `||` chain, inline predicate helper.
- `func_020442fc()`: reads Res36 fields 0x19/0x1a of the ctx, calls
  `func_02051b18(&v, 1, 1, Unk02f2a8_Unk_035b74(..) + 1, 2)` on a fresh 0x1a value,
  returns 0 if unchanged else `Unk02e000_TestFlag(Unk02f2a8_Unk_035b08(r19, v)) != 0`.
  The ROM calls `Unk04bb9c_GetCtxUnka20` twice before the last read (reproduced
  with an inline helper taking an unused ctx arg) and keeps 1, &v and 2 in
  r4-r6 (push r3-r9); ours folds them into scratch registers (144 vs 152 B).
  Tried constant locals, inline params, and a static helper (not inlined).
