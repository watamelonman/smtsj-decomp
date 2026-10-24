/* src/game/unit_0206fb70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06fb70Work {
    u8 pad_0000[0x120];
    s32 unk_0120;
} Unk06fb70Work;



int func_0206d68c(int mode, u32 value, int scale);
/* ARM 0x020717c0 adds func_0206d68c(2, value, 100) to field +0x120. */
void Unk06fb70_Unk_0717c0(Unk06fb70Work *arg0, u32 arg1){
  int tmp1;
  tmp1 = func_0206d68c(2,arg1,100);
  arg0->unk_0120 = arg0->unk_0120 + tmp1;
  return;
}

int func_0200219c(s32 numerator, s32 denominator);
void func_02007e94(void);
/* ARM 0x0206fb70 divides the value delta by the time delta, both scaled
 * by 4096; a zero time delta first calls 0x02007e94. */
int Unk06fb70_Unk_06fb70(int arg0,int arg1,int arg2,int arg3)
{
  if (arg1 - arg0 == 0) {
    func_02007e94();
  }
  return func_0200219c((arg3 - arg2) * 0x1000,(arg1 - arg0) * 0x1000);
}



void Unk06fb70_Unk_070094();
void Unk06fb70_Unk_070114();
void Unk06fb70_Unk_070168();
void Unk06fb70_Unk_0701bc();
void Unk06fb70_Unk_070210();
void Unk06fb70_Unk_070264();
void Unk06fb70_Unk_0702b8();
void Unk06fb70_Unk_07030c();
void Unk06fb70_Unk_070360();
/* decompiler-derived */
void Unk06fb70_Unk_06feb4(u32 arg0,u32 arg1)
{
  Unk06fb70_Unk_070094();
  Unk06fb70_Unk_070114(arg0,arg1);
  Unk06fb70_Unk_070168(arg0,arg1);
  Unk06fb70_Unk_0701bc(arg0,arg1);
  Unk06fb70_Unk_070210(arg0,arg1);
  Unk06fb70_Unk_070264(arg0,arg1);
  Unk06fb70_Unk_0702b8(arg0,arg1);
  Unk06fb70_Unk_07030c(arg0,arg1);
  Unk06fb70_Unk_070360(arg0,arg1);
  return;
}

void Unk06fb70_Unk_0705f8();
void Unk06fb70_Unk_070758();
void Unk06fb70_Unk_070834();
int func_0206fb9c(s32 t0, s32 t1, float f0, float f1);
void Unk06fb70_Unk_070950();
void Unk06fb70_Unk_070a6c();
void Unk06fb70_Unk_070b88();
void Unk06fb70_Unk_070cc0();
void Unk06fb70_Unk_070df8();
void Unk06fb70_Unk_070f30();
/* decompiler-derived */
void Unk06fb70_Unk_06ff28(u32 arg0,u32 arg1)
{
  Unk06fb70_Unk_0705f8();
  Unk06fb70_Unk_070758(arg0,arg1);
  Unk06fb70_Unk_070834(arg0,arg1);
  Unk06fb70_Unk_070950(arg0,arg1);
  Unk06fb70_Unk_070a6c(arg0,arg1);
  Unk06fb70_Unk_070b88(arg0,arg1);
  Unk06fb70_Unk_070cc0(arg0,arg1);
  Unk06fb70_Unk_070df8(arg0,arg1);
  Unk06fb70_Unk_070f30(arg0,arg1);
  return;
}

/* ARM 0x020713fc clamps the sum toward lim according to the sign of d;
 * p owns a writable signed accumulator in the same units as d and lim. */
void Unk06fb70_AddClamped(s32 *p, s32 d, s32 lim)
{
    *p += d;
    if (d >= 0) {
        if (*p > lim) {
            *p = lim;
        }
    } else if (*p < lim) {
        *p = lim;
    }
}

void func_0207142c(int a, int b, int c, int d, int e, int option, int f, int g);
void func_02071898(int a, int b, int c, int d, int e, int option, int f, int g);
void func_020703b4(void *a, void *b, void *c, void *d, void *e, void *f, void *g, void *h);
/* Target ARM call to 0207142c forwards seven words, inserting zero as word six. */
void Unk06fb70_Call_07142c(int a, int b, int c, int d, int e, int f, int g)
{
    func_0207142c(a, b, c, d, e, 0, f, g);
}

/* Target ARM call to 02071898 forwards seven words, inserting zero as word six. */
void Unk06fb70_Call_071898(int a, int b, int c, int d, int e, int f, int g)
{
    func_02071898(a, b, c, d, e, 0, f, g);
}

/* ARM 0x02071d28 forwards views at +0x16c, +0x2c, +0x28, +0x30,
 * +0, +0xc, +0x18 and +0x34; o must cover all these object fields. */
void Unk06fb70_Call_0703b4(u8 *o)
{
    func_020703b4(o + 364, o + 44, o + 40, o + 48, o, o + 12, o + 24, o + 52);
}

typedef struct Unk06fb70Key {
    s32 t[9];                   /* +0x00: per-channel time */
    u8 c[4];                    /* +0x24 */
    float f0;                   /* +0x28 */
    s16 h0;                     /* +0x2c */
    u8 pad_2e[2];
    float f1;                   /* +0x30 */
    float f2;                   /* +0x34 */
    s16 h1;                     /* +0x38 */
    s16 h2;                     /* +0x3a */
    s16 h3;                     /* +0x3c */
    u8 pad_3e[2];
    s32 unk_40;                 /* +0x40 */
} Unk06fb70Key;
typedef struct Unk06fb70Anim {
    u8 pad_000[16];
    Unk06fb70Key keys[4];       /* +0x10: count from the < 4 bounds */
    u8 pad_120[196];
    s32 pos[11];                /* +0x1e4: channel 0 uses [0..2], channel n>0 uses [n+2] */
    s32 vel[11];                /* +0x210 */
    s32 max[11];                /* +0x23c */
    u8 pad_268[83];
    s8 state[9];                /* +0x2bb: current key per channel */
    u8 pad_2c4[4];
    s32 tick[9];                /* +0x2c8 */
    u8 pad_2ec[4];
    s32 limit[9];               /* +0x2f0 */
} Unk06fb70Anim;
void Unk06fb70_AddClamped(s32 *p, s32 d, s32 lim);

void Unk06fb70_Unk_0705f8(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s = a->state[0];
    int k = 1;
    if (s + 1 >= 4) {
        a->state[0] = 4;
        return;
    }
    for (; s + k < 4; k++, s = a->state[0]) {
        a->limit[0] = b->keys[s + k].t[0] - b->keys[s].t[0];
        if (a->limit[0] > 0) {
            a->vel[0] = Unk06fb70_Unk_06fb70(a->keys[a->state[0]].t[0], a->keys[a->state[0] + k].t[0], a->keys[a->state[0]].c[0], a->keys[a->state[0] + k].c[0]);
            a->vel[1] = Unk06fb70_Unk_06fb70(a->keys[a->state[0]].t[0], a->keys[a->state[0] + k].t[0], a->keys[a->state[0]].c[1], a->keys[a->state[0] + k].c[1]);
            a->vel[2] = Unk06fb70_Unk_06fb70(a->keys[a->state[0]].t[0], a->keys[a->state[0] + k].t[0], a->keys[a->state[0]].c[2], a->keys[a->state[0] + k].c[2]);
            a->max[0] = a->keys[a->state[0] + k].c[0] << 12;
            a->max[1] = a->keys[a->state[0] + k].c[1] << 12;
            a->max[2] = a->keys[a->state[0] + k].c[2] << 12;
            a->state[0] = a->state[0] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070758(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[1] + 1 >= 4) {
        a->state[1] = 4;
    }
    s = a->state[1];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[1]) {
        a->limit[1] = b->keys[s + k].t[1] - b->keys[s].t[1];
        if (a->limit[1] > 0) {
            a->vel[3] = Unk06fb70_Unk_06fb70(a->keys[a->state[1]].t[1], a->keys[a->state[1] + k].t[1], a->keys[a->state[1]].c[3], a->keys[a->state[1] + k].c[3]);
            a->max[3] = a->keys[a->state[1] + k].c[3] << 12;
            a->state[1] = a->state[1] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070094(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[0] >= 4) {
        return;
    }
    if (++a->tick[0] > a->limit[0]) {
        a->tick[0] = 0;
        a->vel[0] = 0;
        a->vel[1] = 0;
        a->vel[2] = 0;
        Unk06fb70_Unk_0705f8(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[0], a->vel[0], a->max[0]);
    Unk06fb70_AddClamped(&a->pos[1], a->vel[1], a->max[1]);
    Unk06fb70_AddClamped(&a->pos[2], a->vel[2], a->max[2]);
}

/* ARM 0x02070114 advances channel 1 while its signed state is below 4;
 * on expiry resets tick/velocity and selects the next key, else clamps position. */
void Unk06fb70_Unk_070114(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[1] >= 4) {
        return;
    }
    if (++a->tick[1] > a->limit[1]) {
        a->tick[1] = 0;
        a->vel[3] = 0;
        Unk06fb70_Unk_070758(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[3], a->vel[3], a->max[3]);
}

/* ARM 0x02070168 advances channel 2 while its signed state is below 4;
 * on expiry resets tick/velocity and selects the next key, else clamps position. */
void Unk06fb70_Unk_070168(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[2] >= 4) {
        return;
    }
    if (++a->tick[2] > a->limit[2]) {
        a->tick[2] = 0;
        a->vel[4] = 0;
        Unk06fb70_Unk_070834(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[4], a->vel[4], a->max[4]);
}

void Unk06fb70_Unk_0701bc(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[3] >= 4) {
        return;
    }
    if (++a->tick[3] > a->limit[3]) {
        a->tick[3] = 0;
        a->vel[5] = 0;
        Unk06fb70_Unk_070950(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[5], a->vel[5], a->max[5]);
}

void Unk06fb70_Unk_070210(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[4] >= 4) {
        return;
    }
    if (++a->tick[4] > a->limit[4]) {
        a->tick[4] = 0;
        a->vel[6] = 0;
        Unk06fb70_Unk_070a6c(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[6], a->vel[6], a->max[6]);
}

void Unk06fb70_Unk_070264(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[5] >= 4) {
        return;
    }
    if (++a->tick[5] > a->limit[5]) {
        a->tick[5] = 0;
        a->vel[7] = 0;
        Unk06fb70_Unk_070b88(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[7], a->vel[7], a->max[7]);
}

void Unk06fb70_Unk_0702b8(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[6] >= 4) {
        return;
    }
    if (++a->tick[6] > a->limit[6]) {
        a->tick[6] = 0;
        a->vel[8] = 0;
        Unk06fb70_Unk_070cc0(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[8], a->vel[8], a->max[8]);
}

void Unk06fb70_Unk_07030c(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[7] >= 4) {
        return;
    }
    if (++a->tick[7] > a->limit[7]) {
        a->tick[7] = 0;
        a->vel[9] = 0;
        Unk06fb70_Unk_070df8(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[9], a->vel[9], a->max[9]);
}

void Unk06fb70_Unk_070360(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[8] >= 4) {
        return;
    }
    if (++a->tick[8] > a->limit[8]) {
        a->tick[8] = 0;
        a->vel[10] = 0;
        Unk06fb70_Unk_070f30(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[10], a->vel[10], a->max[10]);
}

typedef struct Unk06fb70Mgr {
    u8 pad_000[0x24];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_034[0x1f0];
    u32 *unk_224;
    u8 pad_228[4];
    s32 cur;                    /* +0x22c */
    s32 end;                    /* +0x230 */
    u32 objs[50];               /* +0x234: count from the % 50 / < 50 bounds */
} Unk06fb70Mgr;
void func_0207126c();
void func_02071334();
void Unk06ae94_Unk_06c0b0();
void func_02061424();

void Unk06fb70_Unk_070500(void *o, s32 *tick, s8 *state, s32 *limit, s32 *pos, s32 *vel, s32 *max)
{
    if (*state >= 4) {
        return;
    }
    if (++*tick > *limit) {
        *tick = 0;
        *vel = 0;
        func_0207126c(o, state, limit, vel, max);
        return;
    }
    Unk06fb70_AddClamped(pos, *vel, *max);
}

void Unk06fb70_Unk_07057c(void *o, s32 *tick, s8 *state, s32 *limit, s32 *pos, s32 *vel, s32 *max)
{
    if (*state >= 4) {
        return;
    }
    if (++*tick > *limit) {
        *tick = 0;
        *vel = 0;
        func_02071334(o, state, limit, vel, max);
        return;
    }
    Unk06fb70_AddClamped(pos, *vel, *max);
}

void Unk06fb70_Unk_070834(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[2] + 1 >= 4) {
        a->state[2] = 4;
    }
    s = a->state[2];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[2]) {
        a->limit[2] = b->keys[s + k].t[2] - b->keys[s].t[2];
        if (a->limit[2] > 0) {
            a->vel[4] = func_0206fb9c(a->keys[a->state[2]].t[2], a->keys[a->state[2] + k].t[2], a->keys[a->state[2]].f0, a->keys[a->state[2] + k].f0);
            a->max[4] = (s32)(a->keys[a->state[2] + k].f0 > 0.0f
                                  ? 0.5f + 4096.0f * a->keys[a->state[2] + k].f0
                                  : 4096.0f * a->keys[a->state[2] + k].f0 - 0.5f);
            a->state[2] = a->state[2] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070950(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[3] + 1 >= 4) {
        a->state[3] = 4;
    }
    s = a->state[3];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[3]) {
        a->limit[3] = b->keys[s + k].t[4] - b->keys[s].t[4];
        if (a->limit[3] > 0) {
            a->vel[5] = func_0206fb9c(a->keys[a->state[3]].t[4], a->keys[a->state[3] + k].t[4], a->keys[a->state[3]].f1, a->keys[a->state[3] + k].f1);
            a->max[5] = (s32)(a->keys[a->state[3] + k].f1 > 0.0f
                                  ? 0.5f + 4096.0f * a->keys[a->state[3] + k].f1
                                  : 4096.0f * a->keys[a->state[3] + k].f1 - 0.5f);
            a->state[3] = a->state[3] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070a6c(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[4] + 1 >= 4) {
        a->state[4] = 4;
    }
    s = a->state[4];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[4]) {
        a->limit[4] = b->keys[s + k].t[5] - b->keys[s].t[5];
        if (a->limit[4] > 0) {
            a->vel[6] = func_0206fb9c(a->keys[a->state[4]].t[5], a->keys[a->state[4] + k].t[5], a->keys[a->state[4]].f2, a->keys[a->state[4] + k].f2);
            a->max[6] = (s32)(a->keys[a->state[4] + k].f2 > 0.0f
                                  ? 0.5f + 4096.0f * a->keys[a->state[4] + k].f2
                                  : 4096.0f * a->keys[a->state[4] + k].f2 - 0.5f);
            a->state[4] = a->state[4] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070b88(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[5] + 1 >= 4) {
        a->state[5] = 4;
    }
    s = a->state[5];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[5]) {
        a->limit[5] = b->keys[s + k].t[3] - b->keys[s].t[3];
        if (a->limit[5] > 0) {
            if (a->keys[a->state[5] + k].h0 != 0 && a->keys[a->state[5] + k].unk_40 > 0) {
                a->keys[a->state[5] + k].h0 -= func_0206d68c(2, a->keys[a->state[5] + k].unk_40, 1) >> 12;
            }
            a->vel[7] = Unk06fb70_Unk_06fb70(a->keys[a->state[5]].t[3], a->keys[a->state[5] + k].t[3], a->keys[a->state[5]].h0, a->keys[a->state[5] + k].h0);
            a->max[7] = a->keys[a->state[5] + k].h0 << 12;
            a->state[5] = a->state[5] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070cc0(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[6] + 1 >= 4) {
        a->state[6] = 4;
    }
    s = a->state[6];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[6]) {
        a->limit[6] = b->keys[s + k].t[6] - b->keys[s].t[6];
        if (a->limit[6] > 0) {
            if (a->keys[a->state[6] + k].h1 != 0 && a->keys[a->state[6] + k].unk_40 > 0) {
                a->keys[a->state[6] + k].h1 -= func_0206d68c(2, a->keys[a->state[6] + k].unk_40, 1) >> 12;
            }
            a->vel[8] = Unk06fb70_Unk_06fb70(a->keys[a->state[6]].t[6], a->keys[a->state[6] + k].t[6], a->keys[a->state[6]].h1, a->keys[a->state[6] + k].h1);
            a->max[8] = a->keys[a->state[6] + k].h1 << 12;
            a->state[6] = a->state[6] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070df8(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[7] + 1 >= 4) {
        a->state[7] = 4;
    }
    s = a->state[7];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[7]) {
        a->limit[7] = b->keys[s + k].t[7] - b->keys[s].t[7];
        if (a->limit[7] > 0) {
            if (a->keys[a->state[7] + k].h2 != 0 && a->keys[a->state[7] + k].unk_40 > 0) {
                a->keys[a->state[7] + k].h2 -= func_0206d68c(2, a->keys[a->state[7] + k].unk_40, 1) >> 12;
            }
            a->vel[9] = Unk06fb70_Unk_06fb70(a->keys[a->state[7]].t[7], a->keys[a->state[7] + k].t[7], a->keys[a->state[7]].h2, a->keys[a->state[7] + k].h2);
            a->max[9] = a->keys[a->state[7] + k].h2 << 12;
            a->state[7] = a->state[7] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_070f30(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    int s;
    int k = 1;
    if (a->state[8] + 1 >= 4) {
        a->state[8] = 4;
    }
    s = a->state[8];
    if (s + 1 >= 4) {
        return;
    }
    for (; s + k < 4; k++, s = a->state[8]) {
        a->limit[8] = b->keys[s + k].t[8] - b->keys[s].t[8];
        if (a->limit[8] > 0) {
            if (a->keys[a->state[8] + k].h3 != 0 && a->keys[a->state[8] + k].unk_40 > 0) {
                a->keys[a->state[8] + k].h3 -= func_0206d68c(2, a->keys[a->state[8] + k].unk_40, 1) >> 12;
            }
            a->vel[10] = Unk06fb70_Unk_06fb70(a->keys[a->state[8]].t[8], a->keys[a->state[8] + k].t[8], a->keys[a->state[8]].h3, a->keys[a->state[8] + k].h3);
            a->max[10] = a->keys[a->state[8] + k].h3 << 12;
            a->state[8] = a->state[8] + k;
            return;
        }
    }
}

void Unk06fb70_Unk_071844(Unk06fb70Mgr *m)
{
    int i;
    if (m == 0) {
        return;
    }
    for (i = 0; i < 50; i++) {
        Unk06ae94_Unk_06c0b0(m->objs[i]);
    }
    m->unk_24 = 0;
    m->unk_28 = 0;
    m->unk_2c = 0;
    m->unk_30 = 0;
    if (m->unk_224 != 0) {
        *m->unk_224 = 0;
    }
    func_02061424(m);
}
