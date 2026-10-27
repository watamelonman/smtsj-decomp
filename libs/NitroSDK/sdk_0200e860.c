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

/* Packed RTC transfer fields follow NitroSDK rtc/common/type.h; ARM7 owns them. */
typedef struct RTCRawDate {
    u32 year :8;
    u32 month :5;
    u32 dummy0 :3;
    u32 day :6;
    u32 dummy1 :2;
    u32 week :3;
    u32 dummy2 :5;
} RTCRawDate;

/* ARM7 packs clock time into one word; reserved bits retain their SDK widths. */
typedef struct RTCRawTime {
    u32 hour :6;
    u32 afternoon :1;
    u32 dummy0 :1;
    u32 minute :7;
    u32 dummy1 :1;
    u32 second :7;
    u32 dummy2 :9;
} RTCRawTime;

/* Shared status halfword: interrupt modes are updated before a second request. */
typedef struct RTCRawStatus2 {
    u16 intr_mode :4;
    u16 dummy0 :2;
    u16 intr2_mode :1;
    u16 test :1;
    u16 dummy1 :8;
} RTCRawStatus2;

/* Alarm fields and their three enable flags share one ARM7 transfer word. */
typedef struct RTCRawAlarm {
    u32 week :3;
    u32 dummy0 :4;
    u32 we :1;
    u32 hour :6;
    u32 afternoon :1;
    u32 he :1;
    u32 minute :7;
    u32 me :1;
    u32 dummy2 :8;
} RTCRawAlarm;

/* Caller-owned decoded time and alarm fields use hours/minutes/seconds. */
typedef struct { u32 hour, minute, second; } RTCTime;
typedef struct { u32 week, hour, minute, enable; } RTCAlarmParam;
typedef s32 RTCResult;
typedef s32 RTCPxiResult;
typedef u32 RTCWeek;
typedef u32 RTCAlarmStatus;
enum { RTC_ALARM_STATUS_OFF, RTC_ALARM_STATUS_ON };
typedef void (*RTCCallback)(s32, void *);
extern u32 func_02007a58(void);
extern u32 func_02007a6c(u32 mode);
s32 func_0200ef60(void);
s32 func_0200ef70(void);
u32 func_0200eec8(u32 bcd);
s32 func_0200efa8(RTCDate *date);
typedef enum RTCLock {
    RTC_LOCK_OFF = 0,
    RTC_LOCK_ON,
    RTC_LOCK_MAX
} RTCLock;

typedef enum RTCSequence {
    RTC_SEQ_GET_DATE = 0,
    RTC_SEQ_GET_TIME,
    RTC_SEQ_GET_DATETIME,
    RTC_SEQ_SET_DATE,
    RTC_SEQ_SET_TIME,
    RTC_SEQ_SET_DATETIME,
    RTC_SEQ_GET_ALARM1_STATUS,
    RTC_SEQ_GET_ALARM2_STATUS,
    RTC_SEQ_GET_ALARM_PARAM,
    RTC_SEQ_SET_ALARM1_STATUS,
    RTC_SEQ_SET_ALARM2_STATUS,
    RTC_SEQ_SET_ALARM1_PARAM,
    RTC_SEQ_SET_ALARM2_PARAM,
    RTC_SEQ_SET_HOUR_FORMAT,
    RTC_SEQ_SET_REG_STATUS2,
    RTC_SEQ_SET_REG_ADJUST,
    RTC_SEQ_MAX
} RTCSequence;

#define RTC_ALARM_ENABLE_NONE       0x0000
#define RTC_ALARM_ENABLE_WEEK       0x0001
#define RTC_ALARM_ENABLE_HOUR       0x0002
#define RTC_ALARM_ENABLE_MINUTE     0x0004
#define RTC_PXI_COMMAND_MASK                0x00007f00
#define RTC_PXI_COMMAND_SHIFT               8
#define RTC_PXI_RESULT_MASK                 0x000000ff
#define RTC_PXI_RESULT_SHIFT                0
#define RTC_PXI_COMMAND_INTERRUPT           0x30
#define RTC_INTERRUPT_MODE_NONE             0x0
#define RTC_INTERRUPT_MODE_ALARM            0x4
enum { RTC_RESULT_SUCCESS, RTC_RESULT_BUSY, RTC_RESULT_ILLEGAL_PARAMETER,
    RTC_RESULT_SEND_ERROR, RTC_RESULT_INVALID_COMMAND, RTC_RESULT_ILLEGAL_STATUS,
    RTC_RESULT_FATAL_ERROR };
enum { RTC_PXI_RESULT_SUCCESS, RTC_PXI_RESULT_INVALID_COMMAND,
    RTC_PXI_RESULT_ILLEGAL_STATUS, RTC_PXI_RESULT_BUSY, RTC_PXI_RESULT_FATAL_ERROR };

extern RTCState data_021542f8;
extern void func_0200a324(void);
extern s32 func_0200a47c(u32 tag, u32 processor);
extern void func_0200a430(u32 tag, void (*callback)(u32, u32, s32));
extern s32 func_0200a4a0(u32 tag, u32 data, u32 error);
extern void func_0200e978(u32 tag, u32 data, s32 error);
extern s32 func_0200e8cc(RTCTime *time, void (*callback)(s32, void *), void *arg);
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

/* RTC_GetTimeAsync (NitroSDK external.c): borrow time and context until callback.
 * Sequence 1 and FIFO command 0x12 identify the time request. */
s32 func_0200e8cc(RTCTime * time, RTCCallback callback, void * arg)
{
    u32 enabled;

    enabled = func_02007a58();

    if (data_021542f8.lock != RTC_LOCK_OFF) {
        (void)func_02007a6c(enabled);
        return RTC_RESULT_BUSY;
    }

    data_021542f8.lock = RTC_LOCK_ON;
    (void)func_02007a6c(enabled);

    data_021542f8.sequence = RTC_SEQ_GET_TIME;
    data_021542f8.index = 0;
    data_021542f8.buffer[0] = (void *)time;
    data_021542f8.callback = callback;
    data_021542f8.callbackArg = arg;

    if (func_0200ef60()) {
        return RTC_RESULT_SUCCESS;
    } else {
        return RTC_RESULT_SEND_ERROR;
    }
}

/* RTC_GetTime in NitroSDK external.c: time stays caller-owned until completion. */
s32 func_0200e940(RTCTime *time)
{
    data_021542f8.commonResult = func_0200e8cc(time, func_0200ef38, 0);
    if (data_021542f8.commonResult == 0) func_0200ef48();
    return data_021542f8.commonResult;
}

/* RtcCommonCallback (NitroSDK external.c): decode ARM7 results and release requests. */
void func_0200e978(u32 tag, u32 data, s32 err)
{

    RTCResult result;
    RTCPxiResult pxiresult;
    u8 command;
    RTCCallback cb;

    if (err) {
        if (data_021542f8.index) {
            data_021542f8.index = 0;
        }

        if (data_021542f8.lock != RTC_LOCK_OFF) {
            data_021542f8.lock = RTC_LOCK_OFF;
        }

        if (data_021542f8.callback) {
            cb = data_021542f8.callback;
            data_021542f8.callback = 0;
            cb(RTC_RESULT_FATAL_ERROR, data_021542f8.callbackArg);
        }

        return;
    }

    command = (u8)((data & RTC_PXI_COMMAND_MASK) >> RTC_PXI_COMMAND_SHIFT);
    pxiresult = (RTCPxiResult)((data & RTC_PXI_RESULT_MASK) >> RTC_PXI_RESULT_SHIFT);

    if (command == RTC_PXI_COMMAND_INTERRUPT) {
        if (data_021542f8.interrupt) {
            data_021542f8.interrupt();
        }
        return;
    }

    if (pxiresult == RTC_PXI_RESULT_SUCCESS) {
        result = RTC_RESULT_SUCCESS;
        switch (data_021542f8.sequence) {

        case RTC_SEQ_GET_DATE:
        {
            RTCDate * pDst = (RTCDate *)(data_021542f8.buffer[0]);
            RTCRawDate * pSrc = (RTCRawDate *)0x027ffde8;

            pDst->year = func_0200eec8(pSrc->year);
            pDst->month = func_0200eec8(pSrc->month);
            pDst->day = func_0200eec8(pSrc->day);
            pDst->week = func_0200efa8(pDst);
        }
        break;
        case RTC_SEQ_GET_TIME:
        {
            RTCTime * pDst = (RTCTime *)(data_021542f8.buffer[0]);
            RTCRawTime * pSrc = (RTCRawTime *)0x027ffdec;

            pDst->hour = func_0200eec8(pSrc->hour);
            pDst->minute = func_0200eec8(pSrc->minute);
            pDst->second = func_0200eec8(pSrc->second);
        }
        break;
        case RTC_SEQ_GET_DATETIME:
        {
            RTCDate * pDst = (RTCDate *)(data_021542f8.buffer[0]);
            RTCRawDate * pSrc = (RTCRawDate *)0x027ffde8;

            pDst->year = func_0200eec8(*(u32 *)pSrc & 0x000000ff);
            pDst->month = func_0200eec8(pSrc->month);
            pDst->day = func_0200eec8(pSrc->day);
            pDst->week = func_0200efa8(pDst);
        }
            {
                RTCTime * pDst = (RTCTime *)(data_021542f8.buffer[1]);
                RTCRawTime * pSrc = (RTCRawTime *)0x027ffdec;

                pDst->hour = func_0200eec8(pSrc->hour);
                pDst->minute = func_0200eec8(pSrc->minute);
                pDst->second = func_0200eec8(pSrc->second);
            }
            break;

        case RTC_SEQ_SET_DATE:
        case RTC_SEQ_SET_TIME:
        case RTC_SEQ_SET_DATETIME:
            break;
        case RTC_SEQ_GET_ALARM1_STATUS:
        {
            RTCAlarmStatus * pDst = (RTCAlarmStatus *)(data_021542f8.buffer[0]);
            RTCRawStatus2 * pSrc = (RTCRawStatus2 *)0x027ffdea;

            switch (pSrc->intr_mode) {
            case RTC_INTERRUPT_MODE_ALARM:
                *pDst = RTC_ALARM_STATUS_ON;
                break;
            default:
                *pDst = RTC_ALARM_STATUS_OFF;
            }
        }
        break;

        case RTC_SEQ_GET_ALARM2_STATUS:
        {
            RTCAlarmStatus * pDst = (RTCAlarmStatus *)(data_021542f8.buffer[0]);
            RTCRawStatus2 * pSrc = (RTCRawStatus2 *)0x027ffdea;

            if (pSrc->intr2_mode) {
                *pDst = RTC_ALARM_STATUS_ON;
            } else {
                *pDst = RTC_ALARM_STATUS_OFF;
            }
        }
        break;

        case RTC_SEQ_GET_ALARM_PARAM:
        {
            RTCAlarmParam * pDst = (RTCAlarmParam *)(data_021542f8.buffer[0]);
            RTCRawAlarm * pSrc = (RTCRawAlarm *)0x027ffdec;

            pDst->week = (RTCWeek)(pSrc->week);
            pDst->hour = func_0200eec8(pSrc->hour);
            pDst->minute = func_0200eec8(pSrc->minute);
            pDst->enable = RTC_ALARM_ENABLE_NONE;
            if (pSrc->we)
                pDst->enable += RTC_ALARM_ENABLE_WEEK;
            if (pSrc->he)
                pDst->enable += RTC_ALARM_ENABLE_HOUR;
            if (pSrc->me)
                pDst->enable += RTC_ALARM_ENABLE_MINUTE;
        }
        break;
        case RTC_SEQ_SET_ALARM1_STATUS:
            if (data_021542f8.index == 0) {
                RTCRawStatus2 * pSrc = (RTCRawStatus2 *)0x027ffdea;

                if (*(RTCAlarmStatus *)(data_021542f8.buffer[0]) == RTC_ALARM_STATUS_ON) {
                    if (pSrc->intr_mode != RTC_INTERRUPT_MODE_ALARM) {
                        data_021542f8.index++;
                        pSrc->intr_mode = RTC_INTERRUPT_MODE_ALARM;
                        if (!func_0200ef70()) {
                            data_021542f8.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {
                    if (pSrc->intr_mode != RTC_INTERRUPT_MODE_NONE) {
                        data_021542f8.index++;
                        pSrc->intr_mode = RTC_INTERRUPT_MODE_NONE;
                        if (!func_0200ef70()) {
                            data_021542f8.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                data_021542f8.index = 0;
            }
            break;
        case RTC_SEQ_SET_ALARM2_STATUS:
            if (data_021542f8.index == 0) {
                RTCRawStatus2 * pSrc = (RTCRawStatus2 *)0x027ffdea;

                if (*(RTCAlarmStatus *)(data_021542f8.buffer[0]) == RTC_ALARM_STATUS_ON) {
                    if (!pSrc->intr2_mode) {
                        data_021542f8.index++;
                        pSrc->intr2_mode = 1;
                        if (!func_0200ef70()) {
                            data_021542f8.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                } else {

                    if (pSrc->intr2_mode) {

                        data_021542f8.index++;
                        pSrc->intr2_mode = 0;
                        if (!func_0200ef70()) {
                            data_021542f8.index = 0;
                            result = RTC_RESULT_SEND_ERROR;
                        }
                    }
                }
            } else {
                data_021542f8.index = 0;
            }
            break;
        case RTC_SEQ_SET_ALARM1_PARAM:
        case RTC_SEQ_SET_ALARM2_PARAM:
        case RTC_SEQ_SET_HOUR_FORMAT:
        case RTC_SEQ_SET_REG_STATUS2:
        case RTC_SEQ_SET_REG_ADJUST:
            break;
        default:
            result = RTC_RESULT_INVALID_COMMAND;
            data_021542f8.index = 0;
        }
    } else {
        data_021542f8.index = 0;

        switch (pxiresult) {
        case RTC_PXI_RESULT_INVALID_COMMAND:
            result = RTC_RESULT_INVALID_COMMAND;
            break;
        case RTC_PXI_RESULT_ILLEGAL_STATUS:
            result = RTC_RESULT_ILLEGAL_STATUS;
            break;
        case RTC_PXI_RESULT_BUSY:
            result = RTC_RESULT_BUSY;
            break;
        case RTC_PXI_RESULT_FATAL_ERROR:
        default:
            result = RTC_RESULT_FATAL_ERROR;
        }
    }

    if (data_021542f8.index == 0) {
        if (data_021542f8.lock != RTC_LOCK_OFF) {
            data_021542f8.lock = RTC_LOCK_OFF;
        }

        if (data_021542f8.callback) {
            cb = data_021542f8.callback;
            data_021542f8.callback = 0;
            cb(result, data_021542f8.callbackArg);
        }
    }
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

/* RTCi_ReadRawTimeAsync in NitroSDK internal.c: request command 0x12. */
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

/* RTC_GetDayOfWeek (NitroSDK convert.c): Gregorian weekday (Sunday = 0),
 * using caller-owned calendar fields and a 2000-based year. */
s32 func_0200efa8(RTCDate * date)
{
    int cent;
    int year = (int)(2000 + date->year);
    int month = (int)date->month;
    int day = (int)date->day;

    month -= 2;

    if (month < 1) {
        month += 12;
        --year;
    }

    cent = year / 100;
    year %= 100;
    return (RTCWeek)(((26 * month - 2) / 10 + day + year + year / 4 + cent / 4 + 5 * cent) % 7);
}
