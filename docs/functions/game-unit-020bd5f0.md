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
  count at +0x124, restores the selected +0x128 entry through `func_020bcfc4`,
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

`Unk0bd5f0_Unk_0c2050` remains decompiler-derived and outside this card.

## Not done in M1-T1137
- `func_020c1f40`
- `func_020c7bc8`
- `func_020c1c4c`
- `func_020c83a0`
- `func_020c1d88`
- `func_020c7b30`
- `func_020c1af4`

## Not done in M1-T1138
- `func_020c1fb0`
- `func_020c1414`
- `func_020c1b94`
- `func_020c1cd0`
- `func_020c67a0`
- `func_020c0c5c`
- `func_020c1770`
- `func_020c7304`
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
