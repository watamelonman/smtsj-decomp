# src/game/unit_0203aae8.c


## Not done in M1-T667
- `func_0203aff0`
- `func_0203b30c`
- `func_0203b4a0`
- `func_0203b158`

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

## M1-T666 verified functions

Evidence: ARM instructions and call relocations in
`build/delinks/src/game/unit_0203aae8.o`. All eight targets match 100%.
Existing symbol names are retained; no gameplay purpose is inferred from offsets.
Work, object, record, and table addresses are borrowed and must be valid.

- `func_0203af7c` (116 bytes): Initializes bytes 0 and 1 to 32 and 1, and word +4 to 1. For positive part counts, caps the count at 32, divides byte 0 by it with a minimum of 1, then stores `32 - count * byte0 + 1` at +4 with a minimum of 1. The record must expose at least eight bytes.
- `func_0203ab84` (124 bytes): Dispatches the opcode halfword from `work[+0xbc] + instructionIndex * 4` through `data_02142170`. Status 0 clears +0xd0 and returns 2; status 1 clears +0xd0 and continues; status 2 increments +0xd0 and +0xcc and returns 1. Other statuses continue. The opcode must index a valid callback.
- `Unk03aae8_Unk_03b6ec` (128 bytes): Reads signed 16-bit argument 0, obtains the object from active work +0xe8, and sets the selected bit. Kind 0 delegates through owner resolution to `0209512c(owner, bit, 1)`; kinds 1 and 3 modify word +0x40. Returns 1.
- `func_0203b7f4` (132 bytes): Uses the same signed argument and object selection, tests kind 0 through `Unk094fe0_TestFlag18`, or tests word +0x40 for kinds 1 and 3. Stores zero for other kinds and returns 1. Direct word bit indices must be in 0..31.
- `Unk03aae8_Unk_03ae68` (136 bytes): Forwards signed 16-bit argument 0 to `0209502c` with mode 1; values 0x733 through 0x737 additionally call `020b8660` with indices 0 through 4. Returns 1. This existing body was verified and given a typed provider declaration and evidence comment.
- `func_0203b76c` (136 bytes): Clears the bit selected by signed 16-bit argument 0, using `0209512c(owner, bit, 0)` for kind 0 or word +0x40 for kinds 1 and 3. Returns 1. Direct word bit indices must be in 0..31.
- `func_0203aae8` (156 bytes): Tests the top stack value: tags 0 and 2 use `02039dc0`; tags 1 and 3 compare `02039e50` against float zero; other tags are false. True increments instruction index +0x18; false loads the branch destination at +0x18 of the 32-byte record selected by the current instruction's second halfword.
- `func_0203ac00` (156 bytes): Reads stack index `work[+0x1c] - (argumentIndex + 1)`. Tags 0 and 4 return the stack word, tag 1 converts the stack float to int, tag 2 indexes `data_0215e258`, and tag 3 indexes float table `data_0215de58` and converts to int. Other tags return zero. Stack and table indices must be valid.

Hard list for M1-T666: none. No runtime tests were added, as permitted by the
card; instruction and relocation matching verifies these original-code contracts.
