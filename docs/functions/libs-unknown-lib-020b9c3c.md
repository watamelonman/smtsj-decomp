# lib_020b9c3c

The public-source search considered pret/pokeplatinum and NitroSDK/NitroSystem
implementations; no corresponding source was identified. Despite the library split
name, these functions call the game script helpers at 0x0203ac00 and 0x0203acf4.
The original ARM instructions are the behavior evidence; no SDK identity is assumed.
The existing neutral symbol name `Unk03aae8_Unk_03acf4` for the result helper is
retained, matching `config/arm9/symbols.txt` and the rest of the tree, so the C
relocates against the same symbol as the delinked original.

Each handler takes no explicit parameters, reads 32-bit script operand words,
calls `func_020b8b38(command, operand0, operand1, 0)`, publishes its return value
through `Unk03aae8_Unk_03acf4`, and returns status 1. The result helper stores the word at
script context +0xa8 and clears the byte at +0x3b. The dispatcher stores its four
arguments in a work record at +0x20 through +0x2c before calling 0x0204e9d8.
These observations do not establish the semantic meanings of the command IDs.

| Function | Command | Script operand indices | Original size |
| --- | --- | --- | --- |
| `func_020b9c3c` | 80 | 0, 1 | 56 bytes |
| `func_020b9c74` | 81 | 0, 1 | 56 bytes |
| `func_020b9cac` | 82 | 0, 1 | 56 bytes |
| `func_020b9ce4` | 83 | 0, 1 | 56 bytes |
| `func_020b9d1c` | 84 | 0, 1 | 56 bytes |
| `func_020b9d54` | 85 | 0, 1 | 56 bytes |
| `func_020b9d8c` | 86 | 0 (operand1 is zero) | 44 bytes |
| `func_020b9db8` | 87 | 0 (operand1 is zero) | 44 bytes |
| `func_020b9de4` | 88 | 0 (operand1 is zero) | 44 bytes |
| `func_020b9e10` | 89 | 0 (operand1 is zero) | 44 bytes |

M2-T025 adds the handlers at 0x020b9d1c and 0x020b9d54. Their original
ARM calls establish command IDs 84 and 85 respectively, operand reads in order
0 then 1, a zero fourth dispatcher argument, result publication, and status 1.
A further public-source search for the dispatcher and handler addresses found no
matching implementation; the game-specific instruction evidence remains authoritative.
No module boundary changes or new dependencies are introduced.

## Validation

- `python3 tools/match_gate.py`: all ten C functions match at 100%, including both M2-T025 handlers.
- `python3 tools/checksum.py`: all artifacts byte-identical to the original.
- `python3 tools/anticheat.py`: passed.
- `python3 -m unittest discover -s tests -t . -q`: nine tests passed.

No new tests were added: both cards set `tests_required = false`; the original
machine code provides the exact acceptance oracle. The TU remains incomplete in
the human-owned delink configuration, as required.

## Hard list

None of the ten functions required deferral.
