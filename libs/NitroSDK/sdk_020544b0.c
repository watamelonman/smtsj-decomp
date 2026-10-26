#include "types.h"

/* SDK evidence: ntrtwl/NitroSDK include/nitro/gx/gx_bgcnt.h; see the
 * per-function documentation for the source URL and register mapping.
 * Callers supply valid SDK field values; priority and mosaic are preserved. */

/* G2_SetBG3ControlText: gx_bgcnt.h and original MMIO 0x0400000e establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_020544e4(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400000e = (u16)((*(volatile u16 *)0x0400000e & 0x43)
        | (screenSize << 14) | (colorMode << 7)
        | (screenBase << 8) | (charBase << 2));
}

/* G2_SetBG2ControlText: gx_bgcnt.h and original MMIO 0x0400000c establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_02054510(u32 screenSize, u32 colorMode, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400000c = (u16)((*(volatile u16 *)0x0400000c & 0x43)
        | (screenSize << 14) | (colorMode << 7)
        | (screenBase << 8) | (charBase << 2));
}

/* G2S_SetBG3ControlAffine: gx_bgcnt.h and original MMIO 0x0400100e establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_020545a4(u32 screenSize, u32 areaOver, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400100e = (u16)((*(volatile u16 *)0x0400100e & 0x43)
        | (screenSize << 14) | (screenBase << 8)
        | (charBase << 2) | (areaOver << 13));
}

/* G2S_SetBG2ControlAffine: gx_bgcnt.h and original MMIO 0x0400100c establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_020545d0(u32 screenSize, u32 areaOver, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400100c = (u16)((*(volatile u16 *)0x0400100c & 0x43)
        | (screenSize << 14) | (screenBase << 8)
        | (charBase << 2) | (areaOver << 13));
}

/* G2_SetBG3ControlAffine: gx_bgcnt.h and original MMIO 0x0400000e establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_020545fc(u32 screenSize, u32 areaOver, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400000e = (u16)((*(volatile u16 *)0x0400000e & 0x43)
        | (screenSize << 14) | (screenBase << 8)
        | (charBase << 2) | (areaOver << 13));
}

/* G2_SetBG2ControlAffine: gx_bgcnt.h and original MMIO 0x0400000c establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_02054628(u32 screenSize, u32 areaOver, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400000c = (u16)((*(volatile u16 *)0x0400000c & 0x43)
        | (screenSize << 14) | (screenBase << 8)
        | (charBase << 2) | (areaOver << 13));
}

/* G2S_SetBG3Control256x16Affine: gx_bgcnt.h and original MMIO 0x0400100e establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_02054654(u32 screenSize, u32 areaOver, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400100e = (u16)((*(volatile u16 *)0x0400100e & 0x43)
        | (screenSize << 14) | (charBase << 2)
        | (screenBase << 8) | (areaOver << 13));
}

/* G2S_SetBG2Control256x16Affine: gx_bgcnt.h and original MMIO 0x0400100c establish
 * this setter. Inputs are unshifted SDK fields; no range checks are performed. */
void func_02054680(u32 screenSize, u32 areaOver, u32 screenBase, u32 charBase)
{
    *(volatile u16 *)0x0400100c = (u16)((*(volatile u16 *)0x0400100c & 0x43)
        | (screenSize << 14) | (charBase << 2)
        | (screenBase << 8) | (areaOver << 13));
}

/** Background control writes use the NitroSDK GX register layout.
 * See ntrtwl/NitroSDK include/nitro/gx/gx_bgcnt.h (URL in the
 * per-function documentation) for field meanings and expression order. */

/** Configure sub-engine BG0 text layout; the original register address and
 * shifts establish the fields. Preserve priority and mosaic (mask 0x43).
 * Arguments are SDK encodings: size 0..3, color 0..1, screen base 0..31,
 * character base 0..15, and extended palette slot 0..1. */
void func_020544b0(u32 size, u32 color,
                   u32 screen_base, u32 character_base,
                   u32 palette_slot)
{
    volatile u16 *control = (volatile u16 *)0x04001008;
    *control = (u16)((*control & 0x43) | (size << 14) |
                               (color << 7) | (screen_base << 8) |
                               (character_base << 2) | (palette_slot << 13));
}

/** Configure main-engine BG1 text layout; the original register address and
 * shifts establish the fields. Preserve priority and mosaic (mask 0x43).
 * Arguments are SDK encodings: size 0..3, color 0..1, screen base 0..31,
 * character base 0..15, and extended palette slot 0..1. */
void func_0205453c(u32 size, u32 color,
                   u32 screen_base, u32 character_base,
                   u32 palette_slot)
{
    volatile u16 *control = (volatile u16 *)0x0400000a;
    *control = (u16)((*control & 0x43) | (size << 14) |
                               (color << 7) | (screen_base << 8) |
                               (character_base << 2) | (palette_slot << 13));
}

/** Configure main-engine BG0 text layout; the original register address and
 * shifts establish the fields. Preserve priority and mosaic (mask 0x43).
 * Arguments are SDK encodings: size 0..3, color 0..1, screen base 0..31,
 * character base 0..15, and extended palette slot 0..1. */
void func_02054570(u32 size, u32 color,
                   u32 screen_base, u32 character_base,
                   u32 palette_slot)
{
    volatile u16 *control = (volatile u16 *)0x04000008;
    *control = (u16)((*control & 0x43) | (size << 14) |
                               (color << 7) | (screen_base << 8) |
                               (character_base << 2) | (palette_slot << 13));
}

/** Configure main-engine BG3 extended affine character layout; register
 * 0x0400000e and shifts establish these fields. Preserve priority and mosaic.
 * Size is 0..3, wrap is 0..1, screen base is 0..31, character base is 0..15. */
void func_020546ac(u32 size, u32 wrap,
                   u32 screen_base, u32 character_base)
{
    volatile u16 *control = (volatile u16 *)0x0400000e;
    *control = (u16)((*control & 0x43) | (size << 14) |
                               (character_base << 2) | (screen_base << 8) |
                               (wrap << 13));
}
