/*
 * src/game/unit_0209974c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk09974cWork {
    u8 unk_0000[0x20];
    u16 UnkField0020;
} Unk09974cWork;


int func_0209993c();

int Unk09974c_Unk_099860(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_099870(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_099880(Unk09974cWork *work,int arg1);
int Unk09974c_Unk_099890(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_0998a0(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_0998b0(u16 *arg0,u16 *arg1);
int Unk09974c_Unk_0998d8(void);

/* decompiler-derived */
int Unk09974c_Unk_099860(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_099870(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_099880(Unk09974cWork *work,int arg1)
{
  return (u32)work->UnkField0020 - (u32)((Unk09974cWork *)arg1)->UnkField0020;
}

/* decompiler-derived */
int Unk09974c_Unk_099890(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_0998a0(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int Unk09974c_Unk_0998b0(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

typedef struct Unk09974cEntry {
    s32 lo;
    s32 hi;
    u8 unk_0008;
    u8 unk_0009;
    u8 pad_000a[0x2];
} Unk09974cEntry;

Unk09974cEntry *Unk09974c_FindEntry(int id);

u8 Unk09974c_GetEntryUnk08(u32 id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    if (e != 0) {
        return e->unk_0008;
    }
    return 0;
}

/* decompiler-derived */
int Unk09974c_Unk_0998d8(void)
{
  int value;
  value = func_0209993c();
  return 0 < value;
}


int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
u32 Unk09974c_Unk_099bac(int arg0)
{
  u32 value;
  if (arg0 != 0) {
    value = func_020445f4(6,0);
    value = func_0204fed8(value,arg0);
    return value;
  }
  return 0;
}


/* decompiler-derived */
u32 Unk09974c_Unk_099bd4(int arg0)
{
  u32 value;
  if (arg0 != 0) {
    value = func_020445f4(7,0);
    value = func_0204fed8(value,arg0);
    return value;
  }
  return 0;
}

int func_02008848();
int func_020629c4();
/* decompiler-derived */
void Unk09974c_Unk_09974c(int *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_020629c4(arg0[4]);
  arg0[4] = 0;
  func_02008848(arg0,0,0x48);
}




int Unk02e000_GetSubBlock3a4();
extern u8 data_0213bdec[];
int func_02099d14();
int func_02099bfc();
typedef struct Unk09974cStat {
    u8 pad_0000[0x4];
    u32 unk_04 : 10;
    u32 unk_04_rest : 22;
    u8 pad_0008[0x6];
    u16 unk_0e;
} Unk09974cStat;

typedef struct Unk09974cKind {
    u8 pad_0000[0x2a];
    u8 kind : 7;
    u8 kind_hi : 1;
} Unk09974cKind;
Unk09974cEntry *Unk09974c_FindEntry(int id)
{
    Unk09974cEntry *t = (Unk09974cEntry *)data_0213bdec;
    u32 j;
    for (j = 0; j < 10; j++) {
        if (t[j].lo <= id && id <= t[j].hi) {
            return &((Unk09974cEntry *)data_0213bdec)[j];
        }
    }
    return 0;
}

/* decompiler-derived */
int Unk09974c_Unk_0997c8(u32 arg0)
{
  int value;
  value = Unk02e000_GetSubBlock3a4();
  switch(arg0) {
  case 0:
    return value;
  case 1:
    return value + 0xf;
  case 2:
    return value + 0x4b;
  case 3:
    return value + 0x58;
  case 4:
    return value + 0x8a;
  case 5:
    return value + 0xbc;
  case 6:
    return value + 0xee;
  case 7:
    return value + 0x120;
  case 8:
    return value + 0x4f4;
  case 9:
    return value + 0x5d0;
  default:
    return 0;
  }
}

typedef struct Unk09974cFlags {
    u8 pad_0000[0x4];
    u16 unk_04_lo : 8;          /* +0x04 */
    u16 unk_04_mid : 4;         /* +0x04 bits 8..11 */
    u16 unk_04_hi : 4;
} Unk09974cFlags;

int Unk09974c_Unk_0998f0(int id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    int n;
    if (e == 0) {
        return 0;
    }
    n = func_0209993c(id);
    if (n == 0) {
        return 0;
    }
    if (e->unk_0009 == 1 && n < 99) {
        return 0;
    }
    return 1;
}

s32 Unk09974c_Unk_099cc4(Unk09974cStat *p)
{
    u32 v = p->unk_04;
    u32 r;
    s32 q;
    if (v == 0) {
        return 0;
    }
    r = p->unk_0e;
    if (r == 0) {
        return 0;
    }
    if (r == 100) {
        return v;
    }
    q = (v * r) / 100;
    if (q <= 0) {
        q = 1;
    }
    return q;
}

int Unk09974c_Unk_09a090(int id)
{
    if (id >= 51 && id <= 110) {
        u8 v = ((u8 *)func_02099d14(id))[45];
        if (v != 0) {
            return 1;
        }
    }
    return 0;
}

int Unk09974c_Unk_09a0c0(int id)
{
    if (id >= 51 && id <= 110) {
        u8 v = ((u8 *)func_02099d14(id))[45];
        if (v == 1 || v == 3) {
            return 1;
        }
    }
    return 0;
}

int Unk09974c_IsKind1or14(Unk09974cKind *p)
{
    u32 v = p->kind;
    return v == 14 || v == 1;
}

int Unk09974c_HasFlagsMid(Unk09974cFlags *f)
{
    return f->unk_04_mid != 0;
}

int Unk09974c_GetFlagsMidMinus1(Unk09974cFlags *f)
{
    if (Unk09974c_HasFlagsMid(f) == 0) {
        return -1;
    }
    return f->unk_04_mid - 1;
}

void Unk09974c_SetBit6ac(int id)
{
    u8 *b = (u8 *)Unk02e000_GetSubBlock3a4();
    s32 k = id - 51;
    s32 i = k >> 3;
    u8 *f;
    if (i >= 162) {
        return;
    }
    f = b + 684 + 1024;
    f[i] |= (u8)(1 << (k & 7));
}
