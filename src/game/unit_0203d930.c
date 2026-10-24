#include "types.h"

/* Borrowed views: only fields addressed by this unit are described. */
typedef struct CommandWork {
    u8 pad_00[0x18];
    s32 unk_18;
    u8 pad_1c[0x40];
    s8 unk_5c;
} CommandWork;
typedef struct CommandRoot {
    u8 pad_00[0xe8];
    CommandWork *unk_e8;
} CommandRoot;
typedef struct ManagerView {
    u8 pad_00[0x3bc];
    s32 unk_3bc;
} ManagerView;

extern ManagerView *Unk095560_GetManager(void);
extern CommandRoot *Unk03aae8_Unk_03ad14(void);
extern s32 func_0203ac00(s32 index);
extern void Unk09ee4c_Unk_09ef80(s32 value);
extern void Unk09d42c_Unk_09e2a4(s16 value);
extern void Unk0d297c_Unk_0d2b70(s32 value);
extern void Unk10a034_Unk_10af40(s32 value);
extern s32 func_02065544(void);
extern void func_02065c10(void);
extern s32 Unk0d297c_Unk_0d2f98(s32 value);
extern void func_020656ac(s32 value, s32 other);
extern void Unk0caea8_Unk_0caf98(s32 value);
extern void Unk0a0ce4_Unk_0a0da4(s32 value);
extern void Unk02dcfc_SetField64(void);
extern void func_020d2b98(s16 value, u8 other);
extern void func_0210a034(s32 value, CommandWork *work);
extern void Unk10a034_Unk_10a074(void);
extern s32 Unk10a034_Unk_10a08c(void);
extern s32 Unk10a034_Unk_10a0b4(void);
extern void Unk10a034_Unk_10a05c(void);
extern void Unk0fc584_SetDir(s32 value);
extern void Unk03aae8_Unk_03acf4(s32 value);
extern void Unk0d297c_Unk_0d2c1c(s32 value);
extern void Unk10a034_Alloc(s32 value, CommandWork *work);
extern void Unk10a034_Unk_10b018(void);
extern s32 Unk10a034_Unk_10b030(void);
extern void Unk10a034_Unk_10b000(void);

/* Manager field 0x3bc gates the call with 90; a successful path sets work+0x18. */
s32 Unk03d930_Unk_03d930(void)
{
    if (Unk095560_GetManager()->unk_3bc == 0) return 0;
    Unk09ee4c_Unk_09ef80(90);
    {
        CommandWork *work = Unk03aae8_Unk_03ad14()->unk_e8;
        work->unk_18 = 15;
    }
    return 3;
}

/* Argument zero is narrowed to signed 16 bits before forwarding; returns status 3. */
s32 Unk03d930_Unk_03d968(void)
{
    Unk09d42c_Unk_09e2a4((s16)func_0203ac00(0));
    {
        CommandWork *work = Unk03aae8_Unk_03ad14()->unk_e8;
        work->unk_18 = 15;
    }
    return 3;
}

/* Starts the argument-selected operation and initializes its shared wait field. */
s32 Unk03d930_Unk_03d998(void)
{
    s32 value = func_0203ac00(0);
    CommandWork *work = Unk03aae8_Unk_03ad14()->unk_e8;
    Unk0d297c_Unk_0d2b70(value);
    Unk10a034_Unk_10af40(value);
    if (func_02065544() == 0) func_02065c10();
    func_020656ac(Unk0d297c_Unk_0d2f98(1), -1);
    work->unk_18 = 30;
    Unk0caea8_Unk_0caf98(1);
    Unk0a0ce4_Unk_0a0da4(40);
    return 3;
}

/* Calls the field-64 setter (callee evidence) and returns command status 3. */
s32 Unk03d930_Unk_03da00(void)
{
    Unk02dcfc_SetField64();
    return 3;
}

/* Narrows two command arguments, starts an operation, and sets the wait field to 30. */
s32 Unk03d930_Unk_03da10(void)
{
    s16 value = func_0203ac00(0);
    s16 other = func_0203ac00(1);
    func_020d2b98(value, (u8)other);
    Unk10a034_Unk_10af40(value);
    if (func_02065544() == 0) func_02065c10();
    func_020656ac(Unk0d297c_Unk_0d2f98(24), -1);
    {
        CommandWork *work = Unk03aae8_Unk_03ad14()->unk_e8;
        work->unk_18 = 30;
    }
    Unk0caea8_Unk_0caf98(1);
    Unk0a0ce4_Unk_0a0da4(40);
    return 3;
}

/* Work byte 0x5c drives a two-phase operation; pending phases return zero. */
s32 func_0203da90(void)
{
    s32 value = func_0203ac00(0);
    s32 result = 0;
    CommandWork *argument = Unk03aae8_Unk_03ad14()->unk_e8;
    CommandWork *work = Unk03aae8_Unk_03ad14()->unk_e8;
    switch (work->unk_5c) {
    case 0:
        func_0210a034(value, argument);
        work->unk_5c++;
        return result;
    case 1:
        Unk10a034_Unk_10a074();
        if (Unk10a034_Unk_10a08c() == 0) return result;
        result = Unk10a034_Unk_10a0b4();
        Unk10a034_Unk_10a05c();
        break;
    }
    Unk0fc584_SetDir(0);
    work->unk_5c = 0;
    Unk03aae8_Unk_03acf4(result);
    return 3;
}

/* Starts on phase zero, polls on phase one, and clears the phase when finished. */
s32 func_0203db2c(void)
{
    s32 value = func_0203ac00(0);
    CommandWork *argument = Unk03aae8_Unk_03ad14()->unk_e8;
    CommandWork *work = Unk03aae8_Unk_03ad14()->unk_e8;
    switch (work->unk_5c) {
    case 0:
        Unk0d297c_Unk_0d2c1c(value);
        Unk10a034_Alloc(value, argument);
        work->unk_5c++;
        return 0;
    case 1:
        Unk10a034_Unk_10b018();
        if (Unk10a034_Unk_10b030() == 0) return 0;
        Unk10a034_Unk_10b000();
        break;
    }
    Unk0fc584_SetDir(0);
    work->unk_5c = 0;
    return 3;
}
