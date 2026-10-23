# src/game/unit_020bd5f0.c

## M1-T1134 (all 100% in objdiff)
- `Unk0bd5f0_Unk_0bd5f0` (36 B): predicate over two words of the object in r0; true only when the
  word at +8 is 2 and the word at +4 is >= 2.
- `Unk0bd5f0_Unk_0bd614` (28 B): loads the word at `data_0213c4d4[index]` and forwards it to
  `func_02057ddc`, which stores it into four consecutive words of `data_02168b24`; returns 0.
- `Unk0bd5f0_Unk_0c1ad8` (28 B): tail-calls `func_020c8008(0, 0, 0, 0)`.
- `Unk0bd5f0_IsSpecialId` (28 B): membership test for ids 5, 6, 8 and 22.
- `Unk0bd5f0_Unk_0c20f0` (32 B): calls `func_020c1b94` with the object in `data_02176bb0` when that
  pointer is non-null.
- `Unk0bd5f0_Unk_0c7588` (32 B): lexicographic comparison of two 16-bit key pairs (word at +2 first,
  then word at +0); returns the difference.
- `Unk0bd5f0_SetCtxUnk1b8` (24 B): sets the word at +0x1b8 of the context in `data_02176bb4` to 1.
- `func_020c1968` (40 B): returns whether the signed byte at offset `0x348 + index` of the shared
  work area (`Unk02e000_GetWorkArea`) is non-negative.

## M1-T1135 (all 100% in objdiff)
The eight existing C bodies were verified against the delinked object with the configured
MWCC build and objdiff. Their behavior comments and contracts are now recorded in source.
No assembly or fallback bodies were needed.

- `Unk0bd5f0_IsState22or24` (48 B): returns false for a null global context;
  otherwise tests its first word for 22 or 24. The comparisons and the first-word
  writes in `Unk0bd5f0_Unk_0c7fbc` support the existing state predicate name.
- `Unk0bd5f0_Unk_0c8510` (48 B): takes an `Unk0bd5f0Obj *`; reads `unk_0100`
  and the byte `unk_0110` and passes them with zero to `func_020c72a4`, then writes
  `unk_0000 = 20`, `unk_0004 =` the caller's second argument and `unk_0114 = -110`.
  Kept separate from `Unk0bd5f0Ctx` (its -110 field is at +0x114, not +0x118).
- `Unk0bd5f0_Unk_0c20bc` (52 B): tests group 0 masks 0x40 and 0x80 with
  `func_020537b8`; returns true only if both are clear, short-circuiting the second query.
- `Unk0bd5f0_AnyIdWithFlagsMid` (76 B): scans ids 111 through 210 inclusive;
  returns true at the first id accepted by `Unk09974c_Unk_0998d8` whose record
  from `Unk09974c_Unk_099d78` passes `Unk09974c_HasFlagsMid`.
  The loop bounds and helper calls support the existing descriptive name.
- `Unk0bd5f0_AnyIdWithoutFlagsMid` (76 B): same scan, requiring the record to
  fail `Unk09974c_HasFlagsMid`; the negated helper result supports the name.
- `Unk0bd5f0_Unk_0c7f70` (76 B): no-op for a null global context; otherwise
  forwards `unk_0108` and all four caller arguments to `CampStatus_Unk_0dde3c`.
- `Unk0bd5f0_Unk_0c7fbc` (76 B): no-op for a null global context; otherwise
  writes 20 at +0, 22 at +4, -110 at +0x118, and zero at +0x120 and +0x11c.
- `Unk0bd5f0_Unk_0c842c` (76 B): no-op for a null global context; otherwise
  calls `Unk0ddeb0_Unk_0ddeb0` with the +0x100 word, the +0x114 word plus
  three, and constants -2, 0, 12 and 10.

Hard list for M1-T1135: none.
`Unk0bd5f0_Unk_0c75a8` remains decompiler-derived and outside this card.

## M1-T1136
Seven targets match at 100% with the configured MWCC compiler and objdiff.
Names are retained because the instruction accesses establish behavior but not domain meaning.

- `Unk0bd5f0_Unk_0c1870` (80 B): searches the signed-byte list at work-area
  +0x348 for the signed value at +0x354+i; returns the count at +0x357 on failure.
  The caller must provide a readable mapping index.
- `Unk0bd5f0_Unk_0c1918` (80 B): maps i through the signed byte at +0x348;
  returns false for a negative mapping, otherwise tests the mapped 60-byte record's
  +0xa8 halfword for 1 or its signed +0x92 halfword for a nonpositive value.
- `func_020c84c0` (80 B): calls `func_020c7304`, decrements the byte stack
  count at +0x124, passes the sub-object at +0x44 and the popped +0x128 entry
  to `func_020bcfc4`,
  forwards +0x108, +0x110 and the low byte of (+0x54 + 100) to `func_020c72a4`,
  then calls `Unk0a0ce4_Unk_0a0da4(2)`. Requires a populated selection stack.
- `func_020bd9c4` (84 B): initializes the descriptor size to 352 and kind to 0,
  clears +0x14 and stores five callback addresses; preserves +8.
- `func_020c2578` (88 B): initializes the descriptor size to 448 and kind to 3,
  clears +0x14 and stores its five callback addresses; preserves +8.
- `func_020c72a4` (96 B): looks up group 12 with the caller's selector; rejects
  indices at or above table word +12, otherwise resets conversion state, looks up
  and converts the entry, then forwards it to the borrowed object with (-1, 0, 0).
- `Unk0bd5f0_Unk_0c75a8` (100 B): compares readable halfword pairs, putting
  accepted ids first, then ordering by the second halfword and finally the id.

### Hard list for M1-T1136
- `func_020c18c0` (88 B): remains linked from the original delinked object.
  C trials implemented the signed mapping lookup at +0x348+i, a three-entry
  reverse scan at +0x354 and -1 for a negative or absent mapping. Best measured
  objdiff was 96.59%. MWCC emitted `sublt r0, r2, #1` for the early -1 return
  instead of `mvnlt r0, #0`, and reversed the loop equality operands.
  Tried signed/unsigned counters, signed-byte/int keys, declaration and initializer
  ordering, explicit result locals, conditional returns and integer-address forms.
  No nonmatching body is retained; a human can use `tools/decompme.py` for a scratch.

`Unk0bd5f0_Unk_0c2050` was subsequently verified in M1-T1137.

## M1-T1137 (all eight targets 100% in objdiff)

Names remain neutral: instruction accesses establish behavior, but no strings or
callers establish a more specific domain meaning. Parameters borrow their objects.

- `Unk0bd5f0_Unk_0c2050` (108 B): queries group-zero masks 0x40, 0x80,
  0x20 and 0x10, latching 1 into words +0x150, +0x154, +0x158 and +0x15c
  respectively. Clear queries preserve the previous word.
- `func_020c1f40` (112 B): initializes two descriptor flag bytes and sixteen
  word slots, sets flag bit 1 and slot 1 to 24, submits kind 3 to
  `func_020bcbc4`, then invokes the input latch routine.
- `func_020c7bc8` (124 B): searches an inclusive unsigned range for an accepted
  id. Exactly 411..900 uses `func_0209a158`; other ranges use
  `Unk09974c_Unk_0998d8`. Empty ranges return false.
- `func_020c1c4c` (132 B): zeroes six word slots, scans mappings starting at
  owner +0x44 until six entries or a negative signed mapping, collects halfwords
  at work-area +0xaa with stride 60, then refreshes via `func_020c1cd0`.
- `func_020c83a0` (140 B): returns for a null global context; otherwise calls
  helpers with 31 and no arguments, then configures its +0x108 object with
  `(1, 152, 0, 25, 10)` and `(1, 164, 1, 25, 10)`.
- `func_020c1d88` (144 B): collects the same six mapped ids and forwards them
  with the populated count and constants 18, 1 to the owner's +0xb4 object.
- `func_020c7b30` (152 B): counts accepted ids in an inclusive signed range,
  wrapping the count to sixteen bits. Exactly 111..210 additionally requires
  the id's record to pass `Unk09974c_HasFlagsMid`.
- `func_020c1af4` (160 B): collects and forwards ids as in `func_020c1d88`,
  then refreshes the owner with `func_020c1cd0`.

Collection routines require readable mappings and referenced 60-byte records.
The unsigned range scan requires an upper bound below UINT32_MAX when no match
is found, as in the original incrementing loop.

Hard list for M1-T1137: none. No assembly fallback bodies were added.

## M1-T1138 (all eight targets 100% in objdiff)

The existing TU was extended. Neutral symbols are retained because accesses and
helper calls establish behavior but do not establish domain names. Object and
work-area pointers are borrowed; mapped indices must reference readable records.

Typed layouts (all file-local in the .c; no other TU uses them):
- `Unk0bd5f0List`: the 352-byte object of the kind-0 descriptor (`func_020bd9c4`,
  release callback `func_020c0c5c`). Used by `func_020c0c5c`, `func_020c1fb0`,
  `func_020c1414`, `func_020c1b94`, `func_020c1cd0`, `func_020c1770` and the
  earlier `func_020c1af4`/`c1c4c`/`c1d88`.
- `Unk0bd5f0SelectObj`: the 448-byte object of the kind-3 descriptor
  (`func_020c2578`, release callback `func_020c67a0`). Used by `func_020c67a0`,
  `func_020c7304` and `func_020c84c0`. Kept separate from `Unk0bd5f0List`: the
  descriptor sizes differ and the same offsets hold different data (+0x3c is a
  sub-object in the kind-0 object but a released handle in the kind-3 one).
- `Unk0bd5f0SubObj`: a 28-byte sub-object at +0x20/+0x3c (kind 0) and +0x44
  (kind 3); +8 is the first collected index and +0x10 the selected index.
- `Unk0bd5f0WorkArea`/`Unk0bd5f0Record`: base record fields (+0x12, +0x1c, +0x1e),
  text at +0x48 and record fields +6/+0x1a/+0x1c were added.
`func_020c0c5c` and `func_020c67a0` keep `void *` parameters because they are
stored in the descriptor's `void (*)(void *)` callback slots.

- `func_020c1fb0` (160 B): acts only for kind 37. Mode 25 uses the
  1-based selection `unk_0020.unk_0010` into `unk_0354` (indexed from
  `unk_0354 - 1` so the -1 folds into the load offset, as in the original),
  with a special -1 dispatch for index zero. Mode 26 uses `unk_003c.unk_0010`
  into `unk_0348`; that read adds the index to the typed field's address as u32
  because plain indexing reverses the original add operands (See DEC-002). Negative mappings call
  the clearing helper; other mappings go to `func_020c1990`.
- `func_020c1414` (172 B): resets conversion state, converts work-area
  +0x48, then converts the three +0x354 mappings using group 18, selector 1,
  and mapped halfword ids at +0xaa with stride 60. Negative mappings use an
  empty halfword string. Sends the final conversion result to the supplied
  output, then refreshes via `func_020c1b94`. Pointer-typed conversion
  declarations and the local empty-string initializer reproduce register allocation.
- `func_020c1b94` (184 B): submits the base record at +0x12 with signed
  halfwords +0x1c/+0x1e, then each valid +0x354 mapping's record at +0x7e
  and signed halfwords +0x92/+0x94 (stride 60). Slots are 0 and 1..3.
  Uses object +0x138/+0x13c/+0x140 and sets output byte +0x40 to 2.
- `func_020c1cd0` (184 B): accepts six readable word ids. For each nonzero
  id, scans records up to work-area byte +0x357 for matching halfword +0xaa,
  submits the first matching record with the six-slot index, then sets output
  byte +0x40 to 2. Uses object +0x144/+0x148/+0x14c.
- `func_020c67a0` (232 B): signals 30, conditionally releases handles
  +0x3c/+0x40, releases +0x188, the two +0x18c entries and +0x19c,
  then releases outputs +0x100 through +0x10c. Released handles are cleared;
  output handles are reread and cleared only when still non-null.
- `func_020c0c5c` (236 B): conditionally releases +0x10/+0x14, releases
  outputs +0x144/+0x138, the two +0x18 entries and outputs
  +0xac/+0xb4/+0xb0, then clears global `data_02176bb0`. Output handles
  are reread after their release calls before conditional clearing.
- `func_020c1770` (256 B): recounts nonnegative +0x348 mappings into
  object +0x60, resets the +0x20/+0x3c subobjects, collects up to six ids
  beginning at object +0x44, forwards the populated count to +0xb4, then
  refreshes those ids through `func_020c1cd0`. The collection loop is inlined
  as in `func_020c1af4`.
- `func_020c7304` (292 B): derives a row count from group 12 and the
  object's selector, allowing a positive helper result to override it. Rebuilds
  selection subobjects and eight row values from +0xe0 flags, updates the
  three output objects, then sets state 20, next state 24, both transition
  words to -110 and the remaining two transition words to zero. Requires a
  valid selected index for its +0xe0 array and valid output objects.

Validation: `ninja`, anticheat, all nine unit tests, match and checksum gates pass.
No new tests were required by the card; objdiff checks exact generated code.
Hard list for M1-T1138: none. Original delink configuration remains human-owned.

### Earlier hand-matched functions
- `Unk0bd5f0_SetCtxUnk1b8`: hand-matched
- `Unk0bd5f0_IsSpecialId`: hand-matched
- `Unk0bd5f0_Unk_0bd5f0`: hand-matched
- `Unk0bd5f0_Unk_0c1870`: hand-matched
- `Unk0bd5f0_Unk_0c1918`: hand-matched
- `Unk0bd5f0_Unk_0c20bc`: hand-matched
- `Unk0bd5f0_AnyIdWithFlagsMid`: hand-matched
- `Unk0bd5f0_AnyIdWithoutFlagsMid`: hand-matched
- `Unk0bd5f0_Unk_0c7f70`: hand-matched
- `Unk0bd5f0_Unk_0c7fbc`: hand-matched
- `Unk0bd5f0_Unk_0c842c`: hand-matched
- `Unk0bd5f0_IsState22or24`: hand-matched
- `Unk0bd5f0_Unk_0c8510`: hand-matched
