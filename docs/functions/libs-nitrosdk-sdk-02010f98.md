# NitroSDK unit 02010f98

Public-source lookup: the unit was checked against the NitroSDK OS/PXI shapes already
documented in this repository (the neighbouring `sdk_020116a8` message pump, the
`OS_InitIrqTable`/interrupt-restore helpers and the PXI tag wrappers in `sdk_0200d380`).
These sixteen helpers are small register-shape routines with no exact published body in the
checked-in references, so every contract below is taken from the original ARM instructions and
the adjacent BSS symbols. Existing `func_` linker names are retained because
`config/arm9/symbols.txt` is human-owned.

The functions operate on borrowed state: `Unk111f4_State` holds a test word at +0 and the CPSR
image restored at +4; `Unk11164_Value` and `Unk1111c_Value` supply/read the two WAITCNT fields;
`Unk11198_State` holds the polling status and saved CPSR; `Unk11608_Work` describes the worker
block at `data_02155820`; the BSS views at `data_02155724`, `data_02155728`,
`data_02155740` and `data_02155908` expose only the words the original touches. The boot-status
byte is the SystemWork block at `0x027ffc30 + 5`, and the WAITCNT register is `0x04000204`.

| Function | Evidence and contract | Result |
| --- | --- | --- |
| `func_020115e0` | Requests ARM7 operation 2 through `func_02011218`, then falls into `func_02007e94`, whose loop disables interrupts and invalidates the data cache forever. The original never returns. | 100% |
| `func_020115f4` | Loads `data_02155740` and stores zero at +4; no other state is touched. | 100% |
| `func_02011694` | Tail-calls `func_02008848(dst, 0, 36)`, the unaligned-safe fill also used for the SDK's 36-byte message buffer. `dst` remains caller-owned. | 100% |
| `func_02010ff8` | Materialises `0x027ffc30` as a literal, loads byte +5 and isolates bit 0 with a `lsl #31` / `lsr #31` pair. | 100% |
| `func_020111f4` | Tests the word at state +0; when zero, forwards the caller's first argument unchanged to `func_02005ca0`. Then restores the CPSR image at state +4 through `func_02007a6c`. | 100% |
| `func_02010fd0` | Returns 1 only when `func_02011010` returns nonzero and `func_02010ff8` returns zero. Both the failed first probe and a set second probe return 0. | 100% |
| `func_02011558` | Masks the second argument with 63; only the value 1 sets the halfword at `data_02155728` to 1. Every other value enters the non-returning `func_02007e94` loop. The first argument is not read. | 100% |
| `func_02011164` | Two WAITCNT (`0x04000204`) read-modify-writes: bits 2-3 receive `value->unk_00`, then bit 4 receives `value->unk_04`; the other register bits are preserved. | 100% |
| `func_02010f98` | Clears the 32-bit word at `data_02155728` with `CpuSet(&zero, &data_02155728, 0x05000001)` (one 32-bit fill word), then stores `func_02005d6c()` in the halfword at `data_02155724 + 6`, which is inside the cleared word. The lock-id getter is the same one documented for `OS_GetLockID` in `sdk_020026a0`. | 100% |
| `func_0201111c` | Six volatile WAITCNT accesses: exports `(WAITCNT & 12) >> 2` to +0 and `(WAITCNT & 16) >> 4` to +4, then forces bits 2-3 to 3 and clears bit 4 while preserving every other register bit. | 100% |
| `func_02011198` | Polling loop. Saves interrupts, stores the saved CPSR at state +4 and `func_02005d64((void *)0x027fffe8) & 0x40` at +0. A set 0x40 or a zero `func_02005cac(arg)` return ends it; otherwise interrupts are restored, `WaitByLoop(1)` yields and the loop repeats. The `0x027fffe8` operand is the shared work-area block used by the SDK probes. | 100% |
| `func_02011218` | PXI tag-13 request. If `func_0200a4a0(13, value, 0)` accepts the first attempt, loops with `WaitByLoop(1)` until the same call returns zero. Tag 13 is the same FIFO tag registered by `func_020112b0`. | 100% |
| `func_02011268` | Stores the caller word at `data_02155724` (which `func_02010f98` later clears) and restores interrupts. When the boot probe `func_02010fd0()` fails, programs register `0xf000` through `func_0200720c` with `0x5000` for a null state or `0x1000` otherwise. | 100% |
| `func_020112b0` | One-time PXI/ARM7 setup guarded by `data_02155740 + 8`: sets the guard, clears the +0xc accepted flag and the +0x18 callback, waits for tag 13 in `func_0200a47c`, installs the tag-13 callbacks `func_02011558` and `func_02011584`, calls `func_02011364`, starts the worker through `func_02011608(&data_02155820)`, installs the tag-17 callback `func_020115f4`, and finally calls `func_02011268(0)`. | 100% |
| `func_02011584` | Tag-17 callback. Masks the value to six bits; only 17 is accepted, and any other value enters the non-returning `func_02007e94` loop. For 17, a nonzero +0xc flag returns immediately; the optional +0x18 int-returning callback runs and a nonzero result enters the non-returning `func_020115e0` ARM7 request. The +0xc flag is then set. | 100% |
| `func_02011608` | Worker bootstrap under `data_02155908` as the once-only pointer: stores the work pointer, zero-fills the 36-byte buffers at work +0xc4 and `data_0215590c`, clears work +0xc0, registers `func_020116a8` with a 1024-byte stack at priority 20 through `func_0200621c`, starts it with `func_020064e0`, then restores interrupts. | 100% |

## Hard list

None. All sixteen functions match byte-for-byte in objdiff. This matching card requires no new
behavioral tests; the objdiff, full-image checksum and anti-cheat gates validate the unit.
