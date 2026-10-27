#include "libs/NitroSDK/sdk_020026a0.h"

/* File-scope GX state that the original GX.c keeps next to this code.
 * Evidence: pret/pokediamond arm9/lib/NitroSDK/src/GX.c declares
 * `static u16 sDispMode`, `vu16 GXi_VRamLockId` and `u32 GXi_DmaId`, and
 * GX_state.c defines `struct GX_State gGXState`; the delinked addresses below
 * hold those objects. data_021521a0 covers sDispMode followed by the lock ID;
 * GXi_DmaId is the word at data_0213ce40 + 4. */
extern GXDispState data_021521a0;  /* sDispMode, GXi_VRamLockId */
extern u16 data_0213ce40;          /* sIsDispOn */
extern GXState data_021521a4;      /* gGXState */

/* NitroSDK routines called by GX_Init. Their delinked names stay neutral
 * because this unit only sees the call sites. Evidence: the argument/return
 * shapes match OS_GetLockID, OS_Terminate, MI_DmaFill32 and MIi_CpuClear32 in
 * pret/pokediamond's OS_spinLock.c, OS_terminate_proc.c, MI_dma.c and
 * MI_memory.c. */
extern s32 func_02005d6c(void);                         /* OS_GetLockID */
extern void func_02007e94(void);                        /* OS_Terminate */
extern void func_02007ec0(u32 dma, void *dst, u32 value, u32 size);
extern void func_020086a0(u32 value, void *dst, u32 size);

/* No-op entry: the original body at 0x020026a0 is only bx lr. */
void func_020026a0(void)
{
}

/* Prepare the main engine for use: force the 2D engine and LCD on, clear the
 * GX state, block until a VRAM lock ID is free (terminating on the error code),
 * reset the display registers, wipe the 2D and sub-engine register blocks
 * through DMA or the CPU, and load identity affine matrices.
 * Evidence: GX_Init in pret/pokediamond GX.c; every register and mask below
 * matches that source and the delinked instruction stream. */
void func_020026a4(void)
{
    s32 temp;

    *(volatile u16 *)0x04000304 |= 0x8000;
    *(volatile u16 *)0x04000304 =
        (u16)((*(volatile u16 *)0x04000304 & 0xfffffdf1) | 0x020e);
    *(volatile u16 *)0x04000304 |= 1;

    func_02002998();

    while (data_021521a0.vramLockId == 0) {
        temp = func_02005d6c();
        if (temp == -3)  /* OS_LOCK_ID_ERROR in this SDK */
            func_02007e94();
        data_021521a0.vramLockId = (u16)temp;
    }

    *(volatile u16 *)0x04000004 = 0;
    *(volatile u32 *)0x04000000 = 0;
    {
        /* GXi_DmaId lives just past sIsDispOn in the original data layout. */
        u32 dmaId = *(volatile u32 *)((u8 *)&data_0213ce40 + 4);

        if (dmaId != (u32)-1) {
            func_02007ec0(dmaId, (void *)0x04000008, 0, 0x60);
            *(volatile u16 *)0x0400006c = 0;
            func_02007ec0(*(volatile u32 *)((u8 *)&data_0213ce40 + 4),
                          (void *)0x04001000, 0, 0x70);
        } else {
            func_020086a0(0, (void *)0x04000008, 0x60);
            *(volatile u16 *)0x0400006c = 0;
            func_020086a0(0, (void *)0x04001000, 0x70);
        }
    }

    /* BG2PA/BG2PD/BG3PA/BG3PD, then the same four sub-engine registers. */
    *(volatile u16 *)0x04000020 = 0x100;
    *(volatile u16 *)0x04000026 = 0x100;
    *(volatile u16 *)0x04000030 = 0x100;
    *(volatile u16 *)0x04000036 = 0x100;
    *(volatile u16 *)0x04001020 = 0x100;
    *(volatile u16 *)0x04001026 = 0x100;
    *(volatile u16 *)0x04001030 = 0x100;
    *(volatile u16 *)0x04001036 = 0x100;
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
    data_021521a0.dispMode = (u16)((control & 0x30000) >> 16);
    *(volatile u32 *)0x04000000 = control & ~0x30000;
}

/* Show the main display again: mark it on, then restore the BG mode saved by
 * func_02002824. A zero saved mode enables graphics mode 1 instead.
 * Evidence: GX_DispOn in pret/pokediamond GX.c. */
void func_02002860(void)
{
    u16 mode;

    data_0213ce40 = 1;
    mode = data_021521a0.dispMode;
    if (mode)
        *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & ~0x30000) |
                                      ((u32)mode << 16);
    else
        *(volatile u32 *)0x04000000 = *(volatile u32 *)0x04000000 | 0x10000;
}

/* Rebuild the main DISPCNT from a requested display mode, BG mode and BG0
 * 2D/3D selection. The display mode is remembered even while the display is
 * off, but a cleared mode leaves the display marked off; a zero saved mode
 * forces sIsDispOn off afterwards.
 * Evidence: GX_SetGraphicsMode in pret/pokediamond GX.c and the delinked
 * register mask 0xfff0fff0 (BG mode, display mode, BG0 2D/3D and VRAM bits). */
void func_020028a8(u32 dispMode, u32 bgMode, u32 bg0_2d3d)
{
    u32 control = *(volatile u32 *)0x04000000;

    data_021521a0.dispMode = (u16)dispMode;
    if (!data_0213ce40)
        dispMode = 0;
    *(volatile u32 *)0x04000000 =
        bgMode | ((control & 0xfff0fff0) | (dispMode << 16)) | (bg0_2d3d << 3);
    if (!data_021521a0.dispMode)
        data_0213ce40 = 0;
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
