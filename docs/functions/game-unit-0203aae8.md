# src/game/unit_0203aae8.c


## Not done in M1-T665
- `Unk03aae8_Unk_03ae68`: decompiler-derived

## Not done in M1-T666
- `func_0203af7c`
- `func_0203ab84`
- `Unk03aae8_Unk_03b6ec`
- `func_0203b7f4`
- `func_0203b76c`
- `func_0203aae8`
- `func_0203ac00`

## Not done in M1-T667
- `func_0203aff0`
- `func_0203b30c`
- `func_0203b4a0`
- `func_0203b158`
- `Unk03aae8_Unk_03b6ec`: hand-matched

## M1-T664 verified functions

Evidence: ARM instructions and call relocations in the delinked
`build/delinks/src/game/unit_0203aae8.o`. Neutral names are retained because
field accesses and callees do not establish game-level meanings. These wrappers
require an initialized singleton and valid arguments for their callees.

- `Unk03aae8_Nop_03ae0c` (4 bytes): Empty callback; only a return instruction. 100% objdiff.
- `Unk03aae8_Unk_03ad14` (16 bytes): Returns the borrowed address at singleton `data_0215de34 + 4`. 100% objdiff.
- `Unk03aae8_Unk_03acf4` (32 bytes): Clears active-work byte `+0x3b`, reloads the singleton work address, and writes the supplied u32 at `+0xa8`. No return value is consumed. 100% objdiff.
- `Unk03aae8_Unk_03aef0` (36 bytes): Reads argument 0, sign-extends its low 16 bits, calls `Unk094fe0_Call_0209502c(value, 0)`, and returns 1. 100% objdiff.
- `Unk03aae8_Unk_03b878` (36 bytes): Reads argument 0, subtracts one, queries `func_02050074(0, index)`, stores that returned word through `03acf4`, and returns 1. The explicit nested call preserves the original r0 forwarding. 100% objdiff.
- `Unk03aae8_Unk_03af50` (44 bytes): Loads active-work field `+0xe8`, forwards it with the signed low 16 bits of argument 0 to `Unk02dcfc_Unk_02df00`, and returns 3. 100% objdiff.
- `Unk03aae8_Unk_03af14` (60 bytes): Queries `Unk094fe0_Call_020950b4` with the signed low 16 bits of argument 0, stores 1 or 0 through `03acf4`, and returns 1. 100% objdiff.
- `Unk03aae8_Unk_03b89c` (72 bytes): Reads arguments 0 and 1 in order; compares argument 0 unsigned against `func_02050074(0, argument1 - 1)`, stores 1 for greater and 0 otherwise, and returns 1. 100% objdiff.

Hard list for M1-T664: none. No new runtime tests: exact instruction and relocation matching is the acceptance check for these functions.

## M1-T665 verified functions

Evidence: ARM instructions and call relocations in
`build/delinks/src/game/unit_0203aae8.o`. All eight functions match 100%.
Names remain neutral because instructions alone do not establish gameplay roles.
Object pointers and singleton work addresses are borrowed and must be valid.

- `Unk03aae8_Unk_03ac9c` (88 bytes): Computes stack index `work[+0x1c] - (argument + 1)`, reads its byte tag at `+0x20`, and returns its word at `+0x3c` only for tag 5; otherwise returns zero.
- `Unk03aae8_Unk_03ad24` (116 bytes): For kind 0 at object `+8`, zeroes a 64-byte local buffer, fills it through `02095b48` using field `+0x40`, and applies it through `0204b344`. Other kinds do nothing.
- `Unk03aae8_Unk_03ad98` (116 bytes): Resolves a key directly through `0204b3cc` for kind 0, or through `0204fe68(handle, null)` then `0204fed8` for kinds 2 and 3 using fields `+0x5c` and `+0x74`. Other kinds return null.
- `Unk03aae8_Unk_03ae10` (88 bytes): Resolves a key through `095778` for kind 0 or the two-stage resolver using field `+0x50` for kind 2. Other kinds return null.
- `Unk03aae8_Unk_03b634` (96 bytes): Reads two signed 16-bit arguments, gets object `work +0xe8`, resolves owner from `+0x40` for kind 0 (zero otherwise), and calls `SetSlot(owner, argument0, argument1)`. Returns 1.
- `Unk03aae8_Unk_03b694` (88 bytes): Reads one signed 16-bit slot argument and, for kind 0, resolves owner and reads a signed 16-bit slot result. Stores zero for other kinds. Returns 1.
- `func_0203b8e4` (88 bytes): Reads scale and two bounds in order, shifts bounds left 10, queries `02050088` with stream zero, divides the unsigned result by 100, multiplies with word wrapping, arithmetic-shifts right 10, and stores the result. The `0x51eb851f` unsigned multiply-high and shift establish division by 100. Returns 1.
- `Unk03aae8_Unk_03b93c` (76 bytes): Stores whether argument 0 is within the inclusive signed interval specified by arguments 1 and 2. Returns 1.

Hard list for M1-T665: none. Instruction and relocation matching is the
acceptance check; no runtime tests were added for these assembly-preserving wrappers.
