#include "types.h"

/* VRAM bank helpers return the previous bank mask; the u16 slot is cleared.
 * Evidence: original helpers at 02003534 and 02003650, and pret/pokediamond
 * arm9/lib/NitroSDK/src/GX_vramcnt.c (resetBankForX_/disableBankForX_).
 */
extern u32 func_02003534(u16 *bank);
extern u32 func_02003650(u16 *bank);

/* Release the selected VRAM banks using the SDK lock owner ID.
 * Evidence: OSi_UnlockVram in pret/pokediamond GX_vramcnt.c.
 */
extern void func_02007d3c(u16 bankMask, u16 lockId);
extern u16 data_021521a2;
extern u16 data_021521ba;
extern u16 data_021521bc;

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

/* Reset sub-display BG extended palettes and return the previous bank mask.
 * Evidence: GX_ResetBankForSubBGExtPltt in pret/pokediamond GX_vramcnt.c;
 * original DISPCNT address and allocation slot identify the sub display.
 */
u32 func_02003600(void)
{
    *(volatile u32 *)0x04001000 &= ~0x40000000U;
    return func_02003534(&data_021521ba);
}

/* Reset sub-display OBJ extended palettes and return the previous bank mask.
 * Evidence: GX_ResetBankForSubOBJExtPltt in pret/pokediamond GX_vramcnt.c;
 * original DISPCNT bit 31 and slot 021521bc select OBJ extended palettes.
 */
u32 func_02003628(void)
{
    *(volatile u32 *)0x04001000 &= ~0x80000000U;
    return func_02003534(&data_021521bc);
}

/* Clear the borrowed allocation slot, disable its banks, and release their lock.
 * Returns the previous mask. Evidence: disableBankForX_ in pret/pokediamond
 * GX_vramcnt.c; original byte stores select banks A-I (skipping WRAMCNT).
 */
u32 func_02003650(u16 *bank)
{
    u32 mask = *bank;
    *bank = 0;
    if (mask & (1U << 0))
        *(volatile u8 *)0x04000240 = 0;
    if (mask & (1U << 1))
        *(volatile u8 *)0x04000241 = 0;
    if (mask & (1U << 2))
        *(volatile u8 *)0x04000242 = 0;
    if (mask & (1U << 3))
        *(volatile u8 *)0x04000243 = 0;
    if (mask & (1U << 4))
        *(volatile u8 *)0x04000244 = 0;
    if (mask & (1U << 5))
        *(volatile u8 *)0x04000245 = 0;
    if (mask & (1U << 6))
        *(volatile u8 *)0x04000246 = 0;
    if (mask & (1U << 7))
        *(volatile u8 *)0x04000248 = 0;
    if (mask & (1U << 8))
        *(volatile u8 *)0x04000249 = 0;
    func_02007d3c((u16)mask, data_021521a2);
    return mask;
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

/* Disable main-display BG extended palettes and return the previous bank mask.
 * Evidence: GX_DisableBankForBGExtPltt in pret/pokediamond GX_vramcnt.c;
 * DISPCNT bit 30 is cleared before disabling the banks in slot 021521b2.
 */
u32 func_02003758(void)
{
    *(volatile u32 *)0x04000000 &= ~0x40000000U;
    return func_02003650(&data_021521b2);
}
