#include "types.h"

/* Borrowed SDK VRAM allocation state. Field offsets follow the original loads
 * and the neighboring bank setters; GX_State in pret/pokediamond GX_vramcnt.c
 * corroborates the allocation roles. Masks use bits 0-8 for VRAM banks A-I.
 */
typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clearImage;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 subBg;
    u16 subObj;
    u16 subBgExtPltt;
    u16 subObjExtPltt;
} VramAllocationState;

extern VramAllocationState data_021521a4;

/* Return the main background bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0x2; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_0200387c(void)
{
    return data_021521a4.bg;
}

/* Return the main object bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0x4; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_0200388c(void)
{
    return data_021521a4.obj;
}

/* Return the main background extended palette bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0xe; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_0200389c(void)
{
    return data_021521a4.bgExtPltt;
}

/* Return the main object extended palette bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0x10; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_020038ac(void)
{
    return data_021521a4.objExtPltt;
}

/* Return the texture bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0x8; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_020038bc(void)
{
    return data_021521a4.tex;
}

/* Return the texture palette bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0xa; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_020038cc(void)
{
    return data_021521a4.texPltt;
}

/* Return the sub background bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0x12; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_020038dc(void)
{
    return data_021521a4.subBg;
}

/* Return the sub object bank mask without changing allocation.
 * Evidence: original u16 load at SDK state +0x14; corresponding
 * GX_SetBankFor role in pret/pokediamond GX_vramcnt.c (see function docs).
 */
u32 func_020038ec(void)
{
    return data_021521a4.subObj;
}

/* Clear a borrowed allocation slot, disable its banks, release their SDK lock,
 * and return the previous bank mask. Evidence: original helper at 02003650
 * and disableBankForX_ in pret/pokediamond GX_vramcnt.c.
 */
extern u32 func_02003650(u16 *bank);
extern u16 data_021521ac;
extern u16 data_021521ae;
extern u16 data_021521b0;
extern u16 data_021521aa;
extern u16 data_021521b6;

/* Disable the Tex VRAM banks and return their previous mask (bits 0-8).
 * Evidence: original slot literal and GX_DisableBankForTex in
 * pret/pokediamond GX_vramcnt.c; the helper clears the slot and unlocks banks.
 */
u32 func_020037a0(void)
{
    return func_02003650(&data_021521ac);
}

/* Disable the TexPltt VRAM banks and return their previous mask (bits 0-8).
 * Evidence: original slot literal and GX_DisableBankForTexPltt in
 * pret/pokediamond GX_vramcnt.c; the helper clears the slot and unlocks banks.
 */
u32 func_020037b4(void)
{
    return func_02003650(&data_021521ae);
}

/* Disable the ClearImage VRAM banks and return their previous mask (bits 0-8).
 * Evidence: original slot literal and GX_DisableBankForClearImage in
 * pret/pokediamond GX_vramcnt.c; the helper clears the slot and unlocks banks.
 */
u32 func_020037c8(void)
{
    return func_02003650(&data_021521b0);
}

/* Disable the ARM7 VRAM banks and return their previous mask (bits 0-8).
 * Evidence: original slot literal and GX_DisableBankForARM7 in
 * pret/pokediamond GX_vramcnt.c; the helper clears the slot and unlocks banks.
 */
u32 func_020037dc(void)
{
    return func_02003650(&data_021521aa);
}

/* Disable the LCDC VRAM banks and return their previous mask (bits 0-8).
 * Evidence: original slot literal and GX_DisableBankForLCDC in
 * pret/pokediamond GX_vramcnt.c; the helper clears the slot and unlocks banks.
 */
u32 func_020037f0(void)
{
    return func_02003650(&data_021521a4.lcdc);
}

/* Disable the SubBG VRAM banks and return their previous mask (bits 0-8).
 * Evidence: original slot literal and GX_DisableBankForSubBG in
 * pret/pokediamond GX_vramcnt.c; the helper clears the slot and unlocks banks.
 */
u32 func_02003804(void)
{
    return func_02003650(&data_021521b6);
}

/* Return the SubBGExtPltt bank mask (bits 0-8) without changing allocation.
 * Evidence: original u16 load at state +0x16 and the corresponding
 * GX_SetBankForSubBGExtPltt field in pret/pokediamond GX_vramcnt.c.
 */
u32 func_020038fc(void)
{
    return data_021521a4.subBgExtPltt;
}

/* Return the SubOBJExtPltt bank mask (bits 0-8) without changing allocation.
 * Evidence: original u16 load at state +0x18 and the corresponding
 * GX_SetBankForSubOBJExtPltt field in pret/pokediamond GX_vramcnt.c.
 */
u32 func_0200390c(void)
{
    return data_021521a4.subObjExtPltt;
}

extern u16 data_021521b4;
extern u16 data_021521b8;
extern u16 data_021521ba;
extern u16 data_021521bc;

/* Disable main OBJ extended palettes before releasing their banks; return the
 * old mask. Evidence: GX_DisableBankForOBJExtPltt in pret/pokediamond
 * GX_vramcnt.c and the original DISPCNT bit 31 clear / slot address.
 */
u32 func_0200377c(void)
{
    *(volatile u32 *)0x04000000 &= ~0x80000000;
    return func_02003650(&data_021521b4);
}

/* Release sub OBJ banks and return their previous mask (bits 0-8).
 * Evidence: GX_DisableBankForSubOBJ in pret/pokediamond GX_vramcnt.c
 * and the original allocation slot address.
 */
u32 func_02003818(void)
{
    return func_02003650(&data_021521b8);
}

/* Disable sub BG extended palettes before releasing their banks; return the
 * old mask. Evidence: GX_DisableBankForSubBGExtPltt in pret/pokediamond
 * GX_vramcnt.c and the original sub DISPCNT bit 30 clear / slot address.
 */
u32 func_0200382c(void)
{
    *(volatile u32 *)0x04001000 &= ~0x40000000;
    return func_02003650(&data_021521ba);
}

/* Disable sub OBJ extended palettes before releasing their banks; return the
 * old mask. Evidence: GX_DisableBankForSubOBJExtPltt in pret/pokediamond
 * GX_vramcnt.c and the original sub DISPCNT bit 31 clear / slot address.
 */
u32 func_02003854(void)
{
    *(volatile u32 *)0x04001000 &= ~0x80000000;
    return func_02003650(&data_021521bc);
}

/* Return borrowed main BG0 screen memory selected by the live registers.
 * Evidence: G2_GetBG0ScrPtr in pret/pokediamond GX_bgcnt.c; BG0CNT selects
 * 2 KiB blocks and DISPCNT adds the shared 64 KiB screen-base offset.
 */
void *func_0200391c(void)
{
    u32 offset = ((*(volatile u16 *)0x04000008 & 0x1f00) >> 8) << 11;
    return (void *)(0x06000000 +
        (((*(volatile u32 *)0x04000000 & 0x38000000) >> 27) << 16) + offset);
}

/* Return borrowed sub BG0 screen memory in 2 KiB blocks; no allocation occurs.
 * Evidence: G2S_GetBG0ScrPtr in pret/pokediamond GX_bgcnt.c and the original
 * sub BG0CNT register address and screen-base mask.
 */
void *func_02003950(void)
{
    return (void *)(0x06200000 +
        (((*(volatile u16 *)0x04001008 & 0x1f00) >> 8) << 11));
}

/* Return borrowed main BG1 screen memory selected by the live registers.
 * Evidence: G2_GetBG1ScrPtr in pret/pokediamond GX_bgcnt.c; BG1CNT selects
 * 2 KiB blocks and DISPCNT adds the shared 64 KiB screen-base offset.
 */
void *func_02003970(void)
{
    u32 offset = ((*(volatile u16 *)0x0400000a & 0x1f00) >> 8) << 11;
    return (void *)(0x06000000 +
        (((*(volatile u32 *)0x04000000 & 0x38000000) >> 27) << 16) + offset);
}
