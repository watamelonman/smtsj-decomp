# libs/unknown/lib_02027eac

All three functions match at 100% with the configured mwccarm 2.0/sp1p5.
They are NitroSystem G3D `cgtool` routines, although the delink labels the unit
`libs/unknown`. Public source was consulted before writing C:
[ntrtwl/NitroSystem, libraries/g3d/src/cgtool](https://github.com/ntrtwl/NitroSystem/tree/main/libraries/g3d/src/cgtool),
specifically `basic.c` and `maya.c`. Existing `func_` linker names are retained
because the symbol configuration is human-owned.

The header describes the joint-result layout used by both scaling rules. SRT
flags 4, 2 and 1 mean unit scale, zero rotation and zero translation. Result
flags 1, 2, 4, 8, 0x10 and 0x20 mean scale-one, rotation-zero, translation-zero,
scaleEx0-one, scaleEx1-one and Maya scale compensation.

## func_02027eac — NNSi_G3dGetJointScaleBasic (64 bytes)

Source: `cgtool/basic.c`. Flag bit 2 selects a unit local scale, in which case
result flag 1 is set; otherwise the three signed 20.12 scale words are copied
from the caller's array. Both extended scale-identity flags (8 and 0x10) are
always set. The command pointer is unused by this rule. Matches 100%.

## func_02027eec — NNSi_G3dSendJointSRTMaya (196 bytes)

Source: `cgtool/maya.c`. A clear flag bit 2 means the translation is non-zero,
bit 0x20 with a clear bit 8 selects Maya scale compensation, bit 1 selects zero
rotation and bit 0 already selects a unit scale. The routine emits the needed
geometry commands through `func_020252fc`: translation (28, 3 words), scale
(27, 3), 4x3 rotation+translation (25, 12) or 3x3 rotation (26, 9). Submission
order keeps the translation bit as a local state so each component is sent
once. Matches 100%.

## func_02027fb0 — NNSi_G3dGetJointScaleMaya (336 bytes)

Source: `cgtool/maya.c`. The command byte at +1 is the node index, +2 the
parent index and +3 the node-descriptor flags (1 = apply parent compensation,
2 = parent compensation present). Identity-scale bits live in the render
state at +0xc4; the global scale cache holds 24-byte scale/inverse pairs per
node. A unit local scale sets the node's identity bit; otherwise the local
scale is copied, the identity bit is cleared and the three inverse-scale words
are stored. When apply is set, the result asks for Maya compensation and
either marks scaleEx0 as identity or copies the parent's inverse scale; the
extended scaleEx1 flag is always set. Matches 100%.

The three inverse words are addressed through the delinked word symbols
`data_02157d9c`, `data_02157da0` and `data_02157da4`, each viewed as the start
of a 24-byte record. This preserves the original per-word relocations without
changing the cache layout or arithmetic.

## Validation

The exact objdiff comparison and ROM checksum gate validate all three functions
against the delinked original. No new behavioral tests were required by this
card.

## Hard list

None.
