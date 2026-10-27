#include "libs/NitroSDK/sdk_020026a0.h"

/* File-scope GX state that the original GX.c keeps next to this code.
 * Evidence: pret/pokediamond arm9/lib/NitroSDK/src/GX.c declares
 * `static u16 sDispMode` and `static u16 sIsDispOn`, and GX_state.c defines
 * `struct GX_State gGXState`; the delinked addresses below hold those objects. */
extern u16 data_021521a0;      /* sDispMode */
extern u16 data_0213ce40;      /* sIsDispOn */
extern GXState data_021521a4;  /* gGXState */

/* No-op entry: the original body at 0x020026a0 is only bx lr. */
void func_020026a0(void)
{
}

/* Set or clear the main-engine V-blank IRQ enable (DISPSTAT bit 3) and return
 * the bit's previous value, as sampled before the update.
 * Evidence: GX_VBlankIntr in pret/pokediamond GX.c. */
u32 func_020027f0(u32 enable)
{
    u32 previous = *(volatile u16 *)0x04000004 & 8;

    if (enable)
        *(volatile u16 *)0x04000004 |= 8;
    else
        *(volatile u16 *)0x04000004 &= ~8;

    return previous;
}

/* Hide the main display: remember the current BG mode (DISPCNT bits 16-17) in
 * sDispMode, mark the display off, and clear the mode field in DISPCNT.
 * Evidence: GX_DispOff in pret/pokediamond GX.c. */
void func_02002824(void)
{
    u32 control = *(volatile u32 *)0x04000000;

    data_0213ce40 = 0;
    data_021521a0 = (u16)((control & 0x30000) >> 16);
    *(volatile u32 *)0x04000000 = control & ~0x30000;
}

/* Show the main display again: mark it on, then restore the BG mode saved by
 * func_02002824. A zero saved mode enables graphics mode 1 instead.
 * Evidence: GX_DispOn in pret/pokediamond GX.c. */
void func_02002860(void)
{
    u16 mode;

    data_0213ce40 = 1;
    mode = data_021521a0;
    if (mode)
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x30000) |
                                      ((u32)mode << 16);
    else
        *(volatile u32 *)0x04000000 = *(volatile u32 *)0x04000000 | 0x10000;
}

/* Replace the sub-engine BG mode in the low three bits of DISPCNT_SUB.
 * Evidence: GXS_SetGraphicsMode in pret/pokediamond GX.c. */
void func_02002910(u32 value)
{
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~7u) | value;
}

/* Write a master-brightness value to a 16-bit register: zero clears the word,
 * positive values use sign mode 1 (bit 14), negatives mode 2 (bit 15) with the
 * magnitude. Evidence: GXx_SetMasterBrightness_ in pret/pokediamond GX.c. */
void func_0200292c(volatile u16 *dst, s32 brightness)
{
    if (!brightness) {
        *dst = 0;
        return;
    }
    if (brightness > 0)
        *dst = (u16)((1 << 14) | brightness);
    else
        *dst = (u16)((2 << 14) | -brightness);
}

/* Decode the master-brightness word written by func_0200292c: zero means off,
 * bits 14-15 select the sign mode and the low five bits hold the value.
 * Evidence: inverse of GXx_SetMasterBrightness_ in pret/pokediamond GX.c. */
s32 func_02002954(const volatile u16 *dst)
{
    u16 mode = *dst & 0xc000;

    if (mode == 0)
        return 0;
    if (mode == 0x4000)
        return *dst & 0x1f;
    if (mode == 0x8000)
        return -(*dst & 0x1f);
    return 0;
}

/* Clear the GX state record and the VRAM bank control registers. The record is
 * written as thirteen halfwords at gGXState+0 (lcdc, bg, obj, arm7, tex,
 * texPltt, clrImg, bgExtPltt, objExtPltt, sub_bg, sub_obj, sub_bgExtPltt,
 * sub_objExtPltt); the registers are VRAMCNT A-D, E, F, G and VRAM_HI_CNT.
 * Evidence: GX_InitGXState in pret/pokediamond GX_state.c. */
void func_02002998(void)
{
    data_021521a4.lcdc = 0;
    data_021521a4.bg = 0;
    data_021521a4.obj = 0;
    data_021521a4.arm7 = 0;
    data_021521a4.tex = 0;
    data_021521a4.texPltt = 0;
    data_021521a4.clrImg = 0;
    data_021521a4.bgExtPltt = 0;
    data_021521a4.objExtPltt = 0;
    data_021521a4.sub_bg = 0;
    data_021521a4.sub_obj = 0;
    data_021521a4.sub_bgExtPltt = 0;
    data_021521a4.sub_objExtPltt = 0;

    *(volatile u32 *)0x04000240 = 0;
    ((volatile u8 *)0x04000240)[4] = 0;
    ((volatile u8 *)0x04000240)[5] = 0;
    ((volatile u8 *)0x04000240)[6] = 0;
    *(volatile u16 *)0x04000248 = 0;
}
