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


## M2-T397 affine and remaining mosaic wrappers

Source comparison: [NitroSDK g2.h](https://github.com/ntrtwl/NitroSDK/blob/master/include/nitro/gx/g2.h)
provides the four affine wrappers; `gx_bgcnt.h` above provides the mosaic setters.
The matrix is borrowed and contains four signed Q12 entries. Coordinates are
integer pixels, as in the SDK signatures and provider's center shift by 12.
The existing `sdk_02003bb4.h` matrix/provider declarations are reused.

| Function | Evidence and behavior | Match |
| --- | --- | --- |
| `func_02055308` | `G2S_SetBG3Affine`, forwards matrix and four coordinates to `func_02003d8c` at `0x04001030` | 100% |
| `func_02055348` | `G2S_SetBG2Affine`, same provider at `0x04001020` | 100% |
| `func_02055388` | `G2_SetBG3Affine`, same provider at `0x04000030` | 100% |
| `func_020553c8` | `G2_SetBG2Affine`, same provider at `0x04000020` | 100% |
| `func_02055408` | Original indexed load from `data_02143ab0`, null check, and indirect five-argument call establish affine callback dispatch; valid index required, table and matrix borrowed | 100% |
| `func_02055548` | `G2_BG1Mosaic`, sets/clears bit 6 at `0x0400000a` for nonzero/zero enable, preserving other bits | 100% |
| `func_02055574` | `G2_BG0Mosaic`, same operation at `0x04000008` | 100% |
| `func_02055194` | Original MMIO selects main/sub DISPCNT for indices 0..3/4..7, reads plane mask `0x1f00`, toggles the indexed bit, then preserves remaining DISPCNT bits | deferred |

### Hard list

- `func_02055194` (120 bytes): left in the original delink. Tried direct
  read/mask/shift and per-engine conditional expressions, signed/unsigned plane
  locals, explicit and conditional bit-index selection, precomputed bit masks,
  both branch orders, and inline toggle helpers. The closest forms retain the
  correct size and behavior but allocate the plane value to r2 and index to r3;
  the target uses r3 and ip and schedules the shift between index-selection
  instructions. No nonmatching implementation is retained. A human can open a
  scratch with `tools/decompme.py` for this function.


## M2-T398: record cleanup and display reset

Public-source lookup: [NitroSDK gx.h](https://github.com/ntrtwl/NitroSDK/blob/main/include/nitro/gx/gx.h)
provides `GX_SetVisiblePlane`, `GXS_SetVisiblePlane`, and the window-mask
setters. Their DISPCNT masks establish the plane/window portions of these
helpers. No exact public implementation of the surrounding record lifecycle
or mode-table dispatch was found; neutral function symbols are retained.

| Function | Evidence and contract | Match |
| --- | --- | --- |
| `func_02054fb8(int keepPlanes)` | Zero hides planes in both engines. For indices 0..7, the original record provider returns 40-byte storage; an active first word permits releasing nonnull pointers at +0x24 then +0x1c and clearing those slots. Every record is then cleared through its provider, followed by mode eight. | 100% (160 bytes) |
| `func_02055058(void)` | Snapshots both DISPCNT words, clears planes (`0x1f00`) and windows (`0xe000`), and calls the engine reset provider for zero then one. The table at `0x0212e2d0` selects T/A behavior by original mode and background index. T resets scroll unless main BG0 is 3D; A submits a Q12 identity matrix and zero coordinates. | 100% (316 bytes) |

The private record view exposes only instruction-established fields. Resource
slots are released only when the record is active; record storage and the mode
table remain provider-owned. The identity provider at `0x02000d60` writes
`4096, 0, 0, 4096`, confirming the four-word matrix layout. DISPCNT snapshots
use a borrowed volatile union with three mode bits and one BG0 3D bit; this
preserves the original aggregate loads and bitfield extraction. These private
views introduce no public module boundary.

Integration requirement: the original mode-table literal has no relocation or
symbol in `config/arm9/symbols.txt`. The C declaration `data_0212e2d0` names that
existing borrowed table; a human must add a data symbol at `0x0212e2d0` before
marking this TU complete. The configuration is protected, so it is unchanged.
Objdiff matches both functions at 100%; the current delink-linked image remains
byte-identical. Neither requested function is deferred to the hard list.

Validation: `python3 tools/anticheat.py`, the nine discovered unit tests,
`python3 tools/match_gate.py` (all 31 implemented functions in this TU at 100%),
and `python3 tools/checksum.py` all passed; the match gate also ran the build.
