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

void func_0209f534(u32 a, u32 b, Unk09ee4cObj *o)
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
