# NitroSDK screen-base pointers (M2-T053)

All five functions match at 100% in objdiff. Symbols retain their original
`func_` names so the human-owned split/symbol configuration needs no changes.
Each takes no arguments and returns a borrowed VRAM address; no memory is
allocated or accessed through the returned pointer. Reads of hardware registers
are volatile. Callers must arrange valid VRAM bank mapping.

## Evidence and reference lookup

Looked first at pret/pokediamond's known NitroSDK source:
[GX_g2.c](https://github.com/pret/pokediamond/blob/master/arm9/lib/NitroSDK/src/GX_g2.c).
That file reconstructs affine/blend helpers rather than these pointer helpers;
the implementation here follows the original instructions. The corresponding
SDK names are corroborated by the public
[999 symbol list](https://github.com/Ed-1T/999-Code-Reference/blob/master/symbols9.x),
whose consecutive G2S_GetBG1ScrPtr, G2_GetBG2ScrPtr, G2S_GetBG2ScrPtr,
G2_GetBG3ScrPtr, G2S_GetBG3ScrPtr entries have the same function sizes/order.
The hardware addresses, masks, branch tables, and offsets below independently
support the shape descriptions used in code comments.

## Functions

- `func_020039a4` (32 bytes): G2S_GetBG1ScrPtr shape. Reads sub BG1CNT
  at `0x0400100a`, extracts bits 8–12, scales by 2 KiB, and adds
  sub BG VRAM base `0x06200000`.
- `func_020039c4` (132 bytes): G2_GetBG2ScrPtr shape. Reads main
  DISPCNT and BG2CNT (`0x0400000c`). Modes 0–4 use 2 KiB screen blocks
  plus DISPCNT bits 27–29 scaled by 64 KiB. Mode 5 uses that same formula
  when BG2CNT bit 7 is clear, otherwise 16 KiB bitmap blocks without the
  global offset. Mode 6 returns `0x06000000`; mode 7 returns null.
- `func_02003a48` (116 bytes): G2S_GetBG2ScrPtr shape. Reads sub
  DISPCNT and BG2CNT (`0x0400100c`). Modes 0–4 use 2 KiB blocks,
  mode 5 selects 2 KiB or 16 KiB blocks with control bit 7, and modes
  6–7 return null. Non-null addresses start at `0x06200000`.
- `func_02003abc` (132 bytes): G2_GetBG3ScrPtr shape. Same main-engine
  offset rules as BG2, but reads BG3CNT (`0x0400000e`): modes 0–2
  use tile maps, modes 3–5 select tile maps or bitmaps, and modes 6–7
  return null.
- `func_02003b40` (116 bytes): G2S_GetBG3ScrPtr shape. Reads sub
  BG3CNT (`0x0400100e`), uses tile maps for modes 0–2 and selects
  tile maps or bitmaps for modes 3–5. Modes 6–7 return null.

## Validation

Standalone compiler/ROM instruction comparisons and the objdiff match gate
verify all five bodies, including switch tables, volatile load order and literals.
No runtime tests were added: the task exempts tests, and these functions directly
read DS hardware registers. The original delink remains the linked implementation
until a human marks the unit complete.

## Hard list

None.
