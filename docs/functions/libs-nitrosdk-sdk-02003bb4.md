# NitroSDK BG character-base pointers (M2-T195)

Eight functions in `libs/NitroSDK/sdk_02003bb4.c`. All match at 100% in
objdiff. Symbols retain their original `func_` names so the human-owned
split/symbol configuration needs no changes. Each takes no arguments and
returns a borrowed VRAM address; no memory is allocated. Hardware register
reads are volatile. Callers must arrange valid VRAM bank mapping.

## Evidence and reference lookup

The known NitroSDK implementation is the `G2_GetBGxCharPtr` /
`G2S_GetBGxCharPtr` family in
[GX_bgcnt.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_bgcnt.c).
The instruction shapes below corroborate those names: DISPCNT bits 27-29 add
the 64 KiB screen base to a 16 KiB character block selected by bits 2-5 of the
matching BGxCNT register. The BG2/BG3 variants return null when the display
mode makes that background unusable in bitmap mode, matching the reference
branch trees. The public
[999 symbol list](https://github.com/Ed-1T/999-Code-Reference/blob/master/symbols9.x)
also lists the consecutive G2/G2S character-pointer entries.

The reference source uses `u16 control`; this original instead shifts the
masked BGxCNT value unsigned (`lsr`), so the code keeps it in a `u32` to
reproduce the instruction. The mode comparison is signed (`blt`/`bge`), so
`mode` is an `int`. Those typing choices are evidence from the target object,
not style preferences.

## Functions

- `func_02003bb4` (52 bytes): main BG0 character base. Reads BG0CNT at
  `0x04000008` bits 2-5, scales by 16 KiB, and adds DISPCNT bits 27-29
  scaled by 64 KiB plus `0x06000000`.
- `func_02003be8` (32 bytes): sub BG0 character base. Reads sub BG0CNT at
  `0x04001008`, scales bits 2-5 by 16 KiB, and adds `0x06200000`.
- `func_02003c08` (52 bytes): main BG1 character base. Same rule as BG0 but
  reads BG1CNT at `0x0400000a`.
- `func_02003c3c` (32 bytes): sub BG1 character base. Reads sub BG1CNT at
  `0x0400100a` and adds `0x06200000`.
- `func_02003c5c` (80 bytes): main BG2 character base. Reads DISPCNT mode and
  BG2CNT at `0x0400000c`; returns null for modes 5-7 with BG2CNT bit 7 set.
- `func_02003cac` (64 bytes): sub BG2 character base. Reads sub DISPCNT and
  sub BG2CNT at `0x0400100c`; returns null for modes 5-7 with bit 7 set.
- `func_02003cec` (88 bytes): main BG3 character base. Reads DISPCNT mode and
  BG3CNT at `0x0400000e`; BG3 is unavailable in modes 6-7 and in extended
  bitmap mode (3-5) when bit 7 is set.
- `func_02003d44` (72 bytes): sub BG3 character base. Reads sub DISPCNT and
  sub BG3CNT at `0x0400100e` with the same mode/bit-7 availability rules.

## Validation

`tools/match_gate.py` reports every function in the file at 100%, and the
full build/checksum gates verify the linked image. No runtime tests were
added: the card exempts tests, and these functions directly read DS hardware
registers. The original delink remains the linked implementation until a
human marks the unit complete.

## Hard list

None. `func_02003d8c` (the remaining function in this split) belongs to the
follow-up card M2-T196 and is not part of this change.
