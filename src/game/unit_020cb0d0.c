#include "types.h"

/* Observed record prefix; the two tables have strides 0x40 and 0x2a. */
typedef struct Unk0cb0d0Record {
    u8 reserved_00[0x20];
    u16 key;
    u8 reserved_22;
    u8 kind;
    u32 flags;
    u8 reserved_28[0xa];
    u16 flags_32;
} Unk0cb0d0Record;

/* Full search keys preserve each table's stride; only key is read by comparison. */
typedef struct Unk0cb0d0Key40 {
    u8 reserved_00[0x20];
    u16 key;
    u8 reserved_22[0x1e];
} Unk0cb0d0Key40;

typedef struct Unk0cb0d0Key2a {
    u8 reserved_00[0x20];
    u16 key;
    u8 reserved_22[8];
} Unk0cb0d0Key2a;

/* Table 1 (stride 0x2a) record prefix as read by 020cb12c. */
typedef struct Unk0cb0d0Record2a {
    u8 reserved_00[0x20];
    u16 key;
    u8 reserved_22[4];
    u16 flags_26;
} Unk0cb0d0Record2a;

extern u32 func_020445d0(int group, int table);
extern u32 func_020445f4(u32 group, u32 table);
extern void *func_0204fde0(void);
extern u32 func_0204fe18(u32 table);
extern u32 func_0204fed8(u32 table, u32 index);
extern void *func_02011810(const void *key, const void *base, u32 count,
                         u32 stride, int (*compare)(const void *, const void *));

Unk0cb0d0Record *func_020cb1a0(int id);
Unk0cb0d0Record2a *func_020cb21c(int id);
int Unk0cb0d0_IsAbove15e(s32 id);

/* Resolve group 14/table 1 and fetch the entry indexed by bits 5..8 of the id's
 * table-0 record (+0x24); ids above 0x15e use index 0 after a table-1 lookup. */
u32 func_020cb0d0(int id)
{
    u32 table = func_020445f4(14, 1);
    if (Unk0cb0d0_IsAbove15e(id)) {
        func_020cb21c(id);
        return func_0204fed8(table, 0);
    }
    return func_0204fed8(table, (func_020cb1a0(id)->flags << 23) >> 28);
}

/* Resolve group 14/table 2 and fetch the entry indexed by a 5-bit field of the
 * id's record: bits 11..15 of table 1's +0x26 for ids above 0x15e, otherwise
 * bits 12..16 of table 0's +0x24. The looked-up record must exist. */
u32 func_020cb12c(int id)
{
    u32 table = func_020445f4(14, 2);
    if (Unk0cb0d0_IsAbove15e(id)) {
        return func_0204fed8(table, ((u32)func_020cb21c(id)->flags_26 << 16) >> 27);
    }
    return func_0204fed8(table, (func_020cb1a0(id)->flags << 15) >> 27);
}

/* Compare unsigned keys at +0x20, as used by both calls to 02011810 below. */
int Unk0cb0d0_Unk_0cb190(const void *left, const void *right)
{
    return (u32)((const Unk0cb0d0Record *)left)->key -
           (u32)((const Unk0cb0d0Record *)right)->key;
}

/* Search group 11/table 0's 0x40-byte records; return its borrowed match or NULL.
 * The comparator reads only the low 16 bits of the supplied key. */
Unk0cb0d0Record *func_020cb1a0(int id)
{
    Unk0cb0d0Key40 key;
    u32 table = func_020445d0(11, 0);
    void *base = func_0204fde0();
    u32 count = func_0204fe18(table);
    key.key = id;
    return func_02011810(&key, base, count, sizeof(key), Unk0cb0d0_Unk_0cb190);
}

/* Resolve group 11/table 0 and invoke its count helper, discarding the result. */
void Unk0cb0d0_Unk_0cb1f8(void)
{
    u32 table = func_020445d0(11, 0);
    func_0204fde0();
    func_0204fe18(table);
}

/* Search group 11/table 1's 0x2a-byte records; return its borrowed match or NULL.
 * Only the low 16 bits of id participate in comparison. */
Unk0cb0d0Record2a *func_020cb21c(int id)
{
    Unk0cb0d0Key2a key;
    u32 table = func_020445d0(11, 1);
    void *base = func_0204fde0();
    u32 count = func_0204fe18(table);
    key.key = id;
    return func_02011810(&key, base, count, sizeof(key), Unk0cb0d0_Unk_0cb190);
}

/* Test +0x32's high nibble and +0x23's byte; record must cover both fields. */
int Unk0cb0d0_Unk_0cb274(const Unk0cb0d0Record *record)
{
    u32 k = ((u32)record->flags_32 << 16) >> 28;
    if (k == 14 || k == 1) {
        u8 kind = record->kind;
        if (kind == 3 || kind == 7) {
            return 1;
        }
    }
    return 0;
}

/* Accept packed +0x24 bits 5..8 equal to 0, 1, 5 or 6; record is non-NULL. */
int func_020cb2a8(const Unk0cb0d0Record *record)
{
    switch ((record->flags << 23) >> 28) {
    case 0:
    case 1:
    case 5:
    case 6:
        return 1;
    default:
        return 0;
    }
}

/* Signed boundary test; callers 020cb0d0/020cb12c use it to choose a table. */
int Unk0cb0d0_IsAbove15e(s32 id)
{
    return id > 0x15e;
}

/* Look up id in table 0 and test +0x23 for 7; a missing record returns false. */
u32 Unk0cb0d0_Unk_0cb304(int id)
{
    Unk0cb0d0Record *record = func_020cb1a0(id);
    if (record != 0 && record->kind == 7) {
        return 1;
    }
    return 0;
}
