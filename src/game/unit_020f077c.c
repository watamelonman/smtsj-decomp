#include "types.h"

/* Fields are named by their observed offsets; the list occupies +0x50..+0xf3. */
typedef struct Unk0f077cWork {
    u8 pad_0000[8];
    u32 unk_0008;
    u8 pad_000c[0x34];
    s32 unk_0040;
    u8 pad_0044[8];
    s32 unk_004c;
    u8 unk_0050[0xa4];
} Unk0f077cWork;

typedef void (*Unk0f077cCallback)(Unk0f077cWork *);

/* Callback descriptor written by func_020f077c; +8 is owned by the caller. */
typedef struct Unk0f077cDescriptor {
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    Unk0f077cCallback unk_000c;
    Unk0f077cCallback unk_0010;
    Unk0f077cCallback unk_0014;
    Unk0f077cCallback unk_0018;
    Unk0f077cCallback unk_001c;
    Unk0f077cCallback unk_0020;
} Unk0f077cDescriptor;

extern Unk0f077cWork *data_02176dfc;
void func_02008848(void *dest, s32 value, u32 size);
void func_020f0800(Unk0f077cWork *work);
void func_020f08e0(Unk0f077cWork *work);
void Unk0f077c_Nop_0f08dc(Unk0f077cWork *work);
void Unk0f09b4_Unk_0f09b4(Unk0f077cWork *work);
void func_020f09e4(Unk0f077cWork *work);
void Unk0f09b4_Thunk_020f7248(Unk0f077cWork *work);
void Unk0f09b4_Unk_0f0b64(Unk0f077cWork *work);
void Unk0f09b4_Nop_0f0b94(Unk0f077cWork *work);
void func_020f0b98(Unk0f077cWork *work);
void func_020f0be0(Unk0f077cWork *work);
void func_020f0ca4(Unk0f077cWork *work);
void Unk0f0eac_Unk_0f0eac(Unk0f077cWork *work);
void Unk0f0eac_Unk_0f0f08(Unk0f077cWork *work);
void Unk0f0eac_Unk_0f0f2c(Unk0f077cWork *work);
void func_020f0f5c(Unk0f077cWork *work);
void func_020f711c(Unk0f077cWork *work, s32 id, s32 flag, s32 zero,
    s32 a, s32 b, s32 c, s32 d, Unk0f077cCallback e,
    Unk0f077cCallback f, Unk0f077cCallback g);
void func_020f81cc(void *list, s32 a, s32 b, s32 c, s32 d, s32 e,
    Unk0f077cCallback f, Unk0f077cCallback g,
    Unk0f077cCallback h, Unk0f077cCallback i);
void Unk0f81a4_SetUnkFielda0(void *list, Unk0f077cCallback callback);
void Unk0f81a4_SetUnkField9c(void *list, Unk0f077cCallback callback);
void func_020f7188(Unk0f077cWork *work);
void Unk0bc1a8_Unk_0bc9b4(s32 id, s32 value);
void func_020f7de4(s32 id, s32 value);
void Unk0e8228_Unk_0e8684(void);
s32 Unk0e8228_IsFieldCOne(void);
s32 func_020e8628(void);
void func_020f7d14(s32 id);
void Unk100208_Unk_100208(s32 value);
void Unk0e8228_Unk_0e8c50(s32 value);
void func_020f8264(void *list);

/* Supplies a 0xf4-byte work size and callbacks, leaving descriptor +8 untouched. */
void func_020f077c(Unk0f077cDescriptor *descriptor)
{
    descriptor->unk_0000 = 0xf4;
    descriptor->unk_0004 = 4;
    descriptor->unk_000c = func_020f08e0;
    descriptor->unk_0010 = Unk0f09b4_Unk_0f09b4;
    descriptor->unk_0014 = func_020f09e4;
    descriptor->unk_0018 = 0;
    descriptor->unk_001c = Unk0f077c_Nop_0f08dc;
    descriptor->unk_0020 = Unk0f09b4_Thunk_020f7248;
}

/* Clears the caller-owned 0xf4-byte work block and publishes it before setup. */
void Unk0f077c_Unk_0f07d4(Unk0f077cWork *work)
{
    func_02008848(work, 0, 0xf4);
    data_02176dfc = work;
    func_020f0800(work);
}

/* Installs the work and embedded-list callbacks using the observed setup constants. */
void func_020f0800(Unk0f077cWork *work)
{
    work->unk_0040 = 28;
    work->unk_004c = 1;
    func_020f711c(work, work->unk_0040, -128, 0, 12, -128, 0, 0,
        Unk0f09b4_Unk_0f0b64, Unk0f09b4_Nop_0f0b94, func_020f0b98);
    func_020f81cc(work->unk_0050, 5, 5, 0, 0, 1,
        func_020f0be0, func_020f0ca4, Unk0f0eac_Unk_0f0eac, Unk0f0eac_Unk_0f0f08);
    Unk0f81a4_SetUnkFielda0(work->unk_0050, Unk0f0eac_Unk_0f0f2c);
    Unk0f81a4_SetUnkField9c(work->unk_0050, func_020f0f5c);
}

/* Empty descriptor callback, as evidenced by the original single return instruction. */
void Unk0f077c_Nop_0f08dc(Unk0f077cWork *work) { }

/* Advances common work handling, then handles states 2, 9 and 11 only. */
void func_020f08e0(Unk0f077cWork *work)
{
    func_020f7188(work);
    switch (work->unk_0008) {
    case 0: case 1: break;
    case 11:
        Unk0bc1a8_Unk_0bc9b4(work->unk_0040, 0);
        break;
    case 2:
        func_020f7de4(work->unk_0040, 0);
        Unk0e8228_Unk_0e8684();
        if (Unk0e8228_IsFieldCOne()) {
            if (func_020e8628() == 1) {
                func_020f7d14(28);
                Unk100208_Unk_100208(4);
            } else {
                Unk0e8228_Unk_0e8c50(0);
                func_020f7d14(29);
            }
        } else {
            func_020f7d14(27);
            Unk100208_Unk_100208(4);
        }
        break;
    case 3: case 4: case 5: case 6: case 7: case 8: break;
    case 9:
        func_020f8264(work->unk_0050);
        work->unk_0008 = 10;
        break;
    case 10: break;
    }
}
