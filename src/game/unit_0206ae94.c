/*
 * src/game/unit_0206ae94.c: matched functions (see docs). Field meanings are
 * unknown unless a comment cites instruction evidence; the original names are
 * retained for functions that still use a neutral func_/Unk name.
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
int func_0206e0dc(int i);
void func_02093f70(s32 index);
void func_02008848(void *dst, s32 value, u32 size);
void func_0206c204(void);
void *func_020611dc(void (*a)(void), void (*b)(void), s32 zero, void (*c)(void),
                    u32 size, s32 d, s32 e, s32 f);
struct Unk06ae94C130Work;
void *func_0206c130(u32 a, u32 b, u32 c, u32 d, u32 e, u32 *flag,
                    void *callback, u32 g, u32 h);
u32 Unk06e2a0_GetEntrySubUnk34(int x, int i);
void func_0206cad0(void);
void func_02008904(const void *src, void *dst, u32 size);
void func_02071068(void *anim, void *state, void *limit, void *vel, void *max);
struct Unk06ae94C938Work;
void *func_0206c938(u32 a, const void *src1, const void *src2, u32 d, u32 e,
                    void *callback, u32 f, s32 g);
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

/* ARM at 0x0206bb84 derives two signed angles by dividing 90 or -90 by the
 * Q12 value at +0x328, selecting signs from +0x120..+0x128. Only state 1 at
 * +0x1d8 and mode 1 at +0x130 proceed; both fields remain opaque. */
typedef struct Unk06ae94AngleWork {
    u8 pad_0000[4];
    s32 unk_0004;
    s32 unk_0008;
    s32 unk_000c;
    u8 pad_0010[0x110];
    s32 unk_0120;
    s32 unk_0124;
    s32 unk_0128;
    u8 pad_012c[4];
    u8 unk_0130;
    u8 pad_0131[0xa7];
    u8 unk_01d8;
    u8 pad_01d9[0x14f];
    s32 unk_0328;
} Unk06ae94AngleWork;

/* ARM at 0x0206bb84: see the layout comment above. */
void func_0206bb84(Unk06ae94AngleWork *work)
{
    if (work->unk_01d8 == 0) {
        return;
    }
    if (work->unk_01d8 != 1) {
        return;
    }
    if (work->unk_0124 > 0) {
        if (work->unk_0120 > 0) {
            work->unk_000c = 90 / (work->unk_0328 >> 12);
        } else {
            work->unk_000c = -90 / (work->unk_0328 >> 12);
        }
    } else {
        if (work->unk_0120 > 0) {
            work->unk_000c = 90 / (work->unk_0328 >> 12) + 90;
        } else {
            work->unk_000c = -90 / (work->unk_0328 >> 12) - 90;
        }
    }
    if (work->unk_0130 != 1) {
        return;
    }
    if (work->unk_0124 > 0) {
        if (work->unk_0128 > 0) {
            work->unk_0004 = -90 / (work->unk_0328 >> 12);
        } else {
            work->unk_0004 = 90 / (work->unk_0328 >> 12);
        }
    } else {
        if (work->unk_0128 > 0) {
            work->unk_0004 = -90 / (work->unk_0328 >> 12) - 90;
        } else {
            work->unk_0004 = 90 / (work->unk_0328 >> 12) + 90;
        }
    }
}

/* Rounded 20.12 product, as used by the original SMULL/add/shift chains. */
static inline s32 Unk06ae94_MulQ12(s32 a, s32 b)
{
    return (s32)(((s64)a * b + 0x800) >> 12);
}

/* Borrowed moving-object prefix; +0x120 and +0x318 are positions, +0x31c a
 * limit and +0x320 a 20.12 velocity. */
typedef struct Unk06ae94BounceWork {
    u8 pad_0000[0x120];
    s32 unk_0120;
    u8 pad_0124[0x1f4];
    s32 unk_0318;
    s32 unk_031c;
    s32 unk_0320;
} Unk06ae94BounceWork;

void func_0206bca8(Unk06ae94BounceWork *work, void *out);

/* ARM at 0x0206b958 advances two positions by the 20.12 velocity at +0x320.
 * When (position + velocity) leaves the +-limit at +0x31c, the velocity is
 * negated through the same rounded Q12 multiply the original emits. */
void func_0206b958(Unk06ae94BounceWork *work)
{
    u32 buf[5] = {0};
    s32 next;
    func_0206bca8(work, buf);
    next = work->unk_0318 + work->unk_0320;
    if (next > work->unk_031c) {
        work->unk_0320 = Unk06ae94_MulQ12(work->unk_0320, -0x1000);
    } else if (next < Unk06ae94_MulQ12(work->unk_031c, -0x1000)) {
        work->unk_0320 = Unk06ae94_MulQ12(work->unk_0320, -0x1000);
    }
    work->unk_0318 += work->unk_0320;
    work->unk_0120 += work->unk_0320;
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

/* Per-axis scale record: a float multiplier followed by 64 bytes of state.
 * The integer accumulators at +0x1c..+0x24 fall inside the fourth slot. */
typedef struct Unk06ae94ScaleSlot {
    float value;
    u8 pad_04[0x18];
    s32 unk_01c;
    s32 unk_020;
    s32 unk_024;
    u8 pad_028[0x1c];
} Unk06ae94ScaleSlot;

/* Register below the first scale slot. The four slots start at +0x58 with a
 * 68-byte stride; +0x168 holds an integer scaled through float and back. */
typedef struct Unk06ae94ScaleWork {
    u8 pad_0000[0x58];
    Unk06ae94ScaleSlot scale[4];
    s32 unk_0168;
} Unk06ae94ScaleWork;

/* ARM at 0x0206c6d8 adds the three integer deltas to +0x140..+0x148, scales four
 * float slots at +0x58 stride 68, and scales the integer at +0x360. */
void func_0206c6d8(volatile s32 x, volatile s32 y, volatile s32 z, volatile float scale, Unk06ae94ScaleWork *work)
{
    float s;
    int i;
    work->scale[3].unk_01c += x;
    work->scale[3].unk_020 += y;
    work->scale[3].unk_024 += z;
    s = scale;
    for (i = 0; i < 4; i++) {
        work->scale[i].value *= s;
    }
    work->unk_0168 = (s32)((float)work->unk_0168 * scale);
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
void Unk06ae94_Call_06c130(int a, int b, int c, int d, int e, u32 *flag, int g, int h)
{
    func_0206c130(a, b, c, d, e, flag, 0, g, h);
}

/* Two sentinel records at +0x15c, each with an eight-byte stride. */
typedef struct Unk06ae94Sentinel {
    u32 value;
    u32 pad_04;
} Unk06ae94Sentinel;

/* Constructor result layout; only fields written by the original are named. */
typedef struct Unk06ae94C130Work {
    u32 *unk_0000;
    u32 unk_0004;
    s32 unk_0008;
    u8 pad_000c[0x14];
    u32 unk_0020;
    u32 unk_0024;
    u32 unk_0028;
    u32 unk_002c;
    u8 unk_0030;
    u8 pad_0031[0x17];
    u32 unk_0048;
    u8 pad_004c[0x104];
    u32 unk_0150;
    u8 pad_0154[8];
    Unk06ae94Sentinel unk_015c[2];
} Unk06ae94C130Work;

/* ARM at 0x0206c130 allocates a 360-byte work object through func_020611dc,
 * clears it, and fills fields from the nine arguments. The flag pointer gets
 * a 1; the trailing loop writes two -1 sentinels at +0x15c/+0x164. */
void *func_0206c130(u32 a, u32 b, u32 c, u32 d, u32 e, u32 *flag,
                    void *callback, u32 g, u32 h)
{
    Unk06ae94C130Work *work;
    int i;
    work = (Unk06ae94C130Work *)func_020611dc(func_0206c204, 0, 0,
                                              (void (*)(void))callback, 360, 3, 0, 0);
    if (work != 0) {
        func_02008848(work, 0, 360);
        work->unk_0008 = func_0206e0dc(a);
        work->unk_0000 = flag;
        if (flag != 0) {
            *flag = 1;
        }
        work->unk_0020 = b;
        work->unk_0024 = c;
        work->unk_0028 = d;
        work->unk_002c = e;
        work->unk_0030 = a;
        work->unk_0150 = g;
        work->unk_0048 = h;
        func_02093f70(work->unk_0030);
        for (i = 0; i < 2; i++) {
            work->unk_015c[i].value = 0xffffffff;
        }
    }
    return work;
}

/* ARM at 0x0206c76c null-tolerantly releases four handle arrays whose counts
 * live at +0xc/+0x10/+0x18/+0x14 (slots +0x50/+0x90/+0x110/+0xd0), clears the
 * counts and backlinks, and zeroes the owned pointer at +0. */
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

/* ARM at 0x0206c854 resolves provider entry (p[48], word at +4), masks its +8
 * word with 0xfc0, maps 0x40/0x80/0x100 to 8/5/3 and forwards the shared global
 * with entry byte +20 through Unk0946e0_Unk_094704. A null entry or zero mask
 * returns without side effects. */
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

/* Constructor result layout. Only the fields touched by the original are
 * named; +0x198 is a 176-byte animation block whose word at +0x1e4 seeds +4. */
typedef struct Unk06ae94C938Work {
    u8 pad_0000[4];
    s32 unk_0004;
    u8 pad_0008[4];
    u8 unk_000c[0x0c];
    u8 unk_0018[0x10];
    u8 unk_0028[8];
    u8 unk_0030[0x24];
    u8 unk_0054[0x0c];
    u8 pad_0060[4];
    u8 unk_0064[0x134];
    u8 unk_0198[0x4c];
    s32 unk_01e4;
    u8 pad_01e8[0x60];
    u32 unk_0248;
    u32 unk_024c;
    u32 unk_0250;
    u32 unk_0254;
    u32 unk_0258;
    u32 unk_025c;
    u8 pad_0260[0xc8];
    s16 unk_0328;
    s16 unk_032a;
} Unk06ae94C938Work;

/* ARM at 0x0206c938 allocates an 812-byte work object through func_020611dc,
 * clears it, copies three argument blocks into it, and initialises the
 * animation state; the last halfword argument is mirrored from +0x32a to
 * +0x328. Returns the new object, or null. */
void *func_0206c938(u32 a, const void *src1, const void *src2, u32 d, u32 e,
                    void *callback, u32 f, s32 g)
{
    Unk06ae94C938Work *work;
    work = (Unk06ae94C938Work *)func_020611dc(func_0206cad0, 0, 0,
                                              (void (*)(void))callback, 812, 3, 0, 0);
    if (work != 0) {
        func_02008848(work, 0, 812);
        func_02008904(src1, work->unk_0064, 308);
        func_02008904((const u8 *)src1 + 288, work->unk_0054, 12);
        func_02008904(src2, work->unk_0198, 176);
        work->unk_0248 = d;
        work->unk_0004 = work->unk_01e4 << 12;
        work->unk_024c = a;
        work->unk_0254 = f;
        work->unk_025c = 0xffffffff;
        work->unk_0258 = 0xffffffff;
        func_02071068(work->unk_0198, work->unk_0028, work->unk_0030,
                      work->unk_000c, work->unk_0018);
        work->unk_0250 = e;
        work->unk_032a = g;
        work->unk_0328 = work->unk_032a;
    }
    return work;
}

/* ARM at 0x0206ca30 forwards the arguments with a zero sixth slot. */
void Unk06ae94_Call_06c938(u32 a, void *src1, void *src2, u32 d, u32 e, u32 f, s32 g)
{
    func_0206c938(a, src1, src2, d, e, 0, f, g);
}

/* Borrowed transform source; +0x16e is a signed angle, +0x344/+0x348 are the
 * Q12 offsets, and +0x120..+0x128 receive the resulting vector. */
typedef struct Unk06ae94D3b4Work {
    u8 pad_0000[0x120];
    s32 unk_0120;
    s32 unk_0124;
    s32 unk_0128;
    u8 pad_012c[0x42];
    s16 unk_016e;
    u8 pad_0170[0x1d4];
    s32 unk_0344;
    s32 unk_0348;
} Unk06ae94D3b4Work;

/* Three signed angles passed as a by-value, twelve-byte record. */
typedef struct Unk06ae94Angles {
    s32 a;
    s32 b;
    s32 c;
} Unk06ae94Angles;

extern const s16 data_0212629c[];
void func_02000edc(s32 *matrix, s32 a, s32 b);
void *func_0206d268(const s32 *vector, Unk06ae94Angles angles);
void func_020086bc(const void *src, void *dst, u32 size);

/* ARM at 0x0206d3b4 normalises (+0x16e - +0x344) into [0,360), looks up two
 * sin-table entries, rotates (offset + +0x348, 0, 0) through them, applies the
 * three extra angles via func_0206d268, and stores the resulting vector at
 * +0x120..+0x128. */
void func_0206d3b4(Unk06ae94D3b4Work *work, s32 offset, Unk06ae94Angles angles)
{
    s32 matrix[9];
    s32 in[3];
    s32 out[3];
    s32 v;
    s32 a;
    v = work->unk_016e - work->unk_0344;
    if (v >= 360) {
        v %= 360;
    }
    if (v < 0) {
        if (v <= -360) {
            v %= 360;
        }
        v += 360;
    }
    a = ((360 - v) * 182) >> 4;
    in[0] = offset + work->unk_0348;
    in[1] = 0;
    in[2] = 0;
    func_02000edc(matrix, data_0212629c[(a * 2) + 1], data_0212629c[a * 2]);
    func_02000f10(in, matrix, out);
    func_020086bc(func_0206d268(out, angles), out, 12);
    work->unk_0120 = out[0];
    work->unk_0124 = out[1];
    work->unk_0128 = out[2];
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
