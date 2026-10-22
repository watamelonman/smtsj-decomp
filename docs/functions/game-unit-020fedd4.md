# src/game/unit_020fedd4.c

## M1-T167

All eight targets match at 100% in the local objdiff report. The existing C
already matched; this card adds contracts and a typed 05b82c callee declaration.
Evidence below is from the delinked original's instructions and relocations.
The singleton is borrowed; setters require it to have been allocated.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `Unk0fedd4_Thunk_0205bb68` | 12 B | Tail call through the relocation at 0x020fedec to `func_0205bb68`; no arguments. |
| `Unk0fedd4_Thunk_020feef0` | 12 B | Tail call through the relocation at 0x020fef08 to `Unk0fedd4_GetObj`; returns the borrowed pointer, possibly null. |
| `Unk0fedd4_Unk_0fedd4` | 16 B | Loads r0 with 0xd1 at 0x020fedd8 and tail calls `Unk05b82c_Unk_05b82c`. The callee's C definition takes an integer id and returns void; higher-level purpose remains unknown. |
| `Unk0fedd4_GetObj` | 16 B | Loads the pointer from `data_02176e28` at 0x020feef0–0x020feef4; returns it without changing ownership or checking for null. |
| `Unk0fedd4_SetUnk1c` | 20 B | Calls the getter thunk and stores the supplied u32 at +0x1c (0x020fee90). Field meaning remains unknown. |
| `Unk0fedd4_SetState1` | 20 B | Calls the getter thunk and stores 1 at +0x14 (0x020feea4). State names describe only the observed numeric store. |
| `Unk0fedd4_SetState1b` | 20 B | Separate entry point with the same store of 1 at +0x14 (0x020feeb8). No evidence distinguishes its higher-level role. |
| `Unk0fedd4_SetState0` | 20 B | Calls the getter thunk and stores 0 at +0x14 (0x020feecc). State meaning remains unknown. |

No M1-T167 hard targets remain. Existing symbol names are retained; no semantic
meaning is inferred beyond the loads, stores, and forwarding targets above.

## Other functions already present (outside M1-T167)

The same report also shows 100% for `Unk0fedd4_Unk_0fee38`,
`Unk0fedd4_SetUnk0c10`, `Unk0fedd4_SetState2`, `Unk0fedd4_Alloc`,
`Unk0fedd4_Unk_0fee18`, `Unk0fedd4_Unk_0fef78`, and `Unk0fedd4_Unk_0fefc8`.
Their bodies are preserved by this card.

## Hard list

- `func_020fef0c`: no C body in this TU; outside M1-T167.
