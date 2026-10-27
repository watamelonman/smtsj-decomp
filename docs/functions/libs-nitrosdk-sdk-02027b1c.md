# sdk_02027b1c

This unit is the NitroSystem G3D texture/palette animation source
`libraries/g3d/src/anm/nsbtp.c`. Public source was consulted before
implementation:
[ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem/tree/d636fb5d2b212e8736f09859fff447be2bd0ac85/libraries/g3d/src/anm),
the same NitroSystem tree used by pret/pokeplatinum. The addresses, order, call
targets and field offsets agree with that source. Existing `func_` linker names
are retained because symbol configuration is human-owned.

## func_02027b1c — NNSi_G3dAnmObjInitNsBtp (220 bytes)

Installs `data_0213d378` (the default NSBTP material animation callback), stores
the resource, and sets `numMapData` from the model's `info.numMat`. It clears the
caller-supplied map entries with `func_02008644` (`MI_CpuClear16`) and then maps
each texture/palette dictionary name onto its material index with
`func_020259ac` (`NNS_G3dGetResDictIdxByName`), setting the map-present bit
(0x100).

## func_02027bf8 — SetTexParamaters_ (216 bytes)

Static helper from `nsbtp.c`. Looks up the texture data through
`func_020257ec` (`NNS_G3dGetResDataByName`) on `pTex->dict` at offset 0x3c,
chooses the normal or 4x4 VRAM key, and writes `prmTexImage`, `origWidth`,
`origHeight`, `magW` and `magH`. `magW`/`magH` are `FX_Div` results
(`func_0200219c`) unless the source dimensions already match, in which case they
are `FX32_ONE`.

## func_02027cd0 — SetPlttParamaters_ (104 bytes)

Static helper from `nsbtp.c`. Looks up the palette data through
`func_020257ec` on the palette dictionary selected by `plttInfo.ofsDict`. It adds
the palette offset and the key address, halving both for 16-color palettes
(`flag & 1` clear), and stores the result in `prmTexPltt`.

## func_02027d38 — NNSi_G3dAnmCalcNsBtp (116 bytes)

Truncates the signed 20.12 animation frame to its whole part and asks
`func_02025c18` (`NNSi_G3dGetTexPatAnmFV`) for the matching frame value. It then
resolves the texture name with `func_02025bc0` and, unless `idPltt` is 255, the
palette name with `func_02025bec`, forwarding both to the parameter writers
above.

## Validation and hard list

The objdiff match gate and the ROM checksum gate validate compiled code and the
unchanged delink-based image respectively. No added behavioral tests are
required by this card. Hard list: none.
