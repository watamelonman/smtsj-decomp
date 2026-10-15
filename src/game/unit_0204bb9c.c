/* src/game/unit_0204bb9c.c: matched functions. */
#include "types.h"

typedef struct Unk04bb9cCtx {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u16 unk_000c;
    u16 unk_000e;
    u16 unk_0010;
    u8 pad_0012[0xa02];
    u32 unk_0a14;
    u8 pad_0a18[0x8];
    u16 unk_0a20;
} Unk04bb9cCtx;

extern Unk04bb9cCtx *data_0215eea4;

int Unk04bb9c_IsKind02Or32to34(int x)
{
    if (x == 2 || x == 0 || (u32)(x - 32) <= 2) {
        return 1;
    }
    return 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int GameState_GetBody();
void Unk04bb9c_SetCtxUnk0c(s16 a, s16 b, u16 c);

void Unk04bb9c_Unk_04c404(int x, int y)
{
    u8 *a;
    u8 *b;
    if (data_0215eea4 == 0) {
        return;
    }
    a = (u8 *)GameState_GetBody();
    b = (u8 *)GameState_GetBody();
    Unk04bb9c_SetCtxUnk0c((s16)(x - FIELD(u8, FIELD(u8 *, a, 852), 8)), (s16)(y - FIELD(u8, FIELD(u8 *, b, 852), 9)), 20);
}

void Unk04bb9c_SetCtxUnk0c(s16 a, s16 b, u16 c)
{
    if (data_0215eea4 == 0) {
        return;
    }
    data_0215eea4->unk_0008 = 1;
    data_0215eea4->unk_000c = a;
    data_0215eea4->unk_000e = b;
    data_0215eea4->unk_0010 = c;
}

int Unk04bb9c_IsCtxUnk8Clear(void)
{
    if (data_0215eea4 == 0) {
        return 1;
    }
    return data_0215eea4->unk_0008 == 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk04bb9cEnt {
    u8 kind : 6;
    u8 hi : 2;
    u8 a;
    u8 b;
    u8 c;
} Unk04bb9cEnt;
Unk04bb9cEnt *Unk02e000_Unk_02e89c(int i);
int GetGameState();
int GameState_GetBody();
u8 *Unk038fbc_Unk_039160(u8 **o, int x, int y);

int Unk04bb9c_Unk_04c98c(int a, int b, int c)
{
    s8 i;
    for (i = 0; i < 96; i++) {
        Unk04bb9cEnt *e = Unk02e000_Unk_02e89c(i);
        if (e->a == a && e->b == b && e->c == (c == 980 ? 0 : c)) {
            return e->kind;
        }
    }
    return 0;
}

void Unk04bb9c_SetCtxUnka14(u32 value)
{
    if (data_0215eea4 != 0) {
        data_0215eea4->unk_0a14 = value;
    }
}

u16 Unk04bb9c_GetCtxUnka20(void)
{
    if (data_0215eea4 == 0) {
        return 0;
    }
    return data_0215eea4->unk_0a20;
}

u8 Unk04bb9c_Unk_04cbe8(int x, int y)
{
    u8 *g = (u8 *)GetGameState();
    u8 *a = (u8 *)GameState_GetBody();
    u8 *b = (u8 *)GameState_GetBody();
    u8 *o = Unk038fbc_Unk_039160((u8 **)(g + 576), x + FIELD(u8, FIELD(u8 *, a, 572), 8), y + FIELD(u8, FIELD(u8 *, b, 572), 9));
    if (o == 0) {
        return 0;
    }
    return (FIELD(u32, o, 4) << 12) >> 28;
}

u8 Unk04bb9c_Unk_04cc4c(int x, int y)
{
    u8 *g = (u8 *)GetGameState();
    u8 *a = (u8 *)GameState_GetBody();
    u8 *b = (u8 *)GameState_GetBody();
    u8 *o = Unk038fbc_Unk_039160((u8 **)(g + 856), x + FIELD(u8, FIELD(u8 *, a, 852), 8), y + FIELD(u8, FIELD(u8 *, b, 852), 9));
    if (o == 0) {
        return 0;
    }
    return (FIELD(u32, o, 4) << 12) >> 28;
}
