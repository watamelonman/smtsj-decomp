# sdk_02050160

Status of the four functions in this translation unit. The unit is still linked from
the delink (`complete: false`), so `func_02050224` below is supplied by the original
object until a human reconstructs it.

| Function | Bytes | C status | objdiff |
| --- | ---: | --- | ---: |
| `func_02050160` | 48 | reconstructed in `libs/NitroSDK/sdk_02050160.c` | 100.00% |
| `func_02050190` | 64 | reconstructed in `libs/NitroSDK/sdk_02050160.c` | 100.00% |
| `func_020501d0` | 84 | reconstructed in `libs/NitroSDK/sdk_02050160.c` | 100.00% |
| `func_02050224` | 640 | not reconstructed; delinked original | 0.00% (hard list) |

Reproduce the percentages from the worktree root:

```sh
ninja
for f in func_02050160 func_02050190 func_020501d0; do
  ./objdiff-cli diff -1 build/delinks/libs/NitroSDK/sdk_02050160.o \
                     -2 build/libs/NitroSDK/sdk_02050160.o "$f" --format json -o - |
    python3 -c 'import json,sys
d=json.load(sys.stdin)
s=[x for x in d["left"]["symbols"] if x.get("name")==sys.argv[1]][0]
print(sys.argv[1], s["match_percent"])' "$f"
done
```

`func_02050224` is not defined in the C file, so it is absent from
`build/libs/NitroSDK/sdk_02050160.o` and the same command has no base symbol for
it; the delinked object still contains it (0.00% matched C).

The project gate `python3 tools/match_gate.py` only checks functions that are
*defined* in the changed C file, so it sees the three 100% functions and ignores
`func_02050224` (which has no C definition and therefore still links from the delink).

## Matched functions

### `func_02050160` (100%)

Counts how many decimal digits an unsigned value has; zero has zero digits.

Evidence (0x02050160..0x02050190): `cmp r0,#0` / `mov r12,#0` / `beq` returns zero;
the loop loads the reciprocal `0xcccccccd` (literal at 0x0205018c), does
`umull r1,r0,r3,r2` and `lsrs r0,r0,#3` (the standard reciprocal divide by ten),
then `add r12,r12,#1` and `bne`.

### `func_02050190` (100%)

Clamped integer linear interpolation from `start` to `end` over `duration` units.
`duration == 0` returns `end`, `elapsed <= 0` returns `start`, and
`elapsed >= duration` returns `end`; otherwise
`start + (end - start) * elapsed / duration`.

Evidence (0x02050190..0x020501d0): the three guards are the conditional returns
`moveq r0,r1` / `pople` and `cmp r3,r2` / `movge r0,r1`; the body is
`sub r1,r1,r4`, `mul r0,r1,r3`, `bl _s32_div_f`, `add r0,r0,r4`.

### `func_020501d0` (100%)

Same clamp contract, but the interpolation multiply is done in 20.12 with rounding
and the divide is the SDK fixed-point helper `func_0200219c`, i.e.
`start + func_0200219c(FX_MUL(end - start, elapsed << 12), duration << 12)`.

Evidence (0x020501d0..0x02050224): identical guard sequence to `func_02050190`, then
`sub r12,r1,r4`, `lsl r0,r3,#12`, `smull r1,r0,r12,r0`, `adds r3,r1,#0x800`,
`adc r1,r0,#0`, `lsr r0,r3,#12`, `orr r0,r0,r1,lsl #20` (the `FX_MUL` expansion),
`lsl r1,r2,#12`, `bl func_0200219c`, `add r0,r0,r4`.
`func_0200219c` starts the hardware divider at 0x04000280 through `func_02002298`
(stores 1 to DIVCNT, numerator/denominator to +0x14/+0x18) and reads DIV_RESULT at
0x040002a0 in `func_02002204`, returning `(numerator << 12) / denominator`.
The `span` local is deliberately reused for the scaled numerator: that is what makes
mwccarm 2.0/sp1p5 place the span in `r12` and the `smull` low word in `r1`, as the
original does.

## Hard list: `func_02050224` (640 bytes)

**Semantics are provisional.** The formula below is inferred only from the delinked
ARM instructions, not from a matching C source; treat it as a starting point for a
decomp.me scratch, not as verified original source.

Provisional contract (c = 0 for x, 1 for y):

```c
FX_MUL(a, b) = (s32)(((s64)(a) * (b) + 0x800) >> 12)

s  = 0x1000 - t;
s2 = FX_MUL(s, s);
t2 = FX_MUL(t, t);
b0 = FX_MUL(s2, s);                          /* s^3        */
b1 = FX_MUL(FX_MUL(s2, 0x3000), t);          /* 3*s^2*t    */
b2 = FX_MUL(FX_MUL(s, 0x3000), t2);          /* 3*s*t^2    */
b3 = FX_MUL(t2, t);                          /* t^3        */

out[0] = (FX_MUL(b0, in[0] << 12) + FX_MUL(b1, in[2] << 12)
        + FX_MUL(b2, in[4] << 12) + FX_MUL(b3, in[6] << 12)) >> 12;
out[1] = (FX_MUL(b0, in[1] << 12) + FX_MUL(b1, in[3] << 12)
        + FX_MUL(b2, in[5] << 12) + FX_MUL(b3, in[7] << 12)) >> 12;
```

Instruction evidence (addresses are file offsets in
`build/delinks/libs/NitroSDK/sdk_02050160.o`; the function starts at 0xc4):

```asm
c4: push {r4-r11,lr}              ; nine callee-saved registers
c8: sub  sp, sp, #52              ; 13-word frame
cc: rsb  r8, r2, #0x1000          ; s = 0x1000 - t
d0: smull r4, r3, r8, r8          ; s*s
d4: adds r5, r4, #0x800
d8: adc  r4, r3, #0
dc: lsr  r3, r5, #12
e0: orr  r3, r3, r4, lsl #20      ; s2
e8: smull r4, r7, r2, r2          ; t*t -> t2 (rounded at 0xfc..0x108)
f0: umull r5, r11, r8, r6         ; s * 0x3000, r6 = 0x3000
f4: asr  r9, r8, #31
f8: mla  r11, r9, r6, r11         ; sign correction for 3*s
12c: smull r11, r10, r5, r4       ; 3*s * t2 product, spilled to sp+0x10/0x14
140: umull r11, r10, r3, r6       ; s2 * 0x3000 -> 3*s2
150: smull r9, r8, r3, r8         ; s2 * s -> s3
160: smull r6, r3, r10, r2        ; 3*s2 * t
174: smull r6, r3, lr, r7         ; b1 * (in[3] << 12),  y1 term
19c: ldr  r3, [sp, #12]           ; y0 << 12
1a0: smull r6, r3, r12, r3        ; b0 * (in[1] << 12),  y0 term
1e8: ldr  r8, [r1, #20]           ; in[5], y2
1f0: smull r9, r8, r3, r8         ; b2 * (in[5] << 12),  y2 term
210: ldr  r6, [r1, #28]           ; in[7], y3
214: ldr  r7, [r1, #24]           ; in[6], x3
228: ldr  r7, [r1, #16]           ; in[4], x2
22c: ldr  r6, [r1]                ; in[0], x0
238: ldr  r6, [r1, #8]            ; in[2], x1
25c: umull r10, r9, r4, r2        ; t2 * t -> t3
27c: smull r9, r4, r10, r1        ; b3 * (in[7] << 12),  y3 term
28c: smull r2, r1, r10, r1        ; b3 * (in[6] << 12),  x3 term
2c0: umull r9, r4, r3, r8         ; b2 * (in[4] << 12),  x2 term
2e4: umull r4, r3, r12, r7        ; b0 * (in[0] << 12),  x0 term
308: umull r9, r7, lr, r6         ; b1 * (in[2] << 12),  x1 term
2b8: asr  r2, r9, #12             ; out[1] = y sum >> 12
334: asr  r1, r1, #12             ; out[0] = x sum >> 12
338: stm  r0, {r1, r2}            ; out[0] = x, out[1] = y
```

The four control points are interleaved x/y pairs at `in[0..7]`; the component
sums use plain 32-bit `add`, so the accumulator is `s32` after each term is
rounded. The frame is used for 13 spilled values: signs of `t`, `s3`, `b1`, `b2`
and the x coordinates, the `b2` 64-bit product, three shifted coordinates and the
partial y sum.

### What was tried (all with the project's `-O4,p -proc arm946e` flags)

* The natural source above with initialized locals: 39.82%, 117 instructions.
* Reordered basis declarations and y/x term orders, all four sum associations,
  direct `out->x/out->y` versus local results, `Vec2` versus flat `s32 *`,
  precomputed coordinate locals, per-term locals, sequential `+=` accumulation,
  and interleaved x/y accumulation: 30-40%, 117-179 instructions.
* `s64` casts on the x coordinates only (`(s64)in[i].x << 12`) plus an inline
  `t3`: 33.48%, 155 instructions, 28-byte frame, five `umull`.
* Declaring the basis or the coordinates as `s64`, `s32`/`u32` mixes, an inline
  `FX_MUL` helper with `s64` parameters, and the SDK `FX_MUL`/`FX32_CAST` form:
  no form reached 100%.
* Other mwccarm service packs (2.0 base/sp1/sp1p2/sp1p5/sp1p6/sp1p7/sp2/sp2p2/
  sp2p3/sp2p4, 1.2, dsi) do not reproduce the target from this source either.

The target is distinguished by six `umull`+`mla` sign-corrected multiplies
(`3*s`, `3*s2`, `t3`, and the x0/x1/x2 terms) and a 13-word frame; the best
reconstructions use `smull` and a much smaller frame. The remaining gap is
mwccarm register allocation/scheduling, not the arithmetic. A human should open a
`tools/decompme.py` scratch (platform `nds_arm9`) with the provisional formula
above. No `INCLUDE_ASM` or inline assembly was added; the function stays in the
delink.

## Public-source lookup

Searched `ntrtwl/NitroSDK` (4.2.30001), `ntrtwl/NitroSystem` (071126.1),
`pret/pokeplatinum`, `pret/pokeheartgold` and `pret/pokediamond` for the
decimal-digit loop, `FX_MUL`/`0x800` rounding, `0x3000` basis constants, cubic
Bezier/spline code and the divider wrapper. No matching C implementation exists in
those trees; the reconstructions above follow the delinked ARM instructions.

## Card-status note

The card's acceptance criterion asks for 100% on all four functions, while its
Notes say to leave a function out, document it and add it to the hard list if it
cannot be matched. `func_02050224` is on the hard list; the three other functions
are at 100%. A human should split `func_02050224` into a follow-up card if the
criterion is meant to be met before this unit is marked `complete`.
