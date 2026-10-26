# lib_020ba264 — M2-T056 / M2-T057

The selected ARM functions are script handler wrappers, despite the library
path assigned by the split. Existing `game/unit_0203c274` and
`game/unit_0203aae8` identify argument retrieval and result publication through
the same helpers. A public-source search for NitroSDK/pret counterparts found
no matching source; the calls into the game script interface support reconstructing
these directly rather than attributing them to SDK middleware.

Original neutral `func_` symbols are retained because the symbol configuration is
human-owned. All handlers take no explicit parameters and return completion 1.
The underlying meaning of the selected IDs and query values remains unresolved.

| Function | Instruction evidence and contract |
| --- | --- |
| `func_020ba264` | 0x020ba264–0x020ba284: reads script argument 0 and forwards it to `func_020b8b18` with ID 17. |
| `func_020ba284` | 0x020ba284–0x020ba2a4: reads script argument 0 and forwards it with ID 18. |
| `func_020ba2a4` | 0x020ba2a4–0x020ba2c4: reads script argument 0 and forwards it with ID 19. |
| `func_020ba2c4` | 0x020ba2c4–0x020ba2e4: reads script argument 0 and forwards it with ID 20. |
| `func_020ba344` | 0x020ba344–0x020ba35c: publishes `Unk0afc28_CountById(1)` through the implicit script-result helper. |
| `func_020ba35c` | 0x020ba35c–0x020ba374: publishes `Unk0afc28_CountById(2)` through the implicit script-result helper. |
| `func_020ba374` | 0x020ba374–0x020ba390: passes `func_020b8ad8()` and field selector 0 to `func_02049d80`, then publishes its result. |
| `func_020ba390` | 0x020ba390–0x020ba3a4: publishes the result of `Unk03e43c_Unk_03fa28()`. |

## M2-T057 additions

A fresh public-source search for these addresses and the shared helper in
pret/pokeplatinum found no counterpart. The original ARM instructions again
identify game script handlers, rather than known SDK routines. Existing source
was preserved, and the eight missing bodies were added. Neutral configured
symbols are retained; request, selector and field meanings remain unresolved.
No new module boundary or ownership transfer is introduced.

| Function | Instruction evidence and contract |
| --- | --- |
| `func_020ba2e4` | 0x020ba2e4–0x020ba304: reads operand 0, forwards it with selector 21, returns completion 1. |
| `func_020ba304` | 0x020ba304–0x020ba324: reads operand 0, forwards it with selector 22, returns completion 1. |
| `func_020ba324` | 0x020ba324–0x020ba344: reads operand 0, forwards it with selector 23, returns completion 1. |
| `func_020ba3a4` | 0x020ba3a4–0x020ba3c8: reads a halfword at `func_020b8ad8()` +0x1d8, resolves it through `func_020a1428`, and publishes byte +5 of the borrowed record. Returns 1. |
| `func_020ba3c8` | 0x020ba3c8–0x020ba3f0: obtains provider storage before reading operand 0, then publishes the indexed 32-bit word at +0x30. Script supplies a valid index; returns 1. |
| `func_020ba3f0` | 0x020ba3f0–0x020ba420: obtains provider storage, reads index/value operands 0/1 in order, and writes the indexed word at +0x30. Storage remains provider-owned; script supplies a valid index; returns 1. |
| `func_020ba420` | 0x020ba420–0x020ba450: reads signed divisor operand 0, loads the unsigned halfword at provider +0x38, and publishes its signed remainder. The `_s32_div_f` call and move from r1 establish remainder rather than quotient. Divisor must be nonzero; returns 1. |
| `func_020ba450` | 0x020ba450–0x020ba474: dispatches request 106 with three zero arguments, publishes its result, and returns 1. |

The private five-byte-prefix record view expresses only the observed byte load.
Other provider addresses retain word-sized declarations consistent with their
existing definitions. Loads and stores use the instruction-established offsets.

## Validation

The match gate compares all sixteen compiled functions with the delinked originals.
The TU remains linked from the delink until a human marks it complete.
No new behavioral tests are required by the card; the existing test suite,
anticheat gate and full-image checksum are run alongside the match gate.

## Hard list

None of the requested functions.
