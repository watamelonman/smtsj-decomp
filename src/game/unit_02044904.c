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

typedef union Unk044904Rec {
    u32 words[3];
    struct {
    u16 id;
    u16 count;
    u16 countFlag;
    u16 total;
    u16 unk_08;
    u16 flag0 : 1;
    u16 otherFlags : 15;
    };
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

Unk044904Rec *Unk044904_Unk_044948(u32 a, u32 b);

typedef struct Unk044904Entry {
    u16 id;
    u8 pad_0002[10];
} Unk044904Entry;

/* 02044904: scans the caller's 12-byte entry table for a matching leading
 * halfword, using the u32 count at +0x60 (ldr/ldrh/cmp plus a *12 mla). Returns
 * the borrowed entry address, or null when no entry matches; never writes. */
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

/* 02044948: returns the borrowed slot matching key, or clears and appends a
 * 12-byte slot when the caller-owned table has room (count at +0x60, limit 8).
 * Returns null when full; a must address a valid table with count <= 8. */
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

/* Shared slot and embedded-entry view. The twelve embedded entries at manager
 * +0x36c use the same field layout and are 0x2e0 bytes apart. */
typedef struct Unk044904Obj {
    u32 unk_0000;               /* bits 16-23 tested as "type" */
    u8 pad_0004[0x1d4];
    u16 unk_01d8;
    u8 pad_01da[2];
    u8 unk_01dc;
    u8 unk_01dd;
    u8 unk_01de;
    u8 pad_01df;
    u16 unk_01e0;
    u16 unk_01e2;
    u16 unk_01e4;
    u8 pad_01e6[2];
    u32 command[2][6];
    u8 pad_0218[0xc8];
} Unk044904Obj;

/* Manager +0x60 script-table view; only the +0x3c field is observed here. */
typedef struct Unk044904ScriptTable {
    u8 pad_0000[0x3c];
    u32 unk_003c;
} Unk044904ScriptTable;

typedef struct Unk044904Mgr {
    u8 pad_0000[0x40];
    u32 pad_0040_0 : 4;
    u32 flag_0040_4 : 1;        /* selects 0 or 3 for the tone state's +0x44 bits 5..12 */
    u32 pad_0040_5 : 4;
    u32 flag_0040_9 : 1;
    u32 flag_0040_10 : 1;
    u32 pad_0040_11 : 2;
    u32 flag_0040_13 : 1;
    u32 pad_0040_14 : 1;
    u32 flag_0040_15 : 1;
    u32 flag_0040_16 : 1;
    u32 flag_0040_17 : 1;
    u32 flag_0040_18 : 1;
    u8 pad_0044[0xc];
    u32 unk_0050;
    u32 unk_0054;
    u32 unk_0058;
    u32 unk_005c;               /* compared with 1 by Unk044904_Unk_045460 */
    Unk044904ScriptTable *unk_0060;
    Unk044904Obj *slots[10];    /* +0x64 */
    u8 pad_008c[0x1f0];
    u32 unk_027c;               /* compared with 4 by func_02046538 */
} Unk044904Mgr;

/* Enemy talk-tone state at manager +0x7804 (Unk044904_Unk_045048). The +0x44
 * word holds single-bit flags followed by an 8-bit field at bits 5..12; the
 * +0x58 index is 15 while no tone set is loaded. */
typedef struct Unk044904Tone {
    u8 pad_0000[0x40];
    u32 owner_0040;
    u32 flag_0044_0 : 1;
    u32 flag_0044_1 : 1;
    u32 flag_0044_2 : 1;
    u32 flag_0044_3 : 2;
    u32 unk_0044_5 : 8;
    u32 pad_0044_13 : 19;
    u32 unk_0048;
    u32 unk_004c;
    u32 unk_0050;
    u8 name_0054;
    u8 pad_0055[3];
    s32 index_0058;
    void *talkTone_005c;
    void *tone_0060;
    u16 unk_0064;
    u8 pad_0066[2];
    u32 unk_0068;
} Unk044904Tone;

#define UNK044904_MGR() ((Unk044904Mgr *)Unk044904_Get_data_0215ee98())
Unk044904Obj *func_02044ec4(u32 key);
int func_02045a30(s32 slot, s32 id, u32 *out);
int func_02046538(u16 *state);
void func_0204a780();
void func_0204a694();
void Unk0bc1a8_Unk_0bc928();
/* Loader record used by the comparator: kind 1 reads +0x34, other kinds +0x4c. */
typedef struct Unk044904RankRecord {
    u8 pad_0000[0x34];
    u32 unk_0034;
    u8 pad_0038[0x14];
    u32 unk_004c;
} Unk044904RankRecord;

/* Twelve-byte id entry; the script list stores eight before its +0x60 count. */
typedef struct Unk044904IdEntry {
    u16 id;
    u8 pad_0002[10];
} Unk044904IdEntry;

typedef struct Unk044904IdList {
    Unk044904IdEntry entries[8];
    u32 count;
} Unk044904IdList;

u8 Unk09974c_GetEntryUnk08(u32 id);
Unk044904RankRecord *Unk09974c_Unk_099d14(u32 id);
Unk044904RankRecord *Unk09974c_Unk_099c60(u32 id);
void func_0204aba8(Unk044904Obj *o);
void func_0204a7b4(Unk044904Obj *o, int value);
int func_0204a870(Unk044904Obj *o);
Unk044904Obj *func_0204acdc(Unk044904Obj *o);
void func_0204af80(Unk044904Obj *o);
void func_0204ae84(Unk044904Obj *o);
void func_0204aecc(Unk044904Obj *o, const char *path, int mode);
void func_0204af70(Unk044904Obj *o, Unk044904Obj *src);
void func_020449c4(void *view, u32 id);
int func_0204a244(Unk044904Obj *o);
int func_020b07c4(int mode);
int func_02052624(void);
void func_0205257c(int mode);
s8 Unk0a50d4_GetUnk06(void);
void Unk0a4e48_Unk_0a4e9c(int value);
void Unk118b04_Unk_118e50(int id, int value);
s32 func_02118dec(u16 id);
void Unk118b04_SetFlag(int id, int value);
void func_0205e590(int value);
void func_020456d8(int mode);
void func_020454f4(int mode);
void func_020455cc(int mode);
int func_02050074(int selector, int index);
void Unk039774_Unk_039b74(int mode);
void func_02045138(void);
void func_020451d8(void);
void func_020457e8(void);
void func_020458e8(void);

/* Comparator input: only the leading id halfword is read. */
typedef struct Unk044904SortRec { u16 id; } Unk044904SortRec;

/* 02044b84: sorts two records by their table rank and, for unranked
 * entries, by the category value reached through the kind-1/kind-2 loaders.
 * Returns negative, zero or positive; both records are borrowed. See DEC-022
 * for the raw rank-table literal and the scoped propagation setting. */
#pragma push
#pragma opt_propagation off
s32 func_02044b84(Unk044904SortRec *a, Unk044904SortRec *b)
{
    u32 kindA = Unk09974c_GetEntryUnk08(a->id);
    u32 kindB = Unk09974c_GetEntryUnk08(b->id);
    u8 *ranks = (u8 *)0x0212cc24;
    u8 rankA = ranks[kindA];
    u8 rankB = ranks[kindB];
    s32 result = rankB - rankA;
    if (result != 0) {
        return result;
    }
    if (rankA == 0) {
        u32 valueA = 0;
        u32 valueB = 0;
        Unk044904RankRecord *rec;
        if (kindA == 1) {
            rec = Unk09974c_Unk_099d14(a->id);
            if (rec != 0) {
                valueA = rec->unk_0034;
            }
        } else {
            rec = Unk09974c_Unk_099c60(a->id);
            if (rec != 0) {
                valueA = rec->unk_004c;
            }
        }
        if (kindB == 1) {
            rec = Unk09974c_Unk_099d14(b->id);
            if (rec != 0) {
                valueB = rec->unk_0034;
            }
        } else {
            rec = Unk09974c_Unk_099c60(b->id);
            if (rec != 0) {
                valueB = rec->unk_004c;
            }
        }
        if (valueB == valueA) {
            result = 0;
        } else if (valueB > valueA) {
            result = 1;
        } else {
            result = -1;
        }
    }
    if (result == 0) {
        result = a->id - b->id;
    }
    return result;
}
#pragma pop

/* 02044fa0: returns the borrowed pointer from manager slot i (word array at
 * +0x64), or null when unregistered, i is negative, or i is 4 or greater
 * (cmp #0 / cmp #4 with signed branches in the original). */
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

/* 0204527c: asks func_0204a780(slot, 11) for each of the ten manager slots whose
 * type byte (bits 16-23 of the slot's +0 word) is nonzero; null slots and slots
 * with type zero are skipped. The manager must be registered, as every caller of
 * that accessor assumes. No result is returned or stored. */
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

/* 02045430: calls func_0204a694 for each non-null manager slot. Walks all ten
 * +0x64 words unconditionally (counter < 10 with a null-check branch), so the
 * callback sees every live slot in index order. */
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

/* 020457a8: returns the first non-null manager slot whose state byte (bits
 * 16-23 of its +0 word) is zero, otherwise null after the ten-slot walk.
 * The returned pointer stays owned by the manager. */
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

/* 020459fc: one-shot start request. Returns without writing when manager bit
 * 10 (word +0x40, lsl #21/lsr #31) is already set; otherwise stores 1 to the
 * +0x50 word and 0 to +0x54. */
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



/* 02044f4c: finds the first of the ten manager slots for which
 * func_02049a84(slot, k) reports a hit. Returns the slot index 0..9, 0 when the
 * manager is not registered, and -1 when no slot matches. Slots are borrowed;
 * nothing is written. */
int Unk044904_Unk_044f4c(u32 k)
{
    Unk044904Mgr *m = UNK044904_MGR();
    int i;
    if (m == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
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
/* 020453dc: resets every active manager slot with func_0204a8cc(slot, 1) --
 * active means the type byte (bits 16-23 of the slot's +0 word) is nonzero --
 * then clears the manager's +0x58 word. Null slots are skipped; the manager
 * must be registered. No value is returned. */
void Unk044904_Unk_0453dc(void)
{
    int i;
    int one = 1;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o != 0 && ((o->unk_0000 >> 16) & 0xff) != 0) {
            func_0204a8cc(o, one);
        }
    }
    UNK044904_MGR()->unk_0058 = 0;
}

/* 02045c7c: reports that slot 26 (0x1a) is not empty, inverting the 0/1 result
 * of Unk0bc1a8_IsSlotEmpty with cmp/moveq/movne. */
int Unk044904_Unk_045c7c(void)
{
    return Unk0bc1a8_IsSlotEmpty(26) == 0;
}

void func_020452c4(void);
int Unk0aa118_SortRemaining();
void Unk044904_Unk_045bd0();
void func_020456d8();
void func_020455cc();
/* 02046468: advances the manager's +0x38 halfword counter, clears bit 16 of
 * the +0x40 flags, writes state 2 through the caller's s16 pointer, and
 * returns 1. The pointer is only written; the manager retains ownership. */
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

/* 02046644: when manager bit 16 (word +0x40, lsl #15/lsr #31) is set and
 * Unk044904_Unk_045460(1) reports a match, returns 2 without side effects.
 * Otherwise runs func_020456d8(0) then func_020455cc(2) and returns 1. */
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
typedef struct Unk044904Items {
    u8 pad_0000[876];
    Unk044904Obj items[12];
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

/* 02045480: unless manager bits 10 or 20 are set, sets bit 20 and brackets
 * calls to func_02122188 for the twelve embedded entries whose type byte is 1
 * with func_02121d84/func_02122200. Requires a registered manager; entries
 * remain owned by it (instruction evidence: +0x36c base, 0x2e0 stride). */
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
        if (((it->items[i].unk_0000 >> 16) & 0xff) == 1) {
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


void func_020450b8(void);
void func_02045138(void);
void Unk044904_Unk_04527c();
int Unk0aa118_Clear814();
int func_020f8098();
/* 02046108: runs the teardown/refresh sequence (Unk_044fd8, Unk0aa118_Clear814,
 * func_02045138, Unk_04527c, func_020450b8), then probes the +0x78e4 view via
 * func_020f8098(view, 0, 0). If the probe reports work, writes state 2 through
 * the caller's u16 pointer. Always returns 2. */
u32 Unk044904_Unk_046108(u16 *state)
{
  int active;
  Unk044904_Unk_044fd8();
  Unk0aa118_Clear814();
  func_02045138();
  Unk044904_Unk_04527c();
  func_020450b8();
  active = func_020f8098(Unk044904_Unk_045080(), 0, 0);
  if (active != 0) {
    *state = 2;
  }
  return 2;
}


int Unk0a5680_Unk_0a5c14(u32 id, u32 arg1, u32 arg2);
/* One entry of the six 12-byte AI-script candidates scanned by Unk_04599c. */
typedef struct Unk044904AiCheck {
    u32 id;
    u32 unk_04;
    u32 unk_08;
} Unk044904AiCheck;

/* 0204599c: scans exactly six 12-byte entries and reports 1 when any entry has
 * a nonzero id and Unk0a5680_Unk_0a5c14(id & 0xffff, entry[1], entry[2]) accepts
 * it; otherwise 0. The entries are borrowed and are not modified. */
u32 Unk044904_Unk_04599c(Unk044904AiCheck *entries)
{
    u32 found = 0;
    int i = 0;
    do {
        if (entries->id != 0 &&
            Unk0a5680_Unk_0a5c14(entries->id & 0xffff, entries->unk_04, entries->unk_08) != 0) {
            found = 1;
        }
        i++;
        entries++;
    } while (i < 6);
    return found;
}

extern const char data_02142b4c[];
extern const char data_02142b64[];
int func_02013c3c(char *dest, const char *format, ...);
int func_020513d4(const char *path);
u8 *func_020a1740(u32 id);
/* 02045898: builds the enemy AI script path in `path`. Looks up `id`; on a hit
 * it formats data_02142b4c ("Data/Enemy/AI/ai_%s.bf") with the name field at
 * lookup+0x6c and returns once func_020513d4 accepts the path. On a miss, or a
 * rejected path, it formats the data_02142b64 fallback (".../ai_scr_test.bf").
 * Both format strings are ASCII in .data at those addresses; `path` belongs to
 * the caller and must hold the formatted name. */
void Unk044904_BuildEnemyAiPath(char *path, u32 id)
{
    u8 *found = func_020a1740(id);
    if (found != 0) {
        func_02013c3c(path, data_02142b4c, found + 0x6c);
        if (func_020513d4(path) != 0) {
            return;
        }
    }
    func_02013c3c(path, data_02142b64);
}

/* 02045b74: releases every manager slot that func_0204a9ec accepts and whose
 * type byte (bits 16-23 of the slot's +0 word) is 2, via func_0204a884(slot).
 * Slots of other types and null slots are left alone; the manager must be
 * registered. No value is returned. */
void Unk044904_Unk_045b74(void)
{
    Unk044904Mgr *m = UNK044904_MGR();
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
        if (o != 0 && func_0204a9ec(o) != 0 && ((o->unk_0000 >> 16) & 0xff) == 2) {
            func_0204a884(o);
        }
    }
}

/* 02045bd0: selects handle 24 when f is nonzero, otherwise the manager's
 * +0x4c word; manager bit 3 forces the latter path. Calls func_0205e484(handle,
 * 8) only when func_0205e4f8(handle) returns zero. Requires a registered
 * manager; handle storage remains owned by its provider. */
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

/* 02045d38: runs the fixed re-init sequence (Unk09d42c_Init_data_02176278,
 * func_020458e8, func_020525cc(4), Unk0a4e48_Unk_0a4e9c(1),
 * Unk05ae50_Unk_05afd8(0x4000)), then calls func_020a609c with 1 or 0 according
 * to manager flag bit 9. Always returns 1; the manager must be registered. */
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

/* 020460ac: gates on four readiness probes. Returns 0 if func_020a4f3c or
 * func_02052728 reports busy, if Unk09d060_Unk_09d13c reports zero, or if
 * func_0205e4f8(-1) reports busy; otherwise runs Unk044904_Unk_045480 and
 * returns 1. Probes are evaluated in that order and short-circuit. */
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

/* 020465c0: passes the manager's +0x8c word and a flag to func_020ae0d8;
 * the flag is 1 only if Unk044904_Unk_045460(1) is nonzero and +0x38 is zero.
 * Writes state 2 through the caller's writable halfword, calls the +0x379c
 * accessor and Unk0aa118_Clear814, then returns 1. Requires a registered manager. */
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

/* 02044ec4: finds the keyed object used for an enemy talk-tone record. Scans
 * the ten manager slot pointers first (skipping null slots), then the twelve
 * embedded 0x2e0-byte entries at manager +0x36c. Returns the first borrowed
 * object accepted by func_02049a84, or null when none match or the manager is
 * not registered. */
Unk044904Obj *func_02044ec4(u32 key)
{
    Unk044904Mgr *m = UNK044904_MGR();
    int i;
    int j;
    if (m == 0) {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
        if (o != 0 && func_02049a84(o, key) != 0) {
            return o;
        }
    }
    for (j = 0; j < 12; j++) {
        Unk044904Obj *o = (Unk044904Obj *)&((Unk044904Items *)m)->items[j];
        if (func_02049a84(o, key) != 0) {
            return o;
        }
    }
    return 0;
}

/* 020450b8: resets the enemy talk-tone state at manager +0x7804. Clears the
 * owner id, the four low flag fields, and the loaded tone-set fields; the
 * 8-bit +0x44 field becomes 3, or 0 when manager flag bit 4 is set. This puts
 * the state back to "no tone set loaded" (index 15, both file pointers null). */
void func_020450b8(void)
{
    Unk044904Tone *state = (Unk044904Tone *)Unk044904_Unk_045048();
    state->owner_0040 = 0;
    state->flag_0044_0 = 0;
    state->flag_0044_1 = 0;
    state->flag_0044_2 = 0;
    state->flag_0044_3 = 0;
    state->unk_0044_5 = UNK044904_MGR()->flag_0040_4 ? 0 : 3;
    state->index_0058 = 15;
    state->talkTone_005c = 0;
    state->tone_0060 = 0;
    state->unk_0064 = 0;
    state->unk_0068 = 0;
}

/* 02045138: shuffles a ten-entry permutation and copies one byte from it to
 * the +0x1dc field of each non-null manager slot, in slot order. See DEC-022
 * for the scoped propagation setting and explicit loop form. */
#pragma push
#pragma opt_propagation off
void func_02045138(void)
{
    u8 order[10];
    u8 i;
    int j;
    int n;
    u8 *end;
    u8 *value;
    i = 0;
    do {
        order[i] = i;
        i++;
    } while (i < 10);
    j = 10;
    end = &order[j - 1];
    j--;
    do {
        u32 k = func_02050074(0, j);
        if (k != (u32)j) {
            u8 tmp = *end;
            *end = order[k];
            order[k] = tmp;
        }
        end--;
        j--;
    } while (j >= 0);
    value = order;
    n = 0;
    do {
        Unk044904Obj *o = UNK044904_MGR()->slots[n];
        if (o != 0) {
            o->unk_01dc = *value;
        }
        value++;
        n++;
    } while (n < 10);
}
#pragma pop

/* 020451d8: resets every active manager slot and every active embedded
 * 0x2e0-byte entry; an embedded entry is also reset when no slot matches it.
 * Type byte is bits 16-23 of the leading word. */
void func_020451d8(void)
{
    Unk044904Mgr *m = UNK044904_MGR();
    Unk044904Items *items = (Unk044904Items *)m;
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
        if (o != 0 && ((o->unk_0000 >> 16) & 0xff) != 0) {
            func_0204aba8(o);
            func_0204a7b4(o, 2);
        }
    }
    {
        int j;
        Unk044904Obj *o = items->items;
        for (j = 0; j < 12; j++) {
            if (((o->unk_0000 >> 16) & 0xff) != 0) {
                if (Unk044904_Unk_044f4c(o->unk_0000) < 0) {
                    func_0204aba8(o);
                    func_0204a7b4(o, 2);
                }
            }
            o++;
        }
    }
}

/* 020457e8: finishes every accepted manager slot, and every accepted embedded
 * 0x2e0-byte entry when manager flag bit 10 is set. Each resource is detached
 * from its context before the callback, then given back to it. */
void func_020457e8(void)
{
    Unk044904Mgr *m = UNK044904_MGR();
    Unk044904Items *items = (Unk044904Items *)m;
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
        if (o != 0 && func_0204a870(o) != 0) {
            Unk044904Obj *resource = func_0204acdc(o);
            func_0204af80(resource);
            func_0204ae84(resource);
        }
    }
    if (m->flag_0040_10) {
        int j;
        Unk044904Obj *o = items->items;
        for (j = 0; j < 12; j++) {
            if (func_0204a870(o) != 0) {
                Unk044904Obj *resource = func_0204acdc(o);
                func_0204af80(resource);
                func_0204ae84(resource);
            }
            o++;
        }
    }
    Unk039774_Unk_039b74(1);
}

/* 020458e8: loads the AI script named by the halfword at +0x1d8 of each
 * manager slot whose type is 2 (or any nonzero type while manager flag bit 10
 * is set), then binds it to the slot's resource. */
void func_020458e8(void)
{
    Unk044904Mgr *m = UNK044904_MGR();
    char path[128];
    int i;
    int mode = 1;
    func_020457e8();
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
        if (o == 0) {
            continue;
        }
        if (UNK044904_MGR()->flag_0040_10) {
            if (((o->unk_0000 >> 16) & 0xff) != 0) {
                goto load_slot;
            }
        } else {
            if (((o->unk_0000 >> 16) & 0xff) == 2) {
                goto load_slot;
            }
        }
        goto next_slot;
load_slot:
        Unk044904_BuildEnemyAiPath(path, o->unk_01d8);
        o = func_0204acdc(o);
        func_0204ae84(o);
        func_0204aecc(o, path, mode);
        func_0204af70(o, o);
next_slot:
        ;
    }
}

/* 02045a30: tests whether manager slot `slot` holds the tagged key
 * 0x10000 | (u16)id. On a match, stores that key through `out` when non-null
 * and returns 1. Returns 0 for a missing or mismatched slot. The original also
 * returns 1 when both arguments are negative (cmplt/movlt/blt), without
 * reading a slot or writing `out`; that corner is preserved. */
int func_02045a30(s32 slot, s32 id, u32 *out)
{
    Unk044904Mgr *m = UNK044904_MGR();
    Unk044904Obj *o;
    u16 value;
    u32 key;
    int found = 0;
    if (slot < 0 && id < 0) {
        found = 1;
    } else {
        value = id;
        key = (u16)(value & 0xffff) | 0x10000;
        o = m->slots[slot];
        if (o != 0 && o->unk_0000 == key) {
            found = 1;
            if (out != 0) {
                *out = key;
            }
        }
    }
    return found;
}

/* 02045fec: refreshes the two script providers when idle and, unless manager
 * flag bit 10 is set or the script table's +0x3c byte field exceeds 1, flags
 * every listed id accepted by func_02118dec. Always submits mode 10. */
/* 02045ca8: reports 1 when mode 1 is already busy; otherwise requires mode 2
 * to be busy, applies Unk_04502c to slots of type 2 whose func_0204a244 value
 * is 7, and reports 1. Mode 2 idle is the only zero path. */
int func_02045ca8(void)
{
    Unk044904Mgr *m;
    int i;
    if (func_020b07c4(1) != 0) {
        return 1;
    }
    if (func_020b07c4(2) != 0) {
        m = UNK044904_MGR();
        for (i = 0; i < 10; i++) {
            Unk044904Obj *o = m->slots[i];
            if (o != 0 && ((o->unk_0000 >> 16) & 0xff) == 2 && func_0204a244(o) == 7) {
                func_020449c4((void *)Unk044904_Unk_04502c(), o->unk_0000);
            }
        }
        return 1;
    }
    return 0;
}

int func_02045fec(void)
{
    Unk044904Mgr *m;
    if (func_02052624() == 0) {
        func_0205257c(3);
    }
    if (Unk0a50d4_GetUnk06() == 0) {
        Unk0a4e48_Unk_0a4e9c(2);
    }
    m = UNK044904_MGR();
    if (!m->flag_0040_10) {
        u32 field = (m->unk_0060->unk_003c << 22) >> 24;
        if (field <= 1) {
            Unk044904IdList *list;
            u32 i;
            Unk118b04_Unk_118e50(1, 1);
            list = (Unk044904IdList *)Unk044904_Unk_04502c();
            for (i = 0; i < list->count; i++) {
                s32 result = func_02118dec(list->entries[i].id);
                if (result >= 0) {
                    Unk118b04_SetFlag(result, 1);
                }
            }
        }
    }
    func_0205e590(10);
    return 1;
}

/* 0204649c: advances the battle script state word. Flag bit 16 with a
 * matching +0x5c word, or flag bit 10, writes state 2 and returns; otherwise
 * clears a pending +0x50/+0x54 pair and sends the mode-1 request. */
int func_0204649c(u16 *state)
{
    Unk044904Mgr *m = UNK044904_MGR();
    if (m->flag_0040_16) {
        if (Unk044904_Unk_045460(2) != 0) {
            *state = 2;
            return 2;
        }
    }
    if (m->flag_0040_10) {
        func_020456d8(1);
        func_020455cc(1);
        *state = 2;
        return 2;
    }
    if (m->unk_0050 != 0 && m->unk_0054 != 0) {
        m->unk_0050 = 0;
        m->unk_0054 = 0;
    }
    if (Unk044904_Unk_0459ec() == 0) {
        Unk044904_Unk_045c58(1);
    }
    return 1;
}

/* 02046538: advances the enemy talk-tone script. Returns 0 while Unk_045c7c
 * reports pending work. If the tone state's owner type byte (bits 16-23 of
 * +0x40) is 2, writes state 3. Otherwise, when Unk_0459ec reports a loaded
 * request, stops the current tone with Unk_045bd0(0) and advances it with
 * func_020454f4(1); writes state 4 when the manager's +0x27c word is 4, else
 * runs func_020455cc(1) and ScanVisor_Unk_0a2a1c and writes state 2. Returns 1
 * on every path after the pending check. */
int func_02046538(u16 *state)
{
    Unk044904Tone *tone;
    if (Unk044904_Unk_045c7c() != 0) {
        return 0;
    }
    tone = (Unk044904Tone *)Unk044904_Unk_045048();
    if (((tone->owner_0040 >> 16) & 0xff) == 2) {
        *state = 3;
    } else {
        if (Unk044904_Unk_0459ec() != 0) {
            Unk044904_Unk_045bd0(0);
            func_020454f4(1);
        }
        if (UNK044904_MGR()->unk_027c == 4) {
            *state = 4;
        } else {
            func_020455cc(1);
            ScanVisor_Unk_0a2a1c();
            *state = 2;
        }
    }
    return 1;
}

int func_0204a968(Unk044904Obj *o, int mode);
u32 func_020b0874(u32 id, int value);
u32 func_020b1144(int kind);
u32 func_020b0d48(int mode, u32 id);
void func_020aa188(int list, u32 *command);
int func_0204a7f4(Unk044904Obj *o, int mode);
void func_0204ac4c(Unk044904Obj *o);
void func_02049a98(Unk044904Obj *o);
void func_0204aca4(Unk044904Obj *o);
void Unk0e8228_Unk_0e8260(int slot);

/* 020456d8: submits kind-8 commands for the selected slot type. Mode zero
 * selects type 2; other modes require manager flag 10 and select type 1.
 * Evidence: +0x1e8 command stores and the aa188/a780 submission pair. */
void func_020456d8(int mode)
{
    int i;
    if (mode && !UNK044904_MGR()->flag_0040_10) return;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (o == 0) continue;
        if (mode) {
            if ((o->unk_0000 >> 16 & 255) == 1) goto submit456;
        } else {
            if ((o->unk_0000 >> 16 & 255) == 2) goto submit456;
        }
        goto next456;
submit456:
        if (func_0204a968(o, 0)) continue;
        o->command[0][0] = o->unk_0000;
        o->command[0][2] = 8;
        o->command[0][5] = func_020b0874(o->unk_0000, 100) | 0x50000000;
        func_020aa188(Unk044904_Unk_044fd8(), o->command[0]);
        func_0204a780(o, 4);
next456:;
    }
}

/* 020454f4: submits kind-1 commands for active slots matching the optional
 * type filter (zero accepts either type). The provider reverses types 1/2. */
void func_020454f4(int mode)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        u32 kind;
        int target;
        if (!o) continue;
        kind = o->unk_0000 >> 16 & 255;
        if (!kind) continue;
        if (mode && mode != kind) continue;
        if (func_0204a968(o, 0)) continue;
        o->command[0][0] = o->unk_0000;
        kind = o->unk_0000 >> 16 & 255;
        if (kind == 1) target = 2;
        else if (kind == 2) target = 1;
        else target = 0;
        o->command[0][1] = func_020b1144(target);
        o->command[0][2] = 1;
        o->command[0][5] = func_020b0874(o->unk_0000, 100) | 0x50000000;
        func_020aa188(Unk044904_Unk_044fd8(), o->command[0]);
        func_0204a780(o, 4);
    }
}

/* 020455cc: submits kind-10 commands for slot states 5 and 11, using the
 * caller's mode for state 5 and zero for state 11; mode also filters types. */
void func_020455cc(int mode)
{
    int i;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        u32 kind;
        int state;
        if (!o) continue;
        kind = o->unk_0000 >> 16 & 255;
        if (!kind) continue;
        if (mode && mode != kind) continue;
        state = func_0204a244(o);
        if (state == 5) {
            o->command[0][0] = o->unk_0000;
            o->command[0][1] = func_020b0d48(mode, o->unk_0000);
            o->command[0][2] = 10;
            o->command[0][5] = func_020b0874(o->unk_0000, 100) | 0x50000000;
            func_020aa188(Unk044904_Unk_044fd8(), o->command[0]);
            func_0204a780(o, 4);
        } else if (state == 11) {
            o->command[0][0] = o->unk_0000;
            o->command[0][1] = func_020b0d48(0, o->unk_0000);
            o->command[0][2] = 10;
            o->command[0][5] = func_020b0874(o->unk_0000, 100) | 0x50000000;
            func_020aa188(Unk044904_Unk_044fd8(), o->command[0]);
            func_0204a780(o, 4);
        }
    }
}

/* 020452c4: refreshes active slots' two 24-byte commands. Kind 2 requests
 * state zero; kind 6 with argument 247 marks manager +0x58. */
void func_020452c4(void)
{
    int i, j;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = UNK044904_MGR()->slots[i];
        if (!o || !(o->unk_0000 >> 16 & 255)) continue;
        func_0204a7b4(o, 11);
        if (!func_0204a7f4(o, 4)) {
            for (j = 0; j < 2; j++) o->command[j][2] = 0;
        }
        func_0204ac4c(o);
        func_02049a98(o);
        int k;
        Unk044904Obj *cursor = o;
        for (k = 0; k < 2; k++, cursor = (Unk044904Obj *)((u8 *)cursor + 24)) {
            switch (cursor->command[0][2]) {
            case 2: func_0204a780(o, 0); break;
            case 6:
                if (cursor->command[0][3] == 247) UNK044904_MGR()->unk_0058 = 1;
                break;
            }
        }
    }
}

/* 02045a9c: removes the resolved object from its registered slot, or replaces
 * the requested slot with a type-1 id when the resolver fails. Slot is 0..9. */
void func_02045a9c(u32 id, int slot, int value)
{
    int found = func_02045a30(slot, value, &id);
    Unk044904Mgr *m = UNK044904_MGR();
    if (found) {
        slot = (int)func_02044ec4(id);
        func_0204aca4((Unk044904Obj *)slot);
        for (found = 0; found < 10; found++) {
            if (m->slots[found] == (Unk044904Obj *)slot) {
                Unk0e8228_Unk_0e8260(found);
                m->slots[found] = 0;
                return;
            }
        }
    } else {
        if (m->slots[slot]) {
            func_0204aca4(m->slots[slot]);
            Unk0e8228_Unk_0e8260(slot);
        }
        u16 shortValue = value;
        m->slots[slot] = func_02044ec4((u16)(shortValue & 0xffff) | 0x10000);
    }
}

/* Borrowed result accumulator: eight keyed records precede totals. */
typedef struct Unk044904Results {
    Unk044904Rec entries[8];
    u32 count;
    u32 totalA;
    u32 totalB;
    u16 maximum;
    u16 countAll;
} Unk044904Results;
/* Provider statistics observed at +0x5c and +0x60. */
typedef struct Unk044904Drop {
    u16 id;
    u16 chance;
    u16 flag;
} Unk044904Drop;
typedef struct Unk044904Stats {
    u8 pad[0x48];
    Unk044904Drop drops[3];
    u8 pad_005a[2];
    u32 totalA;
    u32 totalB;
} Unk044904Stats;
int func_02049d80(Unk044904Obj *o, int selector);
int Unk02e000_GetRecordUnk1f(u16 id);
void Unk02e000_SetRecordUnk1f_2(u16 id, int value);
int Unk02e000_GetRecordUnk1c(u16 id);
void Unk02e000_SetRecordUnk1c(u16 id, int value);

/* The original capacity helper returns a normalized Boolean. */
static inline int Unk044904_HasRoom(Unk044904Results *v)
{
    if (v->count < 8) return 1;
    return 0;
}

/* 020449c4: accumulates type-2 slot statistics into the caller's eight-entry
 * result table, saturates its counters, and updates the persistent record.
 * Evidence: keyed lookup plus provider totals at +0x5c/+0x60. */
#pragma push
#pragma opt_propagation off
void func_020449c4(void *view, u32 id)
{
    Unk044904Results *v = view;
    Unk044904Obj *o;
    Unk044904Rec *r;
    Unk044904Stats *stats;
    int count, maximum, flag, value;
    u32 sum, contribution;
    if (!v) return;
    if ((id >> 16 & 255) != 2) return;
    o = func_02044ec4(id);
    if (!o) return;
    if (Unk044904_HasRoom(v) <= 0U) return;
    r = Unk044904_Unk_044948((u32)v, o->unk_01d8);
    if (!r) return;
    if (r->count < 65535) r->count++;
    if (UNK044904_MGR()->unk_0058) {
        if (r->countFlag < 65535) r->countFlag++;
    }
    r->total += o->unk_01e4;
    stats = (Unk044904Stats *)func_020a1740(o->unk_01d8);
    count = v->countAll + 1;
    if (count >= 65535) v->countAll = 65535;
    else if (count <= 0) v->countAll = 0;
    else v->countAll = count;
    contribution = stats->totalA;
    sum = v->totalA + contribution;
    if (sum >= 0xffffffff) v->totalA = 0xffffffff;
    else if (sum <= 0) v->totalA = 0;
    else v->totalA = sum;
    contribution = stats->totalB;
    sum = v->totalB + contribution;
    if (sum >= 0xffffffff) v->totalB = 0xffffffff;
    else if (sum <= 0) v->totalB = 0;
    else v->totalB = sum;
    maximum = func_02049d80(o, 2);
    if (v->maximum < maximum) v->maximum = maximum;
    flag = Unk02e000_GetRecordUnk1f(o->unk_01d8);
    if (!flag) {
        r->flag0 = 1;
    }
    Unk02e000_SetRecordUnk1f_2(o->unk_01d8, flag + 1);
    value = Unk02e000_GetRecordUnk1c(o->unk_01d8) - 5;
    Unk02e000_SetRecordUnk1c(o->unk_01d8, value < 0 ? 0 : value);
}

#pragma pop

int func_0204a0e8(Unk044904Obj *o, int selector);
int Unk02e000_GetRecordUnk1e(u16 id);
void func_0204a720(Unk044904Obj *o, s8 *request);
int func_020b1488(u32 *out);
int func_02049350(int mode);
void func_0204f158(int a, int b, int c, int d);
void func_0204f108(int a, int b, int c, int d);
void func_0204f0d4(void);
void Unk0aa118_Unk_0ab34c(void);
int Unk0caea8_GetInRange(int id);

/* 02045d90: resolves the post-probe mode, applies slot requests when a type-1
 * slot satisfies selector 401, and queues provider messages. Evidence: the
 * b1488 mode dispatch and +0x5c state stores. Returns zero only while busy. */
int func_02045d90(void)
{
    Unk044904Mgr *m;
    int found, requested, i, mode, message;
    s8 request[6];
    u32 out;
    if (func_020a4f3c()) return 0;
    if (func_02052728()) return 0;
    m = UNK044904_MGR();
    found = 0;
    requested = 0;
    for (i = 0; i < 10; i++) {
        Unk044904Obj *o = m->slots[i];
        if (o && (o->unk_0000 >> 16 & 255) == 1) {
            if (func_0204a0e8(o, 401)) { found = 1; break; }
        }
    }
    if (found) {
        func_02008848(request, 0, 6);
        request[0] = -1;
        request[1] = -1;
        request[2] = -1;
        int j;
        for (j = 0; j < 10; j++) {
            Unk044904Obj *o = m->slots[j];
            if (o && (o->unk_0000 >> 16 & 255) == 2) {
                if (Unk02e000_GetRecordUnk1e(o->unk_01d8) >= 100) {
                    func_0204a720(o, request);
                    requested = 1;
                }
            }
        }
    }
    out = 0;
    mode = func_020b1488(&out);
    message = 0;
    switch (mode) {
    case 1:
        m->unk_005c = 1;
        message = func_02049350(1);
        break;
    case 2:
        m->unk_005c = 2;
        func_0204f158(0, 32, 2, 0);
        break;
    case 3:
        func_0204f158(0, 32, 2, 0);
        message = func_02049350(3);
        break;
    }
    if (mode == 2) Unk044904_Unk_045bd0(0);
    else if (m->flag_0040_17) Unk044904_Unk_045bd0(1);
    else Unk044904_Unk_045bd0(0);
    if (!m->flag_0040_9) Unk0aa118_Unk_0ab34c();
    if (message) {
        func_0204f0d4();
        func_0204f108(0, 32, message, 0);
    }
    if (requested) {
        int extra = Unk0caea8_GetInRange(401);
        if (extra) {
            func_0204f0d4();
            func_0204f108(0, 32, extra, 0);
        }
    }
    return 1;
}

/* Twelve-byte result records are copied intact to the six-record output. */
typedef struct Unk044904Loot {
    Unk044904Rec entries[6];
    u32 any;
} Unk044904Loot;
int Unk0e651c_Unk_0e666c(int flag);
int Unk09974c_Unk_0998f0(u16 id);
int Unk0986ac_Unk_098978(int id);
int Unk0986ac_Thunk_02098714(int value);
void func_02013c68(void *base, u32 count, u32 stride,
                   s32 (*compare)(Unk044904SortRec *, Unk044904SortRec *));

/* 02044c48: rolls three provider drops per counted result, coalesces matching
 * ids, sorts by 02044b84, and copies at most six records. Flag 1811 gates all
 * drops; provider flag 170 adds five to the chance. Caller owns both tables. */
void func_02044c48(Unk044904Loot *out, Unk044904Results *results)
{
    Unk044904Rec drops[24];
    u32 count = 0, i, j, k;
    int times, n;
    func_02008848(drops, 0, sizeof(drops));
    func_02008848(out, 0, sizeof(*out));
    if (!Unk0e651c_Unk_0e666c(1811)) return;
    for (i = 0; i < results->count; i++) {
        Unk044904Stats *stats = (Unk044904Stats *)func_020a1740(results->entries[i].id);
        times = results->entries[i].count;
        for (n = 0; n < times; n++) {
            for (j = 0; j < 3; j++) {
                Unk044904Drop *drop = &stats->drops[j];
                u32 chance;
                int index;
                if (!drop->id) continue;
                if (Unk09974c_Unk_0998f0(drop->id)) continue;
                if (drop->flag && !Unk0e651c_Unk_0e666c(drop->flag)) continue;
                chance = drop->chance;
                if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(170))) chance += 5;
                if ((u32)func_02050074(0, 99) >= chance) continue;
                index = -1;
                for (k = 0; k < count; k++) {
                    if (drops[k].id == drop->id) { index = k; break; }
                }
                if (index < 0) index = count++;
                drops[index].id = drop->id;
                drops[index].count++;
            }
        }
    }
    func_02013c68(drops, count, 12, func_02044b84);
    int finalIndex;
    for (finalIndex = 0; finalIndex < count; finalIndex++) {
        if (finalIndex >= 6) return;
        out->entries[finalIndex] = drops[finalIndex];
        if (out->entries[finalIndex].count) out->any = 1;
    }
}

/* Borrowed provider prefixes: category/tier bytes and eligibility bits are
 * established by the loads at 02046258 and 02046270. */
typedef struct Unk044904Category {
    u8 pad_0000[4];
    u8 category;
    u8 tier;
} Unk044904Category;
typedef struct Unk044904Eligibility {
    u8 pad_0000[0x16];
    u16 pad_0016_0 : 3;
    u16 flag_0016_3 : 1;
    u16 flag_0016_4 : 1;
    u16 pad_0016_5 : 11;
} Unk044904Eligibility;
int func_020bc1a8(void);
int func_020bc200(u32 id);
int Unk02ee5c_GetTierFromField70(void);
Unk044904Category *func_020a1428(u32 id);
int Unk0afc28_CountById(int id);
int func_02049ce8(Unk044904Obj *o, int selector);

/* 02046148: selects a type-2 slot owner and tone mode 1 or 2, writing script
 * state 3 on selection (otherwise 2). Evidence: ten +0x64 slots, provider
 * category/tier tests and random thresholds. Requires a registered manager;
 * state is a writable halfword. Provider storage remains borrowed. */
int func_02046148(u16 *state)
{
    Unk044904Mgr *m = UNK044904_MGR();
    Unk044904Tone *tone = (Unk044904Tone *)Unk044904_Unk_045048();

    *state = 2;
    if (m->flag_0040_16) {
        if (m->flag_0040_13) {
            for (int i = 0; i < 10; i++) {
                Unk044904Obj *o = m->slots[i];
                if (o && (o->unk_0000 >> 16 & 255) == 2) {
                    tone->owner_0040 = o->unk_0000;
                    break;
                }
            }
            tone->unk_0044_5 = 1;
            *state = 3;
            return 1;
        }
        if (func_020bc1a8()) {
            int tier = Unk02ee5c_GetTierFromField70();
            for (int i = 0; i < 10; i++) {
                Unk044904Obj *o = m->slots[i];
                if (!o || (o->unk_0000 >> 16 & 255) != 2 || !o->unk_01d8 || !func_020bc200(o->unk_0000)) continue;
                Unk044904Category *category = func_020a1428(o->unk_01d8);
                if (category->tier == tier) continue;
                if (((Unk044904Eligibility *)func_020a1740(o->unk_01d8))->flag_0016_3) continue;
                u32 chance;
                if (category->category == 3) {
                    chance = 3;
                    if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(197))) chance += 3;
                } else {
                    chance = 5;
                    if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(197))) chance += 5;
                }
                if ((u32)func_02050074(0, 99) < chance) {
                    tone->owner_0040 = o->unk_0000;
                    tone->unk_0044_5 = 1;
                    *state = 3;
                    break;
                }
            }
        }
    } else if (func_020bc1a8() && Unk0afc28_CountById(2) == 1) {
        for (int i = 0; i < 10; i++) {
            Unk044904Obj *o = m->slots[i];
            if (!o || (o->unk_0000 >> 16 & 255) != 2 || !o->unk_01d8 || !func_020bc200(o->unk_0000)) continue;
            if (func_02049ce8(o, 0) >= 512) continue;
            if (((Unk044904Eligibility *)func_020a1740(o->unk_01d8))->flag_0016_4) continue;
            u32 chance;
            if (func_020a1428(o->unk_01d8)->category == 3) {
                chance = 3;
                if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(198))) chance += 10;
            } else {
                chance = 5;
                if (Unk0986ac_Thunk_02098714(Unk0986ac_Unk_098978(198))) chance += 20;
            }
            if ((u32)func_02050074(0, 99) < chance) {
                tone->owner_0040 = o->unk_0000;
                tone->unk_0044_5 = 2;
                *state = 3;
                break;
            }
        }
    }
    return 1;
}
