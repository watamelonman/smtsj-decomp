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
