# NitroSDK unit 02010f98

Public-source lookup: the unit was checked against the NitroSDK OS/MSL shapes already
documented in this repository (the neighbouring `sdk_020116a8` message pump and the
`OS_InitIrqTable`/interrupt-restore helpers). These eight helpers are small register-shape
routines with no exact published body available in the checked-in references, so every
contract below is taken from the original ARM instructions and the two adjacent BSS symbols.
Existing `func_` linker names are retained because `config/arm9/symbols.txt` is human-owned.

The functions operate on borrowed state: `Unk111f4_State` holds a test word at +0 and the CPSR
image restored at +4; `Unk11164_Value` supplies the two WAITCNT fields; the BSS views at
`data_02155740` and `data_02155728` expose only the words the original touches. The boot-status
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

## Hard list

None. All eight functions match byte-for-byte in objdiff. This matching card requires no new
behavioral tests; the objdiff, full-image checksum and anti-cheat gates validate the unit.
