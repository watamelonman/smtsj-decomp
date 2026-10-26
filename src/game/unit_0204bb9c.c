/* src/game/unit_0204bb9c.c: matched functions. */
#include "types.h"

/* Borrowed singleton layout; offsets are evidenced by the context accessors. */
typedef struct Unk04bb9cCtx {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u16 unk_000c;
    u16 unk_000e;
    u16 unk_0010;
    u8 pad_0012[0x8a2];
    s16 unk_08b4[32];
    u16 unk_08f4[32];
    u16 unk_0934[32];
    s16 unk_0974[32];
    u8 unk_09b4[32];
    u8 unk_09d4[32];
    u8 unk_09f4[32];
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

void func_0204b6f4(void);

/* Free-slot insertion: find the first slot whose signed halfword at +0x8b4 is
   negative, clear it, and record `a` at +0x8f4, `b` at +0x934 and -1 at +0x974.
   The ldrsh/strh and -1 sentinel stores in 0x0204c4cc are the evidence.
   Returns the slot index, or -1 when the singleton is absent or all 32 slots are used. */
int func_0204c4cc(int a, int b)
{
    s8 i;

    if (data_0215eea4 == 0) {
        return -1;
    }
    for (i = 0; i < 32; i++) {
        if (data_0215eea4->unk_08b4[i] < 0) {
            data_0215eea4->unk_08b4[i] = 0;
            data_0215eea4->unk_08f4[i] = a;
            data_0215eea4->unk_0934[i] = b;
            data_0215eea4->unk_0974[i] = -1;
            return i;
        }
    }
    return -1;
}

/* Same free-slot search as func_0204c4cc, but the third value stored at +0x974 is
   the caller's `c` instead of the -1 sentinel (0x0204c564 stores r2 there).
   Returns the slot index, or -1 when the singleton is absent or all slots are used. */
int func_0204c564(int a, int b, int c)
{
    s8 i;

    if (data_0215eea4 == 0) {
        return -1;
    }
    for (i = 0; i < 32; i++) {
        if (data_0215eea4->unk_08b4[i] < 0) {
            data_0215eea4->unk_08b4[i] = 0;
            data_0215eea4->unk_08f4[i] = a;
            data_0215eea4->unk_0934[i] = b;
            data_0215eea4->unk_0974[i] = c;
            return i;
        }
    }
    return -1;
}

/* Release the first occupied entry at +0x9b4 whose keys at +0x9d4/+0x9f4 match
   (`a`, `b`), clearing all three parallel byte arrays and committing the change
   through func_0204b6f4; the byte compares and zero stores at 0x0204c780 are the evidence. */
void func_0204c780(int a, int b)
{
    s32 i;

    if (data_0215eea4 == 0) {
        return;
    }
    for (i = 0; i < 32; i++) {
        if (data_0215eea4->unk_09b4[i] != 0 &&
            a == data_0215eea4->unk_09d4[i] &&
            b == data_0215eea4->unk_09f4[i]) {
            data_0215eea4->unk_09b4[i] = 0;
            data_0215eea4->unk_09d4[i] = 0;
            data_0215eea4->unk_09f4[i] = 0;
            func_0204b6f4();
            return;
        }
    }
}

/* Release the packed record whose kind is non-zero and whose three byte keys match
   (`a`, `b`, and `c`, where 980 maps to zero), clearing its kind and all three keys
   and committing via func_0204b6f4; the `and 63` clear at 0x0204c970 is the evidence. */
void func_0204c8f4(int a, int b, int c)
{
    s8 i;

    for (i = 0; i < 96; i++) {
        Unk04bb9cEnt *e = Unk02e000_Unk_02e89c(i);
        if (e->kind != 0 && e->a == a && e->b == b && e->c == (c == 980 ? 0 : c)) {
            e->kind = 0;
            e->a = 0;
            e->b = 0;
            e->c = 0;
            func_0204b6f4();
            return;
        }
    }
}
