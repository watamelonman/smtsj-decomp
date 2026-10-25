/*
 * src/game/unit_020f3db4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774(void);
int Unk044394_Unk_044428(int index);
int Unk044394_Unk_044534(int index);
int Unk0f3db4_Unk_0f3ec8(u32 arg0);

u32 Unk0f3db4_Unk_0f44a8(u32 arg0);
void Unk0f3db4_Unk_0f3dc8(void);
void Unk0f3db4_Unk_0f3dd8(void);
int Unk0f3db4_Unk_0f4528(u32 arg0);
void Unk0f3db4_Unk_0f4550(u8 *arg0);
int Unk0f3db4_Unk_0f3db4(void);
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1);
u32 Unk0f3db4_Unk_0f4490(u32 arg0,u16 arg1);

/* Extract the low two packed state bits; higher bits do not affect the result. */
u32 Unk0f3db4_Unk_0f44a8(u32 arg0)
{
  return arg0 & 3;
}

/* Forward fixed index 8 to 044428, discarding its result (020f3dc8 assembly). */
void Unk0f3db4_Unk_0f3dc8(void)
{
  Unk044394_Unk_044428(8);
}

/* Forward fixed index 8 to 044534, discarding its result (020f3dd8 assembly). */
void Unk0f3db4_Unk_0f3dd8(void)
{
  Unk044394_Unk_044534(8);
}

/* Return a normalized boolean for packed flag bit 2, independent of other bits. */
int Unk0f3db4_Unk_0f4528(u32 arg0)
{
  return (arg0 & 4) != 0;
}

/* Set packed flag bit 2 in a writable byte, preserving every other bit. */
void Unk0f3db4_Unk_0f4550(u8 *arg0)
{
  *arg0 = *arg0 | 4;
}

/* Return the borrowed work address at base + 0x5e52 (020f3db4 assembly). */
int Unk0f3db4_Unk_0f3db4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5e52;
}

/* Replace a writable packed byte with its old bit 2 OR arg1; arg1 is unmasked. */
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1)
{
  *arg0 = (*arg0 & 4) | arg1;
}

/* Read low state bits at arg1 in the table selected by arg0; caller bounds it. */
u32 Unk0f3db4_Unk_0f4490(u32 arg0,u16 arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8(arg0);
  return Unk0f3db4_Unk_0f44a8(*(u8 *)(value + arg1));
}



/* Return flag bit 2 at the caller-bounded table offset (020f4510 LDRB/call). */
int Unk0f3db4_Unk_0f4510(u32 arg0,int arg1)
{
  int value;
  value = Unk0f3db4_Unk_0f3ec8(arg0);
  return Unk0f3db4_Unk_0f4528(*(u8 *)(value + arg1));
}




/* Return table lengths from the six-case switch at 020f3e6c;
 * unsupported selectors have length zero. */
u32 Unk0f3db4_Unk_0f3e6c(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x32;
  case 1:
    return 0x32;
  case 2:
    return 0x32;
  case 3:
    return 0x32;
  case 4:
    return 100;
  case 5:
    return 0x3c;
  default:
    return 0;
  }
}


/* Return a borrowed packed-byte table at the offsets in 020f3ec8;
 * unsupported selectors return a null address. */
int Unk0f3db4_Unk_0f3ec8(u32 arg0)
{
  int value;
  value = Unk0f3db4_Unk_0f3db4();
  switch(arg0) {
  case 0:
    return value;
  case 1:
    return value + 0x32;
  case 2:
    return value + 100;
  case 3:
    return value + 0x96;
  case 4:
    return value + 200;
  case 5:
    return value + 300;
  default:
    return 0;
  }
}


extern char data_02150e24[];
int func_020152cc(const char *left, const char *right);
void func_02099b10(int id, int amount);
u16 *Unk02e000_Thunk_0202e788(void);
int func_0209993c(int id);
/* Borrowed four-byte entry: halfwords at record offsets 10 and 12. */
typedef struct Unk0f3db4Ent {
    u16 id;
    u16 n;
} Unk0f3db4Ent;
/* Prefix view used by the three-entry loops at 020f4070 and 020f4398. */
typedef struct Unk0f3db4Obj {
    u8 pad[0xa];
    Unk0f3db4Ent e[3];
} Unk0f3db4Obj;
/* Test equality with data_02150e24 using the comparison call at 020f4160;
 * the existing IsName symbol supports the name. s is a terminated string. */
int Unk0f3db4_IsName(const char *s)
{
    return func_020152cc(s, data_02150e24) == 0;
}

/* Submit each nonzero entry ID with its count times k; 020f4398 loads
 * halfwords at +10/+12 with stride four before calling 02099b10. */
void Unk0f3db4_Unk_0f4398(Unk0f3db4Obj *p, int k)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->e[i].id != 0) {
            func_02099b10(p->e[i].id, k * p->e[i].n);
        }
    }
}

/* Subtract one from a positive query result when id occurs in the four
 * borrowed halfwords returned by 0202e788 (020f4448 comparison chain). */
int Unk0f3db4_Unk_0f4448(int id)
{
    u16 *q = (u16 *)Unk02e000_Thunk_0202e788();
    int n = func_0209993c(id);
    if (n <= 0) {
        return n;
    }
    if (id == q[0] || id == q[1] || id == q[2] || id == q[3]) {
        n--;
    }
    return n;
}

/* Copy low state bits over the ranges observed at 020f4674, leaving
 * bytes 200..299 untouched. Both addresses must cover at least 360 bytes. */
void Unk0f3db4_Unk_0f4674(int arg0,int arg1)
{
  u8 value1;
  int value2;
  int value3;
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3));
    *(u8 *)(arg0 + value3) = value1;
    value3 = value3 + 1;
  } while (value3 < 100);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 100));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 100) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 0x96));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 0x96) = value1;
  } while (value3 < 0x32);
  value3 = 0;
  do {
    value1 = Unk0f3db4_Unk_0f44a8(*(u8 *)(arg1 + value3 + 300));
    value2 = arg0 + value3;
    value3 = value3 + 1;
    *(u8 *)(value2 + 300) = value1;
  } while (value3 < 0x3c);
}

/* Set flag bit 2 at a caller-bounded table offset (020f4538 ADD/call). */
void Unk0f3db4_Unk_0f4538(u32 arg0,int arg1)
{
  int tmp1;
  tmp1 = Unk0f3db4_Unk_0f3ec8((u32)arg0);
  Unk0f3db4_Unk_0f4550((u8 *)tmp1 + arg1);
}

/* Forwards (base + offset, value) to Unk0f3db4_Unk_0f44d0. */
void Unk0f3db4_Unk_0f44b0(u32 arg0, u16 offset, u8 value)
{
    Unk0f3db4_Unk_0f44d0((u8 *)Unk0f3db4_Unk_0f3ec8(arg0) + offset, value);
}

/* Promotes state 2 to state 3. */
void Unk0f3db4_Unk_0f44e4(u32 arg0, u16 offset)
{
    if (Unk0f3db4_Unk_0f4490(arg0, offset) != 2) {
        return;
    }
    Unk0f3db4_Unk_0f44b0(arg0, offset, 3);
}

/* Query up to three entries, stopping at a zero ID or insufficient count.
 * 020f4070 returns 0 for shortage at entry zero, 1 for later shortage, and
 * 2 when the scan ends without shortage; p borrows the observed prefix. */
int func_020f4070(const Unk0f3db4Obj *p)
{
    int result = 2;
    int i;
    for (i = 0; i < 3; i++) {
        if (p->e[i].id == 0) {
            break;
        }
        if (func_0209993c(p->e[i].id) < p->e[i].n) {
            if (i == 0) {
                result = 0;
            } else {
                result = 1;
            }
            break;
        }
    }
    return result;
}

void *func_020445d0(int index, int table);
void func_0204fe18(void *resource);
u8 *func_0204fde0(void *resource);

/* Select a borrowed 46-byte record. The switch and resource calls at
 * 020f3de8 establish the table mapping; index wraps to 16 bits for table 1. */
u8 *func_020f3de8(u32 selector, u16 index)
{
    int table = 0;
    void *resource;
    switch (selector) {
    case 0: table = 0; break;
    case 1: index += 50; break;
    case 2: table = 1; break;
    case 3: table = 2; break;
    case 4: table = 3; break;
    case 5: table = 4; break;
    }
    resource = func_020445d0(8, table);
    func_0204fe18(resource);
    return func_0204fde0(resource) + index * 46;
}

/* Map the signed ID ranges tested at 020f3f2c to table selectors.
 * Unrecognized IDs use selector zero, as in the original comparison chain. */
int func_020f3f2c(int id)
{
    if (id >= 211 && id <= 260) return 0;
    if (id >= 261 && id <= 310) return 1;
    if (id >= 311 && id <= 360) return 2;
    if (id >= 361 && id <= 410) return 3;
    if (id >= 111 && id <= 210) return 4;
    if (id >= 51 && id <= 110) return 5;
    return 0;
}

/* Borrowed eight-byte entry, with observed halfwords at +2 and +4. */
typedef struct Unk0f3db4ListEntry {
    u16 unknown;
    u16 index;
    u16 id;
    u16 trailing;
} Unk0f3db4ListEntry;

/* Caller owns storage for count entries and an additional appended entry. */
typedef struct Unk0f3db4List {
    u8 prefix[0xfc];
    int count;
    Unk0f3db4ListEntry entries[1];
} Unk0f3db4List;

/* Append ID/index only if no existing record has the same string at +22;
 * 020f40c8 resolves entries through the range mapper and record accessor. */
void func_020f40c8(Unk0f3db4List *list, const u8 *record, u32 index)
{
    int i;
    for (i = 0; i < list->count; i++) {
        u8 *other = func_020f3de8(func_020f3f2c(list->entries[i].id),
                                list->entries[i].index);
        if (func_020152cc((const char *)record + 22, (const char *)other + 22) == 0) {
            return;
        }
    }
    list->entries[list->count].id = *(const u16 *)record;
    list->entries[list->count].index = index;
    list->count++;
}

/* Promote state 2 to 3 across all six tables. The halfword loop counter
 * and repeated length query follow 020f43d4; table storage is borrowed. */
void func_020f43d4(void)
{
    int selector;
    u16 index;
    for (selector = 0; selector < 6; selector++) {
        for (index = 0; index < Unk0f3db4_Unk_0f3e6c(selector); index++) {
            if (Unk0f3db4_Unk_0f4490(selector, index) == 2) {
                Unk0f3db4_Unk_0f44b0(selector, index, 3);
            }
        }
    }
}

/* Return whether a valid table contains state 2; 020f4560 bounds selectors
 * to [0,6) and scans with a wrapping halfword offset. */
int func_020f4560(int selector)
{
    u32 count;
    u16 index;
    if (selector < 0 || selector >= 6) return 0;
    count = Unk0f3db4_Unk_0f3e6c(selector);
    for (index = 0; index < count; index++) {
        if (Unk0f3db4_Unk_0f4490(selector, index) == 2) return 1;
    }
    return 0;
}

int Unk0e651c_Unk_0e666c(int id);
int Unk044394_HasEntry(int index);
int func_020e49cc(int kind, int id);

/* Borrowed record prefix: signed query IDs at +4, +6, and +8. */
typedef struct Unk0f3db4Record {
    u16 id;
    u8 kind;
    u8 unknown;
    s16 query[3];
} Unk0f3db4Record;

/* Require all present query IDs to pass 020e666c. The signed sentinel
 * comparisons and short-circuit call sequence are observed at 020f3fcc. */
int func_020f3fcc(const Unk0f3db4Record *record)
{
    if (record->query[0] <= -1) return 1;
    if (record->query[1] <= -1) {
        if (Unk0e651c_Unk_0e666c(record->query[0])) return 1;
    } else if (record->query[2] <= -1) {
        if (Unk0e651c_Unk_0e666c(record->query[0]) &&
            Unk0e651c_Unk_0e666c(record->query[1])) return 1;
    } else {
        if (Unk0e651c_Unk_0e666c(record->query[0]) &&
            Unk0e651c_Unk_0e666c(record->query[1]) &&
            Unk0e651c_Unk_0e666c(record->query[2])) return 1;
    }
    return 0;
}


/* Return the integer percentage of eligible records whose state is at least
 * two. 020f45c0 excludes IDs accepted by 020e49cc(2,id); empty sets return zero. */
u32 func_020f45c0(int selector)
{
    u32 ready;
    u32 total;
    int i;
    if (!Unk044394_HasEntry(8)) return 0;
    Unk0f3db4_Unk_0f3db4();
    ready = 0;
    total = 0;
    i = 0;
    for (; i < (int)Unk0f3db4_Unk_0f3e6c(selector); i++) {
        Unk0f3db4Record *record = (Unk0f3db4Record *)func_020f3de8(selector, (u16)i);
        if (!func_020e49cc(2, record->id)) {
            if ((int)Unk0f3db4_Unk_0f4490(selector, (u16)i) >= 2) ready++;
            total++;
        }
    }
    if (total == 0) return 0;
    return 100 * ready / total;
}

/* Writable prefix observed at 020f4180; caller supplies append capacity.
 * The later list starts at this same address and has its own count at +252. */
typedef struct Unk0f3db4Scan {
    int partial;
    int ready;
    int count;
    Unk0f3db4ListEntry entries[1];
} Unk0f3db4Scan;

/* Scan six tables, promote qualifying packed states, and append records.
 * Kind dispatch, query calls, and the two list layouts follow 020f4180;
 * subsystem meanings remain unknown, so the existing neutral name is retained. */
void func_020f4180(Unk0f3db4Scan *out)
{
    u32 selector;
    for (selector = 0; (int)selector < 6; selector++) {
        int count = Unk0f3db4_Unk_0f3e6c(selector);
        int i;
        for (i = 0; (int)i < (int)count; i++) {
            u8 *record = func_020f3de8(selector, i);
            int state;
            if (func_020e49cc(2, ((Unk0f3db4Record *)record)->id)) continue;
            state = Unk0f3db4_Unk_0f4490(selector, i);
            if (state >= 2) continue;
            switch (((Unk0f3db4Record *)record)->kind) {
            case 0:
                if (func_020f3fcc((Unk0f3db4Record *)record)) {
                    Unk0f3db4_Unk_0f44b0(selector, i, 2);
                    if (Unk0f3db4_IsName((char *)record + 22)) out->ready = 1;
                    else func_020f40c8((Unk0f3db4List *)out, record, i);
                }
                break;
            case 1:
                if (func_020f3fcc((Unk0f3db4Record *)record)) {
                    switch (func_020f4070((Unk0f3db4Obj *)record)) {
                    case 0: break;
                    case 1:
                        if (state == 0) {
                            Unk0f3db4_Unk_0f44b0(selector, i, 1);
                            if (Unk0f3db4_IsName((char *)record + 22)) out->partial = 1;
                            else func_020f40c8((Unk0f3db4List *)out, record, i);
                        }
                        break;
                    case 2:
                        Unk0f3db4_Unk_0f44b0(selector, i, 2);
                        if (Unk0f3db4_IsName((char *)record + 22)) out->ready = 1;
                        else func_020f40c8((Unk0f3db4List *)out, record, i);
                        break;
                    }
                }
                break;
            case 2:
                if (func_020f3fcc((Unk0f3db4Record *)record) && func_020f4070((Unk0f3db4Obj *)record) == 2) {
                    out->entries[out->count].id = ((Unk0f3db4Record *)record)->id;
                    out->entries[out->count].index = i;
                    out->count++;
                    Unk0f3db4_Unk_0f4398((Unk0f3db4Obj *)record, 1);
                    Unk0f3db4_Unk_0f44b0(selector, i, 2);
                }
                break;
            }
        }
    }
}
