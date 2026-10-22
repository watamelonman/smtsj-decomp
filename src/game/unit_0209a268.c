/*
 * src/game/unit_0209a268.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk09a268Work {
    s32 unk_0000;
    s32 unk_0004;
    s32 unk_0008;
    u32 UnkField000c;
    void *unk_0010;
    void *unk_0014;
    void *unk_0018;
    void *unk_001c;
    void *unk_0020;
    void *unk_0024;
    s32 unk_0028;
    s32 UnkField002c;
    s32 unk_0030;
    s32 unk_0034;
    s32 unk_0038;
} Unk09a268Work;


/* Partial work-area layout; only the accessed halfword, kind and coordinates are known.
 * unk_0358 is volatile because the transition handlers re-read it after engine calls;
 * keeping those two reads distinct reproduces the original 0209c854 code. See DEC-003. */
typedef struct Unk09a268WorkArea {
    u8 pad_0000[0x344];
    u32 unk_0344;
    u8 pad_0348[0x10];
    volatile u32 unk_0358;
    u16 unk_035c;
    u8 pad_035e[6];
    s8 unk_0364;
    s8 unk_0365;
} Unk09a268WorkArea;

/* Table records have a 0x1c-byte stride; only the last three bytes are used here. */
typedef struct Unk09a268Rec {
    u8 pad_00[0x19];
    u8 unk_19;
    u8 unk_1a;
    u8 unk_1b;
} Unk09a268Rec;


int func_0209a48c(u32 p, int bit);
void Unk09a268_SetBit(u8 *p, int bit, int on);
int func_0209bb68(u32 encoded);
Unk09a268Rec *Unk09a268_Unk_09c484(int arg0);

void Unk09a268_Nop_09b3c8(void);
void Unk09a268_Unk_09a7fc(u32 arg0);
void Unk09a268_Unk_09a820(u32 arg0);
void Unk09a268_Unk_09c498(void);
void Unk09a268_Unk_09a80c(u32 arg0,u32 arg1);
void Unk09a268_Unk_09a830(u32 arg0,u32 arg1);
void Unk09a268_Unk_09a870(u32 arg0,u32 arg1);

typedef struct Unk09a268Ent {
    s32 *val;
    u32 pad_04;
    u32 id;
    u32 pad_0c;
    u32 sub;
    u32 pad_14;
} Unk09a268Ent;

/* Clearable resource slots released by the callback teardown in 0209b5d8. */
typedef struct Unk09a268Cleanup {
    u8 pad_0000[0xc];
    void *unk_000c;
    void *unk_0010;
    void *unk_0014;
    void *unk_0018;
    void *unk_001c;
    void *unk_0020;
    void *unk_0024;
} Unk09a268Cleanup;

/* Four signed bytes per indexed record, fetched by 0392f8_GetEntry36. */
typedef struct Unk09a268Entry4 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
} Unk09a268Entry4;

int func_02058af8();
void func_02058b14();
void func_02058a1c();
int func_02058a64(u8 *table);
void func_02058944(u8 *table, int index, u8 *src, u32 a, u32 b, u32 c, u8 d);
u8 *GetGameState(void);
u32 Unk02f2a8_Unk_034970(void *table, u32 a, u32 b);
u8 *Unk038fbc_Unk_039160(u32 h, u32 a, u32 b);
Unk09a268WorkArea *Unk02e000_GetWorkArea(void);
int Unk1122bc_Unk_1124a0(void);
u32 Unk1122bc_Unk_112460(void);
int Unk1124f0_Unk_1125ac(u32 a, u32 b, u32 c);
void func_02008904(void *dst, void *src, u32 size);
Unk09a268Entry4 *Unk0392f8_GetEntry36(void *table, u32 index);
int func_02034b7c(u16 a, int x, int y, u32 kind, int a5, int a6, int a7, int a8);
void func_0205257c(int mode);
int Unk02d15c_IsMode1Match(int a);
void ScanVisor_Unk_0a2acc(void);
void ScanVisor_Unk_0a2a8c(int index);
void func_02095f94(void);
void func_0205ddb4();
void func_0205c368();
void func_0205c3dc();
void func_0205bb68(void);
void Unk065e88_Unk_065eac(void);
void Unk0fd268_Unk_0fd3ac(void);
void Unk044394_Unk_044534(int index);
void Unk02e000_Unk_02e0cc(void);
void Unk05ae50_Unk_05af2c(int value);
void Unk0c855c_Unk_0ca648(int value);

/* Returns the first record whose +8/+16 words both match id/sub, forwarded to
 * func_02058af8 with its index; returns 1 when no record matches. Evidence: the
 * paired comparisons and the func_02058af8 call at 0209a3a0. */
int Unk09a268_Unk_09a3a0(u8 *w, u32 id, u32 sub)
{
    Unk09a268Ent *base = (Unk09a268Ent *)(w + 164 + 9216);
    int j;
    for (j = 0; j < 128; j++) {
        if (base[j].id == id && base[j].sub == sub) {
            return func_02058af8(base, j);
        }
    }
    return 1;
}

/* Allocates a free entry in the 128-record table and fills it from a, b, c and d;
 * returns the index, or -1 when the table is full. Evidence: the free-slot scan in
 * func_02058a64 and the entry writes in func_02058944. */
int func_0209a3ec(u8 *w, u32 a, u32 b, u32 c, u8 d)
{
    int i = func_02058a64(w + 164 + 9216);
    if (i == -1) {
        return -1;
    }
    func_02058944(w + 164 + 9216, i, w + 24 + 1024, a, b, c, d);
    return i;
}

/* Finds or creates the (a, b) entry using c/d, then forwards e to its setter.
 * Evidence: 0209a458 calls 0209a3ec and passes its index to 02058b14. */
void Unk09a268_Unk_09a458(u8 *w, u32 a, u32 b, u32 c, u8 d, u32 e)
{
    int i = func_0209a3ec(w, a, b, c, d);
    func_02058b14(w + 164 + 9216, i, e);
}

/* Sets bit `bit` of the byte at `p` when `on` is 1, otherwise clears it. */
void Unk09a268_SetBit(u8 *p, int bit, int on)
{
    if (on == 1) {
        *p |= 1 << bit;
    } else {
        *p &= ~(1 << bit);
    }
}

/* Returns the first matching (id, sub) index in the 128-entry table, or -1.
 * Evidence: the paired +8/+16 comparisons and 24-byte stride at 0209a4c4. */
int Unk09a268_FindEntry(u8 *w, u32 id, u32 sub)
{
    int j;
    for (j = 0; j < 128; j++) {
        if (((Unk09a268Ent *)((u8 *)w + 164 + 9216))[j].id == id && ((Unk09a268Ent *)((u8 *)w + 164 + 9216))[j].sub == sub) {
            return j;
        }
    }
    return -1;
}

/* Returns the first set bit index among bits 0-2 of the byte at p, or 0.
 * Evidence: the bit-test loop at 0209a77c; p must address a readable byte. */
u8 Unk09a268_Unk_09a77c(u32 p)
{
    u8 r = 0;
    u8 j;
    for (j = 0; j < 3; j++) {
        if (func_0209a48c(p, j) == 1) {
            r = j;
            break;
        }
    }
    return r;
}

/* Selects bit v among bits 0-2, clearing the other two and preserving bits 3-7.
 * Evidence: the three SetBit calls in the 0209a7bc loop; v >= 3 clears all three.
 * p must address a writable byte. */
void Unk09a268_SetOnlyBit(u32 p, u32 v)
{
    u32 j;
    for (j = 0; j < 3; j++) {
        Unk09a268_SetBit((u8 *)p, j, v == j ? 1 : 0);
    }
}

/* Reads a single bit of the byte at `p`. Callers use bits 0-2 to select one of the
 * three state values and bits 3-5 for the flag setters (Unk09a268_Unk_09a80c/a830/a870). */
int func_0209a48c(u32 p, int bit)
{
    return (*(u8 *)p & (1 << bit)) != 0;
}

/* Returns the s32 pointed to by the first word of the record whose +8 word equals
 * `id`, arithmetically shifted right by 12, or 0 when none matches. Evidence: the 128-record scan at 0209a54c. */
int func_0209a53c(u8 *w, u32 id)
{
    Unk09a268Ent *base = (Unk09a268Ent *)(w + 164 + 9216);
    int i;
    for (i = 0; i < 128; i++) {
        if (base[i].id == id) {
            return *base[i].val >> 12;
        }
    }
    return 0;
}

/* empty callback */
void Unk09a268_Nop_09b3c8(void) { }

/* Tests the bit-3 flag of the state byte at `p`; the result is discarded. */
void Unk09a268_Unk_09a7fc(u32 p)
{
  func_0209a48c(p,3);
}

/* Tests the bit-4 flag of the state byte at `p`; the result is discarded. */
void Unk09a268_Unk_09a820(u32 p)
{
  func_0209a48c(p,4);
}

typedef struct Unk09a268Ctx {
    u8 pad_0000[0x2c];
    u32 unk_002c;
    u32 unk_0030;
    u32 unk_0034;
    u32 unk_0038;
} Unk09a268Ctx;

extern Unk09a268Ctx *data_02176270;

/* Returns the context's +0x34 word, or 0 when the global context is absent. */
u32 func_0209b720(void)
{
    if (data_02176270 == 0) {
        return 0;
    }
    return data_02176270->unk_0034;
}

/* Stores value at +0x38 of the global context when one is allocated. */
void Unk09a268_SetCtxUnk38(u32 value)
{
    if (data_02176270 != 0) {
        data_02176270->unk_0038 = value;
    }
}

/* Runs the func_0209bb68 and Unk09a268_Unk_09c484 steps in sequence, discarding their results. */
void Unk09a268_Unk_09c498(void)
{
  /* Both original lookup calls omit their argument and discard the result. See DEC-002. */
  ((int (*)(void))func_0209bb68)();
  /* Original call supplies no index and discards the address. See DEC-002. */
  ((int (*)(void))Unk09a268_Unk_09c484)();
}

/* Sets or clears the bit-3 flag of the state byte at `p` (`on` == 1 sets). */
void Unk09a268_Unk_09a80c(u32 p,u32 on)
{
  Unk09a268_SetBit((u8 *)p,3,on);
}

/* Sets or clears the bit-4 flag of the state byte at `p` (`on` == 1 sets). */
void Unk09a268_Unk_09a830(u32 p,u32 on)
{
  Unk09a268_SetBit((u8 *)p,4,on);
}

/* Sets or clears the bit-5 flag of the state byte at `p` (`on` == 1 sets). */
void Unk09a268_Unk_09a870(u32 p,u32 on)
{
  Unk09a268_SetBit((u8 *)p,5,on);
}


extern u8 data_0213be64[];
/* Returns the address of the 0x1c-byte record at `arg0` in table data_0213be64. */
Unk09a268Rec *Unk09a268_Unk_09c484(int arg0)
{
  return (Unk09a268Rec *)(arg0 * 0x1c + ((int)data_0213be64));
}

/* Partial body layout: notification halfwords at +0x50/+0x52 and the flag
 * read by 09a844 are established by their respective field accesses. */
typedef struct Unk09a268GameStateBody {
    u8 pad_0000[0x50];
    s16 unk_0050;
    s16 unk_0052;
    u8 pad_0054[0x38c];
    s32 unk_03e0;
} Unk09a268GameStateBody;

Unk09a268GameStateBody *GameState_GetBody(void);
/* Returns bit 5 of the state byte at `arg0` when GameState body +0x3e0 is nonzero, else 1. */
u32 Unk09a268_Unk_09a844(u32 arg0)
{
  Unk09a268GameStateBody *body = GameState_GetBody();
  if (body->unk_03e0 != 0) {
    return func_0209a48c(arg0,5);
  }
  return 1;
}

void Unk_LoadPalette_020de678(u32 palette);
int func_02057524();
int func_02057534();
typedef struct Unk09ae60Ops {
    u32 size;
    u32 unk_04;
    u32 unk_08;
    void (*fn_0c)();
    void (*fn_10)();
    void (*fn_14)();
    void (*fn_18)();
    void (*fn_1c)();
    void (*fn_20)();
} Unk09ae60Ops;
void Unk09a268_Unk_09b3cc(Unk09a268Work *work);
void func_0209b1d4(Unk09a268Work *work);
void func_0209b3f8(Unk09a268Work *work);
void func_0209b5d8(Unk09a268Cleanup *work);
typedef struct Unk09a268Message Unk09a268Message;
void func_0209aebc(Unk09a268Work *work, Unk09a268Message *message);

/* Classifies a position: 2 when the Manhattan distance from the work area's
 * +0x364/+0x365 coordinates is at most the value selected by (x - 30), else 0.
 * Evidence: the two signed byte reads and the (x - 30) jump table at 0209a9c0. */
int func_0209a970(int x, int y, int z)
{
    int ret;
    Unk09a268WorkArea *work;
    int dy;
    int dx;
    int distance;
    int limit;

    if (Unk1122bc_Unk_1124a0() == 0) {
        return 0;
    }
    ret = 0;
    work = Unk02e000_GetWorkArea();
    dy = work->unk_0365 - z;
    if (dy < 0) {
        dy = -dy;
    }
    dx = work->unk_0364 - y;
    if (dx < 0) {
        dx = -dx;
    }
    distance = dx + dy;
    limit = 0;
    switch (x - 30) {
    case 0:
    case 3:
        limit = 1;
        break;
    case 1:
    case 4:
        limit = 2;
        break;
    case 2:
        break;
    }
    if (distance <= limit) {
        ret = 2;
    }
    return ret;
}

/* Fills the 60-byte handler table: size 60, a zero word at +4, and the six
 * callbacks at +0x0c through +0x20. Evidence: the literal pool at 0209ae60. */
void Unk09a268_Unk_09ae60(Unk09ae60Ops *o)
{
    o->size = 60;
    o->unk_04 = 0;
    o->fn_0c = func_0209b1d4;
    o->fn_10 = Unk09a268_Nop_09b3c8;
    o->fn_14 = Unk09a268_Unk_09b3cc;
    o->fn_18 = func_0209b3f8;
    o->fn_1c = func_0209b5d8;
    o->fn_20 = func_0209aebc;
}

/* Reloads the palette from the work's +0xc field when +0x2c is zero. */
void Unk09a268_Unk_09b3cc(Unk09a268Work *work)
{
  func_02057524(0);
  if (work->UnkField002c == 0) {
    Unk_LoadPalette_020de678(work->UnkField000c);
  }
  func_02057534();
}


int Unk0bc1a8_IsSlotEmpty();
/* Stores a and b at +0x2c/+0x30 of the global context when one is allocated. */
void Unk09a268_SetCtxUnk2c30(u32 a, u32 b)
{
    if (data_02176270 != 0) {
        data_02176270->unk_002c = a;
        data_02176270->unk_0030 = b;
    }
}

/* Returns 1 only when slots 0 and 9 are both empty.
 * Evidence: the two Unk0bc1a8_IsSlotEmpty calls at 0209bb38. */
u32 Unk09a268_Unk_09bb38(void)
{
  int value;
  value = Unk0bc1a8_IsSlotEmpty(0);
  if ((value != 0) && (value = Unk0bc1a8_IsSlotEmpty(9), value != 0)) {
    return 1;
  }
  return 0;
}


int Unk02f2a8_GetCurrentCell38e8();
void Unk09a268_SetOnlyBit();
typedef struct Unk09a268MapWork Unk09a268MapWork;
void func_0209c548(Unk09a268MapWork *work);
/* Reads byte +0x1A of the record selected for (a, b); kinds 20 and 23 are handled
 * by their own helpers instead. Evidence: the two compared func_0209bb68 results. */
int func_0209be20(u32 a, u32 b)
{
    int ret = 0;
    u8 *e = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(GetGameState() + 4, a, b), a, b);
    if (e != 0) {
        int kind = func_0209bb68(*e);
        switch (kind) {
        case 20:
            ret = Unk1122bc_Unk_112460();
            break;
        case 23:
            ret = Unk1124f0_Unk_1125ac(Unk02e000_GetWorkArea()->unk_035c, a, b);
            break;
        default:
            ret = Unk09a268_Unk_09c484(kind)->unk_1a;
            break;
        }
    }
    return ret;
}

/* Sets bit 3, clears bit 4, selects the state bit from record 5 byte +0x19,
 * then writes current-cell byte +1 = 1 and halfword +2 = 0 before running
 * func_0209c548(arg0). Evidence: the
 * Unk09a268_SetOnlyBit and Unk09a268_Unk_09a80c/a830 calls at 0209cb10. */
void Unk09a268_Unk_09cb10(u32 arg0)
{
  Unk09a268Rec *value1;
  int value2;
  value1 = Unk09a268_Unk_09c484(5);
  value2 = Unk02f2a8_GetCurrentCell38e8();
  Unk09a268_Unk_09a80c(value2,1);
  Unk09a268_Unk_09a830(value2,0);
  Unk09a268_SetOnlyBit(value2,value1->unk_19);
  *(u8 *)(value2 + 1) = 1;
  *(u16 *)(value2 + 2) = 0;
  func_0209c548((Unk09a268MapWork *)arg0);
}

/* Byte +0x1B of the record for (a, b), or 0 when absent. */
u8 Unk09a268_Unk_09beb0(u32 a, u32 b)
{
    u8 ret = 0;
    u8 *e = Unk038fbc_Unk_039160(Unk02f2a8_Unk_034970(GetGameState() + 4, a, b), a, b);
    if (e != 0) {
        ret = Unk09a268_Unk_09c484(func_0209bb68(*e))->unk_1b;
    }
    return ret;
}

/* Returns 0 for a null handle, otherwise the table record selected by the
 * located entry byte (index 0 when absent). Evidence: calls at 0209c4a8. */
int Unk09a268_Unk_09c4a8(u32 h, u32 a, u32 b)
{
    int r;
    u8 *e;
    if (h == 0) {
        return 0;
    }
    r = 0;
    e = Unk038fbc_Unk_039160(h, a, b);
    if (e != 0) {
        r = func_0209bb68(*e);
    }
    return (int)Unk09a268_Unk_09c484(r);
}

/* Returns 1 when `p` is non-null and its first byte equals 1, else 0. */
int Unk09a268_IsType1(const u8 *p)
{
    if (p == 0) {
        return 0;
    }
    return *p == 1;
}

/* Classifies a record's first byte: 1 and 3 through 6 return 1, all other
 * values return 0. Null is accepted. Evidence: the switch at 0209c4f0. */
int func_0209c4e0(const u8 *record)
{
    if (record == 0) {
        return 0;
    }
    switch (*record) {
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    case 0:
    case 2:
    default:
        return 0;
    }
}

/* Entry removal and transition helpers retain neutral names until their callers
 * establish the meaning of the state values. */
void func_0209a4fc(u8 *work, u32 id);
int func_0209c854(u8 *work);
int func_0209c9bc(u8 *work);
void func_02052da0(void);
u8 *Unk0392f8_Unk_0394b8(void *table, int x, int y);

/* Replaces the three indexed entry variants, omitting each -1 argument.
 * Evidence: 0209a588 removes id first, then inserts variants 0, 1 and 2.
 * work must contain the 128-entry table; c is a signed byte sentinel/index. */
void func_0209a588(u8 *work, u32 id, int a, int b, s8 c, u32 value)
{
    func_0209a4fc(work, id);
    if (a != -1) Unk09a268_Unk_09a458(work, id, a, 0, 0, value);
    if (b != -1) Unk09a268_Unk_09a458(work, id, b, 1, 0, value);
    if (c != -1) Unk09a268_Unk_09a458(work, id, c, 2, 0, value);
}

/* Partial transition layout, established by the signed-byte state accesses, the
 * counter at +0x7484 and the flag words written by the transition handlers. */
typedef struct Unk09a268Transition {
    struct Unk09a268TransitionOwner *owner;
    u8 pad_0004[0x73dc];
    u32 unk_73e0;
    u8 pad_73e4[0x5c];
    u32 unk_7440;
    u8 pad_7444[0x3c];
    s8 kind;
    s8 phase;
    s8 x;
    s8 y;
    s32 counter;
    u8 pad_7488[0xf4];
    u32 unk_757c;
} Unk09a268Transition;
typedef struct Unk09a268TransitionOwner {
    u8 pad_0000[4];
    u32 unk_0004;
    u8 pad_0008[4];
    u32 unk_000c;
    u8 pad_0010[4];
    s32 state;
    s32 next;
} Unk09a268TransitionOwner;
typedef struct Unk09a268Cell {
    u8 flags;
    u8 kind;
    u16 counter;
} Unk09a268Cell;

/* Advances a three-phase transition and its cell counter; phase zero waits
 * for 40 ticks, and later phases wait for owner state 1. Evidence: 0209c768.
 * work and its owner must be allocated; the current cell must be available. */
int func_0209c768(u8 *work)
{
    Unk09a268Transition *w = (Unk09a268Transition *)work;
    Unk09a268Cell *cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
    int result = 0;
    func_02052da0();
    w->counter++;
    cell->counter++;
    switch (w->phase) {
    case 0:
        if (w->counter > 40) {
            Unk09a268_Unk_09a870((u32)cell, 0);
            w->owner->state = 2;
            w->owner->next = 2;
            w->phase++;
        }
        break;
    case 1:
        if (w->owner->state == 1) {
            w->owner->state = 2;
            w->owner->next = 2;
            w->phase++;
        }
        break;
    case 2:
        if (w->owner->state == 1) result = 1;
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

/* Dispatches by signed transition kind and clears the current cell on
 * completion. Evidence: 0209cb68 calls the three transition handlers.
 * work must address the transition layout and a current cell must exist. */
int func_0209cb68(u8 *work)
{
    int result;
    Unk09a268Cell *cell;
    switch (((Unk09a268Transition *)work)->kind) {
    case 0: result = func_0209c768(work); break;
    case 1: result = func_0209c854(work); break;
    default: result = func_0209c9bc(work); break;
    }
    if (result != 1) return 0;
    Unk09a268_Unk_09c484(5);
    cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
    Unk09a268_Unk_09a80c((u32)cell, 0);
    Unk09a268_Unk_09a830((u32)cell, 0);
    Unk09a268_Unk_09a870((u32)cell, 0);
    Unk09a268_SetOnlyBit((u32)cell, 0);
    cell->kind = 0;
    cell->counter = 0;
    return 1;
}

/* Dispatches the transition, then selects cleared or kind-2 cell state from
 * the type-1 record at work +996 and signed coordinates +0x7482/+0x7483.
 * work must include the transition layout and its embedded record table.
 * Evidence: the record lookup and flag writes at 0209cd24. */
int func_0209cd24(u8 *work)
{
    int result;
    Unk09a268Cell *cell;
    switch (((Unk09a268Transition *)work)->kind) {
    case -1: return 1;
    case 0: result = func_0209c768(work); break;
    case 1: result = func_0209c854(work); break;
    default: result = func_0209c9bc(work); break;
    }
    if (result == 1) {
        Unk09a268_Unk_09c484(5);
        cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
        if (Unk09a268_IsType1(Unk0392f8_Unk_0394b8(work + 996,
            ((Unk09a268Transition *)work)->x, ((Unk09a268Transition *)work)->y)) == 1) {
            Unk09a268_Unk_09a80c((u32)cell, 0);
            Unk09a268_Unk_09a830((u32)cell, 0);
            Unk09a268_Unk_09a870((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, 0);
            cell->kind = 0;
            cell->counter = 0;
        } else {
            Unk09a268_Unk_09a80c((u32)cell, 1);
            Unk09a268_Unk_09a830((u32)cell, 1);
            Unk09a268_Unk_09a870((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, 0);
            cell->kind = 2;
            cell->counter = 0;
        }
        return 1;
    }
    return 0;
}

/* Dispatches the transition, then selects cleared or kind-2 cell state from
 * the type-1 record at work +996 and signed coordinates +0x7482/+0x7483.
 * work must include the transition layout and its embedded record table.
 * Evidence: the record lookup and flag writes at 0209cf54. */
int func_0209cf54(u8 *work)
{
    int result;
    Unk09a268Cell *cell;
    switch (((Unk09a268Transition *)work)->kind) {
    case -1: return 1;
    case 0: result = func_0209c768(work); break;
    case 1: result = func_0209c854(work); break;
    default: result = func_0209c9bc(work); break;
    }
    if (result == 1) {
        Unk09a268_Unk_09c484(5);
        cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
        if (Unk09a268_IsType1(Unk0392f8_Unk_0394b8(work + 996,
            ((Unk09a268Transition *)work)->x, ((Unk09a268Transition *)work)->y)) == 1) {
            Unk09a268_Unk_09a80c((u32)cell, 0);
            Unk09a268_Unk_09a830((u32)cell, 0);
            Unk09a268_Unk_09a870((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, 0);
            cell->kind = 0;
            cell->counter = 0;
        } else {
            Unk09a268_Unk_09a80c((u32)cell, 1);
            Unk09a268_Unk_09a830((u32)cell, 1);
            Unk09a268_Unk_09a870((u32)cell, 0);
            Unk09a268_SetOnlyBit((u32)cell, 0);
            cell->kind = 2;
            cell->counter = 0;
        }
        return 1;
    }
    return 0;
}

s32 *Unk038fbc_GetElement(u32 handle, u32 kind, u32 index);
u32 Unk02f2a8_Unk_0349c4(void *map, int x, int y);
int Unk0e651c_Get2Bits(u32 value, u32 index);
int func_0209bd08(u32 kind, u32 direction, u32 mask);

/* Returns the inverse of the directional test for a located map entry.
 * Kind 16 uses its element-7 low nibble and packed two-bit map field;
 * other kinds use 0209bd08. Evidence: the kind comparison at 0209c0e0.
 * x/y are map coordinates; directions 0-3 select masks 2, 4, 1 and 8. */
int func_0209c090(int x, int y, u32 direction, u32 mask)
{
    int result = 0;
    u32 handle;
    u8 *entry;
    u32 kind;
    s32 *element;
    handle = Unk02f2a8_Unk_034970(GetGameState() + 4, x, y);
    entry = Unk038fbc_Unk_039160(handle, x, y);
    if (entry != 0) {
        kind = *entry;
        if (func_0209bb68(kind) == 16) {
            mask = 0;
            switch (direction) {
            case 1: mask = 4; break;
            case 2: mask = 1; break;
            case 3: mask = 8; break;
            case 0: mask = 2; break;
            }
            element = Unk038fbc_GetElement(handle, 7, entry[1]);
            if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y),
                (u32)(*element << 16) >> 24) == 3) {
                result = 1;
            } else if (mask & ((u32)(*element << 28) >> 28)) {
                result = 1;
            }
        } else {
            result = func_0209bd08(kind, direction, mask);
        }
    }
    return result == 0;
}

/* Message payload words are valid only when their corresponding flag is set. */
typedef struct Unk09a268Payload {
    u8 flags;
    u8 pad_0001[11];
    u32 unk_000c;
    u32 unk_0010;
    u32 unk_0014;
} Unk09a268Payload;
struct Unk09a268Message {
    u32 type;
    Unk09a268Payload payload;
};
void func_020525cc(int mode);
void Unk0bc1a8_Unk_0bc504(Unk09a268Work *work, u32 value);

/* Preserves the caller's output when payload word +16 is not flagged valid. */
static inline int Unk09a268_Payload16(Unk09a268Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_0010;
    if (p->flags & 8) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Preserves the caller's output when payload word +20 is not flagged valid. */
static inline int Unk09a268_Payload20(Unk09a268Payload *p, u32 *out)
{
    u32 value;
    if (p == 0) return 0;
    value = p->unk_0014;
    if (p->flags & 16) {
        *out = value;
        return 1;
    }
    return 0;
}

/* Handles messages 0 (mode/payload), 1 (release request), and 2 (state flags).
 * Evidence: 0209aebc's switch and flag-qualified payload reads; words +40,
 * +44, +48 and +52 belong to the 60-byte callback work allocation.
 * Both pointers must be valid; message types outside 0-4 are ignored. */
void func_0209aebc(Unk09a268Work *work, Unk09a268Message *message)
{
    u32 type = message->type;
    Unk09a268Payload *payload = &message->payload;
    u32 value;
    switch (type) {
    case 0:
        if (Unk09a268_Payload16(payload, &value)) {
            if (value == 0) func_020525cc(0);
        } else {
            func_020525cc(0);
        }
        if (Unk09a268_Payload20(payload, &value)) work->unk_0034 = value;
        break;
    case 2:
        work->unk_0028 = message->payload.unk_000c == 1;
        work->UnkField002c = 0;
        work->unk_0030 = 0;
        if (Unk09a268_Payload16(payload, &value)) {
            if (value == 1) {
                work->UnkField002c = 1;
                work->unk_0030 = 1;
            }
        }
        break;
    case 1:
        Unk0bc1a8_Unk_0bc504(work, 0);
        break;
    case 3: break;
    case 4: break;
    }
}

/* Adds each of the seven fixed-size byte arrays of `src` into `dst`, then copies
 * the following 162-byte block from src to dst. Evidence: the seven counted
 * ldrb/add/strb loops and the tail func_02008904(src+0xa84, dst+0xa84, 162). */
void func_0209a268(u8 *dst, u8 *src)
{
    int i;
    for (i = 0; i < 60; i++) dst[i + 15] += src[i + 15];
    for (i = 0; i < 50; i++) dst[i + 88] += src[i + 88];
    for (i = 0; i < 50; i++) dst[i + 138] += src[i + 138];
    for (i = 0; i < 50; i++) dst[i + 188] += src[i + 188];
    for (i = 0; i < 50; i++) dst[i + 238] += src[i + 238];
    for (i = 0; i < 220; i++) dst[i + 1268] += src[i + 1268];
    for (i = 0; i < 220; i++) dst[i + 1488] += src[i + 1488];
    func_02008904(src + 1708, dst + 1708, 162);
}

/* Re-inserts the three indexed variants of an id: removes the old entries, looks
 * up the four-byte record for `index` and, for each non -1 variant, calls the
 * entry setter. When `check` is 1 it also verifies variant 0-2 through
 * Unk09a268_Unk_09a3a0, clearing the result on failure. `index` selects the
 * record; `a5` is stored as a byte. Evidence: the three unrolled blocks and the
 * entry record reads at 0209a638. */
int func_0209a638(u8 *work, u32 id, int index, u32 value, u32 a5, int check)
{
    int ok = 1;
    Unk09a268Entry4 *entry;
    func_0209a4fc(work, id);
    entry = Unk0392f8_GetEntry36(work + 992, id) + index;
    if (entry->unk0 != -1) {
        Unk09a268_Unk_09a458(work, id, entry->unk0, 0, a5, value);
        if (check == 1 && Unk09a268_Unk_09a3a0(work, id, 0) == 0) ok = 0;
    }
    if (entry->unk1 != -1) {
        Unk09a268_Unk_09a458(work, id, entry->unk1, 1, a5, value);
        if (check == 1 && ok == 1 && Unk09a268_Unk_09a3a0(work, id, 1) == 0) ok = 0;
    }
    if (entry->unk2 != -1) {
        Unk09a268_Unk_09a458(work, id, entry->unk2, 2, a5, value);
        if (check == 1 && ok == 1 && Unk09a268_Unk_09a3a0(work, id, 2) == 0) ok = 0;
    }
    return ok;
}

/* Releases the work's seven resource slots, resets the shared engine state and
 * clears the global context pointer. Evidence: the paired free calls and the
 * data_02176270 store at 0209b5d8. */
void func_0209b5d8(Unk09a268Cleanup *work)
{
    int i;
    Unk065e88_Unk_065eac();
    Unk0fd268_Unk_0fd3ac();
    Unk044394_Unk_044534(7);
    Unk044394_Unk_044534(12);
    Unk044394_Unk_044534(18);
    Unk044394_Unk_044534(24);
    Unk044394_Unk_044534(19);
    Unk044394_Unk_044534(22);
    Unk044394_Unk_044534(23);
    Unk044394_Unk_044534(11);
    if (work->unk_000c != 0) { func_0205ddb4(); work->unk_000c = 0; }
    if (work->unk_0010 != 0) { func_0205ddb4(); work->unk_0010 = 0; }
    if (work->unk_0014 != 0) { func_0205c368(); work->unk_0014 = 0; }
    if (work->unk_0018 != 0) { func_0205c3dc(); work->unk_0018 = 0; }
    if (work->unk_001c != 0) { func_0205c3dc(); work->unk_001c = 0; }
    if (work->unk_0020 != 0) { func_0205c3dc(); work->unk_0020 = 0; }
    if (work->unk_0024 != 0) { func_0205c3dc(); work->unk_0024 = 0; }
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
    Unk02e000_Unk_02e0cc();
    Unk05ae50_Unk_05af2c(194);
    func_0205bb68();
    for (i = 42; i <= 48; i++) func_0205bb68();
    Unk0c855c_Unk_0ca648(1);
    data_02176270 = 0;
}

/* Maps a cell kind and a direction to the direction mask accepted by that kind.
 * Kinds 3, 8-12, 14, 23-28 and 37 accept the mask unchanged; kinds 4-7 accept it
 * only for direction 0, 2, 3 or 1 respectively; kinds 13 and 36 invert the
 * "mask == 1" test; every other kind yields 0. Evidence: the 41-entry jump table
 * at 0209bd08. */
int func_0209bd08(u32 kind, u32 direction, u32 mask)
{
    switch (kind) {
    case 0: case 1: case 2:
    case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22:
    case 29: case 30: case 31: case 32: case 33: case 34: case 35:
    case 38: case 39: case 40:
        return 0;
    case 13:
    case 36:
        return mask != 1;
    case 3:
    case 8: case 9: case 10: case 11: case 12:
    case 14:
    case 23: case 24: case 25: case 26: case 27: case 28:
    case 37:
        return mask;
    case 4:
        return direction == 0 ? mask : 0;
    case 5:
        return direction == 2 ? mask : 0;
    case 6:
        return direction == 3 ? mask : 0;
    case 7:
        return direction == 1 ? mask : 0;
    }
    return 0;
}

/* Advances the kind-1 transition: phase 0 waits 40 ticks, then clears the cell
 * flag and enters owner state 2; phase 1 waits 10 ticks and steps the work-area
 * position by one cell (kind 0-3 selects down/right/up/left) before notifying
 * 02034b7c; phase 2 completes once the owner's +0x7440 word is non-zero.
 * Evidence: the phase switch and position jump table at 0209c854. */
int func_0209c854(u8 *work)
{
    Unk09a268Transition *w = (Unk09a268Transition *)work;
    Unk09a268Cell *cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
    int result = 0;
    func_02052da0();
    w->counter++;
    cell->counter++;
    switch (w->phase) {
    case 0:
        if (w->counter > 40) {
            Unk09a268_Unk_09a870((u32)cell, 0);
            w->owner->state = 2;
            w->owner->next = 2;
            w->counter = 0;
            w->phase++;
        }
        break;
    case 1:
        if (w->counter > 10) {
            Unk09a268WorkArea *area = Unk02e000_GetWorkArea();
            int x = w->x;
            int y = w->y;
            switch (area->unk_0358) {
            case 0: y--; break;
            case 1: x++; break;
            case 2: y++; break;
            case 3: x--; break;
            }
            func_02034b7c(area->unk_035c, x, y, area->unk_0358, 3, 0, 0, 1);
            w->phase++;
        }
        break;
    case 2:
        if (w->unk_7440 != 0) result = 1;
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

/* Advances the kind-2 transition: phase 0 waits 40 ticks and enters owner state
 * 2; phase 1 waits for owner state 1, clears owner +0xc and enters state 2;
 * phase 2 waits for owner state 1, and once mode 13 matches, raises the +0x73e0
 * flag, clears owner +4, sets +0x757c to 4 and re-arms the seven scan-visor
 * slots. Evidence: the phase switch and the calls at 0209c9bc. */
int func_0209c9bc(u8 *work)
{
    Unk09a268Transition *w = (Unk09a268Transition *)work;
    Unk09a268Cell *cell = (Unk09a268Cell *)Unk02f2a8_GetCurrentCell38e8();
    int result = 0;
    int i;
    func_02052da0();
    w->counter++;
    cell->counter++;
    switch (w->phase) {
    case 0:
        if (w->counter > 40) {
            Unk09a268_Unk_09a870((u32)cell, 0);
            w->owner->state = 2;
            w->owner->next = 2;
            func_0205257c(3);
            w->phase++;
        }
        break;
    case 1:
        if (w->owner->state == 1) {
            w->owner->unk_000c = 0;
            w->owner->state = 2;
            w->owner->next = 2;
            w->phase++;
        }
        break;
    case 2:
        if (w->owner->state == 1) {
            if (Unk02d15c_IsMode1Match(13) == 1) {
                w->unk_73e0 = 1;
                w->owner->unk_0004 = 0;
                w->unk_757c = 4;
                ScanVisor_Unk_0a2acc();
                for (i = 0; i < 7; i++) {
                    ScanVisor_Unk_0a2a8c(i);
                }
                func_02095f94();
            }
            result = 1;
        }
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

/* Maps the encoded cell byte to its 0x1c-byte record kind. The original
 * 41-way switch groups the directional variants; out-of-range values use 0. */
int func_0209bb68(u32 encoded)
{
    switch (encoded) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: case 5: case 6: case 7: return 4;
    case 8: case 9: return 5;
    case 10: return 6;
    case 11: return 7;
    case 12: return 8;
    case 13: return 9;
    case 14: return 10;
    case 15: return 11;
    case 16: case 17: case 18: case 19: return 12;
    case 20: return 13;
    case 21: case 22: return 14;
    case 23: return 15;
    case 24: case 25: return 16;
    case 26: case 27: return 17;
    case 28: return 18;
    case 29: return 19;
    case 30: case 31: return 20;
    case 32: return 21;
    case 33: case 34: return 22;
    case 35: return 23;
    case 36: return 24;
    case 37: return 25;
    case 38: return 26;
    case 39: return 27;
    case 40: return 28;
    }
    return 0;
}

/* Tests the map entry at (x,y) against direction/mask. Kinds 9, 16 and 17
 * inspect element 3, 7 and 8 respectively; other kinds use 0209bd08. */
int func_0209bf00(u32 x, u32 y, u32 direction, u32 mask)
{
    int result = 0;
    u32 handle = Unk02f2a8_Unk_034970(GetGameState() + 4, x, y);
    u8 *entry = Unk038fbc_Unk_039160(handle, x, y);
    if (entry != 0) {
        u32 encoded = *entry;
        switch (func_0209bb68(encoded)) {
        case 9:
            if (mask == 0) {
                s32 *element = Unk038fbc_GetElement(handle, 3, entry[1]);
                if (element != 0) {
                    u32 bits = 0;
                    switch (direction) {
                    case 1: bits = 4; break;
                    case 2: bits = 1; break;
                    case 3: bits = 8; break;
                    case 0: bits = 2; break;
                    }
                    if (bits & ((u32)(*element << 28) >> 28)) result = 1;
                }
            }
            break;
        case 16:
            if (mask == 1) {
                s32 *element = Unk038fbc_GetElement(handle, 7, entry[1]);
                if (element != 0) {
                    if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y),
                                         ((u32)*element << 16) >> 24) == 3) result = 1;
                }
            }
            break;
        case 17:
            if (mask == 1) {
                u8 *element = (u8 *)Unk038fbc_GetElement(handle, 8, entry[1]);
                if (element != 0) {
                    if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y),
                                         *element) == 3) result = 1;
                }
            }
            break;
        default:
            result = func_0209bd08(encoded, direction, mask);
            break;
        }
    }
    return result;
}

/* Slot messages contain two flag bytes and sixteen optional word values. */
typedef struct Unk09a268SlotMessage {
    u8 flags[2];
    u8 pad_02[2];
    u32 words[16];
} Unk09a268SlotMessage;
void Unk0bc1a8_Unk_0bc928(u32 slot, u32 value, Unk09a268SlotMessage *message);
void CampStatus_Unk_0d51cc(void);
void func_020bc9f4(u32 slot, u32 value);
void func_020bcbc4(u32 slot, Unk09a268SlotMessage *message);
void func_020e7f44(u32 a, u32 b, u32 c, u32 d);

static inline void Unk09a268_ClearSlotMessage(Unk09a268SlotMessage *message)
{
    int i;
    for (i = 0; i < 2; i++) message->flags[i] = 0;
    for (i = 0; i < 16; i++) message->words[i] = 0;
}

/* Resets slots 0/2/1/3/10 and sends their flagged setup values. The stack
 * message flags and slot constants are established by the calls at 0209b960. */
void func_0209b960(void)
{
    Unk09a268SlotMessage message;
    Unk09a268_ClearSlotMessage(&message);
    message.words[3] = 1;
    message.words[4] = 1;
    message.flags[0] |= 0x18;
    Unk0bc1a8_Unk_0bc928(0, 0xffff, &message);
    Unk0bc1a8_Unk_0bc928(2, 0, &message);
    Unk0bc1a8_Unk_0bc928(1, 2, 0);
    CampStatus_Unk_0d51cc();
    Unk09a268_ClearSlotMessage(&message);
    message.words[3] = 2;
    message.words[5] = 0;
    message.flags[0] |= 0x28;
    Unk0bc1a8_Unk_0bc928(3, 0, &message);
    Unk0bc1a8_Unk_0bc928(10, 0, 0);
    func_020bc9f4(0, 0);
    func_020bc9f4(2, 0);
    func_020bc9f4(1, 0);
    func_020bc9f4(3, 0);
    func_020bc9f4(10, 0);
    Unk09a268_ClearSlotMessage(&message);
    message.words[1] = 1;
    message.flags[0] |= 2;
    func_020bcbc4(3, &message);
    Unk09a268_ClearSlotMessage(&message);
    message.words[1] = 1;
    message.flags[0] |= 2;
    func_020bcbc4(10, &message);
}

/* Sets slot 0's flagged value, resets the other slots, then configures the
 * 0/14/9/12 selection. Evidence: 0209b774's message stores and call constants. */
void func_0209b774(u32 value)
{
    Unk09a268SlotMessage message;
    Unk09a268_ClearSlotMessage(&message);
    message.words[4] = value;
    message.flags[0] |= 0x10;
    Unk0bc1a8_Unk_0bc928(0, 0xffff, &message);
    Unk0bc1a8_Unk_0bc928(2, 0, 0);
    Unk0bc1a8_Unk_0bc928(1, 2, 0);
    CampStatus_Unk_0d51cc();
    Unk09a268_ClearSlotMessage(&message);
    message.words[3] = 2;
    message.words[5] = 0;
    message.flags[0] |= 0x28;
    Unk0bc1a8_Unk_0bc928(3, 0, &message);
    Unk0bc1a8_Unk_0bc928(10, 0, 0);
    func_020bc9f4(0, 0);
    func_020bc9f4(2, 0);
    func_020bc9f4(1, 0);
    func_020bc9f4(3, 0);
    func_020bc9f4(10, 0);
    Unk09a268_ClearSlotMessage(&message);
    message.words[1] = 1;
    message.flags[0] |= 2;
    func_020bcbc4(3, &message);
    func_020e7f44(0, 14, 9, 12);
    Unk09a268_ClearSlotMessage(&message);
    message.words[1] = 1;
    message.flags[0] |= 2;
    func_020bcbc4(10, &message);
}

int func_02052728(void);
void func_0205c6e0(void *resource);
void func_0205c704(void *resource);
/* Drives callback states 0, 2 and 14. State 2 advances the work counter and
 * sends flagged slot messages at counters 0 and 5; state 14 waits for the
 * engine transition before restoring the saved state at +8. */
void func_0209b1d4(Unk09a268Work *work)
{
    switch (work->unk_0004) {
    case 0:
        if (func_02052728() != 0) return;
        work->unk_0004 = 2;
        func_0205c6e0(work->unk_0018);
        func_0205c6e0(work->unk_001c);
        func_0205c6e0(work->unk_0020);
        break;
    case 2:
        if (work->unk_0028 == 0) {
            func_0205c704(work->unk_0018);
            func_0205c704(work->unk_001c);
            func_0205c704(work->unk_0020);
            func_0205c704(work->unk_0024);
        }
        if (work->unk_0000 == 0) {
            Unk09a268SlotMessage message;
            Unk09a268_ClearSlotMessage(&message);
            message.words[7] = 1;
            message.flags[0] |= 0x80;
            func_020bcbc4(1, &message);
        }
        if (work->unk_0000 == 5) {
            Unk09a268SlotMessage message;
            Unk09a268_ClearSlotMessage(&message);
            message.words[7] = 1;
            message.flags[0] |= 0x80;
            func_020bcbc4(2, &message);
            Unk09a268_ClearSlotMessage(&message);
            message.words[7] = 6;
            message.flags[0] |= 0x80;
            func_020bcbc4(1, &message);
        }
        if (work->unk_0000 == 10) func_0205c6e0(work->unk_0024);
        work->unk_0000++;
        break;
    case 14:
        if (func_02052728() != 0) return;
        work->unk_0004 = work->unk_0008;
        func_020525cc(0);
        break;
    }
}

extern char data_0214c964[], data_0214c974[], data_0214c984[];
void func_020ca5a4(int value);
void Unk05b82c_Unk_05b82c(int id);
u32 func_0205dcd4(const char *path, int mode);
void *func_0205c2c4(const char *path);
void *func_0205c3c0(void);
void func_0205c3fc(void *resource, void *data, void *table);
void func_0205c408(void *resource, int value);
void func_0205c41c(void *resource, int value);
void Unk05ae50_Unk_05ae50(int id);
u32 func_0205b97c(int id);
void func_02052634(int a, int b, int c);
void Unk044394_Unk_044428(int id);
void Unk0a0ce4_Unk_0a0d30(int value);
void Unk0fd268_Unk_0fd380(int value);
void Unk0fd268_Unk_0fd47c(void);
void Unk0fd268_Unk_0fd494(int a, int b);
void Unk065e88_Unk_065e88(void);
/* Only the word at +0x1244 is established by the initialization callback. */
typedef struct Unk09a268SharedArea {
    u8 pad_0000[0x1244];
    u32 unk_1244;
} Unk09a268SharedArea;
Unk09a268SharedArea *Unk02e000_GetAddr_data_02140ac8(void);

/* Initializes the callback work and its four resources, loads the three
 * data_0214c964/974/984 assets, and arms the fixed engine paths. Evidence:
 * resource setup calls and literal references in 0209afcc. Work is 60 bytes. */
void func_0209afcc(Unk09a268Work *work)
{
    Unk09a268SharedArea *shared;
    int i;
    data_02176270 = (Unk09a268Ctx *)work;
    work->unk_0000 = 0;
    work->unk_0004 = 0;
    work->unk_0028 = 0;
    work->UnkField002c = 0;
    work->unk_0030 = 0;
    work->unk_0038 = 0;
    Unk09a268_SetCtxUnk38(Unk02e000_GetWorkArea()->unk_0344);
    func_020ca5a4(1);
    Unk05b82c_Unk_05b82c(57);
    work->UnkField000c = func_0205dcd4(data_0214c964, 1);
    Unk05b82c_Unk_05b82c(58);
    Unk05b82c_Unk_05b82c(61);
    Unk05b82c_Unk_05b82c(64);
    work->unk_0010 = (void *)func_0205dcd4(data_0214c974, 1);
    work->unk_0014 = func_0205c2c4(data_0214c984);
    work->unk_0018 = func_0205c3c0();
    func_0205c3fc(work->unk_0018, work->unk_0010, work->unk_0014);
    func_0205c408(work->unk_0018, 3);
    func_0205c41c(work->unk_0018, 0);
    work->unk_001c = func_0205c3c0();
    func_0205c3fc(work->unk_001c, work->unk_0010, work->unk_0014);
    func_0205c408(work->unk_001c, 4);
    func_0205c41c(work->unk_001c, 0);
    work->unk_0020 = func_0205c3c0();
    func_0205c3fc(work->unk_0020, work->unk_0010, work->unk_0014);
    func_0205c408(work->unk_0020, 5);
    func_0205c41c(work->unk_0020, 0);
    work->unk_0024 = func_0205c3c0();
    func_0205c3fc(work->unk_0024, work->unk_0010, work->unk_0014);
    func_0205c408(work->unk_0024, 2);
    func_0205c41c(work->unk_0024, 0);
    Unk02e000_Unk_02e0cc();
    Unk05ae50_Unk_05ae50(194);
    shared = Unk02e000_GetAddr_data_02140ac8();
    shared->unk_1244 = func_0205b97c(194);
    work->unk_0008 = 2;
    func_02052634(1, 0, 31);
    Unk044394_Unk_044428(18);
    Unk044394_Unk_044428(24);
    Unk044394_Unk_044428(19);
    Unk044394_Unk_044428(22);
    Unk044394_Unk_044428(23);
    for (i = 42; i <= 48; i++) Unk05b82c_Unk_05b82c(i);
    Unk044394_Unk_044428(12);
    Unk044394_Unk_044428(7);
    Unk044394_Unk_044428(11);
    Unk0a0ce4_Unk_0a0d30(1);
    Unk0fd268_Unk_0fd380(3);
    Unk0fd268_Unk_0fd47c();
    Unk0fd268_Unk_0fd494(-3, 58);
    Unk065e88_Unk_065e88();
}

void func_02057e58(int a, int b, int c);
void func_02057fd8(void);
void func_0205c848(int mode, void *resource, int x, int y,
                  float scaleX, float scaleY, int rotation, float alpha, int layer);
char *func_020a9e14(int mode, const char *format, ...);
void func_020a9fd8(int mode, void *target, int x, int y, const char *text,
                  int value, const char *format, ...);
int Unk0e651c_Unk_0e666c(u32 flag);
void func_02057eb8(int value);
extern char data_0214c994[], data_0214c9a0[], data_0214c9a4[];
extern char data_0214c9a8[], data_0214c9b4[];
/* Resource +0x14 points to the byte-addressed draw target used by this callback. */
typedef struct Unk09a268DrawResource {
    u8 pad_0000[0x14];
    u8 *target;
} Unk09a268DrawResource;

/* Draws the four initialized resources when enabled, then formats the two
 * text overlays. Evidence: palette/draw calls, flag 0x701, and the six string
 * literals at 0209b5c0; text semantics remain unknown. */
void func_0209b3f8(Unk09a268Work *work)
{
    char *text;
    func_02057e58(1, 0, 10);
    if (work->unk_0030 == 0) {
        Unk_LoadPalette_020de678(work->UnkField000c);
    }
    if (work->unk_0028 == 0) {
        func_02057fd8();
        func_0205c848(2, work->unk_0018, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
        func_0205c848(2, work->unk_001c, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
        func_0205c848(2, work->unk_0020, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
        func_02057fd8();
        func_0205c848(2, work->unk_0024, 0, 0, 1.0f, 1.0f, 0, 1.0f, 3);
        func_02057fd8();
        text = func_020a9e14(1, data_0214c994);
        if (Unk0e651c_Unk_0e666c(0x701) != 0) {
            func_020a9fd8(1, ((Unk09a268DrawResource *)work->unk_0020)->target + 45,
                          16, 2, text, 10, data_0214c9a0);
        } else {
            func_020a9fd8(1, ((Unk09a268DrawResource *)work->unk_0020)->target + 45,
                          16, 2, text, 10, data_0214c9a4);
        }
        text = func_020a9e14(1, data_0214c9a8, Unk02e000_GetWorkArea()->unk_0344);
        func_020a9fd8(1, ((Unk09a268DrawResource *)work->unk_0020)->target + 45,
                      16, 2, text, 10, data_0214c9b4, work->unk_0038);
    }
    func_02057eb8(-1);
}

/* Only fields observed by the transition update are represented. */
typedef struct Unk09a268PendingOwner {
    u8 pad_0000[0x5c];
    u32 unk_005c;
} Unk09a268PendingOwner;
typedef struct Unk09a268MapWork {
    Unk09a268PendingOwner *unk_0000;
    u8 pad_0004[0x30];
    s8 unk_0034[0x24];
    u16 unk_0058;
    u8 pad_005a[0x4a];
    u32 unk_00a4;
    u8 unk_00a8[0x198];
    u8 unk_0240[0x7240];
    u8 unk_7480;
    u8 pad_7481[1];
    s8 unk_7482;
    s8 unk_7483;
    u8 pad_7484[8];
    u32 unk_748c;
    u32 unk_7490;
} Unk09a268MapWork;
/* Packed map flags are nibbles 3, 4 and 5 in entry word +4. */
typedef struct Unk09a268MapEntry {
    u32 unk_0000;
    u32 pad:12;
    u32 unk_0004_12:4;
    u32 unk_0004_16:4;
    u32 unk_0004_20:4;
    u32 rest:8;
} Unk09a268MapEntry;
void Unk0a0ce4_Unk_0a0da4(int value);
void func_02052d7c(void *dst, u32 value);
void Unk02d15c_Call_02d91c(void);
int func_0202d170(void);
void func_0202d198(void);
int Unk02d15c_Unk_02d794(int x, int y);
int Unk0e5fb8_Unk_0e63c8(int value);
/* Updates the pending transition from adjacent-cell flag differences. Evidence:
 * direction at work-area +0x358 selects the neighbor; entry word +4 nibbles
 * select writes to +0x7480/+0x748c/+0x7490. The work object is writable. */
void func_0209c548(Unk09a268MapWork *work)
{
    int x, y, changed;
    Unk09a268MapEntry *current, *next;
    int pending;
    work->unk_0000->unk_005c = 1;
    Unk0a0ce4_Unk_0a0da4(work->unk_0058);
    func_02052d7c(work->unk_00a8, work->unk_00a4);
    work->unk_7480 = 0;
    x = work->unk_7482;
    y = work->unk_7483;
    switch (Unk02e000_GetWorkArea()->unk_0358) {
    case 0: y--; break;
    case 1: x++; break;
    case 2: y++; break;
    case 3: x--; break;
    }
    changed = 0;
    Unk02d15c_Call_02d91c();
    if (func_0202d170() != 0) {
        do {
            if (Unk02d15c_Unk_02d794(x, y) == 1) {
                work->unk_7480 = 2;
                changed = 1;
                work->unk_748c = 1;
                work->unk_7490 = 1;
                break;
            } else {
                func_0202d198();
            }
        } while (func_0202d170() != 0);
    }
    if (changed == 0) {
        current = (Unk09a268MapEntry *)Unk038fbc_Unk_039160((u32)work->unk_0240,
            Unk02e000_GetWorkArea()->unk_0364, Unk02e000_GetWorkArea()->unk_0365);
        next = (Unk09a268MapEntry *)Unk038fbc_Unk_039160((u32)work->unk_0240, x, y);
        if (current == 0 || next == 0) return;
        pending = 0;
        if (current->unk_0004_12 != next->unk_0004_12) {
            work->unk_7480 = 1;
            work->unk_748c = 1;
            if (current->unk_0004_12 == 0) work->unk_7490 = 1;
            pending = 1;
        }
        if (pending == 0) {
            u32 b = next->unk_0004_16;
            u32 a = current->unk_0004_16;
            if (a != b) {
                int value = 0;
                if (b != 0) value = work->unk_0034[b - 1];
                else if (a != 0) value = work->unk_0034[a - 1];
                if (value >= 0 && Unk0e5fb8_Unk_0e63c8(value) != 0) {
                    pending = 1;
                    work->unk_7480 = 1;
                    work->unk_748c = 1;
                    work->unk_7490 = 1;
                }
            }
        }
        if (pending == 0 && current->unk_0004_20 != next->unk_0004_20) {
            work->unk_7480 = 1;
            work->unk_748c = 1;
            work->unk_7490 = 1;
        }
    }
}

/* Word-backed element indices retain the packed field access width. */
typedef struct Unk09a268PackedElement {
    u32 low:8;
    u32 index:8;
    u32 rest:16;
} Unk09a268PackedElement;
int Unk116598_Unk_117050(int x, int y);
int Unk0e651c_TestFlag(u32 value, u32 bit);
int func_021227fc(int x, int y);
int Unk1124f0_Unk_112564(int x, int y);
int Unk116360_Unk_116438(int x, int y);
int Unk10b4d0_Unk_10b7bc(void);
int func_0210b6c8(u32 value);
int Unk10b4d0_Unk_10b794(void);
int Unk1122bc_IsCurrent(u32 value);
int Unk1122bc_Unk_1124c8(void);
int Unk1159f8_IsCurrent(u32 value);
int Unk1159f8_Unk_115c68(int x, int y);
/* Dispatches the located cell's kind to its state predicate, returning zero for
 * absent maps/cells and unsupported kinds. Evidence: 09bb68's kind mapping and
 * the element-flag tests in the 0209c1e4 jump table. Coordinates are map cells. */
int func_0209c1a0(u32 handle, void *table, int x, int y)
{
    int result;
    u8 *entry;
    u32 encoded;
    if (handle == 0) return 0;
    result = 0;
    entry = Unk038fbc_Unk_039160(handle, x, y);
    if (entry != 0) {
        encoded = *entry;
        switch (func_0209bb68(encoded)) {
        case 1: result = Unk116598_Unk_117050(x, y); break;
        case 3: {
            u8 *element = (u8 *)Unk038fbc_GetElement(handle, 0, entry[1]);
            if (Unk0e651c_TestFlag(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y), element[26]) == 1)
                result = 2;
            break;
        }
        case 5: result = func_021227fc(x, y); break;
        case 8: result = Unk1124f0_Unk_112564(x, y); break;
        case 11: result = Unk116360_Unk_116438(x, y); break;
        case 12: result = Unk10b4d0_Unk_10b7bc(); break;
        case 16: {
            Unk09a268PackedElement *element = (Unk09a268PackedElement *)Unk038fbc_GetElement(handle, 7, entry[1]);
            if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y), element->index) == 3) {
                u8 *cell = Unk0392f8_Unk_0394b8(table, x, y);
                if (cell != 0) result = func_0209c4e0(cell) == 1 ? -1 : 2;
            }
            break;
        }
        case 17: {
            u8 *element = (u8 *)Unk038fbc_GetElement(handle, 8, entry[1]);
            if (Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y), *element) == 3) {
                u8 *cell = Unk0392f8_Unk_0394b8(table, x, y);
                if (cell != 0) result = func_0209c4e0(cell) == 1 ? -1 : 2;
            }
            break;
        }
        case 19:
            if (func_0210b6c8(Unk02e000_GetWorkArea()->unk_035c) == 1) {
                result = Unk10b4d0_Unk_10b794();
                break;
            }
            if (Unk1122bc_IsCurrent(Unk02e000_GetWorkArea()->unk_035c) == 1) {
                result = Unk1122bc_Unk_1124c8();
                break;
            }
            if (Unk1159f8_IsCurrent(Unk02e000_GetWorkArea()->unk_035c) == 1)
                result = Unk1159f8_Unk_115c68(x, y);
            break;
        case 20:
        case 22: result = func_0209a970(encoded, x, y); break;
        case 23: {
            Unk09a268PackedElement *element = (Unk09a268PackedElement *)Unk038fbc_GetElement(handle, 11, entry[1]);
            result = Unk0e651c_Get2Bits(Unk02f2a8_Unk_0349c4(GetGameState() + 4, x, y), element->low) * 2;
            break;
        }
        }
    }
    return result;
}

Unk09a268Cell *Unk02f2a8_GetCell38e8(int x, int y);
/* Updates kinds 30/31/33/34 in the clipped seven-by-seven neighborhood.
 * Evidence: encoded cell kinds select Manhattan radii 1/2, record 20 supplies
 * state bits, and body +0x50/+0x52 supplies the once-per-call notification.
 * Coordinates are cells within the 45 by 40 map. */
void func_0209aa00(u32 handle, int x, int y)
{
    Unk09a268GameStateBody *body;
    Unk09a268Rec *record;
    int notified;
    int left, top, right, bottom;
    int column, row;
    if (Unk1122bc_Unk_1124a0() == 0) return;
    body = GameState_GetBody();
    record = Unk09a268_Unk_09c484(20);
    left = x - 3;
    top = y - 3;
    right = x + 3;
    bottom = y + 3;
    if (left < 0) left = 0;
    if (top < 0) top = 0;
    if (right > 44) right = 44;
    if (bottom > 39) bottom = 39;
    notified = 0;
    for (row = top; row <= bottom; row++) {
        column = left;
        if (column <= right) {
            int dy = y - row;
            int negative_dy = -dy;
            do {
                u8 *entry = Unk038fbc_Unk_039160(handle, column, row);
                if (entry != 0) {
                    int radius = 0;
                    int notification = -1;
                    switch (*entry) {
                    case 30:
                        radius = 1;
                        if (body != 0) notification = body->unk_0050;
                        break;
                    case 31:
                        radius = 2;
                        if (body != 0) notification = body->unk_0050;
                        break;
                    case 33:
                        radius = 1;
                        if (body != 0) notification = body->unk_0052;
                        break;
                    case 34:
                        radius = 2;
                        if (body != 0) notification = body->unk_0052;
                        break;
                    }
                    if (radius > 0) {
                        Unk09a268Cell *cell = Unk02f2a8_GetCell38e8(column, row);
                        int distance_y = dy >= 0 ? dy : negative_dy;
                        int dx = x - column;
                        if (dx < 0) dx = -dx;
                        if (dx + distance_y <= radius) {
                            if (cell->kind == 3 || cell->kind == 0) {
                                Unk09a268_Unk_09a80c((u32)cell, 1);
                                Unk09a268_Unk_09a830((u32)cell, 0);
                                Unk09a268_Unk_09a870((u32)cell, 0);
                                Unk09a268_SetOnlyBit((u32)cell, record->unk_19);
                                cell->kind = 1;
                                cell->counter = 0;
                                if (notification >= 0 && notified == 0) {
                                    Unk0a0ce4_Unk_0a0da4(notification);
                                    notified = 1;
                                }
                            }
                        } else if (cell->kind == 1 || cell->kind == 2) {
                            Unk09a268_Unk_09a80c((u32)cell, 1);
                            Unk09a268_Unk_09a830((u32)cell, 0);
                            Unk09a268_Unk_09a870((u32)cell, 0);
                            Unk09a268_SetOnlyBit((u32)cell, record->unk_19);
                            cell->kind = 3;
                            cell->counter = 0;
                            if (notification >= 0 && notified == 0) {
                                Unk0a0ce4_Unk_0a0da4(notification);
                                notified = 1;
                            }
                        }
                    }
                }
            } while (++column <= right);
        }
    }
}
