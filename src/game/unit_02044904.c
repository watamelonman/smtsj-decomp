/*
 * src/game/unit_02044904.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0215ee98[];
int func_0206df10(void);
int Unk071dc0_Unk_072200(void);
int Unk09d060_Unk_09d13c(void);

int Unk044904_GetConst1(void);
u32 Unk044904_Get_data_0215ee98(void);
u32 Unk044904_Unk_0459ec(void);
void Unk044904_Unk_045c98(void);
void Unk044904_Unk_044e90(int arg0);
int Unk044904_Unk_045fd4(void);
void Unk044904_Unk_044ea8(void);

typedef struct Unk044904Rec {
    u8 pad_0000[0x8];
    u16 unk_08;
} Unk044904Rec;

/* 8 x 12-byte keyed slots followed by a count (see Unk044904_Unk_044948). */
typedef struct Unk044904Slot {
    u16 id;
    u8 pad_02[10];
} Unk044904Slot;
typedef struct Unk044904SlotTab {
    Unk044904Slot slots[8];
    u32 count;
} Unk044904SlotTab;

typedef struct Unk044904Objs {
    u8 pad_0000[100];
    u32 objs[10];
} Unk044904Objs;

Unk044904Rec *Unk044904_Unk_044948(u32 a, u32 b);

typedef struct Unk044904Entry {
    u16 id;
    u8 pad_0002[10];
} Unk044904Entry;

Unk044904Entry *Unk044904_FindById(Unk044904Entry *tbl, u16 key)
{
    u32 i;
    Unk044904Entry *e;
    for (i = 0; i < FIELD(u32, tbl, 0x60); i++) {
        e = &tbl[i];
        if (key == e->id) {
            return &tbl[i];
        }
    }
    return 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u32 Unk044904_Get_data_0215ee98(void);
void func_02008848();
int func_02049a84();
void func_0204a8cc();

Unk044904Rec *Unk044904_Unk_044948(u32 a, u32 key)
{
    Unk044904SlotTab *t = (Unk044904SlotTab *)a;
    u32 n = t->count;
    u32 i;
    Unk044904Slot *e;
    for (i = 0; i < n; i++) {
        if (key == t->slots[i].id) {
            return (Unk044904Rec *)&t->slots[i];
        }
    }
    if (n >= 8) {
        return 0;
    }
    e = &t->slots[n];
    func_02008848(e, 0, 12);
    e->id = key;
    t->count++;
    return (Unk044904Rec *)e;
}

/* 02044b68: adds n modulo 65536 to the keyed record's halfword at +8.
 * The lookup must return a record; the original does not check for a full table. */
void Unk044904_AddRecUnk08(u32 a, u32 b, int n)
{
    Unk044904Rec *r = Unk044904_Unk_044948(a, b);
    r->unk_08 += n;
}

typedef struct Unk044904Obj {
    u32 unk_0000;               /* bits 16-23 tested as "active" */
    u8 pad_0004[0x1da];
    u8 unk_01de;
} Unk044904Obj;

typedef struct Unk044904Mgr {
    u8 pad_0000[0x40];
    u32 pad_0040_0 : 10;
    u32 flag_0040_10 : 1;
    u32 pad_0040_11 : 4;
    u32 flag_0040_15 : 1;
    u32 flag_0040_16 : 1;
    u32 pad_0040_17 : 1;
    u32 flag_0040_18 : 1;
    u8 pad_0044[0xc];
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0x4];
    u32 unk_005c;               /* compared with 1 by Unk044904_Unk_045460 */
    u8 pad_0060[0x4];
    Unk044904Obj *slots[10];    /* +0x64 */
} Unk044904Mgr;

#define UNK044904_MGR() ((Unk044904Mgr *)Unk044904_Get_data_0215ee98())
void func_0204a780();
void func_0204a694();
void Unk0bc1a8_Unk_0bc928();
Unk044904Obj *Unk044904_GetSlot(int i)
{
    Unk044904Mgr *m = UNK044904_MGR();
    if (m == 0) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    if (i >= 4) {
        return 0;
    }
    return m->slots[i];
}

void Unk044904_Unk_04527c(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && (o->unk_0000 >> 16 & 0xff)) {
            func_0204a780(o, 11);
        }
    }
}

/* 020453ac: clears the byte at +0x1de of every registered slot; null slots are
 * skipped (cmp/strbne), matching the other ten-slot walks in this file. */
void Unk044904_ClearSlotsUnk1de(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0) {
            o->unk_01de = 0;
        }
    }
}

void Unk044904_ForEachSlot_04a694(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0) {
            func_0204a694(o);
        }
    }
}

Unk044904Obj *Unk044904_FindInactiveSlot(void)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && (o->unk_0000 >> 16 & 0xff) == 0) {
            return o;
        }
    }
    return 0;
}

void Unk044904_Unk_0459fc(void)
{
    if (UNK044904_MGR()->flag_0040_10) {
        return;
    }
    UNK044904_MGR()->unk_0050 = 1;
    UNK044904_MGR()->unk_0054 = 0;
}

/* 02045c38: exposes manager bit 18 as 0/1 (ldr word at +0x40, lsl #13, lsr #31);
 * the same bitfield layout is used by Unk044904_Unk_0459fc. */
int Unk044904_GetFlag18(void)
{
    return UNK044904_MGR()->flag_0040_18 ? 1 : 0;
}

/* 02045c58: only argument 1 triggers the call to Unk0bc1a8_Unk_0bc928 with
 * (26, 0xffff, 0); every other value returns immediately (cmp #1 / popne). */
void Unk044904_Unk_045c58(int x)
{
    if (x != 1) {
        return;
    }
    Unk0bc1a8_Unk_0bc928(26, 0xffff, 0);
}

/* 02046100: unconditional mov r0,#1 supplies the constant return value. */
int Unk044904_GetConst1(void) { return 1; }

/* 02044e80: loads the word stored at data_0215ee98; zero means unregistered.
 * Returns the borrowed address as a 32-bit word, matching existing callers. */
u32 Unk044904_Get_data_0215ee98(void)
{
  return *data_0215ee98;
}

/* 020459ec: reads the registered manager's +0x50 word; requires registration. */
u32 Unk044904_Unk_0459ec(void)
{
    Unk044904Mgr *manager = UNK044904_MGR();
    return manager->unk_0050;
}

/* 02045c98: calls 0206df10 then 02072200, discarding both results. */
void Unk044904_Unk_045c98(void)
{
  func_0206df10();
  Unk071dc0_Unk_072200();
}

/* 02044e90: registers the supplied address only while the global word is zero.
 * The conditional store is the evidence for first-registration behavior. */
void Unk044904_Unk_044e90(int arg0)
{
  if (*data_0215ee98 == 0) {
    *data_0215ee98 = arg0;
  }
}

/* 02045fd4: normalizes 0209d13c's result to exactly zero or one. */
int Unk044904_Unk_045fd4(void)
{
  int value;
  value = Unk09d060_Unk_09d13c();
  return value != 0;
}

/* 02044ea8: clears a nonzero registration word without freeing its target. */
void Unk044904_Unk_044ea8(void)
{
  if (*data_0215ee98 != 0) {
    *data_0215ee98 = 0;
  }
}



int Unk044904_Unk_044f4c(u32 k)
{
    Unk044904Objs *t = (Unk044904Objs *)Unk044904_Get_data_0215ee98();
    int i;
    if (t == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        u32 o = t->objs[i];
        if (o != 0 && func_02049a84(o, k) != 0) {
            return i;
        }
    }
    return -1;
}

/* 020044fd8: returns the borrowed manager +0x379c address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_044fd8(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x379c;
    }
    return address;
}


/* 020044ff4: returns the borrowed manager +0x3fb0 address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_044ff4(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x3fb0;
    }
    return address;
}


/* 020045010: returns the borrowed manager +0x77bc address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_045010(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x77bc;
    }
    return address;
}


/* 02004502c: returns the borrowed manager +0x372c address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_04502c(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x372c;
    }
    return address;
}


/* 020045048: returns the borrowed manager +0x7804 address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_045048(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x7804;
    }
    return address;
}


/* 020045064: returns the borrowed manager +0x7874 address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_045064(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x7874;
    }
    return address;
}


/* 020045080: returns the borrowed manager +0x78e4 address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_045080(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x78e4;
    }
    return address;
}


/* 02004509c: returns the borrowed manager +0x7970 address word, or zero.
 * The original conditional adds establish the byte offset; ownership stays with
 * the registered manager and no subobject is dereferenced here.
 */
int Unk044904_Unk_04509c(void)
{
    u32 address = Unk044904_Get_data_0215ee98();
    if (address == 0) {
        address = 0;
    } else {
        address += 0x7970;
    }
    return address;
}


int Unk0bc1a8_IsSlotEmpty();
void Unk044904_Unk_0453dc(void)
{
    int i;
    int one = 1;
    for (i = 0; i < 10; i++) {
        u8 *o = (u8 *)((Unk044904Objs *)Unk044904_Get_data_0215ee98())->objs[i];
        if (o != 0 && ((FIELD(u32, o, 0) >> 16) & 0xff) != 0) {
            func_0204a8cc(o, one);
        }
    }
    FIELD(u32, Unk044904_Get_data_0215ee98(), 88) = 0;
}

/* 02045c7c: reports that slot 26 (0x1a) is not empty, inverting the 0/1 result
 * of Unk0bc1a8_IsSlotEmpty with cmp/moveq/movne. */
int Unk044904_Unk_045c7c(void)
{
    return Unk0bc1a8_IsSlotEmpty(26) == 0;
}

int func_020452c4();
int Unk0aa118_SortRemaining();
void Unk044904_Unk_045bd0();
void func_020456d8();
void func_020455cc();
int Unk044904_Unk_046468(s16 *st)
{
    Unk044904Mgr *m = UNK044904_MGR();
    FIELD(u16, m, 0x38)++;
    FIELD(u32, m, 0x40) &= ~0x10000;
    st[0] = 2;
    return 1;
}

/* 0204661c: one-shot script step: if the s16 at +2 is 1, write state 2 to the
 * s16 at +0; otherwise call Unk044904_Unk_045bd0(0). Always returns 2. */
int Unk044904_Unk_04661c(s16 *st)
{
    if (st[1] == 1) {
        st[0] = 2;
    } else {
        Unk044904_Unk_045bd0(0);
    }
    return 2;
}

int Unk044904_Unk_046644(void)
{
    if (UNK044904_MGR()->flag_0040_16 && Unk044904_Unk_045460(1) != 0) {
        return 2;
    }
    func_020456d8(0);
    func_020455cc(2);
    return 1;
}

/* 02046688: calls func_020452c4, Unk044904_Unk_044fd8, Unk0aa118_SortRemaining
 * and Unk044904_Unk_045c98 in that order, discarding every result (bare bls);
 * returns 1 unconditionally. */
u32 Unk044904_Unk_046688(void)
{
  func_020452c4();
  Unk044904_Unk_044fd8();
  Unk0aa118_SortRemaining();
  Unk044904_Unk_045c98();
  return 1;
}


/* 02045460: reports whether the argument equals the manager's +0x5c word (the
 * word is loaded with ldr r0,[r0,#92] after registration; cmp/moveq/movne). */
int Unk044904_Unk_045460(int arg0)
{
  return arg0 == UNK044904_MGR()->unk_005c;
}

int func_02045ca8();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
typedef struct Unk044904Bits {
    u8 pad_0000[0x40];
    u32 b0 : 3;
    u32 b3 : 1;
    u32 b4 : 5;
    u32 b9 : 1;
    u32 b10 : 1;
    u32 b11 : 9;
    u32 b20 : 1;
    u32 b21 : 11;
    u8 pad_0044[0x8];
    u32 unk_004c;
} Unk044904Bits;
typedef struct Unk044904Item {
    u32 hdr;
    u8 pad[732];
} Unk044904Item;
typedef struct Unk044904Items {
    u8 pad_0000[876];
    Unk044904Item items[12];
} Unk044904Items;
void func_02121d84();
void func_02122188();
void func_02122200();
int func_0204a9ec();
void func_0204a884();
int func_0205e4f8();
void func_0205e484();
void Unk09d42c_Init_data_02176278();
void func_020458e8();
void func_020525cc();
void Unk0a4e48_Unk_0a4e9c();
void Unk05ae50_Unk_05afd8();
void func_020a609c();
int func_020a4f3c();
int func_02052728();
int Unk09d060_Unk_09d13c(void);
void Unk044904_Unk_045480(void);

void Unk044904_Unk_045480(void)
{
    Unk044904Bits *m = (Unk044904Bits *)Unk044904_Get_data_0215ee98();
    Unk044904Items *it = (Unk044904Items *)m;
    int i;
    if (m->b10) {
        return;
    }
    if (m->b20) {
        return;
    }
    m->b20 = 1;
    func_02121d84();
    for (i = 0; i < 12; i++) {
        if (((it->items[i].hdr >> 16) & 0xff) == 1) {
            func_02122188(&it->items[i]);
        }
    }
    func_02122200();
}

/* 02046448: when func_02045ca8 reports pending work, writes state 2 through the
 * caller's halfword pointer (movne r0,#2; strhne); always returns 1. */
u32 Unk044904_Unk_046448(u16 *arg0)
{
  if (func_02045ca8() != 0) {
    *arg0 = 2;
  }
  return 1;
}


int func_020450b8();
int func_02045138();
void Unk044904_Unk_04527c();
int Unk0aa118_Clear814();
int func_020f8098();
/* decompiler-derived */
u32 Unk044904_Unk_046108(u16 *arg0)
{
  u32 value1;
  int value2;
  Unk044904_Unk_044fd8();
  Unk0aa118_Clear814();
  func_02045138();
  Unk044904_Unk_04527c();
  func_020450b8();
  value1 = Unk044904_Unk_045080();
  value2 = func_020f8098(value1,0,0);
  if (value2 != 0) {
    *arg0 = 2;
  }
  return 2;
}


int Unk0a5680_Unk_0a5c14();
/* decompiler-derived */
u32 Unk044904_Unk_04599c(u32 *arg0)
{
  int value1;
  u32 value2;
  int value3;
  value2 = 0;
  value3 = 0;
  do {
    if ((*arg0 != 0) &&
       (value1 = Unk0a5680_Unk_0a5c14(*arg0 & 0xffff,arg0[1],arg0[2]), value1 != 0)) {
      value2 = 1;
    }
    value3 = value3 + 1;
    arg0 = arg0 + 3;
  } while (value3 < 6);
  return value2;
}

extern u8 data_02142b4c[];
extern u8 data_02142b64[];
int func_02013c3c();
int func_020513d4();
int func_020a1740();
/* Builds "Data/Enemy/AI/ai_%s.bf" for an enemy; falls back to ai_scr_test.bf if missing. */
void Unk044904_BuildEnemyAiPath(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020a1740(arg1);
  if (tmp1 != 0) {
    func_02013c3c(arg0,data_02142b4c,tmp1 + 0x6c);
    tmp1 = func_020513d4(arg0);
    if (tmp1 != 0) {
      return;
    }
  }
  func_02013c3c(arg0,data_02142b64);
}

void Unk044904_Unk_045b74(void)
{
    Unk044904Objs *m = (Unk044904Objs *)Unk044904_Get_data_0215ee98();
    int i;
    for (i = 0; i < 10; i++) {
        u8 *o = (u8 *)m->objs[i];
        if (o != 0 && func_0204a9ec(o) != 0 && ((FIELD(u32, o, 0) >> 16) & 0xff) == 2) {
            func_0204a884(o);
        }
    }
}

void Unk044904_Unk_045bd0(int f)
{
    Unk044904Bits *m = (Unk044904Bits *)Unk044904_Get_data_0215ee98();
    if (m->b3) {
        f = 0;
    }
    if (f != 0) {
        if (func_0205e4f8(24) == 0) {
            func_0205e484(24, 8);
        }
    } else {
        if (func_0205e4f8(m->unk_004c) == 0) {
            func_0205e484(m->unk_004c, 8);
        }
    }
}

int Unk044904_Unk_045d38(void)
{
    Unk044904Bits *m = (Unk044904Bits *)Unk044904_Get_data_0215ee98();
    Unk09d42c_Init_data_02176278();
    func_020458e8();
    func_020525cc(4);
    Unk0a4e48_Unk_0a4e9c(1);
    Unk05ae50_Unk_05afd8(0x4000);
    if (m->b9) {
        func_020a609c(1);
    } else {
        func_020a609c(0);
    }
    return 1;
}

int Unk044904_Unk_0460ac(void)
{
    if (func_020a4f3c() != 0) {
        return 0;
    }
    if (func_02052728() != 0) {
        return 0;
    }
    if (Unk09d060_Unk_09d13c() == 0) {
        return 0;
    }
    if (func_0205e4f8(-1) != 0) {
        return 0;
    }
    Unk044904_Unk_045480();
    return 1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk044904_Unk_045460();
void func_020ae0d8();
int Unk044904_Unk_044fd8();
int Unk0aa118_Clear814();

int Unk044904_Unk_0465c0(u16 *p)
{
    int f;
    if (Unk044904_Unk_045460(1) != 0 && FIELD(u16, Unk044904_Get_data_0215ee98(), 56) == 0) {
        f = 1;
    } else {
        f = 0;
    }
    func_020ae0d8(FIELD(u32, Unk044904_Get_data_0215ee98(), 140), f, 0);
    *p = 2;
    Unk044904_Unk_044fd8();
    Unk0aa118_Clear814();
    return 1;
}
