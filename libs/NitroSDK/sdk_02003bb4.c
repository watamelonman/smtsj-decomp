#include "types.h"

/* NitroSDK background character-base pointers.
 * Reference lookup: pret/pokediamond arm9/lib/NitroSDK/src/GX_bgcnt.c
 * (G2_GetBGxCharPtr / G2S_GetBGxCharPtr family). See
 * docs/functions/libs-nitrosdk-sdk-02003bb4.md.
 */

/* Return the main BG0 character-data base. DISPCNT bits 27-29 select the
 * 64 KiB screen base; BG0CNT bits 2-5 select a 16 KiB character block.
 * Evidence: G2_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003bb4(void)
{
    u32 offset = ((*(volatile u16 *)0x04000008 & 0x3c) >> 2) << 14;
    return 0x06000000 +
        (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) + offset;
}

/* Return the sub BG0 character-data base. Sub BG0CNT bits 2-5 select a
 * 16 KiB block in the 0x06200000 sub engine region.
 * Evidence: G2S_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003be8(void)
{
    return 0x06200000 + (((*(volatile u16 *)0x04001008 & 0x3c) >> 2) << 14);
}

/* Return the main BG1 character-data base. DISPCNT bits 27-29 select the
 * 64 KiB screen base; BG1CNT bits 2-5 select a 16 KiB character block.
 * Evidence: G2_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003c08(void)
{
    u32 offset = ((*(volatile u16 *)0x0400000a & 0x3c) >> 2) << 14;
    return 0x06000000 +
        (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) + offset;
}

/* Return the sub BG1 character-data base. Sub BG1CNT bits 2-5 select a
 * 16 KiB block in the 0x06200000 sub engine region.
 * Evidence: G2S_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003c3c(void)
{
    return 0x06200000 + (((*(volatile u16 *)0x0400100a & 0x3c) >> 2) << 14);
}

/* Return the main BG2 character-data base, or null in extended bitmap modes
 * with bit 7 of BG2CNT set. Evidence: G2_GetBG2CharPtr in pret/pokediamond
 * GX_bgcnt.c.
 */
u32 func_02003c5c(void)
{
    int mode = *(volatile u32 *)0x04000000 & 7;
    u32 control = *(volatile u16 *)0x0400000c;

    if (mode < 5 || !(control & 0x80))
        return 0x06000000 +
            (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) +
            (((control & 0x3c) >> 2) << 14);
    return 0;
}

/* Return the sub BG2 character-data base, or null in extended bitmap modes
 * with bit 7 of sub BG2CNT set. Evidence: G2S_GetBG2CharPtr in
 * pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003cac(void)
{
    int mode = *(volatile u32 *)0x04001000 & 7;
    u32 control = *(volatile u16 *)0x0400100c;

    if (mode < 5 || !(control & 0x80))
        return 0x06200000 + (((control & 0x3c) >> 2) << 14);
    return 0;
}

/* Return the main BG3 character-data base, or null when BG3 is unusable
 * (mode >= 6, or extended bitmap mode with BG3CNT bit 7 set). Evidence:
 * G2_GetBG3CharPtr in pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003cec(void)
{
    int mode = *(volatile u32 *)0x04000000 & 7;
    u32 control = *(volatile u16 *)0x0400000e;

    if (mode < 3 || (mode < 6 && !(control & 0x80)))
        return 0x06000000 +
            (((*(volatile u32 *)0x04000000 & 0x7000000) >> 24) << 16) +
            (((control & 0x3c) >> 2) << 14);
    return 0;
}

/* Return the sub BG3 character-data base, or null when sub BG3 is unusable
 * (mode >= 6, or extended bitmap mode with sub BG3CNT bit 7 set). Evidence:
 * G2S_GetBG3CharPtr in pret/pokediamond GX_bgcnt.c.
 */
u32 func_02003d44(void)
{
    int mode = *(volatile u32 *)0x04001000 & 7;
    u32 control = *(volatile u16 *)0x0400100e;

    if (mode < 3 || (mode < 6 && !(control & 0x80)))
        return 0x06200000 + (((control & 0x3c) >> 2) << 14);
    return 0;
}
