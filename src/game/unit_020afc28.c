/* src/game/unit_020afc28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0afc28Work {
    u8 pad_0000[0x20];
    s32 unk_0020;
} Unk0afc28Work;




/* decompiler-derived */
void Unk0afc28_Unk_0afc28(Unk0afc28Work *arg0, int arg1){
  arg0->unk_0020 = arg0->unk_0020 + arg1;
  return;
}

int func_020492ec();
int func_0204a67c();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk0afc28Pos12 {
    u32 w[3];
} Unk0afc28Pos12;

typedef struct Unk0afc28Ptrs {
    u8 pad_00[0x64];
    u32 *e[10];
} Unk0afc28Ptrs;

int Unk0981dc_Unk_098324(int a, int b);
int func_02050074();
int Unk0afc28_Unk_0afd60(int a, int b);
int Unk044904_Get_data_0215ee98();
int func_020982c0();
typedef struct Unk0afc28Pos Unk0afc28Pos;
int Unk0afc28_IsOrigin(Unk0afc28Pos *p);
void Unk0afc28_Unk_0afc38(u8 *p, Unk0afc28Pos12 *src)
{
    u32 cur = FIELD(u32, p, 36);
    if (cur != 0 && Unk0981dc_Unk_098324((s8)src->w[0], (s8)cur) == 0) {
        return;
    }
    *(Unk0afc28Pos12 *)(p + 36) = *src;
}

/* decompiler-derived */
void Unk0afc28_Unk_0afdd0(u32 arg0,u32 arg1,int arg2)
{
  int tmp1;
  tmp1 = func_0204a67c();
  if (arg2 != 0) {
    tmp1 = -tmp1;
  }
  func_020492ec(arg1,tmp1);
  return;
}



/* decompiler-derived */
u32 Unk0afc28_Unk_0afcd4(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 8;
  case 1:
    return 9;
  case 2:
    return 10;
  case 3:
    return 0xb;
  case 4:
    return 0xc;
  case 5:
    return 0xd;
  case 6:
    return 0xe;
  case 7:
    return 0xf;
  default:
    return 0x1a;
  }
}

struct Unk0afc28Pos {
    u8 pad_0000[0x4];
    s8 x;                       /* +0x04 */
    u8 pad_0005;
    s8 y;                       /* +0x06 */
};

int Unk0afc28_Unk_0afd60(int a, int b)
{
    int n = a * b * 2;
    return (func_02050074(0, n) - n / 2) / 100;
}

int Unk0afc28_Unk_0afd98(int a, int b, int c)
{
    int r;
    if (a <= c) {
        r = func_02050074(0, c - 1) + 1;
    } else {
        r = Unk0afc28_Unk_0afd60(a, b);
        r += a;
    }
    if (r <= 0) {
        r = 1;
    }
    return r;
}

int Unk0afc28_CountById(u32 id)
{
    Unk0afc28Ptrs *g = (Unk0afc28Ptrs *)Unk044904_Get_data_0215ee98();
    int n = 0;
    int j;
    for (j = 0; j < 10; j++) {
        u32 *e = g->e[j];
        if (e != 0 && id == ((e[0] >> 16) & 0xff)) {
            n++;
        }
    }
    return n;
}

int Unk0afc28_IsOrigin(Unk0afc28Pos *p)
{
    if (p->x == 0 && p->y == 0) {
        return -1;
    }
    return 0;
}

int Unk0afc28_Unk_0b0930(u32 *p, u32 a, u16 b, u32 c)
{
    Unk0afc28Pos *r = (Unk0afc28Pos *)func_020982c0((s8)c);
    if (r == 0) {
        return 0;
    }
    p[0] = c;
    p[1] = a;
    FIELD(u16, p, 10) = b;
    FIELD(u16, p, 8) = Unk0afc28_IsOrigin(r);
    return 1;
}
