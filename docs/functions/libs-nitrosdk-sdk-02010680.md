# sdk_02010680

This partial C unit implements the eight card functions. The remaining routines
and the linked image still come from the delink; completion configuration is
human-owned. All eight entries below report 100% in `build/report.json`.

Public-source search: searched for NitroSDK WM accessor/callback implementations
in pret/pokeheartgold and pret/pokeplatinum. Network retrieval did not provide a
usable source during this task. The implementation therefore follows the local
delinked instructions; original `func_` symbols are retained without speculative
SDK API names.

| Function | Instruction evidence and contract | Match |
| --- | --- | --- |
| `func_02010680` | Loads global `data_02154c40` +4, stores a callback at work +0x18 + index*4. Caller supplies a valid index and borrowed callback. | 100% |
| `func_0201079c` | Returns the provider-owned pointer at global +4; no allocation. | 100% |
| `func_020107ac` | Reads the unsigned halfword at global +0; returns 0 when nonzero, otherwise 3. | 100% |
| `func_020108a4` | Saves interrupt state through `func_02007a58`, reads work +0x150 as an unsigned halfword (zero if work is absent), restores state through `func_02007a6c`. Returns a 32-bit zero-extended value. | 100% |
| `func_020108d4` | Uses the same interrupt protection, reads a full word at work +0x14c (zero if absent), truncates to 16 bits after restoring state. | 100% |
| `func_02010c34` | Literal indirect tail call to `func_02010bec`, forwarding caller-owned work and returning the signed status. | 100% |
| `func_02010cbc` | Literal indirect tail call to argument-free `func_02010c84`, returning its signed status. | 100% |
| `func_02010dd0` | Reads the provider pointer at `data_02155720` and returns its nonzero test as 0 or 1. | 100% |

The work/global layout views remain private to the C unit. The callback table's
17-entry extent follows the neighboring command-index stores (including index
16 at 02010bd0);
only the eight selected functions are reconstructed here. No ownership changes.

Validation: match gate, anticheat gate, nine existing unit tests, and checksum
gate all passed. The first comparison of `func_020108a4` exposed redundant
return narrowing with a 16-bit result type; the original uses a 32-bit result.
No new tests are required by this card; instruction identity checks all eight
function bodies against the original object.

Hard list: none of the eight requested functions.
