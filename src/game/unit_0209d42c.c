#include "GameState.h"
#include "types.h"

extern u8 data_02176278[];
void func_02008848();
void Unk09d42c_Init_data_02176278(void)
{
    func_02008848(data_02176278, 0, 0x884);
}

int Unk09d42c_Unk_09d4bc(void)
{
    *(int *)(data_02176278 + 0x808) = 0;
    return *(int *)(data_02176278 + 0x800) > *(int *)(data_02176278 + 0x804);
}

int Unk09d42c_Unk_09d600(int arg0)
{
    if (arg0 == 0xff) {
        arg0 = 0;
    }
    return arg0;
}

extern u8 data_02176278[];
int Unk09d42c_Unk_09d4e0(void)
{
    return *(int *)(((int)data_02176278) + 0x800) == *(int *)(((int)data_02176278) + 0x804);
}

u32 Unk02e000_GetWorkArea(void);
u32 func_0203611c(u32 a, u32 b);

void Unk09d42c_Unk_09e2f4(u32 arg0)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    v = func_0203611c(*(u32 *)(Unk02e000_GetWorkArea() + 0x358), arg0);
    gs->root->unk_18 = v;
    gs->root->unk_14 = 4;
    gs->unk_73e8 = 1;
}

void Unk09d42c_Unk_09e2a4(u32 arg0)
{
    GameState *gs = GetGameState();
    u32 v;
    if (gs == 0) {
        return;
    }
    v = func_0203611c(*(u32 *)(Unk02e000_GetWorkArea() + 0x358), arg0);
    gs->root->unk_18 = v;
    gs->root->unk_14 = 2;
    gs->root->unk_0c = 0;
    gs->unk_73e8 = 0;
}
