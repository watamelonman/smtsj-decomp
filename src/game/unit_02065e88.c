/*
 * unit_02065e88: small accessors for a game object whose fields are written
 * from many systems (callers in 0x020a7..., 0x020b7..., 0x020fe...).
 * Field meanings are not known yet; offsets are named by position.
 */
typedef signed int s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned long long u64;
typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
typedef unsigned int u32;

typedef struct GameObj {
    u32 unk00;
    u32 pairA;      /* 0x04: first of a pair set together */
    u32 pairB;      /* 0x08: second of the pair */
    u32 field0C;    /* 0x0C */
    u32 field10;    /* 0x10 */
    u32 unk14[3];
    u32 field20;    /* 0x20 */
    u32 field24;    /* 0x24 */
    u32 field28;    /* 0x28 */
    u32 field2C;    /* 0x2C */
    u32 field30;    /* 0x30 */
    u32 field34;    /* 0x34 */
    u32 unk38;
    u32 field3C;    /* 0x3C */
} GameObj;

u8 *func_02065fc0(u32 a, u32 b, u32 c, int d, u16 e);
/* At 02065fac, forwards three words and inserts mode 3 before the
 * halfword argument. The callee reads its fifth stack argument with ldrh. */
void Unk065e88_Call_02065fc0(u32 a, u32 b, u32 c, u16 d)
{
    func_02065fc0(a, b, c, 3, d);
}

/*
 * Stores both words of the 0x04/0x08 pair. The two are always written together,
 * so they are kept adjacent in GameObj; callers use the pair as one record.
 */
void Unk065e88_SetPair04(GameObj *obj, u32 a, u32 b) {
    obj->pairA = a;
    obj->pairB = b;
}

/* Stores value in the unknown u32 at +0x20. */
void Unk065e88_SetUnkField20(GameObj *obj, u32 value) { obj->field20 = value; }

/* Stores value in the unknown u32 at +0x28. */
void Unk065e88_SetUnkField28(GameObj *obj, u32 value) { obj->field28 = value; }

/* Stores value in the unknown u32 at +0x24. */
void Unk065e88_SetUnkField24(GameObj *obj, u32 value) { obj->field24 = value; }

/* Stores value in the unknown u32 at +0x2C. */
void Unk065e88_SetUnkField2C(GameObj *obj, u32 value) { obj->field2C = value; }

/* Stores value in the unknown u32 at +0x30. */
void Unk065e88_SetUnkField30(GameObj *obj, u32 value) { obj->field30 = value; }

/* Stores value in the unknown u32 at +0x34. */
void Unk065e88_SetUnkField34(GameObj *obj, u32 value) { obj->field34 = value; }

typedef struct Unk065e88Flag {
    u8 pad_0000[0x3a];
    u8 unk_003a;
} Unk065e88Flag;

/* At 020662b8, cmp/movne/moveq normalize any nonzero input to byte 1. */
void Unk065e88_SetFlag3a(Unk065e88Flag *o, int on)
{
    o->unk_003a = on != 0;
}

extern u8 data_0214544c[];
extern u8 data_02144e44[];
/* At 020663d8, selectors 0 and 1 load the two literal table addresses.
 * Other selectors retain their incoming r0 value and are not valid tables. */
u32 *Unk065e88_GetTable(int i)
{
    if (i == 0) {
        return (u32 *)data_0214544c;
    }
    if (i == 1) {
        return (u32 *)data_02144e44;
    }
    return (u32 *)i;
}

/* At 020663f8, selectors 0 and 1 each have 193 words; others have none.
 * The two return constants and GetTableEntry indexing support the table name. */
int Unk065e88_GetTableCount(int i)
{
    int n = 0;
    switch (i) {
    case 0:
        n = 193;
        break;
    case 1:
        n = 193;
        break;
    }
    return n;
}

/* At 0206641c, converts a one-based index to a word offset in GetTable.
 * Offsets >= count - 1 select word zero; negative offsets are not clamped.
 * Callers must supply selector 0 or 1 and an index valid for the table. */
u32 *Unk065e88_GetTableEntry(int i, int n)
{
    n--;
    if (n >= Unk065e88_GetTableCount(i) - 1) {
        n = 0;
    }
    return Unk065e88_GetTable(i) + n;
}

/*
 * Empty callback (a bare return, 4 bytes). It has no direct callers but its address
 * is stored in a callback table by Unk065e88_Unk_06646c, so the body stays empty.
 */
void Unk065e88_Nop_066c90(void) { }



/* At 020662cc, stores one word at +0x3c; the field meaning is unknown. */
void Unk065e88_SetUnkField3c(GameObj *obj, u32 value)
{
    obj->field3C = value;
}

/* At 02066284, stores the two words at +0x0c and +0x10 in that order. */
void Unk065e88_SetUnkFieldsc_10(GameObj *obj, u32 a, u32 b)
{
    obj->field0C = a;
    obj->field10 = b;
}

typedef struct Unit020a1418Entry Unit020a1418Entry;
int func_020684c0(const void *record);
Unit020a1418Entry *func_020a1428(u16 id);
/* At 02068554, passes the resource-19 lookup result directly to 020684c0.
 * The caller must supply an id whose lookup produces a valid record. */
int Unk065e88_Unk_068554(u16 id)
{
    return func_020684c0(func_020a1428(id));
}

void func_0205bb68(void);
/* At 02065eac, invokes 0205bb68 three times without setting arguments. */
void Unk065e88_Unk_065eac(void)
{
    func_0205bb68();
    func_0205bb68();
    func_0205bb68();
}

/* This entry receives a word in r0 even though its current callee ignores it. */
void Unk05ae50_Unk_05af2c(u32 value);
void func_020617c8(u32 value);
/* At 020663bc, forwards arg1 to 0205af2c, then saved arg0 to 020617c8. */
void Unk065e88_Unk_0663bc(u32 arg0, u32 arg1)
{
    Unk05ae50_Unk_05af2c(arg1);
    func_020617c8(arg0);
}



/* At 0206644c, compares two readable halfword pairs by second word, then
 * first word on ties. Returns the signed difference, not a normalized sign. */
int Unk065e88_Unk_06644c(const u16 *arg0, const u16 *arg1)
{
  int value;
  value = (u32)arg0[1] - (u32)arg1[1];
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}

void Unk02e000_Unk_02e0cc(void);
void Unk05b82c_Unk_05b82c(int id);
/* At 02065e88, calls 0202e0cc, then submits ids 188, 189 and 190 to
 * 0205b82c in that order. No broader initialization purpose is established. */
void Unk065e88_Unk_065e88(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xbc);
  Unk05b82c_Unk_05b82c(0xbd);
  Unk05b82c_Unk_05b82c(0xbe);
}

void func_0205c3dc(u32 handle);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_02095818(void);
void func_02063b80();
void func_020640c0();
void func_0206541c();
void func_02065438();
void func_02063b08();
void func_02063b4c();
void func_0205c704(u32 handle);
int func_0205ca88(u32 handle);
int func_0205caa0(u32 handle);

/* At 02065ec0, fills a caller-owned 36-byte callback descriptor with size
 * 120, mode 4, halfword 100 and six callback addresses; calls 02095818. */
void Unk065e88_Unk_065ec0(u32 *p)
{
    p[0] = 120;
    func_02095818();
    p[1] = 4;
    FIELD(u16, p, 8) = 100;
    p[3] = (u32)func_02063b80;
    p[4] = (u32)func_020640c0;
    p[5] = (u32)func_0206541c;
    p[6] = (u32)func_02065438;
    p[7] = (u32)func_02063b08;
    p[8] = (u32)func_02063b4c;
}

/* At 02066258, forwards a nonzero handle to 0205c3dc and clears its slot.
 * The caller owns a writable slot; zero requires no call. */
void Unk065e88_Unk_066258(u32 *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_0205c3dc(*arg0);
  *arg0 = 0;
}

typedef struct Unk065e88Resource Unk065e88Resource;
Unk065e88Resource *func_020445d0(u32 arg0, u32 arg1);
void *func_0204fde0(Unk065e88Resource *resource);
u32 func_0204fe18(Unk065e88Resource *resource);
/* At 02067d30, forwards both inputs to 020445d0, writes the low halfword
 * of 0204fe18(resource) to the caller-owned output, then calls 0204fde0. */
void Unk065e88_Unk_067d30(u32 arg0,u32 arg1,u16 *arg2)
{
  u16 value1;
  Unk065e88Resource *value2;
  value2 = func_020445d0(arg0, arg1);
  value1 = func_0204fe18(value2);
  *arg2 = value1;
  func_0204fde0(value2);
}


extern u8 data_0216b9a8[];
void func_02008848(void *destination, int value, u32 size);
int func_020629ac(int arg0, int arg1, int arg2, int arg3);
void func_02063a6c(int *object);
/* At 02065f30, clears 120 caller-owned bytes, allocates two handles and
 * initializes the owner only when both succeed. Publishes it at 0216b9ac.
 * A failed second allocation retains the first handle, as in the original. */
void Unk065e88_Unk_065f30(int *arg0)
{
  int value;
  func_02008848(arg0,0,0x78);
  value = func_020629ac(5,4,1,1);
  *arg0 = value;
  if (value == 0) {
    return;
  }
  value = func_020629ac(4,1,1,1);
  arg0[1] = value;
  if (value == 0) {
    return;
  }
  arg0[3] = 0;
  arg0[2] = 0;
  arg0[0x13] = 0;
  func_02063a6c(arg0);
  *(int **)(((int)data_0216b9a8) + 4) = arg0;
}

/* Partial readable record layout established by the loads at 02068564. */
typedef struct Unk065e88Obj24 {
    u8 pad_0000[0x24];
    u32 pad_0024_0 : 28;
    u32 flag_0024_28 : 1;
    u8 pad_0028[2];
    u16 unk_002a;
} Unk065e88Obj24;

void func_02072238(s32 *object);
int Unk0e651c_Unk_0e666c(u32 id);
int func_020684c0(const void *record);
/* At 02066078, updates the handle when byte +0x38 is set; byte +0x39
 * enables the end-position test, which clears both flags at count - 1.
 * The owner must cover 0x3a bytes and contain a valid handle at +0. */
void Unk065e88_Unk_066078(u8 *p)
{
    if (p[56] != 0) {
        func_0205c704(FIELD(u32, p, 0));
    }
    if (p[57] == 0) {
        return;
    }
    {
        int n = func_0205ca88(FIELD(u32, p, 0));
        if (func_0205caa0(FIELD(u32, p, 0)) >= n - 1) {
            p[56] = 0;
            p[57] = 0;
        }
    }
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020667d0();
void Unk065e88_Nop_066c90();
typedef struct Unk065e88Work Unk065e88Work;
void func_02066c94(Unk065e88Work *object);
void func_02066d30();
void func_020664c4();
void func_02063920(void);
int func_020445f4(int resource, int index);
int func_0204fed8(int handle, u32 index);
int func_02063a30(int entry);
void func_02061f10(u32 handle, int arg1, int arg2, int arg3, int value);

/* At 0206646c, fills a caller-owned 36-byte callback descriptor with size
 * 1104, mode 4, a null slot and five callback addresses; leaves +8 intact. */
void Unk065e88_Unk_06646c(u32 *p)
{
    p[0] = 1104;
    p[1] = 4;
    p[3] = 0;
    p[4] = (u32)func_020667d0;
    p[5] = (u32)Unk065e88_Nop_066c90;
    p[6] = (u32)func_02066c94;
    p[7] = (u32)func_02066d30;
    p[8] = (u32)func_020664c4;
}

/* At 020672b4, stores the mode word, then optionally dispatches mode 1
 * to 02072238 or sets a word at +0x220 (mode 2) / +0x2f0 (mode 4).
 * Those stores and dispatch establish the name; o must cover the selected field. */
void Unk065e88_SetMode(s32 *o, s32 v, int notify)
{
    o[0] = v;
    if (notify == 0) {
        return;
    }
    switch (o[0]) {
    case 1:
        func_02072238(o);
        break;
    case 2:
        FIELD(u32, o, 0x220) = 1;
        break;
    case 4:
        FIELD(u32, o, 0x2f0) = 1;
        break;
    }
}

/* At 020672fc, converts n entries from resource 12 and submits the last
 * value through the owner handle at +0x108. Requires n > 0 and an owner
 * readable through +0x10b; the original leaves the value unset for n == 0. */
void Unk065e88_Unk_0672fc(u8 *p, int a, u32 n)
{
    int r;
    int h;
    u32 i;
    func_02063920();
    h = func_020445f4(12, a);
    for (i = 0; i < n; i++) {
        r = func_02063a30(func_0204fed8(h, i));
    }
    func_02061f10(FIELD(u32, p, 264), -1, 0, 0, r);
}

/* At 02068564, rejects bit 28 at +0x24, then requires either a zero id
 * at +0x2a or a nonzero 020e666c result, and a nonzero 020684c0 result.
 * The caller supplies a readable record; the returned predicate is 0 or 1. */
int Unk065e88_Unk_068564(Unk065e88Obj24 *o)
{
    if (!o->flag_0024_28 && (o->unk_002a == 0 || Unk0e651c_Unk_0e666c(o->unk_002a) != 0) && func_020684c0(o) != 0) {
        return 1;
    }
    return 0;
}

/* Partial owner layout: only offsets read by these callbacks are established. */
struct Unk065e88Work {
    u32 unk_0000;
    u8 pad_0004[0xae];
    u8 unk_00b2;
    u8 pad_00b3[0x69];
    u32 unk_011c;
    u8 pad_0120[0x114];
    u32 unk_0234;
    u8 pad_0238[0x158];
    u32 unk_0390;
};

typedef struct Unk065e88Record {
    u16 unk_0000;
    u8 pad_0002[0x26];
    u16 flag_0028 : 1;
    u16 id_0028 : 15;
} Unk065e88Record;

typedef struct Unk065e88LocalRecord {
    u8 pad_0000[0x1f];
    u8 pad_001f : 2;
    u8 flags_001f : 6;
    u8 pad_0020[4];
} Unk065e88LocalRecord;
int Unk02e000_SetRecord(u32 id, void *record);

/* At 02067418, resolves each id through resource 19, uses its byte +2
 * to index resource 18, and submits the last converted value to +0x11c.
 * The owner count at +0xb2 must be positive and ids must cover that count. */
void func_02067418(Unk065e88Work *object, const u16 *ids)
{
    int value;
    int handle;
    u16 i;
    func_02063920();
    handle = func_020445f4(18, 0);
    for (i = 0; i < object->unk_00b2; i++) {
        const u8 *record = (const u8 *)func_020a1428(ids[i]);
        value = func_02063a30(func_0204fed8(handle, record[2]));
    }
    func_02061f10(object->unk_011c, -1, 0, 0, value);
}

void func_02057e58(int arg0, int arg1, int arg2);
void func_02057eb8(int arg0);
void Unk072238_Nop_072370(Unk065e88Work *object);
void func_0207498c(Unk065e88Work *object);
void func_02092624(Unk065e88Work *object);
/* At 02066c94, skips owners with +0x234 == 11 or +0x390 == 8.
 * Otherwise brackets mode-specific callbacks with 02057e58/02057eb8 calls.
 * The owner must be readable through +0x393; no gameplay purpose is known. */
void func_02066c94(Unk065e88Work *object)
{
    if (object->unk_0234 == 11 || object->unk_0390 == 8) return;
    func_02057e58(4, 10, 30);
    func_02057e58(5, 30, 10);
    func_02057eb8(4);
    switch (object->unk_0000) {
    case 1: Unk072238_Nop_072370(object); break;
    case 2:
    case 3: func_0207498c(object); break;
    case 4: func_02092624(object); break;
    case 0:
    case 5:
    case 6: break;
    }
    func_02057eb8(-1);
}

/* At 020684c0, accepts an unflagged record immediately; otherwise either
 * referenced record must have nonzero upper six bits at +0x1f. Both lookups
 * write a caller-owned 36-byte temporary. The input must cover +0x29. */
int func_020684c0(const void *record)
{
    const Unk065e88Record *r = record;
    Unk065e88LocalRecord local;
    if (!r->flag_0028) return 1;
    if (Unk02e000_SetRecord(r->unk_0000, &local) && local.flags_001f) return 1;
    if (r->id_0028 && Unk02e000_SetRecord(r->id_0028, &local) && local.flags_001f) return 1;
    return 0;
}


/* Partial resource record: lookups return consecutive 100-byte records. */
typedef struct Unk065e88SelectionRecord {
    u16 id;
    u8 kind;
    u8 rank;
    u8 unk04;
    u8 category;
    u8 rest[94];
} Unk065e88SelectionRecord;

u8 *Unk02e000_GetWorkArea(void);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
void func_02057df8(void);
void func_0205de40(int mode, u32 handle, int id, int x, int y,
                   float a, float b, int c, float d, int layer);
void func_020a9fd8(int mode, int x, int y, int a, int b, int layer,
                   const void *text, int value);
void func_020dd910(u32 *object);
void func_02060dd4(void *out, u32 *object, int a, int b, int c);
void func_02059f70(u32 handle, int a, int id, int value,
                   const void *data, int b, int layer);
u8 *Unk02e000_Thunk_0202e788(void);
u8 *func_020a9e14(int kind, const void *table, int index);
extern u8 data_021457cc[], data_021457d0[], data_021457d4[], data_021457dc[];
void func_020660cc(u8 *object);
u8 *func_020611dc(void (*a)(u8 *), void (*b)(u8 *), void (*c)(u8 *),
                   void (*d)(u32 *), int size, int mode, u16 value, int flag);
u32 func_0205c3c0(void);
void func_0205c3fc(u32 handle, u32 a, u32 b);

/* At 02065fc0, allocates a 64-byte owner, chooses callbacks by c, and
 * initializes its handle, unit scales, sentinel words and enabled bytes.
 * Returns the allocation; allocation and handle creation must succeed. */
u8 *func_02065fc0(u32 a, u32 b, u32 c, int d, u16 e)
{
    u8 *p = func_020611dc(Unk065e88_Unk_066078,
        c ? func_020660cc : 0,
        c ? 0 : func_020660cc,
        Unk065e88_Unk_066258, 64, d, e, 1);
    u32 h = func_0205c3c0();
    FIELD(u32, p, 0) = h;
    func_0205c3fc(h, a, b);
    FIELD(float, p, 32) = 1.0f;
    FIELD(float, p, 20) = 1.0f;
    FIELD(float, p, 24) = 1.0f;
    FIELD(int, p, 40) = -1;
    FIELD(int, p, 48) = -1;
    FIELD(int, p, 52) = -1;
    p[56] = 1;
    p[58] = 1;
    FIELD(int, p, 60) = -1;
    return p;
}

/* Partial owner layout; callers provide the trailing array of entry pointers. */
typedef struct Unk065e88SelectionOwner {
    u8 pad[280];
    u32 handle;
    u32 unused;
    u8 *entries[];
} Unk065e88SelectionOwner;

/* At 02067370, converts resource-18 entries selected by the work area's
 * signed indices, then submits the last value through owner +0x118.
 * At least one nonnegative selection and valid entry pointers are required. */
void func_02067370(Unk065e88SelectionOwner *owner)
{
    int value;
    int handle;
    u8 *work;
    u16 i;
    func_02063920();
    handle = func_020445f4(18, 0);
    work = Unk02e000_GetWorkArea();
    for (i = 0; i < work[855]; i++) {
        int index = ((s8 *)work)[840 + i];
        if (index >= 0) {
            const u8 *r = (const u8 *)func_020a1428(FIELD(u16, owner->entries[index], 54));
            value = func_02063a30(func_0204fed8(handle, r[2]));
        }
    }
    func_02061f10(owner->handle, -1, 0, 0, value);
}

/* At 02067b28, sets four identical dispatch words, then chooses the
 * handle-based call for zero value or text-table call otherwise.
 * A zero value requires a valid handle at owner +0x3b0. */
void func_02067b28(u8 *owner, int value, int x, int y)
{
    func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
    if (value == 0) {
        func_0205de40(1, FIELD(u32, owner, 944), 25, x - 8, y, 1.0f, 1.0f, 0, 1.0f, 10);
    } else {
        func_020a9fd8(1, x, y, 2, 2, 10, data_021457cc, value);
    }
}

/* At 02067bd8, zero value uses the owner's +0x3b0 handle; nonzero
 * value resets dispatch state before submitting table 021457d0.
 * A zero value requires a valid handle at owner +0x3b0. */
void func_02067bd8(u8 *owner, int value, int x, int y)
{
    if (value == 0) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        func_0205de40(1, FIELD(u32, owner, 944), 25, x - 8, y, 1.0f, 1.0f, 0, 1.0f, 10);
    } else {
        func_02057df8();
        func_020a9fd8(1, x, y, 2, 2, 10, data_021457d0, value);
    }
}

/* At 02067c88, builds a 16-byte descriptor for id 161, then uses byte
 * +0x6e of the shared work to select a table and dispatch its +0xf0 data.
 * The owner handle and returned shared work/table entry must be valid. */
void func_02067c88(u32 *owner)
{
    u8 local[16];
    int value;
    u8 *entry;
    func_020dd910(owner);
    func_02060dd4(local, owner, 0, 0, 8);
    func_02059f70(*owner, 0, 161, 1, local, 0, 10);
    func_02057df8();
    value = Unk02e000_Thunk_0202e788()[110];
    entry = func_020a9e14(2, data_021457d4, value);
    func_020a9fd8(1, (int)(entry + 240), 1, 2, 2, 10, data_021457dc, value);
}

/* At 020674a4, chooses dispatch words from record id/category and sends
 * the caller's descriptor with a signed halfword value through owner +0.
 * Requires a valid owner handle, descriptor and resource-19 id. */
void func_020674a4(u32 *owner, const void *descriptor, u16 id, int arg, s16 value)
{
    const Unk065e88SelectionRecord *r = (const Unk065e88SelectionRecord *)func_020a1428(id);
    if (r->id == 0) func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
    else if (r->category == 4) func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
    else if (r->category == 5) func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
    else func_02057df8();
    func_02059f70(*owner, 0, arg, value, descriptor, 0, 10);
}

/* Partial bounds layout; the two byte tables occupy +4 and +0x44. */
typedef struct Unk065e88SelectionBounds {
    u8 pad[4];
    u8 lower[64];
    u8 upper[64];
    u8 gap[44];
    u16 count;
} Unk065e88SelectionBounds;

/* At 020685b0, clamps rank to the owner's lower table then selects the
 * nearest eligible record of this kind at or above rank. Requires kind < 64
 * and count valid resource records; ties keep the first, no match returns 0. */
u16 func_020685b0(Unk065e88SelectionBounds *owner, u32 kind, u32 rank)
{
    u16 result = 0;
    u8 distance = 255;
    Unk065e88SelectionRecord *r = (Unk065e88SelectionRecord *)func_020a1428(0);
    int i;
    if (rank > owner->lower[kind]) rank = owner->lower[kind];
    for (i = 0; i < owner->count; i++, r++) {
        if (r->kind == kind && r->rank >= rank && (int)(r->rank - rank) < distance && Unk065e88_Unk_068564((Unk065e88Obj24 *)r)) {
            result = i;
            distance = r->rank - rank;
        }
    }
    return result;
}

/* At 02068658, clamps rank to the owner's upper table then selects the
 * nearest eligible record of this kind at or below rank. Requires kind < 64
 * and count valid resource records; ties keep the first, no match returns 0. */
u16 func_02068658(Unk065e88SelectionBounds *owner, u32 kind, u32 rank)
{
    u16 result = 0;
    u8 distance = 255;
    Unk065e88SelectionRecord *r = (Unk065e88SelectionRecord *)func_020a1428(0);
    int i;
    if (rank < owner->upper[kind]) rank = owner->upper[kind];
    for (i = 0; i < owner->count; i++, r++) {
        if (r->kind == kind && r->rank <= rank && (int)(rank - r->rank) < distance && Unk065e88_Unk_068564((Unk065e88Obj24 *)r)) {
            result = i;
            distance = rank - r->rank;
        }
    }
    return result;
}
