/*
 * src/game/unit_0202e000.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02140ac8[];
extern u32 data_0215dd24[];
void Unk02e000_Unk_02e0cc(void);
u8 *Unk02e000_GetWorkArea(void);
int func_0205a9d0();

void Unk02e000_Nop_02e3e0(void);
u32 Unk02e000_GetAddr_data_02140ac8(void);
u8 *Unk02e000_Thunk_0202e788(void);
void Unk02e000_Set_data_0215dd24(u32 arg0);
u32 Unk02e000_Get_data_0215dd24(void);
u32 Unk02e000_Unk_02e170(void);
void Unk02e000_Unk_02e0ac(void);
int Unk02e000_Unk_02e774(void);
int Unk02e000_Unk_02e8b8(void);
int Unk02e000_Unk_02e8f0(void);

typedef struct Unk02e000Mgr {
    u8 pad_0000[0x38];
    u32 unk_0038;
    u32 unk_003c;
    u8 pad_0040[0x34];
    u32 slots[16];
} Unk02e000Mgr;

Unk02e000Mgr *Unk02dcfc_Thunk_Unk095560_GetManagerAlias(void);

u32 func_02052fe0();

typedef struct Unk02e000Save {
    u8 pad_0000[0x5fc4];
    u32 counter_5fc4;          /* +0x5FC4, capped at 35999999 */
} Unk02e000Save;

typedef struct Unk02e000Rec {
    u8 pad_0000[0xb];
    u8 unk_000b;
    u8 pad_000c[0x10];
    u16 unk_001c;
    u8 unk_001e_0 : 7;
    u8 unk_001e_7 : 1;
    u8 flag_001f_0 : 1;
    u8 flag_001f_1 : 1;
    u8 unk_001f_2 : 6;
    u8 pad_0020[4];
} Unk02e000Rec;                 /* 36 bytes; table at work+0x16FC, ids 1..491 */
#define UNK02E000_RECS() ((Unk02e000Rec *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc))

void Unk02e000_SetSlot(int i, u32 v)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m == 0) {
        return;
    }
    if (i < 0 || i >= 16) {
        return;
    }
    m->slots[i] = v;
}

u32 Unk02e000_GetSlot(int i)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m == 0) {
        return 0;
    }
    if (i < 0 || i >= 16) {
        return 0;
    }
    return m->slots[i];
}

void Unk02e000_SetMgrUnk38(u32 a, u32 b)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m != 0) {
        m->unk_0038 = a;
        m->unk_003c = b;
    }
}

void Unk02e000_ClearMgrUnk38(void)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m != 0) {
        m->unk_0038 = 0;
        m->unk_003c = 0;
    }
}

void Unk02e000_EnsureAlloc7718(void)
{
    if (data_0215dd24[1] != 0) {
        return;
    }
    data_0215dd24[1] = func_02052fe0(0x7718);
}

void Unk02e000_AddCounter5fc4(int add)
{
    Unk02e000Save *w = (Unk02e000Save *)Unk02e000_Unk_02e774();
    u32 v = w->counter_5fc4 + add;
    if (v > 35999999) {
        w->counter_5fc4 = 35999999;
    } else {
        w->counter_5fc4 = v;
    }
}

/* empty callback */
void Unk02e000_Nop_02e3e0(void) { }

/* decompiler-derived */
u32 Unk02e000_GetAddr_data_02140ac8(void)
{
  return ((int)data_02140ac8);
}

void func_0202e4dc(u8 *rec);
void func_0202e520(u8 *rec);

int Unk02e000_GetTier(int x)
{
    if (x - 3 < 0) {
        return 0;
    }
    if (x - 11 < 0) {
        return 1;
    }
    if (x - 31 < 0) {
        return 2;
    }
    return 3;
}

/* 100-byte records starting at +500. */
void Unk02e000_Call_02e4dc(u8 *base, int i)
{
    func_0202e4dc(base + 500 + i * 100);
}

void Unk02e000_Call_02e520(u8 *base, int i)
{
    func_0202e520(base + 500 + i * 100);
}

int Unk02e000_Call_02008848(void)
{
    return func_02008848(Unk02e000_Unk_02e884(), 0, 0x1148);
}

/* forwards to `Unk02e000_GetWorkArea` */
u8 *Unk02e000_Thunk_0202e788(void) { return Unk02e000_GetWorkArea(); }

/* decompiler-derived */
void Unk02e000_Set_data_0215dd24(u32 arg0)
{
  *data_0215dd24 = arg0;
}

/* decompiler-derived */
u32 Unk02e000_Get_data_0215dd24(void)
{
  return *data_0215dd24;
}

/* decompiler-derived */
u32 Unk02e000_Unk_02e170(void)
{
  return *(u32 *)(((int)data_0215dd24) + 4);
}

/* decompiler-derived */
void Unk02e000_Unk_02e0ac(void)
{
  func_0205a9d0(0xa0);
  Unk02e000_Unk_02e0cc();
}

/* decompiler-derived */
int Unk02e000_Unk_02e774(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x98;
}

/* 60-byte records at +0x74 of the work area. */
u8 *Unk02e000_GetAreaRecord(int i)
{
    return Unk02e000_GetWorkArea() + 116 + i * 60;
}

u8 *Unk02e000_Unk_02e7c0(int i)
{
    u8 *w = Unk02e000_GetWorkArea();
    s8 idx = (w + i + 0x300)[0x54];
    u8 *r = 0;
    if (idx >= 0) {
        r = w + 0x74 + idx * 60;
    }
    return r;
}

int Unk02e000_FindEntryIndex(u8 *p)
{
    u8 *e;
    int i;
    if (p == 0) {
        return -1;
    }
    e = Unk02e000_GetWorkArea() + 0x74;
    for (i = 0; i < 12; i++) {
        if (e == p) {
            return i;
        }
        if (e[58] == p[58]) {
            return i;
        }
        e += 60;
    }
    return -1;
}

int Unk02e000_Unk_02e840(u8 *p)
{
    int idx = Unk02e000_FindEntryIndex(p);
    s8 *arr = (s8 *)(Unk02e000_GetWorkArea() + 0x354);
    int i;
    for (i = 0; i < 3; i++) {
        if (arr[i] >= 0 && idx == arr[i]) {
            return 1;
        }
    }
    return 0;
}

/* decompiler-derived */
int Unk02e000_Unk_02e8b8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0xafc;
}

/* decompiler-derived */
int Unk02e000_Unk_02e8f0(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x90;
}


void Unk02e000_Unk_02e180(void);
int func_0202e23c();
int Unk02e000_Call_02008848();
void Unk02e000_Unk_02e5c4(int arg0);
/* decompiler-derived */
void Unk02e000_Unk_02e144(void)
{
  int value;
  Unk02e000_Unk_02e180();
  func_0202e23c();
  Unk02e000_Call_02008848();
  value = 0;
  do {
    Unk02e000_Unk_02e5c4(value);
    value = value + 1;
  } while (value < 2);
}



/* decompiler-derived */
int Unk02e000_Unk_02e75c(int arg0)
{
  return arg0 * 0x48 + *(int *)(((int)data_0215dd24) + 4);
}


/* decompiler-derived */
int Unk02e000_Unk_02e884(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x65d0;
}


/* decompiler-derived */
int Unk02e000_Unk_02e89c(int arg0)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x5d26 + arg0 * 4;
}

/* decompiler-derived */
int Unk02e000_Unk_02e228(void)
{
  int tmp1;
  tmp1 = Unk02e000_Unk_02e774();
  return tmp1 + 0x5fc8;
}

extern u32 data_0213d89c[];
int func_0205ad2c();
int func_0205ad78();
/* decompiler-derived; refs "Data/Tex/" */
void Unk02e000_Unk_02e0cc(void)
{
  func_0205ad2c(*data_0213d89c);
  func_0205ad78(data_02140ac8,0xde);
}

int func_02008848();
int func_0202e1b8();
/* decompiler-derived */
void Unk02e000_Unk_02e180(void)
{
  u8 *v1;
  v1 = (u8 *)Unk02e000_Unk_02e8f0();
  func_02008848(v1,0,8);
  *v1 = 2;
  v1[1] = 2;
  v1[2] = 1;
  v1[3] = 1;
  func_0202e1b8();
}

int func_020445d0();
s16 *func_0204fde0();
u32 func_0204fe18();
int Unk02e000_FindIndex_02e3e4(int a)
{
    int h = func_020445d0(35, 0);
    s16 *t = func_0204fde0();
    u32 n = func_0204fe18(h);
    u32 i;
    for (i = 0; i < n; i++) {
        if (a == t[i]) {
            return i;
        }
    }
    return -1;
}

int Unk02e000_Unk_02e884(void);
int Unk02e000_GetTier(int x);
int Unk02e000_FindIndex_02e3e4(int a);

u8 *Unk02e000_GetSlotPtr(int i)
{
    u8 *p = (u8 *)Unk02e000_Unk_02e884();
    if (i < 3) {
        return p + i * 152;
    }
    if (i - 3 < 8) {
        return p + 456 + (i - 3) * 96;
    }
    if (i - 11 < 20) {
        return p + 1224 + (i - 11) * 64;
    }
    if (i - 31 < 60) {
        return p + 2504 + (i - 31) * 32;
    }
    return 0;
}

/* decompiler-derived */
void Unk02e000_Unk_02e5c4(int arg0)
{
  u32 tmp1;
  tmp1 = Unk02e000_Unk_02e75c(arg0);
  func_02008848(tmp1,0,0x48);
}

/* decompiler-derived */
int Unk02e000_Unk_02e740(int arg0)
{
  int tmp1;
  tmp1 = Unk02e000_Unk_02e75c((int)arg0);
  return *(char *)(tmp1 + 0x28) != '\0';
}

/* Work area at +4 of the Unk02e000_Unk_02e774 block. */
u8 *Unk02e000_GetWorkArea(void)
{
    return (u8 *)Unk02e000_Unk_02e774() + 4;
}


/* Unk094fe0Work block at +0xCFC of the Unk02e000_Unk_02e774 block. */
u8 *Unk02e000_GetUnk094fe0Work(void)
{
    return (u8 *)Unk02e000_Unk_02e774() + 0xcfc;
}

/* Pointer to the +0x3A4 sub-block of the Unk02e000_GetWorkArea work area. */
u8 *Unk02e000_GetSubBlock3a4(void)
{
    return Unk02e000_GetWorkArea() + 0x3a4;
}

int Unk02e000_HasField36(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return FIELD(u16, p, 0x36) != 0;
}

int Unk02e000_TestFlag(int i)
{
    if (i < 0) {
        return 0;
    }
    if (i >= 90) {
        return 0;
    }
    if ((Unk02e000_GetWorkArea() + (i >> 3))[0x374] & (u8)(1 << (i & 7))) {
        return 1;
    }
    return 0;
}

void func_02008904();
u8 *func_020a1740();
int Unk0a163c_Unk_0a17d8();
int Unk02e000_GetRecordUnk1f(u32 id);


typedef struct Unk02e000ObjFlags {
    u16 pad_0000[11];
    u16 flag_0016_0 : 1;
} Unk02e000ObjFlags;

void Unk02e000_SetBit_02e968(int i, int set)
{
    u8 m;
    u8 *w;
    if (i < 0 || i >= 90) {
        return;
    }
    m = 1 << (i & 7);
    w = Unk02e000_GetWorkArea();
    if (set != 0) {
        (w + 884)[i >> 3] |= m;
    } else {
        (w + 884)[i >> 3] &= ~m;
    }
}

int Unk02e000_SetRecord(u32 id, void *src)
{
    if (id > 491) {
        return 0;
    }
    func_02008904(&UNK02E000_RECS()[id - 1], src, 36);
    return 1;
}

int Unk02e000_GetRecord(u32 id, u32 a)
{
    Unk02e000Rec *e;
    if (id > 491) {
        return 0;
    }
    e = &UNK02E000_RECS()[id - 1];
    func_02008904(a, e, 36);
    e->unk_000b |= 2;
    return 1;
}

int Unk02e000_SetSlot40(int i, void *src)
{
    u8 *base = (u8 *)Unk02e000_Unk_02e774() + 8 + 0x5c00;
    if (i >= 0 && i < 3) {
        func_02008904(base + i * 40 + 4, src, 36);
        return 1;
    }
    return 0;
}

int Unk02e000_SetRecordUnk1c(u32 id, u16 v)
{
    Unk02e000Rec *e;
    if (id > 491) {
        return 0;
    }
    e = &UNK02E000_RECS()[id - 1];
    e->unk_001c = v;
    if (e->unk_001c > 500) {
        e->unk_001c = 500;
    }
    return 1;
}

u32 Unk02e000_GetRecordUnk1c(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02e000Rec *r = &UNK02E000_RECS()[id - 1];
        return r->unk_001c;
    }
}

int Unk02e000_SetRecordUnk1e(u32 id, int v)
{
    Unk02e000Rec *e;
    if (id > 491) {
        return 0;
    }
    e = &UNK02E000_RECS()[id - 1];
    if (v > 100) {
        e->unk_001e_0 = 100;
    } else {
        e->unk_001e_0 = (u8)v;
    }
    return 1;
}

u32 Unk02e000_GetRecordUnk1e(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02e000Rec *r = &UNK02E000_RECS()[id - 1];
        return r->unk_001e_0;
    }
}

int Unk02e000_IsRecordAvailable(u32 id)
{
    Unk02e000ObjFlags *o = (Unk02e000ObjFlags *)func_020a1740(id);
    if (Unk0a163c_Unk_0a17d8(id) == 0 && o->flag_0016_0 && Unk02e000_GetRecordUnk1f(id) > 0) {
        return 1;
    }
    return 0;
}

int Unk02e000_SetRecordFlag1f(u32 id, int v)
{
    Unk02e000Rec *e;
    if (id > 491) {
        return 0;
    }
    e = &UNK02E000_RECS()[id - 1];
    e->flag_001f_0 = (u8)(v != 0);
    return 1;
}

int Unk02e000_GetRecordFlag0(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02e000Rec *r = &UNK02E000_RECS()[id - 1];
        return r->flag_001f_0 ? 1 : 0;
    }
}


int Unk02e000_SetRecordFlag1f_1(u32 id, int v)
{
    Unk02e000Rec *e;
    if (id > 491) {
        return 0;
    }
    e = &UNK02E000_RECS()[id - 1];
    e->flag_001f_1 = (u8)(v != 0);
    return 1;
}

int Unk02e000_GetRecordFlag1(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02e000Rec *r = &UNK02E000_RECS()[id - 1];
        return r->flag_001f_1 ? 1 : 0;
    }
}

int Unk02e000_SetRecordUnk1f_2(u32 id, int v)
{
    Unk02e000Rec *e;
    if (id > 491) {
        return 0;
    }
    e = &UNK02E000_RECS()[id - 1];
    if (v > 63) {
        e->unk_001f_2 = 63;
    } else {
        e->unk_001f_2 = (u8)v;
    }
    return 1;
}

int Unk02e000_GetRecordUnk1f(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02e000Rec *r = &UNK02E000_RECS()[id - 1];
        return r->unk_001f_2;
    }
}
