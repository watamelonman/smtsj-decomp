/*
 * src/CampStatus.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


typedef float f32;

/* Reached through two pointers from CampStatusWork.unk_002c. */
typedef struct CampStatusLink {
    u8 pad_0000[0x14];
    u32 unk_0014;
} CampStatusLink;

/* Animation/scale block at CampStatusWork.unk_0094. */
typedef struct CampStatusAnim {
    u8 pad_0000[0x20];
    f32 scale;                  /* +0x20: reset to 1.0 */
    u8 pad_0024[0x4];
    s32 unk_0028;               /* +0x28: reset to -1 */
} CampStatusAnim;

/* Byte pairs copied as a block (see func_020d6cac / func_020d6ce4). */
typedef struct CampStatusPair {
    u8 a;
    u8 b;
} CampStatusPair;
typedef struct CampStatusPairs6 {
    CampStatusPair p[6];
} CampStatusPairs6;
typedef struct CampStatusPairs5 {
    CampStatusPair p[5];
} CampStatusPairs5;

/* Object at CampStatusWork.unk_0078; +0x3a is the flag Unk065e88_SetFlag3a writes. */
typedef struct CampStatusFlagObj {
    u32 handle;
    u8 pad_0004[0x36];
    u8 flag_3a;
} CampStatusFlagObj;

/* Camp status work; the first argument here and also *data_02176be4. */
typedef struct CampStatusWork {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x8];
    u32 unk_0018;
    u32 unk_001c;
    u8 pad_0020[0xc];
    CampStatusLink **unk_002c;
    u8 pad_0030[0x48];
    CampStatusFlagObj *unk_0078;
    u8 pad_007c[0x18];
    CampStatusAnim *unk_0094;
    u8 pad_0098[0x30];
    void *unk_00c8;
    u8 pad_00cc[0x28];
    u32 unk_00f4;
    u32 unk_00f8;
    s16 unk_00fc;
    s16 unk_00fe;
    s16 unk_0100;
    s16 unk_0102;
    s16 unk_0104;
    s16 unk_0106;
    s16 unk_0108;
    s16 unk_010a;
    s16 unk_010c;
    s16 unk_010e;
    u32 unk_0110;
    u8 pad_0114[0x54];
    CampStatusPairs6 unk_0168;
    u8 pad_0174[0x2];
    CampStatusPairs5 unk_0176;
    u8 pad_0180[0x28];
    u32 unk_01a8;
    u8 pad_01ac[0x94];
    u8 unk_0240;
    u8 unk_0241;
    u8 pad_0242[0xe];
    u32 unk_0250;               /* +0x250: written to 1 by func_020dcb44 */
    u8 pad_0254[0x4];
    u32 unk_0258;
    u8 pad_025c[0x4];
    u32 unk_0260;
    u8 pad_0264[0x4];
    s32 unk_0268;               /* +0x268: set by func_020dcad4 */
    u8 pad_026c[0x7228];
    u32 unk_7494;
} CampStatusWork;

extern CampStatusWork *data_02176be4;

u32 CampStatus_GetUnkField1c(CampStatusWork *work);
u32 CampStatus_GetUnkField7494(CampStatusWork *work);

/* Read the unidentified work word at +0x1c; no caller evidence for a better name. */
u32 CampStatus_GetUnkField1c(CampStatusWork *work) { return work->unk_001c; }

/* Read the 49-byte table at data_0213c60c; an out-of-range index reads entry 0. */
extern u8 data_0213c60c[49];

int CampStatus_GetTableByte(u32 i)
{
    if (i >= 49) {
        i = 0;
    }
    return data_0213c60c[i];
}

/* Read the cached word at +0x7494 (shape only; purpose not evidenced). */
u32 CampStatus_GetUnkField7494(CampStatusWork *work)
{
  return work->unk_7494;
}



/* decompiler-derived */
int CampStatus_Unk_0d34e4(int *arg0,int arg1)
{
  if (arg1 < arg0[7]) {
    return *arg0 + *(int *)(arg0[6] + arg1 * 4) * 2;
  }
  return 0;
}

int func_02061424();
/* decompiler-derived */
void CampStatus_Unk_0d3510(int *arg0)
{
  int value;
  value = *arg0;
  *arg0 = value + 1;
  if (value + 1 < arg0[1]) {
    return;
  }
  arg0[2] = 0;
  func_02061424();
}


extern u8 data_021507f4[];
int func_02013c3c();
int func_02051610();
int func_0205b444();
void Unk05b82c_Unk_05b82c();
void func_020ca5a4();
void func_020119a0();
/* Callback table filled by func_020d3624. */
typedef struct CampStatusOps {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} CampStatusOps;
/* Per-frame (x, y) offset. */
typedef struct CampStatusOffset {
    s8 x;
    s8 y;
} CampStatusOffset;
/* Frame record returned by func_020616c0. */
typedef struct CampStatusFrame {
    s32 index;
    u32 unk_04;
    CampStatusOffset *offsets;
} CampStatusFrame;
/* 12-byte task state run by CampStatus_Unk_0d3510. */
typedef struct CampStatusTimer {
    s32 count;
    s32 limit;
    u32 unk_08;
} CampStatusTimer;
/* Entry returned by func_020a1428. */
typedef struct CampStatusEntry {
    u16 unk_00;
    u8 pad_02[0x3];
    u8 kind;
} CampStatusEntry;
void func_020d5644();
void func_020d5d44();
void func_020d6120();
void func_020d6948();
void func_020d6a24();
void func_020d3680();
int func_02061698(void *obj);
CampStatusFrame *func_020616c0(void *obj);
void func_020614b0(u32 *handle);
void *func_020611dc();
void func_020615ec(u32 *handle, void *task);
s32 Unk06ae94_Unk_06aeec(void *obj);
u32 Unk06ae94_Unk_06aed4(void *obj);
void Unk09d060_Unk_09d170(void *task);
void func_020dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n);
void Unk065e88_SetFlag3a(CampStatusFlagObj *obj, int value);
void func_0205cac0(u32 handle);
void func_0205c6f8(u32 handle);
CampStatusEntry *func_020a1428(int id);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
u32 func_020445f4(u32 a, u32 b);
void func_02063920(void);
u32 func_0204fed8(u32 tab, u32 id);
u32 func_02063a30(u32 v);
void func_02061f10();
/* Read the current (x, y) offset pair of obj's frame, if it has one. Returns 0 when
 * func_02061698 says obj is not active (outputs stay 0), otherwise 1. */
/* Start a 12-byte CampStatus_Unk_0d3510 task for obj and return the handle from func_020614b0. */
u32 func_020d353c(void *obj)
{
    u32 handle;
    CampStatusTimer *t;
    func_020614b0(&handle);
    t = func_020611dc(CampStatus_Unk_0d3510, 0, 0, 0, 12, 0, 0, 0);
    if (t != 0) {
        t->count = 0;
        t->limit = Unk06ae94_Unk_06aeec(obj);
        t->unk_08 = Unk06ae94_Unk_06aed4(obj);
        Unk09d060_Unk_09d170(t);
        func_020615ec(&handle, t);
    }
    return handle;
}

int func_020d35c0(void *obj, s32 *x, s32 *y)
{
    CampStatusFrame *f;
    *x = 0;
    *y = 0;
    if (func_02061698(obj) == 0) {
        return 0;
    }
    f = func_020616c0(obj);
    if (f->offsets != 0) {
        CampStatusOffset *o = &f->offsets[f->index];
        *x = o->x;
        *y = o->y;
    }
    return 1;
}

/* Fill the module's callback table: work size 620, then the six handlers (0x0c..0x20). */
void func_020d3624(CampStatusOps *o)
{
    o->size = 620;
    o->unk_04 = 4;
    o->fn_0c = func_020d5644;
    o->fn_10 = func_020d5d44;
    o->fn_14 = func_020d6120;
    o->fn_18 = func_020d6948;
    o->fn_1c = func_020d6a24;
    o->fn_20 = func_020d3680;
}

void CampStatus_Unk_0d51cc(void)
{
    int i;
    for (i = 59; i <= 64; i++) {
        Unk05b82c_Unk_05b82c(i);
    }
    func_020ca5a4(0);
    func_020ca5a4(2);
}

void CampStatus_Copy12c(void *src)
{
    func_020119a0((u8 *)data_02176be4 + 300, src, 60);
}

/* Copy six byte pairs into the shared work at +0x168. */
void func_020d6cac(const CampStatusPairs6 *src)
{
    data_02176be4->unk_0168 = *src;
}

/* Copy five byte pairs into the shared work at +0x176. */
void func_020d6ce4(const CampStatusPairs5 *src)
{
    data_02176be4->unk_0176 = *src;
}

/* decompiler-derived */
u32 CampStatus_Unk_0db338(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  func_02013c3c(auStack_48,((int)data_021507f4),arg1);
  tmp1 = func_02051610(auStack_48);
  ((CampStatusWork *)arg0)->unk_000c = tmp1;
  func_0205b444(((CampStatusWork *)arg0)->unk_0008,((CampStatusWork *)arg0)->unk_000c);
  return 1;
}

extern u8 data_02150824[];
int CampStatus_GetTableByte();
/* decompiler-derived */
u32 CampStatus_Unk_0db394(int arg0,u32 arg1)
{
  u32 tmp1;
  u8 auStack_48 [64];
  tmp1 = CampStatus_GetTableByte(arg1);
  func_02013c3c(auStack_48,((int)data_02150824),tmp1);
  tmp1 = func_02051610(auStack_48);
  ((CampStatusWork *)arg0)->unk_000c = tmp1;
  func_0205b444(((CampStatusWork *)arg0)->unk_0008,((CampStatusWork *)arg0)->unk_000c);
  return 1;
}




/* decompiler-derived */
int CampStatus_Unk_0dd88c(int arg0,int arg1)
{
  int tmp1;
  tmp1 = arg0;
  if ((arg1 == 2) && (arg0 == 0 || arg0 == 2)) {
    tmp1 = 2;
  }
  if ((arg1 == 5) && ((arg0 == 0 || arg0 == 2) || arg0 == 5)) {
    tmp1 = 5;
  }
  if ((arg1 == 1) && (((arg0 == 0 || arg0 == 2) || arg0 == 5) || arg0 == 1)) {
    tmp1 = 1;
  }
  if ((arg1 == 3) &&
     ((((arg0 == 0 || arg0 == 2) || arg0 == 5) || arg0 == 1) || arg0 == 3)) {
    tmp1 = 3;
  }
  if ((arg1 == 4) && (arg0 != 4)) {
    tmp1 = 4;
  }
  return tmp1;
}


int func_02057fd8();
int func_0205dee8();
/* decompiler-derived */
void CampStatus_Unk_0ddd2c(u32 arg0,u32 arg1,u32 arg2)
{
  func_0205dee8(2,arg0,0x10,arg1,0,0x3f800000,0x3f800000,0,arg2,2);
  func_02057fd8();
  func_0205dee8(2,arg0,0x11,arg1,0,0x3f800000,0x3f800000,0,arg2,3);
  func_02057fd8();
  func_0205dee8(2,arg0,0x12,arg1,0,0x3f800000,0x3f800000,0,arg2,4);
  return;
}

int func_02057df8();
int func_02057e18();
/* decompiler-derived */
void CampStatus_Unk_0d71bc(int arg0)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2b,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2c,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2d,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);
  func_02057e18(0x1f);
  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2e,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x2f,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,0x3f800000,3);
}

/* decompiler-derived */
void CampStatus_Unk_0d7680(int arg0)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,5,(int)((CampStatusWork *)arg0)->unk_00fe,0,0x3f800000,
                0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x41,(int)((CampStatusWork *)arg0)->unk_00fe,0,0x3f800000,
                0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,3);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x22,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x23,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x24,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x25,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x26,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x27,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);

  func_0205dee8(2,((CampStatusWork *)arg0)->unk_0018,0x21,0,(int)((CampStatusWork *)arg0)->unk_010c,0x3f800000
                ,0x3f800000,0,((CampStatusWork *)arg0)->unk_0110,2);
  func_02057e18(0x1f);
}

int CampStatus_IsUnkF4F8Set(void)
{
    CampStatusWork *w = data_02176be4;
    return w->unk_00f4 != 0 && w->unk_00f8 != 0;
}

/* Read the unidentified word at +0x1a8 in the shared work. */
u32 CampStatus_GetUnk1a8(void)
{
    return data_02176be4->unk_01a8;
}

/* Write the unidentified word at +0x1a8 in the shared work. */
void CampStatus_SetUnk1a8(u32 value)
{
    data_02176be4->unk_01a8 = value;
}

/* Read the unidentified word at +0x258 in the shared work. */
u32 CampStatus_GetUnk258(void)
{
    return data_02176be4->unk_0258;
}

/* Raise the mode flag at +0x260; see CampStatus_ResetAnim for the clear. */
void CampStatus_SetUnk260(void)
{
    data_02176be4->unk_0260 = 1;
}

void CampStatus_ResetAnim(void)
{
    data_02176be4->unk_0260 = 0;
    data_02176be4->unk_0094->unk_0028 = -1;
    data_02176be4->unk_0094->scale = 1.0f;
}

void CampStatus_SetUnk240(u8 a, u8 b)
{
    data_02176be4->unk_0240 = a;
    data_02176be4->unk_0241 = b;
}

void CampStatus_GetLinkUnk14(u32 *out)
{
    *out = (*data_02176be4->unk_002c)->unk_0014;
}

/* Triangle-ish ramp over a 120-tick period: 11 rising to 31 over ticks 0..45, hold 31 to 74,
 * then fall back (4.12 fixed point, slope 0x71c). */
u8 func_020db214(s32 t)
{
    s32 r = t % 120;
    s32 v = 0xb000;
    if (r <= 45) {
        v += r * 0x71c;
        return v >> 12;
    }
    if (r < 75) {
        return 31;
    }
    v += 0x14000 - (r - 75) * 0x71c;
    return v >> 12;
}

/* Ramp over a 50-tick period: 31 falling to 16 over ticks 0..40, then back up (4.12 fixed point). */
u8 func_020db288(s32 t)
{
    s32 r = t % 50;
    s32 v = 0x1f000;
    if (r <= 40) {
        v -= r * 0x600;
    } else {
        v -= 0xf000 - (r - 40) * 0x1800;
    }
    return v >> 12;
}

/* Ramp over a 40-tick period: 18 rising to 31 over ticks 0..10, then falling (4.12 fixed point). */
u8 func_020db2dc(s32 t)
{
    s32 r = t % 40;
    s32 v;
    if (r <= 10) {
        v = 0x12000;
        v += r * 0x13d7;
    } else {
        v = 0x1f000 - (r - 10) * 0x6ee;
    }
    return v >> 12;
}

/* For ids 8..10 only: show entry id of group (14, 0) on work->unk_00c8 via func_020dde3c. */
void func_020dbf24(CampStatusWork *work, u32 id)
{
    u32 ids[1];
    if (id < 8) {
        return;
    }
    if (id > 10) {
        return;
    }
    ids[0] = id;
    func_020dde3c(work->unk_00c8, 14, 0, ids, 1);
}

/* Reset the flag at +0xf4 and the ten s16 values at +0xfc..+0x10e to their start values. */
void func_020dca50(CampStatusWork *work)
{
    work->unk_00f4 = 0;
    work->unk_00fc = -12;
    work->unk_00fe = -160;
    work->unk_0100 = -224;
    work->unk_0102 = -288;
    work->unk_0104 = -352;
    work->unk_0106 = -416;
    work->unk_0108 = -480;
    work->unk_010a = 80;
    work->unk_010c = 60;
    work->unk_010e = 0;
}

void CampStatus_Unk_0dcaac(void)
{
    data_02176be4->unk_00f4 = 0;
    data_02176be4->unk_010e = -80;
}

/* Store on at +0x268, then switch the unk_0078 object on (flag 0x3a set + func_0205cac0, only
 * if not already set) or off (func_0205c6f8 + flag cleared). */
void func_020dcad4(s32 on)
{
    CampStatusFlagObj *obj;
    data_02176be4->unk_0268 = on;
    obj = data_02176be4->unk_0078;
    if (on != 0) {
        if (obj->flag_3a != 0) {
            return;
        }
        Unk065e88_SetFlag3a(obj, 1);
        func_0205cac0(data_02176be4->unk_0078->handle);
        return;
    }
    func_0205c6f8(obj->handle);
    Unk065e88_SetFlag3a(data_02176be4->unk_0078, 0);
}

void CampStatus_Unk_0dd308(s32 *v, s32 add, int n, s32 *cnt, float *out)
{
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            v[i] += add;
        }
    }
    if (*cnt >= 10) {
        return;
    }
    (*cnt)++;
    *out = *cnt / 10.0f;
}

/* Set the unidentified flag at +0x250; neutral name kept from symbols.txt. */
void func_020dcb44(void)
{
    data_02176be4->unk_0250 = 1;
}

/* Pick the four-corner colour for entry id: grey when its first u16 is 0, otherwise by the
 * kind byte at +5 (4 and 5 get their own colours, anything else the default via func_02057df8). */
void func_020ddb9c(int id)
{
    CampStatusEntry *e = func_020a1428(id);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
        return;
    }
    if (e->kind == 5) {
        func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
        return;
    }
    func_02057df8();
}

/* Draw frame 26 of obj at (x, 0) with the given alpha, prio 2 (func_0205dee8). */
void func_020dddf4(u32 obj, int x, u32 alpha)
{
    func_0205dee8(2, obj, 0x1a, x, 0, 0x3f800000, 0x3f800000, 0, alpha, 2);
}

/* Look up group (a, b) and, after func_02063920, run each of the n ids through func_0204fed8 and
 * func_02063a30; the last result goes to func_02061f10 for obj. Does nothing when n is 0. */
void func_020dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n)
{
    u32 last;
    u32 tab;
    u32 i;
    if (n == 0) {
        return;
    }
    tab = func_020445f4(a, b);
    func_02063920();
    for (i = 0; i < n; i++) {
        last = func_02063a30(func_0204fed8(tab, ids[i]));
    }
    func_02061f10(obj, -1, 0, 0, last);
}
