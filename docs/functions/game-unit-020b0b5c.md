# game/unit_020b0b5c — M1-T222 / M1-T223

The behavior below follows the ARM instructions and relocation targets in the
original delinked object. Resource/query meanings are not established, so existing
neutral symbol names are retained. All eight implemented functions match at 100%.
No module boundary changes are introduced.

| Function | Contract and instruction evidence |
| --- | --- |
| `func_020b0b5c` | Not implemented; see hard list below. The five signed arguments feed a rounded Q12 calculation; the value 4000 returns argument two unchanged. |
| `func_020b0bd4` | For percentages at least 100, return the base. Otherwise multiply the Q12 percentage and base with rounding, divide through `func_0200219c` by Q12 100, multiply by the third argument with rounding, convert to integer, and clamp to at least one. The third argument is used directly as a fixed-point multiplier. Intermediate shifted values/products must fit their signed representations. |
| `Unk0b0b5c_Unk_0b0c30` | Return the lesser of the requested signed amount and `query49f24(value,0) - (query49d80(value,0) - query4ab98(value))`. The three call relocations establish the query sequence. |
| `Unk0b0b5c_Unk_0b0c78` | Return the lesser of the requested signed amount and `query49d80(value,0) - query4ab98(value)`. |
| `Unk0b0b5c_Unk_0b0cac` | Mode-one counterpart of 0b0c30, using query4ab14 for the final query. |
| `Unk0b0b5c_Unk_0b0cf4` | Mode-one counterpart of 0b0c78, using query4ab14 for the final query. |
| `Unk0b0b5c_Unk_0b0d28` | Return second pointed-to signed integer minus first. Both pointers must be valid; subtraction must fit a signed int. The original is two loads, subtraction, return. |
| `Unk0b0b5c_Unk_0b0d38` | Return first pointed-to signed integer minus second, with the same pointer and arithmetic contract. |

| `func_020b0d48` | Select among the singleton's ten non-null entries at offset 0x64. A nonzero filter must equal bits 16–23 of the entry's first word; zero filter accepts any nonzero byte there. Exclude entries whose first word equals the fallback, or whose `func_0204a9ec` result is nonzero. Reload the first word after that call. Return zero if the singleton is absent, fallback if no candidates qualify, otherwise choose with `func_02050074(0, count - 1)`. The selected word is opaque; signed parameters and return preserve its 32-bit representation. Entry pointers must remain valid during the call, and the random helper must return an inclusive in-range index. The original's 0x28-byte stack array, ten-iteration loop, loads, tests, and call relocations establish this behavior. The explicit accepted-filter label preserves the original branch layout; separate candidate store and count increment preserve register allocation. All 192 bytes match. |

The query helpers take a 32-bit opaque value; their data interpretation is not yet
established. Query differences and requested limits use signed comparisons and
must fit signed int arithmetic.

## Hard list

- `func_020b0b5c` (120 bytes): best readable C candidate reached 99.33%.
  Its behavior is: return fallback when value is 4000; otherwise compute
  `factor = factor * 6 / 10`, form the rounded Q12 product of `value << 12`
  and `(offset + 20) << 12`, divide it through `func_0200219c` by
  `(factor + 25) << 12`, then apply the fifth argument as a rounded Q12
  multiplier and convert to integer. Tried separate quotient and denominator
  temporaries, operand order, shifted-input temporaries, signed/unsigned result
  types, and inline fixed-point multiplication helpers. The best candidate has
  the correct 30-word instruction sequence, but registers differ in the final
  denominator addition and numerator rounding/shift (r1/r2 allocation).
  Omitted from C so the original remains linked from the delink. A human can
  open a scratch with `tools/decompme.py` for the remaining allocation issue.
