# sdk_020544b0 BG control setters (M2-T099)

Evidence: public [NitroSDK gx_bgcnt.h](https://github.com/ntrtwl/NitroSDK/blob/master/include/nitro/gx/gx_bgcnt.h),
compared with the original ARM instructions at each symbol address. The SDK
expressions establish field order and meaning; the original literals establish
which display engine and background each wrapper targets. Existing `func_` symbols
are retained for objdiff and linkage.

All setters read and write one volatile 16-bit BG control register. Mask `0x43`
preserves priority (bits 0–1) and mosaic (bit 6), clearing other old fields.
Arguments are unshifted SDK field encodings: screen size 0–3, screen base 0–31
(in 2 KiB blocks), character base 0–15 (in 16 KiB blocks), and color mode or
area-over policy 0–1. Callers select the appropriate display mode beforehand.
There is no validation, allocation, or transferred ownership. Inputs outside SDK
ranges are not masked before combining; the final result is truncated to 16 bits.

## func_020544e4

Corresponds to `G2_SetBG3ControlText`; MMIO `0x0400000e`. Parameters: `(screenSize, colorMode, screenBase, charBase)`.
Writes shifts 14, 7, 8, and 2, in that order, after the preserved bits.

## func_02054510

Corresponds to `G2_SetBG2ControlText`; MMIO `0x0400000c`. Parameters: `(screenSize, colorMode, screenBase, charBase)`.
Writes shifts 14, 7, 8, and 2, in that order, after the preserved bits.

## func_020545a4

Corresponds to `G2S_SetBG3ControlAffine`; MMIO `0x0400100e`. Parameters: `(screenSize, areaOver, screenBase, charBase)`.
Writes screen size at bit 14, screen base at bit 8, character base at bit 2,
and wrap/transparent area-over policy at bit 13, in that order.

## func_020545d0

Corresponds to `G2S_SetBG2ControlAffine`; MMIO `0x0400100c`. Parameters: `(screenSize, areaOver, screenBase, charBase)`.
Writes screen size at bit 14, screen base at bit 8, character base at bit 2,
and wrap/transparent area-over policy at bit 13, in that order.

## func_020545fc

Corresponds to `G2_SetBG3ControlAffine`; MMIO `0x0400000e`. Parameters: `(screenSize, areaOver, screenBase, charBase)`.
Writes screen size at bit 14, screen base at bit 8, character base at bit 2,
and wrap/transparent area-over policy at bit 13, in that order.

## func_02054628

Corresponds to `G2_SetBG2ControlAffine`; MMIO `0x0400000c`. Parameters: `(screenSize, areaOver, screenBase, charBase)`.
Writes screen size at bit 14, screen base at bit 8, character base at bit 2,
and wrap/transparent area-over policy at bit 13, in that order.

## func_02054654

Corresponds to `G2S_SetBG3Control256x16Affine`; MMIO `0x0400100e`. Parameters: `(screenSize, areaOver, screenBase, charBase)`.
Writes screen size at bit 14, character base at bit 2, screen base at bit 8,
and area-over policy at bit 13, in that order. The SDK extended-palette
affine mode constant is zero; this ordering distinguishes it from the ordinary
affine setter even though its register value formula is equivalent.

## func_02054680

Corresponds to `G2S_SetBG2Control256x16Affine`; MMIO `0x0400100c`. Parameters: `(screenSize, areaOver, screenBase, charBase)`.
Writes screen size at bit 14, character base at bit 2, screen base at bit 8,
and area-over policy at bit 13, in that order. The SDK extended-palette
affine mode constant is zero; this ordering distinguishes it from the ordinary
affine setter even though its register value formula is equivalent.

## Scope and hard list

Only the eight M2-T099 functions are reconstructed. The other functions in this
shared TU belong to M2-T100 and remain in the delinked object. No hard cases
are identified for M2-T099. The human-owned delink completion flag is unchanged.
