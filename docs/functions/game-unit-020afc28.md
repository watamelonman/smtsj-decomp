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

## M1-T681

All eight functions match at 100% in the instruction comparison and objdiff.
The existing canonical symbols are retained; field layouts expose only observed
accesses and borrowed provider storage. No new module boundary is introduced.

| Function | Contract and instruction evidence |
| --- | --- |
| `Unk0afc28_CountById` | Counts matching IDs among ten nonnull pointers at global +0x64. The first word's bits 16..23 supply the ID, supporting the existing name. |
| `func_020afc80` | Searches ten ID/value slots starting at work +0x30. Adds delta to the first empty or matching slot, writes the ID, and returns 1 only if its old ID was nonzero. Returns 0 if full. Paired word accesses establish the slot layout. Signed accumulation must fit. |
| `Unk0afc28_Unk_0afcd4` | The original jump table maps selectors 0..7 to 8..15 and all other unsigned values to 26. |
| `func_020afdf8` | Queries selector 7 on both borrowed inputs; clamps unsigned `5*(query(a)+10)/(query(b)+10)` to 1..50, then compares a random 0..99 draw against it. Evidence: multiply, unsigned divide, clamp and unsigned final comparison. Denominator must be nonzero. |
| `func_020b06a0` | Rejects values other than 1. Accepts a nonzero selector-one query on global +0x8c. Otherwise requires nonzero flag and either kind 1/7 or a nonzero selector-zero query. Evidence: the three provider calls and branches. |
| `func_020b07c4` | Calls 0b071c(value,0,-1). When global bit 10 is clear and the result is nonzero, delegates to 0b06a0(value,0); otherwise returns whether the first result was zero. Evidence: word +0x40, bit extraction, and calls. |
| `func_020b081c` | Same branch structure as 0b07c4, with flag 1 passed to both helpers. Evidence: immediate arguments in the original. |
| `func_020b0a5c` | Returns 0 unless provider kind is 3. Multiplies selector 17 (doubled if the selector-zero predicate succeeds) by the halfword at +0x17a, divides signed by 100, adds five and spread(result,10), and clamps to one. Evidence: halfword load, signed division sequence, calls and final compare. Signed arithmetic must fit. |

### Hard list

None for M1-T681.

## Not done in M1-T683
- `func_020afe64`
- `func_020b04b4`
- `func_020b0310`

## M1-T682

Seven functions match at 100% objdiff. Existing prerequisite functions retain
100%. Neutral canonical names remain because no strings or callers establish
more specific roles. Provider storage is borrowed; arithmetic intermediates
must fit the widths used by the original.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020b0adc` | Requires kind 9; scales selector 23 by +0x17a, doubles the selector when the predicate succeeds, divides by 100, adds five, halves, adds spread and clamps to one. Evidence: provider calls, halfword load and signed division sequences. |
| `func_020b0874` | Missing ID provider returns zero. Perturbs selector 6 by a random -5..5, clamps at zero, adds three for ID class one when global bit 10 is clear, scales by the supplied percentage and caps at 65535. Packs its low sixteen bits at bits 10..25, the provider byte +0x1dc at bits 2..9, and sets bit zero. Evidence: shifts, ORs, masks and provider calls. |
| `func_020b071c` | Counts matching IDs in ten global slots, excluding selector-one state. Nonzero flag additionally excludes selector-zero state and kinds 1/7. Third argument is unused, as incoming r2 is never read. Evidence: ten-slot loop and bit extraction from each first word. |
| `func_020b017c` | Uses source/target selector 4, source twice minus target selector and target level, and source plus 8*source/10+5. Applies rounded 20.12 products, delegates to 0affc8 and spreads/clamps the result. Evidence: provider selectors and SMULL/add/shift chains. |
| `func_020b00c0` | Uses source selector 3 minus target selector 5, the supplied level minus target level, and source plus 4*level/10+5. Applies the supplied fixed-point factor, delegates to 0affc8 and spreads/clamps. Evidence: provider calls and signed scaling instructions. |
| `func_020affc8` | Combines forwarded selector 13/12 results, the mapped target selector divided by 100, supplied factor and base using rounded 20.12 products. Source +0x282 bit two applies factor 0x119a. Returns integer units. Evidence: SMULL chains, bit extraction and final signed shift. Corrects the prerequisite forwarding helper's return type to expose the result already left in r0; that helper still matches. |
| `func_020b0974` | Returns zero for absent +0x170 record or signed state below zero/equal one. With x zero, accepts nonzero y below state. Otherwise compares a random unsigned 0..99 draw with `(x*selector7+10)/(6*selector2/10+15)+10*state`. Evidence: signed byte/halfword loads, division, SMLABB and unsigned comparison. Denominator must be nonzero. |
| `func_020b0234` | Not emitted. Original averages source selectors 3/4, subtracts target selector 5, optionally replaces their sum via 0a120 when source +0x1d8 is zero, then applies a target-level multiplier and delegates to 0affc8 with selector 18 before spread/clamp. |

### Hard list

- `func_020b0234`: best local objdiff 99.27273%. Tried direct and inline
  rounded products, separating base calculation, signed/unsigned stat views,
  variable reuse and declaration ordering. Remaining difference is allocation
  of the sum and multiplier to r5/r6 (including the sum's shift destination).
  Leave linked from the delink; a human can open a scratch with
  `tools/decompme.py`. No nonmatching C implementation is retained.
