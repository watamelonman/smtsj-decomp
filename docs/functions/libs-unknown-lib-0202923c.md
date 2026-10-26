# libs/unknown/lib_0202923c

## Source evidence

The public-source search found matching ARM implementations in
[pret/pokediamond NNS_G3D_xsi.s](https://github.com/pret/pokediamond/blob/master/arm9/asm/NNS_G3D_xsi.s):
`texmtxCalc_flag_` and `texmtxCalc_flagS_`. The multiply, division, field offsets,
and six matrix stores agree with the target. C was reconstructed from those
instructions; existing linker names are retained because configuration is human-owned.
The private material view uses Q12 scale/translation and signed Q12 sine/cosine,
with unsigned texel dimensions at offsets 44/46. The caller owns both objects.
Only matrix entries 0, 1, 4, 5, 12 and 13 are modified. Dimensions must be nonzero,
and inputs must keep fixed-point arithmetic within its representable range.

## func_0202923c — 340 bytes

XSI texture matrix construction with scale, rotation and translation enabled.
Uses asynchronous height/width and width/height division for the cross terms.
Rotates translation in signed 64-bit intermediates, retaining the full shifted
64-bit result for the subsequent scale multiplication. Applies texel dimensions
and the vertical-origin correction to the translation entries. Matches 100%.

## func_02029390 — 224 bytes

XSI unit-scale specialization, corresponding to `texmtxCalc_flagS_`.
Copies cosine to the diagonal and uses dimension ratios for the sine cross terms.
Rotates translation, applies texel dimensions and corrects the vertical origin.
Matches 100%.

## Validation

Both functions pass standalone instruction/relocation comparison against the ROM
using mwccarm 2.0/sp1p5. The full objdiff match gate, anticheat, nine existing
unit tests, and byte-identical image checksum gate pass. No new tests are required
by the card; the original instruction streams supply the regression oracle.
The TU stays linked from its delinked original until human completion.

## Hard list

None.
