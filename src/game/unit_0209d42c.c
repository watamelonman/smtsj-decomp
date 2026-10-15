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

int func_020445d0();
int func_0204fde0();
int func_0204fe18();
void func_02052da0();
int Unk02f2a8_GetCell38e8();
int Unk09a268_Unk_09a844();
int Unk1124f0_Unk_11259c();
u8 Unk09d42c_MapId(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b != 0) {
        switch (a) {
        case 62:
            return 65;
        case 63:
            return 66;
        case 64:
            return 67;
        }
    }
    return a;
}

u8 *Unk09d42c_GetTable0Entry(int i)
{
    int t = func_020445d0(9, 0);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 2;
}

u8 *Unk09d42c_GetTable1Entry(int i)
{
    int t = func_020445d0(9, 1);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 106;
}

u8 *Unk09d42c_GetTable2Entry(int i)
{
    int t = func_020445d0(9, 2);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 24;
}

u8 *Unk09d42c_GetTable3Entry(int i)
{
    int t = func_020445d0(9, 3);
    u8 *base = (u8 *)func_0204fde0(t);
    if (i < 0 || (u32)i >= (u32)func_0204fe18(t)) {
        return base;
    }
    return base + i * 52;
}

int Unk09d42c_Unk_09df70(u8 *p)
{
    int r = 0;
    u8 *cell;
    func_02052da0(p);
    cell = (u8 *)Unk02f2a8_GetCell38e8(FIELD(s8, p + 29696, 130), FIELD(s8, p + 29696, 131));
    FIELD(u16, cell, 2) += 1;
    if (Unk09a268_Unk_09a844() == 1) {
        r = 1;
    }
    return r;
}

int Unk09d42c_Unk_09e080(u8 *p)
{
    int r = 1;
    int (**ent)(void) = (int (**)(void))Unk1124f0_Unk_11259c(FIELD(u32, p + 28672, 1004));
    if (ent[1] != 0) {
        r = ent[1]();
    }
    return r;
}

int Unk09d42c_Unk_09e274(void)
{
    u8 *gs = (u8 *)GetGameState();
    if (gs == 0) {
        return 1;
    }
    return FIELD(s32, gs + 28672, 1000) == -1;
}

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
