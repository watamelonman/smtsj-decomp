#ifndef SDK_020026A0_H
#define SDK_020026A0_H

#include "types.h"

/* The two display globals that sit immediately before gGXState. The lock ID is
 * volatile because the hardware-lock loop polls it after every assignment.
 * Evidence: `sDispMode` and `GXi_VRamLockId` in pret/pokediamond GX.c; the
 * delinked load at 0x020027d4 is data_021521a0 and reads +2 as a halfword. */
typedef struct GXDispState {
    u16 dispMode;
    volatile u16 vramLockId;
} GXDispState;

/* Borrowed view of the NitroSDK GX state record (gGXState). Only the thirteen
 * halfword fields cleared by GX_InitGXState are named; the original struct has
 * more state after them. Evidence: pret/pokediamond GX_state.c. */
typedef struct GXState {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GXState;

/* Empty entry kept for address-table parity; the original body is bx lr. */
void func_020026a0(void);

/* Initialize the main 2D engine and acquire the GX VRAM lock (GX_Init). */
void func_020026a4(void);

/* Set or clear the main-engine V-blank IRQ enable and return its old value. */
u32 func_020027f0(u32 enable);

/* Save the main display mode and turn the display off (GX_DispOff). */
void func_02002824(void);

/* Restore the mode saved by func_02002824 and turn the display on (GX_DispOn). */
void func_02002860(void);

/* Rebuild DISPCNT from a display mode, BG mode and BG0 2D/3D selection
 * (GX_SetGraphicsMode). */
void func_020028a8(u32 dispMode, u32 bgMode, u32 bg0_2d3d);

/* Replace the sub-engine BG mode in DISPCNT_SUB (GXS_SetGraphicsMode). */
void func_02002910(u32 value);

/* Encode a signed master-brightness value into a 16-bit register word. */
void func_0200292c(volatile u16 *dst, s32 brightness);

/* Decode a master-brightness word; unknown encodings read as 0. */
s32 func_02002954(const volatile u16 *dst);

/* Clear gGXState and the VRAM bank control registers (GX_InitGXState). */
void func_02002998(void);

#endif
