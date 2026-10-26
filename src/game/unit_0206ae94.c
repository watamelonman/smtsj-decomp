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
void func_02052d34(void);
void func_02052d58(void);

u32 Unk06ae94_GetUnkField4c(const Unk06ae94Work *obj);
void Unk06ae94_Unk_06c8e0(Unk06ae94Work *work,u32 arg1,u32 arg2);
void Unk06ae94_Unk_06ae94(u32 arg0);
void Unk06ae94_Unk_06aeb4(u32 arg0);

u32 func_020445d0(int kind, u32 id);
void func_0204fde0(u32 h);
void func_0204fe18(u32 h);
/* At 0x0206aed4, resolve category 2 and pass its handle to func_0204fde0. */
void Unk06ae94_Unk_06aed4(u32 id)
{
    func_0204fde0(func_020445d0(2, id));
}

/* At 0x0206aeec, resolve category 2 and pass its handle to func_0204fe18. */
void Unk06ae94_Unk_06aeec(u32 id)
{
    func_0204fe18(func_020445d0(2, id));
}

/* The load at 0x0206c764 reads +0x4c; obj must reference a valid work object. */
u32 Unk06ae94_GetUnkField4c(const Unk06ae94Work *obj)
{
    return obj->unk_004c;
}

typedef struct Unk06ae94Pair {
    u32 a;
    u32 b;
} Unk06ae94Pair;

typedef struct Unk06ae94Pairs {
    u8 pad_0000[0x158];
    Unk06ae94Pair pair[2];      /* +0x158 */
} Unk06ae94Pairs;

/* Stores at 0x0206c8d4/8 identify the pair at +0x158 with stride 8.
 * The signed comparison clamps indices >= 2 to 1; callers must supply i >= 0. */
void Unk06ae94_SetPair(Unk06ae94Pairs *p, u32 a, u32 b, int i)
{
    if (i >= 2) {
        i = 1;
    }
    p->pair[i].a = a;
    p->pair[i].b = b;
}

/* Stores at 0x0206c8e0 set bit 2 at +0x34, then write arg2/arg1 at +0x3c/+0x40.
 * work must be valid; the field meanings are unknown. */
void Unk06ae94_Unk_06c8e0(Unk06ae94Work *work,u32 arg1,u32 arg2)
{
  work->unk_0034 = work->unk_0034 | 4;
  work->unk_003c = arg2;
  work->unk_0040 = arg1;
}

/* The test at 0x0206aea0 calls func_02052d34 only when
 * arg0 overlaps the global word at data_021457e0; bit meanings are unknown. */
void Unk06ae94_Unk_06ae94(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d34();
}

/* The test at 0x0206aec0 calls func_02052d58 only when
 * arg0 overlaps the global word at data_021457e0; bit meanings are unknown. */
void Unk06ae94_Unk_06aeb4(u32 arg0)
{
  if ((*data_021457e0 & arg0) == 0) {
    return;
  }
  func_02052d58();
}



void Unk06ae94_Unk_06c0b0(u32 o);
typedef struct Unk06ae94Obj Unk06ae94Obj;
void Unk06ae94_Unk_06d4e8(Unk06ae94Obj *o);
int Unk06fb70_Unk_071844();
int func_02071d6c();
void func_0206af04(int a, int b, int c, int d, int e, int f, int zero, u8 g, int h, int i);
/* ARM at 0x0206b0ac inserts a zero seventh argument; g is loaded as a byte. */
void Unk06ae94_Call_06af04(int a, int b, int c, int d, int e, int f, u8 g, int h, int i)
{
    func_0206af04(a, b, c, d, e, f, 0, g, h, i);
}

void func_02061424();
void func_0206c130(int a, int b, int c, int d, int e, int f, int zero, int g, int h);
u32 Unk06e2a0_GetEntrySubUnk34(int x, int i);
void func_0206c938(int a, int b, int c, int d, int e, int zero, int f, int g);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
/* Borrowed 20-byte record; only the three signed coordinate fields are observed. */
typedef struct Unk06ae94Pt {
    s16 x;
    s16 y;
    s16 z;
    u8 pad_06[14];
} Unk06ae94Pt;
/* Borrowed provider object prefix; the release loop establishes 50 handle slots. */
struct Unk06ae94Obj {
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
};
void func_02000f10(const s32 *in, const void *matrix, s32 *out);
int func_0206e334();
int Unk0939f0_Get_data_02175d8c();
void Unk0946e0_Unk_094704();
void Unk06ae94_Unk_06c0b0(u32 o);
void func_02061424();

/* ARM at 0x0206b8e4 transforms four borrowed 20-byte records through func_02000f10;
 * signed halfword coordinates are widened, then truncated on writeback. */
void Unk06ae94_Unk_06b8e4(Unk06ae94Pt *p, const void *m)
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

/* Borrowed release prefix; only the optional backlink at +0x360 is observed. */
typedef struct Unk06ae94ReleaseView {
    u8 pad_0000[0x360];
    u32 *link;
} Unk06ae94ReleaseView;

/* ARM at 0x0206c0b0 clears the optional backlink at +0x360 before release.
 * A nonzero address must reference a valid provider-owned object. */
void Unk06ae94_Unk_06c0b0(u32 o)
{
    u32 *p;
    if (o == 0) {
        return;
    }
    p = ((Unk06ae94ReleaseView *)o)->link;
    if (p != 0) {
        *p = 0;
    }
    func_02061424(o);
}

/* Unsigned branches at 0x0206c0dc return -1/0/1 for the two valid u32 inputs. */
int Unk06ae94_CompareU32(const u32 *a, const u32 *b)
{
    if (*a < *b) {
        return -1;
    }
    return *a > *b;
}

/* ARM at 0x0206c0f4 forwards the arguments with a zero seventh slot. */
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
      Unk06ae94_Unk_06d4e8((Unk06ae94Obj *)arg0[value + 0x24]);
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
      Unk06fb70_Unk_071844(arg0[value + 0x34]);
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

/* ARM at 0x0206c8f8 tests mask 0x1fffe000 across six provider entries. */
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

/* ARM at 0x0206ca30 forwards the arguments with a zero sixth slot. */
void Unk06ae94_Call_06c938(int a, int b, int c, int d, int e, int f, int g)
{
    func_0206c938(a, b, c, d, e, 0, f, g);
}

/* ARM at 0x0206d4e8 releases 50 handles at +0x260, clears observed state
 * and the optional backlink, then releases o; null is accepted. */
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
