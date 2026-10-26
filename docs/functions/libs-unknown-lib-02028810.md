# libs/unknown/lib_02028810

## func_02028810

Identified as `NNSi_G3dGetJointScaleSi3d` from the public
[NitroSystem source](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/cgtool/si3d.c).
The existing linker symbol is retained because symbol configuration is human-owned.

The parameters are a joint result, six signed 20.12 scale/inverse-scale values,
a command containing node and parent byte indices, and SRT flags. Flag bit 2
selects an identity local scale. The function propagates identity bits, copies
24-byte scale pairs when multiplication is unnecessary, or multiplies all six
components with signed 64-bit intermediates and truncates after shifting by 12.
The parent cache is copied to the result's inherited-scale fields when needed.
Callers must supply valid pointers and cache indices; scale input supplies six
values whenever local scale is nonidentity.

Render-state identity bits begin at offset 0xc4. The scale cache uses 24-byte
records. Cache extent is intentionally unspecified because this function only
establishes byte-sized indices, not the allocation's full layout.

Validation: original instruction sequence and literal offsets reproduced;
objdiff and project gates are recorded in the worker report.

Hard list: none.
