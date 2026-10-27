# sdk_0205ea18 — M2-T326 / M2-T327

Public NitroSDK source was searched first; no matching source was identified.
The neighbouring unit also contains application helpers, so the path alone is
not evidence of SDK provenance. Existing symbol names are retained.
Evidence below comes from ARM instructions in `extract/arm9/arm9.bin` and the
original object `build/delinks/libs/NitroSDK/sdk_0205ea18.o`.
No public module boundary is added: the borrowed state view is private to this TU.

| Function | Evidence and contract | Status |
| --- | --- | --- |
| `func_0205ecc8` | Loads the signed word at global `data_0216b428 +4`; no storage is transferred. | Exact match |
| `func_0205ecd8` | Loads the signed word at global +0; neighbouring protocol code tests it for zero. | Exact match |
| `func_0205ece8` | Clears global +8 then +4; retains all other fields. | Exact match |
| `func_0205eae0` | Guards duration zero and both endpoints, then returns `start + (end-start)*position/duration`. Units must agree and intermediate arithmetic must fit signed int. | Exact match |
| `Unk_InterpolateLinear` | Despite its existing name, uses a signed halfword from the table at `0x0212629c`, indexed by `((position<<14)/duration)>>4` with four-byte stride, then multiplies by the endpoint span and shifts by 12. Same endpoint guards as the linear helper. | Hard; remains delinked |
| `func_0205eb78` | Same table interpolation, adding `0xc000` to the angle and 4096 to the sampled value before the Q12 multiply. | Hard; remains delinked |
| `func_0205ede8` | Switches on global +8: phase zero clears +12, checks enabled/provider availability, and sets +8/+4 to one; phase one polls `func_02051210`, retaining phase one for result 2; other phases call `func_02050e80`, clear +4 and return one. Pending returns zero. | Hard; remains delinked |
| `func_0205ea18` | Orders signed endpoints, returns the high endpoint for period zero, otherwise folds the absolute phase remainder into a triangular span. The fifth argument reverses the fold. Nonzero periods must be positive and at least two; intermediate arithmetic, including phase negation, must fit int. | Exact match |

| `func_0205ebd8` | Clears result/enabled, borrows a pointer to `count` 24-byte records, checks provider/resource availability, enables and configures the provider, then registers each slot using record words +0/+4/+12/+16. Returns zero on any failed check, one after resetting phase/busy. Records must remain valid for later processing; no allocation or ownership transfer occurs. | Exact match (240 bytes, 100%) |
| `func_0205ed00` | Phase zero clears result, checks enabled/provider availability, sets busy, and records `func_02051040`'s result. Unless that result is 3 or 4, walks records whose +20 word is nonzero and invokes `func_020510f4(index)`, stopping on a result other than 1. Advances phase and returns zero. Other phases shut down the provider, clear busy and return one; unavailable providers return one immediately. | Exact match (232 bytes, 100%) |

M2-T327 repeated the public-source search before reconstruction; no matching
NitroSDK implementation was identified. The provider protocol and application
record layout do not establish a public SDK identity, so existing neutral
symbols are retained. Both new functions match the original ARM instructions
and relocations; no public module boundary is added.

## Hard list

- `Unk_InterpolateLinear` (88 bytes): reconstructed endpoint guards, Q12 table
  sampling and arithmetic. Tested separate span/sample locals, staged updates,
  signed/unsigned index forms, array and pointer indexing, and explicit division.
  Closest candidate matches every instruction except the table load base/index
  operand order (`ldrsh r0,[r1,r0]` instead of `[r0,r1]`). The original table
  literal has no relocation; inventing an external table symbol would be wrong.
- `func_0205eb78` (96 bytes): same experiments and single load-operand mismatch
  as the preceding interpolator, including the exact angle and sample biases.
- `func_0205ede8` (156 bytes): reconstructed the entire three-phase switch.
  Tested local switch/result variables and both struct/array global views.
  Closest candidate uses r0/r1 for the initial global pointer/phase, while the
  original uses r1/r2. Remaining instruction sequence and size agree.

These three definitions are omitted so the original delink continues providing
all three functions. A human can use `tools/decompme.py` for further matching.
M2-T327 supplies `func_0205ebd8` and `func_0205ed00` in readable C; both match exactly.
