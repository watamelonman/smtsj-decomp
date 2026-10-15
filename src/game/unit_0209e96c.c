#include "GameState.h"
#include "types.h"

u32 Unk095560_Unk_095764(u32 a);
u32 func_0204fde0(void);
u32 func_0204fe18(u32 a);
void func_02052d7c(u32 a, u32 b);

void Unk09e96c_Unk_09e9cc(void)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    Unk095560_Unk_095764(0);
    v = func_0204fde0();
    gs->unk_7430 = v;
    gs->unk_7434 = 0;
    gs->unk_7438 = 0;
    func_02052d7c(gs->unk_7430, gs->unk_7434);
    gs->unk_73e8 = 0xe;
}

void Unk09e96c_Unk_09e96c(u32 arg0, u32 arg1)
{
    GameState *gs = GetGameState();
    u32 v;
    u32 w;
    if (gs == 0) {
        return;
    }
    v = Unk095560_Unk_095764(arg0);
    w = func_0204fde0();
    gs->unk_7430 = w;
    v = func_0204fe18(v);
    gs->unk_7434 = v;
    gs->unk_7438 = arg1;
    func_02052d7c(gs->unk_7430, gs->unk_7434);
    gs->unk_73e8 = 0xe;
}
