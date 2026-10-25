#include "types.h"

/* Table selectors return a handle consumed by the base/count accessors. */
extern void *func_020445d0(u32 group, u32 table);
extern void *func_0204fde0(void *handle);
extern u32 func_0204fe18(void *handle);
extern void *func_02011810(const void *key, const void *base, u32 count,
                          u32 size, int (*compare)(const void *, const void *));

/* Compare leading unsigned byte keys; 020e679c passes this to 02011810. */
int Unk0e675c_Unk_0e675c(const void *left, const void *right)
{
    return (u32)*(const u8 *)left - (u32)*(const u8 *)right;
}

/* Compare leading unsigned halfword keys; 020e67f4 supplies aligned records. */
int Unk0e675c_Unk_0e676c(const void *left, const void *right)
{
    return (u32)*(const u16 *)left - (u32)*(const u16 *)right;
}

/* Compare leading unsigned halfwords for the six-byte records in 020e6874. */
int Unk0e675c_Unk_0e677c(const void *left, const void *right)
{
    return (u32)*(const u16 *)left - (u32)*(const u16 *)right;
}

/* Compare leading unsigned halfwords for the twelve-byte records in 020e68f0. */
int Unk0e675c_Unk_0e678c(const void *left, const void *right)
{
    return (u32)*(const u16 *)left - (u32)*(const u16 *)right;
}

/* Search group 0x21/table 0 by its leading byte; return a borrowed record or NULL.
 * Evidence: the original call to 02011810 uses stride 0x10 and the byte comparator. */
void *func_020e679c(u32 id)
{
    u8 key[0x10];
    void *handle = func_020445d0(0x21, 0);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    key[0] = id;
    return func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e675c);
}

/* Search group 0x21/table 1 by its leading halfword; return a borrowed record
 * or NULL. The original stride is 0x34; only the leading key is compared. */
void *func_020e67f4(u32 id)
{
    u16 key[0x34 / sizeof(u16)];
    void *handle = func_020445d0(0x21, 1);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    key[0] = id;
    return func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e676c);
}

/* Return a borrowed word in group 0x21/table 2; unsigned indices clamp to five.
 * Evidence: the original adds the clamped index shifted left by two to the base. */
u32 *Unk0e675c_Unk_0e684c(u32 index)
{
    u32 *base;
    void *handle;
    if (index > 5) {
        index = 5;
    }
    handle = func_020445d0(0x21, 2);
    base = func_0204fde0(handle);
    return base + index;
}

/* Six-byte record of group 0x17/table 2, sorted by its leading halfword id. */
typedef struct Unk0e675cRecord6 {
    u16 id;                     /* +0x00: search key */
    u8 pad_0002[2];
    u8 unk_0004_0 : 2;          /* +0x04 bits 0-1 */
    u8 unk_0004_2 : 2;          /* +0x04 bits 2-3 */
    u8 unk_0004_4 : 2;          /* +0x04 bits 4-5: not read here */
    u8 unk_0004_6 : 2;          /* +0x04 bits 6-7 */
    u8 pad_0005[1];
} Unk0e675cRecord6;

/* Entry returned by func_020a1428; only the id list read by 020e6948 is typed. */
typedef struct Unk0e675cEntry {
    u8 pad_0000[0x2e];
    u16 unk_002e[6];            /* +0x2e: ids compared against a record id */
} Unk0e675cEntry;

extern Unk0e675cEntry *func_020a1428(u32 id);

/* Search group 0x17/table 2 (six-byte records) by leading halfword id; return
 * a borrowed record or NULL. Evidence: stride 6 and comparator 020e677c. */
Unk0e675cRecord6 *func_020e6874(u32 id)
{
    u16 key[3];
    void *handle = func_020445d0(0x17, 2);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    key[0] = id;
    return func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e677c);
}

/* Return the count for group 0x17/table 2 after establishing its base accessor.
 * Evidence: 0204fe18's result remains in r0 at the original return. */
u32 Unk0e675c_Unk_0e68cc(void)
{
    void *handle = func_020445d0(0x17, 2);
    func_0204fde0(handle);
    return func_0204fe18(handle);
}

/* Search group 0x17/table 1 (twelve-byte records) by leading halfword id;
 * return a borrowed record or NULL. Evidence: stride 12 and comparator 020e678c. */
void *func_020e68f0(u32 id)
{
    u16 key[6];
    void *handle = func_020445d0(0x17, 1);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    key[0] = id;
    return func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e678c);
}

/* Return 1 when the group 0x17/table 2 record for `id` is listed in the six
 * ids of entry `owner`, or when any of its bit pairs 0-1, 2-3 or 6-7 is set;
 * otherwise 0. The search repeats func_020e6874 in place (the original has no
 * call to it) and does not check the result for NULL, so `id` must exist in
 * the table. `owner` is passed through to func_020a1428. */
int func_020e6948(u32 owner, u32 id)
{
    u16 key[3];
    Unk0e675cEntry *entry = func_020a1428(owner);
    void *handle = func_020445d0(0x17, 2);
    void *base = func_0204fde0(handle);
    u32 count = func_0204fe18(handle);
    Unk0e675cRecord6 *record;
    int i;
    key[0] = id;
    record = func_02011810(key, base, count, sizeof(key), Unk0e675c_Unk_0e677c);
    for (i = 0; i < 6; i++) {
        if (record->id == entry->unk_002e[i]) {
            return 1;
        }
    }
    if (record->unk_0004_0 != 0 || record->unk_0004_2 != 0 || record->unk_0004_6 != 0) {
        return 1;
    }
    return 0;
}
