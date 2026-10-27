#ifndef SDK_02003BB4_H
#define SDK_02003BB4_H

#include "types.h"

/* Signed 20.12 fixed-point value used by the NitroSDK GX affine helpers. */
typedef s32 fx32;
/* Signed 4.12 fixed-point value; the SDK stores matrix elements as fx32 but
 * converts their fractional part through fx16 when writing hardware regs. */
typedef s16 fx16;

/* Column-major 2x2 matrix of signed 20.12 values, as used by G2x affine
 * helpers. The array order follows NitroSDK's `MtxFx22` layout. */
typedef struct Mtx22 {
    fx32 _[4];
} Mtx22;

/* Main BG0 character-data base. Adds DISPCNT bits 24-26 (64 KiB character-base
 * offset) and BG0CNT bits 2-5 (16 KiB character block) to 0x06000000.
 * Evidence: G2_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003bb4(void);

/* Sub BG0 character-data base. Adds sub BG0CNT bits 2-5 (16 KiB block) to
 * 0x06200000. Evidence: G2S_GetBG0CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003be8(void);

/* Main BG1 character-data base. Same rule as BG0 but reads BG1CNT.
 * Evidence: G2_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003c08(void);

/* Sub BG1 character-data base. Adds sub BG1CNT bits 2-5 (16 KiB block) to
 * 0x06200000. Evidence: G2S_GetBG1CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003c3c(void);

/* Main BG2 character-data base, or null for display modes 5-7 when BG2CNT bit 7
 * is set. Evidence: G2_GetBG2CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003c5c(void);

/* Sub BG2 character-data base, or null for display modes 5-7 when sub BG2CNT
 * bit 7 is set. Evidence: G2S_GetBG2CharPtr in pret/pokediamond GX_bgcnt.c. */
void *func_02003cac(void);

/* Main BG3 character-data base, or null when BG3 is unavailable (mode >= 6, or
 * modes 3-5 with BG3CNT bit 7 set). Evidence: G2_GetBG3CharPtr in
 * pret/pokediamond GX_bgcnt.c. */
void *func_02003cec(void);

/* Sub BG3 character-data base, or null when sub BG3 is unavailable (mode >= 6,
 * or modes 3-5 with sub BG3CNT bit 7 set). Evidence: G2S_GetBG3CharPtr in
 * pret/pokediamond GX_bgcnt.c. */
void *func_02003d44(void);

/* Write the four 32-bit BGx affine registers at `ptr` from a 2x2 signed 20.12
 * matrix and a reference point. `centerX`/`centerY` are the rotation centre;
 * `x1`/`y1` are the reference point in 20.12. The matrix's PA/PB and PC/PD
 * elements are truncated to signed 4.12 halves, then the displacement terms are
 * scaled by the reference-point offset from the centre. `ptr` must be a writable
 * hardware register address. Evidence: G2x_SetBGyAffine_ in pret/pokediamond
 * arm9/lib/NitroSDK/src/GX_g2.c (same size and instruction sequence). */
void func_02003d8c(u32 ptr, const struct Mtx22 *mtx, fx32 centerX,
                   fx32 centerY, fx32 x1, fx32 y1);

#endif
