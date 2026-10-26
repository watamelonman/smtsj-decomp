/*
 * src/game/unit_020a7d54.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* One 40-byte entry in the 32-slot table starting at +0x48 of the work area.
 * Offsets come from the loads/stores in the entry routines below; the words whose
 * purpose is unknown stay neutral. */
typedef struct Unk0a7d54Entry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0c;
    u8 unk_0d;
    u8 pad_0e[2];
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    s32 unk_1c;
    u32 unk_20;
    u32 pad_24;
} Unk0a7d54Entry;

/* Borrowed work-area view: 020a7d54/020a84a4/020a8534 walk 32 entries from +0x48.
 * Header words are those read or written by 020a8ad0/020a8b70/020a8bac; the
 * unused gaps have no inferred meaning and stay padded. */
typedef struct Unk0a7d54Work {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 pad_0c[0x14];
    u32 unk_20;
    u8 pad_24[0x20];
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

int func_020a82f0();
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
void Unk0a7d54_Unk_0a93b8(Unk0a7d54Entry *entry);
/* decompiler-derived */
void Unk0a7d54_Unk_0a8bac(int arg0)
{
  if (arg0 == 0) {
    return;
  }
  Unk0a7d54_Unk_0a93b8((Unk0a7d54Entry *)arg0);
  Unk0a7d54_Unk_0a8534((Unk0a7d54Work *)arg0);
  *(u32 *)(arg0 + 8) = 0;
  *(u32 *)(arg0 + 4) = 0;
  if (*(int *)(arg0 + 0x14) != 0) {
    func_0205ddb4();
    *(u32 *)(arg0 + 0x14) = 0;
  }
  if (*(int *)(arg0 + 0x18) == 0) {
    return;
  }
  func_0205c368();
  *(u32 *)(arg0 + 0x18) = 0;
  return;
}


/* decompiler-derived */
u32 Unk0a7d54_Unk_0a916c(u32 arg0)
{
  switch(arg0) {
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
void Unk0a7d54_Unk_0a8bac(int arg0);
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

void Unk0a7d54_Unk_0a8b00(u32 *p, u32 a, s32 b)
{
    if (p == 0) {
        return;
    }
    if (p[2] != 0 && p[2] != 11) {
        return;
    }
    p[1] = 0;
    p[0] = a;
    p[3] = b + 1;
    p[4] = 0;
    if (p[2] == 11) {
        p[17] = 1;
    } else {
        p[2] = 1;
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
    Unk0a7d54_Unk_0a8bac((int)work);
}

int Unk0a7d54_Unk_0a8c04(u8 *p)
{
    u32 v;
    if (Unk0a7d54_Unk_0a9204((Unk0a7d54Fields *)p) == 1) {
        return 0;
    }
    v = FIELD(u32, p, 8);
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

/* Count down entry word +0x1c while it is positive, releasing one unit through
 * 0205bb68 per step. 020a9390 loads +0x1c, compares with zero, then calls and
 * decrements; non-positive counters are left alone. */
void Unk0a7d54_Unk_0a9390(Unk0a7d54Entry *entry)
{
    if (entry->unk_1c <= 0) {
        return;
    }
    func_0205bb68(entry->unk_1c);
    entry->unk_1c -= 1;
}

/* Run the countdown on entry word +0x1c exactly the number of times it holds,
 * forwarding each step to 020a9390. 020a93b8 loads the signed count into r4
 * once, returns when it is non-positive (`cmp #0`/`pople`) and iterates with
 * `cmp r5,r4`/`blt`; this is why the count is cached before the loop. */
void Unk0a7d54_Unk_0a93b8(Unk0a7d54Entry *entry)
{
    s32 n = entry->unk_1c;
    int j;
    for (j = 0; j < n; j++) {
        Unk0a7d54_Unk_0a9390(entry);
    }
}
