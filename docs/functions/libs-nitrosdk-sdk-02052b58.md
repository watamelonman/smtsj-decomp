# sdk_02052b58

Eighteen matched accessors, state helpers and writers for two SDK state blocks and the GX command
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

## M2-T215 source investigation

Public-source searches for NitroSDK/NitroSystem implementations and the nearby
`WH_SYSSTATE_IDLE` string did not identify an exact reconstruction. No public
source was copied. Names remain neutral: the ARM instructions establish the
contracts below, but do not establish the larger subsystem purpose.

## func_02052b58

- Original: ARM, address `0x02052b58`, size 36 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Returns data_021437e0[index], calling func_02007e94 first when the unsigned index is >=6. The provider call is not assumed to return or terminate; the lookup follows it exactly as in the original.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052bac

- Original: ARM, address `0x02052bac`, size 40 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Clears all 24 bytes at data_0215f4a0 +8. The signed loop counter and byte stores follow the original loop.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052bd4

- Original: ARM, address `0x02052bd4`, size 36 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Fills all 24 bytes at data_0215f4a0 +0x20 with the caller-supplied byte.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052d14

- Original: ARM, address `0x02052d14`, size 32 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Logically negates the state word at +8; zero becomes one, any nonzero value becomes zero.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052d34

- Original: ARM, address `0x02052d34`, size 36 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Tests func_02052cb0(1); if true, calls func_020574d4, toggles the flag, then calls func_02052c3c, in that order.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052d58

- Original: ARM, address `0x02052d58`, size 36 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Tests func_02052cb0(0); if true, calls func_020574d4, toggles the flag, then calls func_02052c94, in that order.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052d7c

- Original: ARM, address `0x02052d7c`, size 36 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: For a nonnull borrowed signed-byte pair array, resets index to zero and stores count and pointer at +4/+12. Null leaves state unchanged. Caller retains array ownership and must keep it alive.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## func_02052dd8

- Original: ARM, address `0x02052dd8`, size 36 bytes.
- Status: **100% objdiff match**.
- Contract/evidence: Returns null for state index -1; otherwise returns the borrowed pointer at +12 plus twice the index. The provider/caller is responsible for valid bounds and backing storage.
- Evidence: original instruction sequence at the function address, including
  its loads/stores, conditional branches and ordered calls.

## M2-T216 source investigation

Public-source searches for NitroSDK/NitroSystem GX helpers, including
`G3_MtxMode`, `G3_Translate` and `WH_SYSSTATE_IDLE`, found no exact public
reconstruction of these state wrappers. No source was copied. Names remain
neutral because the larger subsystem purpose is not established.

## func_02052cb0

- Original: ARM, address `0x02052cb0`, size 100 bytes.
- Status: **100% objdiff match**.
- Contract: nonzero mode succeeds only when index is not -1, pairs is nonnull,
  and flag is zero. Zero mode succeeds only when flag is nonzero.
- Evidence: ordered loads and early returns at 0x02052cc4..0x02052d10.
  The function reads provider-owned state and changes no storage.

## func_02052da0

- Original: ARM, address `0x02052da0`, size 56 bytes.
- Status: **100% objdiff match**.
- Contract: index -1 is unchanged. Otherwise increments index; reaching count
  sets index to -1 and clears pairs without releasing caller-owned storage.
- Evidence: increment/store and signed conditional stores at
  0x02052db8..0x02052dd0.

## func_02052c3c

- Original: ARM, address `0x02052c3c`, size 88 bytes.
- Status: **not implemented; original delink retained**.
- Evidence/contract: loads the current signed-byte pair, writes 2 to GX matrix
  mode (0x04000440), 0 to matrix push (0x04000444), then sends each coordinate
  multiplied by 4096 and arithmetically shifted right five, followed by zero,
  to translation port 0x04000470. Requires a valid current pair.
- Attempt: direct byte indexing, a local pair pointer, two-byte array views,
  coordinate type/declaration variants, and inline translation/setup helpers.
  Best result was 98.41%; instruction count and operations matched, but the
  initial index/address registers differed. The nonmatching body was removed.

## Hard list

- `func_02052c3c`: register allocation differs in the initial pair loads;
  suitable for a human decomp.me scratch via tools/decompme.py.
