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
int func_0205a9d0(int arg0);

void Unk02e000_Nop_02e3e0(void);
u32 Unk02e000_GetAddr_data_02140ac8(void);
u8 *Unk02e000_Thunk_0202e788(void);
void Unk02e000_Set_data_0215dd24(u32 arg0);
u32 Unk02e000_Get_data_0215dd24(void);
u32 Unk02e000_Unk_02e170(void);
void Unk02e000_Unk_02e0ac(void);
int Unk02e000_Unk_02e774(void);
int Unk02e000_Unk_02e75c(int index);
int Unk02e000_Unk_02e884(void);
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

u32 func_02052fe0(u32 size);

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

/* Original 0x0202e000 stores at manager +0x74 + i*4, supporting SetSlot.
 * Null managers and indices outside 0..15 are ignored; ownership stays external. */
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

/* Original 0x0202e034 loads manager +0x74 + i*4, supporting GetSlot.
 * Null managers and signed indices outside 0..15 return zero; view is borrowed. */
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

/* Original 0x0202e070 conditionally stores the pair at manager +0x38/+0x3c,
 * supporting the existing offset-based name. Any word values and null are allowed. */
void Unk02e000_SetMgrUnk38(u32 a, u32 b)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m != 0) {
        m->unk_0038 = a;
        m->unk_003c = b;
    }
}

/* Original 0x0202e090 clears manager words +0x38/+0x3c when the borrowed
 * manager alias exists; the paired stores support the existing name. */
void Unk02e000_ClearMgrUnk38(void)
{
    Unk02e000Mgr *m = Unk02dcfc_Thunk_Unk095560_GetManagerAlias();
    if (m != 0) {
        m->unk_0038 = 0;
        m->unk_003c = 0;
    }
}

/* Original 0x0202e114 allocates 0x7718 bytes only when global word +4 is zero.
 * The size and conditional allocation support the name; storage stays module-owned. */
void Unk02e000_EnsureAlloc7718(void)
{
    if (data_0215dd24[1] != 0) {
        return;
    }
    data_0215dd24[1] = func_02052fe0(0x7718);
}

/* Original 0x0202e1f8 adds to work +0x5fc4 and caps the unsigned result at
 * 35999999, supporting the name. Requires allocation; addition wraps before capping. */
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

/* Original 0x0202e3e0 is only bx lr: intentionally has no side effects. */
void Unk02e000_Nop_02e3e0(void) { }

/* Original 0x0202e0c0 returns the symbol address; ownership stays with the module. */
u32 Unk02e000_GetAddr_data_02140ac8(void)
{
    return (u32)data_02140ac8;
}

u8 *func_0202e4dc(int value);
void func_0202e520(u8 *rec);

/* Original 0x0202e440 tests the sign of x-3, x-11 and x-31 to return 0..3.
 * GetSlotPtr uses the same boundaries for record tiers; callers supply slot indices. */
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

/* Original 0x0202e578 computes base + 500 + i * 100 and tail-calls
 * func_0202e4dc; the caller must supply a valid borrowed record index. */
void Unk02e000_Call_02e4dc(u8 *base, int i)
{
    func_0202e4dc((int)(base + 500 + i * 100));
}

/* Original 0x0202e590 uses the same 100-byte record layout and tail-calls
 * func_0202e520; base and the selected record remain caller-owned. */
void Unk02e000_Call_02e520(u8 *base, int i)
{
    func_0202e520(base + 500 + i * 100);
}

/* Original 0x0202e5a8 calls func_02008848 on the borrowed +0x65d0 block
 * with value zero and length 0x1148; allocation must already exist. */
int Unk02e000_Call_02008848(void)
{
    return func_02008848(Unk02e000_Unk_02e884(), 0, 0x1148);
}

/* Original 0x0202e798 tail-jumps to GetWorkArea; returns the same borrowed view. */
u8 *Unk02e000_Thunk_0202e788(void) { return Unk02e000_GetWorkArea(); }

/* Original 0x0202e0f4 stores the first global word, without validation or allocation. */
void Unk02e000_Set_data_0215dd24(u32 arg0)
{
    data_0215dd24[0] = arg0;
}

/* Original 0x0202e104 loads the first global word; its meaning is unconfirmed. */
u32 Unk02e000_Get_data_0215dd24(void)
{
    return data_0215dd24[0];
}

/* Original 0x0202e170 loads global word +4; allocation is owned by EnsureAlloc7718. */
u32 Unk02e000_Unk_02e170(void)
{
    return data_0215dd24[1];
}

/* Original 0x0202e0ac calls func_0205a9d0 with 0xa0 before Unk_02e0cc;
 * the initialization purpose is unconfirmed, so retain the neutral name. */
void Unk02e000_Unk_02e0ac(void)
{
  func_0205a9d0(0xa0);
  Unk02e000_Unk_02e0cc();
}

/* Original 0x0202e774 returns global word +4 plus 0x98 as a 32-bit address.
 * EnsureAlloc7718 must have provided the allocation; no ownership transfers. */
int Unk02e000_Unk_02e774(void)
{
  return (int)data_0215dd24[1] + 0x98;
}

/* Original 0x0202e7a4 computes work +0x74 + i*60; this table arithmetic
 * supports GetAreaRecord. Caller supplies a valid index; storage is borrowed. */
u8 *Unk02e000_GetAreaRecord(int i)
{
    return Unk02e000_GetWorkArea() + 116 + i * 60;
}

/* Original 0x0202e7c0 reads signed byte work+0x354+i; negative returns null,
 * otherwise returns work+0x74+byte*60. Caller supplies a valid allocated index. */
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

/* Original 0x0202e7f4 scans twelve 60-byte entries at work+0x74,
 * comparing addresses then byte +0x3a; this supports FindEntryIndex. Null returns
 * -1; otherwise p must expose that byte. Requires allocated work storage. */
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

/* Original 0x0202e840 tests whether FindEntryIndex(p) occurs in the three
 * nonnegative signed bytes at work+0x354. Requires allocated work storage. */
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

/* Original 0x0202e8b8 adds 0xafc to the allocated Unk_02e774 view.
 * Returns a borrowed 32-bit address; the sub-block purpose is unconfirmed. */
int Unk02e000_Unk_02e8b8(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0xafc;
}

/* Original 0x0202e8f0 returns allocation word +4 plus 0x90.
 * Unk_02e180 uses this borrowed address for an eight-byte initialization. */
int Unk02e000_Unk_02e8f0(void)
{
  return (int)data_0215dd24[1] + 0x90;
}


void Unk02e000_Unk_02e180(void);
int func_0202e23c(void);
int Unk02e000_Call_02008848();
void Unk02e000_Unk_02e5c4(int arg0);
/* Original 0x0202e144 calls three initialization helpers in order, then
 * Unk_02e5c4 for indices 0 and 1. Requires allocation; broader purpose is unknown. */
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



/* Original 0x0202e75c multiply-adds index*72 to allocation word +4.
 * Caller supplies a valid index; the borrowed record purpose is unconfirmed. */
int Unk02e000_Unk_02e75c(int index)
{
    return index * 0x48 + (int)data_0215dd24[1];
}


/* Original 0x0202e884 adds 0x5d0 then 0x6000 to allocation word +4.
 * Returns a borrowed address; the sub-block purpose remains unconfirmed. */
int Unk02e000_Unk_02e884(void)
{
    return (int)data_0215dd24[1] + 0x65d0;
}


/* Original 0x0202e89c adds 0x5d26 and index*4 to allocation word +4.
 * Caller supplies a valid index; returns an unaligned borrowed address. */
int Unk02e000_Unk_02e89c(int index)
{
    return (int)data_0215dd24[1] + 0x5d26 + index * 4;
}

/* Original 0x0202e228 adds 0x5fc8 to the allocated Unk_02e774 view.
 * Returns a borrowed 32-bit address; the sub-block purpose is unconfirmed. */
int Unk02e000_Unk_02e228(void)
{
  int tmp1;
  tmp1 = Unk02e000_Unk_02e774();
  return tmp1 + 0x5fc8;
}

extern u32 data_0213d89c[];
int func_0205ad2c(u32 value);
int func_0205ad78(u8 *data, u32 value);
/* Original 0x0202e0cc passes global word zero to func_0205ad2c, then
 * data_02140ac8 and 0xde to func_0205ad78. Purpose is unconfirmed; name stays neutral. */
void Unk02e000_Unk_02e0cc(void)
{
  func_0205ad2c(*data_0213d89c);
  func_0205ad78(data_02140ac8,0xde);
}

int func_02008848();
void func_0202e1b8(void);
/* Original 0x0202e180 clears eight allocated bytes, sets 2,2,1,1, then
 * calls func_0202e1b8. Requires allocation; initialization purpose is unconfirmed. */
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

/* Original 0x0202e5c4 passes the indexed borrowed record to func_02008848
 * with zero and length 72. Caller must provide an allocated, valid index. */
void Unk02e000_Unk_02e5c4(int index)
{
    int record = Unk02e000_Unk_02e75c(index);
    func_02008848(record, 0, 0x48);
}

/* Original 0x0202e740 tests unsigned byte +0x28 in the indexed record.
 * Requires a valid allocated record; the byte's meaning is unconfirmed. */
int Unk02e000_Unk_02e740(int index)
{
    u8 *record = (u8 *)Unk02e000_Unk_02e75c(index);
    return record[0x28] != 0;
}

/* Original 0x0202e788 calls Unk_02e774 then adds 4; requires its allocated block.
 * Returns a borrowed byte view, as used by GetAreaRecord and TestFlag. */
u8 *Unk02e000_GetWorkArea(void)
{
    return (u8 *)Unk02e000_Unk_02e774() + 4;
}


/* Original 0x0202e8cc adds 0xcfc to Unk_02e774; unit_02094fe0
 * uses this as its work block. Allocation is required; the view is borrowed. */
u8 *Unk02e000_GetUnk094fe0Work(void)
{
    return (u8 *)Unk02e000_Unk_02e774() + 0xcfc;
}

/* Original 0x0202e8e0 calls GetWorkArea then adds 0x3a4.
 * Returns a borrowed sub-block; the work area must already be allocated. */
u8 *Unk02e000_GetSubBlock3a4(void)
{
    return Unk02e000_GetWorkArea() + 0x3a4;
}

/* Original 0x0202e904 returns whether the borrowed halfword at +0x36 is
 * nonzero, supporting the name. Null returns false; nonnull storage must be aligned. */
int Unk02e000_HasField36(u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return FIELD(u16, p, 0x36) != 0;
}

/* Original 0x0202e924 tests bit i in the work+0x374 byte array, supporting
 * TestFlag. Indices outside 0..89 return false; valid indices require allocation. */
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
u8 *func_020a1740(u32 id);
int Unk0a163c_Unk_0a17d8(u32 id);
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

/* Original 0x0202e9c8 copies 36 bytes into work+0x16fc+(id-1)*36,
 * supporting SetRecord. IDs above 491 return zero; callers supply IDs 1..491
 * and readable source storage. Allocation and destination ownership stay external. */
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

/* Original 0x0202ea68 copies 36 bytes to work+0x5c0c+i*40,
 * supporting SetSlot40. Signed indices outside 0..2 return zero, but allocation
 * is required even then; src must expose 36 readable bytes for valid indices. */
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

/* Original 0x0202eb0c loads unsigned halfword +0x1c in the 36-byte record,
 * supporting the offset name. IDs above 491 return zero; valid IDs are 1..491. */
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

/* Original 0x0202ebb8 extracts bits 0..6 of record byte +0x1e,
 * supporting the offset name. IDs above 491 return zero; callers supply valid
 * allocated IDs 1..491. The seven-bit value has no established semantic meaning. */
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

/* Original 0x0202ebfc requires a zero Unk0a163c_Unk_0a17d8 result,
 * object halfword +0x16 bit zero set, and positive GetRecordUnk1f result; these
 * predicates support the existing availability name. Caller supplies a valid id
 * with a nonnull object lookup and allocated record storage. */
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

/* Original 0x0202ecac normalizes record byte +0x1f bit zero to 0/1,
 * supporting GetRecordFlag0. IDs above 491 return zero; callers supply valid
 * allocated IDs 1..491. The flag purpose remains unconfirmed. */
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

/* Original 0x0202ed5c normalizes record byte +0x1f bit one to 0/1,
 * supporting GetRecordFlag1. IDs above 491 return zero; callers supply valid
 * allocated IDs 1..491. The flag purpose remains unconfirmed. */
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

/* Original 0x0202ee18 extracts bits 2..7 of record byte +0x1f,
 * supporting the offset name. IDs above 491 return zero; callers supply valid
 * allocated IDs 1..491. The six-bit value has no established semantic meaning. */
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

/* Original 0x0202e4dc looks up the signed low halfword, then its slot view.
 * A missing index or null slot retries with index lookup key -1. The returned
 * record is borrowed; the allocation must exist. Broader purpose is unconfirmed. */
u8 *func_0202e4dc(int value)
{
    u8 *record = 0;
    int index = Unk02e000_FindIndex_02e3e4((s16)value);
    if (index >= 0) {
        record = Unk02e000_GetSlotPtr(index);
    }
    if (record == 0) {
        record = Unk02e000_GetSlotPtr(Unk02e000_FindIndex_02e3e4(-1));
    }
    return record;
}
