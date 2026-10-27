# sdk_02052b58

Eight small accessors and writers for two SDK state blocks and the GX command
port. The symbols are retained as `func_` because the delink has no descriptive
names and no caller in the current C tree resolves their use beyond the shapes
below.

## func_02052b7c

- Original: ARM, address `0x02052b7c`, size 16 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: stores the two 32-bit arguments at `data_0215f4a0 + 0x00` and
  `+0x04`. No validation and no return value.
- Evidence: one literal load of `data_0215f4a0` followed by
  `stm r2, {r0, r1}`, which covers both words in one instruction.
- Public-source lookup: no exact public reconstruction of this pair setter was
  identified; the symbol name is retained.

## func_02052b8c

- Original: ARM, address `0x02052b8c`, size 16 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns the first 32-bit word at `data_0215f4a0`.
- Evidence: literal load of `data_0215f4a0`, then `ldr r0, [r0]`.
- Public-source lookup: no exact public reconstruction identified.

## func_02052b9c

- Original: ARM, address `0x02052b9c`, size 16 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns the second 32-bit word at `data_0215f4a0 + 0x04`.
- Evidence: literal load of `data_0215f4a0`, then `ldr r0, [r0, #4]`.
- Public-source lookup: no exact public reconstruction identified.

## func_02052bf8

- Original: ARM, address `0x02052bf8`, size 16 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns the unsigned byte at `data_0215f4c0[index]`. The caller
  supplies the index; there is no bounds check.
- Evidence: literal load of `data_0215f4c0`, then `ldrb r0, [r1, r0]`.
- Public-source lookup: no exact public reconstruction identified.

## func_02052c08

- Original: ARM, address `0x02052c08`, size 24 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: adds 2 to the unsigned byte at `data_0215f4a8[index]`, wrapping at
  8 bits, and stores it back. No return value and no bounds check.
- Evidence: `ldrb`, `add #2`, and `strb` on `data_0215f4a8` using the argument
  directly as the index.
- Public-source lookup: no exact public reconstruction identified.

## func_02052c20

- Original: ARM, address `0x02052c20`, size 16 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns the unsigned byte at `data_0215f4a8[index]`. The byte is
  zero-extended by the load; there is no bounds check.
- Evidence: literal load of `data_0215f4a8`, then `ldrb r0, [r1, r0]`.
- Public-source lookup: no exact public reconstruction identified.

## func_02052c30

- Original: ARM, address `0x02052c30`, size 12 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: returns the address `data_021438c0`. That block begins with two
  words initialized to `-1` and holds the strings `WH_SYSSTATE_IDLE` and
  `WH_SYSSTATE_BUSY` at `+0x30`; the rest of the TU treats it as a state
  record. This card does not consume the fields, so the return type stays
  opaque and the name neutral.
- Evidence: the original body is a single literal load of `data_021438c0` and
  `bx lr`.
- Public-source lookup: the `WH_SYSSTATE_*` strings appear only in ROM data, and
  no exact public reconstruction of this accessor was identified.

## func_02052c94

- Original: ARM, address `0x02052c94`, size 28 bytes.
- Status: **100% objdiff match**, with typed parameters and readable C.
- Contract: writes `2` to `0x04000440` and `1` to `0x04000448`. Both stores are
  volatile MMIO writes; there is no read-back and no return value.
- Evidence: one literal load of `0x04000440`, then `str #2, [r1]` and
  `str #1, [r1, #8]`.
- Public-source lookup: the address is the GX command/status port used by the
  NitroSDK GX helpers in this repository; no exact public reconstruction of
  this specific two-store wrapper was identified.

## Hard list

None; all eight functions' instructions match. The remaining functions in the
TU belong to sibling cards and are still supplied by the delink.
