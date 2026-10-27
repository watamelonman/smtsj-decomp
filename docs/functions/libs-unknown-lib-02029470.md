# XSI texture matrix specializations (M2-T152)

## Source evidence

The public-source search found matching ARM implementations in
[pret/pokediamond NNS_G3D_xsi.s](https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_xsi.s):
`texmtxCalc_flagR_`, `texmtxCalc_flagRS_`, `texmtxCalc_flagT_` and
`texmtxCalc_flagTS_`. Field offsets, division calls, multiply/shift sequences and
matrix stores agree with the target. The C formulations follow the public
NitroSystem reconstruction in
[ctrl-cheeb-del/pokeheartgold](https://github.com/ctrl-cheeb-del/pokeheartgold/tree/master/lib/NitroSystem/src),
files `g3d_cgtool_xsi_texmtx_sr.c` and `g3d_cgtool_xsi_texmtx.c`, where the same
functions appear as `texmtxCalc_flagR___xsi`, `texmtxCalc_flagRS___xsi`,
`texmtxCalc_flagT___xsi` and `texmtxCalc_flagTS___xsi`. Existing linker names are
retained because configuration is human-owned.

The material view is a partial `NNSG3dMatAnmResult`: Q12 scale at 0x18/0x1c,
signed Q12 sine/cosine at 0x20/0x22, translation at 0x24/0x28, and unsigned texel
dimensions at 0x2c/0x2e. The caller owns both arguments. Only matrix entries 0, 1,
4, 5, 12 and 13 are written; the remaining entries must be initialized by the
caller. Rotating variants require nonzero dimensions and exclusive use of the SDK
hardware divider until its result is retrieved. Fixed-point products must remain
representable in the declared intermediates.

## func_02029470 — 132 bytes, 100%

Corresponds to `texmtxCalc_flagR_`: writes scale to the diagonal, zeroes the
off-diagonal terms, and translates by the scale-scaled input translation. The S
translation is negated before the texel-width product; T includes the vertical
origin correction.

## func_020294f4 — 84 bytes, 100%

Corresponds to `texmtxCalc_flagRS_`: writes unit scale and zero off-diagonal
terms, then converts negated input translation directly to texture-coordinate
units using the texel dimensions.

## func_02029548 — 204 bytes, 100%

Corresponds to `texmtxCalc_flagT_`: combines Q12 scale and rotation without input
translation. Signed 64-bit scale/trigonometric products are shifted right 12
bits; asynchronous height/width and width/height division supplies the
aspect-ratio corrections for the sine cross term and the centered translation.

## func_02029614 — 164 bytes, 100%

Corresponds to `texmtxCalc_flagTS_`: retains rotation with unit scale and no input
translation. It uses the same two aspect-ratio divisions and computes centered
translation from sine, cosine and texel dimensions.

## Validation and hard list

No new tests are required by the card; exact instruction matching verifies all
four implementations. The full objdiff match gate, anticheat, existing unit tests
and byte-identical image checksum gate pass. The TU remains linked from its
original delink pending human completion marking. No hard functions remain.
