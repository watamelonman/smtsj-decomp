/* Mode changers that write the GameState transition block around 0x73CC. */
#include "GameState.h"
#include "types.h"

void Unk09974c_Unk_09974c(void *sub);
void Unk11f2d0_Unk_11f2d0(void *sub);
void func_0203480c(void *obj, int a);
void Unk02e000_SetBit_02e968(u32 a, int b);

void Unk09e72c_Unk_09e72c(u32 arg0)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73d0 = arg0;
    gs->unk_73cc = 0xc;
    gs->unk_73e8 = 7;
}

void Unk09e72c_Unk_09e8f0(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73e4 = 0;
    gs->unk_73d8 = 1;
    gs->unk_73e8 = 0xb;
}

void Unk09e72c_Unk_09e920(u32 arg0)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73cc = 6;
    gs->root->unk_04 = 0;
    gs->unk_7480 = (u8)arg0;
    Unk02e000_SetBit_02e968(arg0, 1);
    gs->unk_73e8 = 0xd;
}

void Unk09e72c_Unk_09e89c(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    func_0203480c((u8 *)gs + 4, 0);
    Unk09974c_Unk_09974c(gs->unk_7550);
    Unk11f2d0_Unk_11f2d0(gs->unk_7598);
    gs->unk_73e4 = 1;
    gs->unk_73d8 = 0;
    gs->unk_73e8 = 10;
}
