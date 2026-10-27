# NitroSDK BG pointers and affine helper (M2-T195, M2-T196)

Nine functions in `libs/NitroSDK/sdk_02003bb4.c`. All match at 100% in
objdiff. Symbols retain their original `func_` names so the human-owned
split/symbol configuration needs no changes. Eight take no arguments and
return a borrowed VRAM address; the ninth writes the four affine registers at
a caller-supplied hardware address. No memory is allocated. Hardware register
access is volatile. Callers must arrange valid VRAM bank mapping. The
prototypes and the `fx32`/`fx16`/`Mtx22` types are declared in
`include/libs/NitroSDK/sdk_02003bb4.h`.

## Evidence and reference lookup

The known NitroSDK implementation is the `G2_GetBGxCharPtr` /
`G2S_GetBGxCharPtr` family in
[GX_bgcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_bgcnt.c).
The instruction shapes below corroborate those names: DISPCNT bits 24-26 add
the 64 KiB character-base offset to a 16 KiB character block selected by bits
2-5 of the matching BGxCNT register. (The sibling screen-base getters in the
reference use DISPCNT bits 27-29 instead; this unit is the character-base
family.) The BG2/BG3 variants return null when the display mode makes that
background unusable in bitmap mode, matching the reference branch trees. The
public
[999 symbol list](https://github.com/Ed-1T/999-Code-Reference/blob/master/symbols9.x)
also lists the consecutive G2/G2S character-pointer entries.

`func_02003d8c` is the immediately following `G2x_SetBGyAffine_` in
[GX_g2.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g2.c).
That reference function is also 176 bytes, and its statement sequence produces
the target's exact instruction stream, including the two packed `PA/PB` and
`PC/PD` stores and the two displacement multiplies. The 999 symbol list records
`G2x_SetBGyAffine_` directly after `G2S_GetBG3CharPtr`, and its span there
(`0x0207C044` to `0x0207C08C`, then `0x0207C08C` to `0x0207C13C`) matches this
unit's 72- and 176-byte symbols.

The reference snapshots BGxCNT in a `u32` (`u32 temp = reg_G2_BGxCNT`). This
target differs by path: BG0/BG1 shift the directly-read `u16` control value,
which integer promotion makes signed and compiles to `asr`; BG2/BG3 widen the
register read into a `u32` local and compile to `lsr`. Each local type is
therefore chosen to reproduce the target's shift instruction, not as a style
preference. The mode comparison is signed (`blt`/`bge`), so `mode` is an
`int`. Those typing choices are evidence from the target object.

## Functions

- `func_02003bb4` (52 bytes): main BG0 character base. Reads BG0CNT at
  `0x04000008` bits 2-5, scales by 16 KiB, and adds DISPCNT bits 24-26
  scaled by 64 KiB plus `0x06000000`.
- `func_02003be8` (32 bytes): sub BG0 character base. Reads sub BG0CNT at
  `0x04001008`, scales bits 2-5 by 16 KiB, and adds `0x06200000`.
- `func_02003c08` (52 bytes): main BG1 character base. Same rule as BG0 but
  reads BG1CNT at `0x0400000a`.
- `func_02003c3c` (32 bytes): sub BG1 character base. Reads sub BG1CNT at
  `0x0400100a` and adds `0x06200000`.
- `func_02003c5c` (80 bytes): main BG2 character base. Reads DISPCNT mode and
  BG2CNT at `0x0400000c`; returns null only for modes 5-7 with BG2CNT bit 7
  set. Modes 6-7 with bit 7 clear still return the base: the target has a
  two-branch tree, unlike the newer reference's mode-6 special case.
- `func_02003cac` (64 bytes): sub BG2 character base. Reads sub DISPCNT and
  sub BG2CNT at `0x0400100c`; same null rule as main BG2, so modes 6-7 with
  bit 7 clear still return the base.
- `func_02003cec` (88 bytes): main BG3 character base. Reads DISPCNT mode and
  BG3CNT at `0x0400000e`; BG3 is unavailable in modes 6-7 and in extended
  bitmap mode (3-5) when bit 7 is set.
- `func_02003d44` (72 bytes): sub BG3 character base. Reads sub DISPCNT and
  sub BG3CNT at `0x0400100e` with the same mode/bit-7 availability rules.
- `func_02003d8c` (176 bytes): `G2x_SetBGyAffine_` shape. Writes BGxPA..BGxPD
  at the caller's register address. The 2x2 signed 20.12 matrix is truncated
  to signed 4.12 for PA/PB and PC/PD; the reference point `(x1, y1)` is offset from the
  rotation centre `(centerX, centerY)`, transformed by the matrix, and added to
  the centre displacement before the final 4-bit shift. The `ptr` argument is
  the hardware register address (callers pass `&reg_G2_BG2PA` and relatives),
  so the stores use `volatile u32` and no VRAM is reserved or freed.

## Validation

`tools/match_gate.py` reports every function in the file at 100%, and the
full build/checksum gates verify the linked image. No runtime tests were
added: the cards exempt tests, and these functions directly access DS hardware
registers. The original delink remains the linked implementation until a
human marks the unit complete.

## Hard list

None. All nine functions match from readable C.
