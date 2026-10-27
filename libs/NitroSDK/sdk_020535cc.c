#include "libs/NitroSDK/sdk_020535cc.h"

/* Key input register and its BIOS mirror; both hold active-low key bits. */
#define REG_KEYINPUT (*(volatile u16 *)0x04000130)
#define REG_KEYMIRROR (*(volatile u16 *)0x027fffa8)

/* Only the low 12 key bits are tracked by this TU (A/B/Select/Start/dpad/L/R/X/Y). */
#define KEY_MASK 0x2fff

/* Records: the updater at 0x02053640 maintains held/complemented/new/released
 * bits plus the per-key auto-repeat state. Initialization advances by 0x56
 * bytes; record 0 is the one the updater refreshes. */
typedef struct Unk020535ccInput {
    u16 held;
    u16 complemented;
    u16 pressed;
    u16 released;
    u16 previous;
    u16 repeated;
    u16 repeating;
    u16 delay[12];
    u16 interval[12];
    u16 counter[12];
} Unk020535ccInput;

/* State block used by 0x0205397c and 0x020539dc; provider-owned. Offsets are
 * fixed by the callers in this TU, not by any public SDK layout. */
typedef struct Unk020535ccState {
    u32 state;
    u32 started;
    u32 unk08;
    u32 countdown;
    u32 reload;
    u32 dispatch14;
    u32 dispatch18;
    u32 dispatch1c;
    u32 busy20;
    u32 timer24;
    void (*callback28)(void);
    void (*callback2c)(void);
} Unk020535ccState;

extern Unk020535ccInput data_021605e4[5];
extern Unk020535ccState data_02160794;
/* Idle-frame counter cleared whenever any tracked key is held. */
extern u32 data_021605e0;

extern void func_020119c0(void *dst, int value, u32 size);
extern void func_0200e134(int arg0, int arg1, int arg2);
extern void func_02010d5c(void);
extern int func_020533d4(void);
extern void func_020533e4(void);
extern void func_0205342c(void);
extern void func_02053570(void);
extern void func_0205e818(int value);

/* Clears the five input records and gives every tracked key the initial
 * auto-repeat timing (delay 60 frames, interval 0). */
void func_020535cc(void)
{
    int device;
    u16 key;
    int bit;
    Unk020535ccInput *input = data_021605e4;

    for (device = 0; device < 5; device++) {
        func_020119c0(input, 0, sizeof(Unk020535ccInput));
        input++;
        for (bit = 0; bit < 12; bit++) {
            key = (u16)(1 << bit);
            func_020538dc(device, key, 60, 0);
        }
    }
}

/* Samples the key registers and updates record 0: held/complemented/pressed/
 * released bit sets, then the per-key auto-repeat counters. A key first fires
 * after `delay` held frames, then repeats each `interval` frames while held;
 * `repeated` holds the keys that fired this frame. The idle counter is reset
 * on any tracked input and incremented every call. */
void func_02053640(void)
{
    Unk020535ccInput *input = &data_021605e4[0];
    int i;

    input->previous = input->held;
    /* Key lines are active low: XOR flips only the tracked bits, then the
     * mask drops the unused high bits of the pair. */
    input->held = ((REG_KEYINPUT | REG_KEYMIRROR) ^ KEY_MASK) & KEY_MASK;
    input->complemented = ~input->held;
    input->pressed = input->held & ~input->previous;
    input->released = ~input->held & input->previous;
    input->repeated = input->pressed;

    for (i = 0; i < 12; i++) {
        u16 mask = (u16)(1 << i);

        if (input->held & mask) {
            if (input->repeating & mask) {
                if (input->counter[i] >= input->interval[i]) {
                    input->counter[i] = 0;
                    input->repeated |= mask;
                } else {
                    input->repeated &= ~mask;
                }
            } else if (input->counter[i] >= input->delay[i]) {
                input->counter[i] = 0;
                input->repeated |= mask;
                input->repeating |= mask;
            }
            input->counter[i]++;
        } else {
            input->counter[i] = 0;
            input->repeating &= ~mask;
            input->repeated &= ~mask;
        }
    }

    if (input->held != 0)
        data_021605e0 = 0;
    data_021605e0++;
}

/* Tests held bits, as established by the input updater's +0 halfword store. */
int func_020537b8(int device, u32 mask)
{
    int bits = data_021605e4[device].held;
    bits &= mask;
    return bits != 0;
}

/* Tests complemented held bits, stored at +2 by 0x02053640. */
int func_020537dc(int device, u32 mask)
{
    int bits = ((Unk020535ccInput *)((u32)data_021605e4 + device * sizeof(Unk020535ccInput)))->complemented;
    bits &= mask;
    return bits != 0;
}

/* Tests rising input bits: 0x02053640 stores current & ~previous at +4. */
int func_02053800(int device, u32 mask)
{
    int bits = ((Unk020535ccInput *)((u32)data_021605e4 + device * sizeof(Unk020535ccInput)))->pressed;
    bits &= mask;
    return bits != 0;
}

/* Tests auto-repeat bits, stored at +10 by 0x02053640. */
int func_02053824(int device, u32 mask)
{
    Unk020535ccInput *input = &data_021605e4[device];
    return (input->repeated & mask) != 0;
}

/* Maps a one-hot key bit (1..0x800) to its 0-based index; any other value
 * maps to -1. Evidence: the chain of shifts compared in 0x020538dc. */
int func_02053848(u32 key)
{
    if (key == 0x001) return 0;
    if (key == 0x002) return 1;
    if (key == 0x004) return 2;
    if (key == 0x008) return 3;
    if (key == 0x010) return 4;
    if (key == 0x020) return 5;
    if (key == 0x040) return 6;
    if (key == 0x080) return 7;
    if (key == 0x100) return 8;
    if (key == 0x200) return 9;
    if (key == 0x400) return 10;
    if (key == 0x800) return 11;
    return -1;
}

/* Sets the first-fire delay and repeat interval for one key on one device.
 * Returns 0 when the key is not one of the twelve tracked bits. */
int func_020538dc(u8 device, u16 key, u16 delay, u16 interval)
{
    Unk020535ccInput *input = &data_021605e4[device];
    int index = func_02053848(key);

    if (index == -1)
        return 0;
    input->delay[index] = delay;
    input->interval[index] = interval;
    return 1;
}

/* Applies the same first-fire delay and repeat interval to all twelve tracked
 * keys on all five records. */
void func_02053924(u16 delay, u16 interval)
{
    int device;
    u16 key;
    int bit;

    for (device = 0; device < 5; device++) {
        for (bit = 0; bit < 12; bit++) {
            key = (u16)(1 << bit);
            func_020538dc(device, key, delay, interval);
        }
    }
}

/* Resets the state block to state 3 and clears the countdown, reload, timer
 * and callback slots. The dispatch flags are cleared through their setters. */
void func_0205397c(void)
{
    data_02160794.state = 3;
    data_02160794.started = 0;
    data_02160794.unk08 = 0;
    data_02160794.countdown = 0;
    data_02160794.reload = 0;
    data_02160794.busy20 = 0;
    data_02160794.timer24 = 0;
    data_02160794.callback28 = 0;
    data_02160794.callback2c = 0;
    func_02053bd8(0);
    func_02053be8(0);
    func_02053bf8(0);
}

/* Sets the reload word copied into the countdown by 0x02053a28. */
void func_020539cc(u32 value)
{
    data_02160794.reload = value;
}

/* Advances the state machine once. Returns 1 on the frame the countdown is
 * armed, otherwise 0. While key-register bit 15 is set the sequence counts
 * down into state 1 and services at most one pending dispatch flag per call;
 * otherwise it tears the sequence down (state 2 if it was running, state 3 if
 * it never started). */
int func_020539dc(void)
{
    int armed = 0;

    if (data_02160794.busy20 == 1)
        return 0;

    if (((REG_KEYMIRROR & 0x8000) >> 15) == 1) {
        if (data_02160794.started == 0 && data_02160794.countdown == 0) {
            data_02160794.countdown = data_02160794.reload;
            data_02160794.state = 0;
            armed = 1;
        }
        if (data_02160794.countdown != 0) {
            data_02160794.countdown--;
            if (data_02160794.countdown == 0) {
                data_02160794.started = 1;
                data_02160794.state = 1;
                func_0205e818(1);
            }
        }
        if (data_02160794.started == 1) {
            if (data_02160794.dispatch14 == 1) {
                func_020533e4();
                func_0205342c();
                while (func_020533d4() != 1) {
                }
                func_02053570();
                data_02160794.dispatch14 = 0;
                func_0200e134(12, 0, 0);
            } else if (data_02160794.dispatch18 == 1) {
                func_02010d5c();
                data_02160794.dispatch18 = 0;
                func_0200e134(12, 0, 0);
            } else if (data_02160794.dispatch1c == 1) {
                if (data_02160794.callback28 != 0) {
                    data_02160794.callback28();
                    data_02160794.callback28 = 0;
                }
                data_02160794.dispatch1c = 0;
                func_0200e134(12, 0, 0);
            } else {
                func_0200e134(12, 0, 0);
            }
        }
    } else {
        data_02160794.unk08 = 0;
        if (data_02160794.started == 1) {
            data_02160794.unk08 = 1;
            data_02160794.state = 2;
            if (data_02160794.callback2c != 0) {
                data_02160794.callback2c();
                data_02160794.callback2c = 0;
            }
            data_02160794.timer24 = 40;
            func_0205e818(0);
        } else {
            data_02160794.state = 3;
        }
        data_02160794.started = 0;
        data_02160794.countdown = 0;
        if (data_02160794.timer24 != 0)
            data_02160794.timer24--;
    }

    return armed == 1;
}

/* Reads the state word assigned values 0..3 by 0x020539dc. */
u32 func_02053bc8(void)
{
    return data_02160794.state;
}

/* Sets the +0x14 flag tested before the provider sequence at 0x02053a78. */
void func_02053bd8(u32 value)
{
    data_02160794.dispatch14 = value;
}

/* Sets the +0x18 flag tested before the provider call at 0x02053ac0. */
void func_02053be8(u32 value)
{
    data_02160794.dispatch18 = value;
}

/* Sets the +0x1c flag tested before callback dispatch at 0x02053adc. */
void func_02053bf8(u32 value)
{
    data_02160794.dispatch1c = value;
}
