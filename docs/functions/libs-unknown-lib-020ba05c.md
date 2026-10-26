# libs/unknown/lib_020ba05c

## Evidence and contracts

The eight ARM functions below consume no incoming arguments and return signed
integer 1 after calling `func_020b8b18(selector, 0)`. That helper stores the
selector's low halfword at shared-record offset 0x0c and a 32-bit value at
0x10, obtaining the record through `func_020b8ac8` before each store.
The selector meanings and library provenance are unknown, so existing neutral
linker symbols are retained. The constants are the original call operands.

A public-source search of pret/pokeplatinum NitroSDK/script dispatch code did
not identify this unit. The inspected [battle script interface](https://github.com/pret/pokeplatinum/blob/main/include/battle/battle_script.h)
does not establish a relationship to these functions; implementation follows
this ROM's instructions rather than borrowing an unsupported SDK identity.

| Function | Selector | Behavior |
| --- | ---: | --- |
| `func_020ba0a4` | 1 | Store selector 1 and value zero through `func_020b8b18`; return 1. |
| `func_020ba0bc` | 2 | Store selector 2 and value zero through `func_020b8b18`; return 1. |
| `func_020ba0d4` | 3 | Store selector 3 and value zero through `func_020b8b18`; return 1. |
| `func_020ba0ec` | 4 | Store selector 4 and value zero through `func_020b8b18`; return 1. |
| `func_020ba104` | 5 | Store selector 5 and value zero through `func_020b8b18`; return 1. |
| `func_020ba11c` | 6 | Store selector 6 and value zero through `func_020b8b18`; return 1. |
| `func_020ba1b4` | 11 | Store selector 11 and value zero through `func_020b8b18`; return 1. |
| `func_020ba1cc` | 12 | Store selector 12 and value zero through `func_020b8b18`; return 1. |

## M2-T042: operand-supplied selectors

A further search for script dispatch wrappers in pret/pokeplatinum and zeldaret
public sources did not identify a matching implementation. No SDK provenance or
selector meaning is inferred from the directory classification.

Each entry below has no explicit parameters. Its original ARM instructions call
`func_0203ac00(0)`, pass the returned 32-bit value unchanged to
`func_020b8b18(selector, value)`, then return signed integer 1. The provider in
`src/game/unit_0203aae8.c` reads a zero-based operand from the implicit script
stack, resolving its tag and converting numeric values as needed. The wrapper
performs no additional narrowing or validation. The record remains owned by the
external provider; the wrappers acquire no storage.

| Function | Selector | Behavior |
| --- | ---: | --- |
| `func_020ba134` | 7 | Store operand zero with selector 7; return 1. |
| `func_020ba154` | 8 | Store operand zero with selector 8; return 1. |
| `func_020ba174` | 9 | Store operand zero with selector 9; return 1. |
| `func_020ba194` | 10 | Store operand zero with selector 10; return 1. |
| `func_020ba1e4` | 13 | Store operand zero with selector 13; return 1. |
| `func_020ba204` | 14 | Store operand zero with selector 14; return 1. |
| `func_020ba224` | 15 | Store operand zero with selector 15; return 1. |
| `func_020ba244` | 16 | Store operand zero with selector 16; return 1. |

## M2-T043: result-publishing requests

A public-source search of pret/pokeplatinum script-command interfaces found no
matching implementation. The existing neutral symbols remain; request-code
meanings and SDK provenance are not established.

| Function | Request code | Behavior |
| --- | ---: | --- |
| `func_020ba05c` | 104 | Submit `(104, 0, 0, 0)` through `func_020b8b38`, publish its result through `Unk03aae8_Unk_03acf4`, and return 1. |
| `func_020ba080` | 105 | Submit `(105, 0, 0, 0)` through `func_020b8b38`, publish its result through `Unk03aae8_Unk_03acf4`, and return 1. |

Both original 36-byte ARM bodies consume no incoming arguments and use the
implicit runtime context. The request helper at 0x020b8b38 writes four words to
work offsets 0x20 through 0x2c, calls `func_0204e9d8`, and normalizes its return
to 0 or 1. The result publisher at 0x0203acf4 clears active-work byte 0x3b and
stores the result word at 0xa8. These wrappers acquire no storage and do not
change ownership. Direct compilation and relocation-aware instruction comparison
against the ROM match both functions exactly.

## Validation

`python3 tools/match_gate.py` built successfully and verified all sixteen C
functions at 100% objdiff for M2-T042. M2-T043 verifies all eighteen definitions
at 100% with the same gate. `python3 tools/checksum.py` verified all artifacts
byte-identical to the original. `python3 tools/anticheat.py` passed, and
`python3 -m unittest discover -s tests -t . -q` passed all nine tests.
No new behavioral tests are required by this card; the original object is the
instruction-level acceptance reference.

## Hard list

None. All eighteen functions in this translation unit are implemented. The TU
continues to link from the delinked original until a human marks it complete.
