/* NitroSDK background screen pointers. Hardware register evidence and reference
 * lookup: docs/functions/libs-nitrosdk-sdk-020039a4.md. */
typedef unsigned int u32;
typedef unsigned short u16;

/* G2S_GetBG1ScrPtr shape: sub BG1CNT screen-base bits select 2 KiB blocks. */
void *func_020039a4(void)
{
    int block = (*(volatile u16 *)0x0400100a & 0x1f00) >> 8;
    return (void *)(0x06200000 + (block << 11));
}

/* G2_GetBG2ScrPtr shape: DISPCNT mode and BG2CNT select the
 * screen base; bitmap blocks use 16 KiB, tile maps 2 KiB. Unsupported modes return null. */
void *func_020039c4(void)
{
    u32 mode = *(volatile u32 *)0x04000000 & 7;
    u32 control = *(volatile u16 *)0x0400000c;
    u32 offset = ((*(volatile u32 *)0x04000000 & 0x38000000) >> 27) << 16;
    u32 block = (control & 0x1f00) >> 8;
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return (void *)(0x06000000 + offset + (block << 11));
    case 5:
        if (control & 0x80)
            return (void *)(0x06000000 + (block << 14));
        else
            return (void *)(0x06000000 + offset + (block << 11));
    case 6:
        return (void *)0x06000000;
    default:
        return 0;
    }
}

/* G2S_GetBG2ScrPtr shape: DISPCNT mode and BG2CNT select the
 * screen base; bitmap blocks use 16 KiB, tile maps 2 KiB. Unsupported modes return null. */
void *func_02003a48(void)
{
    u32 mode = *(volatile u32 *)0x04001000 & 7;
    u32 control = *(volatile u16 *)0x0400100c;
    u32 block = (control & 0x1f00) >> 8;
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return (void *)(0x06200000 + (block << 11));
    case 5:
        if (control & 0x80)
            return (void *)(0x06200000 + (block << 14));
        else
            return (void *)(0x06200000 + (block << 11));
    case 6:
        return 0;
    default:
        return 0;
    }
}

/* G2_GetBG3ScrPtr shape: DISPCNT mode and BG3CNT select the
 * screen base; bitmap blocks use 16 KiB, tile maps 2 KiB. Unsupported modes return null. */
void *func_02003abc(void)
{
    u32 mode = *(volatile u32 *)0x04000000 & 7;
    u32 control = *(volatile u16 *)0x0400000e;
    u32 offset = ((*(volatile u32 *)0x04000000 & 0x38000000) >> 27) << 16;
    u32 block = (control & 0x1f00) >> 8;
    switch (mode) {
    case 0:
    case 1:
    case 2:
        return (void *)(0x06000000 + offset + (block << 11));
    case 3:
    case 4:
    case 5:
        if (control & 0x80)
            return (void *)(0x06000000 + (block << 14));
        else
            return (void *)(0x06000000 + offset + (block << 11));
    case 6:
        return 0;
    default:
        return 0;
    }
}

/* G2S_GetBG3ScrPtr shape: DISPCNT mode and BG3CNT select the
 * screen base; bitmap blocks use 16 KiB, tile maps 2 KiB. Unsupported modes return null. */
void *func_02003b40(void)
{
    u32 mode = *(volatile u32 *)0x04001000 & 7;
    u32 control = *(volatile u16 *)0x0400100e;
    u32 block = (control & 0x1f00) >> 8;
    switch (mode) {
    case 0:
    case 1:
    case 2:
        return (void *)(0x06200000 + (block << 11));
    case 3:
    case 4:
    case 5:
        if (control & 0x80)
            return (void *)(0x06200000 + (block << 14));
        else
            return (void *)(0x06200000 + (block << 11));
    case 6:
        return 0;
    default:
        return 0;
    }
}
