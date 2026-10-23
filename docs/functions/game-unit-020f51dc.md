# game/unit_020f51dc — M1-T721

All eight functions match at 100%. Names are retained from the symbol map;
helper purposes remain uncertain, so no new descriptive symbols are introduced.
Evidence below is the original ARM instruction stream at each function address.

| Function | Contract and evidence |
| --- | --- |
| `Unk0f51dc_Unk_0f623c` | Calls `func_02057eb8(-1)`, then `func_020572d8()`. Evidence: MVN of zero followed by the two BLs. |
| `Unk0f51dc_Unk_0f5738` | Forwards signed coordinates to `func_020f6250(6, x, y, 17)`. Evidence: register shuffle and constants before the tail call; coordinate callers also appear in unit_020f09b4. |
| `Unk0f51dc_Unk_0f5dfc` | Same forwarding contract with selector 10. Evidence: constants 10 and 17 before the tail call. |
| `Unk0f51dc_Unk_0f5ab4` | Same forwarding contract with selector 17. Evidence: r0 is set to 17 and copied into r3 before the tail call. |
| `Unk0f51dc_Unk_0f621c` | Calls `func_02057e18(31)`, `func_02057ddc(-1)`, then `func_02057524(4)`. Evidence: three constant loads and ordered BLs. |
| `Unk0f51dc_Unk_0f57d4` | Forwards five arguments and appends `(0, 8, 0)` to `func_020f58bc`. Evidence: fifth argument loaded from the incoming stack and four outgoing stack stores. |
| `func_020f5754` | First argument indexes `Unk0ea208_GetArr58`; null returns immediately. The low five bits of word +0x24 provide the outgoing seventh argument, except kind 8 converts bits 12–16 through `Unk0f7eb4_Unk_0f7eb4`. Appends zero and byte +0x22 while forwarding the original five arguments. Evidence: LSL/LSR pairs, compare against 8, conditional branch over conversion, LDRB and outgoing stores. The record is borrowed. |
| `func_020f5ad4` | Zero alpha or zero shared handle returns immediately. Caller must provide a valid index into `data_0213c954`. Submits the selected entry through `func_0205de40` with mode 2, unit scales, zero extra value and order 16. For flag zero and index 2, replaces alpha with 0.84f. Evidence: `_feq`, shared-handle null check, indexed LDR, literal 0x3f570a3d and outgoing argument stores. |

## Hard list

None.
