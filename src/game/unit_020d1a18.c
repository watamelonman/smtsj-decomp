#include "types.h"

/* The callback owner stores its phase, resource handle, width and two timers. */
typedef struct {
    int phase;
    int handle;
    int width;
    int delay;
    int timer;
} Unk0d1a18State;

typedef struct {
    u8 flags[2];
    u8 padding[2];
    u32 values[16];
} Unk0d1a18Options;

extern void Unk02e000_Unk_02e0cc(void);
extern void CampStatus_Unk_0d51cc(void);
extern void Unk0bc1a8_Unk_0bc928(int mode, int value, Unk0d1a18Options *options);
extern void func_020bcbc4(int mode, Unk0d1a18Options *options);
extern void func_02062a00(int handle);
extern void func_02061730(Unk0d1a18State *state);
extern void func_02057524(int mode);
extern void func_02057df8(void);
extern void func_02057e18(int value);
extern void func_020580ec(int enabled);
extern void func_02058e9c(int layer, int resource, int x, int y, float scale, int value, int flags);
extern int func_02059c70(int resource, int value);
extern void func_02058f10(int layer, int resource, int x, int y, int width, int value, int flags);
extern void func_02060b60(int mode, int handle, int x, int y, int value, int flags);
extern void func_02057534(void);

/* Build the mode-3 option block; bit/slot meanings remain unidentified. */
void func_020d1a18(void)
{
    Unk0d1a18Options options;
    int i;
    for (i = 0; i < 2; i++)
        options.flags[i] = 0;
    for (i = 0; i < 16; i++)
        options.values[i] = 0;
    options.flags[0] |= 8;
    options.flags[0] |= 32;
    options.values[3] = 21;
    options.values[5] = 1;
    Unk0bc1a8_Unk_0bc928(3, 21, &options);
    options.values[1] = 1;
    options.flags[0] |= 2;
    func_020bcbc4(3, &options);
}

/* Invoke the paired setup routines used by this unit's callers. */
void Unk0d1a18_Unk_0d1aa4(void)
{
    Unk02e000_Unk_02e0cc();
    CampStatus_Unk_0d51cc();
}

/* Advance the phase timers and release the handle and owner at phase 4's end. */
void func_020d1ab4(Unk0d1a18State *state)
{
    switch (state->phase) {
    case 0:
    case 1:
        break;
    case 2:
        if (state->delay > 0) {
            if (--state->delay == 0) {
                state->phase = 4;
                state->timer = 2;
            }
        }
        break;
    case 3:
        if (++state->timer >= 2)
            state->phase = 2;
        break;
    case 4:
        if (--state->timer == 0) {
            state->phase = 0;
            func_02062a00(state->handle);
            func_02061730(state);
        }
        break;
    }
}

/* Submit three resource draws around a centered width; phase 2 adds the handle draw. */
void func_020d1b54(Unk0d1a18State *state)
{
    int width, half;
    if (state->phase == 0)
        return;
    width = state->width + 32;
    if (width % 2 != 0)
        width++;
    half = (width - 32) / 2;
    func_02057524(7);
    func_02057df8();
    func_02057e18(31);
    func_020580ec(0);
    Unk02e000_Unk_02e0cc();
    func_02058e9c(2, 0x5f80, -half, -111, 1.0f, 0, 16);
    func_02058f10(2, 0x5f82, -half, -111, width, func_02059c70(0x5f82, 3), 16);
    func_02058e9c(0x4002, 0x5f81, half, -111, 1.0f, 0, 16);
    if (state->phase == 2)
        func_02060b60(0x1000001, state->handle, 128, 13, 0, 17);
    func_020580ec(1);
    func_02057534();
}
