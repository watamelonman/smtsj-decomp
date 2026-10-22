/*
 * src/game/unit_0209a268.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;

/* Object passed as the first argument in this file (layout from field accesses; names unknown). */
typedef struct Unk09a268Work {
    u8 unk_0000[0xc];
    u32 UnkField000c;
    u8 unk_0010[0x18];
    s32 unk_0028;
    s32 UnkField002c;
    s32 unk_0030;
    s32 unk_0034;
} Unk09a268Work;


/* Partial work-area layout; only the accessed halfword, kind and coordinates are known.
 * unk_0358 is volatile because the transition handlers re-read it after engine calls;
 * keeping those two reads distinct reproduces the original 0209c854 code. See DEC-003. */
typedef struct Unk09a268WorkArea {
    u8 pad_0000[0x358];
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
int func_0209bb68();
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
  func_0209bb68();
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

/* Partial body layout: only the flag read by 09a844 is established here. */
typedef struct Unk09a268GameStateBody {
    u8 pad_0000[0x3e0];
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
void func_0209b1d4();
void func_0209b3f8();
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
int func_0209c548();
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
  func_0209c548(arg0);
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
