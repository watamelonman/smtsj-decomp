# src/game/unit_0203dbbc.c

All seven functions match the delinked ARM object at 100% in objdiff.
Names retain the configured symbols because the instruction evidence establishes
operand forwarding and field accesses, but not their gameplay meaning.
All handlers take no C arguments, obtain operands through `func_0203ac00`, and
return 3. Signed operands use the low signed halfword; byte operands use the
low unsigned byte. Evidence below is the original instruction range.

- `Unk03dbbc_Unk_03dbbc` (0x0203dbbc–0x0203dc0c): reads two signed
  operands, calls both context/work getters, forwards the pair to
  `Unk04bb9c_Unk_04c404`, then writes 17 to context +0xe8's subobject +0x18.
- `Unk03dbbc_Unk_03dc0c` (0x0203dc0c–0x0203dc48): consumes operand 0,
  then forwards signed operands 1 and 2 to `func_0204c4cc`.
- `Unk03dbbc_Unk_03dc48` (0x0203dc48–0x0203dc5c): consumes operand 0
  and returns 3 without using the operand value.
- `func_0203dc5c` (0x0203dc5c–0x0203dccc): reads a signed operand and
  two byte operands, loads the work halfword at +0x35c, and checks the byte
  pair/value with `Unk04bb9c_Unk_04c98c`. A zero result forwards all four
  values to `func_0204c804`. Keeping the final byte in a word-sized local
  reproduces register allocation; a byte-sized local produced 98.93%.
- `Unk03dbbc_Unk_03dccc` (0x0203dccc–0x0203dd08): forwards two byte
  operands and the unsigned work halfword at +0x35c to `func_0204c8f4`.
- `func_0203dd08` (0x0203dd08–0x0203dd98): reads four signed operands.
  Either negative first-pair operand selects the unsigned work halfword at
  +0x35c; otherwise the pair is resolved by `Unk02f2a8_Unk_035b08`.
  Forwards that result and the second pair to `func_0204d1bc`, then writes
  substate 17 through context +0xe8, subobject +0x18.
- `Unk03dbbc_Unk_03dd98` (0x0203dd98–0x0203de08): resolves the first
  signed pair with `Unk02f2a8_Unk_035b08`, truncates the result to a signed
  halfword, and forwards it with the second signed pair to `func_0204c564`.

## Hard list

None.
