#ifndef SDK_02053C08_H
#define SDK_02053C08_H

#include "types.h"

/* Borrowed view of one 14-byte touch record in data_021607c4. The field roles
 * follow the public NitroSDK TPData layout (touch/x/y at +0/+2/+4) and the
 * stores at 0x02053cdc..0x02053d30: the sample is shifted into the previous
 * half of the record before the current fields are replaced. pad_0c is
 * alignment and is never accessed. */
typedef struct Unk02053c08Entry {
    u16 touch;
    u16 previousTouch;
    u16 x;
    u16 y;
    u16 previousX;
    u16 previousY;
    u16 pad_0c;
} Unk02053c08Entry;

/* Returns the borrowed record at `index` in the five-entry table. The caller
 * must keep the index in range; the original has no bounds check. */
Unk02053c08Entry *func_02053c98(int index);

/* Initializes the touch provider (TP_Init), obtains the user calibration
 * (TP_GetUserInfo), clears the five records and installs that calibration
 * (TP_SetCalibrateParam). Returns 0 when the calibration is unavailable. */
int func_02053c08(void);

/* Samples the touch panel until TP_WaitRawResult succeeds, converts the sample
 * with TP_GetCalibratedPoint, then shifts touch/x/y into the first record and
 * keeps the previous values. An invalid raw sample clears the current fields. */
void func_02053cac(void);

/* Returns 1 while the current record is touched and copies its calibrated x/y
 * to the two optional outputs; otherwise clears both outputs and returns 0. */
int func_02053d38(u16 *x, u16 *y);

/* Reports a touch-down edge: returns 1 only while the record is touched and
 * was not touched by the previous sample, with the current x/y. */
int func_02053d8c(u16 *x, u16 *y);

/* Reports a touch-up edge: returns 1 only while the record is not touched but
 * the previous sample was, with the previous x/y. */
int func_02053de8(u16 *x, u16 *y);

/* Hit-tests the selected touch edge against the half-open rectangle
 * x/y/width/height. `kind` selects 0 = current touch, 1 = touch-down edge,
 * 2 = touch-up edge. When `draw` is one and the renderer is ready, the
 * rectangle is also submitted through the GX helpers. */
int func_02053e44(s32 x, s32 y, s32 width, s32 height, int kind, int draw);

/* Returns 1 when the current touch point is at least `distanceSquared` from
 * (x, y). The provider returns dx*dx + dy*dy, so the threshold is squared. */
int func_02053f68(s32 x, s32 y, s32 distanceSquared);

#endif
