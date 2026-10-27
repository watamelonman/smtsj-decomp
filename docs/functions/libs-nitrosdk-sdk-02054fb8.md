# sdk_02054fb8 background-priority wrappers

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

## Validation

The match gate compares all eight functions with the original object.
No new tests are required by this card; hardware accesses are verified by
objdiff rather than exercised on the host.

## Hard list

None of the eight requested functions is deferred. The remaining TU is
provided by the delink until a human marks the unit complete.
