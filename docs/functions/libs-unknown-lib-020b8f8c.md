# lib_020b8f8c script wrappers (M2-T073)

## Evidence and interpretation

Despite the library path, these functions call the game's implicit script argument
reader (`func_0203ac00`) and result writer (`Unk03aae8_Unk_03acf4`).
The latter stores its input at script-state offset 0xa8 and clears the byte at
0x3b. The shared worker (`func_020b8b38`) stores its four arguments at offsets
0x20 through 0x2c of the current work record, calls `func_0204e9d8`, and returns
whether that call returned nonzero. No selector meaning is established here.

A public-source search covered NitroSDK/NitroSystem and pret script handlers,
including [pokeplatinum's script wrappers](https://github.com/pret/pokeplatinum/blob/main/src/scrcmd_amity_square.c).
No matching implementation was found. The direct calls into this game's script
state support treating these as game-specific wrappers rather than SDK routines.
Existing neutral symbols are retained to match the human-owned symbol map.

Each entry point has no C parameters: its input comes from active script argument
zero. It submits `(selector, argument, 0, 0)`, publishes the Boolean worker result,
and returns 1. Original ARM instructions provide the evidence for each contract.

## Functions

| Symbol | Selector | Contract / evidence |
| --- | --- | --- |
| `func_020b8f8c` | 12 | Reads argument 0, submits selector 12, stores result, returns 1; ARM at `0x020b8f8c`. |
| `func_020b8fb8` | 13 | Reads argument 0, submits selector 13, stores result, returns 1; ARM at `0x020b8fb8`. |
| `func_020b8fe4` | 15 | Reads argument 0, submits selector 15, stores result, returns 1; ARM at `0x020b8fe4`. |
| `func_020b9010` | 16 | Reads argument 0, submits selector 16, stores result, returns 1; ARM at `0x020b9010`. |
| `func_020b903c` | 17 | Reads argument 0, submits selector 17, stores result, returns 1; ARM at `0x020b903c`. |
| `func_020b9068` | 18 | Reads argument 0, submits selector 18, stores result, returns 1; ARM at `0x020b9068`. |
| `func_020b90cc` | 20 | Reads argument 0, submits selector 20, stores result, returns 1; ARM at `0x020b90cc`. |
| `func_020b90f8` | 21 | Reads argument 0, submits selector 21, stores result, returns 1; ARM at `0x020b90f8`. |

## Validation

The delinked originals are the behavioral and instruction-level oracle; this card
requires no new unit tests. Objdiff must report 100% for all eight wrappers, with
anticheat, repository tests, and checksum gates also run locally. The TU stays
incomplete in the human-owned delink configuration as required by the card.

## Hard list

None for M2-T073. Other functions in the same TU belong to separate cards and
remain supplied by the delinked original.
