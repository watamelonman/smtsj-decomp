/*
 * src/game/unit_0206ae94.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06ae94Work {
    u8 pad_0000[0x34];
    u32 unk_0034;
    u8 pad_0038[0x4];
    u32 unk_003c;
    u32 unk_0040;
    u8 pad_0044[0x8];
    u32 unk_004c;
} Unk06ae94Work;

extern u32 data_021457e0[];
int func_02052d34();
int func_02052d58();

u32 Unk06ae94_GetUnkField4c(void *obj);
void Unk06ae94_Unk_06c8e0(Unk06ae94Work *work,u32 arg1,u32 arg2);
void Unk06ae94_Unk_06ae94(u32 arg0);
void Unk06ae94_Unk_06aeb4(u32 arg0);

u32 func_020445d0(int kind, u32 id);
void func_0204fde0(u32 h);
void func_0204fe18(u32 h);
void Unk06ae94_Unk_06aed4(u32 id)
{
    func_0204fde0(func_020445d0(2, id));
}

void Unk06ae94_Unk_06aeec(u32 id)
{
    func_0204fe18(func_020445d0(2, id));
}

/* get u32 at +0x4c */
u32 Unk06ae94_GetUnkField4c(void *obj) { return ((Unk06ae94Work *)obj)->unk_004c; }

typedef struct Unk06ae94Pair {
    u32 a;
    u32 b;
} Unk06ae94Pair;

typedef struct Unk06ae94Pairs {
    u8 pad_0000[0x158];
    Unk06ae94Pair pair[2];      /* +0x158 */
} Unk06ae94Pairs;

void Unk06ae94_SetPair(Unk06ae94Pairs *p, u32 a, u32 b, int i)
{
    if (i >= 2) {
        i = 1;
    }
    p->pair[i].a = a;
    p->pair[i].b = b;
}

/* decompiler-derived */
void Unk06ae94_Unk_06c8e0(Unk06ae94Work *work,u32 arg1,u32 arg2)
{
  work->unk_0034 = work->unk_0034 | 4;
  work->unk_003c = arg2;
  work->unk_0040 = arg1;
}

/* decompiler-derived */
void Unk06ae94_Unk_06ae94(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d34();
}

/* decompiler-derived */
void Unk06ae94_Unk_06aeb4(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d58();
}



void Unk06ae94_Unk_06c0b0();
void Unk06ae94_Unk_06d4e8();
int func_02071844();
int func_02071d6c();
void func_0206af04();
void Unk06ae94_Call_06af04(int a, int b, int c, int d, int e, int f, u8 g, int h, int i)
{
    func_0206af04(a, b, c, d, e, f, 0, g, h, i);
}

void func_02061424();
void func_0206c130();
u32 Unk06e2a0_GetEntrySubUnk34();
void func_0206c938();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk06ae94Pt {
    s16 x;
    s16 y;
    s16 z;
    u8 pad_06[14];
} Unk06ae94Pt;
typedef struct Unk06ae94Obj {
    u8 pad_00[0x24];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_34[0x14];
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u8 pad_54[0x1fc];
    u32 *unk_250;
    u8 pad_254[4];
    s32 unk_258;
    s32 unk_25c;
    u32 objs[50];
} Unk06ae94Obj;
void func_02000f10();
int func_0206e334();
int Unk0939f0_Get_data_02175d8c();
void Unk0946e0_Unk_094704();
void Unk06ae94_Unk_06c0b0();
void func_02061424();

void Unk06ae94_Unk_06b8e4(Unk06ae94Pt *p, void *m)
{
    int i;
    for (i = 0; i < 4; i++, p++) {
        s32 in[3];
        s32 out[3];
        s32 z = p->z;
        s32 y = p->y;
        s32 x = p->x;
        in[0] = x;
        in[1] = y;
        in[2] = z;
        func_02000f10(in, m, out);
        p->x = out[0];
        p->y = out[1];
        p->z = out[2];
    }
}

void Unk06ae94_Unk_06c0b0(u32 o)
{
    u32 *p;
    if (o == 0) {
        return;
    }
    p = FIELD(u32 *, o, 0x360);
    if (p != 0) {
        *p = 0;
    }
    func_02061424(o);
}

int Unk06ae94_CompareU32(u32 *a, u32 *b)
{
    if (*a < *b) {
        return -1;
    }
    return *a > *b;
}

void Unk06ae94_Call_06c130(int a, int b, int c, int d, int e, int f, int g, int h)
{
    func_0206c130(a, b, c, d, e, f, 0, g, h);
}

/* decompiler-derived */
void Unk06ae94_Unk_06c76c(u32 *arg0)
{
  int value;
  if (arg0 == (u32 *)0x0) {
    return;
  }
  value = 0;
  if (0 < (int)arg0[3]) {
    do {
      Unk06ae94_Unk_06c0b0(arg0[value + 0x14]);
      value = value + 1;
    } while (value < (int)arg0[3]);
  }
  value = 0;
  if (0 < (int)arg0[4]) {
    do {
      Unk06ae94_Unk_06d4e8(arg0[value + 0x24]);
      value = value + 1;
    } while (value < (int)arg0[4]);
  }
  value = 0;
  if (0 < (int)arg0[6]) {
    do {
      func_02071d6c(arg0[value + 0x44]);
      value = value + 1;
    } while (value < (int)arg0[6]);
  }
  value = 0;
  if (0 < (int)arg0[5]) {
    do {
      func_02071844(arg0[value + 0x34]);
      value = value + 1;
    } while (value < (int)arg0[5]);
  }
  arg0[3] = 0;
  arg0[4] = 0;
  arg0[6] = 0;
  arg0[5] = 0;
  arg0[7] = 0;
  arg0[1] = 0;
  if ((u32 *)*arg0 != (u32 *)0x0) {
    *(u32 *)*arg0 = 0;
  }
}

void Unk06ae94_Unk_06c854(u8 *p)
{
    u8 *e = (u8 *)func_0206e334(p[48], FIELD(u32, p, 4));
    u32 k;
    int r;
    if (e == 0) {
        return;
    }
    k = FIELD(u32, e, 8) & 0xfc0;
    if (k == 0) {
        return;
    }
    r = 0;
    switch (k) {
    case 64: r = 8; break;
    case 128: r = 5; break;
    case 256: r = 3; break;
    }
    Unk0946e0_Unk_094704(Unk0939f0_Get_data_02175d8c(), r, r, e[20], 0);
}

int Unk06ae94_Unk_06c8f8(int x)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (Unk06e2a0_GetEntrySubUnk34(x, i) & 0x1fffe000) {
            return 1;
        }
    }
    return 0;
}

void Unk06ae94_Call_06c938(int a, int b, int c, int d, int e, int f, int g)
{
    func_0206c938(a, b, c, d, e, 0, f, g);
}

void Unk06ae94_Unk_06d4e8(Unk06ae94Obj *o)
{
    int i;
    if (o == 0) {
        return;
    }
    i = 0;
    o->unk_24 = i;
    for (; i < 50; i++) {
        Unk06ae94_Unk_06c0b0(o->objs[i]);
    }
    o->unk_24 = 0;
    o->unk_28 = 0;
    o->unk_2c = 0;
    o->unk_30 = 0;
    o->unk_48 = 0;
    o->unk_4c = 0;
    o->unk_50 = 0;
    if (o->unk_250 != 0) {
        *o->unk_250 = 0;
    }
    func_02061424(o);
}
