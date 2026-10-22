#include "types.h"

/* Only fields accessed by this unit are named; offsets follow the ARM loads. */
typedef struct Unk0eed24Work {
    u32 unk_00;
    u32 unk_04;
    s32 unk_08;
    u32 unk_0c;
    s32 unk_10;
    u32 unk_14;
    u32 unk_18;
    s32 unk_1c;
    u8 pad_20[0x20];
    u32 unk_40;
} Unk0eed24Work;

/* Callback slots are stored at offsets 0x0c through 0x20 in the original. */
typedef struct Unk0eed24Callbacks {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    void (*unk_0c)(void);
    void (*unk_10)(void);
    void (*unk_14)(void);
    u32 unk_18;
    void (*unk_1c)(void);
    void (*unk_20)(void);
} Unk0eed24Callbacks;

void func_020f7248(void);
void func_020d1e94(s32 value);
void Unk0fd9f0_Unk_0fda58(s32 value);
void Unk0d1c98_Unk_0d1d94(u32 value, s32 arg1);
u32 func_020ea630(s32 value);
void Unk0feba0_Unk_0febe8(s32 value);
s32 Unk0f7188_Unk_0f7210(void);
s32 func_02053800(s32 arg0, u32 mask);
void func_020f7de4(u32 value, s32 arg1);
void func_020f7e48(u32 value, s32 arg1, s32 arg2);
void func_020f7d14(u32 value);
void Unk100208_Unk_100208(s32 value);
void Unk0e8228_Unk_0e8e50(void);
void func_02057df8(void);
void func_02057fd8(void);
s32 Unk0e8228_Unk_0e8474(void);
u32 Unk0e8228_GetArr30(s32 index);
void func_020f5e18(u32 value, s32 x, s32 y, s32 arg3);
s32 Unk0e8228_Unk_0e8460(void);
u32 Unk0e8228_GetArr40(s32 index);
u32 func_02044ec4(void);
void func_02049c58(u32 value, s16 *position);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Unk_0e8e7c(void);
void func_020eef84(void);
void Unk0eef2c_Nop_0ef06c(void);
void Unk0eef2c_Unk_0ef070(void);
void Unk0eef2c_Nop_0eef80(void);
void func_020ef090(void);

/* Forward unchanged to the target identified by the original branch relocation. */
void Unk0eed24_Thunk_020f7248(void) { func_020f7248(); }

/* Select value 1 in both external subsystems; purpose remains unidentified. */
void Unk0eed24_Unk_0eeebc(void)
{
    func_020d1e94(1);
    Unk0fd9f0_Unk_0fda58(1);
}

/* Reset one subsystem and pass the entry for index 10 to another. */
void Unk0eed24_Unk_0eee94(void)
{
    u32 value;
    Unk0feba0_Unk_0febe8(0);
    value = func_020ea630(10);
    Unk0d1c98_Unk_0d1d94(value, -1);
    Unk0fd9f0_Unk_0fda58(3);
}

/* Apply the three work-handle operations only when both external checks pass. */
void func_020eed24(Unk0eed24Work *work)
{
    if (Unk0f7188_Unk_0f7210() == 0) return;
    if (func_02053800(0, 0xc03) == 0) return;
    func_020f7de4(work->unk_40, 0);
    func_020f7e48(work->unk_04, 0, 5);
    func_020f7d14(work->unk_04);
    Unk100208_Unk_100208(6);
}

/* Visit both external arrays using the observed coordinates and percentage scale. */
void func_020eed80(Unk0eed24Work *work)
{
    s32 scale;
    s32 base;
    s32 offset;
    s32 i;
    u32 entry;
    s32 j;
    s16 position[2];
    s32 delta;
    if (work->unk_08 == 1) return;
    Unk0e8228_Unk_0e8e50();
    func_02057df8();
    scale = 100;
    delta = work->unk_1c - work->unk_10;
    if (delta > 0) scale = 100 - delta * 100 / 10;
    func_02057fd8();
    base = work->unk_10;
    offset = 39;
    for (i = 0; i < Unk0e8228_Unk_0e8474(); i++, offset += 64) {
        u32 value = Unk0e8228_GetArr30(i);
        if (value != 0) func_020f5e18(value, base + offset, 102, scale);
    }
    for (j = 0; j < Unk0e8228_Unk_0e8460(); j++) {
        entry = Unk0e8228_GetArr40(j);
        func_02049c58(func_02044ec4(), position);
        func_020f5e18(entry, base + position[0], 30, scale);
    }
    Unk0e8228_Thunk_02057534();
    Unk0e8228_Unk_0e8e7c();
}

/* Populate the descriptor with the exact callbacks evidenced by literal relocations. */
void func_020eeed4(Unk0eed24Callbacks *callbacks)
{
    callbacks->unk_00 = 24;
    callbacks->unk_04 = 4;
    callbacks->unk_0c = func_020eef84;
    callbacks->unk_10 = Unk0eef2c_Nop_0ef06c;
    callbacks->unk_14 = Unk0eef2c_Unk_0ef070;
    callbacks->unk_18 = 0;
    callbacks->unk_1c = Unk0eef2c_Nop_0eef80;
    callbacks->unk_20 = func_020ef090;
}
