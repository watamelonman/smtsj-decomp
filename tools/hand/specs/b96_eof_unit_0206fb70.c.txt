/* src/game/unit_0206fb70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06fb70Work {
    u8 pad_0000[0x120];
    s32 unk_0120;
} Unk06fb70Work;



int func_0206d68c();
/* decompiler-derived */
void Unk06fb70_Unk_0717c0(Unk06fb70Work *arg0, u32 arg1){
  int tmp1;
  tmp1 = func_0206d68c(2,arg1,100);
  arg0->unk_0120 = arg0->unk_0120 + tmp1;
  return;
}

int func_0200219c();
int func_02007e94();
/* decompiler-derived */
int Unk06fb70_Unk_06fb70(int arg0,int arg1,int arg2,int arg3)
{
  if (arg1 - arg0 == 0) {
    func_02007e94();
  }
  return func_0200219c((arg3 - arg2) * 0x1000,(arg1 - arg0) * 0x1000);
}



void func_02070094();
void func_02070114();
void func_02070168();
void func_020701bc();
void func_02070210();
void func_02070264();
void func_020702b8();
void func_0207030c();
void func_02070360();
/* decompiler-derived */
void Unk06fb70_Unk_06feb4(u32 arg0,u32 arg1)
{
  func_02070094();
  func_02070114(arg0,arg1);
  func_02070168(arg0,arg1);
  func_020701bc(arg0,arg1);
  func_02070210(arg0,arg1);
  func_02070264(arg0,arg1);
  func_020702b8(arg0,arg1);
  func_0207030c(arg0,arg1);
  func_02070360(arg0,arg1);
  return;
}

void func_020705f8();
void func_02070758();
int func_02070834();
int func_02070950();
int func_02070a6c();
int func_02070b88();
int func_02070cc0();
int func_02070df8();
int func_02070f30();
/* decompiler-derived */
void Unk06fb70_Unk_06ff28(u32 arg0,u32 arg1)
{
  func_020705f8();
  func_02070758(arg0,arg1);
  func_02070834(arg0,arg1);
  func_02070950(arg0,arg1);
  func_02070a6c(arg0,arg1);
  func_02070b88(arg0,arg1);
  func_02070cc0(arg0,arg1);
  func_02070df8(arg0,arg1);
  func_02070f30(arg0,arg1);
  return;
}

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

void func_0207142c();
void func_02071898();
void func_020703b4();
void Unk06fb70_Call_07142c(int a, int b, int c, int d, int e, int f, int g)
{
    func_0207142c(a, b, c, d, e, 0, f, g);
}

void Unk06fb70_Call_071898(int a, int b, int c, int d, int e, int f, int g)
{
    func_02071898(a, b, c, d, e, 0, f, g);
}

void Unk06fb70_Call_0703b4(u8 *o)
{
    func_020703b4(o + 364, o + 44, o + 40, o + 48, o, o + 12, o + 24, o + 52);
}

typedef struct Unk06fb70Key {
    u8 pad_00[16];
    s32 t[9];                   /* +0x10: per-channel time */
    u8 c[4];                    /* +0x34 */
    u8 pad_38[12];
} Unk06fb70Key;
typedef struct Unk06fb70Anim {
    Unk06fb70Key keys[4];       /* count from the < 4 bounds */
    u8 pad_110[212];
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

void func_020705f8(Unk06fb70Anim *a, Unk06fb70Anim *b)
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

void func_02070758(Unk06fb70Anim *a, Unk06fb70Anim *b)
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

void func_02070094(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[0] >= 4) {
        return;
    }
    if (++a->tick[0] > a->limit[0]) {
        a->tick[0] = 0;
        a->vel[0] = 0;
        a->vel[1] = 0;
        a->vel[2] = 0;
        func_020705f8(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[0], a->vel[0], a->max[0]);
    Unk06fb70_AddClamped(&a->pos[1], a->vel[1], a->max[1]);
    Unk06fb70_AddClamped(&a->pos[2], a->vel[2], a->max[2]);
}

void func_02070114(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[1] >= 4) {
        return;
    }
    if (++a->tick[1] > a->limit[1]) {
        a->tick[1] = 0;
        a->vel[3] = 0;
        func_02070758(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[3], a->vel[3], a->max[3]);
}

void func_02070168(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[2] >= 4) {
        return;
    }
    if (++a->tick[2] > a->limit[2]) {
        a->tick[2] = 0;
        a->vel[4] = 0;
        func_02070834(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[4], a->vel[4], a->max[4]);
}

void func_020701bc(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[3] >= 4) {
        return;
    }
    if (++a->tick[3] > a->limit[3]) {
        a->tick[3] = 0;
        a->vel[5] = 0;
        func_02070950(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[5], a->vel[5], a->max[5]);
}

void func_02070210(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[4] >= 4) {
        return;
    }
    if (++a->tick[4] > a->limit[4]) {
        a->tick[4] = 0;
        a->vel[6] = 0;
        func_02070a6c(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[6], a->vel[6], a->max[6]);
}

void func_02070264(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[5] >= 4) {
        return;
    }
    if (++a->tick[5] > a->limit[5]) {
        a->tick[5] = 0;
        a->vel[7] = 0;
        func_02070b88(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[7], a->vel[7], a->max[7]);
}

void func_020702b8(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[6] >= 4) {
        return;
    }
    if (++a->tick[6] > a->limit[6]) {
        a->tick[6] = 0;
        a->vel[8] = 0;
        func_02070cc0(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[8], a->vel[8], a->max[8]);
}

void func_0207030c(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[7] >= 4) {
        return;
    }
    if (++a->tick[7] > a->limit[7]) {
        a->tick[7] = 0;
        a->vel[9] = 0;
        func_02070df8(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[9], a->vel[9], a->max[9]);
}

void func_02070360(Unk06fb70Anim *a, Unk06fb70Anim *b)
{
    if (a->state[8] >= 4) {
        return;
    }
    if (++a->tick[8] > a->limit[8]) {
        a->tick[8] = 0;
        a->vel[10] = 0;
        func_02070f30(a, b);
        return;
    }
    Unk06fb70_AddClamped(&a->pos[10], a->vel[10], a->max[10]);
}
