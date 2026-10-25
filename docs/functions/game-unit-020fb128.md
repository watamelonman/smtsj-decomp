# game/unit_020fb128

All seven functions match at 100% in objdiff. Evidence below refers to ARM
instructions in the original `extract/arm9/arm9.bin` at the named addresses.
Names remain neutral because the record states and message IDs do not establish
a gameplay meaning. All pointers are borrowed; no function allocates or frees them.
Private struct views expose only accessed fields and preserve signed byte loads.

| Function | Contract and original evidence |
| --- | --- |
| `func_020fb128` | Requires non-null work. Iterates slots 0..3, obtaining the primary record for 0 and secondary records for 1..3. Null records and state 1 are skipped; state 2 is cleared. Converts the signed halfword at primary +0x12 or secondary +0x0a through `Unk02f2a8_Unk_0366dc`, sets work +0x74a8 + index*8 to 1, subtracts the conversion from the next word, and calls `ScanVisor_Unk_0a379c(index, 3)`. The loop bound, offsets, signed loads and calls are visible at 0x020fb144..0x020fb1c8. |
| `func_020fb1d0` | Requires non-null work. Calls `func_020fd0c8(0)`, stores 1 at +0x74ec and returns 1, as evidenced by 0x020fb1dc..0x020fb1ec. |
| `func_020fb1f0` | No explicit inputs. Iterates the same four nullable records. Eligibility comes from `Unk0981dc_Unk_098324(3, (s8)state)`. Reads pair 9, computes a threshold with `func_0203675c` and the signed byte at primary +0x19 or secondary +0x11, then sets state 3 and notifies the slot if `func_02050074(1, 100)` is below the unsigned threshold. The unsigned `bcs` branches after the random-value comparisons exclude equal thresholds. |
| `Unk0fb128_GetConst1` | Returns 1 without accessing work; evidenced by `mov r0, #1; bx lr` at 0x020fb31c. |
| `func_020fb324` | Requires non-null work and context; phase 4 additionally requires a primary record when the repeat count expires. Dispatches signed phase +0x7481 through cases 0..6. Clears context +0x38/+0x34 in phase 0; waits on external completion predicates; initializes repeat count +0x7484 to 3; emits IDs 36, 37, 38; loops to phase 2 while repeats remain and clears primary state on expiry. Returns 0 while waiting, 1 when phase 6 completes or phase is out of range. Evidence: jump table 0x020fb344..0x020fb35c and handlers through 0x020fb500. `func_0204faf0` receives index 1 and the current repeat count; its body at 0x0204faf0 saves both r0 and r1 and conditionally stores the latter in an indexed table. |
| `func_020fb504` | Requires non-null work. Checks eligibility for state 2 and computes unsigned thresholds using pair 8, `func_020368e8`, and the same signed record bytes. A strictly smaller random value sets record state 2. Only primary success sets work pending +0x7480 to 1. Evidence: calls and conditional halfword/byte stores at 0x020fb524..0x020fb600. |
| `Unk0fb128_Unk_0fb614` | Requires non-null work. Returns 1 unless signed pending +0x7480 equals exactly 1; otherwise returns `func_020fb324(work)`. Evidence: signed load, compare, early return and call at 0x020fb614..0x020fb630. |

The split work/tail view reflects the original +0x7000 addressing base and is
private to this translation unit. No module boundary changes are introduced.

## Validation

- Standalone compiler comparison: every function's instructions and relocations
  match the original.
- `FORGE_BASE=HEAD python3 tools/match_gate.py`: all seven functions at 100%.
- Behavioral tests are not required by this card; original instruction and
  relocation comparisons provide the acceptance check.

## Hard list

None.
