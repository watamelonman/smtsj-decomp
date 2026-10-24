# libs/unknown/lib_020ba474

## Evidence and source search

The original ARM instructions call `func_020b8b38` with a constant request
number and three integer arguments, then pass its result to
`Unk03aae8_Unk_03acf4`, the current script result writer. Every handler returns
completion status 1. `func_020ba4bc` obtains its first request argument from
script operand zero through `func_0203ac00`.

A public-source search for the entry addresses and NitroSDK/Pokémon Platinum
reconstructions found no corresponding implementation. Calls to the game's
script helpers support treating these as game-specific wrappers, despite the
library split path. No SDK identity or request-specific meaning is asserted.
Existing neutral `func_` symbols are retained to agree with the protected symbol
configuration. The C signatures have no explicit inputs; script state is implicit.

## Functions

| Symbol | Request | Arguments | Contract |
| --- | --- | --- | --- |
| `func_020ba474` | 107 | 0, 0, 0 | Publish request result; return 1. |
| `func_020ba498` | 108 | 0, 0, 0 | Publish request result; return 1. |
| `func_020ba4bc` | 109 | operand 0, 0, 0 | Read operand, publish request result; return 1. |
| `func_020ba514` | 111 | 0, 0, 0 | Publish request result; return 1. |
| `func_020ba538` | 112 | 0, 0, 0 | Publish request result; return 1. |
| `func_020ba5b4` | 115 | 0, 0, 0 | Publish request result; return 1. |
| `func_020ba5d8` | 116 | 0, 0, 0 | Publish request result; return 1. |
| `func_020ba5fc` | 117 | 0, 0, 0 | Publish request result; return 1. |

Evidence for each entry is its own original ARM instruction stream at the
address encoded in the symbol. Request-specific behavior remains unresolved.

## Hard list

None of the eight requested functions is left out. Other functions in this
translation unit remain linked from the original delink as required by the card.
