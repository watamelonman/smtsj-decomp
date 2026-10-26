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

