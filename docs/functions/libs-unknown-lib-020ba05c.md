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

## Validation

`python3 tools/match_gate.py` built successfully and verified all eight
functions at 100% objdiff. `python3 tools/checksum.py` verified all artifacts
byte-identical to the original. `python3 tools/anticheat.py` passed, and
`python3 -m unittest discover -s tests -t . -q` passed all nine tests.
No new behavioral tests are required by this card; the original object is the
instruction-level acceptance reference.

## Hard list

None of the eight requested functions. Other functions in this translation
unit remain supplied by the delinked original, as required by the card.
