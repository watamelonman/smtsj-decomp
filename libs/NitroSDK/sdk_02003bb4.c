#include "libs/NitroSDK/sdk_02003bb4.h"

/* NitroSDK background character-base pointers.
 * Reference lookup: pret/pokediamond arm9/lib/NitroSDK/src/GX_bgcnt.c
 * (G2_GetBGxCharPtr / G2S_GetBGxCharPtr family). See
 * docs/functions/libs-nitrosdk-sdk-02003bb4.md.
 */

/* Return the main BG0 character-data base. DISPCNT bits 24-26 select the
 * 64 KiB character-base offset; BG0CNT bits 2-5 select a 16 KiB character
 * block. Evidence: G2_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003bb4(void)
{
    u32 offset = ((*(volatile u16 *)0x04000008 & 0x3c) >> 2) << 14;
    return (void *)(0x06000000 +
        (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) + offset);
}

/* Return the sub BG0 character-data base. Sub BG0CNT bits 2-5 select a
 * 16 KiB block in the 0x06200000 sub engine region.
 * Evidence: G2S_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003be8(void)
{
    return (void *)(0x06200000 +
        (((*(volatile u16 *)0x04001008 & 0x3c) >> 2) << 14));
}

/* Return the main BG1 character-data base. DISPCNT bits 24-26 select the
 * 64 KiB character-base offset; BG1CNT bits 2-5 select a 16 KiB character
 * block. Evidence: G2_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003c08(void)
{
    u32 offset = ((*(volatile u16 *)0x0400000a & 0x3c) >> 2) << 14;
    return (void *)(0x06000000 +
        (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) + offset);
}

/* Return the sub BG1 character-data base. Sub BG1CNT bits 2-5 select a
 * 16 KiB block in the 0x06200000 sub engine region.
 * Evidence: G2S_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003c3c(void)
{
    return (void *)(0x06200000 +
        (((*(volatile u16 *)0x0400100a & 0x3c) >> 2) << 14));
}

/* Return the main BG2 character-data base. The branch returns null only for
 * display modes 5-7 when BG2CNT bit 7 is set; modes 6-7 with that bit clear
 * still return the base, unlike the newer reference's mode-6 special case.
 * Evidence: G2_GetBG2CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003c5c(void)
{
    int mode = *(volatile u32 *)0x04000000 & 7;
    u32 control = *(volatile u16 *)0x0400000c;

    if (mode < 5 || !(control & 0x80))
        return (void *)(0x06000000 +
            (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) +
            (((control & 0x3c) >> 2) << 14));
    return (void *)0;
}

/* Return the sub BG2 character-data base. The branch returns null only for
 * display modes 5-7 when sub BG2CNT bit 7 is set; modes 6-7 with that bit clear
 * still return the base, unlike the newer reference's mode-6 special case.
 * Evidence: G2S_GetBG2CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003cac(void)
{
    int mode = *(volatile u32 *)0x04001000 & 7;
    u32 control = *(volatile u16 *)0x0400100c;

    if (mode < 5 || !(control & 0x80))
        return (void *)(0x06200000 +
            (((control & 0x3c) >> 2) << 14));
    return (void *)0;
}

/* Return the main BG3 character-data base, or null when BG3 is unusable
 * (modes 6-7, or modes 3-5 with BG3CNT bit 7 set). Evidence:
 * G2_GetBG3CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003cec(void)
{
    int mode = *(volatile u32 *)0x04000000 & 7;
    u32 control = *(volatile u16 *)0x0400000e;

    if (mode < 3 || (mode < 6 && !(control & 0x80)))
        return (void *)(0x06000000 +
            (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) +
            (((control & 0x3c) >> 2) << 14));
    return (void *)0;
}

/* Return the sub BG3 character-data base, or null when sub BG3 is unusable
 * (modes 6-7, or modes 3-5 with sub BG3CNT bit 7 set). Evidence:
 * G2S_GetBG3CharPtr in pret/pokediamond GX_bgcnt.c.
 */
void *func_02003d44(void)
{
    int mode = *(volatile u32 *)0x04001000 & 7;
    u32 control = *(volatile u16 *)0x0400100e;

    if (mode < 3 || (mode < 6 && !(control & 0x80)))
        return (void *)(0x06200000 +
            (((control & 0x3c) >> 2) << 14));
    return (void *)0;
}

/* Write the four BGx affine registers at `ptr` (BGxPA, BGxPB, BGxPC, BGxPD in
 * that order). The 2x2 signed 20.12 matrix supplies the rotation/scale; the
 * reference point is first made relative to the rotation centre, then rotated
 * and scaled to produce the two displacement registers. Matrix elements are
 * truncated to signed 4.12 before being packed as PA/PB and PC/PD. `ptr` is a hardware
 * register address; `centerX`/`centerY` and `x1`/`y1` use signed 20.12 units.
 * Evidence: this is G2x_SetBGyAffine_ from pret/pokediamond
 * arm9/lib/NitroSDK/src/GX_g2.c, whose 176-byte instruction stream matches.
 */
void func_02003d8c(u32 ptr, const struct Mtx22 *mtx, fx32 centerX,
                   fx32 centerY, fx32 x1, fx32 y1)
{
    fx32 dx, dy, temp2, temp3;

    *(volatile u32 *)(ptr + 0) = (u32)((u16)(fx16)(mtx->_[0] >> 4) |
        (u32)((u16)(fx16)(mtx->_[1] >> 4) << 16));
    *(volatile u32 *)(ptr + 4) = (u32)((u16)(fx16)(mtx->_[2] >> 4) |
        (u32)((u16)(fx16)(mtx->_[3] >> 4) << 16));
    dx = x1 - centerX;
    dy = y1 - centerY;
    temp2 = mtx->_[0] * dx + mtx->_[1] * dy + (centerX << 12);
    temp3 = mtx->_[2] * dx + mtx->_[3] * dy + (centerY << 12);
    *(volatile u32 *)(ptr + 8) = (u32)(temp2 >> 4);
    *(volatile u32 *)(ptr + 12) = (u32)(temp3 >> 4);
}
