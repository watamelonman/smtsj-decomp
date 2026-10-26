# libs/unknown/lib_020b91a8

## Evidence and source search

The public-source search considered NitroSDK/MSL implementations in pret/pokeplatinum
and zeldaret; no matching implementation was identified. Despite the library path,
these wrappers call the game's interpreter helpers: `func_0203ac00` reads a
stack value (including float-to-integer conversion), `func_020b8b38` writes four
words at work offsets 0x20–0x2c and submits them to `func_0204e9d8`, and
`Unk03aae8_Unk_03acf4` clears the interpreter tag at 0x3b and stores the result
at 0xa8. These local ARM instructions are the evidence for the contracts below.
The meaning of each numeric code remains unknown; original neutral symbols are retained.
No module boundary changes or new dependencies are introduced.

All thirteen entry points take no parameters and return signed integer 1 after
publishing the submission result. The one-value forms read stack index 0 first.
They require the shared interpreter and submission work state to be initialized.

## Functions

| Symbol | Original size | Submitted code | Submitted arguments |
| --- | --- | --- | --- |
| `func_020b91a8` | 44 bytes | 25 | stack[0], 0, 0 |
| `func_020b91d4` | 36 bytes | 26 | 0, 0, 0 |
| `func_020b91f8` | 36 bytes | 27 | 0, 0, 0 |
| `func_020b921c` | 36 bytes | 28 | 0, 0, 0 |
| `func_020b9240` | 44 bytes | 29 | stack[0], 0, 0 |
| `func_020b926c` | 44 bytes | 30 | stack[0], 0, 0 |
| `func_020b9298` | 44 bytes | 31 | stack[0], 0, 0 |
| `func_020b92c4` | 44 bytes | 32 | stack[0], 0, 0 |
| `func_020b92f0` | 44 bytes | 33 | stack[0], 0, 0 |
| `func_020b931c` | 44 bytes | 34 | stack[0], 0, 0 |
| `func_020b9348` | 44 bytes | 35 | stack[0], 0, 0 |
| `func_020b9374` | 44 bytes | 36 | stack[0], 0, 0 |
| `func_020b93a0` | 44 bytes | 37 | stack[0], 0, 0 |

The follow-up public-source search for this unit and its submission helper in
pret/pokeplatinum returned no matching source. The five remaining wrappers use
the same interpreter-specific call sequence, as confirmed directly in ARM code.

## Validation

`python3 tools/match_gate.py` builds the project and confirms 100% objdiff
matches for all thirteen definitions (548 bytes total), including the five 44-byte wrappers
for codes 33–37 added by M2-T090.

`python3 tools/anticheat.py` passes, the nine existing unit tests pass via
`python3 -m unittest discover -s tests -t . -q`, and
`python3 tools/checksum.py` reports all artifacts byte-identical to the original.
The unit remains linked from the delinked object pending human completion marking.
No new tests were required by this card; objdiff checks the generated instructions
against the original implementation.

## Hard list

None.
