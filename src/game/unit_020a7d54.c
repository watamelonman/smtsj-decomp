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

/* Borrowed work-area view: 020a7d54/020a84a4/020a8534 walk 32 entries from +0x48. */
typedef struct Unk0a7d54Work {
    u8 pad_00[0x48];
    Unk0a7d54Entry entries[32];
} Unk0a7d54Work;

void Unk0a7d54_Unk_0a7e8c(Unk0a7d54Entry *entry);
int Unk0a7d54_FindByKey(u8 *p, u32 key);

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
void Unk0a7d54_Unk_0a8594(u8 *owner, u32 key)
{
    Unk0a7d54Entry *entry = (Unk0a7d54Entry *)Unk0a7d54_FindByKey(owner, key);
    if (entry == 0) {
        return;
    }
    Unk0a7d54_Unk_0a7e8c(entry);
}

/* Forward owner/key to FindByKey, then mark a found entry with value.
 * 020a7ec8 saves the third argument across the lookup; missing keys do nothing. */
void Unk0a7d54_Unk_0a7ec8(u8 *owner, u32 key, u32 value)
{
    int entry = Unk0a7d54_FindByKey(owner, key);
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


int Unk0a0ce4_Unk_0a0da4();
int Unk0a0ce4_Unk_0a0dd8();
void Unk0a7d54_Unk_0a8b70();
/* decompiler-derived */
void Unk0a7d54_Unk_0a8c40(u32 arg0)
{
  int tmp1;
  tmp1 = Unk0a0ce4_Unk_0a0dd8(0x1d);
  if (tmp1 != 0) {
    Unk0a0ce4_Unk_0a0da4(0x52);
  }
  Unk0a7d54_Unk_0a8b70(arg0);
  return;
}

int func_020a7ee8();
/* decompiler-derived */
void Unk0a7d54_Unk_0a84cc(int arg0)
{
  int tmp1;
  int *v2;
  v2 = (int *)(arg0 + 0x48);
  tmp1 = 0;
  do {
    if (*v2 != 0) {
      func_020a7ee8(v2);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 10;
  } while (tmp1 < 0x20);
  return;
}

int func_020a82f0();
/* decompiler-derived */
void Unk0a7d54_Unk_0a8500(int arg0)
{
  int tmp1;
  int *v2;
  v2 = (int *)(arg0 + 0x48);
  tmp1 = 0;
  do {
    if (*v2 != 0) {
      func_020a82f0(v2);
    }
    tmp1 = tmp1 + 1;
    v2 = v2 + 10;
  } while (tmp1 < 0x20);
  return;
}


int func_0205c368();
int func_0205ddb4();
void Unk0a7d54_Unk_0a8534(Unk0a7d54Work *work);
void Unk0a7d54_Unk_0a93b8();
/* decompiler-derived */
void Unk0a7d54_Unk_0a8bac(int arg0)
{
  if (arg0 == 0) {
    return;
  }
  Unk0a7d54_Unk_0a93b8();
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

int Unk0a7d54_FindByKey(u8 *p, u32 k)
{
    int j;
    u8 *e = p + 72;
    for (j = 0; j < 32; j++, e += 40) {
        if (FIELD(u32, e, 0) != 0 && FIELD(u8, e, 12) == k) {
            return (int)e;
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
void Unk0a7d54_Unk_0a8500(int arg0);
void Unk0a7d54_Unk_0a8bac(int arg0);
void func_0205bb68(s32 value);
typedef struct Unk0a7d54Slots {
    u8 pad_00[0x20];
    u32 flag;
    u32 slot[8];
} Unk0a7d54Slots;
void Unk0a7d54_Unk_0a8ad0(u8 *p)
{
    if (p == 0 || FIELD(u32, p, 8) == 0) {
        return;
    }
    func_02057e18(31);
    func_02057ddc(-1);
    Unk0a7d54_Unk_0a8500((int)p);
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

void Unk0a7d54_Unk_0a8b70(u8 *p)
{
    if (p == 0 || FIELD(u32, p, 8) == 0) {
        return;
    }
    FIELD(u32, p, 68) = 0;
    if (Unk0a7d54_Unk_0a9204((Unk0a7d54Fields *)p) != 0) {
        FIELD(u32, p, 8) = 11;
        return;
    }
    Unk0a7d54_Unk_0a8bac((int)p);
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

void Unk0a7d54_Unk_0a93b8(u8 *p)
{
    s32 n = FIELD(s32, p, 28);
    int j;
    for (j = 0; j < n; j++) {
        Unk0a7d54_Unk_0a9390((Unk0a7d54Entry *)p);
    }
}
