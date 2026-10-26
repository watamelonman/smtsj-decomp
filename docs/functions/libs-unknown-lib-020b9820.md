# libs/unknown/lib_020b9820

## Identification and contracts

The card classifies this unit as SDK/middleware. A public-source search of
NitroSDK/pret script code did not identify a matching implementation (reference:
https://github.com/pret/pokeplatinum/blob/main/src/battle/battle_controller_player.c).
Local evidence instead identifies game script request wrappers: `func_0203ac00`
reads operands from the active context at `data_0215de34 + 4` (including numeric
conversion), and `Unk03aae8_Unk_03acf4` clears its byte at +0x3b and stores
the result word at +0xa8. `func_020b8b38` stores its four arguments into request
fields +0x20 through +0x2c and returns a Boolean submission result.
No meaning beyond these operations is inferred for the request numbers.
Existing neutral `func_` symbols are preserved to agree with the protected symbol map.

All ten functions take no explicit arguments, read the implicit current script
context, publish the submission result, and return completion status 1. Operand
reads occur in increasing index order. Parameters to callees are typed 32-bit
integers; no script operand is narrowed. The final request word is always zero.

## Functions

| Symbol | Original size | Request | Operand words |
| --- | ---: | ---: | --- |
| `func_020b9820` | 56 | 61 | script operands 0, 1 |
| `func_020b9858` | 56 | 62 | script operands 0, 1 |
| `func_020b9890` | 56 | 63 | script operands 0, 1 |
| `func_020b98c8` | 56 | 64 | script operands 0, 1 |
| `func_020b9900` | 56 | 65 | script operands 0, 1 |
| `func_020b9938` | 56 | 66 | script operands 0, 1 |
| `func_020b9970` | 56 | 67 | script operands 0, 1 |
| `func_020b99a8` | 44 | 68 | script operand 0, zero |
| `func_020b99d4` | 44 | 69 | script operand 0, zero |
| `func_020b9a00` | 56 | 70 | script operands 0, 1 |

Evidence for each entry is the ARM disassembly beginning at the address in its
symbol: immediate request in r0, operands in r1/r2, zero in r3, followed by calls
to the submission and result-store helpers. The constants describe original
request behavior, rather than test-specific outputs.

## Verification

Matching is checked against the original delinked object with objdiff; checksum
verification retains the original linking arrangement until a human marks the
unit complete. M2-T067 adds the remaining request-67 and request-70 wrappers.
A further public-source search for the operand/submission helper symbols found
no matching SDK implementation; the existing game-script identification applies.
Both new functions follow the same 14-instruction ARM sequence as the two-operand
wrappers above, including preserving operand 0 in r4 across the second read.

## Hard list

None; all ten functions are implemented.
