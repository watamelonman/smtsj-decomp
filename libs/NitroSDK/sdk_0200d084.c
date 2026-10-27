#include "types.h"

/** Uncalibrated touch coordinates (12 bits), contact bit and two validity bits. */
typedef struct { u16 x, y, touch, validity; } TPData;
/** Shared touch-panel state; storage and sample ring belong to the SDK. */
typedef struct {
    u32 initialized;
    void (*callback)(u32 command, u32 result, u32 index);
    TPData sample;
    u16 index;
    u16 pad12;
    TPData *samples;
    u16 count;
    u8 pad1a[0x36 - 0x1a];
    u16 state;
    u16 errors;
    u16 busy;
} TPWork;
extern TPWork data_02154290;
extern void func_02007e94(void);

/** ARM9 shared-memory wire format; the two halfwords must be read separately. */
typedef union {
    struct { u16 lo, hi; } halves;
    struct { u32 x:12, y:12, touch:1, validity:2, padding:5; } bits;
} TPPacked;

/** Handles touch FIFO results, as identified by pokediamond's TPi_TpCallback.
 * Evidence: pret/pokediamond arm9/asm/SPI_tp.s, TPi_TpCallback.
 * Shared-memory samples at 0x027fffaa contain packed coordinates and status.
 * The provider must initialize the sample ring/count before automatic sampling.
 */
void func_0200d100(u32 tag, u32 data, s32 error)
{
    u16 result = (u16)data;
    u16 command = (result & 0x7f00) >> 8;
    u16 status;
    if (error) {
        data_02154290.errors |= 1 << command;
        if (data_02154290.callback)
            data_02154290.callback(command, 4, 0);
        return;
    }
    if (command == 16) {
        TPPacked sample;
        TPData *output;
        data_02154290.index++;
        if (data_02154290.index >= data_02154290.count)
            data_02154290.index = 0;
        sample.halves.lo = *(volatile u16 *)0x027fffaa;
        sample.halves.hi = *(volatile u16 *)0x027fffac;
        output = &data_02154290.samples[data_02154290.index];
        output->x = sample.bits.x;
        output->y = sample.bits.y;
        output->touch = (u8)sample.bits.touch;
        output->validity = (u8)sample.bits.validity;
        if (data_02154290.callback)
            data_02154290.callback(command, 0, (u8)data_02154290.index);
        return;
    }
    if (!(data & 0x1000000)) return;
    switch (result & 0xff) {
    case 0:
        switch (command) {
        case 0: {
            TPPacked sample;
            sample.halves.lo = *(volatile u16 *)0x027fffaa;
            sample.halves.hi = *(volatile u16 *)0x027fffac;
            data_02154290.sample.x = sample.bits.x;
            data_02154290.sample.y = sample.bits.y;
            data_02154290.sample.touch = (u8)sample.bits.touch;
            data_02154290.sample.validity = (u8)sample.bits.validity;
            data_02154290.state = 0;
            break;
        }
        case 1: data_02154290.state = 2; break;
        case 2: data_02154290.state = 0; break;
        }
        data_02154290.busy &= ~(1 << command);
        if (data_02154290.callback)
            data_02154290.callback(command, 0, 0);
        return;
    case 4: status = 3; goto error_result;
    case 2: status = 1; goto error_result;
    case 3: status = 2;
    error_result:
        data_02154290.errors |= 1 << command;
        data_02154290.busy &= ~(1 << command);
        if (data_02154290.callback)
            data_02154290.callback(command, (u8)status, 0);
        return;
    default: func_02007e94(); return;
    }
}
