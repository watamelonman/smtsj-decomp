#include "types.h"

#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Borrowed record view; the subtraction routines require a readable first halfword. */
typedef struct Unk09974cRecord {
    u16 unk_00;
} Unk09974cRecord;

/* Borrowed record view for the halfword loaded at +0x20. */
typedef struct Unk09974cRecord20 {
    u8 padding_00[0x20];
    u16 unk_20;
} Unk09974cRecord20;

/* Range-table entry: FindEntry tests the inclusive bounds and returns this view. */
typedef struct Unk09974cEntry {
    s32 lo;
    s32 hi;
    u8 unk_0008;
    u8 unk_0009;
    u8 padding_0a[2];
} Unk09974cEntry;

extern Unk09974cEntry *Unk09974c_FindEntry(int id);
extern s32 func_0209993c(u32 id);

/* Subtract unsigned halfwords at +0; evidence: loads at 0x02099860/64. */
s32 Unk09974c_Unk_099860(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x02099870/74. */
s32 Unk09974c_Unk_099870(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0x20; evidence: loads at 0x02099880/84. */
s32 Unk09974c_Unk_099880(const Unk09974cRecord20 *left, const Unk09974cRecord20 *right)
{
    return left->unk_20 - right->unk_20;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x02099890/94. */
s32 Unk09974c_Unk_099890(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x020998a0/a4. */
s32 Unk09974c_Unk_0998a0(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Subtract unsigned halfwords at +0; evidence: loads at 0x020998b0/b4. */
s32 Unk09974c_Unk_0998b0(const Unk09974cRecord *left, const Unk09974cRecord *right)
{
    return left->unk_00 - right->unk_00;
}

/* Return entry byte +8, or zero for an absent id (0x020998c4..d0). */
u32 Unk09974c_GetEntryUnk08(u32 id)
{
    Unk09974cEntry *entry = Unk09974c_FindEntry(id);
    return entry != 0 ? entry->unk_0008 : 0;
}

/* Return whether the helper result is signed-positive (0x020998dc..e8). */
s32 Unk09974c_Unk_0998d8(u32 id)
{
    return func_0209993c(id) > 0;
}

void *func_020445f4(int index, int item);
void *func_0204fed8(void *resource, int id);

/* Resolve a nonzero id in resource (6, 0); evidence: 0x02099bbc..bcc.
 * Zero is the absent-id sentinel and returns a null borrowed pointer. */
void *Unk09974c_Unk_099bac(int id)
{
    if (id != 0) {
        void *resource = func_020445f4(6, 0);
        return func_0204fed8(resource, id);
    }
    return 0;
}

/* Resolve a nonzero id in resource (7, 0); evidence: 0x02099be4..bf4.
 * The returned pointer is borrowed; zero ids return null. */
void *Unk09974c_Unk_099bd4(int id)
{
    if (id != 0) {
        void *resource = func_020445f4(7, 0);
        return func_0204fed8(resource, id);
    }
    return 0;
}

/* Caller-owned 0x48-byte area; only the observed live marker and handle
 * are interpreted. Other bytes are cleared along with these fields. */
typedef struct Unk09974cWork {
    u32 live;
    u8 padding_04[12];
    void *handle;
    u8 padding_14[0x34];
} Unk09974cWork;

void func_02008848(void *dest, int value, u32 size);
void func_020629c4(void *handle);

/* Release the +0x10 handle and clear a live area; evidence: 0x02099754..778.
 * A zero live marker leaves the caller-owned 0x48 bytes untouched. */
void Unk09974c_Unk_09974c(Unk09974cWork *work)
{
    if (work->live == 0) {
        return;
    }
    func_020629c4(work->handle);
    work->handle = 0;
    func_02008848(work, 0, 0x48);
}




int Unk02e000_GetSubBlock3a4();
extern u8 data_0213bdec[];
void *Unk09974c_Unk_099d14(int id);
void *Unk09974c_Unk_099bfc(int id);
typedef struct Unk09974cStat {
    u8 pad_0000[0x4];
    u32 unk_04 : 10;
    u32 unk_04_rest : 22;
    u8 pad_0008[0x6];
    u16 unk_0e;
} Unk09974cStat;

/* Borrowed record prefix: byte +0x2a holds a seven-bit kind. */
typedef struct Unk09974cKind {
    u8 pad_0000[0x2a];
    u8 kind : 7;
    u8 kind_hi : 1;
} Unk09974cKind;
/* Scan ten signed inclusive ranges; evidence: 0x02099780..7c0.
 * Returns a borrowed table entry, or null when no range contains id. */
Unk09974cEntry *Unk09974c_FindEntry(int id)
{
    Unk09974cEntry *t = (Unk09974cEntry *)data_0213bdec;
    u32 j;
    for (j = 0; j < 10; j++) {
        if (t[j].lo <= id && id <= t[j].hi) {
            return &((Unk09974cEntry *)data_0213bdec)[j];
        }
    }
    return 0;
}

/* Select a borrowed subblock slice for categories 0..9; offsets are evidenced
 * by the switch at 0x020997d4..985c. Other categories return zero. */
int Unk09974c_Unk_0997c8(u32 arg0)
{
  int value;
  value = Unk02e000_GetSubBlock3a4();
  switch(arg0) {
  case 0:
    return value;
  case 1:
    return value + 0xf;
  case 2:
    return value + 0x4b;
  case 3:
    return value + 0x58;
  case 4:
    return value + 0x8a;
  case 5:
    return value + 0xbc;
  case 6:
    return value + 0xee;
  case 7:
    return value + 0x120;
  case 8:
    return value + 0x4f4;
  case 9:
    return value + 0x5d0;
  default:
    return 0;
  }
}

/* Borrowed record prefix: halfword +4 contains the four-bit field at 8..11. */
typedef struct Unk09974cFlags {
    u8 pad_0000[0x4];
    u16 unk_04_lo : 8;          /* +0x04 */
    u16 unk_04_mid : 4;         /* +0x04 bits 8..11 */
    u16 unk_04_hi : 4;
} Unk09974cFlags;

/* Require a nonzero helper result, and at least 99 for entry mode 1;
 * evidence: byte +9 and signed comparison at 0x0209991c..934. */
int Unk09974c_Unk_0998f0(int id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    int n;
    if (e == 0) {
        return 0;
    }
    n = func_0209993c(id);
    if (n == 0) {
        return 0;
    }
    if (e->unk_0009 == 1 && n < 99) {
        return 0;
    }
    return 1;
}

typedef struct Unk09974cRec8 {
    u16 id;
    u8 pad_02[3];
    u8 unk_05;
    u8 pad_06[2];
} Unk09974cRec8;
typedef struct Unk09974cRec16 {
    u16 id;
    u8 pad_02[14];
} Unk09974cRec16;
typedef struct Unk09974cRec56 {
    u8 pad_00[32];
    u16 id;
    u8 pad_22[22];
} Unk09974cRec56;
typedef struct Unk09974cRec80 {
    u16 id;
    u8 unk_02;
    u8 pad_03[20];
    u8 f0 : 1;                  /* +0x17 */
    u8 f1 : 1;
    u8 f2 : 1;
    u8 : 5;
    u8 pad_18[56];
} Unk09974cRec80;
void *func_020445d0();
void *func_0204fde0();
int func_0204fe18();
void *func_02011810();

void Unk09974c_SetBit6ac(int id);

/* Read the indexed halfword only for entry mode 2; evidence: 0x02099a04..a24.
 * Missing entries and other modes return zero; storage is borrowed. */
u32 Unk09974c_Unk_0999d4(int id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u16 *buf;
    int off;
    if (e == 0) {
        return 0;
    }
    buf = (u16 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0:
    case 1:
        break;
    case 2:
        return buf[off];
    }
    return 0;
}

/* Store a nonzero halfword for mode 2 and mark the id bit for any present
 * entry; evidence: 0x02099acc..b0c. The selected buffer must be writable. */
void Unk09974c_Unk_099abc(int id, u16 v)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u16 *buf;
    int off;
    if (e == 0 || v == 0) {
        return;
    }
    buf = (u16 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0:
    case 1:
        break;
    case 2:
        buf[off] = v;
        break;
    }
    Unk09974c_SetBit6ac(id);
}

/* Search resource (5, 0) using the id's low halfword at record +0;
 * evidence: 0x020099bfc passes stride 8 and comparator 099860 to 02011810.
 * Returns a borrowed record, or null for an absent resource or search miss. */
void *Unk09974c_Unk_099bfc(int id)
{
    Unk09974cRec8 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 0);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 8, Unk09974c_Unk_099860);
}

/* Search resource (5, 2) using the id's low halfword at record +0;
 * evidence: 0x020099c60 passes stride 80 and comparator 099870 to 02011810.
 * Returns a borrowed record, or null for an absent resource or search miss. */
void *Unk09974c_Unk_099c60(int id)
{
    Unk09974cRec80 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 2);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 80, Unk09974c_Unk_099870);
}

/* Scale the ten-bit field at +4 by unsigned percent +0x0e, rounding down
 * with minimum 1 when both are nonzero; evidence: 0x02099cc4..d10. */
s32 Unk09974c_Unk_099cc4(Unk09974cStat *p)
{
    u32 v = p->unk_04;
    u32 r;
    s32 q;
    if (v == 0) {
        return 0;
    }
    r = p->unk_0e;
    if (r == 0) {
        return 0;
    }
    if (r == 100) {
        return v;
    }
    q = (v * r) / 100;
    if (q <= 0) {
        q = 1;
    }
    return q;
}

/* Search resource (5, 1) using the id's low halfword at record +32;
 * evidence: 0x020099d14 passes stride 56 and comparator 099880 to 02011810.
 * Returns a borrowed record, or null for an absent resource or search miss. */
void *Unk09974c_Unk_099d14(int id)
{
    Unk09974cRec56 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 1);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 56, Unk09974c_Unk_099880);
}

/* Search resource (5, 3) using the id's low halfword at record +0;
 * evidence: 0x020099d78 passes stride 16 and comparator 099890 to 02011810.
 * Returns a borrowed record, or null for an absent resource or search miss. */
void *Unk09974c_Unk_099d78(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 3);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_099890);
}

/* Search resource (5, 4) using the id's low halfword at record +0;
 * evidence: 0x020099ddc passes stride 16 and comparator 0998a0 to 02011810.
 * Returns a borrowed record, or null for an absent resource or search miss. */
void *Unk09974c_Unk_099ddc(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 4);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_0998a0);
}

int Unk02ee5c_GetTierFromField70();
void *Unk02e000_Thunk_0202e788();
int func_0209a158(int id);

/* Search resource (5, 5) using the id's low halfword at record +0;
 * evidence: 0x020099e40 passes stride 16 and comparator 0998b0 to 02011810.
 * Returns a borrowed record, or null for an absent resource or search miss. */
void *Unk09974c_Unk_099e40(int id)
{
    Unk09974cRec16 key;
    void *base;
    int n;
    void *tab = func_020445d0(5, 5);
    if (tab == 0) {
        return 0;
    }
    base = func_0204fde0(tab);
    n = func_0204fe18(tab);
    key.id = id;
    return func_02011810(&key, base, n, 16, Unk09974c_Unk_0998b0);
}

/* Accept record +0x17 bits 0/2/1 for tiers 4/5/1 respectively;
 * evidence: 0x02099ea4..9f20. Missing borrowed records return zero. */
int Unk09974c_Unk_099ea4(int id)
{
    int tier = Unk02ee5c_GetTierFromField70();
    Unk09974cRec80 *r = (Unk09974cRec80 *)Unk09974c_Unk_099c60(id);
    if (r == 0) {
        return 0;
    }
    if (r->f0 && tier == 4) {
        return 1;
    }
    if (r->f2 && tier == 5) {
        return 1;
    }
    if (r->f1 && tier == 1) {
        return 1;
    }
    return 0;
}

/* For an id accepted by 099ea4, store its low halfword in subblock slot
 * 0..3 selected by record byte +2 values 3..6; evidence: 0x02099f24..f78.
 * Accepted ids require a present record and a writable four-halfword subblock. */
void Unk09974c_Unk_099f24(int id)
{
    u16 *w;
    Unk09974cRec80 *r;
    if (Unk09974c_Unk_099ea4(id) == 0) {
        return;
    }
    w = (u16 *)Unk02e000_Thunk_0202e788();
    r = (Unk09974cRec80 *)Unk09974c_Unk_099c60(id);
    if (r->unk_02 == 3) {
        w[0] = id;
    }
    if (r->unk_02 == 4) {
        w[1] = id;
    }
    if (r->unk_02 == 5) {
        w[2] = id;
    }
    if (r->unk_02 == 6) {
        w[3] = id;
    }
}

/* Test byte +0x2d for ids 51..110; evidence: 0x0209a094..a0b4.
 * In-range ids require a present record from Unk09974c_Unk_099d14. */
int Unk09974c_Unk_09a090(int id)
{
    if (id >= 51 && id <= 110) {
        u8 v = ((u8 *)Unk09974c_Unk_099d14(id))[45];
        if (v != 0) {
            return 1;
        }
    }
    return 0;
}

/* Accept record byte +0x2d values 1 or 3 for ids 51..110; evidence:
 * 0x0209a0c0..aec. In-range ids require a present borrowed record. */
int Unk09974c_Unk_09a0c0(int id)
{
    if (id >= 51 && id <= 110) {
        u8 v = ((u8 *)Unk09974c_Unk_099d14(id))[45];
        if (v == 1 || v == 3) {
            return 1;
        }
    }
    return 0;
}

/* Test kinds 14 and 1 in byte +0x2a bits 0..6; evidence: 0x0209a0f4..a108. */
int Unk09974c_IsKind1or14(Unk09974cKind *p)
{
    u32 v = p->kind;
    return v == 14 || v == 1;
}

/* Test halfword +4 bits 8..11; the shifts at 0x0209a118/11c support the name. */
int Unk09974c_HasFlagsMid(Unk09974cFlags *f)
{
    return f->unk_04_mid != 0;
}

/* Decode halfword +4 bits 8..11 to 0..14, or -1 when absent.
 * Evidence for the name: HasFlagsMid call and subtraction at 0x0209a14c. */
int Unk09974c_GetFlagsMidMinus1(Unk09974cFlags *f)
{
    if (Unk09974c_HasFlagsMid(f) == 0) {
        return -1;
    }
    return f->unk_04_mid - 1;
}

/* Test the same subblock +0x6ac bit as SetBit6ac, returning 0 or 1;
 * evidence: 0x0209a158..19c. Callers must supply id >= 51; indices >= 162
 * return zero. The subblock pointer is borrowed. */
int func_0209a158(int id)
{
    u8 *b = (u8 *)Unk02e000_GetSubBlock3a4();
    s32 k = id - 51;
    s32 i = k >> 3;
    if (i < 162) {
        u8 value = (b + i)[0x6ac];
        u8 mask = (u8)(1 << (k & 7));
        return (value & mask) != 0;
    }
    return 0;
}

/* Set the id-minus-51 bit in subblock +0x6ac; evidence: 0x0209a1a0..1e0.
 * Existing symbol is the card's SetSeenBit; the bit's gameplay meaning is unproven.
 * Callers must supply id >= 51; byte indices >= 162 are ignored. */
void Unk09974c_SetBit6ac(int id)
{
    u8 *b = (u8 *)Unk02e000_GetSubBlock3a4();
    s32 k = id - 51;
    s32 i = k >> 3;
    u8 *f;
    if (i >= 162) {
        return;
    }
    f = b + 684 + 1024;
    f[i] |= (u8)(1 << (k & 7));
}

/* Return zero for an already-set 6ac bit, else category 0's record byte +5,
 * one for categories 8/9, or zero; evidence: 0x0209a1e4..a238.
 * Requires id >=51 for the bit test and a present record for category zero. */
int Unk09974c_Unk_09a1e4(int id)
{
    if (func_0209a158(id) != 0) {
        return 0;
    }
    switch (Unk09974c_GetEntryUnk08(id)) {
    case 0:
        return ((Unk09974cRec8 *)Unk09974c_Unk_099bfc(id))->unk_05;
    case 8:
    case 9:
        return 1;
    }
    return 0;
}

/* Return record byte +5 only for entry category zero; evidence: the category
 * test and record load at 0x0209a244..a258. The lookup must return a record. */
int func_0209a23c(int id)
{
    switch (Unk09974c_GetEntryUnk08(id)) {
    case 0:
        return ((Unk09974cRec8 *)Unk09974c_Unk_099bfc(id))->unk_05;
    }
    return 0;
}

/* Read mode 0's bit, mode 1's byte, or mode 2's presence flag;
 * evidence: 0x0209993c..99d0. Missing entries return zero. */
s32 func_0209993c(u32 id)
{
    Unk09974cEntry *e = Unk09974c_FindEntry(id);
    u8 *buf;
    int off;
    if (e == 0) return 0;
    buf = (u8 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0: {
        u32 byte = buf[off / 8];
        return (byte & (1 << (off % 8))) != 0;
    }
    case 1: return buf[off];
    case 2: return ((u16 *)buf)[off] != 0;
    }
    return 0;
}

/* Set a mode-0 bit or add to a mode-1 byte with a cap of 99, then mark
 * the id bit; evidence: 0x02099a28..9ab8. Storage must be writable. */
void func_02099a28(int id, u32 amount)
{
    Unk09974cEntry *e;
    u8 *buf;
    int off;
    if (amount == 0) return;
    e = Unk09974c_FindEntry(id);
    if (e == 0) return;
    buf = (u8 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0: buf[off / 8] |= 1 << (off % 8); break;
    case 1: {
        u32 sum = buf[off];
        sum += amount;
        if (sum >= 99) buf[off] = 99;
        else buf[off] = sum;
        break;
    }
    case 2: break;
    }
    Unk09974c_SetBit6ac(id);
}

/* Clear a mode-0 bit or mode-2 halfword, or subtract with a zero floor
 * from a mode-1 byte; evidence: 0x02099b10..9ba8. Storage is borrowed. */
void func_02099b10(int id, u32 amount)
{
    Unk09974cEntry *e;
    u8 *buf;
    int off;
    if (amount == 0) return;
    e = Unk09974c_FindEntry(id);
    if (e == 0) return;
    buf = (u8 *)Unk09974c_Unk_0997c8(e->unk_0008);
    off = id - e->lo;
    switch (e->unk_0009) {
    case 0: buf[off / 8] &= ~(1 << (off % 8)); break;
    case 1:
        if (buf[off] < amount) buf[off] = 0;
        else buf[off] -= amount;
        break;
    case 2: ((u16 *)buf)[off] = 0; break;
    }
}

/* Source halfword view: signed ten-bit adjustment and signed six-bit kind;
 * evidence: sign-extending shifts at 0x02099ff0 and 0x0209a038. */
typedef struct Unk09974cPackedSource {
    s16 value : 10;
    s16 kind : 6;
} Unk09974cPackedSource;

/* Unsigned packed output preserves the ten-bit value when replacing its kind. */
typedef struct Unk09974cPackedDest {
    u16 value : 10;
    u16 kind : 6;
} Unk09974cPackedDest;

/* Borrowed input prefix containing two optional resource ids at +4 and +6. */
typedef struct Unk09974cPair {
    u8 pad_00[4];
    u16 ids[2];
} Unk09974cPair;

/* Borrowed resource prefix followed by 19 signed packed adjustments. */
typedef struct Unk09974cAdjustments {
    u8 pad_00[24];
    Unk09974cPackedSource slots[19];
} Unk09974cAdjustments;

int Unk02f078_IsAllowed_02f190(int current, int candidate);

/* Combine two optional resource records into 19 caller-owned packed slots;
 * evidence and field contracts are given by the views above (0x02099f7c). */
void func_02099f7c(const Unk09974cPair *input, Unk09974cPackedDest *dest)
{
    Unk09974cAdjustments *records[2] = {0, 0};
    int i;
    if (input->ids[0] != 0) records[0] = Unk09974c_Unk_099c60(input->ids[0]);
    if (input->ids[1] != 0) records[1] = Unk09974c_Unk_099c60(input->ids[1]);
    for (i = 0; i < 19; i++, dest++) {
        int adjustment = 0;
        u32 j;
        for (j = 0; j < 2; j++) {
            if (records[j] != 0) {
                int kind = records[j]->slots[i].kind;
                if (Unk02f078_IsAllowed_02f190(dest->kind, kind)) {
                    dest->kind = kind;
                    adjustment = records[j]->slots[i].value;
                }
            }
        }
        dest->value += adjustment;
    }
}
