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
