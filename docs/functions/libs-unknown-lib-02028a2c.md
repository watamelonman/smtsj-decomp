# lib_02028a2c: SI3D submission and 3ds Max texture matrices

Known source was consulted before implementing either function:
[NitroSystem si3d.c](https://github.com/ntrtwl/NitroSystem/blob/d636fb5d2b212e8736f09859fff447be2bd0ac85/libraries/g3d/src/cgtool/si3d.c) and
[NitroSystem 3dsmax.c](https://github.com/ntrtwl/NitroSystem/blob/d636fb5d2b212e8736f09859fff447be2bd0ac85/libraries/g3d/src/cgtool/3dsmax.c).
Original linker symbols remain unchanged because symbol configuration is human-owned.

## func_02028a2c — 460 bytes, 100% objdiff

Matches `NNSi_G3dSendTexSRTSi3d`: constructs a 4x3 texture matrix using the
material's scale/translation identity flags, applies texture magnification,
and selects load or multiply from flag bit 3. Rotation is absent from this
SI3D path. The packet contains packed MTX_MODE, LOAD/MULT_4x3, MTX_MODE
commands and fourteen parameter words. The original geometry provider call
uses the packed command and remaining packet words as separate arguments.
The material is borrowed; the geometry packet lives on the stack during submission.

## func_02028bf8 — 264 bytes, 100% objdiff

Matches `texmtxCalc_flag_` in 3dsmax.c: combines scale, rotation, translation,
and original texture dimensions with aspect correction using asynchronous SDK
division. Writes only matrix entries 00, 01, 10, 11, 30 and 31. The matrix
is caller-owned and the material is borrowed. Scales, translations and rotation
use twelve fractional bits; dimensions are unsigned pixel counts. Nonzero
dimensions and exclusive access to the divider until both results are collected
are required by the original algorithm.

## Validation

The original delinked instructions serve as the matching oracle; no new tests
are required by the card. Both compiled functions match at 100% in objdiff.
The normal build continues to link this TU from the delink until human completion.

## Hard list

None.
