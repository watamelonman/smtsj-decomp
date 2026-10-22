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
    u8 pad_0000[0x1e];
    s16 unk_001e;               /* +0x1e: compared > 0 by func_020dd9d8 */
    u8 pad_0020[0x8];
    u16 unk_0028[6];            /* +0x28: id list, 0-terminated */
    u16 unk_0034;               /* +0x34: values 1 and 7 are treated alike by func_020dd9d8 */
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
    u8 pad_007c[0x8];
    u32 unk_0084;               /* +0x84/+0x88/+0x90: handles released by func_020dc908 */
    u32 unk_0088;
    u8 pad_008c[0x4];
    u32 unk_0090;
    CampStatusAnim *unk_0094;
    u8 pad_0098[0x4];
    u32 unk_009c;               /* +0x9c/+0xa0/+0xa8/+0xac: released by func_020dc908 */
    u32 unk_00a0;
    u8 pad_00a4[0x4];
    u32 unk_00a8;
    void *unk_00ac;
    u8 pad_00b0[0xc];
    void *unk_00bc;             /* +0xbc..+0xc8: draw objects passed to CampStatus_Unk_0dde3c */
    void *unk_00c0;
    void *unk_00c4;
    void *unk_00c8;
    CampStatusUnit *unk_00cc;
    u16 unk_00d0;
    u8 unk_00d2[0x8];           /* +0xd2: passed to func_020da710; size from the next field */
    u16 unk_00da;               /* +0xda: id passed to func_020a1740 */
    u16 unk_00dc[6];            /* +0xdc: id list filled by func_020a18c8 */
    u32 unk_00e8;
    u8 pad_00ec[0x4];
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
    f32 unk_0110;               /* +0x110: alpha passed to func_0205dee8 */
    u8 pad_0114[0x54];
    CampStatusPairs6 unk_0168;
    u8 pad_0174[0x2];
    CampStatusPairs5 unk_0176;
    u8 pad_0180[0xc];
    u32 unk_018c;               /* +0x18c: CampStatus_Unk_0d6948 draws only when set */
    u8 pad_0190[0x10];
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
    u32 unk_025c;               /* +0x25c: selects the id list in func_020dc3b8 */
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

/* Record buffer filled by Unk02e000_SetRecord (36 bytes on the stack in func_020dc3b8). */
typedef struct CampStatusSavedRecord {
    u8 pad_0000[0x10];
    u16 unk_0010[6];            /* +0x10: id list, 0-terminated */
    u8 pad_001c[0x8];
} CampStatusSavedRecord;
int Unk02e000_SetRecord(u32 id, CampStatusSavedRecord *out);
void func_0204fcb0(u32 slot, u32 v);
void func_0205bb68(void);
void func_02053000(u32 handle);
void func_0205ddb4(u32 handle);
void func_0205c368(u32 handle);
void func_02061424();

/* Opaque grey RGBA: v in all three colour bytes, alpha 0xff. */
#define CAMP_GREY(v) (((v) << 24) + ((v) << 16) + ((v) << 8) + 0xff)
/* Player-side record from Unk02e000_Thunk_0202e788 (fields as used in this file). */
typedef struct CampStatusPlayer {
    u16 unk_0000;               /* +0x00/+0x02: ids passed to Unk09974c_Unk_099c60 */
    u16 unk_0002;
    u8 pad_0004[0x18];
    s16 unk_001c;               /* +0x1c: compared > 0 by CampStatus_Unk_0dd910 */
    u8 pad_001e[0x2a];
    char unk_0048[0x24];        /* +0x48: text passed to func_02061f10; size guessed */
    u16 unk_006c;               /* +0x6c: values 1 and 7 are treated alike by CampStatus_Unk_0dd910 */
} CampStatusPlayer;
/* Record from Unk09974c_Unk_099c60. */
typedef struct CampStatusInfo {
    u8 pad_0000[0x2];
    u8 unk_0002;                /* +0x02: 3 and 4 select the slot set in func_020db910 */
    u8 pad_0003;
    u32 pad_04_0 : 20;
    u32 unk_04_20 : 12;         /* +0x04: top 12 bits */
    u8 lo : 4;                  /* +0x08: two nibbles compared by CampStatus_Unk_0db824 */
    u8 hi : 4;
    u8 unk_0009;
    u8 pad_000a;
    u8 unk_000b;
    u8 pad_000c[0x34];
    u16 unk_0040[3];            /* +0x40: id list, 0-terminated */
} CampStatusInfo;
/* Values subtracted and clamped at 0 by CampStatus_Unk_0dc5dc. */
typedef struct CampStatusStats {
    s16 unk_00;
    s16 unk_02;
    s8 unk_04;
    s8 unk_05;
    s8 unk_06;
    s8 unk_07;
    s8 unk_08;
} CampStatusStats;
/* Global at data_0215f05c; +0x18 is a running tick count fed to the ramp helpers. */
typedef struct CampStatusTicker {
    u8 pad_0000[0x18];
    s32 unk_0018;
} CampStatusTicker;
extern CampStatusTicker data_0215f05c;
extern u8 data_0213c600[];
void func_02057fd8(void);
void func_02057df8(void);
void func_02057e18(u32 alpha);
void func_02057eb8(s32 v);
void func_0205dee8(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_0205de40(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_02058e9c(int screen, u32 res, int x, int y, float scale, int a, int b);
void func_02058f10(int screen, u32 res, int x, int y, int w, int h, int c);
CampStatusPlayer *Unk02e000_Thunk_0202e788(void);
CampStatusInfo *Unk09974c_Unk_099c60(u32 id);
void func_02008644(u32 value, void *dst, u32 size);
int func_020a18c8(u16 id, u16 *out, u32 n);
void Unk0ddeb0_Unk_0ddeb0(void *obj, int a, int b, int c, int d, int e);
s32 Unk02ee5c_GetTierFromField70(void);
int func_020523a8(void);
u32 Unk0ddeb0_Unk_0ddfd8(u32 i);
u32 Unk0ca69c_Unk_0ca6a4(u32 v);
void func_020db910(CampStatusInfo *info);
void func_020da710();
u8 CampStatus_Unk_0db288(s32 t);

/* Record list returned by func_020a1740: three 6-byte records from +0x48. */
typedef struct CampStatusRecord {
    u16 id;
    u8 pad_02[0x4];
} CampStatusRecord;
typedef struct CampStatusRecordSet {
    u8 pad_0000[0x16];
    u16 pad_16_0 : 5;           /* +0x16: three small values */
    u16 unk_16_5 : 4;
    u16 unk_16_9 : 3;
    u16 unk_16_c : 3;
    u16 pad_16_f : 1;
    u8 unk_0018;
    u8 pad_0019;
    u8 unk_001a;
    u8 pad_001b[0x2d];
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
    u8 pad_03;
    u8 unk_04;
    u8 kind;                    /* +0x05: 4 and 5 get their own colours */
    u8 pad_06[0x4];
    u16 pad_0a_0 : 1;           /* +0x0a: three small values */
    u16 unk_0a_1 : 4;
    u16 unk_0a_5 : 3;
    u16 unk_0a_8 : 3;
    u16 pad_0a_b : 5;
    u8 unk_0c;
    u8 pad_0d;
    u8 unk_0e;
    u8 pad_0f[0x1f];
    u16 unk_002e[6];            /* +0x2e: id list, 0-terminated */
} CampStatusEntry;
void func_020d5644();
void func_020d5d44();
void func_020d6120();
void CampStatus_Unk_0d6948();
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
    o->fn_18 = CampStatus_Unk_0d6948;
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

/* Handler 0x18 of the CampStatus_Unk_0d3624 table: when unk_018c is set and func_020523a8()
 * is 1, draw six grey gradient bars (frame 0, 32 px apart), then run func_020d6120. */
void CampStatus_Unk_0d6948(CampStatusWork *work)
{
    int i;
    if (work->unk_018c == 0) {
        return;
    }
    if (func_020523a8() != 1) {
        return;
    }
    func_02057eb8(-1);
    func_02057fd8();
    func_02057df8();
    for (i = 0; i < 6; i++) {
        /* bar i fades from shade i (top) to shade i + 1 (bottom); shade n = 25 + 38 * n */
        u32 top = CAMP_GREY(i * 38 + 25);
        u32 bottom = CAMP_GREY((i + 1) * 38 + 25);
        func_02057dcc(top, bottom, bottom, top);
        func_0205dee8(2, work->unk_001c, 0, 0, i * 32, 1.0f, 1.0f, 0, 1.0f, 0);
    }
    func_020d6120(work);
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


/* decompiler-derived: frames 0x10..0x12 of obj at (x, 0), alpha a. */
void CampStatus_Unk_0ddd2c(u32 obj, int x, float alpha)
{
  func_0205dee8(2, obj, 0x10, x, 0, 1.0f, 1.0f, 0, alpha, 2);
  func_02057fd8();
  func_0205dee8(2, obj, 0x11, x, 0, 1.0f, 1.0f, 0, alpha, 3);
  func_02057fd8();
  func_0205dee8(2, obj, 0x12, x, 0, 1.0f, 1.0f, 0, alpha, 4);
}

/* decompiler-derived */
void CampStatus_Unk_0d71bc(CampStatusWork *work)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2, work->unk_0018, 0x2b, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x2c, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x2d, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_02057e18(0x1f);
  func_0205dee8(2, work->unk_0018, 0x2e, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x2f, 0, work->unk_010c, 1.0f, 1.0f, 0, 1.0f, 3);
}

/* decompiler-derived */
void CampStatus_Unk_0d7680(CampStatusWork *work)
{
  func_02057fd8();
  func_02057df8();
  func_0205dee8(2, work->unk_0018, 5, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x41, work->unk_00fe, 0, 1.0f, 1.0f, 0, work->unk_0110, 3);
  func_0205dee8(2, work->unk_0018, 0x22, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x23, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x24, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x25, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x26, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x27, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
  func_0205dee8(2, work->unk_0018, 0x21, 0, work->unk_010c, 1.0f, 1.0f, 0, work->unk_0110, 2);
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
/* Draw the labels on unk_00c0 (grey when Unk09974c_Unk_0998d8(unk_00d0) is 0), the list on
 * unk_00c4 (func_020da710, selection unk_00f0 when unk_00e8 is set, else -1) and, when unk_0008
 * is set, two more labels on unk_00c8. */
void CampStatus_Unk_0d8d60(CampStatusWork *work)
{
    if (Unk09974c_Unk_0998d8(work->unk_00d0) == 0) {
        func_02057ddc(0x7b7b7bff);
    } else {
        func_02057df8();
    }
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c0, 42, 14, 0, 8, 10);
    func_02057df8();
    func_020da710(work->unk_00c4, work->unk_00d2, 0, work->unk_00e8 != 0 ? work->unk_00f0 : -1);
    if (work->unk_0008 == 0) {
        return;
    }
    func_02057df8();
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 168, 0, 23, 10);
    Unk0ddeb0_Unk_0ddeb0(work->unk_00c8, 13, 180, 1, 23, 10);
}

/* Draw two numbers (a at x 24, b at x 86, y 27) with func_020a9fd8, after resetting the colour. */
void CampStatus_Unk_0da670(u32 a, u32 b)
{
    func_02057df8();
    func_020a9fd8(1, 24, 27, 2, (u32)func_020a9e14(1, data_021507cc), 10, (u32)data_021507d0, a);
    func_020a9fd8(1, 86, 27, 2, (u32)func_020a9e14(1, data_021507d4, 0), 10, (u32)data_021507dc, b);
}

/* When sel >= 0, draw the pulsing cursor bar at row sel (85 px per row, alpha from the
 * CampStatus_Unk_0db288 ramp); then draw the three slots of obj. */
void CampStatus_Unk_0da8c4(void *obj, u32 unused, s32 sel)
{
    s32 i;
    if (sel >= 0) {
        func_02057df8();
        func_02057e18(CampStatus_Unk_0db288(data_0215f05c.unk_0018));
        func_02058f10(2, 0x1dd4, sel * 85, 13, 83, 12, 9);
        func_02057e18(31);
    }
    func_02057fd8();
    for (i = 0; i < 3; i++) {
        func_02057df8();
        Unk0ddeb0_Unk_0ddeb0(obj, i * 85 + 4, 153, i, 8, 10);
    }
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
/* For a non-zero idx: draw frame 6 of obj, the resource for Unk0ddeb0_Unk_0ddfd8(idx) at
 * (109, 13), and frame data_0213c600[idx] of obj2. */
void CampStatus_Unk_0db478(u32 obj, u32 obj2, u32 idx)
{
    if (idx == 0) {
        return;
    }
    func_0205dee8(2, obj, 6, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_02057e18(31);
    func_02057df8();
    func_02058e9c(2, Unk0ca69c_Unk_0ca6a4(Unk0ddeb0_Unk_0ddfd8(idx)), 109, 13, 1.0f, 0, 3);
    func_0205de40(2, obj2, data_0213c600[idx], 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
}

/* For both player ids (+0x00, +0x02): pick icon 1/0 (resp. 3/2) by whether the record's two
 * nibbles differ and run func_020db910 on it; show both icons on unk_00c8 only when both ids
 * are set, else clear it. */
void CampStatus_Unk_0db824(CampStatusWork *work)
{
    u32 icons[2] = {0, 0};
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    CampStatusInfo *info;
    if (p->unk_0000 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0000)) != 0) {
        if (info->lo != info->hi) {
            icons[0] = 1;
        } else {
            icons[0] = 0;
        }
        func_020db910(info);
    }
    if (p->unk_0002 != 0 && (info = Unk09974c_Unk_099c60(p->unk_0002)) != 0) {
        if (info->lo != info->hi) {
            icons[1] = 3;
        } else {
            icons[1] = 2;
        }
        func_020db910(info);
    }
    if (p->unk_0000 != 0 && p->unk_0002 != 0) {
        CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, icons, 2);
        return;
    }
    Unk0ddeb0_Unk_0ddf0c(work->unk_00c8);
}

/* Push info's values into the slots via func_0204fcb0/func_0204faf0: entries of groups (14, 1),
 * (14, 2) and (14, 3) go to slots 1-3 when unk_0002 is 3 and to slots 4-6 when it is 4; the
 * nibbles go through func_0204faf0 (the high one only when it differs). */
void func_020db910(CampStatusInfo *info)
{
    u32 v;
    if (info == 0) {
        return;
    }
    v = func_0204fed8(func_020445f4(14, 1), info->unk_0009);
    if (info->unk_0002 == 3) {
        func_0204fcb0(1, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(4, v);
    }
    if (info->unk_0002 == 3) {
        func_0204faf0(1, info->lo);
        if (info->lo != info->hi) {
            func_0204faf0(2, info->hi);
        }
    }
    if (info->unk_0002 == 4) {
        func_0204faf0(3, info->lo);
        if (info->lo != info->hi) {
            func_0204faf0(4, info->hi);
        }
    }
    v = func_0204fed8(func_020445f4(14, 2), info->unk_04_20);
    if (info->unk_0002 == 3) {
        func_0204fcb0(2, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(5, v);
    }
    v = func_0204fed8(func_020445f4(14, 3), info->unk_000b);
    if (info->unk_0002 == 3) {
        func_0204fcb0(3, v);
    }
    if (info->unk_0002 == 4) {
        func_0204fcb0(6, v);
    }
}

/* Fill slots 1-5 from entry id's values (groups (14, 1..4)) and show icon data_0213c568[4] on
 * unk_00c8, or icon 5 when the two 3-bit values at +0x0a differ. */
void func_020dba84(CampStatusWork *work, u16 id)
{
    u32 icon = data_0213c568[4];
    CampStatusEntry *e = func_020a1428(id);
    u32 tab = func_020445f4(14, 4);
    func_0204fcb0(4, func_0204fed8(tab, e->unk_04));
    func_0204fcb0(5, func_0204fed8(tab, e->kind));
    func_0204fcb0(1, func_0204fed8(func_020445f4(14, 1), e->unk_0a_1));
    func_0204faf0(1, e->unk_0a_5);
    if (e->unk_0a_5 != e->unk_0a_8) {
        icon = 5;
        func_0204faf0(2, e->unk_0a_8);
    }
    func_0204fcb0(2, func_0204fed8(func_020445f4(14, 2), e->unk_0c));
    func_0204fcb0(3, func_0204fed8(func_020445f4(14, 3), e->unk_0e));
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}

/* Like func_020dba84, but slots 1-3 and the icon test come from func_020a1740(id) (+0x16..+0x1a)
 * and the default icon is data_0213c568[1]. */
void func_020dbbbc(CampStatusWork *work, u16 id)
{
    u32 icon = data_0213c568[1];
    CampStatusEntry *e = func_020a1428(id);
    CampStatusRecordSet *rs = func_020a1740(id);
    u32 tab = func_020445f4(14, 4);
    func_0204fcb0(4, func_0204fed8(tab, e->unk_04));
    func_0204fcb0(5, func_0204fed8(tab, e->kind));
    func_0204fcb0(1, func_0204fed8(func_020445f4(14, 1), rs->unk_16_5));
    func_0204faf0(1, rs->unk_16_9);
    if (rs->unk_16_9 != rs->unk_16_c) {
        icon = 5;
        func_0204faf0(2, rs->unk_16_c);
    }
    func_0204fcb0(2, func_0204fed8(func_020445f4(14, 2), rs->unk_0018));
    func_0204fcb0(3, func_0204fed8(func_020445f4(14, 3), rs->unk_001a));
    CampStatus_Unk_0dde3c(work->unk_00c8, 14, 0, &icon, 1);
}

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
/* Show icon 43 on unk_00bc, the player's text (+0x48) on unk_00c0, and the 0-terminated id
 * list (up to 3) of the player's second record on unk_00c4. */
void CampStatus_Unk_0dc184(CampStatusWork *work)
{
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    u32 ids[3];
    CampStatusInfo *info;
    u32 i;
    ids[0] = 43;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    func_02061f10(work->unk_00c0, -1, 0, 0, p->unk_0048);
    if (p->unk_0002 == 0) {
        return;
    }
    info = Unk09974c_Unk_099c60(p->unk_0002);
    if (info == 0) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (info->unk_0040[i] == 0) {
            break;
        }
        ids[i] = info->unk_0040[i];
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}

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
/* Like func_020dc240 for record unk_00da: its entry byte on unk_00bc, the id on unk_00c0, and
 * the id list func_020a18c8 writes to unk_00dc (up to 6) on unk_00c4. */
void CampStatus_Unk_0dc2ec(CampStatusWork *work)
{
    u32 ids[6];
    u32 i;
    ids[0] = func_020a1428(work->unk_00da)->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00da;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    func_02008644(0, work->unk_00dc, 12);
    if (func_020a18c8(work->unk_00da, work->unk_00dc, 6) == 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        if (work->unk_00dc[i] == 0) {
            break;
        }
        ids[i] = work->unk_00dc[i];
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}

/* Like func_020dc2ec, but needs the saved record for unk_00da; the id list comes from the
 * entry (+0x2e) when unk_025c is set, else from the saved record (+0x10). */
void func_020dc3b8(CampStatusWork *work)
{
    CampStatusSavedRecord rec;
    u32 ids[6];
    CampStatusEntry *e = func_020a1428(work->unk_00da);
    u32 i;
    if (Unk02e000_SetRecord(work->unk_00da, &rec) == 0) {
        return;
    }
    ids[0] = e->unk_02;
    CampStatus_Unk_0dde3c(work->unk_00bc, 18, 0, ids, 1);
    ids[0] = work->unk_00da;
    CampStatus_Unk_0dde3c(work->unk_00c0, 18, 1, ids, 1);
    if (work->unk_025c != 0) {
        for (i = 0; i < 6; i++) {
            if (e->unk_002e[i] == 0) {
                break;
            }
            ids[i] = e->unk_002e[i];
        }
    } else {
        for (i = 0; i < 6; i++) {
            if (rec.unk_0010[i] == 0) {
                break;
            }
            ids[i] = rec.unk_0010[i];
        }
    }
    CampStatus_Unk_0dde3c(work->unk_00c4, 10, 0, ids, i);
}

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

/* out = a - b field by field, each clamped at 0. */
void CampStatus_Unk_0dc5dc(const CampStatusStats *a, const CampStatusStats *b, CampStatusStats *out)
{
    out->unk_00 = a->unk_00 - b->unk_00;
    if (out->unk_00 < 0) {
        out->unk_00 = 0;
    }
    out->unk_02 = a->unk_02 - b->unk_02;
    if (out->unk_02 < 0) {
        out->unk_02 = 0;
    }
    out->unk_04 = a->unk_04 - b->unk_04;
    if (out->unk_04 < 0) {
        out->unk_04 = 0;
    }
    out->unk_08 = a->unk_08 - b->unk_08;
    if (out->unk_08 < 0) {
        out->unk_08 = 0;
    }
    out->unk_05 = a->unk_05 - b->unk_05;
    if (out->unk_05 < 0) {
        out->unk_05 = 0;
    }
    out->unk_06 = a->unk_06 - b->unk_06;
    if (out->unk_06 < 0) {
        out->unk_06 = 0;
    }
    out->unk_07 = a->unk_07 - b->unk_07;
    if (out->unk_07 < 0) {
        out->unk_07 = 0;
    }
}

/* Release the shared work's resources (two sets of three handles plus three tasks) and clear
 * each field. */
void func_020dc908(void)
{
    func_0205bb68();
    func_02053000(data_02176be4->unk_00a8);
    data_02176be4->unk_00a8 = 0;
    if (data_02176be4->unk_009c != 0) {
        func_0205ddb4(data_02176be4->unk_009c);
        data_02176be4->unk_009c = 0;
    }
    if (data_02176be4->unk_00a0 != 0) {
        func_0205c368(data_02176be4->unk_00a0);
        data_02176be4->unk_00a0 = 0;
    }
    func_02061424(data_02176be4->unk_00ac);
    data_02176be4->unk_00ac = 0;
    func_0205bb68();
    func_02053000(data_02176be4->unk_0090);
    data_02176be4->unk_0090 = 0;
    if (data_02176be4->unk_0084 != 0) {
        func_0205ddb4(data_02176be4->unk_0084);
        data_02176be4->unk_0084 = 0;
    }
    if (data_02176be4->unk_0088 != 0) {
        func_0205c368(data_02176be4->unk_0088);
        data_02176be4->unk_0088 = 0;
    }
    func_02061424(data_02176be4->unk_0094);
    data_02176be4->unk_0094 = 0;
    func_02061424(data_02176be4->unk_002c);
    data_02176be4->unk_002c = 0;
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
/* Colour for the player's line by tier (4, 5, other): the first colour when status +0x6c is
 * 1 or 7 or +0x1c is not positive, the second otherwise (default colour for other tiers). */
void CampStatus_Unk_0dd910(void)
{
    s32 tier = Unk02ee5c_GetTierFromField70();
    CampStatusPlayer *p = Unk02e000_Thunk_0202e788();
    if (tier == 4) {
        if (p->unk_006c == 1 || p->unk_006c == 7 || p->unk_001c <= 0) {
            func_02057ddc(0x18525aff);
        } else {
            func_02057ddc(0x39dccbff);
        }
        return;
    }
    if (tier == 5) {
        if (p->unk_006c == 1 || p->unk_006c == 7 || p->unk_001c <= 0) {
            func_02057ddc(0x5a3129ff);
        } else {
            func_02057ddc(0xff7b63ff);
        }
        return;
    }
    if (p->unk_006c == 1 || p->unk_006c == 7 || p->unk_001c <= 0) {
        func_02057ddc(0x7b7b7bff);
    } else {
        func_02057df8();
    }
}

/* Colour for a unit's line: grey for an empty entry; for kinds 4 and 5 the first colour when
 * status +0x34 is 1 or 7 or +0x1e is not positive, the second otherwise; other kinds grey or
 * the default colour. */
void func_020dd9d8(CampStatusUnit *unit)
{
    CampStatusEntry *e = func_020a1428(unit->unk_0036);
    if (e->unk_00 == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        return;
    }
    if (e->kind == 4) {
        if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
            func_02057dcc(0x18525aff, 0x18525aff, 0x18525aff, 0x18525aff);
        } else {
            func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
        }
        return;
    }
    if (e->kind == 5) {
        if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
            func_02057dcc(0x5a3129ff, 0x5a3129ff, 0x5a3129ff, 0x5a3129ff);
        } else {
            func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
        }
        return;
    }
    if (unit->unk_0034 == 1 || unit->unk_0034 == 7 || unit->unk_001e <= 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
    } else {
        func_02057df8();
    }
}

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

/* Draw a frame of height *rows * 13 at x: top piece (frame 5), two strips (resources 0x1d01
 * and 0x1d00), bottom piece (frame 6) at the last row. */
void func_020ddc20(u32 obj, const s32 *rows, u32 unused, int x, float alpha)
{
    func_02057fd8();
    func_0205dee8(2, obj, 5, x, 0, 1.0f, 1.0f, 0, alpha, 2);
    func_02058f10(2, 0x1d01, x, 0, 99, *rows * 13 - 1, 2);
    func_02058f10(2, 0x1d00, x, 0, 8, *rows * 13 - 1, 2);
    func_0205dee8(2, obj, 6, x, (*rows - 1) * 13, 1.0f, 1.0f, 0, alpha, 2);
}

/* Draw frame 26 of obj at (x, 0) with the given alpha, prio 2 (func_0205dee8). */
void CampStatus_Unk_0dddf4(u32 obj, int x, float alpha)
{
    func_0205dee8(2, obj, 0x1a, x, 0, 1.0f, 1.0f, 0, alpha, 2);
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
