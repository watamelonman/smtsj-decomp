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

/* Byte pairs copied as a block (see CampStatus_Copy168 / CampStatus_Copy176). */
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

/* Unit record at CampStatusWork.unk_00cc (also the argument of CampStatus_Unk_0ddb04). */
typedef struct CampStatusUnit {
    u8 pad_0000[0x28];
    u16 unk_0028[6];            /* +0x28: id list, 0-terminated */
    u8 pad_0034[0x2];
    u16 unk_0036;               /* +0x36: id passed to func_020a1428 */
} CampStatusUnit;

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
    u8 pad_0098[0x24];
    void *unk_00bc;             /* +0xbc..+0xc8: draw objects passed to CampStatus_Unk_0dde3c */
    void *unk_00c0;
    void *unk_00c4;
    void *unk_00c8;
    CampStatusUnit *unk_00cc;
    u16 unk_00d0;
    u8 pad_00d2[0x8];
    u16 unk_00da;               /* +0xda: id passed to func_020a1740 */
    u8 pad_00dc[0x14];
    s8 unk_00f0;                /* +0xf0: record index into func_020a1740's result */
    u8 pad_00f1[0x3];
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
    u8 pad_0180[0x20];
    u32 unk_01a0;
    u8 pad_01a4[0x4];
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
    s32 unk_0268;               /* +0x268: set by CampStatus_Unk_0dcad4 */
} CampStatusWork;                /* 0x26c bytes: the size CampStatus_Unk_0d3624 registers */

/* Cell returned by Unk038fbc_Unk_039160; bits 12..15 of the word at +4 select a flag. */
typedef struct CampStatusCell {
    u32 unk_00;
    u32 pad_bits : 12;
    u32 flag : 4;
    u32 pad_hi : 16;
} CampStatusCell;

/* Object handled by the four-entry table at 0x0213c1d8 (CampStatus_GetUnkField7494,
 * CampStatus_Unk_0dcb68, func_020dcc00, func_020dd0a4); a different object from CampStatusWork. */
typedef struct CampStatusTableWork {
    u8 pad_0000[0x240];
    u8 unk_0240[0x7242];        /* +0x240: object passed to Unk038fbc_Unk_039160; size from the next field */
    s8 unk_7482;                /* +0x7482/+0x7483: (x, y) passed with unk_0240 */
    s8 unk_7483;
    s32 unk_7484;               /* +0x7484: set to 60 when a new flag is raised */
    u8 pad_7488[0xc];
    u32 unk_7494;
} CampStatusTableWork;

extern CampStatusWork *data_02176be4;

/* Record list returned by func_020a1740: three 6-byte records from +0x48. */
typedef struct CampStatusRecord {
    u16 id;
    u8 pad_02[0x4];
} CampStatusRecord;
typedef struct CampStatusRecordSet {
    u8 pad_0000[0x48];
    CampStatusRecord rec[3];
} CampStatusRecordSet;
/* Work area from Unk02e000_GetWorkArea; only the flag-set word is used here. */
typedef struct CampStatusWorkArea {
    u8 pad_0000[0x35c];
    u16 unk_035c;
} CampStatusWorkArea;
extern char data_021507cc[];
extern char data_021507d0[];
extern char data_021507d4[];
extern char data_021507dc[];
extern u32 data_0213c568[];
void func_02057ddc(u32 color);
char *func_020a9e14(int mode, const char *format, ...);
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5, u32 resource, u32 count);
int Unk09974c_Unk_0998d8(u32 id);
int func_0204faf0(u32 a, u32 b);
CampStatusRecordSet *func_020a1740(u16 id);
s32 Unk02e000_GetRecordUnk1e(u32 id);
void Unk0ddeb0_Unk_0ddf0c(void *obj);
CampStatusCell *Unk038fbc_Unk_039160(u8 *grid, int x, int y);
CampStatusWorkArea *Unk02e000_GetWorkArea(void);
int Unk0e651c_TestFlag(u32 set, u32 bit);
void Unk0e651c_SetFlag(u32 set, u32 bit, int value);
void ScanVisor_Unk_0a2ab0(void);
void ScanVisor_Unk_0a2ae8(u32 a, int b);

u32 CampStatus_GetUnkField1c(CampStatusWork *work);
u32 CampStatus_GetUnkField7494(CampStatusTableWork *work);

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
u32 CampStatus_GetUnkField7494(CampStatusTableWork *work)
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
/* Callback table filled by CampStatus_Unk_0d3624. */
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
    u8 unk_02;
    u8 pad_03[0x2];
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
void CampStatus_Unk_0dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n);
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
u32 CampStatus_Unk_0d353c(void *obj)
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

int CampStatus_Unk_0d35c0(void *obj, s32 *x, s32 *y)
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
void CampStatus_Unk_0d3624(CampStatusOps *o)
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
void CampStatus_Copy168(const CampStatusPairs6 *src)
{
    data_02176be4->unk_0168 = *src;
}

/* Copy five byte pairs into the shared work at +0x176. */
void CampStatus_Copy176(const CampStatusPairs5 *src)
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
/* Draw two numbers (a at x 24, b at x 86, y 27) with func_020a9fd8, after resetting the colour. */
void CampStatus_Unk_0da670(u32 a, u32 b)
{
    func_02057df8();
    func_020a9fd8(1, 24, 27, 2, (u32)func_020a9e14(1, data_021507cc), 10, (u32)data_021507d0, a);
    func_020a9fd8(1, 86, 27, 2, (u32)func_020a9e14(1, data_021507d4, 0), 10, (u32)data_021507dc, b);
}

u8 CampStatus_Unk_0db214(s32 t)
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
u8 CampStatus_Unk_0db288(s32 t)
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
u8 CampStatus_Unk_0db2dc(s32 t)
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

/* Set the text colour for a compared value: mode 1 compares b against a, mode 3 b against c
 * (green 0x8cff4a00 when larger, red 0xff290000 when smaller), mode 2 is green when c > 0.
 * Equal values (and other modes) keep the default colour from func_02057df8. */
void CampStatus_Unk_0db3e0(s32 a, s32 b, s32 c, s32 mode)
{
    func_02057df8();
    if (mode == 1) {
        if (b > a) {
            func_02057ddc(0x8cff4a00);
        } else if (b < a) {
            func_02057ddc(0xff290000);
        }
        return;
    }
    if (mode == 2) {
        if (c > 0) {
            func_02057ddc(0x8cff4a00);
        }
        return;
    }
    if (mode == 3) {
        if (b > c) {
            func_02057ddc(0x8cff4a00);
        } else if (b < c) {
            func_02057ddc(0xff290000);
        }
    }
}

/* Show icon data_0213c568[3] on unk_00c8 when Unk09974c_Unk_0998d8(unk_00d0) is 0; otherwise
 * show data_0213c568[0], or 7 after func_0204faf0(10, id) when id is not 0xffff. */
void CampStatus_Unk_0dbd04(CampStatusWork *work, u32 id)
{
    u32 other;
    u32 icon;
    if (Unk09974c_Unk_0998d8(work->unk_00d0) == 0) {
        other = data_0213c568[3];
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &other, 1);
        return;
    }
    icon = data_0213c568[0];
    if (id != 0xffff) {
        icon = 7;
        func_0204faf0(10, id);
    }
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}

/* For ids 8..10 only: show entry id of group (14, 0) on work->unk_00c8 via CampStatus_Unk_0dde3c. */
void CampStatus_Unk_0dbf24(CampStatusWork *work, u32 id)
{
    u32 ids[1];
    if (id < 8) {
        return;
    }
    if (id > 10) {
        return;
    }
    ids[0] = id;
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, ids, 1);
}

/* Show the unit's entries: the byte at +2 of its func_020a1428 entry on unk_00bc, its id on
 * unk_00c0, and its 0-terminated id list (up to 6) on unk_00c4. */
void CampStatus_Unk_0dc240(CampStatusWork *work)
{
    u32 ids[6];
    u32 i;
    ids[0] = func_020a1428(work->unk_00cc->unk_0036)->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00cc->unk_0036;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    for (i = 0; i < 6; i++) {
        if (work->unk_00cc->unk_0028[i] == 0) {
            break;
        }
        ids[i] = work->unk_00cc->unk_0028[i];
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}

/* On unk_00c4: entry 201 of group (12, 0), then each non-zero record id (up to 3) of
 * func_020a1740(unk_00da) from group (6, 0). */
void CampStatus_Unk_0dc4a8(CampStatusWork *work)
{
    u32 tabA = func_020445f4(6, 0);
    u32 tabB = func_020445f4(12, 0);
    CampStatusRecordSet *rs = func_020a1740(work->unk_00da);
    u32 last;
    u32 i;
    func_02063920();
    last = func_02063a30(func_0204fed8(tabB, 201));
    if (rs != 0) {
        for (i = 0; i < 3; i++) {
            if (rs->rec[i].id != 0) {
                last = func_02063a30(func_0204fed8(tabA, rs->rec[i].id));
            }
        }
    }
    func_02061f10(work->unk_00c4, -1, 0, 0, last);
}

/* When unk_01a0 is set: show the selected record id (group 7) on unk_00c8 if the record exists
 * and Unk02e000_GetRecordUnk1e(unk_00da) is at least 100, else clear it via Unk0ddeb0_Unk_0ddf0c. */
void CampStatus_Unk_0dc540(CampStatusWork *work)
{
    CampStatusRecordSet *rs;
    u32 ids[1];
    if (work->unk_01a0 == 0) {
        return;
    }
    rs = func_020a1740(work->unk_00da);
    if (rs != 0 && rs->rec[work->unk_00f0].id != 0 && Unk02e000_GetRecordUnk1e(work->unk_00da) >= 100) {
        ids[0] = rs->rec[work->unk_00f0].id;
        CampStatus_Unk_0dde3c(work->unk_00c8, 7, 0, ids, 1);
        return;
    }
    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
}

/* Reset the flag at +0xf4 and the ten s16 values at +0xfc..+0x10e to their start values. */
void CampStatus_Unk_0dca50(CampStatusWork *work)
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
void CampStatus_Unk_0dcad4(s32 on)
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
/* Handler 2 of the table at 0x0213c1d8: look up the cell at (unk_7482, unk_7483); if its 4-bit
 * flag number n is non-zero and work-area flag n + 55 is not set yet, set it, call
 * ScanVisor_Unk_0a2ab0 and start the 60-tick unk_7484 timer. Always ends with
 * ScanVisor_Unk_0a2ae8(3, 2) and returns 1. */
int CampStatus_Unk_0dcb68(CampStatusTableWork *work)
{
    CampStatusCell *c = Unk038fbc_Unk_039160(work->unk_0240, work->unk_7482, work->unk_7483);
    u32 n;
    work->unk_7484 = 0;
    if (c != 0 && (n = c->flag) != 0) {
        if (Unk0e651c_TestFlag(Unk02e000_GetWorkArea()->unk_035c, n + 55) == 0) {
            Unk0e651c_SetFlag(Unk02e000_GetWorkArea()->unk_035c, n + 55, 1);
            ScanVisor_Unk_0a2ab0();
            work->unk_7484 = 60;
        }
    }
    ScanVisor_Unk_0a2ae8(3, 2);
    return 1;
}

/* Like CampStatus_Unk_0ddb9c with the unit's id: grey for an empty entry, own colours for
 * kinds 4 and 5, grey otherwise. */
void CampStatus_Unk_0ddb04(CampStatusUnit *unit)
{
    CampStatusEntry *e = func_020a1428(unit->unk_0036);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        func_02057dcc(0x18525aff, 0x18525aff, 0x18525aff, 0x18525aff);
        return;
    }
    if (e->kind == 5) {
        func_02057dcc(0x5a3129ff, 0x5a3129ff, 0x5a3129ff, 0x5a3129ff);
        return;
    }
    func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
}

void CampStatus_Unk_0ddb9c(int id)
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
void CampStatus_Unk_0dddf4(u32 obj, int x, u32 alpha)
{
    func_0205dee8(2, obj, 0x1a, x, 0, 0x3f800000, 0x3f800000, 0, alpha, 2);
}

/* Look up group (a, b) and, after func_02063920, run each of the n ids through func_0204fed8 and
 * func_02063a30; the last result goes to func_02061f10 for obj. Does nothing when n is 0. */
void CampStatus_Unk_0dde3c(void *obj, u32 a, u32 b, const u32 *ids, u32 n)
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
