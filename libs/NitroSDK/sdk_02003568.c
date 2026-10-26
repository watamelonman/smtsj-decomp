#include "types.h"

/* VRAM bank helpers return the previous bank mask; the u16 slot is cleared.
 * Evidence: original helpers at 02003534 and 02003650, and pret/pokediamond
 * arm9/lib/NitroSDK/src/GX_vramcnt.c (resetBankForX_/disableBankForX_).
 */
extern u32 func_02003534(u16 *bank);
extern u32 func_02003650(u16 *bank);

extern u16 data_021521b2;
extern u16 data_021521b4;
extern u16 data_021521ac;
extern u16 data_021521ae;
extern u16 data_021521b6;
extern u16 data_021521b8;
extern u16 data_021521a6;
extern u16 data_021521a8;

/* Reset the BGExtPltt VRAM banks and return the previous mask.
 * Evidence: GX_ResetBankForBGExtPltt in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521b2. Clears the
 * main display palette-enable bit before moving the banks to LCDC.
 */
u32 func_02003568(void)
{
    *(volatile u32 *)0x04000000 &= ~0x40000000U;
    return func_02003534(&data_021521b2);
}

/* Reset the OBJExtPltt VRAM banks and return the previous mask.
 * Evidence: GX_ResetBankForOBJExtPltt in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521b4. Clears the
 * main display palette-enable bit before moving the banks to LCDC.
 */
u32 func_0200358c(void)
{
    *(volatile u32 *)0x04000000 &= ~0x80000000U;
    return func_02003534(&data_021521b4);
}

/* Reset the Tex VRAM banks and return the previous mask.
 * Evidence: GX_ResetBankForTex in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521ac.
 */
u32 func_020035b0(void)
{
    return func_02003534(&data_021521ac);
}

/* Reset the TexPltt VRAM banks and return the previous mask.
 * Evidence: GX_ResetBankForTexPltt in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521ae.
 */
u32 func_020035c4(void)
{
    return func_02003534(&data_021521ae);
}

/* Reset the SubBG VRAM banks and return the previous mask.
 * Evidence: GX_ResetBankForSubBG in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521b6.
 */
u32 func_020035d8(void)
{
    return func_02003534(&data_021521b6);
}

/* Reset the SubOBJ VRAM banks and return the previous mask.
 * Evidence: GX_ResetBankForSubOBJ in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521b8.
 */
u32 func_020035ec(void)
{
    return func_02003534(&data_021521b8);
}

/* Disable the BG VRAM banks and return the previous mask.
 * Evidence: GX_DisableBankForBG in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521a6.
 */
u32 func_02003730(void)
{
    return func_02003650(&data_021521a6);
}

/* Disable the OBJ VRAM banks and return the previous mask.
 * Evidence: GX_DisableBankForOBJ in pret/pokediamond GX_vramcnt.c;
 * original literal selects the u16 bank slot at 021521a8.
 */
u32 func_02003744(void)
{
    return func_02003650(&data_021521a8);
}
