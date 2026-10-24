#include "types.h"

/* Layout follows the byte/word accesses at 020a4e48..020a50c8. */
typedef struct BrightnessState {
    u32 mode;
    u8 delay;
    u8 step;
    s8 level;
    u8 elapsed;
    s32 active;
} BrightnessState;

extern BrightnessState data_02176b08;
extern void func_0200292c(volatile u16 *reg, s32 level);
void func_020a4eb0(u32 mode, u32 delay, u32 step);

/* Reset the shared state; a zero argument also writes the sub-screen master
 * brightness register (0x0400106c), as evidenced by the original literal. */
void func_020a4e48(s32 defer_write)
{
    data_02176b08.mode = 2;
    data_02176b08.level = 0;
    data_02176b08.elapsed = 0;
    data_02176b08.delay = 0;
    data_02176b08.active = 0;
    data_02176b08.step = 3;
    if (defer_write == 0) {
        func_0200292c((volatile u16 *)0x0400106c, data_02176b08.level / 2);
    }
}

/* Start the selected mode with no delay and a three-unit step. */
void Unk0a4e48_Unk_0a4e9c(u32 mode)
{
    func_020a4eb0(mode, 0, 3);
}

/* Start a brightness transition. Delay and step are stored as bytes; modes
 * 0/1 start at -32/+32, while modes 2/3 start at zero. */
void func_020a4eb0(u32 mode, u32 delay, u32 step)
{
    data_02176b08.active = 1;
    data_02176b08.mode = mode;
    data_02176b08.elapsed = 0;
    data_02176b08.delay = delay;
    data_02176b08.step = step;
    switch (mode) {
    case 0: data_02176b08.level = -32; break;
    case 1: data_02176b08.level = 32; break;
    case 2: data_02176b08.level = 0; break;
    case 3: data_02176b08.level = 0; break;
    }
    func_0200292c((volatile u16 *)0x0400106c, data_02176b08.level / 2);
}

/* Empty callback: the original consists solely of a return instruction. */
void Unk0a4e48_Nop_0a4f38(void) { }

/* Advance the shared transition by one tick and return its active flag.
 * The signed byte level is halved before writing register 0x0400106c. */
s32 func_020a4f3c(void)
{
    if (data_02176b08.active != 0) {
        if (data_02176b08.elapsed >= data_02176b08.delay) {
            switch (data_02176b08.mode) {
            case 0:
                data_02176b08.level += data_02176b08.step;
                if (data_02176b08.level > 0) data_02176b08.level = 0;
                break;
            case 1:
                data_02176b08.level -= data_02176b08.step;
                if (data_02176b08.level < 0) data_02176b08.level = 0;
                break;
            case 2:
                data_02176b08.level -= data_02176b08.step;
                if (data_02176b08.level < -32) data_02176b08.level = -32;
                break;
            case 3:
                data_02176b08.level += data_02176b08.step;
                if (data_02176b08.level > 32) data_02176b08.level = 32;
                break;
            }
            func_0200292c((volatile u16 *)0x0400106c, data_02176b08.level / 2);
            data_02176b08.elapsed = 0;
        } else {
            data_02176b08.elapsed++;
        }
    }
    if (data_02176b08.mode == 0) {
        if (data_02176b08.level >= 0) data_02176b08.active = 0;
    }
    if (data_02176b08.mode == 1) {
        if (data_02176b08.level <= 0) data_02176b08.active = 0;
    }
    if (data_02176b08.mode == 2) {
        if (data_02176b08.level <= -32) data_02176b08.active = 0;
    }
    if (data_02176b08.mode == 3) {
        if (data_02176b08.level >= 32) data_02176b08.active = 0;
    }
    return data_02176b08.active;
}
