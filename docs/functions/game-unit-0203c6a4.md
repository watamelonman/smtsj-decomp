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

## Existing functions outside this card

- `Unk03c6a4_Unk_03c6a4`: existing decompiler-derived body; 100% in the local report.
- `Unk03c6a4_Unk_03c954`: existing hand-matched body; 100% in the local report.
- `Unk03c6a4_Unk_03c9c0`: existing hand-matched body; 100% in the local report.
- `func_0203c748`: remains supplied by the delink, outside M1-T296.

## Hard list

None for M1-T296.
