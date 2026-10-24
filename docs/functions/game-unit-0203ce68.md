# game/unit_0203ce68

## M1-T250

All eight handlers match at 100% objdiff. Each takes no C parameters and returns
completion status 1. Command operands are read through `func_0203ac00(index)`;
reported values go through `Unk03aae8_Unk_03acf4(value)`.
Neutral names are retained because the command identities are not established.
The evidence below is the original ARM instruction sequence at each entry address.

| Function | Behavior and instruction evidence |
| --- | --- |
| `Unk03ce68_Unk_03cf48` | Reads operand 0, calls `Unk096754_Unk_096a14`, and reports whether its return differs from -1 (`cmp` and conditional zero move). |
| `Unk03ce68_Unk_03cf78` | Reads operand 0 and reports constant 1 (`mov r0, #1` before the result call). |
| `Unk03ce68_Unk_03cf94` | Masks operand 0 to eight bits, calls `Unk0981dc_Unk_0981dc`, and forwards its return register directly to the result call. The declaration preserves that full register result; the callee TU's existing no-parameter declaration does not describe this caller's observed argument transfer. |
| `Unk03ce68_Unk_03cfb4` | Calls `Unk0979d8_ResetAllEntries`, then returns 1. |
| `Unk03ce68_Unk_03cfc4` | Calls `Unk096754_ResetAreaPos`, then returns 1. |
| `Unk03ce68_Unk_03cfd4` | Reads operand 0, obtains the work block, and reports its unsigned byte at offset 0x70 (`ldrb`). A partial struct represents that observed field without assuming the full block size. |
| `Unk03ce68_Unk_03cff4` | Reads operand 0 and forwards `Unk02ee5c_GetTierFromField70`'s return register to the result call. |
| `Unk03ce68_Unk_03d010` | Reads operands 0 and 1, sign-extends operand 1 from 16 bits (`lsl`/`asr`), and calls `Unk02ee5c_AddClamped70`. |

The pre-existing bodies for the return-forwarding handlers discarded C return
values and relied on the compiler leaving r0 intact. Explicit value forwarding
preserves the original instructions while expressing the data dependency.
`Unk096754_Unk_096a14` likewise receives the operand in r0 in the original;
its current implementation does not use it.

## Other existing functions (outside M1-T250)

The TU also contains `Unk03ce68_Unk_03ce68`, `Unk03ce68_Unk_03ced0`,
`Unk03ce68_Unk_03d038`, `Unk03ce68_Unk_03d088`, and
`Unk03ce68_Unk_03d0f0`; their bodies were retained.

## Hard list

None for M1-T250.
