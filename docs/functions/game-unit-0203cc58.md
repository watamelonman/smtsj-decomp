# game/unit_0203cc58

Names retain the original neutral symbols because the calls establish operations,
but do not establish domain-level meanings. Evidence below is the ARM instruction
stream at each function's address. Parameters are signed words unless narrowed
explicitly; all five implemented handlers return a status word.

- `Unk03cc58_Unk_03cc58` (0x0203cc58): reads argument 0. Selector 0 calls
  `Unk096754_Unk_097110`; selectors 1..3 call `Unk0979d8_Unk_0981a4`
  with a byte-sized index minus one. Other selectors yield zero. Passes the
  selected result to `Unk03aae8_Unk_03acf4`, then returns 1.
- `func_0203ccac` (0x0203ccac): reads selector and value. The six-entry jump
  table dispatches selector 0, selectors 1..3, selector 4, and selector 5 to four
  distinct callees. Values narrow to signed halfwords; individual indices narrow
  to bytes. Returns 1, including for selectors outside the table.
- `Unk03cc58_Unk_03cd34` (0x0203cd34): the BL chain forwards argument 0
  to `func_0209993c`, then forwards its result to `Unk03aae8_Unk_03acf4`.
  Returns 1.
- `Unk03cc58_Unk_03cd50` (0x0203cd50): original-only, not implemented. Positive
  amounts select between `func_02065aa4` and `func_020659a4` by mode, call
  `func_02099a28`, write 5 through context +0xe8 to subobject +0x18, and
  return 3. Nonpositive amounts first call the work-area thunk, then exclude
  entry kinds 3..6 before forwarding the negated amount to `func_02099b10`;
  returns 1.
- `Unk03cc58_Unk_03ce10` (0x0203ce10): reads arguments 0 and 1, calls
  `Unk03cc58_Unk_03cd50` with mode 0, and preserves its returned status.
- `Unk03cc58_Unk_03ce3c` (0x0203ce3c): same forwarding contract with mode 1.

## Hard list

- `Unk03cc58_Unk_03cd50`: reconstructed the signed branch, mode dispatch, typed
  context/subobject layout, state store, and kind switch. The original tests
  `func_02095818() == 1` and calls `func_02065c10` separately in both branches.
  Ordinary C with its no-argument prototype merges those identical calls,
  producing 176 rather than 192 bytes. Disabling common subexpressions did not
  preserve the branch. An exploratory argument-forwarding version retained the
  branch but added an instruction (196 bytes); it was discarded because the
  callee does not consume that argument. Leave the helper in the delink and
  investigate compiler control-flow settings in a human-created decomp.me scratch.
- `Unk03cc58_Unk_03cd50`: hand-matched
