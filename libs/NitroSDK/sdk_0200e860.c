#include "types.h"

/* RTCWork layout follows NitroSDK libraries/rtc/src/external.c; SDK owns it. */
typedef struct {
    u16 initialized;
    u8 reserved[10];
    volatile u32 lock;
    void (*callback)(s32, void *);
    void *buffer[2];
    void *callbackArg;
    u32 sequence;
    u32 index;
    void (*interrupt)(void);
    s32 commonResult;
} RTCState;
/* Caller-owned date output, with calendar fields in SDK units. */
typedef struct { u32 year, month, day, week; } RTCDate;
extern RTCState data_021542f8;
extern void func_0200a324(void);
extern s32 func_0200a47c(u32 tag, u32 processor);
extern void func_0200a430(u32 tag, void (*callback)(u32, u32, s32));
extern s32 func_0200a4a0(u32 tag, u32 data, u32 error);
extern void func_0200e978(u32 tag, u32 data, s32 error);
extern s32 func_0200e8cc(RTCDate *date, void (*callback)(s32, void *), void *arg);
void func_0200ef38(s32 result, void *arg);
/* Original assembly busy-wait remains in the delink; see the function document. */
extern void func_0200ef48(void);
s32 func_0200ef80(u32 command);

/* RTC_Init in NitroSDK external.c: initialize once and bind the ARM7 RTC FIFO. */
void func_0200e860(void)
{
    if (data_021542f8.initialized) return;
    data_021542f8.initialized = 1;
    data_021542f8.lock = 0;
    data_021542f8.callback = 0;
    data_021542f8.interrupt = 0;
    data_021542f8.buffer[0] = 0;
    data_021542f8.buffer[1] = 0;
    func_0200a324();
    while (!func_0200a47c(5, 1)) { }
    func_0200a430(5, func_0200e978);
}

/* RTC_GetDate in NitroSDK external.c: date stays caller-owned until completion. */
s32 func_0200e940(RTCDate *date)
{
    data_021542f8.commonResult = func_0200e8cc(date, func_0200ef38, 0);
    if (data_021542f8.commonResult == 0) func_0200ef48();
    return data_021542f8.commonResult;
}

/* RtcBCD2HEX in NitroSDK external.c: reject any non-decimal nibble with zero. */
u32 func_0200eec8(u32 bcd)
{
    u32 hex = 0;
    s32 i, w;
    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 15) >= 10) return hex;
    }
    for (i = 0, w = 1; i < 8; i++, w *= 10) {
        hex += ((bcd >> (i * 4)) & 15) * w;
    }
    return hex;
}

/* RtcGetResultCallback in NitroSDK external.c: retain synchronous request status. */
void func_0200ef38(s32 result, void *arg)
{
    data_021542f8.commonResult = result;
}

/* RTCi_ReadRawDateAsync in NitroSDK internal.c: request command 0x12. */
s32 func_0200ef60(void)
{
    return func_0200ef80(18);
}

/* RTCi_WriteRawStatus2Async in NitroSDK internal.c: request command 0x27. */
s32 func_0200ef70(void)
{
    return func_0200ef80(39);
}

/* RtcSendPxiCommand in NitroSDK internal.c: pack a seven-bit RTC FIFO command. */
s32 func_0200ef80(u32 command)
{
    return func_0200a4a0(5, (command << 8) & 0x7f00, 0) >= 0;
}
