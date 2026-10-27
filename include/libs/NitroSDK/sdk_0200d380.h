#ifndef SDK_0200D380_H
#define SDK_0200D380_H
#include "types.h"
/** Caller-owned raw touch sample; coordinates use the panel's 12-bit range. */
typedef struct {
    u16 x, y, touch, validity;
} TPData;
/** Caller-owned Q2 origins and Q8 raw units per display pixel. */
typedef struct {
    s16 x0, y0, xDotSize, yDotSize;
} TPCalibrateParam;
/** Initialize the shared touch state once and wait for the ARM7 FIFO callback. Caller retains
 * input/output storage. */
void func_0200d380(void);
/** Read firmware calibration; clear unusable parameters and always return true. Caller retains
 * input/output storage. */
s32 func_0200d3f8(TPCalibrateParam* calibrate);
/** Install Q2 origins and Q8 scales atomically; NULL disables calibration. Caller retains
 * input/output storage. */
void func_0200d48c(const TPCalibrateParam* param);
/** Request one ARM7 sample; report FIFO failure through the registered callback. Caller retains
 * input/output storage. */
void func_0200d5b4(void);
/** Wait for sampling and copy the raw sample; return one on sampling error. Caller retains
 * input/output storage. */
u32 func_0200d648(TPData* result);
/** Derive calibration from two points; return one for invalid ranges or coincident axes. Caller
 * retains input/output storage. */
u32 func_0200d698(TPCalibrateParam* calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2,
    u16 raw_y2, u16 dx2, u16 dy2);
/** Convert raw coordinates using installed calibration and clamp to the display bounds. Caller
 * retains input/output storage. */
void func_0200d884(TPData* disp, const TPData* raw);
/** Spin until the selected asynchronous command bits clear; IRQ delivery must remain enabled.
 * Caller retains input/output storage. */
void func_0200d9a8(u32 command_flgs);
#endif
