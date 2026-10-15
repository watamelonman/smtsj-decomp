#include "GameState.h"
#include "types.h"

int func_02035b08();
int Unk0e651c_Unk_0e666c();
int func_021124f0(u16 a, u32 b, u32 c)
{
    int r = 0;
    if (a == func_02035b08(8, 10) && b == 23 && c == 10) {
        if (Unk0e651c_Unk_0e666c(344) == 1) {
            r = 1;
        }
    }
    return r;
}

int Unk1124f0_GetConst1(void) { return 1; }

extern u8 data_0213cb24[];
int Unk1124f0_Unk_11259c(int arg0)
{
    return ((int)data_0213cb24) + arg0 * 8;
}

void func_0209a884(void *a, void *b);
void Unk1124f0_Unk_112538(void)
{
    GameState *gs = GetGameState();
    if (gs == 0) {
        return;
    }
    func_0209a884(gs->unk_38e8, (u8 *)gs + 4);
}

u32 Unk02e000_GetWorkArea(void);
int func_021124f0(u16 a, u32 b, u32 c);
u32 Unk1124f0_Unk_112564(u32 arg0, u32 arg1)
{
    int value1;
    u32 value2;
    value2 = 0;
    value1 = Unk02e000_GetWorkArea();
    value1 = func_021124f0(*(u16 *)(value1 + 0x35c), arg0, arg1);
    if (value1 == 1) {
        value2 = 2;
    }
    return value2;
}

int func_02115bf4(void);
int func_02116f84(u32 a, u32 b, u32 c);
int Unk1124f0_Unk_1125ac(u32 arg0, u32 arg1, u32 arg2)
{
    int value1;
    int value2;
    value1 = func_02115bf4();
    value2 = func_02116f84(arg0, arg1, arg2);
    return value1 != 0 && value2 != 0;
}
