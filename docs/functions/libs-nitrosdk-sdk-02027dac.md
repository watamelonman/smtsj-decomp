# sdk_02027dac

Although the delink labels this unit NitroSDK, all three routines correspond to
NitroSystem G3D. Public source was consulted before implementation:
[ntrtwl/NitroSystem](https://github.com/ntrtwl/NitroSystem/tree/d636fb5d2b212e8736f09859fff447be2bd0ac85/libraries/g3d/src),
also used by pret/pokeplatinum through its NitroSystem subproject.
Existing `func_` linker names are retained because symbol configuration is human-owned.
The local header describes only the resource/object portions these routines use.

## func_02027dac — NNSi_G3dAnmObjInitNsBva (76 bytes)

Source: `anm/nsbva.c`. Installs the default visibility callback from
`data_0213d36c`, stores the resource, and creates one identity map entry per model
node with the map-present bit (0x100). The caller must allocate enough trailing
map entries. The model node count is at byte 23; the object count/map are at
bytes 25/26. Other animation object fields remain untouched.

## func_02027df8 — NNSi_G3dAnmCalcNsBva (56 bytes)

Source: `anm/nsbva.c`. Takes the whole part of the signed 20.12 frame, computes
`frame * numNode + dataIdx`, and returns that visibility word's selected bit.
The result is the original mask, not a normalized boolean. The caller supplies
a valid frame/node index and a resource containing the corresponding words.

## func_02027e30 — NNSi_G3dSendJointSRTBasic (124 bytes)

Source: `cgtool/basic.c`. Flags 4, 2, and 1 indicate zero translation, zero
rotation, and unit scale. Sends a combined rotation/translation matrix (command
25, 12 words), translation alone (28, 3), or rotation alone (26, 9), then scale
(27, 3) when needed through `func_020252fc`. Rotation and translation occupy
adjacent storage in the joint result, as in the public source layout.

## Validation and hard list

The exact objdiff gate and ROM checksum gate validate compiled code and the
unchanged delink-based image respectively. No added behavioral tests are required
by this card. Hard list: none.
