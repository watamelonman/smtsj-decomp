# libs/NitroSDK/sdk_02054284 — GX BG setters and a VRAM/free-block allocator (M2-T112)

Evidence: public [NitroSDK gx_bgcnt.h](https://github.com/ntrtwl/NitroSDK/blob/main/include/nitro/gx/gx_bgcnt.h),
compared with the original ARM instructions and the MMIO literals at each
symbol. The SDK expressions establish field order and meaning; the original
literals establish which display engine and background each wrapper targets.
Existing `func_` symbols are retained for objdiff and linkage.

All BG setters read and write one volatile 16-bit control register. Mask `0x43`
preserves priority (bits 0–1) and mosaic (bit 6), clearing the other old fields.
Arguments are unshifted SDK field encodings: screen size 0–3, color mode /
extended-palette slot 0–1, screen base 0–31 (2 KiB blocks), and character base
0–15 (16 KiB blocks). There is no validation, allocation, or transferred
ownership. Inputs outside SDK ranges are not masked before combining; the final
result is truncated to 16 bits.

## func_02054284

Comparator for the 8-byte free-block records used by `func_02054294`. The
original `func_02054294` passes this address with element size 8 to the MSL sort
routine `func_02013c68`, and the body loads the first word of each record and
returns `a->start - b->start`, so the records are sorted by start offset.
Borrowed `const void *` arguments; callers must supply two valid records.

## func_02054424

Corresponds to `G2S_SetBG3ControlText`; MMIO `0x0400100e`. Parameters:
`(screenSize, colorMode, screenBase, charBase)`. Writes shifts 14, 7, 8, and 2,
in that order, after the preserved bits.

## func_02054450

Corresponds to `G2S_SetBG2ControlText`; MMIO `0x0400100c`. Parameters and
expression order match `func_02054424`, targeting sub-engine BG2.

## func_0205447c

Corresponds to `G2S_SetBG1Control`; MMIO `0x0400100a`. Parameters:
`(screenSize, colorMode, screenBase, charBase, bgExtPltt)`. Writes shifts 14, 7,
8, 2, and 13, in that order. The fifth argument selects the extended-palette
slot; that is why this wrapper has one more parameter than the BG2/BG3 text
setters.

## Hard list

### func_02054294 (400 B, not reconstructed)

The original is a free-block allocator over the caller-owned structure
`{ u32 count; struct { u32 start; u32 size; } blocks[]; }`. The observed
algorithm is:

- First pass: for each block whose `size` fits, try to allocate at the block
  start when `start` is aligned (advance `start`, shrink `size`), or just below
  the block end when `end - size` is aligned (shrink `size`). `fromStart != 0`
  tries the start edge first; `fromStart == 0` tries the tail edge first.
- Second pass: if no edge-aligned fit exists, take the interior aligned address
  `ALIGN_UP(start, align)`, move the leading remainder into a new final record,
  leave the trailing remainder in place, then increment `count` and sort all
  records by start with `func_02013c68(..., 8, func_02054284)`.
- Returns the allocated offset, or zero when no block fits.

The reconstructed C produces the same operations but not the original register
allocation. mwcc 2.0/sp1p5 keeps the list pointer in `r5` (original: `r6`),
`blockSize` in `r6`/`r8` (original: `r7`), and `align - 1` in `r7` (original:
`r5`); the best variant is 392 bytes of code versus the original 396. Variants
tried: struct and `u32 *` indexing, `for`/`while`/`if`+`do-while`, local or
expanded count/mask/addr/blockSize, separate loop indices, and multiple
declaration orders. Because no variant reproduces the instruction registers,
the function is left undefined in C so the delink keeps linking the original
body. The rest of the translation unit is reconstructed above.

## Validation

- `python3 tools/hand/cmp.py` reports 100% for `func_02054284`,
  `func_02054424`, `func_02054450`, and `func_0205447c`.
- `python3 tools/match_gate.py` passes for every C function defined in this TU.
- `python3 tools/checksum.py`: all artifacts byte-identical (the TU is still
  linked from the delink, as required until a human marks it complete).
- `python3 tools/anticheat.py` and the unit-test gate pass.
