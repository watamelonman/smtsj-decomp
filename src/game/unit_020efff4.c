#include "types.h"

/* Borrowed 0x110-byte work area; offsets follow this unit's loads/stores. */
typedef struct Unk0efff4Work {
    u32 size;
    u32 unk_0004;
    s32 unk_0008;
    void (*unk_000c)(void);
    void (*unk_0010)(struct Unk0efff4Work *work);
    void (*unk_0014)(void);
    u32 unk_0018;
    void (*unk_001c)(void);
    void (*unk_0020)(void);
    u8 pad_0024[4];
    s32 unk_0028;
    u8 pad_002c[0x18];
    u32 unk_0044;
    u8 pad_0048[8];
    u8 unk_0050[0xa4];
    u32 unk_00f4;
    u32 unk_00f8[6];
} Unk0efff4Work;

void func_020f0264(void);
void func_020f0330(void);
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
