#include "GameState.h"
#include "types.h"

void func_02118c6c(void);
void Unk09ee4c_Thunk_02118c6c(void) { func_02118c6c(); }

extern u8 data_0213c190[];
void func_0204f1f8(int v, u32 b, u32 c, u8 *d);
void Unk09ee4c_Call_0204f1f8(int base, u32 b, u32 c, u8 *d)
{
    int v = d[1] + base;
    if (v < 0) {
        v = 0;
    }
    func_0204f1f8(v, b, c, d);
}

typedef struct Unk09ee4cObj {
    u8 pad_0000[0x64];
    u32 unk_64;
} Unk09ee4cObj;

void func_0204f68c(u32 a, u32 b, u32 *p);

void Unk09ee4c_Call_0204f68c(u32 a, u32 b, Unk09ee4cObj *o)
{
    if (o->unk_64 == 0) {
        return;
    }
    func_0204f68c(a, b, &o->unk_64);
}

int Unk09ee4c_Unk_0a03b8(int arg0)
{
    return arg0 * 0x18 + ((int)data_0213c190);
}

void ScanVisor_Unk_0a2ae8(u32 a, int b);
void Unk09ee4c_Unk_09ef50(u32 arg0)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    ScanVisor_Unk_0a2ae8(arg0, 2);
    gs->unk_73e8 = 0x14;
}

void Unk09ee4c_Unk_09ee4c(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_7400 = 0;
    gs->root->unk_5c = 1;
    gs->unk_73e8 = 0x12;
}

void Unk11f2d0_Unk_11f308(void *sub, u32 a);
void Unk09ee4c_Unk_09ef80(u32 arg0)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    Unk11f2d0_Unk_11f308(gs->unk_7598, arg0);
    gs->unk_73e8 = 0x15;
}

int Unk1124f0_Unk_11259c();
void Unk09ee4c_Unk_09efb4(u32 id)
{
    u8 *gs = (u8 *)GetGameState();
    void (**ent)(u32);
    if (gs == 0) {
        return;
    }
    ent = (void (**)(u32))Unk1124f0_Unk_11259c(id);
    if (ent[0] != 0) {
        ent[0](id);
    }
    FIELD(u32, gs + 28672, 1000) = 22;
    FIELD(u32, gs + 28672, 1004) = id;
}

u16 Unk09ee4c_GetField3c0Bits(void)
{
    u8 *gs = (u8 *)GetGameState();
    if (gs == 0) {
        return 0;
    }
    return (u16)((FIELD(u32, gs + 28672, 960) << 12) >> 22);
}

int func_02044ec4();
int func_020a1740();
int func_0209f550();
void Unk044904_ClearSlotsUnk1de();
void func_0209f034();
int func_0209f5d8(u32 a, u32 id)
{
    u8 *e;
    if (((id >> 16) & 0xff) != 2) {
        return -1;
    }
    e = (u8 *)func_02044ec4(id);
    e = (u8 *)func_020a1740(FIELD(u16, e + 256, 216));
    return func_0209f550(a, id, e[3], 0);
}

void func_0209fd14(u32 a, u32 b)
{
    int j;
    Unk044904_ClearSlotsUnk1de(a);
    for (j = 0; j < 4; j++) {
        func_0209f034(0, a, a, b, 1);
        b += 22;
    }
}
