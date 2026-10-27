# sdk_0204f520 command wrappers

## Evidence and interpretation

These functions build 56-byte stack messages and call `func_0204f098`.
The initializer at `0204f0a4` clears 56 bytes, stores its last three inputs
at +4/+8/+12, and sets byte +16 to one. The wrappers pass their second
input into both middle initializer parameters. The word payload begins at
+20. The struct describes only these observed offsets; it is private to
this translation unit and introduces no shared ownership contract.

A public-source search for NitroSDK command wrappers did not establish a
matching implementation. The path's SDK classification does not establish
the message domain. Existing neutral `func_` symbols are retained rather
than assigning unsupported SDK API names. All behavior below is evidenced
by the original instructions at the corresponding function address.

## Functions

| Symbol | Observed behavior | Match |
| --- | --- | --- |
| `func_0204f520` | Command 16; clears byte +16 when third input is zero. | 100% |
| `func_0204f560` | Command 17; fixes middle routing values to 65536 and writes argument at +20. | 100% |
| `func_0204f59c` | Command 18 with argument at +20; then calls `Unk118b04_Unk_118e50(4, argument)`. | 100% |
| `func_0204f5e0` | Command 19 with argument at +20. | 100% |
| `func_0204f618` | Command 20 with argument at +20. | 100% |
| `func_0204f650` | Caller-selected command and argument at +20. | 100% |
| `func_0204f728` | Caller-selected command; leaves initialized payload intact. | 100% |
| `func_0204f758` | Command 11; leaves initialized payload intact. | 100% |

| `func_0204f68c` | Command 23 on both sides of a signed selector comparison; copies twelve payload bytes to +20. | 100% |
| `func_0204f6d8` | Command 24 for signed selectors 1..11, otherwise keeps the initialized command; copies twelve payload bytes. | 100% |
| `func_0204f788` | Command 25; copies three unsigned halfwords to +20/+22/+24. | 100% |

For M2-T230, source was also searched in
[ntrtwl/NitroSDK](https://github.com/ntrtwl/NitroSDK) (`libraries/` command
providers); no matching public implementation was established. The domain
therefore remains unnamed. Payload inputs are borrowed only for the duration
of the call. See DEC-035 for instruction-preserving source choices.

## Validation

All eleven functions match the delinked originals at 100% in objdiff.
`python3 tools/match_gate.py`, `python3 tools/anticheat.py`, the nine-test
unittest suite, and `python3 tools/checksum.py` pass. The checksum gate
reports all artifacts byte-identical to the original.
The card requires no new runtime tests; these wrappers depend on existing
providers, and object comparison checks exact calls, offsets and control flow.

## Hard list

None. All eleven reconstructed wrappers remain linked from the original
delinked object until a human marks the TU complete.
