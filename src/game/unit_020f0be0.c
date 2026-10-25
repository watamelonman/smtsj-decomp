#include "types.h"

/* Borrowed work-area prefix; only the two observed halfwords are required. */
typedef struct Unk0f0be0Flags {
    u16 unk_00;
    u16 unk_02;
} Unk0f0be0Flags;

/* Shared work prefix, with its handle at the offset used by the original. */
typedef struct Unk0f0be0Work {
    u8 pad_00[0x40];
    u32 unk_40;
} Unk0f0be0Work;

/* Context prefix and embedded record; the record's extent is not established. */
typedef struct Unk0f0be0Context {
    u32 unk_00;
    u8 pad_04[0x1e4];
    u8 unk_1e8[1];
} Unk0f0be0Context;

extern Unk0f0be0Work *data_02176dfc;
extern Unk0f0be0Flags *Unk02e000_Thunk_0202e788(void);
extern s32 Unk0e8228_Unk_0e84e4(void);
extern s32 Unk0e651c_Unk_0e666c(u32 value);
extern s32 Unk0e8228_Unk_0e8488(void);
extern s32 Unk0e8228_Thunk_02045c38(void);
extern s32 func_020e8f74(void);
extern s32 Unk0f8448_GetUnkField10(void *object);
extern s32 Unk0e8228_Unk_0e8c80(void);
extern Unk0f0be0Context *func_02044ec4(s32 id);
extern void func_020e8ebc(s32 value);
extern void Unk0e8228_Unk_0e8f50(s32 value);
extern s32 Unk0e8228_IsField4One(void);
extern void func_0204a160(Unk0f0be0Context *context, s32 value);
extern void Unk0e8228_Unk_0e8eac(void);
extern void func_020f7e48(u32 handle, s32 value, s32 mode);
extern void func_020f7d7c(u32 handle, s32 value);
extern s32 func_0204a1d0(Unk0f0be0Context *context, s32 value);
extern void Unk0feba0_Unk_0febe8(s32 value);
extern void Unk0fd9f0_Unk_0fda58(s32 value);
extern void func_020e8710(u32 handle, s32 value, s32 mode);
extern s32 Unk0e8228_Unk_0e82ac(void);
extern void Unk0e8228_Unk_0e8d90(u32 handle, s32 value);
extern void func_020f7de4(u32 handle, s32 value);
extern void Unk100208_Unk_100208(s32 value);
extern s32 func_020e8d38(Unk0f0be0Context *context, void *record, u32 value, s32 mode);
extern void Unk0e8228_Unk_0e8d18(s32 value);

/* Test the selected option's prerequisites; the callback's first argument is unused.
 * Instruction evidence establishes the checks, but not the options' meanings. */
s32 func_020f0be0(void *unused, s32 option)
{
    Unk0f0be0Flags *flags = Unk02e000_Thunk_0202e788();
    switch (option) {
    case 0: return flags->unk_00 != 0;
    case 1: return flags->unk_02 != 0;
    case 2: return Unk0e8228_Unk_0e84e4() != 0;
    case 3:
        if (!Unk0e651c_Unk_0e666c(0x703)) return 0;
        if (Unk0e8228_Unk_0e8488() < 1) return 0;
        if (Unk0e8228_Thunk_02045c38()) return 0;
        return func_020e8f74() == 0;
    case 4: return 1;
    default: return 1;
    }
}

/* Dispatch the object's selection (0..4) through the observed context and handle
 * helpers. Other selections only perform the two common resets. */
void func_020f0ca4(void *object)
{
    s32 selection = Unk0f8448_GetUnkField10(object);
    Unk0f0be0Work *work = data_02176dfc;
    Unk0f0be0Context *context = func_02044ec4(Unk0e8228_Unk_0e8c80());
    func_020e8ebc(0);
    Unk0e8228_Unk_0e8f50(0);
    switch (selection) {
    case 0:
        if (Unk0e8228_IsField4One()) {
            func_0204a160(context, 0);
            Unk0e8228_Unk_0e8eac();
            func_020f7e48(30, 1, 0);
            func_020f7d7c(work->unk_40, 30);
            func_020f7e48(30, 2, func_0204a1d0(context, 0));
            func_020f7e48(work->unk_40, 0, 1);
            Unk0feba0_Unk_0febe8(0);
            Unk0fd9f0_Unk_0fda58(1);
        } else {
            func_020e8710(work->unk_40, 0, 0);
            func_020f7e48(work->unk_40, 0, 1);
            Unk0feba0_Unk_0febe8(0);
        }
        break;
    case 1:
        if (!Unk0e8228_Unk_0e82ac()) Unk0e8228_Unk_0e8d90(4, 0);
        func_020f7e48(31, 1, 3);
        func_020f7d7c(work->unk_40, 31);
        func_020f7de4(work->unk_40, 2);
        Unk0fd9f0_Unk_0fda58(1);
        Unk100208_Unk_100208(4);
        break;
    case 2:
        if (!Unk0e8228_Unk_0e82ac()) Unk0e8228_Unk_0e8d90(8, 0);
        func_020f7e48(32, 1, 4);
        func_020f7d7c(work->unk_40, 32);
        func_020f7de4(work->unk_40, 2);
        Unk0fd9f0_Unk_0fda58(1);
        Unk100208_Unk_100208(4);
        break;
    case 3:
        func_020e8710(work->unk_40, 5, 0);
        func_020f7e48(work->unk_40, 0, 1);
        Unk0feba0_Unk_0febe8(0);
        Unk0fd9f0_Unk_0fda58(1);
        break;
    case 4:
        if (func_020e8d38(context, context->unk_1e8, context->unk_00, 7))
            Unk0e8228_Unk_0e8d18(0);
        func_020f7e48(work->unk_40, 0, 2);
        break;
    }
}
