# libs/unknown/lib_02028578

All three functions match at 100% with the configured mwccarm 2.0/sp1p5.
They are NitroSystem G3D `cgtool` texture/joint submission routines, although
the delink labels the unit `libs/unknown`. Public sources were consulted
before writing C:
[ntrtwl/NitroSystem, libraries/g3d/src/cgtool/maya.c](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/cgtool/maya.c),
the [ctrl-cheeb-del/pokeheartgold cgtool reconstruction](https://github.com/ctrl-cheeb-del/pokeheartgold/tree/master/lib/NitroSystem/src),
and the pret/pokediamond listing `arm9/asm/NNS_G3D_maya.s`. Existing `func_`
linker names are retained because the symbol configuration is human-owned.

The material view (`Unk0296b8Material`, twelve fractional bits, dimensions at
+44/+46, magnification at +48/+52) and the 4x4 matrix view are the shared
G3D cgtool layouts already declared by
`include/libs/unknown/lib_020296b8.h`. The joint result layout is declared in
this unit's header: flags at +0, local scale at +4, parent inverse scale
(`scaleEx0`) at +16, extra scale (`scaleEx1`) at +28, the 3x3 rotation at +40
and the translation at +76.

## func_02028578 — texmtxCalc_flagTRS_ (36 bytes)

Source: `cgtool/maya.c` and entry 7 of the constructor table at 0x0213d584.
Every texture-transform component is at its identity value, so the routine
writes unit scale (4096) to `_00`/`_11`, zero to `_01`/`_10`, and zero to the
S/T translation `_30`/`_31`. The other ten matrix entries are the caller's;
they are initialized by the submission wrapper. Matches 100%.

## func_0202859c — NNSi_G3dSendTexSRTMaya (328 bytes)

Source: `cgtool/maya.c`; the instruction sequence is identical to the
pokediamond listing. Flag bit 3 selects a load (`0x00101610`) instead of a
multiply (`0x00101810`) of the texture matrix; the packed words also switch
the matrix mode to texture and back to position-vector. The constructor table
at 0x0213d584 is indexed by the three identity flag bits, and the nine
constant entries are zeroed while `_33` stays at 4096. The material's `magW`
and `magH` then scale `_00/_01/_30` and `_10/_11/_31` respectively, and the
18-word packet is submitted through `func_020252fc`. The material is borrowed
and not modified. Matches 100%.

## func_020286e4 — Maya joint-SRT sender (300 bytes)

Source: reconstructed from the original instructions. The public cgtool
source describes the older sequence (translation, then rotation, then scale)
and that variant is already matched as `func_02027eec`; this routine is the
newer one, reached from the dispatch table entry at 0x0213d3e4 that sits next
to the texture sender. Two flag bits share one identity test (0x08 and 0x10,
`scaleEx0`/`scaleEx1`). While neither is identity, the extra scale at +28 is
submitted first, the translation is pre-multiplied by the parent inverse
scale (`(trans * scaleEx0) >> 12`, signed 64-bit intermediate) before being
sent, and `scaleEx0` is submitted after the rotation. A clear translation-zero
bit keeps the translation live: the rotation is then sent as 4x3 (12 words),
otherwise as 3x3 (9 words), otherwise the translation is sent on its own.
A clear scale-one bit (0x01) sends the local scale last. Commands go through
`func_020252fc`: scale 27, translation 28, 4x3 rotation 25, 3x3 rotation 26.
The result is borrowed and not modified. Matches 100%.

## Validation

`objdiff` reports 100% for all three functions, the full build reproduces the
original ARM9 image (checksum gate), and the anti-cheat scanner is clean. No
new behavioural tests were required by this card.

## Hard list

None.
