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

## M1-T251

The remaining five functions already matched in HEAD, but with untyped
prototypes (`int f();`), raw `u16 *` work access and no comments. They now use
the shared `Unk03ce68Work` struct (u16 slots `unk_0000`..`unk_0006`, then
`unk_0070`), real prototypes taken from the callee definitions, and doc comments.
All five are still 100% objdiff and the image is still byte-identical. Neutral names
are kept because the command identities are not established.

| Function | Behavior and instruction evidence |
| --- | --- |
| `Unk03ce68_Unk_03ce68` | Reads slot index (operand 0; operand 1 is read and discarded), reports work u16 slot 0..3 (`ldrh [r0,#0..#6]` jump table), 0 otherwise. |
| `Unk03ce68_Unk_03ced0` | Reads id (operand 1, `lsl/lsr #16`; operand 0 discarded), switches on `Unk09974c_GetEntryUnk08(id)`: kinds 3..6 `strh` the id into slots 0..3, kinds 0..2 and others store nothing (7-entry table). |
| `Unk03ce68_Unk_03d038` | Pure mapping of selector 0..4 to 0, 4, 1, 2, 3; others give 0 (5-entry table of `mov r0,#n; bx lr`). |
| `Unk03ce68_Unk_03d088` | Target = operand 0, selector = `03d038(operand 1)`. Target 0 reports `Unk09727c_GetAreaS8(sel)`, targets 1..3 report `Unk0981dc_Unk_098258((u8)(target-1), sel)`, others report 0. |
| `Unk03ce68_Unk_03d0f0` | Setter counterpart: operand 2 is the value, sign-extended from 16 bits (`lsl/asr #16`), then passed to `Unk096754_Unk_097220(sel, v)` for target 0 or `Unk0981dc_Unk_0981f4((u8)(target-1), sel, v)` for targets 1..3. |

Those two setters take a `u8` value in their own TUs. Here the caller-side
prototypes declare `s16` because the ROM sign-extends from 16 bits at the call site.

## Hard list

None for M1-T250 or M1-T251.
