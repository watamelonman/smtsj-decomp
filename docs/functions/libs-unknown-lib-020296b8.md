# libs/unknown/lib_020296b8

All six functions match at 100% with the configured mwccarm 2.0/sp1p5.
Existing `func_` linker names are retained because the symbol configuration is
human-owned. No higher-level purpose is assigned to the constant-return leaves.
The TU remains linked from its delinked original pending human completion.

## Source and layout evidence

First searched public pret/pokeplatinum and pret/pokeheartgold checkouts for
`SendTexSRT`, `TexSRT`, and `origHeight`; no matching C implementation was found.
The implementation was reconstructed from the original ARM instructions.
The [NNSG3dMatAnmResult documentation](https://twlsdk.randommeaninglesscharacters.com/docs/twl/TwlSystem/g3d/struct/NNSG3dMatAnmResult.html)
agrees with the flags and offsets: scale at 24/28, sine/cosine at 32/34,
translation at 36/40, dimensions at 44/46, and magnification at 48/52.
Geometry command words contain MTX_MODE (0x10), MTX_LOAD_4x4 (0x16) or
MTX_MULT_4x4 (0x18), followed by MTX_MODE. This supports the texture-matrix
interpretation without changing linker names.

## func_020296b8 — 64 bytes

Fills the scale-only entries of a caller-owned matrix from a material result.
Sets the cross terms and S translation to zero, and computes T translation
as `-origHeight * (scaleT - 4096) * 16`. Other entries are preserved.
The fixed-point values and dimensions must keep this arithmetic representable.
Matches 100%.

## func_020296f8 — 36 bytes

Fills the same six entries with identity scale (4096) and zero cross terms
and translation. Leaves other matrix entries untouched. Matches 100%.

## func_0202971c — 392 bytes

Builds a 4x4 texture matrix command packet on the stack. Flags 1/2/4
normalize scale, rotation and translation in the supplied material in place.
Dispatches through the existing eight-entry table using those three flags,
then applies the width/height magnifications with signed 64-bit products
shifted by twelve. Flag 8 selects load versus multiply. Submits eighteen
parameter words and restores matrix mode 2. The table's constructors own the
six matrix entries not initialized by this function. Matches 100%.

## func_020298a4 — 8 bytes

Returns signed zero, with no observed inputs or side effects. Matches 100%.

## func_020298ac — 8 bytes

Returns signed minus one, with no observed inputs or side effects. Matches 100%.

## func_020298b4 — 8 bytes

Returns signed zero, with no observed inputs or side effects. Matches 100%.

## Validation

No new tests are required by this card. Exact instruction comparison and the
objdiff gate validate all six functions against the delinked original.

## Hard list

None.
