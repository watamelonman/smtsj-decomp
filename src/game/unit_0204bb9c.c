/* src/game/unit_0204bb9c.c: matched functions. */
#include "types.h"

/* Borrowed singleton layout; offsets are evidenced by the context accessors. */
typedef struct Unk04bb9cCtx {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u16 unk_000c;
    u16 unk_000e;
    u16 unk_0010;
    u8 pad_0012[0xa02];
    u32 unk_0a14;
    u32 unk_0a18;
    u8 pad_0a1c[0x4];
    u16 unk_0a20;
} Unk04bb9cCtx;

extern Unk04bb9cCtx *data_0215eea4;

/* Accept kinds 0, 2 and 32..34; the comparisons at 0x0204c13c establish this set. */
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

/* Translate coordinates using body +0x354 bytes 8/9 before requesting a 20-unit update. */
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

/* Store three halfwords at +0xc/+0xe/+0x10 and set +8, as evidenced by the stores in 0x0204c464; absent contexts are ignored. */
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

/* Report clear when the singleton is absent or its +8 word is zero (direct load/comparison evidence). */
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
/* Four-byte record: the low six bits encode kind, followed by three lookup keys. */
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

/* Search 96 packed records by their three byte fields and return the six-bit kind; 980 maps to field value zero. */
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

/* Store the word at singleton +0xa14 when present, evidenced by the direct store in this routine. */
void Unk04bb9c_SetCtxUnka14(u32 value)
{
    if (data_0215eea4 != 0) {
        data_0215eea4->unk_0a14 = value;
    }
}

/* Read the halfword at singleton +0xa20, or zero when absent, evidenced by the direct halfword load. */
u16 Unk04bb9c_GetCtxUnka20(void)
{
    if (data_0215eea4 == 0) {
        return 0;
    }
    return data_0215eea4->unk_0a20;
}

/* Return bits 16..19 of the queried object word at +4, or zero for a missing object; uses body +0x23c coordinates. */
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

/* Return bits 16..19 of the queried object word at +4, or zero for a missing object; uses body +0x354 coordinates. */
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

/* Read singleton +0xa14 as a signed word; the load at 0x0204ca2c and absent sentinel -1 are the evidence. */
s32 func_0204ca1c(void)
{
    if (data_0215eea4 == 0) {
        return -1;
    }
    return data_0215eea4->unk_0a14;
}

/* Read singleton +0xa18, with absent value 1; evidenced by 0x0204cb9c..0x0204cba0. */
u32 func_0204cb90(void)
{
    if (data_0215eea4 == 0) {
        return 1;
    }
    return data_0215eea4->unk_0a18;
}

/* Store the +0xa20 halfword when present; the strh at 0x0204cbbc establishes the width. */
void func_0204cbac(u16 value)
{
    if (data_0215eea4 != 0) {
        data_0215eea4->unk_0a20 = value;
    }
}
