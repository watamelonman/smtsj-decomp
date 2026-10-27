# sdk_02054fb8 background control wrappers

Public-source comparison: [NitroSDK gx_bgcnt.h](https://github.com/ntrtwl/NitroSDK/blob/master/include/nitro/gx/gx_bgcnt.h),
`G2_SetBG0Priority` through `G2_SetBG3Priority` and their `G2S` counterparts.
These use a volatile halfword read, clear priority mask 3, OR the caller's
priority, then write the halfword. The original functions have the same
sequence and hardware addresses. Symbol names stay unchanged for objdiff.
The caller supplies priority 0..3; release code does not validate it or mask
the input. There is no storage ownership or module boundary change.

| Function | SDK counterpart | Register | Match |
| --- | --- | --- | --- |
| `func_0205520c` | `G2S_SetBG3Priority` | `0x0400100e` | 100% |
| `func_02055228` | `G2S_SetBG2Priority` | `0x0400100c` | 100% |
| `func_02055244` | `G2S_SetBG1Priority` | `0x0400100a` | 100% |
| `func_02055260` | `G2S_SetBG0Priority` | `0x04001008` | 100% |
| `func_0205527c` | `G2_SetBG3Priority` | `0x0400000e` | 100% |
| `func_02055298` | `G2_SetBG2Priority` | `0x0400000c` | 100% |
| `func_020552b4` | `G2_SetBG1Priority` | `0x0400000a` | 100% |
| `func_020552d0` | `G2_SetBG0Priority` | `0x04000008` | 100% |

## M2-T396: mosaic and table dispatch

The same public SDK header defines `G2_BG2Mosaic`, `G2_BG3Mosaic` and
`G2S_BG0Mosaic` through `G2S_BG3Mosaic`. Each preserves all control bits
except mosaic bit 6, setting it for any nonzero `enable` and clearing it
for zero. Hardware halfwords are volatile and no storage is retained.

| Function | Evidence / behavior | Register or table | Match |
| --- | --- | --- | --- |
| `func_020552ec` | Original indexed load and indirect one-argument call | `data_02143ad0` | 100% |
| `func_02055440` | `G2S_BG3Mosaic` | `0x0400100e` | 100% |
| `func_0205546c` | `G2S_BG2Mosaic` | `0x0400100c` | 100% |
| `func_02055498` | `G2S_BG1Mosaic` | `0x0400100a` | 100% |
| `func_020554c4` | `G2S_BG0Mosaic` | `0x04001008` | 100% |
| `func_020554f0` | `G2_BG3Mosaic` | `0x0400000e` | 100% |
| `func_0205551c` | `G2_BG2Mosaic` | `0x0400000c` | 100% |
| `func_020555a0` | Original indexed load and indirect one-argument call | `data_02143af0` | 100% |

The dispatchers borrow provider-owned callback arrays. Callers must supply a
valid index and initialized callback; the original has no bounds or null check.
The callback argument is represented as an `int` word; its semantic role is
not established, so the original neutral symbols are retained. No module
boundary or ownership changes are introduced.

## Validation

The match gate compares all sixteen implemented functions with the original object.
No new tests are required by this card; hardware accesses are verified by
objdiff rather than exercised on the host.

## Hard list

None of the requested functions is deferred. The remaining TU is
provided by the delink until a human marks the unit complete.
