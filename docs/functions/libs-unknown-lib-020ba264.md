# lib_020ba264 — M2-T056

The eight selected ARM functions are script handler wrappers, despite the library
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

## Validation

The match gate compares all eight compiled functions with the delinked originals.
The TU remains linked from the delink until a human marks it complete.
No new behavioral tests are required by the card; the existing test suite,
anticheat gate and full-image checksum are run alongside the match gate.

## Hard list

None of the eight requested functions.
