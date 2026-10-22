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

## M1-T1090

Three of eight targets match at 100% in objdiff. The existing source was extended;
no delink configuration was changed. Neutral symbols are retained because the
memory accesses establish operations but do not establish gameplay names.

- `Unk03e43c_Unk_0434b0` (176 B): clamps two writable s16 coordinates to
  upper bounds 176/112 and lower bounds `-8 * (dimension - 10)`. The dimensions
  are bytes +10/+11 of the map referenced by `GameState_GetBody() + 0x354`.
  The existing body matched; its parameter types and contract are now explicit.
- `func_0203f960` (168 B): fills a clipped rectangle on a 256 by 192 byte
  surface through `func_020119c0`. Negative origins discard leading columns
  or rows. The caller supplies the surface storage and rectangle dimensions.
- `func_02043340` (208 B): submits the 96-byte entry at index `slot + 3`
  relative to object +32, using resource +0x28a0 and coordinates (128, 96).
  Then the signed byte at +0x2982+slot selects entry 0, 1 or 2 for another
  submission at (128 + slot*64, 96). Other byte values produce no second call.

### Hard list (for a decomp.me scratch)

These five functions remain supplied by the delinked object; no unmatched C
bodies were retained. No assembly stub is needed in this project's pipeline.

- `func_0203e6f0` (164 B): builds a path from its first two arguments and
  `data_02142214`, acquires a resource through `Unk03e43c_Unk_03e614`, and
  optionally merges the acquired header's +12 table. The candidate was 160 B;
  reversing the two 64-byte local buffer declarations fixed their stack offsets,
  but the compiler kept the initial path pointer in ip and loaded the extension
  later, instead of preserving it in r4. Tried an explicit extension local.
- `func_0203eaf8` (172 B): configures mode, builds entries through
  `func_0203eba4`, marks each eight-byte entry through `func_02056bd0`, submits
  them and increments `data_0215e658`. Candidates were 180/184 B. Tried for/while
  loops, signed/unsigned indices, typed u64 entry indexing, and postincrement
  in the address expression. The compiler strength-reduced the index into a
  separate pointer cursor; the original retains an index shifted by three.
- `func_0203f174` (192 B): transforms a point about a center, using the
  distance from `func_020500bc`, angle from `func_020024f8`, and s16 table
  `data_0212629c`. A 192-byte candidate reproduced the initial paired point
  loads and signed angle modulo, but table-load scheduling and multiplication
  registers differed. Tried paired temporary loads, separate products, reversed
  declaration order and s16 versus int temporaries.
- `func_0203f2d4` (192 B): clips a destination rectangle to 256 by 192 and
  copies source rows through `func_02008904`, using 256-byte strides. Tried
  separate end/row locals, while loops and source-row postincrement in the
  address expression. The last candidate was 188 B; the compiler folded the
  source base and row offset and used fewer saved registers than the original.
- `func_0203f394` (188 B): copies nonzero source pixels into a clipped
  destination rectangle on 256-byte-stride surfaces. The candidate had the
  correct size and control flow but different register allocation from the
  first source-coordinate load onward. Reordering x/y declarations and moving
  destination coordinate temporaries to function scope did not resolve it.

### Retry results (attempt 2)

The three matching functions are unchanged. The remaining five were re-examined;
none reached 100%, so no C body was retained (the delink supplies them). All 2.0
service packs were checked for `func_0203f174` and produce identical code, so the
difference is source shape, not the compiler service pack.

- `func_0203e6f0`: declaring `u8 name[64] = {0}` before `u8 path[64]` puts the
  zeroed buffer at sp+68 and gives the exact 164-byte layout (87.9%). The original
  also keeps `a0` in r4 and `a1` in r6, while mwcc keeps `a0` in ip and `a1` in
  r4; both values are dead after their call, so this is a register-allocation
  choice.
- `func_0203f174`: the angle reduction is `(u16)((theta + angle) % 65536) >> 4`;
  `x % 65536` is what produces the original `lsr/rsb/ror` idiom, and the table is
  `s16 *` at 0x0212629c indexed by `idx * 2`. The 192-byte body then differs only
  in register naming: the original keeps `idx * 2` in r3 and fills r1/r0 with the
  two byte offsets, while mwcc reuses r1.
- `func_0203f2d4`: the 192-byte body and control flow are reproduced exactly.
  The original keeps `src` in fp and `srcCol` in r8 and forms
  `srcCol + (row << 8)` each row; mwcc folds `src + srcCol` into sl and
  strength-reduces the row term. Parenthesizing the address and recomputing the
  row from `top + srcY` did not prevent the fold.
- `func_0203eaf8`: not retried; the previous findings still apply.
- `func_0203f394`: not retried; the previous findings still apply.

## M1-T1091

Two of the eight card targets match the delinked original at 100% in objdiff;
the other six remain supplied by the delinked object and are on the hard list.
`func_0203f450` and `func_0203f394` now have typed prototypes in the TU because
the matched callers pass five and eight arguments respectively.

- `func_0203e43c` (360 B): NOT MATCHED. Builds three resource paths from `a`,
  `b` and the three `data_021421f*` suffixes, acquires them with
  `Unk03e43c_Unk_03e5a4/03e5dc/03e64c`, stores the handles through `d`, `e`,
  `c`, then submits setup slots 0/1 through `func_0203e684` for bank 2 or the
  selected bank. A 356-byte candidate had the correct control flow. The
  original zeroes its 64-byte scratch buffer as 16 iterations of four byte
  stores with the pointer in `ip`; mwcc always chose a different loop form and
  kept `bank` in r8 instead of r7. Tried simple/indexed/pointer loops and
  four-byte unrolling.
- `func_0203e93c` (444 B): NOT MATCHED. 452-byte candidate reproduces the
  branches: flag bit 19 switches the bank and marks each built entry, otherwise
  angle `+0x4c` builds a `func_02052dfc` matrix and scale `+0x40/+0x44` selects
  identity or the angle matrix; the result count accumulates into
  `data_0215e658`. mwcc emits a `count <= 0` pre-check that the original does
  not, and assigns the seven saved registers differently throughout. Tried
  `for`/indexed/u64-table forms, signed vs unsigned flag load, and reordered
  `else if` branches.
- `func_02041d98` (392 B): draws the object's 8x8 icon at (x, y). Skips the
  draw unless the work-area context id at +0x35c matches
  `Unk04bb9c_GetCtxUnka20`; mode 0 uses `func_0203f394`, modes 1/2 use
  `func_0203f450` with a 90 or 0 degree transform, and the fallback passes the
  mirror flag. The s16 offsets at +0x1c/+0x1e and +1 origin come from the
  original call sites.
- `func_020435c8` (356 B): NOT MATCHED. 352-byte candidate reads the 24-byte
  id table at 0x0212cc0c, maps the object type at +0x28e9 to a starting y
  (180/172/164/156/148/140), and draws up to 24 7x7 icons four per row through
  `func_0203e93c`. The conditional category mapping (23->0x4a, 24->0x4b,
  20->0x49) is reproduced; only register assignment and the two-byte copy
  loop shape differ (r9/r6/r7 vs r4/r5/r9 etc.). Tried reversed declaration
  order, pointer/indexed copy loops, explicit zero/category locals.
- `func_02043ea8` (620 B): draws a 7x7 icon for an id in 2, 13, 14, 18, 19 or
  21..24 from source-column/row pairs (0x30, 0x88, 0x90, 0xb0, 0xb8, 0,
  8, 0x10, 0x18; rows 0 or 8) at (x+1, y+1). Ids outside 1..36 are ignored.
  The case order follows the original handler order; case 14 is last and falls
  through to the shared return.

### Hard list (for a decomp.me scratch)

- `func_0203e43c`: see the zero-loop/register notes above (356 B vs 360 B).
- `func_0203e93c`: see the loop pre-check/register notes above (452 B vs 444 B).
- `func_020435c8`: see the register/copy-loop notes above (352 B vs 356 B).
- `func_0203eba4` (1488 B): not matched. Ghidra shows the entry builder:
  mode must be 1; adds s16 offsets +0x4a/+0x48 to the position, applies
  `func_0202128c` to the resource list and `func_0203f234`/`func_0203f174`
  to the cached positions, computes rotated/translated quad corners from the
  scale at +0x40/+0x44 and angle byte +0x5d, updates the two register words
  at 0x0215e85c/0x0215e860 through bitfields, and increments the u16 count at
  0x0215e858 by the built count. The stack-restarting decompiler output and
  heavy bitfield/register mixing need a dedicated scratch.
- `func_0203f450` (1296 B): not matched. Rotated/mirrored surface blit. It
  normalises the angle through the 0x0203f958/0x0203f95c reciprocal, allocates
  a `-(width*height) & ~7` stack buffer, copies the source through four
  separate 0/90/180/270 paths, then composites with optional clipping and
  transform flags (`param_9`..`param_11`). Callers pass 11 arguments.
- `func_0203fb14` (1360 B): not matched. Initialises the 0x299c-byte task:
  clears the +0x2000 work fields, stores the work-area pointer, seeds the
  coordinate/camera fields through `GameState_*`/`Unk02e000_GetWorkArea`,
  builds 76 + 32 draw entries via `Unk03e43c_Unk_03e894`, clears the shared
  table, creates 16 slots through `func_0203e6f0`, three icon submissions,
  and finishes with `func_02061f10`/`func_020442fc`.
- `func_0203f450`/`func_0203fb14`/`func_0203eba4` source bodies are not retained
  because the compiler-generated stack frames are large and the Ghidra output
  loses the argument slots; no candidate reached a stable size. Open a
  decomp.me scratch with the delinked body before retrying.
