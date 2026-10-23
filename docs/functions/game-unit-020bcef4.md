# src/game/unit_020bcef4.c

## M1-T434: eight matched functions

All eight entries below match at 100% with the configured mwccarm compiler.
Evidence is the original ARM code in the delinked object; no higher-level
meaning is inferred for the neutral symbols. All pointer views are borrowed.

| Function | Size | Evidence and contract |
| --- | ---: | --- |
| `Unk0bcef4_Unk_0bd2fc` | 16 B | 020bd2fc..020bd308 tail-calls `func_020bd30c` with the original two arguments and a zero third argument. Address arguments must satisfy the callee. |
| `Unk0bcef4_Unk_0bd388` | 16 B | 020bd388..020bd394 loads the readable word at argument 1 and forwards it as the count to `Unk0bcef4_Unk_0bd584`. |
| `Unk0bcef4_Unk_0bd470` | 16 B | 020bd470..020bd47c loads the readable first word and forwards it to `Unk0bd5f0_Unk_0bd614`. |
| `Unk0bcef4_Unk_0bd5c4` | 16 B | 020bd5c4..020bd5d0 forwards the record address to `func_020bd49c` with mode 2. |
| `Unk0bcef4_Unk_0bd3e0` | 28 B | 020bd3e0..020bd3f8 increments the writable signed word at +4 and caps values above 1 at 1. The `gt` condition establishes signed comparison. |
| `func_020bd3fc` | 28 B | 020bd3fc..020bd414 increments the writable signed word at +4, then takes its signed remainder modulo 2. The sign correction before the shifts establishes signed remainder, including negative inputs. |
| `Unk0bcef4_Unk_0bd480` | 28 B | 020bd480..020bd498 writes the supplied state into word 0; for states 1, 4, and 6 it also writes 1 into word 1, otherwise preserving word 1. Requires two writable words. |
| `Unk0bcef4_IsState015` | 28 B | 020bd5d4..020bd5ec reads the first word and returns exactly 1 for states 1, 0, or 5, otherwise 0. These comparisons support the existing descriptive name. |

The modulo routine needs a separate increment and compound remainder assignment:
a single `(field + 1) % 2` expression computes the same result but allocates the
sum to r1 rather than the original r3. The two statements reproduce the original
instructions without explicit register control.

Validation: `python3 tools/match_gate.py`, `python3 tools/checksum.py`,
`python3 tools/anticheat.py`, and the full Python unittest discovery suite.

## Hard list
- `Unk0bcef4_Unk_0bcef4`: decompiler-derived
- `Unk0bcef4_Unk_0bd368`: decompiler-derived

## Not done in M1-T435
- `func_020bd54c`
- `func_020bd034`
- `Unk0bcef4_Unk_0bd584`
- `func_020bd398`
- `func_020bd418`
- `func_020bd30c`
- `Unk0bcef4_Unk_0bd29c`: decompiler-derived

## Not done in M1-T436
- `func_020bcfc4`
- `func_020bd110`
- `func_020bd070`
- `func_020bcf14`
- `func_020bd49c`
- `func_020bd1a8`
- `Unk0bcef4_Unk_0bd584`: decompiler-derived (plain cleanup)
- `Unk0bcef4_IsState015`: hand-matched
