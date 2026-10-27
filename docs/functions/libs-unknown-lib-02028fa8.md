# libs/unknown/lib_02028fa8

All four functions match at 100% with the configured mwccarm 2.0/sp1p5, and
the full-image checksum remains byte-identical. Existing `func_` linker names
are retained because the symbol configuration is human-owned. The TU remains
linked from its delinked original pending human completion.

## Source and layout evidence

The eight constructors reachable from the table at `0x0213d5a4` follow the
3ds Max texture-matrix family rather than the XSI family in the neighbouring
`lib_0202923c`/`lib_02029470` units. The matching public reconstruction is in
[ctrl-cheeb-del/pokeheartgold `lib/NitroSystem/src/g3d_cgtool_3dsmax.c`](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/g3d_cgtool_3dsmax.c)
and
[`g3d_cgtool_3dsmax_texmtx.c`](https://github.com/ctrl-cheeb-del/pokeheartgold/blob/master/lib/NitroSystem/src/g3d_cgtool_3dsmax_texmtx.c):

- `texmtxCalc_flagTS___3dsmax` — `func_02028fa8`
- `texmtxCalc_flagTR___3dsmax` — `func_02029080`
- `texmtxCalc_flagTRS___3dsmax` — `func_020290d0`
- `NNSi_G3dSendTexSRT3dsMax` — `func_020290f4`

The delink relocations map the table entries in the same flag order
(`flag_`, `flagS_`, `flagR_`, `flagRS_`, `flagT_`, `flagTS_`, `flagTR_`,
`flagTRS_`), and the ARM instruction streams agree with the cited sources.
The material is a partial `NNSG3dMatAnmResult`: Q12 scale at 0x18/0x1c,
signed Q12 sine/cosine at 0x20/0x22, translation at 0x24/0x28, unsigned texel
dimensions at 0x2c/0x2e, and magnification at 0x30/0x34. The caller owns both
arguments; only matrix entries 0, 1, 4, 5, 12 and 13 are written by the
constructors, so the remaining entries must already be initialized. Fixed-point
products must remain representable in the declared intermediates, and rotating
variants require nonzero texture dimensions and exclusive use of the SDK
hardware divider until its result has been retrieved.

## func_02028fa8 — 216 bytes, 100%

`texmtxCalc_flagTS___3dsmax`: rotation with unit scale and zero input
translation. Starts the height/width and width/height Q12 divisions, writes the
cosine to the diagonal, the sine aspect-ratio cross term to `m01`, and derives
the centred translation at `m30`/`m31` from `-width << 11` and `-height << 11`
with signed 64-bit products shifted right by eight. Both texel dimensions must
be nonzero.

## func_02029080 — 80 bytes, 100%

`texmtxCalc_flagTR___3dsmax`: scale only, with rotation fixed to identity and
no input translation. Writes the Q12 scales to the diagonal, zeroes the cross
terms and negated translation, and builds `m30`/`m31` as
`((4096 - scale) * dimension) << 3`.

## func_020290d0 — 36 bytes, 100%

`texmtxCalc_flagTRS___3dsmax`: all input transforms disabled. Writes identity
scale (4096) and zero cross terms and translation, leaving the other matrix
entries untouched.

## func_020290f4 — 328 bytes, 100%

`NNSi_G3dSendTexSRT3dsMax`: builds an 18-parameter texture-matrix command
packet on the stack, selects load versus multiply from flag bit 8, and
dispatches through `data_0213d5a4` using the low three flag bits. It then
applies the width/height magnification with signed 64-bit products shifted by
twelve and submits the packet's 18 parameter words.

## Validation

No new tests are required by this card. Exact instruction comparison (objdiff
100% on every function) and the full-image checksum gate validate the
implementation. Unit tests and the anticheat gate also pass.

## Hard list

None.
