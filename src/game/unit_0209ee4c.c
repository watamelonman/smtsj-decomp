#include "GameState.h"
#include "types.h"

void func_02118c6c(void);
void Unk09ee4c_Thunk_02118c6c(void) { func_02118c6c(); }

extern u8 data_0213c190[];
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
