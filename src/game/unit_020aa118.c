/*
 * src/game/unit_020aa118.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))


/* 0x90-byte list node allocated by Unk0aa118_Unk_0afb90; the first word
 * links to the next node. The rest of the layout is not known yet. */
typedef struct Unk0aa118Node {
    struct Unk0aa118Node *next;     /* +0x00 */
    u8 pad_0004[0x8c];
} Unk0aa118Node;

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0aa118Work {
    u8 pad_0000[0x4];
    s32 unk_0004;                   /* node count */
    u8 pad_0008[0x10];
    Unk0aa118Node *unk_0018;        /* list head */
    Unk0aa118Node *unk_001c;        /* list tail */
} Unk0aa118Work;

int Unk044904_Unk_04509c();
u8 *Unk0aa118_Unk_0af8d8(int a, u32 id, int c);

void Unk0aa118_Nop_0ae054(void);
u8 *Unk0aa118_Thunk_020af8d8(int a, u32 id, int c);
void Unk0aa118_Unk_0ab454(void);
int Unk0aa118_Unk_0ab4b8(void);

typedef struct Unk0aa118List {
    u32 item[0x20];             /* +0x00 */
    u32 pos;                    /* +0x80 */
    u32 count;                  /* +0x84 */
} Unk0aa118List;

/* Group storage that follows the list in the same outer object; the +0x308
 * count and +0x14 entry stride in func_020aa130 support this layout. */
typedef struct Unk0aa118GroupEntry {
    u8 pad_000[8];
    u32 flags;                  /* +0x08; bit 15 cleared by func_020aa130 */
    u8 pad_00c[8];
} Unk0aa118GroupEntry;

typedef struct Unk0aa118Group {
    Unk0aa118GroupEntry entry[32];  /* +0x000 */
    u32 count;                      /* +0x280 */
} Unk0aa118Group;

/* Outer object: Advance receives a pointer to its leading list. */
typedef struct Unk0aa118Groups {
    Unk0aa118List list;         /* +0x000 */
    Unk0aa118Group group[3];    /* +0x088 */
} Unk0aa118Groups;

void func_02013c68();
void func_020aa130(Unk0aa118Groups *p);

/* zero-fills the 0x814-byte structure at p */
void Unk0aa118_Clear814(void *p)
{
    func_02008848(p, 0, 0x814);
}

/* Orders borrowed item pointers by descending word +0x14, then ascending
 * word +0. The sorting callback passed at 0x020aa224 supports CompareItems. */
int Unk0aa118_CompareItems(u32 **a, u32 **b)
{
    if ((*b)[5] == (*a)[5]) {
        if ((*a)[0] == (*b)[0]) {
            return 0;
        }
        return (*a)[0] > (*b)[0] ? 1 : -1;
    }
    return (*b)[5] > (*a)[5] ? 1 : -1;
}

/* Sorts only the unconsumed entries; +0x80/+0x84 cursor/count accesses and
 * the CompareItems callback at 0x020aa224 support the SortRemaining name.
 * The caller must provide pos <= count <= 32. */
void Unk0aa118_SortRemaining(Unk0aa118List *l)
{
    func_02013c68(&l->item[l->pos], l->count - l->pos, 4, Unk0aa118_CompareItems);
}

/* returns the item at the list cursor, or 0 once the cursor is at/past the end */
u32 Unk0aa118_PeekItem(Unk0aa118List *l)
{
    if (l->pos >= l->count) {
        return 0;
    }
    return l->item[l->pos];
}

/* Advances the cursor, refreshes through func_020aa130, and clamps at count.
 * The +0x80 increment at 0x020aa264 supports Advance; returns 0 at the end. */
int Unk0aa118_Advance(Unk0aa118List *l)
{
    l->pos++;
    /* l is the leading member of a Unk0aa118Groups object */
    func_020aa130((Unk0aa118Groups *)l);
    if (l->pos >= l->count) {
        l->pos = l->count;
        return 0;
    }
    return 1;
}

void func_020aa4f4();
void func_020ae1e8(u32 *p);
extern u8 data_02176b18[];
int Unk044904_Get_data_0215ee98();
int func_020b081c();
int func_0204add4();
void func_0204a7b4();
extern u32 data_0214d2f4[];
extern u8 data_0214d398[];
int func_020152cc();
int func_020491b4();
int func_0205f2e4();
int func_0205f41c();
int func_0204fd18();
int func_0204fdac();
int func_0204fe18();
int Unk09974c_Unk_099d14();
extern u8 data_0214fef8[];
extern u32 data_0214d380[];
int func_0204fde0(int t);
u8 *Unk0aa118_FindRecord(u32 id);
int Unk0aa118_Unk_0af7cc(u32 i);
int Unk0aa118_Unk_0af7f8(u32 a, u32 b);
int Unk0aa118_Unk_0af824(u32 id);
u8 *Unk0aa118_Unk_0af8d8(int a, u32 id, int c);
typedef struct Unk0aa118Ptrs {
    u8 pad_00[0x64];
    u32 *e[10];
} Unk0aa118Ptrs;
/* Requests (2, 0, 0, 0), then passes the global work area to func_020ae1e8;
 * the callees' larger purpose is not established. No arguments are retained. */
void Unk0aa118_Unk_0ab34c(void)
{
    func_020aa4f4(2, 0, 0, 0);
    func_020ae1e8((u32 *)data_02176b18);
}

/* empty callback */
void Unk0aa118_Nop_0ae054(void) { }

/* forwards to `Unk0aa118_Unk_0af8d8` */
u8 *Unk0aa118_Thunk_020af8d8(int a, u32 id, int c) { return Unk0aa118_Unk_0af8d8(a, id, c); }

/* clears the +0x18 word of the object returned by Unk044904_Unk_04509c */
void Unk0aa118_Unk_0ab454(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  *(u32 *)(value + 0x18) = 0;
}

/* Appends x to the Unk044904_Unk_04509c id array when absent; the array
 * holds at most 6 ids, with the count word at +0x18. */
void Unk0aa118_AddUniqueId(u32 x)
{
    u32 *t = (u32 *)Unk044904_Unk_04509c();
    s32 j;
    s32 n = t[6];
    if (n >= 6) {
        return;
    }
    for (j = 0; j < n; j++) {
        if (x == t[j]) {
            return;
        }
    }
    t[n] = x;
    t[6]++;
}

/* returns non-zero when the +0x18 word of the Unk044904_Unk_04509c object is set */
int Unk0aa118_Unk_0ab4b8(void)
{
  int value;
  value = Unk044904_Unk_04509c();
  return *(int *)(value + 0x18) != 0;
}

int func_02044ec4(int id);
int func_02049aec(int obj, int mask, int set);

/* looks up the record for id a and applies bit b (masked to 8 bits) with set=1 */
int func_020ab4d4(int a, int b)
{
    int v = func_02044ec4(a);
    return func_02049aec(v, (1 << b) & 255, 1);
}


int func_02008848();
int func_02052fe0();
/* Allocates and zeroes 0x94 bytes, then stores arg0 in the first word.
 * Returns the allocated work area; allocation failure is handled by the allocator. */
u32 * Unk0aa118_Unk_0afb64(u32 arg0)
{
  u32 *v1;
  v1 = (u32 *)func_02052fe0(0x94);
  func_02008848(v1,0,0x94);
  *v1 = arg0;
  return v1;
}


/* Returns borrowed table storage selected by the first two bytes of the
 * matching record; a missing id selects table (0, 0). */
int Unk0aa118_Unk_0af824(u32 id)
{
    u8 *v = Unk0aa118_FindRecord(id);
    if (v != 0) {
        return func_0204fde0(Unk0aa118_Unk_0af7f8(v[0], v[1]));
    }
    return func_0204fde0(Unk0aa118_Unk_0af7f8(0, 0));
}



/* Allocates and zeroes a 0x90-byte node, appends it to the +0x18/+0x1c
 * head/tail list, increments the +4 count and returns the node. */
Unk0aa118Node *Unk0aa118_Unk_0afb90(Unk0aa118Work *w)
{
  Unk0aa118Node *node;
  node = (Unk0aa118Node *)func_02052fe0(0x90);
  func_02008848(node,0,0x90);
  if (w->unk_0018 == 0) {
    w->unk_0018 = node;
  }
  else {
    w->unk_001c->next = node;
  }
  w->unk_001c = node;
  w->unk_0004 = w->unk_0004 + 1;
  return node;
}

int func_0204a0e8();
int func_0204a244();
int func_020b0310();
/* Returns 1 when mode == 3. Otherwise returns 0 for records whose
 * func_0204a244 kind is 2 and that pass func_0204a0e8(record, 400), and
 * forwards everything else to func_020b0310(a, b, record). */
u32 Unk0aa118_Unk_0ab4f4(u32 a, u32 b, u32 record, int mode)
{
  if (mode == 3) {
    return 1;
  }
  if (func_0204a244(record) == 2 && func_0204a0e8(record, 400) != 0) {
    return 0;
  }
  return func_020b0310(a, b, record);
}

int func_0204abd8();
int func_0204f108();
int func_0209fd64();
int func_020ab62c();
void Unk0aa118_Unk_0ab8f8(u32 p);
int func_020af9f4(int category, u32 id, int reverse);
void func_020afbdc(Unk0aa118Work *w);
int Unk0afc28_Unk_0b0930();
int Unk0caea8_GetInRange();
/* Sets bit 3 at p+8 when global +0x40 bit 11 and query 2 are both set.
 * p must address writable work storage containing that word. */
void Unk0aa118_Unk_0ab8f8(u32 p)
{
    u32 v = FIELD(u32, Unk044904_Get_data_0215ee98(), 64);
    if (((v << 20) >> 31) == 0) {
        return;
    }
    if (func_020b081c(2) != 0) {
        FIELD(u32, p, 8) |= 8;
    }
}

/* Returns byte +58, +59, or +60 for id classifications 4, 1, or 5,
 * respectively; other classifications return zero. p must contain these bytes. */
u8 Unk0aa118_Unk_0ab930(u8 *p, u32 id)
{
    switch (func_0204add4(id)) {
    case 4:
        return p[58];
    case 1:
        return p[59];
    case 5:
        return p[60];
    }
    return 0;
}

/* Visits the ten global pointers at +0x64 and requests operation 2 for
 * non-null entries whose first word has a nonzero byte at bits 16..23. */
void Unk0aa118_Unk_0acb28(void)
{
    Unk0aa118Ptrs *g = (Unk0aa118Ptrs *)Unk044904_Get_data_0215ee98();
    int j;
    for (j = 0; j < 10; j++) {
        u32 *e = g->e[j];
        if (e != 0 && ((e[0] >> 16) & 0xff) != 0) {
            func_0204a7b4(e, 2);
        }
    }
}

/* decompiler-derived */
void Unk0aa118_Unk_0acb74(u32 arg0,u32 arg1,u32 arg2)
{
  u32 *v1;
  int tmp2;
  u32 tmp3;
  int tmp4;
  u32 tmp5;
  v1 = (u32 *)func_02044ec4(arg2);
  tmp2 = func_0204abd8(v1,0);
  if (tmp2 == 0) {
    tmp2 = Unk0caea8_GetInRange(arg1);
    if (tmp2 != 0) {
      func_0204f108(0,0x20,tmp2,0);
    }
    tmp2 = (int)Unk0aa118_Unk_0afb64(arg0);
    tmp5 = arg0 >> 0x10 & 0xff;
    if (tmp5 == 1) {
      tmp3 = 2;
    }
    else if (tmp5 == 2) {
      tmp3 = 1;
    }
    else {
      tmp3 = 0;
    }
    tmp3 = func_020af9f4(tmp3,arg1,0);
    *(u32 *)(tmp2 + 0x10) = tmp3;
    if (tmp5 == 1) {
      tmp3 = 2;
    }
    else if (tmp5 == 2) {
      tmp3 = 1;
    }
    else {
      tmp3 = 0;
    }
    tmp3 = func_020af9f4(tmp3,arg1,1);
    *(u32 *)(tmp2 + 0x14) = tmp3;
    *(u32 *)(tmp2 + 8) = *(u32 *)(tmp2 + 8) | 0x10;
    tmp4 = (int)Unk0aa118_Unk_0afb90((Unk0aa118Work *)tmp2);
    *(u32 *)(tmp4 + 0x84) = *(u32 *)(tmp4 + 0x84) & 0xffffff00 | 4;
    *(u32 *)(tmp4 + 4) = *v1;
    Unk0afc28_Unk_0b0930(tmp4 + 100,arg0,0,1);
    func_020ab62c(tmp4,arg0,0xffffffff);
    *(u32 *)(tmp4 + 0x84) = *(u32 *)(tmp4 + 0x84) | 0x1000;
    Unk0aa118_Unk_0ab8f8(tmp2);
    func_0209fd64(tmp2);
    func_020afbdc((Unk0aa118Work *)tmp2);
    return;
  }
}

/* Reads data_0214d2f4 with one-based i and a three-word group offset
 * for k == 2 or 3. The literal table access supports GetTableD2f4; the
 * caller must supply an index within the table. Other k values use group 0. */
u32 Unk0aa118_GetTableD2f4(int k, int i)
{
    int b = 0;
    switch (k) {
    case 1:
        break;
    case 2:
        b = 3;
        break;
    case 3:
        b = 6;
        break;
    }
    return data_0214d2f4[b + (i - 1)];
}

/* Searches 326 records of 34 bytes by comparing id with each record +2
 * through func_020152cc, supporting FindRecord. Returns borrowed
 * storage for the first match, or null when absent. */
u8 *Unk0aa118_FindRecord(u32 id)
{
    u8 *e = data_0214d398;
    u32 j;
    for (j = 0; j < 0x146; j++, e += 34) {
        if (func_020152cc(id, e + 2) == 0) {
            return e;
        }
    }
    return 0;
}

/* Resolves the table selected by i; an out-of-range unsigned index uses 0.
 * The returned handle is passed unchanged to the next table lookup. */
int Unk0aa118_Unk_0af7cc(u32 i)
{
    int t = func_020491b4(i);
    if (i >= (u32)func_0205f2e4(t)) {
        i = 0;
    }
    return func_0205f41c(t, i);
}

/* Resolves table a, then selects entry b, using entry 0 when b is out of range.
 * Both indices use the unsigned bounds observed in the original. */
int Unk0aa118_Unk_0af7f8(u32 a, u32 b)
{
    int t = Unk0aa118_Unk_0af7cc(a);
    if (b >= (u32)func_0204fd18(t)) {
        b = 0;
    }
    return func_0204fdac(t, b);
}

/* Returns one of two 412-byte regions in the table for id. a == 1 selects
 * the second region; any nonzero c reverses the selection. Storage is borrowed. */
u8 *Unk0aa118_Unk_0af8d8(int a, u32 id, int c)
{
    u8 *base = (u8 *)Unk0aa118_Unk_0af824(id);
    int k = 0;
    if (a == 1) {
        k = 1;
    }
    if (c != 0) {
        k = 1 - k;
    }
    return base + k * 412;
}

/* Looks up id through Unk09974c_Unk_099d14; returns 0 when absent or when
 * func_020152cc(e, data_0214fef8) reports a match failure, otherwise forwards
 * to Unk0aa118_Unk_0af8d8. */
u8 *Unk0aa118_Unk_0afa60(int a, u32 id, int c)
{
    u32 e = Unk09974c_Unk_099d14(id);
    if (e != 0) {
        if (func_020152cc(e, data_0214fef8) == 0) {
            return 0;
        }
        return Unk0aa118_Unk_0af8d8(a, e, c);
    }
    return 0;
}

/* Returns borrowed 22-byte entries from table (39, 0); byte 2 of x equal
 * to 1 selects the second half, using the unsigned entry count divided by 2. */
u8 *Unk0aa118_Unk_0afab0(u32 x)
{
    int t = Unk0aa118_Unk_0af7f8(39, 0);
    int k = 0;
    u8 *base = (u8 *)func_0204fde0(t);
    u32 n = func_0204fe18(t);
    if (((x >> 16) & 0xff) == 1) {
        k += n >> 1;
    }
    return base + k * 22;
}

/* Returns borrowed 22-byte entries from table (0, 0); byte 2 of x equal
 * to 1 selects the second half, using the unsigned entry count divided by 2. */
u8 *Unk0aa118_Unk_0afaf8(u32 x)
{
    int t = Unk0aa118_Unk_0af7f8(0, 0);
    int k = 0;
    u8 *base = (u8 *)func_0204fde0(t);
    u32 n = func_0204fe18(t);
    if (((x >> 16) & 0xff) == 1) {
        k += n >> 1;
    }
    return base + k * 22;
}

/* returns the table base for record id data_0214d380[i], or 0 for i == 0 */
int Unk0aa118_Unk_0afb40(int i)
{
    if (i == 0) {
        return 0;
    }
    return Unk0aa118_Unk_0af824(data_0214d380[i]);
}

/* Clears bit 15 of word +8 on every entry of the three 32-entry groups.
 * Group k starts at +0x88 + k*0x284; its count word follows the entries.
 * The +0x308 count and +0x14 entry stride support this layout. */
void func_020aa130(Unk0aa118Groups *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        u32 count = p->group[i].count;
        Unk0aa118GroupEntry *e = p->group[i].entry;
        u32 j;
        for (j = 0; j < count; j++, e++) {
            e->flags &= ~0x8000;
        }
    }
}

/* Adds the borrowed entry pointer v to the list when absent, unless the
 * 32-entry list is full. The +0x84 count and capacity check at 0x020aa188
 * support this contract; returns 1 when added (or already present) and 0
 * when full. The pointer parameter matches the caller at 0x020efdf4. */
int func_020aa188(Unk0aa118List *l, void *v)
{
    u32 i;
    if (l->count >= 32) {
        return 0;
    }
    for (i = 0; i < l->count; i++) {
        if ((void *)l->item[i] == v) {
            return 1;
        }
    }
    l->item[l->count] = (u32)v;
    l->count++;
    Unk0aa118_SortRemaining(l);
    return 1;
}

void func_02053000(void *p);

/* Frees each node of the +0x18 list up to and including the +0x1c tail (or
 * until a null link), decrementing the +4 count, then frees the owner. */
void func_020afbdc(Unk0aa118Work *w)
{
    Unk0aa118Node *node = w->unk_0018;
    while (node != 0) {
        Unk0aa118Node *current = node;
        node = node->next;
        func_02053000(current);
        w->unk_0004--;
        if (current == w->unk_001c || node == 0) {
            break;
        }
    }
    func_02053000(w);
}

extern u8 data_0214d318[], data_0214fee4[], data_0214fef0[];
void func_0204f158(int a, int b, int c, int d);
void func_0204f0d4(void);
void func_0204f728(int a, u32 b, int c);
void func_0204f758(int a, u32 b);
u32 func_020cb1a0(u32 id);
u32 func_020cb21c(u32 id);
int func_020afe64(u32 count);
int Unk044904_Unk_045460(int mode);
int Unk044904_Unk_045010(void);
int Unk044904_Unk_04599c(int value);
void Unk09ee4c_Unk_09fd14(u32 id, u8 *table);
int Unk09974c_Unk_099bac(u32 id);
int Unk0caea8_Unk_0cb044(u32 id);

void func_020ae058(u32 id);

/* Rejects global bit 2 or a failed counter query, otherwise submits id.
 * A zero bypass increments the global 16-bit counter even when rejected. */
int func_020ae0d8(u32 id, int bypass, int unused)
{
    if ((FIELD(u32, Unk044904_Get_data_0215ee98(), 64) << 29) >> 31) {
        func_0204f158(0, 32, 6, 0);
        return 0;
    }
    if (bypass == 0) {
        u8 *g = (u8 *)Unk044904_Get_data_0215ee98();
        int result = func_020afe64(FIELD(u16, g, 58));
        FIELD(u16, g, 58)++;
        if (result == 0) {
            func_0204f158(0, 32, 5, 0);
            return 0;
        }
    }
    func_020ae058(id);
    return 1;
}

/* For category 1, submits the leading id with a global-state bypass;
 * other categories submit request 8 directly. p must contain its id word. */
void func_020ae16c(u32 *p)
{
    if (((p[0] >> 16) & 255) == 1) {
        int bypass;
        if (Unk044904_Unk_045460(1) != 0 &&
            FIELD(u16, Unk044904_Get_data_0215ee98(), 56) == 0) {
            bypass = 1;
        } else {
            bypass = 0;
        }
        func_020ae0d8(p[0], bypass, 0);
    } else {
        func_0204f158(0, 32, 8, 0);
        func_0204f728(0, p[0], 8);
    }
}

/* Builds and processes a temporary node list from eight-byte records.
 * The second word equal to UINT_MAX terminates the borrowed input array. */
void func_020ae1e8(u32 *p)
{
    u32 *w = Unk0aa118_Unk_0afb64(p[0]);
    w[4] = (u32)Unk0aa118_Unk_0af8d8(2, (u32)data_0214d318, 0);
    w[2] &= ~16;
    while (p[1] != ~0U) {
        Unk0aa118Node *node = Unk0aa118_Unk_0afb90((Unk0aa118Work *)w);
        FIELD(u32, node, 4) = p[0];
        p += 2;
        FIELD(u32, node, 132) = (FIELD(u32, node, 132) & ~255) | 2;
    }
    func_0209fd64(w);
    func_020afbdc((Unk0aa118Work *)w);
}

/* Resolves a table using the category byte of p's id, processes it, then
 * chooses request 16 or fallback request 17 from the global query. */
void func_020ae270(u32 id, u32 *p)
{
    u8 *table = Unk0aa118_Thunk_020af8d8((p[0] >> 16) & 255, id, 0);
    Unk09ee4c_Unk_09fd14(p[0], table);
    func_0204f0d4();
    if (Unk044904_Unk_04599c(Unk044904_Unk_045010()) != 0) {
        func_0204f758(16, p[0]);
    } else {
        func_0204f158(0, 60, 17, 0);
    }
}

/* Returns a borrowed six-byte table entry for group 1..3 and one-based
 * index; other groups return the base, and a missing record returns null. */
u8 *func_020af85c(int group, int index)
{
    u8 *record = Unk0aa118_FindRecord((u32)data_0214fee4);
    if (record != 0) {
        u8 *base = (u8 *)func_0204fde0(Unk0aa118_Unk_0af7f8(record[0], record[1]));
        switch (group) {
        case 1: return base + (index - 1) * 6;
        case 2: return base + (index + 2) * 6;
        case 3: base += (index + 5) * 6; break;
        }
        return base;
    }
    return 0;
}

/* Tries two id resolvers in order, then returns borrowed table storage;
 * data_0214fef0 supplies the fallback id when both resolvers return zero. */
int func_020af9f4(int category, u32 id, int reverse)
{
    u32 resolved = 0;
    u32 found = func_020cb1a0(id);
    if (found != 0) {
        resolved = found;
    } else {
        found = func_020cb21c(id);
        if (found != 0) {
            resolved = found;
        }
    }
    if (resolved != 0) {
        return (int)Unk0aa118_Unk_0af8d8(category, resolved, reverse);
    }
    return (int)Unk0aa118_Unk_0af8d8(category, (u32)data_0214fef0, reverse);
}

/* Dispatches kinds 5 and 6 through separate id resolvers to request 32.
 * The borrowed four-word record holds kind at +8 and id at +12. */
void func_020ab2c8(u32 *p)
{
    switch (p[2]) {
    case 0: break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 10: return;
    case 5: func_0204f108(0, 32, Unk09974c_Unk_099bac(p[3]), 0); break;
    case 6: func_0204f108(0, 32, Unk0caea8_Unk_0cb044(p[3]), 0); break;
    case 8: break;
    case 9: break;
    }
}
