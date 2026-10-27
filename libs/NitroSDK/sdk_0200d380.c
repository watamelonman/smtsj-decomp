#include "libs/NitroSDK/sdk_0200d380.h"
typedef s32 BOOL;
typedef s32 OSIntrMode;
typedef u32 TPRequestCommandFlag;
typedef struct {
    s32 x0, xDotSize, xDotSizeInv, y0, yDotSize, yDotSizeInv;
} TPiCalibrateParam;
typedef struct {
    u16 initial;
    u16 padding;
    void (*callback)(u32 command, u32 result, u32 index);
    TPData buf;
    u16 index, frequence;
    TPData* samplingBufs;
    u16 bufSize, pad;
    TPiCalibrateParam calibrate;
    u16 calibrate_flg;
    volatile u16 state, err_flg, command_flg;
} TPState;
extern TPState data_02154290;
/* The existing symbol at state +0x1c preserves the converter relocation. */
extern TPiCalibrateParam data_021542ac;
extern void func_0200a324(void);
extern s32 func_0200a47c(u32 tag, u32 processor);
extern void func_0200a430(u32 tag, void (*callback)(u32, u32, s32));
extern s32 func_0200a4a0(u32 tag, u32 data, u32 error);
extern void func_0200d100(u32 tag, u32 data, s32 error);
extern s32 func_02007a58(void);
extern s32 func_02007a6c(s32 state);
#define tpState data_02154290
#define TRUE 1
#define FALSE 0
#define NULL 0
#define TP_STATE_READY 0
#define PXI_FIFO_TAG_TOUCHPANEL 6
#define PXI_PROC_ARM7 1
#define TP_REQUEST_COMMAND_FLAG_SAMPLING 1
#define TP_REQUEST_COMMAND_SAMPLING 0
#define TP_RESULT_PXI_BUSY 4
#define TP_RAW_MAX 4096
#define GX_LCD_SIZE_X 256
#define GX_LCD_SIZE_Y 192
#define TP_CALIBRATE_DOT_SCALE_SHIFT 8
#define TP_CALIBRATE_ORIGIN_SCALE_SHIFT 2
#define TP_CALIBRATE_DOT_INV_SCALE_SHIFT 20
static inline void CP_SetDiv32_32(u32 n, u32 d)
{
    *(volatile u16*)0x04000280 = 0;
    *(volatile u32*)0x04000290 = n;
    /* SDK writes the full zero-extended denominator as one 64-bit access. */
    *(u64*)0x04000298 = d;
}
static inline s32 CP_GetDivResult32(void)
{
    while (*(volatile u16*)0x04000280 & 0x8000) { }
    return *(volatile s32*)0x040002a0;
}
static inline BOOL TPi_SamplingNow(void)
{
    if (func_0200a4a0(6, 0x3000000, 0) < 0)
        return FALSE;
    return TRUE;
}
static inline void TPi_ErrorAtPxi(u32 command)
{
    tpState.err_flg |= 1 << command;
    if (tpState.callback)
        tpState.callback(command, 4, 0);
}
typedef struct {
    u8 pad[88];
    u16 raw_x1, raw_y1;
    u8 dx1, dy1;
    u16 raw_x2, raw_y2;
    u8 dx2, dy2;
} TPUserInfo;
/** TP_Init in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Initialize the shared touch state once and wait for the ARM7 FIFO callback. */
void func_0200d380(void)
{

    if (tpState.initial) {
        return;
    }

    tpState.initial = TRUE;

    func_0200a324();

    tpState.index = 0;
    tpState.callback = NULL;
    tpState.samplingBufs = NULL;
    tpState.state = TP_STATE_READY;
    tpState.calibrate_flg = FALSE;
    tpState.command_flg = 0;
    tpState.err_flg = 0;

    while (!func_0200a47c(PXI_FIFO_TAG_TOUCHPANEL, PXI_PROC_ARM7)) { }

    func_0200a430(PXI_FIFO_TAG_TOUCHPANEL, func_0200d100);
}

/** TP_GetUserInfo in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Read firmware calibration; clear unusable parameters and always return true. */
BOOL func_0200d3f8(TPCalibrateParam* calibrate)
{
    const TPUserInfo* info = (const TPUserInfo*)0x27ffc80;

    u16 x1, y1, x2, y2, dx1, dy1, dx2, dy2;

    x1 = info->raw_x1;
    y1 = info->raw_y1;
    dx1 = (u16)(info->dx1);
    dy1 = (u16)(info->dy1);
    x2 = info->raw_x2;
    y2 = info->raw_y2;
    dx2 = (u16)(info->dx2);
    dy2 = (u16)(info->dy2);

    if ((x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
        || (func_0200d698(calibrate, x1, y1, dx1, dy1, x2, y2, dx2, dy2) != 0)) {
        calibrate->x0 = 0;
        calibrate->y0 = 0;
        calibrate->xDotSize = 0;
        calibrate->yDotSize = 0;

        return TRUE;
    }

    return TRUE;
}

/** TP_SetCalibrateParam in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Install Q2 origins and Q8 scales atomically; NULL disables calibration. */
void func_0200d48c(const TPCalibrateParam* param)
{
    OSIntrMode enabled;

    if (param == NULL) {
        tpState.calibrate_flg = FALSE;
        return;
    }

    enabled = func_02007a58();

    if (param->xDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32)param->xDotSize);

        tpState.calibrate.x0 = param->x0;
        tpState.calibrate.xDotSize = param->xDotSize;
        tpState.calibrate.xDotSizeInv = (s32)CP_GetDivResult32();
    } else {
        tpState.calibrate.x0 = 0;
        tpState.calibrate.xDotSize = 0;
        tpState.calibrate.xDotSizeInv = 0;
    }

    if (param->yDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32)param->yDotSize);

        tpState.calibrate.y0 = param->y0;
        tpState.calibrate.yDotSize = param->yDotSize;
        tpState.calibrate.yDotSizeInv = (s32)CP_GetDivResult32();
    } else {
        tpState.calibrate.y0 = 0;
        tpState.calibrate.yDotSize = 0;
        tpState.calibrate.yDotSizeInv = 0;
    }

    (void)func_02007a6c(enabled);

    tpState.calibrate_flg = TRUE;
}

/** TP_RequestSamplingAsync in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Request one ARM7 sample; report FIFO failure through the registered callback. */
void func_0200d5b4(void)
{
    OSIntrMode enabled;

    enabled = func_02007a58();

    if (TPi_SamplingNow() == FALSE) {

        (void)func_02007a6c(enabled);
        TPi_ErrorAtPxi(TP_REQUEST_COMMAND_SAMPLING);
        return;
    }

    tpState.command_flg |= TP_REQUEST_COMMAND_FLAG_SAMPLING;
    tpState.err_flg &= ~TP_REQUEST_COMMAND_FLAG_SAMPLING;

    (void)func_02007a6c(enabled);
}

/** TP_WaitRawResult in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Wait for sampling and copy the raw sample; return one on sampling error. */
u32 func_0200d648(TPData* result)
{

    func_0200d9a8(TP_REQUEST_COMMAND_FLAG_SAMPLING);

    if (tpState.err_flg & TP_REQUEST_COMMAND_FLAG_SAMPLING) {
        return 1;
    }

    *result = tpState.buf;
    return 0;
}

/** TP_CalcCalibrateParam in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Derive calibration from two points; return one for invalid ranges or coincident axes. */
u32 func_0200d698(TPCalibrateParam* calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2, u16 dx2, u16 dy2)
{
    s32 rx_width, dx_width, ry_width, dy_width;
    s32 tmp32;
    OSIntrMode enabled;

#define IN_S16_RANGE(x) ((x) < 0x8000 && (x) >= -0x8000)

    if (raw_x1 >= TP_RAW_MAX || raw_y1 >= TP_RAW_MAX || raw_x2 >= TP_RAW_MAX
        || raw_y2 >= TP_RAW_MAX) {
        return 1;
    }
    if (dx1 >= GX_LCD_SIZE_X || dx2 >= GX_LCD_SIZE_X || dy1 >= GX_LCD_SIZE_Y
        || dy2 >= GX_LCD_SIZE_Y) {
        return 1;
    }
    if (dx1 == dx2 || dy1 == dy2 || raw_x1 == raw_x2 || raw_y1 == raw_y2) {
        return 1;
    }

    rx_width = raw_x1 - raw_x2;
    dx_width = dx1 - dx2;

    enabled = func_02007a58();

    CP_SetDiv32_32(((u32)rx_width) << TP_CALIBRATE_DOT_SCALE_SHIFT, (u32)dx_width);

    ry_width = raw_y1 - raw_y2;
    dy_width = dy1 - dy2;

    tmp32 = CP_GetDivResult32();
    CP_SetDiv32_32(((u32)ry_width) << TP_CALIBRATE_DOT_SCALE_SHIFT, (u32)dy_width);

    if (!IN_S16_RANGE(tmp32)) {
        (void)func_02007a6c(enabled);
        return 1;
    }
    calibrate->xDotSize = (s16)tmp32;
    tmp32 = (s16)((((s32)(raw_x1 + raw_x2) << TP_CALIBRATE_DOT_SCALE_SHIFT)
                      - ((s32)(dx1 + dx2) * calibrate->xDotSize))
        >> (TP_CALIBRATE_DOT_SCALE_SHIFT - TP_CALIBRATE_ORIGIN_SCALE_SHIFT + 1));
    if (!IN_S16_RANGE(tmp32)) {
        (void)func_02007a6c(enabled);
        return 1;
    }
    calibrate->x0 = (s16)tmp32;

    tmp32 = CP_GetDivResult32();
    (void)func_02007a6c(enabled);

    if (!IN_S16_RANGE(tmp32)) {
        return 1;
    }

    calibrate->yDotSize = (s16)tmp32;
    tmp32 = (s16)((((s32)(raw_y1 + raw_y2) << TP_CALIBRATE_DOT_SCALE_SHIFT)
                      - ((s32)(dy1 + dy2) * calibrate->yDotSize))
        >> (TP_CALIBRATE_DOT_SCALE_SHIFT - TP_CALIBRATE_ORIGIN_SCALE_SHIFT + 1));
    if (!IN_S16_RANGE(tmp32)) {
        return 1;
    }

    calibrate->y0 = (s16)tmp32;

    return 0;
}

/** TP_GetCalibratedPoint in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Convert raw coordinates using installed calibration and clamp to the display bounds. */
void func_0200d884(TPData* disp, const TPData* raw)
{
    TPiCalibrateParam* cal;

    enum { MAX_X = GX_LCD_SIZE_X - 1, MAX_Y = GX_LCD_SIZE_Y - 1 };

    if (!tpState.calibrate_flg) {
        *disp = *raw;
        return;
    }

    cal = &data_021542ac;

    disp->touch = raw->touch;
    disp->validity = raw->validity;

    if (raw->touch == 0) {
        disp->x = 0;
        disp->y = 0;
        return;
    }

    disp->x
        = (u16)((((u64)(raw->x << TP_CALIBRATE_ORIGIN_SCALE_SHIFT) - cal->x0) * cal->xDotSizeInv)
            >> (TP_CALIBRATE_DOT_INV_SCALE_SHIFT + TP_CALIBRATE_ORIGIN_SCALE_SHIFT));

    if ((s16)disp->x < 0) {
        disp->x = 0;
    } else if ((s16)disp->x > MAX_X) {
        disp->x = MAX_X;
    }

    disp->y
        = (u16)((((u64)(raw->y << TP_CALIBRATE_ORIGIN_SCALE_SHIFT) - cal->y0) * cal->yDotSizeInv)
            >> (TP_CALIBRATE_DOT_INV_SCALE_SHIFT + TP_CALIBRATE_ORIGIN_SCALE_SHIFT));

    if ((s16)disp->y < 0) {
        disp->y = 0;
    } else if ((s16)disp->y > MAX_Y) {
        disp->y = MAX_Y;
    }
}

/** TP_WaitBusy in NitroSDK libraries/spi/src/tp.c (source linked in the function doc).
 * Spin until the selected asynchronous command bits clear; IRQ delivery must remain enabled. */
void func_0200d9a8(TPRequestCommandFlag command_flgs)
{

    while (tpState.command_flg & command_flgs) { }

    return;
}
