# src/game/unit_020afc28.c

## M1-T680

All eight card functions match at 100% objdiff. Layouts use only observed offsets;
no ownership transfer occurs. Neutral canonical names are retained.

| Function | Contract and evidence |
| --- | --- |
| `Unk0afc28_Unk_0afc28` | Adds the signed delta to the word at work +0x20 (load/add/store in the original 16-byte routine). |
| `func_020afd48` | Narrows the ID to signed eight bits, calls `func_020982c0`, and returns the signed byte at +5. The caller must supply an ID with an existing record; no null check appears in the original. |
| `Unk0afc28_IsOrigin` | Returns -1 when signed bytes +4 and +6 are both zero, otherwise 0. These two coordinate tests support the existing IsOrigin name. |
| `Unk0afc28_Unk_0afdd0` | Calls `func_0204a67c(work, selector)` and forwards the result to `func_020492ec(selector, result)`, negating it for any nonzero third argument. The first callee tail-calls `func_0204a44c`, which reads the supplied work pointer and selector. |
| `Unk0afc28_Unk_0afd60` (card: `Unk0afc28_RandSpread`) | Computes n = 2*a*b, calls `func_02050074(0, n)`, then returns `(result - n/2)/100` with signed truncation. The random-helper call and centred arithmetic support the card alias; protected symbols use the neutral name. Products must fit signed 32 bits. |
| `Unk0afc28_Unk_0afd98` | When a <= c, calls the random helper with 0 and c-1 and adds one; otherwise adds the scaled spread to a. Clamps the result to at least one. Evidence: comparison, two call paths, and final conditional move. Arithmetic must fit signed 32 bits. |
| `Unk0afc28_Unk_0b0930` | Looks up the signed low byte of c; returns 0 without stores if absent. Otherwise writes c/a at +0/+4, b at +10, and the origin result at +8, returning 1. Typed result fields follow the original word and halfword stores. |
| `Unk0afc28_Unk_0afc38` | If the current record's first word at +0x24 is nonzero, checks the signed low-byte source/current IDs with `Unk0981dc_Unk_098324`. A zero predicate result leaves it unchanged; otherwise copies all three words. Evidence: conditional call followed by LDM/STM. |

### Hard list

None for M1-T680.

### Other existing implementations

- `Unk0afc28_Unk_0afcd4`: existing selector mapping, outside this card.
- `Unk0afc28_CountById`: existing ten-pointer ID count, outside this card.

## Not done in M1-T681
- `Unk0afc28_CountById`
- `func_020afc80`
- `func_020b07c4`
- `func_020b081c`
- `func_020afdf8`
- `func_020b06a0`
- `func_020b0a5c`

## Not done in M1-T683
- `func_020afe64`
- `func_020b04b4`
- `func_020b0310`

## Not done in M1-T682
- `func_020b0adc`
- `func_020b0874`
- `func_020b071c`
- `func_020b017c`
- `func_020b00c0`
- `func_020b0234`
- `func_020b0974`
- `func_020affc8`
