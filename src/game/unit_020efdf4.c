#include "types.h"

/* Unknown gaps preserve the offsets accessed by this unit. */
typedef struct Unk0efdf4Work {
    u8 pad_0000[0x40];
    u32 unk_0040;
    u8 pad_0044[8];
    u32 unk_004c;
} Unk0efdf4Work;

/* The record passed to func_020aa188 begins at context offset 0x1e8. */
typedef struct Unk0efdf4Record {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    u8 pad_000c[8];
    u32 unk_0014;
} Unk0efdf4Record;

/* Only fields used here are known; the remaining context belongs to its provider. */
typedef struct Unk0efdf4Context {
    u32 unk_0000;
    u8 pad_0004[0x1e4];
    Unk0efdf4Record unk_01e8;
} Unk0efdf4Context;

extern Unk0efdf4Work *data_02176df4;
extern s32 Unk0f8448_GetUnkField10(u32 handle);
extern void Unk0f8448_Init(u32 handle, u32 value);
extern void func_020f8264(u32 handle);
extern void func_020f7e48(u32 handle, s32 value, s32 mode);
extern void func_020f7d7c(u32 handle, s32 value);
extern void Unk0e8228_Unk_0e8d90(u32 handle, s32 value);
extern void func_020e8ebc(s32 value);
extern void Unk044904_Unk_045bd0(s32 value);
extern void Unk0e8228_Unk_0e8d18(s32 value);
extern s32 Unk0e8228_IsState3(void);
extern void Unk0e8228_Unk_0e9020(s32 value);
extern s32 Unk0e8228_IsField4One(void);
extern void Unk0e8228_Unk_0e8cbc(void);
extern void Unk0e8228_Unk_0e8b7c(void);
extern void Unk0feba0_Unk_0febe8(s32 value);
extern void Unk0fd9f0_Unk_0fda58(s32 value);
extern void Unk0e8228_Unk_0e8c80(void);
extern Unk0efdf4Context *func_02044ec4(void);
extern u32 func_020b0874(u32 value, s32 scale);
extern u32 Unk044904_Unk_044fd8(void);
extern void func_020aa188(u32 handle, Unk0efdf4Record *record);
extern void Unk0e8228_Unk_0e8c2c(void);
extern void func_020e82c8(void);
extern void func_020ea3cc(s32 value);
extern s32 Unk0e651c_Unk_0e666c(u32 value);

/* Dispatch values 0..2 from the handle's field 0x10; other values have no branch. */
void func_020efdf4(u32 handle)
{
    s32 state = Unk0f8448_GetUnkField10(handle);
    Unk0efdf4Work *work = data_02176df4;
    Unk0efdf4Context *context;
    func_020e8ebc(0);
    switch (state) {
    case 0:
        Unk044904_Unk_045bd0(0);
        Unk0e8228_Unk_0e8d18(0);
        if (Unk0e8228_IsState3()) return;
        Unk0e8228_Unk_0e9020(1);
        if (Unk0e8228_IsField4One()) Unk0e8228_Unk_0e8cbc();
        func_020f7e48(work->unk_0040, 0, 2);
        break;
    case 1:
        Unk0e8228_Unk_0e8b7c();
        Unk044904_Unk_045bd0(1);
        func_020f7e48(30, 1, 8);
        func_020f7d7c(work->unk_0040, 30);
        func_020f7e48(work->unk_0040, 0, 1);
        Unk0feba0_Unk_0febe8(0);
        Unk0fd9f0_Unk_0fda58(1);
        break;
    case 2:
        Unk0e8228_Unk_0e8c80();
        context = func_02044ec4();
        context->unk_01e8.unk_0008 = 4;
        context->unk_01e8.unk_0000 = context->unk_0000;
        context->unk_01e8.unk_0004 = context->unk_0000;
        context->unk_01e8.unk_0014 = func_020b0874(context->unk_01e8.unk_0000, 100) | 0x50000000;
        func_020aa188(Unk044904_Unk_044fd8(), &context->unk_01e8);
        Unk0feba0_Unk_0febe8(0);
        Unk0e8228_Unk_0e8c2c();
        func_020e82c8();
        break;
    }
}

/* Reset the supplied handle with a zero value, then invoke its follow-up helper. */
void Unk0efdf4_Unk_0eff1c(u32 handle)
{
    Unk0f8448_Init(handle, 0);
    func_020f8264(handle);
}

/* Forward the handle's field 0x10 to the work object's field 0x4c helper. */
void Unk0efdf4_Unk_0eff38(u32 handle)
{
    Unk0efdf4Work *work = data_02176df4;
    Unk0e8228_Unk_0e8d90(work->unk_004c, Unk0f8448_GetUnkField10(handle));
}

/* Apply mode 7 and value 34 to the handle stored at work offset 0x40. */
void Unk0efdf4_Unk_0eff5c(void)
{
    Unk0efdf4Work *work = data_02176df4;
    func_020f7e48(work->unk_0040, 0, 7);
    func_020f7d7c(work->unk_0040, 34);
}

/* Map field 0x10 to a helper value; state 1 additionally queries identifier 0x707. */
void func_020eff8c(u32 handle)
{
    switch (Unk0f8448_GetUnkField10(handle)) {
    case 0:
        func_020ea3cc(1);
        break;
    case 1:
        if (!Unk0e651c_Unk_0e666c(0x707)) func_020ea3cc(13);
        else func_020ea3cc(2);
        break;
    case 2:
        func_020ea3cc(3);
        break;
    }
}
