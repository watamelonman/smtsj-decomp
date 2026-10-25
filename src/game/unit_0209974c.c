#include "types.h"

#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Borrowed record view; the subtraction routines require a readable first halfword. */
typedef struct Unk09974cRecord {
    u16 unk_00;
} Unk09974cRecord;

/* Borrowed record view for the halfword loaded at +0x20. */
typedef struct Unk09974cRecord20 {
    u8 padding_00[0x20];
    u16 unk_20;
} Unk09974cRecord20;

/* Range-table entry: FindEntry tests the inclusive bounds and returns this view. */
typedef struct Unk09974cEntry {
    s32 lo;
    s32 hi;
    u8 unk_0008;
    u8 unk_0009;
    u8 padding_0a[2];
} Unk09974cEntry;

extern Unk09974cEntry *Unk09974c_FindEntry(int id);
extern s32 func_0209993c(u32 id);

/* Subtract unsigned halfwords at +0; evidence: loads at 0x02099860/64. */
s32 Unk09974c_Unk_099860(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x02099870/74. */
s32 Unk09974c_Unk_099870(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0x20; evidence: loads at 0x02099880/84. */
s32 Unk09974c_Unk_099880(const Unk09974cRecord20 *left, const Unk09974cRecord20 *right)
{
    return left->unk_20 - right->unk_20;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x02099890/94. */
s32 Unk09974c_Unk_099890(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x020998a0/a4. */
s32 Unk09974c_Unk_0998a0(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x020998b0/b4. */
s32 Unk09974c_Unk_0998b0(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Return entry byte +8, or zero for an absent id (0x020998c4..d0). */
u32 Unk09974c_GetEntryUnk08(u32 id)
{
    Unk09974cEntry *entry = Unk09974c_FindEntry(id);
    return entry != 0 ? entry->unk_0008 : 0;
}

/* Return whether the helper result is signed-positive (0x020998dc..e8). */
s32 Unk09974c_Unk_0998d8(u32 id)
{
    return func_0209993c(id) > 0;
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
void *Unk09974c_Unk_099d14(int id);
void *Unk09974c_Unk_099bfc(int id);
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

typedef struct Unk09974cRec8 {
    u16 id;
    u8 pad_02[3];
    u8 unk_05;
    u8 pad_06[2];
} Unk09974cRec8;
typedef struct Unk09974cRec16 {
    u16 id;
    u8 pad_02[14];
} Unk09974cRec16;
typedef struct Unk09974cRec56 {
    u8 pad_00[32];
    u16 id;
    u8 pad_22[22];
} Unk09974cRec56;
typedef struct Unk09974cRec80 {
    u16 id;
    u8 unk_02;
    u8 pad_03[20];
    u8 f0 : 1;                  /* +0x17 */
    u8 f1 : 1;
    u8 f2 : 1;
    u8 : 5;
    u8 pad_18[56];
} Unk09974cRec80;
void *func_020445d0();
void *func_0204fde0();
int func_0204fe18();
void *func_02011810();

void Unk09974c_SetBit6ac(int id);

u32 Unk09974c_Unk_0999d4(int id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u16 *buf;
    int off;
    if (e == 0) {
        return 0;
    }
    buf = (u16 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0:
    case 1:
        break;
    case 2:
        return buf[off];
    }
    return 0;
}

void Unk09974c_Unk_099abc(int id, u16 v)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u16 *buf;
    int off;
    if (e == 0 || v == 0) {
        return;
    }
    buf = (u16 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0:
    case 1:
        break;
    case 2:
        buf[off] = v;
        break;
    }
    Unk09974c_SetBit6ac(id);
}

void *Unk09974c_Unk_099bfc(int id)
{
    Unk09974cRec8 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 0);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 8, Unk09974c_Unk_099860);
}

void *Unk09974c_Unk_099c60(int id)
{
    Unk09974cRec80 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 2);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 80, Unk09974c_Unk_099870);
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

void *Unk09974c_Unk_099d14(int id)
{
    Unk09974cRec56 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 1);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 56, Unk09974c_Unk_099880);
}

void *Unk09974c_Unk_099d78(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 3);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_099890);
}

void *Unk09974c_Unk_099ddc(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 4);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_0998a0);
}

int Unk02ee5c_GetTierFromField70();
void *Unk02e000_Thunk_0202e788();
int func_0209a158();

void *Unk09974c_Unk_099e40(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 5);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_0998b0);
}

int Unk09974c_Unk_099ea4(int id)
{
    int tier = Unk02ee5c_GetTierFromField70();
    Unk09974cRec80 *r = (Unk09974cRec80 *)Unk09974c_Unk_099c60(id);
    if (r == 0) {
        return 0;
    }
    if (r->f0 && tier == 4) {
        return 1;
    }
    if (r->f2 && tier == 5) {
        return 1;
    }
    if (r->f1 && tier == 1) {
        return 1;
    }
    return 0;
}

void Unk09974c_Unk_099f24(int id)
{
    u16 *w;
    Unk09974cRec80 *r;
    if (Unk09974c_Unk_099ea4(id) == 0) {
        return;
    }
    w = (u16 *)Unk02e000_Thunk_0202e788();
    r = (Unk09974cRec80 *)Unk09974c_Unk_099c60(id);
    if (r->unk_02 == 3) {
        w[0] = id;
    }
    if (r->unk_02 == 4) {
        w[1] = id;
    }
    if (r->unk_02 == 5) {
        w[2] = id;
    }
    if (r->unk_02 == 6) {
        w[3] = id;
    }
}

int Unk09974c_Unk_09a090(int id)
{
    if (id >= 51 && id <= 110) {
        u8 v = ((u8 *)Unk09974c_Unk_099d14(id))[45];
        if (v != 0) {
            return 1;
        }
    }
    return 0;
}

int Unk09974c_Unk_09a0c0(int id)
{
    if (id >= 51 && id <= 110) {
        u8 v = ((u8 *)Unk09974c_Unk_099d14(id))[45];
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

int Unk09974c_Unk_09a1e4(int id)
{
    if (func_0209a158(id) != 0) {
        return 0;
    }
    switch (Unk09974c_GetEntryUnk08(id)) {
    case 0:
        return ((Unk09974cRec8 *)Unk09974c_Unk_099bfc(id))->unk_05;
    case 8:
    case 9:
        return 1;
    }
    return 0;
}
