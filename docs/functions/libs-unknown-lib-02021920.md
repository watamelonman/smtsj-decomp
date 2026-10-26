# libs/unknown/lib_02021920

All four functions reconstruct NitroSystem's G3D kernel routines. Source was
located before implementation in
[ntrtwl/NitroSystem, libraries/g3d/src/kernel.c](https://github.com/ntrtwl/NitroSystem/blob/main/libraries/g3d/src/kernel.c).
The corresponding `include/nnsys/g3d/kernel.h` and
`include/nnsys/g3d/binres/res_struct.h` establish the field names and offsets.
Existing `func_` symbols are retained because the split configuration is human-owned.
The local header declares only the prefixes accessed by this unit, not complete
SDK objects; callers retain ownership and must supply valid list/render storage.

## func_02021920 — removeLink_ (116 bytes)

Removes the first node identical to `item` from a singly linked animation list.
Returns 1 on removal and clears the removed node's next pointer; returns 0 and
leaves the list untouched when absent. `next` is at offset 0x10. The source's
head special case and previous/current traversal reproduce the original flow.

## func_02021994 — NNS_G3dRenderObjRemoveAnmObj (84 bytes)

Searches material, joint, then visibility animation lists at offsets 8, 16, 24.
Stops after the first successful removal and sets HINT_OBSOLETE (0x10) in the
render flags. No list hit leaves flags unchanged. Both list ordering and the
flag constant agree with the known source.

## func_020219e8 — NNS_G3dTexGetRequiredSize (20 bytes)

Returns the unsigned halfword at texture-resource offset 0x0c multiplied by 8,
or zero for a null resource. This is ordinary texture storage in bytes; the
known `texInfo.sizeTex` field is measured in eight-byte units.

## func_020219fc — NNS_G3dTex4x4GetRequiredSize (20 bytes)

Returns `tex4x4Info.sizeTex` at offset 0x1c multiplied by 8, or zero for null.
This reports compressed texture bytes, without the separate palette-index data.

## Validation

The task exempts new tests. `python3 tools/match_gate.py` passed: all four
functions are 100% in objdiff, checking complete instructions and relocations
against each original function, including all traversal branches.
`python3 tools/anticheat.py` passed; all nine existing unittest tests passed.
`python3 tools/checksum.py` reported all artifacts byte-identical to the original.
The checksum gate verifies the linked original image while this TU remains
incomplete in the human-owned delink configuration.

## Hard list

None.
