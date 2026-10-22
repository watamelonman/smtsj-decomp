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

## Hard list

None for M1-T1087.

## Not done in M1-T1088
- `Unk03e43c_CopyEntry32`
- `Unk03e43c_Unk_03e894`
- `Unk03e43c_UpdatePos18`
- `Unk03e43c_MergeTable`
- `Unk03e43c_Unk_03e8cc`
- `Unk03e43c_Unk_044194`
- `Unk03e43c_Unk_043450`
- `Unk03e43c_Unk_043560`

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
