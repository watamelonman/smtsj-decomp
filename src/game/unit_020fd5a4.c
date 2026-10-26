#include "types.h"

/** Borrowed work view; offsets follow the loads in 020fd5e0..020fd71c. */
typedef struct Unk0fd5a4Obj {
    void *resource;
    s32 unk04;
    s32 x, y;
    s32 dx, dy;
    s32 unk18;
    s32 mode;
    s32 counter;
    s32 unk24;
    s32 flag;
    s32 state;
} Unk0fd5a4Obj;

extern void func_020572d8(void);
extern void func_02057524(s32 value);
extern void func_02057ddc(s32 value);
extern void func_02057e18(s32 value);
extern void func_02057e58(s32 a, s32 b, s32 c);
extern void func_02057eb8(s32 value);
extern void func_02057fd8(void);
extern void func_020580ec(s32 value);
extern void func_0205bb68(void);
extern void func_0205ddb4(void *resource);
extern s32 func_020e666c(s32 mask);
extern void func_020fd7d8(Unk0fd5a4Obj *o);
extern u32 data_02176e1c;

/** Release the owned resource if present, clear its slot, and reset the global word. */
void Unk0fd5a4_Unk_0fd5a4(void **resource)
{
    if (*resource != 0) {
        func_0205ddb4(*resource);
        *resource = 0;
    }
    func_0205bb68();
    func_0205bb68();
    data_02176e1c = 0;
}

/** Advance each signed coordinate toward its bounds, stopping its delta on arrival. */
void func_020fd5e0(Unk0fd5a4Obj *o, s32 minX, s32 minY, s32 maxX, s32 maxY)
{
    if (o->dx < 0) {
        o->x += o->dx;
        if (o->x <= minX) { o->x = minX; o->dx = 0; }
    }
    if (o->dy < 0) {
        o->y += o->dy;
        if (o->y <= minY) { o->y = minY; o->dy = 0; }
    }
    if (o->dx > 0) {
        o->x += o->dx;
        if (o->x >= maxX) { o->x = maxX; o->dx = 0; }
    }
    if (o->dy > 0) {
        o->y += o->dy;
        if (o->y >= maxY) { o->y = maxY; o->dy = 0; }
    }
}

/** Wrap the frame counter at 65535, latch the queried flag, and advance coordinates. */
void func_020fd68c(Unk0fd5a4Obj *o)
{
    if (++o->counter >= 65535) o->counter = 0;
    if (func_020e666c(0x700)) o->flag = 1;
    func_020fd5e0(o, -81, 0, 0, 0);
}

void func_020fd71c(Unk0fd5a4Obj *o);

/** Submit the work only when its state differs from zero. */
void Unk0fd5a4_Unk_0fd6ec(Unk0fd5a4Obj *o)
{
    if (o->state == 0) return;
    func_020fd71c(o);
}

/** Submit the work only when its state differs from one. */
void Unk0fd5a4_Unk_0fd704(Unk0fd5a4Obj *o)
{
    if (o->state == 1) return;
    func_020fd71c(o);
}

/** Establish the fixed submission settings used by 020fd71c. */
void Unk0fd5a4_Unk_0fd9b4(void)
{
    func_020580ec(0);
    func_02057e18(31);
    func_02057ddc(-1);
    func_02057524(4);
}

/** Restore selector -1 and finish the submission sequence. */
void Unk0fd5a4_Unk_0fd9dc(void)
{
    func_02057eb8(-1);
    func_020572d8();
}

/** Dispatch the mode-specific setup around 020fd7d8; valid modes are 0..3. */
void func_020fd71c(Unk0fd5a4Obj *o)
{
    Unk0fd5a4_Unk_0fd9b4();
    switch (o->mode) {
    case 1:
        func_02057e58(2, 48, 10);
        func_02057eb8(2);
        func_020fd7d8(o);
        func_02057eb8(-1);
        break;
    case 0:
        func_02057e58(1, 40, 10);
        func_02057eb8(1);
        func_020fd7d8(o);
        func_02057eb8(-1);
        break;
    case 2:
        func_02057e58(0, 5, 10);
        func_02057eb8(0);
        func_020fd7d8(o);
        break;
    case 3:
        func_02057fd8();
        func_020fd7d8(o);
        break;
    }
    Unk0fd5a4_Unk_0fd9dc();
}
