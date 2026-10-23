/* Mode changers that write the GameState transition block around 0x73CC. */
#include "GameState.h"
#include "types.h"

void Unk09974c_Unk_09974c(void *sub);
void Unk11f2d0_Unk_11f2d0(void *sub);
void func_0203480c(void *obj, int a);
void Unk02e000_SetBit_02e968(u32 a, int b);

void func_02052590(u32 kind, u32 value, u32 count);
void func_020a4eb0(u32 kind, u32 value, u32 count);

/* Store the supplied transition value and request mode 7; absent state is ignored. */
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

/* Clamp count to 1..4 and remap kind for the request; flag 1 also
 * submits the paired request and selects mode 9, otherwise mode 8. */
void func_0209e7fc(u32 value, u32 count, u32 kind, u32 flag)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    if (count < 1) {
        count = 1;
    } else if (count > 4) {
        count = 4;
    }
    switch (kind) {
    case 0:
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 4;
        break;
    }
    func_02052590(kind, value, count);
    if (flag == 1) {
        func_020a4eb0(kind == 3 ? 2 : 3, value, count);
        gs->unk_73e8 = 9;
    } else {
        gs->unk_73e8 = 8;
    }
}

/* Set the transition flags and request mode 11 when game state exists. */
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

/* Store the low byte of the selector, set its bit, and request mode 13. */
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

/* Reset the body and two embedded work objects before requesting mode 10. */
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
