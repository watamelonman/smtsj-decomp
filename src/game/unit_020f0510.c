#include "types.h"

/* Borrowed global state; only offsets used by this unit are described. */
typedef struct Unk0f0510State {
    u32 unk_00;
    u32 unk_04;
    s32 unk_08;
    u8 pad_0c[0x1c];
    s32 unk_28;
    u8 pad_2c[0x14];
    u32 unk_40;
    u32 unk_44;
} Unk0f0510State;

/* Optional indexed record returned by GetArr58; no ownership is transferred. */
typedef struct Unk0f0510Record {
    u8 pad_00[0x20];
    u16 unk_20;
    u8 unk_22;
} Unk0f0510Record;

extern Unk0f0510State *data_02176df8;
u32 Unk0f8448_GetUnkField10(void *object);
s32 Unk0f8448_Unk_0f8468(void *object);
Unk0f0510Record *Unk0ea208_GetArr58(s32 index);
s32 Unk0e8228_Unk_0e8c9c(void);
u32 Unk0e8228_Unk_0e8c80(void);
u32 func_02044ec4(u32 value);
s32 func_02049d80(u32 value, s32 mode);
s32 Unk0e8228_Thunk_02045c38(void);
s32 Unk0cb0d0_Unk_0cb304(u32 value);
s32 Unk0e8228_IsField4One(void);
void func_0204a160(u32 value, s32 mode);
void Unk0e8228_Unk_0e8eac(void);
void func_020f7e48(u32 value, s32 mode, s32 argument);
void func_020f7d7c(u32 value, s32 argument);
s32 func_0204a1d0(u32 value, s32 mode);
void Unk0feba0_Unk_0febe8(s32 value);
void func_020e8710(u32 value, s32 mode, s32 argument);
void func_020f7578(Unk0f0510State *state, Unk0f0510Record *record);
void func_020f7d14(u32 value);
void Unk0e8228_Unk_0e8d90(u32 value, u32 field);
s32 Unk0e8228_Unk_0e8c68(void);
void Unk0ea208_Unk_0ea878(u32 value);
void func_0204faf0(s32 mode, u32 value);
void Unk0caea8_Unk_0cb064(u32 value);
void Unk0fedd4_Unk_0fee38(void);

/* Test whether an index can proceed; absent records succeed, while byte +0x22
 * supplies the threshold. The first incoming argument is unused in the ROM. */
s32 func_020f0510(u32 unused, s32 index)
{
    Unk0f0510State *state = data_02176df8;
    Unk0f0510Record *record;
    if (index == 0 && state->unk_28 == 3) return 1;
    if (Unk0e8228_Unk_0e8c9c()) return 0;
    record = Unk0ea208_GetArr58(index);
    if (record == 0) return 1;
    if (func_02049d80(func_02044ec4(Unk0e8228_Unk_0e8c80()), 1) < record->unk_22) return 0;
    if (Unk0e8228_Thunk_02045c38()) {
        record = Unk0ea208_GetArr58(index);
        if (record == 0) return 1;
        if (Unk0cb0d0_Unk_0cb304(record->unk_20)) return 0;
    }
    return 1;
}

/* Dispatch an object's relative index; the zero-index/state-3 path issues
 * mode updates against the borrowed global handles instead of a record. */
void func_020f05b4(void *object)
{
    Unk0f0510State *state = data_02176df8;
    u32 field = Unk0f8448_GetUnkField10(object);
    s32 index = Unk0f8448_Unk_0f8468(object);
    if (field == 0 && state->unk_28 == 3) {
        u32 value = func_02044ec4(Unk0e8228_Unk_0e8c80());
        if (Unk0e8228_IsField4One()) {
            func_0204a160(value, 1);
            Unk0e8228_Unk_0e8eac();
            func_020f7e48(30, 1, state->unk_28);
            func_020f7d7c(state->unk_40, 30);
            func_020f7e48(30, 2, func_0204a1d0(value, 1));
            func_020f7e48(state->unk_40, 0, 7);
            Unk0feba0_Unk_0febe8(0);
        } else {
            func_020e8710(state->unk_40, 3, 0);
            func_020f7e48(state->unk_40, 0, 7);
            Unk0feba0_Unk_0febe8(0);
        }
    } else {
        func_020f7578(state, Unk0ea208_GetArr58(index));
    }
}

/* Reset the two handles at +4 and +0x40; both belong to global state. */
void Unk0f0510_Unk_0f06a4(void)
{
    Unk0f0510State *state = data_02176df8;
    func_020f7d14(state->unk_04);
    func_020f7e48(state->unk_40, 0, 1);
}

/* Forward the object's field +0x10 to the global handle at +0x44. */
void Unk0f0510_Unk_0f06d0(void *object)
{
    u32 field = Unk0f8448_GetUnkField10(object);
    Unk0e8228_Unk_0e8d90(data_02176df8->unk_44, field);
}

/* Only states 9 and 10 accept this update. Missing records clear the two
 * selected values; every accepted path finishes with the same notification. */
void func_020f06f4(void *object)
{
    s32 index;
    Unk0f0510Record *record;
    if (data_02176df8->unk_08 != 9 && data_02176df8->unk_08 != 10) return;
    index = Unk0f8448_Unk_0f8468(object);
    if (index == 0 && Unk0e8228_Unk_0e8c68()) {
        Unk0ea208_Unk_0ea878(func_02044ec4(Unk0e8228_Unk_0e8c80()));
    } else {
        record = Unk0ea208_GetArr58(index);
        if (record == 0) {
            func_0204faf0(10, 0);
            Unk0caea8_Unk_0cb064(0);
        } else {
            func_0204faf0(10, record->unk_20);
            Unk0caea8_Unk_0cb064(record->unk_20);
        }
    }
    Unk0fedd4_Unk_0fee38();
}
