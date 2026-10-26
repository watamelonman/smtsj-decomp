# game/unit_0203c6a4

## M1-T296: verified matches

All eight functions below match the delinked ARM instructions at 100% with the
configured compiler. They have no C parameters. Neutral names are retained because
the instruction evidence establishes forwarding/state behavior but not game meaning.

| Function | Evidence and contract |
| --- | --- |
| `Unk03c6a4_GetConst1` | At 0x0203c710, returns 1 directly. The handler result meaning is unconfirmed. |
| `Unk03c6a4_Unk_03c718` | At 0x0203c718, polls `func_02065544`; zero returns 3 immediately. Otherwise calls `func_02065c30`, obtains the owner through `Unk03aae8_Unk_03ad14`, follows +0xe8, writes worker +0x18 = 4, and returns 3. Requires a valid owner/worker on the nonzero path. |
| `Unk03c6a4_Unk_03c84c` | At 0x0203c84c, obtains argument 0 from `func_0203ac00`, sign-extends its low 16 bits, and calls `func_0203c748(0, value, 0, 0, 0)`. |
| `Unk03c6a4_Unk_03c878` | At 0x0203c878, forwards the same signed argument with `(1, value, 0, 0, 0)`. |
| `Unk03c6a4_Unk_03c8a4` | At 0x0203c8a4, forwards the same signed argument with `(2, value, 0, 0, 0)`. |
| `Unk03c6a4_Unk_03c8d0` | At 0x0203c8d0, forwards the same signed argument with `(0, value, 1, 0, 0)`. |
| `Unk03c6a4_Unk_03c8fc` | At 0x0203c8fc, forwards the same signed argument with `(1, value, 1, 0, 0)`. |
| `Unk03c6a4_Unk_03c928` | At 0x0203c928, forwards the same signed argument with `(2, value, 1, 0, 0)`. |

The six forwarding wrappers preserve the existing void C interface; their ARM
epilogues leave the callee result in r0. The state-store inline helper preserves
the original value/worker register order without assembly. Objdiff verifies the
signed truncation, immediate arguments, call relocations and early-return path.
No new behavioral tests are required by this card; instruction matching is the
acceptance check.

## M1-T297: verified matches

All four functions below match at 100% with the configured compiler. The existing
wrappers remain at 100%. Parameters and worker fields reflect ARM instruction
usage; game-specific meanings remain unknown.

| Function | Evidence and contract |
| --- | --- |
| `Unk03c6a4_Unk_03c6a4` | No parameters. Reads script argument 0, obtains owner +0xe8, initializes worker +0x2c if zero, resolves the argument through `Unk03aae8_Unk_03ae10`, polls/starts the subsystem, forwards the resolved value and sets worker state +0x18 to 28. Returns 3. Requires a valid owner and worker. |
| `Unk03c6a4_Unk_03c954` | No parameters. Reads signed low 16 bits of argument 0; argument 1 selects mode 1 or 2, otherwise 0. Forwards kind/option 0 and flags 0x101 to `func_0203c748`, returning its result. |
| `Unk03c6a4_Unk_03c9c0` | No parameters. Reads four script arguments in order; signed argument 0 supplies value, argument 1 supplies kind, argument 2 selects mode 1 or 2, otherwise 0. Argument 3 is read but unused. Forwards option/flags 0 and returns the callee result. |
| `func_0203c748` | Five integer parameters: mode, value, kind, option, flags. Requires owner +0xe8. If `func_020ba944` is nonzero, calls the two global helpers, forwards a signed 16-bit result to `Unk03aae8_Unk_03acf4` and returns 1. Otherwise sets worker state 9; kind 0 initializes +0x28 and resolves through `Unk03aae8_Unk_03ad98`, kind 1 initializes +0x2c and resolves through `Unk03aae8_Unk_03ae10`. Other kinds forward zero. Polls/starts the subsystem, forwards resolved value/mode/option/flags and returns 0. |

The worker layout models only observed offsets. Keeping the dispatcher before its
wrappers preserves matching local call relocations in objdiff. No module boundary
changes or new behavior assumptions are introduced. This card requires no new
behavioral tests; instruction matching verifies branches, argument order and stores.

## Hard list

None.
