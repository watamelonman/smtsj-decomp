#include "types.h"

/** Caller-owned work prefix; offsets 0, 4, 16 and 20 follow callback loads. */
typedef struct Unk0211f894Work {
    s32 state;
    s32 step;
    u32 unknown08[2];
    u32 resource;
    u32 alternate;
} Unk0211f894Work;

extern void func_02057524(s32 mode);
extern void func_02057534(void);
extern void func_02057fd8(void);
extern void func_02057e18(u32 value);
extern void func_02057d54(s32, s32, s32, s32, s32, s32);
extern void func_0205de40(s32, u32, s32, s32, s32, float, float, s32, float, s32);
extern void func_02058bf8(void *, u32, s32, s32, s32, s32, s32);
extern void func_020574d4(void);
extern void *Unk02e000_GetAddr_data_02140ac8(void);
extern void func_02058f84(u32, void *, void *);
void func_0211f9a4(Unk0211f894Work *work);
/* Retained in the delink: see the hard list in docs/functions/game-unit-0211f894.md. */
void func_0211fa24(u32 resource, s32 direction);
void func_0211fb4c(u32 id, s32 x, s32 y, s32 top, s32 left, s32 bottom, s32 right, s32 a, s32 b, s32 c);

/** Requires valid work; dispatches submissions using the state loads at 0211f894. */
void func_0211f894(Unk0211f894Work *work)
{
    switch (work->state) {
    case 6:
    case 7:
        func_0211f9a4(work);
    }
    func_0211fa24(work->resource, 1);
    switch (work->state) {
    case 2: {
        s32 height = ((8 - work->step) * 172) / 8;
        func_0211fb4c(0x5c00, 42, 90, 0, 0, height, 12, height, 12, 1);
        break;
    }
    case 3:
    case 4:
        func_0205de40(2, work->alternate, 0, 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
        break;
    }
}

/** Requires valid work; always submits the reverse variant, updating intensity in states 6/7. */
void func_0211f974(Unk0211f894Work *work)
{
    switch (work->state) {
    case 6:
    case 7:
        func_0211f9a4(work);
    }
    func_0211fa24(work->resource, 0);
}

/** Requires valid work; narrows step-derived intensity to a byte and replaces zero with one. */
void func_0211f9a4(Unk0211f894Work *work)
{
    u8 intensity;
    func_02057524(4);
    intensity = ((11 - work->step) * 31) / 11;
    if (intensity == 0) intensity = 1;
    func_02057fd8();
    func_02057e18(intensity);
    func_02057d54(0, 0, 0, 256, 192, 22);
    func_02057e18(31);
    func_02057534();
}

/** Rejects empty bounds, prepares a submission, and brackets it with geometry register writes. */
void func_0211fb4c(u32 id, s32 x, s32 y, s32 top, s32 left, s32 bottom, s32 right, s32 a, s32 b, s32 c)
{
    struct {
        u32 prepared[9];
        s32 left, right, top, bottom;
        u32 unknown34;
    } packet;
    if (bottom - top <= 0) return;
    if (right - left <= 0) return;
    func_02058bf8(&packet, 0x20001, x, y, a, b, c);
    packet.left = left;
    packet.right = right;
    packet.top = top;
    packet.bottom = bottom;
    func_020574d4();
    *(volatile u32 *)0x4000440 = 2;
    *(volatile u32 *)0x4000444 = 0;
    func_02058f84(id, &packet, Unk02e000_GetAddr_data_02140ac8());
    *(volatile u32 *)0x4000448 = 1;
}
