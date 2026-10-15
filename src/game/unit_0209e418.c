#include "GameState.h"
#include "types.h"

void Unk09e418_Unk_09e468(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73cc = 10;
    gs->root->unk_04 = 0;
    gs->unk_73e8 = 5;
}

void Unk09e418_Unk_09e418(u16 arg0, u16 arg1, u16 arg2)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    gs->unk_73cc = 9;
    gs->root->unk_04 = 0;
    gs->unk_73f4 = arg0;
    gs->unk_73f6 = arg1;
    gs->unk_73f8 = arg2;
    gs->unk_73e8 = 4;
}
