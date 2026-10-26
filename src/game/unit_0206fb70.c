/* src/game/unit_0206fb70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06fb70Work {
    u8 pad_0000[0x120];
    s32 unk_0120;
    s32 unk_0124;
    s32 unk_0128;
} Unk06fb70Work;

/* Animation state shared by the per-channel helpers below; the full layout is
 * declared after the dispatchers that forward these pointers. */
typedef struct Unk06fb70Anim Unk06fb70Anim;

/* Second animation object used by 0x020703b4..0x02071334. Each of its four
 * keys is 24 bytes and holds three value/time pairs at +0/+4, +8/+12 and
 * +16/+20; the offsets are established by the original mla sequences
 * (+0x44 + key * 24 + channel * 8). */
typedef struct Unk06fb70Key2 {
    s32 value0;
    s32 time0;
    s32 value1;
    s32 time1;
    s32 value2;
    s32 time2;
} Unk06fb70Key2;

typedef struct Unk06fb70Anim2 {
    u8 pad_0000[68];
    Unk06fb70Key2 keys[4];
} Unk06fb70Anim2;

int func_0206d68c(int mode, u32 value, int scale);
/* ARM 0x020717c0 adds func_0206d68c(2, value, 100) to field +0x120. */
void Unk06fb70_Unk_0717c0(Unk06fb70Work *arg0, u32 arg1){
  int tmp1;
  tmp1 = func_0206d68c(2,arg1,100);
  arg0->unk_0120 = arg0->unk_0120 + tmp1;
  return;
}

/* ARM 0x02071cc8 adds func_0206d68c(2, delta, 100) to each of the three
 * signed words at +0x120, +0x124 and +0x128 of the given work object.
 * The name is neutral because the original symbol name is unknown. */
void func_02071cc8(Unk06fb70Work *work, u32 delta)
{
    work->unk_0120 += func_0206d68c(2, delta, 100);
    work->unk_0124 += func_0206d68c(2, delta, 100);
    work->unk_0128 += func_0206d68c(2, delta, 100);
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

/* ARM 0x0206fb9c converts a float delta over an integer time delta into the
 * same 20.12 scale as 0x0206fb70, rounding away from zero by half a unit.
 * A zero time delta first calls 0x02007e94, as the integer variant does. */
int func_0206fb9c(s32 t0, s32 t1, float f0, float f1)
{
    s32 dt;
    float value;
    if (t1 - t0 == 0) {
        func_02007e94();
    }
    dt = (t1 - t0) * 0x1000;
    if (f1 - f0 > 0.0f) {
        value = 0.5f + 4096.0f * (f1 - f0);
    } else {
        value = 4096.0f * (f1 - f0) - 0.5f;
    }
    return func_0200219c((s32)value, dt);
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
/* ARM 0x0206feb4 advances all nine animation channels by calling the
 * per-channel update routines in order, with the two animation objects. */
void Unk06fb70_Unk_06feb4(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
  Unk06fb70_Unk_070094();
  Unk06fb70_Unk_070114(a,b);
  Unk06fb70_Unk_070168(a,b);
  Unk06fb70_Unk_0701bc(a,b);
  Unk06fb70_Unk_070210(a,b);
  Unk06fb70_Unk_070264(a,b);
  Unk06fb70_Unk_0702b8(a,b);
  Unk06fb70_Unk_07030c(a,b);
  Unk06fb70_Unk_070360(a,b);
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
/* ARM 0x0206ff28 advances all nine animation channels through the second
 * group of per-channel update routines (including the float conversions). */
void Unk06fb70_Unk_06ff28(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
  Unk06fb70_Unk_0705f8();
  Unk06fb70_Unk_070758(a,b);
  Unk06fb70_Unk_070834(a,b);
  Unk06fb70_Unk_070950(a,b);
  Unk06fb70_Unk_070a6c(a,b);
  Unk06fb70_Unk_070b88(a,b);
  Unk06fb70_Unk_070cc0(a,b);
  Unk06fb70_Unk_070df8(a,b);
  Unk06fb70_Unk_070f30(a,b);
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
void func_020703b4(Unk06fb70Anim2 *anim, s32 *tick, s32 *state, s32 *limit, s32 *pos, s32 *vel, s32 *max, s32 *extra);
void func_02070440(Unk06fb70Anim2 *anim, s32 *tick, s32 *state, s32 *limit, s32 *pos, s32 *vel, s32 *max);
void func_02071068(Unk06fb70Anim2 *anim, s32 *state, s32 *limit, s32 *vel, s32 *max);
void func_0207112c(Unk06fb70Anim2 *anim, s32 *state, s32 *limit, s32 *vel, s32 *max);
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
/* Target ARM call to 020703b4 forwards object views at +0x16c, +0x2c, +0x28,
 * +0x30, +0, +0xc, +0x18 and +0x34. */
void Unk06fb70_Call_0703b4(u8 *o)
{
    func_020703b4((Unk06fb70Anim2 *)(o + 364), (s32 *)(o + 44), (s32 *)(o + 40),
                  (s32 *)(o + 48), (s32 *)o, (s32 *)(o + 12), (s32 *)(o + 24),
                  (s32 *)(o + 52));
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
struct Unk06fb70Anim {
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
};
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

/* ARM 0x02070758 bounds channel 1's signed state at four and searches later
 * keys for a positive time delta; the key loads and stores establish the
 * limit, velocity and 20.12 maximum before advancing the selected state. */
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

/* ARM 0x02070094 advances channel 0 only while its signed state is below four.
 * Its tick compare and BL 0x020705f8 show expiry resets tick/three velocities
 * and selects the next key; the other path clamps all three positions. */
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

/* ARM 0x020701bc advances animation channel 3 while its signed key state is
 * below 4; on tick expiry it resets tick/velocity and selects the next key
 * through 0x02070950, otherwise it clamps position 5 within its maximum. */
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

/* ARM 0x02070210 advances animation channel 4 while its signed key state is
 * below 4; on tick expiry it resets tick/velocity and selects the next key
 * through 0x02070a6c, otherwise it clamps position 6 within its maximum. */
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

/* ARM 0x02070264 advances animation channel 5 while its signed key state is
 * below 4; on tick expiry it resets tick/velocity and selects the next key
 * through 0x02070b88, otherwise it clamps position 7 within its maximum. */
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

/* ARM 0x020702b8 advances animation channel 6 while its signed key state is
 * below 4; on tick expiry it resets tick/velocity and selects the next key
 * through 0x02070cc0, otherwise it clamps position 8 within its maximum. */
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

/* ARM 0x0207030c advances animation channel 7 while its signed key state is
 * below 4; on tick expiry it resets tick/velocity and selects the next key
 * through 0x02070df8, otherwise it clamps position 9 within its maximum. */
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

/* ARM 0x02070360 advances animation channel 8 while its signed key state is
 * below 4; on tick expiry it resets tick/velocity and selects the next key
 * through 0x02070f30, otherwise it clamps position 10 within its maximum. */
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

/* ARM 0x020703b4 advances the first channel of the second animation object.
 * The state word at *state gates the update at four; tick expiry clears tick,
 * position, velocity and the extra component before selecting the next key
 * through 0x02071068, otherwise the position is clamped by velocity. */
void func_020703b4(Unk06fb70Anim2 *anim, s32 *tick, s32 *state, s32 *limit,
                   s32 *pos, s32 *vel, s32 *max, s32 *extra)
{
    if (*state >= 4) {
        return;
    }
    if (++*tick > *limit) {
        *tick = 0;
        *vel = 0;
        *pos = 0;
        *extra = 0;
        func_02071068(anim, state, limit, vel, max);
        return;
    }
    Unk06fb70_AddClamped(pos, *vel, *max);
}

/* ARM 0x02070440 advances the three value channels of the second animation
 * object. A completed state clears its four position words; tick expiry clears
 * tick and the four velocity words before selecting the next keys through
 * 0x0207112c, otherwise each position is clamped by its velocity. */
void func_02070440(Unk06fb70Anim2 *anim, s32 *tick, s32 *state, s32 *limit,
                   s32 *pos, s32 *vel, s32 *max)
{
    if (*state >= 4) {
        pos[0] = 0;
        pos[1] = 0;
        pos[2] = 0;
        pos[3] = 0;
        return;
    }
    if (++*tick > *limit) {
        *tick = 0;
        vel[0] = 0;
        vel[1] = 0;
        vel[2] = 0;
        vel[3] = 0;
        func_0207112c(anim, state, limit, vel, max);
        return;
    }
    Unk06fb70_AddClamped(&pos[0], vel[0], max[0]);
    Unk06fb70_AddClamped(&pos[1], vel[1], max[1]);
    Unk06fb70_AddClamped(&pos[2], vel[2], max[2]);
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
void func_0207126c(Unk06fb70Anim2 *anim, s8 *state, s32 *limit, s32 *vel, s32 *max);
void func_02071334(Unk06fb70Anim2 *anim, s8 *state, s32 *limit, s32 *vel, s32 *max);
void Unk06ae94_Unk_06c0b0();
void func_02061424();

/* ARM 0x0207153c starts at the manager's current slot and advances the
 * cursor while the slot is empty, stopping early at the end sentinel or at
 * the first occupied slot. The name is neutral because the original symbol
 * name is unknown. */
void func_0207153c(Unk06fb70Mgr *m)
{
    s32 *cursor = &m->cur;
    s32 cur = m->cur;
    if (cur < 0) {
        return;
    }
    if (m->objs[cur] != 0) {
        return;
    }
    for (;;) {
        if (m->end == cur) {
            return;
        }
        *cursor = (*cursor + 1) % 50;
        cur = *cursor;
        if (m->objs[cur] != 0) {
            return;
        }
    }
}

/* ARM 0x020719a8 has the same cursor-advance logic as 0x0207153c for a
 * second manager instance. The name is neutral because the original symbol
 * name is unknown. */
void func_020719a8(Unk06fb70Mgr *m)
{
    s32 *cursor = &m->cur;
    s32 cur = m->cur;
    if (cur < 0) {
        return;
    }
    if (m->objs[cur] != 0) {
        return;
    }
    for (;;) {
        if (m->end == cur) {
            return;
        }
        *cursor = (*cursor + 1) % 50;
        cur = *cursor;
        if (m->objs[cur] != 0) {
            return;
        }
    }
}

/* ARM 0x02070500 advances one animation channel described by separate
 * tick/state/limit/pos/vel/max words. It returns once the signed state reaches
 * four; on tick expiry it clears tick and velocity and selects the next key
 * through 0x0207126c, otherwise it clamps pos by vel within max. */
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

/* ARM 0x0207057c is the second channel updater with the same
 * tick/state/limit/pos/vel/max contract, selecting the next key through
 * 0x02071334 instead. */
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

/* ARM 0x02071068 selects the next key for channel 0 of the second animation
 * object. It stops at key four, sets the time delta limit, and on a positive
 * limit stores the value-derived velocity and maximum before advancing state.
 * Unlike the later channels, this one derives the maximum from the current
 * key's value, exactly as the original load at +0x44 does. */
void func_02071068(Unk06fb70Anim2 *anim, s32 *state, s32 *limit, s32 *vel, s32 *max)
{
    s32 k = 1;
    if (*state + 1 >= 4) {
        return;
    }
    for (; *state + k < 4; k++) {
        *limit = anim->keys[*state + k].time0 - anim->keys[*state].time0;
        if (*limit > 0) {
            *vel = Unk06fb70_Unk_06fb70(anim->keys[*state].time0, anim->keys[*state + k].time0, 0,
                                        anim->keys[*state].value0);
            *max = anim->keys[*state].value0 << 12;
            *state += k;
            return;
        }
    }
}

/* ARM 0x0207126c is the channel 1 counterpart of 0x02071068. It derives both
 * velocity and maximum from the value/time pair at key +8/+12 and advances the
 * signed byte state only when the next key has a later time. */
void func_0207126c(Unk06fb70Anim2 *anim, s8 *state, s32 *limit, s32 *vel, s32 *max)
{
    s32 k = 1;
    if (*state + 1 >= 4) {
        return;
    }
    for (; *state + k < 4; k++) {
        *limit = anim->keys[*state + k].time1 - anim->keys[*state].time1;
        if (*limit > 0) {
            *vel = Unk06fb70_Unk_06fb70(anim->keys[*state].time1, anim->keys[*state + k].time1,
                                        anim->keys[*state].value1,
                                        anim->keys[*state + k].value1);
            *max = anim->keys[*state + k].value1 << 12;
            *state += k;
            return;
        }
    }
}

/* ARM 0x02071334 is the channel 2 counterpart of 0x0207126c, using the
 * value/time pair at key +16/+20. The same signed byte state and four-key
 * bound apply. */
void func_02071334(Unk06fb70Anim2 *anim, s8 *state, s32 *limit, s32 *vel, s32 *max)
{
    s32 k = 1;
    if (*state + 1 >= 4) {
        return;
    }
    for (; *state + k < 4; k++) {
        *limit = anim->keys[*state + k].time2 - anim->keys[*state].time2;
        if (*limit > 0) {
            *vel = Unk06fb70_Unk_06fb70(anim->keys[*state].time2, anim->keys[*state + k].time2,
                                        anim->keys[*state].value2,
                                        anim->keys[*state + k].value2);
            *max = anim->keys[*state + k].value2 << 12;
            *state += k;
            return;
        }
    }
}

/* ARM 0x02071844 tears down a manager: it releases the 50 objects at +0x234,
 * zeroes the words at +0x24..+0x30, clears the word reached through +0x224
 * when non-null, then calls func_02061424 on the manager. */
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

/* ARM 0x02071d6c releases a second manager of the same layout: it tears down
 * the 50 objects at +0x234, zeroes the words at +0x24..+0x30, clears the word
 * pointed to by +0x224 (when present), then calls func_02061424 on the manager.
 * The identical body at 0x02071844 is a separate original function, so this
 * one is emitted as its own C definition rather than an alias. */
void func_02071d6c(Unk06fb70Mgr *m)
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
