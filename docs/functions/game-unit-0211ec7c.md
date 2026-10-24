# game/unit_0211ec7c

## M1-T316 — matched callbacks

All eight functions below are 100% in the objdiff report. Work pointers are
borrowed, non-null views; no ownership is transferred. Field names remain neutral
because the state machine's user-facing purpose is not established.

| Function | Original address / size | Behavior and naming evidence |
| --- | --- | --- |
| `Unk11ec7c_Nop_11ef08` | `0x0211ef08` / 4 | Only returns; the empty body supports Nop. State 2 entry in ApplyNext calls it. |
| `Unk11ec7c_Unk_11efec` | `0x0211efec` / 24 | Calls `Unk02e000_Unk_02e0cc`, then `Unk05b82c_Unk_05b82c(0xd2)`, and returns 1. No work argument. |
| `Unk11ec7c_Unk_11ee8c` | `0x0211ee8c` / 28 | Passes work words +4 and +8 to `func_0205dde4` and `func_0211eda0`, respectively. |
| `Unk11ec7c_Unk_11ef0c` | `0x0211ef0c` / 32 | Increments unsigned +0x18, compares against unsigned +0x14, and queues state 3 at +0x10 when greater. |
| `Unk11ec7c_Update` | `0x0211f06c` / 52 | The +0 active word gates execution. Applies a pending state unless +0x10 is -1, then dispatches. These calls support Update. |
| `Unk11ec7c_ApplyNext` | `0x0211ef74` / 60 | Copies pending +0x10 to current +0xc and restores the -1 sentinel. Enters state 1 through `Unk11ec7c_Unk_11ee8c`, state 2 through Nop. The copy and entry calls support ApplyNext. |
| `Unk11ec7c_Dispatch` | `0x0211efb0` / 60 | Switches on +0xc: state 1 calls `func_0211eea8`, state 2 calls `Unk11ec7c_Unk_11ef0c`, state 3 calls `Unk11ec7c_Unk_11ef2c`. Other values return. The callback switch supports Dispatch. |
| `Unk11ec7c_Unk_11ef2c` | `0x0211ef2c` / 72 | Decrements signed +0x1c, calls `func_0211ee10(work, 0)`, then rechecks +0x1c. When nonpositive, clears +0x10..+0x20 words and the +0x24 halfword. |

The typed work view preserves the observed offsets and distinguishes the signed
pending-state sentinel from the unsigned elapsed counter. No module boundary changed.
No new tests are required by this card; objdiff checks the generated instructions.

## Other existing functions

`Unk11ec7c_Unk_11ec7c` and `Unk11ec7c_Unk_11f004` remain as supplied.
The remaining delinked functions (`func_0211eccc`, `func_0211eea8`,
`func_0211eda0`, `func_0211ed28`, `func_0211ee10`) belong to M1-T317.

## Hard list

None for M1-T316.
