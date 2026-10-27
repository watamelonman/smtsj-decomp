#include "libs/unknown/lib_02049398.h"

extern Unk049398State *data_0215eea0;

/* Borrowed MTBL/TBL1 accessors; ownership stays with the resource tables. */
extern void *func_0204fdac(void *resource, u32 index);
extern u32 func_0204fe18(void *table);
extern void *func_0204fde0(void *table);
extern void *func_0204fe68(void *resource, u32 index);
extern void *func_0204fed8(void *table, u32 id);
extern u32 func_0204ff30(void *table);
extern u32 func_0204ff64(void *table);

/* SDK byte-fill helper and the battle record accessors used by func_020494d0. */
extern void func_02008848(void *destination, u32 value, u32 size);
extern void *Unk044904_Unk_04502c(void);
extern void Unk044904_AddRecUnk08(void *area, u32 id, s32 delta);

/* ARM 02049398: looks up group one and falls back to entry zero when id is absent. */
void *func_02049398(u32 id)
{
    void *table = func_0204fe68(data_0215eea0->unk_7994, 1);
    void *result = func_0204fed8(table, id);
    if (result != 0) return result;
    return func_0204fed8(table, 0);
}

/* ARM 020493e0: looks up group two and falls back to entry zero when id is absent. */
void *func_020493e0(u32 id)
{
    void *table = func_0204fe68(data_0215eea0->unk_7994, 2);
    void *result = func_0204fed8(table, id);
    if (result != 0) return result;
    return func_0204fed8(table, 0);
}

/* ARM 02049428: rejects ids outside the group-zero table's inclusive index range. */
void *func_02049428(u32 id)
{
    void *table = func_0204fe68(data_0215eea0->unk_79a4, 0);
    if (func_0204ff30(table) <= id) {
        if (id <= func_0204ff64(table)) return func_0204fed8(table, id);
    }
    return 0;
}

/* ARM 02049484: clamps the index to the last 38-byte record, matching the unsigned compare. */
void *func_02049484(u32 index)
{
    void *table = func_0204fdac(data_0215eea0->unk_79a8, 0);
    u32 count = func_0204fe18(table);
    u8 *base = func_0204fde0(table);
    if (index >= count) index = count - 1;
    return base + index * 38;
}

/* ARM 020494d0: forwards the id and signed delta to the current battle record area. */
void func_020494d0(u32 id, s32 delta)
{
    void *area = Unk044904_Unk_04502c();
    Unk044904_AddRecUnk08(area, id, delta);
}

/* ARM 020494f0: zeroes the 0x3800-byte record array, then its three trailing words. */
void func_020494f0(Unk049398List *list)
{
    func_02008848(list, 0, 0x3800);
    list->unk_3800 = list->unk_3804 = list->count = 0;
}

/* ARM 0204951c: appends a 56-byte record while fewer than 256 are stored. */
s32 func_0204951c(Unk049398List *list, const Unk049398Record *record)
{
    if (list->count >= UNK049398_RECORD_CAPACITY) return 0;
    list->records[list->count] = *record;
    list->count++;
    return 1;
}

/* ARM 02049574: orders by the word at +4, using the word at +0 as the tie-breaker. */
s32 func_02049574(const Unk049398Record *a, const Unk049398Record *b)
{
    u32 delta = a->unk_04 - b->unk_04;
    if (delta == 0) delta = a->unk_00 - b->unk_00;
    return delta;
}
