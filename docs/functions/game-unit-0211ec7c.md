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

## M1-T317: the rest of the TU

All seven functions are 100% in the objdiff report, so the whole TU is now C. The file
is reordered by address. `Unk11ec7cWork` now runs to 0x31c bytes. `func_0211eccc` stores
0x31c as the descriptor's work size, so that size is confirmed. `unk_0020` is a float:
it gets `(float)n / 10.0f` and `1.0f`.

| Function | Original address / size | Behavior and naming evidence |
| --- | --- | --- |
| `Unk11ec7c_Unk_11ec7c` | `0x0211ec7c` / 80 | Already matched. Now takes the typed work pointer. Releases the +0x26c, +0xa8 and +0xb0 handles through `func_02053000` and zeroes them. If +0x274 is set, calls `Unk044394_Unk_044534(0x24)`. It is slot +0x1c of the descriptor. |
| `func_0211eccc` | `0x0211eccc` / 92 | Fills `Unk11ec7cDesc`: +0 = 0x31c (work size), +4 = 1, +0xc..+0x20 = `func_0211de14`, `func_0211e0ec`, `func_0211e260`, `func_0211e6b8`, `Unk11ec7c_Unk_11ec7c`, `func_0211dc74`. |
| `func_0211ed28` | `0x0211ed28` / 120 | Work init. Sets +0x274 to 1 only if it had to register entry 0x24 (`Unk044394_HasEntry` / `Unk044394_Unk_044428`). Stores `func_0204459c(0x26)` at +0x270 and `func_02051610(data_02151f98)` at +0x26c, clears +4, +0x2e4, +0x268, +0xa8, +0xb0 and +0x318, then calls `func_02119390`. |
| `func_0211eda0` | `0x0211eda0` / 112 | Zeroes a 16-halfword buffer, has `func_0203546c(buf, 16, global +0x35c)` fill it, and passes it to `func_02061f10(handle, -1, 0, 0, buf)`. The `= {0}` initializer gives the ROM's unrolled store loop; a `for` loop does not. |
| `func_0211ee10` | `0x0211ee10` / 124 | With n = +0x1c - 2 > 0: gets record 1 of handle +4 (`func_0205e318`). If `scale == 1`, sets +0x24 = record s16 +0xc * n / 10. Always sets +0x20 = n / 10.0f. Otherwise it clears both. |
| `func_0211eea8` | `0x0211eea8` / 96 | State 1 tick, called by Dispatch. Increments +0x1c and calls `func_0211ee10(work, 1)`. At 12 or more: queues state 2, clears +0x18, sets +0x1c = 12, +0x24 = record +0xc, +0x20 = 1.0f. |
| `Unk11ec7c_Unk_11f004` | `0x0211f004` / 104 | Already matched. Now takes the typed work pointer. If +0 is not 1: zero-fills 0x28 bytes, sets +0 = 1, clears +0xc/+0x10, loads handles +4 (`func_0205dcd4(data_02151fb4, 1)`) and +8 (`func_020629ac(5, 1, 1, 1)`). |

All names stay neutral because nothing shows what the module is for.

## Hard list

None.
