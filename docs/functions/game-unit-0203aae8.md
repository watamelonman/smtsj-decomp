# src/game/unit_0203aae8.c


## Not done in M1-T664
- `Unk03aae8_Unk_03ac9c`: decompiler-derived

## Not done in M1-T665
- `Unk03aae8_Unk_03b93c`
- `Unk03aae8_Unk_03ae10`
- `Unk03aae8_Unk_03b694`
- `func_0203b8e4`
- `Unk03aae8_Unk_03b634`
- `Unk03aae8_Unk_03ad24`
- `Unk03aae8_Unk_03ad98`
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
- `Unk03aae8_Unk_03b93c`: hand-matched
- `Unk03aae8_Unk_03ad24`: hand-matched
- `Unk03aae8_Unk_03ad98`: hand-matched
- `Unk03aae8_Unk_03ae10`: hand-matched
- `Unk03aae8_Unk_03b634`: hand-matched
- `Unk03aae8_Unk_03b694`: hand-matched
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
