# sdk_02050160

Two of the four functions in this translation unit match at 100% with the configured
mwccarm compiler; the two fixed-point routines remain on the hard list and are still
supplied by the delinked original. The original `func_` symbols are retained for linkage.

Public-source lookup: the pret/pokeplatinum NitroSDK and NitroSystem subprojects were
cloned at the pinned revisions (`ntrtwl/NitroSDK` 4.2.30001 and `ntrtwl/NitroSystem`
071126.1) and searched for the decimal-digit loop, the `FX_MUL`/`0x800` rounding idiom,
`0x3000` basis constants, cubic/Bezier/spline code, and the hardware-divider wrapper.
No matching C implementation exists in either tree, so the code below follows the
delinked ARM instructions directly.

| Function | Bytes | Contract and instruction evidence |
| --- | ---: | --- |
| `func_02050160` | 48 | Counts how many times an unsigned value can be divided by ten before reaching zero, so zero returns zero. The divisor is the 0xcccccccd reciprocal with the high product shifted right by three. |
| `func_02050190` | 64 | Clamps `elapsed` to the open interval `(0, duration)` and linearly interpolates from `start` to `end`; a zero duration returns `end`. Uses the compiler's `_s32_div_f` runtime helper for the signed division. |

The C implementations use only `types.h` and preserve the original parameter order and
signedness. No module boundary changes were needed.

Validation: objdiff reports 100% for both implemented functions, including the
`end - start` ordering and the shared `span` temporary needed to match the original
comparison and register schedule.

## Hard list

| Function | Bytes | Contract and remaining mismatch |
| --- | ---: | --- |
| `func_020501d0` | 84 | Same endpoint guards as `func_02050190`, but interpolates in 20.12 fixed point: `start + func_0200219c((s32)(((s64)(end - start) * (elapsed << 12) + 2048) >> 12), duration << 12)`. `func_0200219c` drives the hardware divider (DIVCNT at `0x04000280`, numerator/denominator at `0x04000294`/`0x04000298`) and reads the 64-bit result at `0x040002a0`. The reconstruction has the same instruction count and semantics; mwccarm 2.0/sp1p5 always places `end - start` in r1/r0 and the SMULL low result in r3, while the original places the span in `ip` and the SMULL low result in r1. Tried: `s32 span`/`s32 scaled` locals, `s64` products and casts, `u64` casts, statement splitting, declaration hoisting/sinking, the `FX_MUL` macro, `register`, ternary and `else`-chain guard forms, and both return orderings; every form produces the same register assignment. |
| `func_02050224` | 640 | 2D cubic Bezier evaluator. `out[0]` is the x component and `out[1]` the y component of four 2D control points at `in[0]`..`in[7]`; `t` is 20.12. It computes `s = 0x1000 - t`, the basis `s^3`, `3*s^2*t`, `3*s*t^2`, `t^3` with `(s64)a*b + 0x800 >> 12` rounding, multiplies each basis by `coordinate << 12`, sums, and shifts the sum right by 12. The original is a 13-word stack frame with many spilled sign words; mwccarm 2.0/sp1p5 keeps the same basis but spills less (best reconstruction 129 instructions versus 160, and a 5-6 word frame). Tried: named coefficient locals, fully nested expressions, `Vec2` struct return versus an output pointer, macro versus `static inline` multiplication, x-first/y-first orders, and a two-iteration component loop; none reproduced the original spill schedule. |

Hard-list notes: both functions are unambiguous in behavior; only mwccarm register
allocation and spill scheduling differ. A human can open a `tools/decompme.py` scratch
(platform `nds_arm9`) with the formulas above. No `INCLUDE_ASM` or inline assembly was
added because unmatched functions already link from the delink until the unit is marked
`complete`.
