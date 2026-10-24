# game/unit_02115fbc

All seven functions match the original ARM code at 100% objdiff. Names remain
neutral because field accesses and callees establish behavior but do not establish
the subsystem's purpose. The existing `func_` symbols are retained to agree with
the human-owned symbol configuration.

## Function entries

| Function | Bytes | Contract and evidence |
| --- | ---: | --- |
| `func_02115fbc` | 108 | Requires a non-null 28-byte work block. The loop at 0x02115fcc reads three pointers at +0x10, releases non-null items through `func_0205c3dc`, and clears them. It then releases and clears +8 and +0xc using their distinct destructors. |
| `func_02116028` | 208 | Returns a work block or null if allocation fails. The call at 0x02116058 supplies callbacks at 0x02115ca0, 0x02115e20, and 0x02115fbc, size 28, alignment 4, and zero auxiliary arguments. It clears the first two words, loads resources via `data_02151afc` and `data_02151b10`, then creates, binds, indexes, and finalizes three items. Resource-call failure handling follows the original; there are no added checks. |
| `Unk115fbc_Unk_1160f8` | 60 | Requires the external state accessor to return valid storage. Formats operand zero from `Unk03aae8_Unk_03ac9c` with `data_02151b24` into the 32-byte buffer at +0x54, sets +0x48 to 1, and returns 3. These offsets, capacity, and return value are present directly in the original instructions. |
| `Unk115fbc_Unk_116134` | 52 | Requires valid external state. Sets +0x4c to 1 and +0x50 to the result of comparing `func_0203ac00(0)` with zero; returns 1. The stores and conditional values provide the behavior evidence. |
| `func_02116168` | 152 | Takes an unsigned category and signed integer ID. Categories 0, 1, and 2 map to packed types 0, 2, and 1; category 3 returns the word at table +0x8c. Other categories use type 0. Scans ten optional pointers at +0x64 for a matching bits-16-through-23 type and halfword at record +0x1d8. Returns the packed first word on success or 0xffff when absent. Evidence is the original jump table, ten-iteration loop, shifts, and halfword load. |
| `func_02116200` | 196 | Reads three signed operands, resolves the first two through `func_02116168`, and returns 1 without updating state when the packed type is zero. Otherwise caps operand two at count minus one using a signed comparison, invokes `func_0204f59c`, `func_0204f24c` with mode 0, and `func_0204f364`, sets state +0x48, and returns 3. No lower bound is introduced: the original only applies an upper cap. |
| `func_021162c4` | 156 | Reads three operands and resolves the record as above. A zero packed type returns 1. Otherwise forwards the third operand without clamping to `func_0204f5e0` and `func_0204f24c` with mode 2, sets state +0x48, and returns 3. Evidence is the original call arguments and early-return test. |

## Layout and ownership

The TU uses private partial views, not shared subsystem declarations. Work-block
pointers at +8, +0xc, and +0x10 are owned resources, as evidenced by creation and
cleanup in this pair of functions. The state, table, and records are borrowed
from accessors; no ownership transfer is inferred. Padding represents unobserved
fields, and the three-item and ten-record array lengths come directly from loops.
No module boundary changes are introduced.

## Validation

- `python3 tools/match_gate.py`: all seven functions report 100%.
- `python3 tools/anticheat.py`: passed.
- `python3 -m unittest discover -s tests -t . -q`: nine tests passed.
- `python3 tools/checksum.py`: all artifacts byte-identical to the original.

The match gate builds the project before comparing objects. The task does not
require new tests; the original instructions and objdiff are the behavior oracle.
The TU remains linked from its delinked object until a human marks it complete.

## Hard list

None. No requested function was left out.
