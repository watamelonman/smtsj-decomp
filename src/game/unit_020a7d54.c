/*
 * src/game/unit_020a7d54.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;

/* One 40-byte entry in the 32-slot table starting at +0x48 of the work area.
 * Offsets come from the loads/stores in the entry routines below; the words whose
 * purpose is unknown stay neutral. */
typedef struct Unk0a7d54Entry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0c;
    s8 unk_0d;
    u8 pad_0e[2];
    s32 unk_10;
    u32 unk_14;
    u32 unk_18;
    s32 unk_1c;
    u32 unk_20;
    u32 pad_24;
} Unk0a7d54Entry;

/* Borrowed work-area view: 020a7d54/020a84a4/020a8534 walk 32 entries from +0x48.
 * The state machine at 020a9218 uses the eight slot words at +0x24, the +0x1c
 * counter, the +0x20 state word and the +0x44 flag; 020a7d80 additionally reads
 * the two words at +0x14/+0x18. Entry fields remain the 40-byte view above. */
typedef struct Unk0a7d54Work {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    s32 unk_1c;
    u32 unk_20;
    u32 slot[8];
    u32 unk_44;
    Unk0a7d54Entry entries[32];
} Unk0a7d54Work;

void Unk0a7d54_Unk_0a7e8c(Unk0a7d54Entry *entry);
Unk0a7d54Entry *Unk0a7d54_FindByKey(Unk0a7d54Work *work, u32 key);

/* Borrowed field view; offsets follow loads/stores in 020a7eb8 and 020a9158.
 * Field meanings and the bytes between them remain unknown. */
typedef struct Unk0a7d54Fields {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0c;
    u8 unk_0d;
    u8 pad_0e[0x0e];
    u32 unk_1c;
    u32 unk_20;
} Unk0a7d54Fields;

/* The STR at 020a9164 establishes the name: write field +8; obj must be valid. */
void Unk0a7d54_SetUnkField8(Unk0a7d54Fields *obj, u32 value)
{
    obj->unk_08 = value;
}

/* Set field +4 to one (020a9158); obj is a borrowed, non-null field view. */
void Unk0a7d54_Unk_0a9158(Unk0a7d54Fields *obj)
{
    obj->unk_04 = 1;
}

/* Mark byte +13 and store value at +28, as shown by STRB/STR at 020a7eb8.
 * The returned lookup entry must be non-null. */
void Unk0a7d54_Unk_0a7eb8(Unk0a7d54Fields *obj, u32 value)
{
    obj->unk_0d = 1;
    obj->unk_1c = value;
}

/* Read field +4 from a borrowed object, or return zero for null (020a8648). */
u32 Unk0a7d54_Unk_0a8648(Unk0a7d54Fields *obj)
{
    return obj == 0 ? 0 : obj->unk_04;
}

/* Test field +32 of a non-null object; 020a9204 normalizes the result to 0/1. */
int Unk0a7d54_Unk_0a9204(Unk0a7d54Fields *obj)
{
    return obj->unk_20 != 0;
}

/* Forward the owner/key to FindByKey and clean up a found entry.
 * Calls and argument flow at 020a8594 establish this contract. */
void Unk0a7d54_Unk_0a8594(Unk0a7d54Work *owner, u32 key)
{
    Unk0a7d54Entry *entry = Unk0a7d54_FindByKey(owner, key);
    if (entry == 0) {
        return;
    }
    Unk0a7d54_Unk_0a7e8c(entry);
}

/* Forward owner/key to FindByKey, then mark a found entry with value.
 * 020a7ec8 saves the third argument across the lookup; missing keys do nothing. */
void Unk0a7d54_Unk_0a7ec8(Unk0a7d54Work *owner, u32 key, u32 value)
{
    Unk0a7d54Entry *entry = Unk0a7d54_FindByKey(owner, key);
    if (entry == 0) {
        return;
    }
    Unk0a7d54_Unk_0a7eb8((Unk0a7d54Fields *)entry, value);
}

/* Clear one entry's lifecycle fields in the store order seen at 020a7e64:
 * words +4 and +0, byte +12, words +20/+24/+28/+32, then word +8. Field +16 is
 * deliberately not cleared. */
void Unk0a7d54_Unk_0a7e64(Unk0a7d54Entry *entry)
{
    entry->unk_04 = 0;
    entry->unk_00 = 0;
    entry->unk_0c = 0;
    entry->unk_14 = 0;
    entry->unk_18 = 0;
    entry->unk_1c = 0;
    entry->unk_20 = 0;
    entry->unk_08 = 0;
}

/* Return the first of the 32 entry slots whose word +0 is zero, or null when all
 * are occupied. 020a7d54 starts at work+0x48 and advances 0x28 per slot. */
Unk0a7d54Entry *Unk0a7d54_Unk_0a7d54(Unk0a7d54Work *work)
{
    Unk0a7d54Entry *entry = work->entries;
    int i = 0;
    do {
        if (entry->unk_00 == 0) {
            return entry;
        }
        i++;
        entry++;
    } while (i < 32);
    return 0;
}

/* Set state word +8 to 4 only when it is currently 3 (predicate at 020a8628) and
 * clear word +16. Null entries are ignored; the stores are at 020a8b44. */
int Unk0a7d54_IsField8Is3(Unk0a7d54Entry *entry);
void Unk0a7d54_Unk_0a8b44(Unk0a7d54Entry *entry)
{
    if (entry == 0) {
        return;
    }
    if (Unk0a7d54_IsField8Is3(entry) == 0) {
        return;
    }
    entry->unk_08 = 4;
    entry->unk_10 = 0;
}


int Unk0a0ce4_Unk_0a0dd8(u32 value);
int Unk0a0ce4_Unk_0a0da4(u32 value);
void Unk0a7d54_Unk_0a8b70(Unk0a7d54Work *work);
/* Call Unk0a0ce4_Unk_0a0dd8(0x1d); when it returns nonzero, call
 * Unk0a0ce4_Unk_0a0da4(0x52), then forward the work object to 020a8b70. The
 * MOV #29 / conditional MOV #82 / BL sequence at 020a8c40 establishes both
 * constants and the forwarding. */
void Unk0a7d54_Unk_0a8c40(Unk0a7d54Work *work)
{
  int tmp1;
  tmp1 = Unk0a0ce4_Unk_0a0dd8(0x1d);
  if (tmp1 != 0) {
    Unk0a0ce4_Unk_0a0da4(0x52);
  }
  Unk0a7d54_Unk_0a8b70(work);
  return;
}

int func_020a7ee8();
/* Walk all 32 entry slots from work+0x48 and forward each occupied entry to
 * 020a7ee8. The LDR/CMP at the loop head, the 0x28 pointer step and the
 * `cmp #0x20` bound at 020a84cc establish the visit condition and stride. */
void Unk0a7d54_Unk_0a84cc(Unk0a7d54Work *work)
{
  int i;
  Unk0a7d54Entry *entry;
  entry = work->entries;
  i = 0;
  do {
    if (entry->unk_00 != 0) {
      func_020a7ee8(entry);
    }
    i = i + 1;
    entry = entry + 1;
  } while (i < 0x20);
  return;
}

void func_020a82f0(Unk0a7d54Entry *entry);
/* Same 32-slot visit as 020a84cc, but forwards each occupied entry to
 * 020a82f0 instead. Kept separate because the original emits two loops. */
void Unk0a7d54_Unk_0a8500(Unk0a7d54Work *work)
{
  int i;
  Unk0a7d54Entry *entry;
  entry = work->entries;
  i = 0;
  do {
    if (entry->unk_00 != 0) {
      func_020a82f0(entry);
    }
    i = i + 1;
    entry = entry + 1;
  } while (i < 0x20);
  return;
}


int func_0205c368();
int func_0205ddb4();
void Unk0a7d54_Unk_0a8534(Unk0a7d54Work *work);
void Unk0a7d54_Unk_0a93b8(Unk0a7d54Work *work);
/* Tear down a work area: drain the +0x1c count, release all entries, clear the
 * +8/+4 state words, release the +0x14 and +0x18 resources when present, and
 * return. The load/call/zero sequence at 020a8bac is the evidence; a null work
 * pointer returns immediately. */
void Unk0a7d54_Unk_0a8bac(Unk0a7d54Work *work)
{
    if (work == 0) {
        return;
    }
    Unk0a7d54_Unk_0a93b8(work);
    Unk0a7d54_Unk_0a8534(work);
    work->unk_08 = 0;
    work->unk_04 = 0;
    if (work->unk_14 != 0) {
        func_0205ddb4();
        work->unk_14 = 0;
    }
    if (work->unk_18 == 0) {
        return;
    }
    func_0205c368();
    work->unk_18 = 0;
}


/* Map a state selector 6..10 to the handle ids 0x1a, 0x1b, 0x1c, 0x1e and
 * 0x1f; selectors 0..5 and values above 10 return zero. The `addls pc` table
 * and the five MOV immediates at 020a916c are the evidence. */
u32 Unk0a7d54_Unk_0a916c(u32 selector)
{
    switch (selector) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        return 0x1a;
    case 7:
        return 0x1b;
    case 8:
        return 0x1c;
    case 9:
        return 0x1e;
    case 10:
        return 0x1f;
    }
    return 0;
}

void func_02061424(u32 handle);
/* Release the entry: 020a7e8c passes word +8 to 02061424 when non-zero, clears
 * +8, then resets the remaining fields through 020a7e64. */
void Unk0a7d54_Unk_0a7e8c(Unk0a7d54Entry *entry)
{
    if (entry->unk_08 != 0) {
        func_02061424(entry->unk_08);
        entry->unk_08 = 0;
    }
    Unk0a7d54_Unk_0a7e64(entry);
}

/* Walk all 32 entry slots starting at work+0x48 and release each one with
 * 020a7e8c. The loop bound and 0x28 stride come from 020a84a4. */
void Unk0a7d54_Unk_0a84a4(Unk0a7d54Work *work)
{
    int i;
    Unk0a7d54Entry *entry = work->entries;
    for (i = 0; i < 32; i++, entry++) {
        Unk0a7d54_Unk_0a7e8c(entry);
    }
}

/* Same 32-slot release walk as 020a84a4, emitted separately at 020a8534. */
void Unk0a7d54_Unk_0a8534(Unk0a7d54Work *work)
{
    int i;
    Unk0a7d54Entry *entry = work->entries;
    for (i = 0; i < 32; i++, entry++) {
        Unk0a7d54_Unk_0a7e8c(entry);
    }
}

/* Find the first occupied entry whose byte +12 equals key. 020a855c (56 B)
 * starts the scan at work+0x48, steps 0x28 per slot and compares key against
 * an LDRB; returns null when none of the 32 entries matches. */
Unk0a7d54Entry *Unk0a7d54_FindByKey(Unk0a7d54Work *work, u32 key)
{
    int j;
    Unk0a7d54Entry *e = work->entries;
    for (j = 0; j < 32; j++, e++) {
        if (e->unk_00 != 0 && e->unk_0c == key) {
            return e;
        }
    }
    return 0;
}

/* The null check and LDR +8 at 020a8608 support this field-only name.
 * Null is false; otherwise return a normalized predicate on the borrowed view. */
int Unk0a7d54_HasField8(Unk0a7d54Fields *p)
{
    if (p == 0) {
        return 0;
    }
    return p->unk_08 != 0;
}

/* Null-safe predicate on entry word +8: true only when it equals 3.
 * The loads and MOVcc sequence at 020a8628 establish the comparison. */
int Unk0a7d54_IsField8Is3(Unk0a7d54Entry *entry)
{
    if (entry == 0) {
        return 0;
    }
    return entry->unk_08 == 3;
}

void func_02057e18();
void func_02057ddc();
void Unk0a7d54_Unk_0a8500(Unk0a7d54Work *work);
void Unk0a7d54_Unk_0a8bac(Unk0a7d54Work *work);
void func_0205bb68(s32 value);
typedef struct Unk0a7d54Slots {
    u8 pad_00[0x20];
    u32 flag;
    u32 slot[8];
} Unk0a7d54Slots;
/* Call 02057e18(31) and 02057ddc(-1), then hand the work object to 020a8500,
 * but only when the work pointer and its state word +8 are both non-null. The
 * LDRNE state load and POPEQ at 020a8ad0 are the evidence for the guard. */
void Unk0a7d54_Unk_0a8ad0(Unk0a7d54Work *work)
{
    if (work == 0 || work->unk_08 == 0) {
        return;
    }
    func_02057e18(31);
    func_02057ddc(-1);
    Unk0a7d54_Unk_0a8500(work);
}

/* Start a work area in state 1 (or state 11 when it is already stopping):
 * null and non-initial states are ignored, +4/+0x10 are cleared, word +0 takes
 * the caller value, byte +12 becomes selector+1, and the +0x44 flag is raised
 * only for the state-11 transition. The compare/branch/store sequence at
 * 020a8b00 is the evidence. */
void Unk0a7d54_Unk_0a8b00(Unk0a7d54Work *work, u32 value, s32 selector)
{
    if (work == 0) {
        return;
    }
    if (work->unk_08 != 0 && work->unk_08 != 11) {
        return;
    }
    work->unk_04 = 0;
    work->unk_00 = value;
    work->unk_0c = selector + 1;
    work->unk_10 = 0;
    if (work->unk_08 == 11) {
        work->unk_44 = 1;
    } else {
        work->unk_08 = 1;
    }
}

/* Clear work word +0x44 (the state checked by 020a9204 is word +0x20), then
 * either mark state word +8 as 11 or continue through 020a8bac. A null work
 * pointer or a zero state word +8 returns immediately; the LDRNE/CMPNE guard
 * and the STR at +0x44 in 020a8b70 establish this. */
void Unk0a7d54_Unk_0a8b70(Unk0a7d54Work *work)
{
    if (work == 0 || work->unk_08 == 0) {
        return;
    }
    work->unk_44 = 0;
    if (Unk0a7d54_Unk_0a9204((Unk0a7d54Fields *)work) != 0) {
        work->unk_08 = 11;
        return;
    }
    Unk0a7d54_Unk_0a8bac(work);
}

/* Return false when the work has the +0x20 predicate or its +8 state is one of
 * the stopping states 9, 10 or 11; otherwise return true. The null-free
 * predicate call and the CMPNE chain at 020a8c04 are the evidence. */
int Unk0a7d54_Unk_0a8c04(Unk0a7d54Work *work)
{
    u32 v;
    if (Unk0a7d54_Unk_0a9204((Unk0a7d54Fields *)work) == 1) {
        return 0;
    }
    v = work->unk_08;
    switch (v) {
    case 9:
    case 10:
    case 11:
        return 0;
    }
    return 1;
}

/* Insert x into the first zero slot of an 8-word array at +0x24 and set the
 * activity flag at +0x20. The `str #1` to +0x20 and the LDR/STREQ into
 * [r0 + ip*4 + 0x24] with `cmp ip,#8` at 020a91d4 are the evidence. Full
 * arrays leave the flag set and change no slot. */
void Unk0a7d54_AddSlot(Unk0a7d54Slots *p, u32 x)
{
    int j;
    p->flag = 1;
    for (j = 0; j < 8; j++) {
        if (p->slot[j] == 0) {
            p->slot[j] = x;
            return;
        }
    }
}

/* Count down the work header word +0x1c while it is positive, releasing one unit
 * through 0205bb68 per step. 020a9390 loads +0x1c, compares with zero, then calls
 * and decrements; non-positive counters are left alone. */
void Unk0a7d54_Unk_0a9390(Unk0a7d54Work *work)
{
    if (work->unk_1c <= 0) {
        return;
    }
    func_0205bb68(work->unk_1c);
    work->unk_1c -= 1;
}

/* Run the countdown on work header word +0x1c exactly the number of times it
 * holds, forwarding each step to 020a9390. 020a93b8 loads the signed count into
 * r4 once, returns when it is non-positive (`cmp #0`/`pople`) and iterates with
 * `cmp r5,r4`/`blt`; this is why the count is cached before the loop. */
void Unk0a7d54_Unk_0a93b8(Unk0a7d54Work *work)
{
    s32 n = work->unk_1c;
    int j;
    for (j = 0; j < n; j++) {
        Unk0a7d54_Unk_0a9390(work);
    }
}

/* Slot object returned by func_0205ad9c; only the two words written/read by
 * 020a9218 are modelled. */
typedef struct Unk0a7d54SlotObj {
    u8 pad_00[0x10];
    u32 unk_10;
    u32 unk_14;
} Unk0a7d54SlotObj;

void Unk02e000_Unk_02e0cc(void);
Unk0a7d54SlotObj *func_0205ad9c(int id);
int func_0205b36c(Unk0a7d54SlotObj *obj);
void func_0205ae60(Unk0a7d54SlotObj *obj);
u32 Unk05b82c_CreateNamedEntry(Unk0a7d54SlotObj *desc, u32 size, const char *name);
void func_0205b9a0(void);
int Unk05ae50_Unk_05b388(u32 slot);
void Unk05ae50_Unk_05af2c(u32 slot);

void func_020a9588(u32 work, s32 level);
void func_020a98fc(u32 id, s32 value, s32 limit);
void func_020a996c(u32 id, s32 value, s32 limit);
void func_020a97fc(u32 work, s32 amount);
void func_020a97b4(u32 work, s32 x, s32 y);
void func_020a966c(u32 work, s32 x, s32 y, s32 phase);
void Unk0a9a90_Nop_0a9a90(u32 work, s32 value);

/* A 32-byte descriptor entry in the table at data_0214cea4. Only the fields
 * touched by 020a7d80 are named; the remaining bytes keep neutral padding. */
typedef struct Unk0a7d54Record {
    s32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u8 unk_18;
    u8 pad_19[3];
    u32 unk_1c;
} Unk0a7d54Record;

/* Object created through Unk065e88_Call_02065fc0; its first word is handed to
 * the two 0205c408/0205c6e0 calls at 020a7dc8 and 020a7dd4. */
typedef struct Unk0a7d54GameObj {
    void *unk_00;
} Unk0a7d54GameObj;

extern Unk0a7d54Record data_0214cea4[];
Unk0a7d54GameObj *Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u16 d);
void func_0205c408(void *object, s32 value);
void func_0205c6e0(void *object);
void Unk065e88_SetUnkFieldsc_10(Unk0a7d54GameObj *obj, u32 a, u32 b);
void Unk065e88_SetUnkField24(Unk0a7d54GameObj *obj, u32 value);
void Unk065e88_SetUnkField30(Unk0a7d54GameObj *obj, u32 value);
void Unk065e88_SetUnkField3c(Unk0a7d54GameObj *obj, u32 value);

/* Allocate the first free entry for descriptor `index`. When the descriptor's
 * signed word +0 is non-negative, build a game object from work words +0x14/
 * +0x18 and copy the descriptor's presentation/position fields into the entry.
 * The signed `ldr/cmp/blt` at 020a7d9c..020a7dac and the store sequence at
 * 020a7e14 are the evidence for the field order. Returns the entry or null. */
Unk0a7d54Entry *func_020a7d80(Unk0a7d54Work *work, u32 index)
{
    Unk0a7d54Entry *entry = Unk0a7d54_Unk_0a7d54(work);
    Unk0a7d54Record *record;
    Unk0a7d54GameObj *obj;

    if (entry == 0) {
        return 0;
    }
    record = &data_0214cea4[index];
    if (record->unk_00 >= 0) {
        obj = Unk065e88_Call_02065fc0(work->unk_14, work->unk_18, 1, record->unk_18);
        func_0205c408(obj->unk_00, record->unk_00);
        func_0205c6e0(obj->unk_00);
        Unk065e88_SetUnkFieldsc_10(obj, record->unk_08, record->unk_0c);
        Unk065e88_SetUnkField24(obj, record->unk_04);
        Unk065e88_SetUnkField30(obj, 4);
        Unk065e88_SetUnkField3c(obj, record->unk_1c);
        entry->unk_08 = (u32)obj;
    }
    entry->unk_04 = (u32)work;
    entry->unk_00 = 1;
    entry->unk_0c = (u8)index;
    entry->unk_0d = 0;
    entry->unk_10 = 0;
    entry->unk_14 = record->unk_08;
    entry->unk_18 = record->unk_0c;
    entry->unk_1c = (s32)record->unk_10;
    entry->unk_20 = record->unk_14;
    entry->pad_24 = record->unk_04;
    return entry;
}

/* Reset a work area to its initial state: word +0 becomes 1, the +4..+0x20
 * header words (except +0x10) are cleared around a release-all call, and the
 * eight slot words plus +0x44 are zeroed. The `str` order and the BL at
 * 020a85d8 are taken directly from 020a85ac. */
void func_020a85ac(Unk0a7d54Work *work)
{
    int i;

    if (work == 0) {
        return;
    }
    work->unk_04 = 0;
    work->unk_00 = 1;
    work->unk_08 = 0;
    work->unk_0c = 0;
    work->unk_14 = 0;
    work->unk_18 = 0;
    Unk0a7d54_Unk_0a84a4(work);
    work->unk_1c = 0;
    work->unk_20 = 0;
    for (i = 0; i < 8; i++) {
        work->slot[i] = 0;
    }
    work->unk_44 = 0;
}

/* State machine over the work header word +0x20 and the eight slot words at
 * +0x24. State 0 succeeds immediately. State 1 marks every slot object's +0x14
 * link as zero and retries failed objects. State 2 creates the missing named
 * entries and runs the post-create hook. State 3 checks the first occupied
 * slot, then releases every occupied slot and returns success. The `addls pc`
 * jump table at 020a9228 and the `cmp #8` loops establish the dispatch and
 * bounds; return 1 only from states 0 and 3 as the original does. */
int func_020a9218(Unk0a7d54Work *work)
{
    int i;
    int found;

    switch (work->unk_20) {
    case 1:
        Unk02e000_Unk_02e0cc();
        for (i = 0; i < 8; i++) {
            if (work->slot[i] != 0) {
                Unk0a7d54SlotObj *obj = func_0205ad9c((int)work->slot[i]);
                obj->unk_14 = 0;
                if (func_0205b36c(obj) == 0) {
                    func_0205ae60(obj);
                }
            }
        }
        work->unk_20 += 1;
        break;
    case 2:
        for (i = 0; i < 8; i++) {
            if (work->slot[i] != 0) {
                Unk0a7d54SlotObj *obj = func_0205ad9c((int)work->slot[i]);
                if (func_0205b36c(obj) == 0) {
                    obj->unk_14 = Unk05b82c_CreateNamedEntry(obj, obj->unk_10 + 12, 0);
                    func_0205b9a0();
                }
            }
        }
        work->unk_20 += 1;
        break;
    case 3:
        found = 0;
        for (i = 0; i < 8; i++) {
            if (work->slot[i] != 0) {
                found = Unk05ae50_Unk_05b388(work->slot[i]);
                break;
            }
        }
        if (found == 0) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (work->slot[i] != 0) {
                Unk05ae50_Unk_05af2c(work->slot[i]);
                work->slot[i] = 0;
                work->unk_1c += 1;
            }
        }
        work->unk_20 = 0;
        return 1;
    case 0:
        return 1;
    default:
        break;
    }
    return 0;
}

/* Dispatch one live entry by its byte state at +12. Cases 6..10 resolve the
 * state through Unk0a7d54_Unk_0a916c and submit a clipped band (90/80) through
 * 020a98fc or 020a996c, gated by the signed byte at +13. Cases 15..17 and
 * 24/25 forward the work link at +4 and the position/phase words to the
 * 020a9... helpers; cases 24/25 additionally take the phase modulo 15. The
 * jump-table order and constants come from the addls table at 020a8318 and
 * its targets. */
void func_020a82f0(Unk0a7d54Entry *entry)
{
    u32 id;

    if (entry->unk_08 != 0) {
        return;
    }
    if (entry->unk_04 == 0) {
        return;
    }
    switch (entry->unk_0c) {
    case 3:
        func_020a9588(entry->unk_04, entry->unk_10);
        return;
    case 6:
    case 7:
    case 8:
        id = Unk0a7d54_Unk_0a916c(entry->unk_0c);
        switch (entry->unk_0d) {
        case 0:
            return;
        case 1:
            func_020a98fc(id, 90 - entry->unk_10, 90);
            return;
        case 2:
            func_020a98fc(id, entry->unk_10, 80);
            return;
        default:
            return;
        }
    case 9:
    case 10:
        id = Unk0a7d54_Unk_0a916c(entry->unk_0c);
        switch (entry->unk_0d) {
        case 0:
            return;
        case 1:
            func_020a996c(id, 90 - entry->unk_10, 90);
            return;
        case 2:
            func_020a996c(id, entry->unk_10, 80);
            return;
        default:
            return;
        }
    case 15:
        func_020a97fc(entry->unk_04, 140 - entry->unk_10);
        return;
    case 16:
        func_020a97b4(entry->unk_04, entry->unk_14, entry->unk_18);
        return;
    case 17:
        if (entry->unk_0d == 0) {
            return;
        }
        if (entry->unk_0d != 1) {
            return;
        }
        func_020a966c(entry->unk_04, entry->unk_14, entry->unk_18, entry->unk_10);
        return;
    case 24:
    case 25:
        Unk0a9a90_Nop_0a9a90(entry->unk_04, entry->unk_10 % 15);
        return;
    }
}
