/* Matched functions at 0x02053c08-0x02053fd0: touch-sample record accessors and
 * a rectangle hit test built on the touch-panel and GX providers. The delink
 * still supplies the rest of the SDK; see
 * docs/functions/libs-nitrosdk-sdk-02053c08.md. */
#include "libs/NitroSDK/sdk_02053c08.h"

/* Five 14-byte records; func_02053c98 returns a borrowed entry and
 * func_02053c08 clears the whole table. */
extern Unk02053c08Entry data_021607c4[5];

/* Touch-panel provider routines (0x0200d380-0x0200d884), named by the public
 * NitroSDK tp.c API: TP_Init, TP_GetUserInfo, TP_SetCalibrateParam,
 * TP_RequestSamplingAsync, TP_WaitRawResult and TP_GetCalibratedPoint. */
extern void func_0200d380(void);
extern int func_0200d3f8(s16 *info);
extern void func_0200d48c(s16 *info);
extern void func_0200d5b4(void);
extern int func_0200d648(u16 *raw);
extern void func_0200d884(u16 *point, u16 *raw);

/* Integer-distance helper used by func_02053f68: writes dx*dx + dy*dy to the
 * SQRT unit and returns its integer square root. */
extern int func_020500bc(const void *a, const void *b);

/* Renderer readiness and the ordered GX rectangle submission used when
 * func_02053e44 is asked to draw. */
extern int func_020523a8(void);
extern void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
extern void func_02057e18(u32 value);
extern void func_02057e30(u32 value);
extern void func_02057b50(s32 x, s32 y, s32 width, s32 height, s32 mode);
extern void func_02057df8(void);

/* Initializes the touch provider, clears the five 14-byte records and installs
 * the calibration data. Evidence: the TP_Init call, the TP_GetUserInfo success
 * gate, the 5x14-byte store loop and TP_SetCalibrateParam at
 * 0x02053c14..0x02053c84. The provider returns 0 when calibration is missing. */
int func_02053c08(void)
{
    s16 info[4];
    u8 *p = (u8 *)data_021607c4;
    int i;

    func_0200d380();
    if (func_0200d3f8(info) == 0) {
        return 0;
    }
    /* The original clears each record with fourteen byte stores; mwccarm only
     * produces that shape for explicit stores, not for a byte loop. */
    for (i = 0; i < 5; i++) {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        p[8] = 0;
        p[9] = 0;
        p[10] = 0;
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
        p += 14;
    }
    func_0200d48c(info);
    return 1;
}

/* Returns a borrowed pointer to one record. Evidence: the `mla r0, r1, r0, r2`
 * with r1 = 14 at 0x02053c9c, so the table stride is fourteen bytes. */
Unk02053c08Entry *func_02053c98(int index)
{
    return &data_021607c4[index];
}

/* Retries the asynchronous sampling request until TP_WaitRawResult reports a
 * sample, converts it, then shifts the record: previousTouch/previousX/
 * previousY keep the old touch/x/y. A raw validity of TP_VALIDITY_VALID (0)
 * publishes the new touch flag and calibrated x/y; any other validity clears
 * the current fields. Evidence: the request/wait loop at
 * 0x02053cbc..0x02053ccc, TP_GetCalibratedPoint at 0x02053cd8 and the
 * conditional halfword moves at 0x02053cdc..0x02053d30. */
void func_02053cac(void)
{
    u16 raw[4];
    u16 point[4];
    Unk02053c08Entry *entry = &data_021607c4[0];

    do {
        func_0200d5b4();
    } while (func_0200d648(raw) != 0);
    func_0200d884(point, raw);

    entry->previousTouch = entry->touch;
    entry->previousX = entry->x;
    entry->previousY = entry->y;
    if (raw[3] == 0) {
        entry->touch = point[2];
        entry->x = point[0];
        entry->y = point[1];
        return;
    }
    entry->touch = 0;
    entry->x = 0;
    entry->y = 0;
}

/* Returns 1 while touch is nonzero and copies x/y to the two optional outputs;
 * a non-touched record clears both outputs and returns 0. Evidence: the
 * ldrh/cmp around data_021607c4 and the paired conditional stores at
 * 0x02053d3c..0x02053d84. */
int func_02053d38(u16 *x, u16 *y)
{
    Unk02053c08Entry *entry = &data_021607c4[0];

    if (entry->touch != 0) {
        if (x != 0) {
            *x = entry->x;
        }
        if (y != 0) {
            *y = entry->y;
        }
        return 1;
    }
    if (x != 0) {
        *x = 0;
    }
    if (y != 0) {
        *y = 0;
    }
    return 0;
}

/* Same outputs as func_02053d38, but only for a touch-down edge: touch == 1
 * and previousTouch == 0. Evidence: the conditional `ldrheq`/`cmpeq` pair at
 * 0x02053d90..0x02053d98 and the same store sequence as func_02053d38. */
int func_02053d8c(u16 *x, u16 *y)
{
    Unk02053c08Entry *entry = &data_021607c4[0];

    if (entry->touch == 1 && entry->previousTouch == 0) {
        if (x != 0) {
            *x = entry->x;
        }
        if (y != 0) {
            *y = entry->y;
        }
        return 1;
    }
    if (x != 0) {
        *x = 0;
    }
    if (y != 0) {
        *y = 0;
    }
    return 0;
}

/* Same shape as func_02053d8c for a touch-up edge (touch == 0 and
 * previousTouch == 1), reporting the last touched coordinates previousX/
 * previousY. Evidence: the compare pair at 0x02053dec..0x02053df4 and the
 * offsets at 0x02053df8/0x02053e00. */
int func_02053de8(u16 *x, u16 *y)
{
    Unk02053c08Entry *entry = &data_021607c4[0];

    if (entry->touch == 0 && entry->previousTouch == 1) {
        if (x != 0) {
            *x = entry->previousX;
        }
        if (y != 0) {
            *y = entry->previousY;
        }
        return 1;
    }
    if (x != 0) {
        *x = 0;
    }
    if (y != 0) {
        *y = 0;
    }
    return 0;
}

/* Draws the rectangle when requested and the renderer is ready, then hit-tests
 * the selected touch edge against x/y/width/height. `kind` must be 0, 1 or 2
 * (0 = func_02053d38, 1 = func_02053d8c, 2 = func_02053de8); other values are
 * outside the contract and leave the original's hit flag in caller-saved r4.
 * The bounds comparisons are half-open, so the right and bottom edges are
 * exclusive. Returns 1 only on a supported `kind` whose point exists and lies
 * inside the rectangle, 0 otherwise.
 * Evidence: the renderer guard at 0x02053e60..0x02053e70, the ordered GX calls
 * at 0x02053e74..0x02053ec4 and the comparison chain at 0x02053f24..0x02053f64. */
int func_02053e44(s32 x, s32 y, s32 width, s32 height, int kind, int draw)
{
    u16 pointX;
    u16 pointY;
    /* Deliberately uninitialized. `kind` is contractually 0-2; for any other
     * value the original branches straight to the hit test with caller-saved
     * r4 holding whatever the callers left there, and this indeterminate
     * local reproduces that. Initializing it would change the emitted code. */
    int hit;

    if (draw == 1 && func_020523a8() == 1) {
        /* Only the call order and argument values are evidenced at
         * 0x02053e6c..0x02053ebc; their meanings are not established by a
         * public source. The first call gets 0xff000000 in all four argument
         * registers, func_02057e18 gets 16 before and 31 after the rectangle,
         * func_02057e30 gets 10 and 0, and func_02057b50 gets the rectangle
         * plus 21 as its mode argument. Reproduce them verbatim. */
        func_02057dcc(0xff000000, 0xff000000, 0xff000000, 0xff000000);
        func_02057e18(16);
        func_02057e30(10);
        func_02057b50(x, y, width, height, 21);
        func_02057e30(0);
        func_02057e18(31);
        func_02057df8();
    }
    if (kind == 0) {
        hit = func_02053d38(&pointX, &pointY);
    } else if (kind == 1) {
        hit = func_02053d8c(&pointX, &pointY);
    } else if (kind == 2) {
        hit = func_02053de8(&pointX, &pointY);
    }
    if (hit != 0 && pointX >= x && pointX < x + width &&
        pointY >= y && pointY < y + height) {
        return 1;
    }
    return 0;
}

/* Returns 1 when a current touch point exists and its integer distance from
 * (x, y) is at least `distance`; otherwise returns 0. func_020500bc returns the
 * integer square root of dx*dx + dy*dy, so the threshold is a distance in pixel
 * units, not a squared value. Evidence: the local pair stores at
 * 0x02053f90..0x02053fac, func_020500bc at 0x02053fb0 and the `cmp r0, r4`
 * return at 0x02053fb4..0x02053fc0. */
int func_02053f68(s32 x, s32 y, s32 distance)
{
    u16 pointX;
    u16 pointY;
    s32 point[2];
    s32 target[2];

    if (func_02053d38(&pointX, &pointY) != 0) {
        point[0] = pointX;
        point[1] = pointY;
        target[0] = x;
        target[1] = y;
        if (func_020500bc(point, target) >= distance) {
            return 1;
        }
    }
    return 0;
}
