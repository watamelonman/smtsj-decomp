/* src/game/unit_020a1418.c: lookups into the 100-byte record table of resource 19.
 *
 * Resource 19 is a table of 100-byte records (see func_020445d0/func_0204fde0/
 * func_0204fe18). A record is identified by the u16 at +0, grouped by the u8 at
 * +2, and carries a packed halfword at +0x28 whose bit 0 is a marker and whose
 * remaining bits hold a second key. The two data symbols below are overlapping
 * u16 views of the same three {kind, value} pairs in .data.
 */
#include "types.h"

typedef struct Unit020a1418Entry {
    u16 id;                 /* 0x00: record id, the binary-search key */
    u8 kind;                /* 0x02: group id matched by func_020a1554 */
    u8 pad_03[5];           /* 0x03 */
    u16 enabled : 1;        /* 0x08: bit 0, record participates in listings */
    u16 pad_08 : 15;        /* 0x08: unused */
    u8 pad_0a[0x1e];        /* 0x0a */
    u16 active : 1;         /* 0x28: bit 0, tested by the caller of func_020a1480 */
    u16 value : 15;         /* 0x28: bits 1..15, key searched by func_020a1480 */
    u8 pad_2a[0x3a];        /* 0x2a */
} Unit020a1418Entry;         /* 0x64 = 100 bytes */

extern void *func_020445d0(int resource, int index);
extern Unit020a1418Entry *func_0204fde0(void *resource);
extern u32 func_0204fe18(void *resource);
extern void *func_02011810(const void *key, const void *base, u32 count, u32 size,
                           int (*compare)(u16 *, u16 *));
extern int func_0209993c(u16 id);
extern int Unk065e88_Unk_068554(u16 id);

/* Three {kind, value} pairs. func_020a14e0 reads the kind through
   data_0213c24c and the value through data_0213c24e (the same words, viewed
   from an address two bytes later); func_020a1554 reads both through
   data_0213c24c. */
extern u16 data_0213c24c[][2];
extern u16 data_0213c24e[][2];

/* Ordering callback for the binary search: compares the record ids. */
int Unk0a1418_Unk_0a1418(u16 *arg0, u16 *arg1)
{
    return (u32)*arg0 - (u32)*arg1;
}

/* Binary-searches resource 19 for the record whose id is `id`. Returns the
   matching record, or the NULL that func_02011810 reports when absent. */
Unit020a1418Entry *func_020a1428(u16 id)
{
    void *res = func_020445d0(19, 0);
    Unit020a1418Entry *base = func_0204fde0(res);
    u32 count = func_0204fe18(res);
    Unit020a1418Entry key;

    key.id = id;
    return func_02011810(&key, base, count, sizeof(key), Unk0a1418_Unk_0a1418);
}

/* Linear scan of resource 19 for a record whose packed +0x28 value equals
   `value`. Returns the record, or NULL when none qualifies. */
Unit020a1418Entry *func_020a1480(int value)
{
    void *res = func_020445d0(19, 0);
    Unit020a1418Entry *base = func_0204fde0(res);
    u32 count = func_0204fe18(res);
    u32 i;

    for (i = 0; i < count; i++, base++) {
        if (value == base->value) {
            return base;
        }
    }
    return 0;
}

/* Decides whether a record is usable: records with id 0x158 or 0x1d9 always
   are, otherwise the record's kind must appear in the three-pair table and the
   table's value must satisfy func_0209993c. */
int func_020a14e0(Unit020a1418Entry *entry)
{
    int i;

    if (entry->id == 0x158 || entry->id == 0x1d9) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        if (data_0213c24c[i][0] == entry->kind) {
            return func_0209993c(data_0213c24e[i][0]) != 0;
        }
    }
    return 1;
}

/* Collects up to `capacity` record ids belonging to `kind` into `out` and
   terminates the list with 0. The id list is derived from the matching table
   pair; ids rejected by Unk065e88_Unk_068554 and the two special ids are
   skipped. Returns 1 when `kind` is present in the table, else 0. */
int func_020a1554(u16 *out, int capacity, u16 kind)
{
    int i;

    if (capacity == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        Unit020a1418Entry *entry;
        void *res;
        u32 count;
        u32 j;
        u16 want;

        if (kind != data_0213c24c[i][1]) {
            continue;
        }
        want = data_0213c24c[i][0];
        res = func_020445d0(19, 0);
        entry = func_0204fde0(res);
        count = func_0204fe18(res);
        for (j = 0; j < count; j++, entry++) {
            if (!entry->enabled) {
                continue;
            }
            if (entry->kind != want) {
                continue;
            }
            if (Unk065e88_Unk_068554(entry->id) != 0 && entry->id != 0x158 &&
                entry->id != 0x1d9) {
                *out++ = entry->id;
                if (--capacity == 0) {
                    break;
                }
            }
        }
        if (capacity != 0) {
            *out = 0;
        }
        return 1;
    }
    return 0;
}
