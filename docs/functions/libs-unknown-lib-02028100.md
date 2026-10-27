# Maya texture matrix specializations (M2-T161)

All three functions match the delinked original at 100%. Known-source evidence
is the public NitroSystem reconstruction in
[pret/pokediamond, NNS_G3D_maya.s](https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_maya.s).
Its `texmtxCalc_flag_`, `texmtxCalc_flagS_`, and `texmtxCalc_flagR_` have the
same field accesses, division helpers, and arithmetic; this unit's addresses
form the same three-variant run immediately before `lib_02028354.c`, whose
functions are the next entries of the same table.

The caller owns both arguments. `TextureSRT` is a partial material-result
layout: scale at 0x18/0x1c, signed sine/cosine at 0x20/0x22, translation at
0x24/0x28, and unsigned texel dimensions at 0x2c/0x2e. Scale, translation and
trigonometric values use 12 fractional bits. The output is a 4x4 matrix; only
words 0, 1, 4, 5, 12 and 13 are written. Other matrix entries must be
initialized by the caller. The rotating variants require nonzero dimensions and
exclusive use of the SDK hardware divider (`func_02002298`) until
`func_02002204` retrieves the quotient. Arithmetic and truncation preserve the
original ARM fixed-point behavior.

## func_02028100 — 264 bytes, 100%

Corresponds to `texmtxCalc_flag_`: the full scale/rotation/translation case.
Signed 64-bit scale/trigonometric products are shifted right 12 bits; two
aspect-ratio divisions supply the rotated matrix terms; translation uses the
scale/translation products shifted right 8 bits, scaled by texel dimensions.

## func_02028208 — 208 bytes, 100%

Corresponds to `texmtxCalc_flagS_`: retains unit rotation with input translation.
It uses the same two aspect-ratio divisions and adds translation scaled by the
texel dimensions; the scale matrix entries are cosine.

## func_020282d8 — 124 bytes, 100%

Corresponds to `texmtxCalc_flagR_`: rotation and translation with scale folded
into the translation terms. It performs no hardware division; the vertical
term applies the Maya origin correction `-2 * scaleT + 8192`.

## Validation and hard list

No new tests are required by the card; exact instruction matching verifies all
three implementations. The TU remains linked from its original delink pending
human completion marking. No hard functions remain.
