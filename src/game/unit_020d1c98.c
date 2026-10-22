#include "types.h"

/* Only the resource fields read by this unit are known. */
typedef struct Unk0d1c98Resource {
    u8 pad_0000[0x14];
    u32 unk_0014;
    u8 pad_0018[0x10];
    u32 unk_0028;
} Unk0d1c98Resource;

/* Five words are allocated by func_020d1cb4; offsets follow ARM accesses. */
typedef struct Unk0d1c98Work {
    u32 unk_0000;
    Unk0d1c98Resource *unk_0004;
    s32 unk_0008;
    u32 unk_000c;
    u32 unk_0010;
} Unk0d1c98Work;

extern Unk0d1c98Work *data_02176bdc;
void func_020629c4(Unk0d1c98Resource *resource);
void func_02061424(Unk0d1c98Work *work);
void func_020d1da4(u32 arg0, u32 arg1, u32 arg2);
void func_020d1ab4(Unk0d1c98Work *work);
void func_020d1b54(Unk0d1c98Work *work);
Unk0d1c98Work *func_020611dc(void (*arg0)(Unk0d1c98Work *),
    void (*arg1)(Unk0d1c98Work *), u32 arg2,
    void (*arg3)(Unk0d1c98Work *), u32 size, u32 alignment, u32 arg6, u32 arg7);
Unk0d1c98Resource *func_020629ac(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
void func_0204fcb0(u32 arg0, u32 arg1);
void func_02061f10(Unk0d1c98Resource *resource, s32 arg1, u32 arg2, u32 arg3, u32 arg4);
void Unk09d060_Unk_09d170(Unk0d1c98Work *work);
s32 func_02061a04(u32 arg0, u32 arg1);

/* Forward the two words with the optional third argument disabled. */
void Unk0d1c98_Unk_0d1d94(u32 arg0, u32 arg1)
{
    func_020d1da4(arg0, arg1, 0);
}

/* Release the resource owned at +4, then clear its ownership slot. */
void Unk0d1c98_Unk_0d1c98(Unk0d1c98Work *work)
{
    func_020629c4(work->unk_0004);
    work->unk_0004 = 0;
}

/* Release the singleton and its resource, if initialized; evidence: paired frees. */
void Unk0d1c98_Release(void)
{
    if (data_02176bdc == 0) return;
    func_020629c4(data_02176bdc->unk_0004);
    data_02176bdc->unk_0004 = 0;
    func_02061424(data_02176bdc);
    data_02176bdc = 0;
}

/* Allocate the five-word singleton once and install its resource and callbacks. */
void func_020d1cb4(void)
{
    if (data_02176bdc != 0) return;
    data_02176bdc = func_020611dc(func_020d1ab4, func_020d1b54, 0,
        Unk0d1c98_Unk_0d1c98, 20, 4, 0, 1);
    data_02176bdc->unk_0004 = func_020629ac(5, 1, 0, 1);
    data_02176bdc->unk_0000 = 0;
}

/* Submit arg0, clamp the derived excess to 140, and update state and arg1. */
void func_020d1da4(u32 arg0, u32 arg1, u32 arg2)
{
    s32 value;
    if (arg2 != 0) func_0204fcb0(1, arg2);
    func_02061f10(data_02176bdc->unk_0004, -1, 0, 0, arg0);
    Unk09d060_Unk_09d170(data_02176bdc);
    data_02176bdc->unk_0008 = 0;
    value = func_02061a04(data_02176bdc->unk_0004->unk_0028,
        data_02176bdc->unk_0004->unk_0014);
    if (value > 50) {
        if (value > 190) value = 190;
        data_02176bdc->unk_0008 = value - 50;
    }
    switch (data_02176bdc->unk_0000) {
    case 0:
        data_02176bdc->unk_0000 = 3;
        data_02176bdc->unk_0010 = 0;
        break;
    case 1: case 2: case 3: break;
    case 4:
        data_02176bdc->unk_0000 = 3;
        break;
    }
    data_02176bdc->unk_000c = arg1;
}

/* In states 2/3, request state 4 or set +0xc according to the input flag. */
void func_020d1e94(u32 arg0)
{
    Unk0d1c98Work *work = data_02176bdc;
    if (work == 0) return;
    if (arg0 != 0) {
        switch (work->unk_0000) {
        case 2: case 3:
            work->unk_0000 = 4;
            work->unk_0010 = 1;
            break;
        }
    } else {
        switch (work->unk_0000) {
        case 2: case 3:
            work->unk_000c = 1;
            break;
        }
    }
}
