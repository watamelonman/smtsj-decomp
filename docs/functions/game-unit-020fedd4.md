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

## M1-T168

All eight targets match at 100% in the local objdiff report. `func_020fef0c` is new
C; the other seven already matched and now use the typed `Unk0fedd4Obj` layout,
real callee prototypes and contract comments.

| Function | Size | Evidence and contract |
| --- | --- | --- |
| `Unk0fedd4_SetUnk0c10` | 28 B | Calls the getter thunk and stores a at +0x0c and b at +0x10. Meaning unknown. |
| `Unk0fedd4_SetState2` | 28 B | Stores 2 at +0x14 and 1 at +0x20. The update `func_020ff034` checks +0x20 when the state is 2 and clears it. |
| `Unk0fedd4_Unk_0fee18` | 32 B | If `data_02176e28` is non-null, passes it to `func_02061424` (the task release call). |
| `Unk0fedd4_Alloc` | 40 B | If `data_02176e28` is null, stores the result of `func_020fef0c(arg)` in it. |
| `Unk0fedd4_Unk_0fee38` | 48 B | Calls `func_02061f10(obj->handle, -1, 0, 0, arg)`. Meaning unknown. |
| `func_020fef0c` | 108 B | Calls `func_020611dc(Unk0ff030_Nop_0ff030, func_020ff034, 0, Unk0fedd4_Unk_0fef78, 36, 3, 0, 1)` (literal pool at 0x020fef6c). Returns 0 on failure; otherwise calls `Unk0fedd4_Unk_0fefc8(obj, arg)` and returns obj. Keeps its symbol-table name. |
| `Unk0fedd4_Unk_0fef78` | 80 B | Destroy callback: if +0x00 is set, frees the +0x04 handle (`func_020629c4`); if +0x08 is set, frees it (`func_0205ddb4`); then clears `data_02176e28`. |
| `Unk0fedd4_Unk_0fefc8` | 104 B | Init: stores arg at +0x00, zeroes +0x04/+0x0c..+0x14/+0x1c/+0x20 and sets +0x18 to -1. Only when arg is non-zero does it set +0x04 = `func_020629ac(5, 2, 1, 1)`. The `beq` at 0x020feffc skips only that call, so +0x08 = `func_0205dcd4(data_021510f4, 1)` always runs. |

## Hard list

None.
