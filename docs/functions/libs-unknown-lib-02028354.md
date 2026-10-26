# Maya texture matrix specializations (M2-T084)

The existing C implementation is retained: all four functions match at 100%.
Known-source evidence is the public NitroSystem reconstruction in
[pret/pokediamond, NNS_G3D_maya.s](https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_maya.s).
Its `texmtxCalc_flagRS_`, `texmtxCalc_flagT_`, `texmtxCalc_flagTS_`, and
`texmtxCalc_flagTR_` have the same field accesses and arithmetic. The inherited
TS/TR comments had their flag letters reversed; these are corrected without
changing generated code. Original address symbols remain unchanged.

The caller owns both arguments. `TextureSRT` is a partial material-result layout:
scale at 0x18/0x1c, signed sine/cosine at 0x20/0x22, translation at 0x24/0x28,
and unsigned texel dimensions at 0x2c/0x2e. Scale, translation and trigonometric
values use 12 fractional bits. The output is a 4x4 matrix; only words 0, 1, 4,
5, 12 and 13 are written. Other matrix entries must be initialized by the caller.
The rotating variants require nonzero dimensions and exclusive use of the SDK
hardware divider until their result is retrieved. Arithmetic and truncation
preserve the original ARM fixed-point behavior.

## func_02028354 — 72 bytes, 100%

Corresponds to `texmtxCalc_flagRS_`: writes identity scale/rotation and converts
normalized translation to texture-coordinate units using width and height.
S translation is negated; both translation products are shifted left four bits.

## func_0202839c — 224 bytes, 100%

Corresponds to `texmtxCalc_flagT_`: combines Q12 scale and rotation without input
translation. Signed 64-bit scale/trigonometric products are shifted right 12
bits; asynchronous height/width and width/height division supplies aspect-ratio
corrections. The translation terms implement Maya's texture-origin convention.

## func_0202847c — 184 bytes, 100%

Corresponds to `texmtxCalc_flagTS_`: retains rotation with unit scale and no input
translation. It uses the same two aspect-ratio divisions and computes centered
translation from sine, cosine and texel dimensions.

## func_02028534 — 68 bytes, 100%

Corresponds to `texmtxCalc_flagTR_`: writes scale with zero off-diagonal terms and
zero S translation. T translation corrects the vertical origin using height and
`2 - 2 * scaleT` in fixed-point units.

## Validation and hard list

No new tests are required by the card; exact instruction matching verifies all
four implementations. The TU remains linked from its original delink pending
human completion marking. No hard functions remain.
