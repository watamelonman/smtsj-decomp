#include "types.h"

/* Borrowed 0x110-byte work area; offsets follow this unit's loads/stores. */
typedef struct Unk0efff4Work {
    u32 size;
    u32 unk_0004;
    s32 unk_0008;
    void (*unk_000c)(struct Unk0efff4Work *work);
    void (*unk_0010)(struct Unk0efff4Work *work);
    void (*unk_0014)(struct Unk0efff4Work *work);
    u32 unk_0018;
    void (*unk_001c)(void);
    void (*unk_0020)(void);
    u8 pad_0024[4];
    s32 unk_0028;
    u8 pad_002c[0x14];
    u32 unk_0040;
    u32 unk_0044;
    u32 unk_0048;
    u32 unk_004c;
    u8 unk_0050[0xa4];
    u32 unk_00f4;
    float unk_00f8[6];
} Unk0efff4Work;

void func_020f0264(Unk0efff4Work *work);
void func_020f0330(Unk0efff4Work *work);
void func_020f7248(void);
void func_02008848(void *dest, int value, u32 size);
void func_020f019c(Unk0efff4Work *work);
int Unk0f7188_Unk_0f7210(void);
void func_020f82e0(void *work);
void Unk0fedd4_SetState2(void);
void Unk0e8228_Unk_0e8c50(u32 value);
u32 func_020e852c(void);
void Unk0f81a4_Init(void *work, int count, u32 value);
s32 Unk0e8228_Unk_0e8374(u32 value);
void Unk0f8448_Init(void *work, s32 value);
void Unk0e8228_Unk_0e8c80(void);
void func_020ea290(void);
void func_020f8264(void *work);
void Unk0feba0_Unk_0febe8(int value);
extern Unk0efff4Work *data_02176df8;

/* Empty callback: the original contains only a return instruction. */
void Unk0efff4_Nop_0f0260(void) { }

/* Forwarding callback; the only call in the original targets func_020f7248. */
void Unk0efff4_Thunk_020f7248(void) { func_020f7248(); }

/* Clear the six words at +0xf8..+0x10c, as evidenced by the store loop. */
void Unk0efff4_ClearArrF8(Unk0efff4Work *work)
{
    int i;
    for (i = 0; i < 6; i++) {
        work->unk_00f8[i] = 0;
    }
}

/* Clear the entire work area, publish its borrowed pointer, then initialize it. */
void Unk0efff4_Unk_0f004c(Unk0efff4Work *work)
{
    func_02008848(work, 0, 0x110);
    data_02176df8 = work;
    func_020f019c(work);
}

/* Update the embedded +0x50 object when enabled; state 10 triggers the final call. */
void Unk0efff4_Unk_0f0300(Unk0efff4Work *work)
{
    if (Unk0f7188_Unk_0f7210() == 0) {
        return;
    }
    func_020f82e0(work->unk_0050);
    if (work->unk_0008 != 10) {
        return;
    }
    Unk0fedd4_SetState2();
}

/* Store a percentage as a float, clamping the input to the inclusive 0..100 range. */
void Unk0efff4_Unk_0f0098(float *dest, int value)
{
    if (value < 0) {
        *dest = 0.0f;
        return;
    }
    if (value > 100) {
        *dest = 1.0f;
        return;
    }
    *dest = value / 100.0f;
}

/* Populate the descriptor prefix; stores and callback relocations establish the layout. */
void func_020efff4(Unk0efff4Work *work)
{
    work->size = 0x110;
    work->unk_0004 = 4;
    work->unk_000c = func_020f0264;
    work->unk_0010 = Unk0efff4_Unk_0f0300;
    work->unk_0014 = func_020f0330;
    work->unk_0018 = 0;
    work->unk_001c = Unk0efff4_Nop_0f0260;
    work->unk_0020 = Unk0efff4_Thunk_020f7248;
}

/* Initialize the embedded +0x50 object using fields +0x28/+0x44 and clear its six slots. */
void func_020f04a4(Unk0efff4Work *work)
{
    Unk0e8228_Unk_0e8c50(work->unk_0028 == 3);
    work->unk_00f4 = func_020e852c();
    Unk0f81a4_Init(work->unk_0050, 6, work->unk_00f4);
    Unk0f8448_Init(work->unk_0050, Unk0e8228_Unk_0e8374(work->unk_0044));
    Unk0e8228_Unk_0e8c80();
    func_020ea290();
    func_020f8264(work->unk_0050);
    Unk0feba0_Unk_0febe8(4);
    Unk0efff4_ClearArrF8(work);
}

void func_020f7188(Unk0efff4Work *work);
void Unk0bc1a8_Unk_0bc9b4(u32 value, int flag);
void func_020f7de4(u32 value, int flag);
void func_020f711c(Unk0efff4Work *work, u32 value, int a, int b, int c, int d, int g, int h,
                   void (*callback)(Unk0efff4Work *), int e, int f);
int Unk0cb0d0_Unk_0cb1f8(void);
void func_020f0510(Unk0efff4Work *work);
void func_020f05b4(Unk0efff4Work *work);
void Unk0f0510_Unk_0f06a4(Unk0efff4Work *work);
void Unk0f0510_Unk_0f06d0(Unk0efff4Work *work);
void func_020f06f4(Unk0efff4Work *work);
void func_020f81cc(void *work, int count, int index, int g, int a, int b,
                  void (*c)(Unk0efff4Work *), void (*d)(Unk0efff4Work *),
                  void (*e)(Unk0efff4Work *), void (*f)(Unk0efff4Work *));
void Unk0f81a4_SetUnkField9c(void *work, void (*callback)(Unk0efff4Work *));
void Unk0f8448_Unk_0f8468(void *work);
int Unk0f8448_GetUnkField8(void *work);
int Unk0f8448_GetUnkField0(void *work);
void func_02057df8(void);
void Unk0e8228_Unk_0e8e50(void);
void func_02057e18(int value);
void Unk0e8228_Unk_0e8e6c(void);
int Unk0f8448_GetEntry(void *work, int index);
void func_020f5800(int x, int y, int kind, float alpha, int flag);
void Unk0f51dc_Unk_0f5ab4(int x, int y);
int Unk0e8228_Unk_0e8c68(void);
void Unk0f51dc_Unk_0f57d4(int index, int x, int y, int kind, float alpha);
void func_020f5754(int index, int x, int y, int kind, float alpha);
void Unk0e8228_Thunk_02057534(void);
void Unk0e8228_Unk_0e8e7c(void);

/* Update six float slots from the signed timer at +0x10 and duration at +0x18. */
void func_020f00dc(Unk0efff4Work *work)
{
    int value;
    if (work->unk_0010 == 0) {
        int i;
        for (i = 0; i < 6; i++) work->unk_00f8[i] = 1.0f;
        return;
    }
    value = (300 * ((int)work->unk_0018 - (int)work->unk_0010)) / (int)work->unk_0018;
    if (value > 250) Unk0efff4_Unk_0f0098(&work->unk_00f8[5], value - 250);
    if (value > 180) Unk0efff4_Unk_0f0098(&work->unk_00f8[4], value - 180);
    if (value > 120) Unk0efff4_Unk_0f0098(&work->unk_00f8[3], value - 120);
    if (value > 70) Unk0efff4_Unk_0f0098(&work->unk_00f8[2], value - 70);
    if (value > 30) Unk0efff4_Unk_0f0098(&work->unk_00f8[1], value - 30);
    Unk0efff4_Unk_0f0098(&work->unk_00f8[0], value);
}

/* Set fields +0x40..+0x4c and register the original callback addresses for six entries. */
void func_020f019c(Unk0efff4Work *work)
{
    int index;
    work->unk_0040 = 31;
    work->unk_0044 = 4;
    work->unk_0048 = 0;
    work->unk_004c = 0;
    func_020f711c(work, work->unk_0040, -10, 0, 10, -10, 0, 0, func_020f04a4, 0, 0);
    index = Unk0cb0d0_Unk_0cb1f8() - 1;
    func_020f81cc(work->unk_0050, 6, index,
                  0, 1, 0, func_020f0510, func_020f05b4,
                  Unk0f0510_Unk_0f06a4, Unk0f0510_Unk_0f06d0);
    Unk0f81a4_SetUnkField9c(work->unk_0050, func_020f06f4);
}

/* Advance the work state; original switch handles states 2, 9 and 11 specially. */
void func_020f0264(Unk0efff4Work *work)
{
    func_020f7188(work);
    if (work->unk_0008 != 1) func_020f00dc(work);
    switch (work->unk_0008) {
    case 11: Unk0bc1a8_Unk_0bc9b4(work->unk_0040, 0); break;
    case 9: func_020f8264(work->unk_0050); work->unk_0008 = 10; break;
    case 2: func_020f7de4(work->unk_0040, 2); work->unk_0008 = 1; break;
    case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8: case 10: break;
    }
}

/* Submit up to six entries at x=74, y=25+15*i using their float slots and entry kinds. */
void func_020f0330(Unk0efff4Work *work)
{
    int offset, count, y, limit, i, kind, flag;
    Unk0f8448_Unk_0f8468(work->unk_0050);
    offset = Unk0f8448_GetUnkField8(work->unk_0050);
    count = Unk0f8448_GetUnkField0(work->unk_0050);
    if (work->unk_0008 == 1) return;
    func_02057df8();
    Unk0e8228_Unk_0e8e50();
    limit = work->unk_00f4;
    y = 25;
    if (limit > count) limit = count;
    for (i = 0; i < limit; i++) {
        int entry;
        func_02057e18(31);
        Unk0e8228_Unk_0e8e6c();
        entry = Unk0f8448_GetEntry(work->unk_0050, i);
        flag = work->unk_0010 == 0;
        switch (entry) {
        case 2: flag = 0;
        case 1: kind = 1; break;
        case 3: flag = 0;
        case 4: kind = 2; break;
        default: flag = 0; kind = 0; break;
        }
        func_020f5800(74, y, kind, work->unk_00f8[i], flag);
        if (flag) Unk0f51dc_Unk_0f5ab4(74, y);
        if (i + offset == 0 && Unk0e8228_Unk_0e8c68())
            Unk0f51dc_Unk_0f57d4(i, 74, y, kind, work->unk_00f8[i]);
        else
            func_020f5754(i, 74, y, kind, work->unk_00f8[i]);
        y += 15;
    }
    Unk0e8228_Thunk_02057534();
    Unk0e8228_Unk_0e8e7c();
}
