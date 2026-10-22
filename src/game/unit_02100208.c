#include "types.h"

/** Partial comparator record; offsets follow loads in 0x02100298–0x021003d8. */
typedef struct Unk100208Record {
    u16 id;
    u8 unk_0002;
    u8 unk_0003;
    s32 unk_0004;
    u32 unk_0008;
    u32 unk_000c;
} Unk100208Record;

/** Only the byte read by the comparators is known in the lookup result. */
typedef struct Unk100208Lookup {
    u8 pad_0000[3];
    u8 unk_0003;
} Unk100208Lookup;

extern Unk100208Lookup *func_020a1428(u32 id);
extern void Unk0a0ce4_Unk_0a0da4(u32 value);
extern u32 func_020445d0(s32 kind, u32 id);
extern const u16 *func_0204fde0(u32 handle);

/** Translate selectors 0–7 to the constants passed to 0x020a0da4; others do nothing. */
void Unk100208_Unk_100208(u32 arg0)
{
  switch(arg0) {
  case 0:
    Unk0a0ce4_Unk_0a0da4(1);
    return;
  case 1:
    Unk0a0ce4_Unk_0a0da4(4);
    return;
  case 2:
    Unk0a0ce4_Unk_0a0da4(2);
    return;
  case 3:
    Unk0a0ce4_Unk_0a0da4(0);
    return;
  case 4:
    Unk0a0ce4_Unk_0a0da4(0xb);
    return;
  case 5:
    Unk0a0ce4_Unk_0a0da4(9);
    return;
  case 6:
    Unk0a0ce4_Unk_0a0da4(10);
    return;
  case 7:
    Unk0a0ce4_Unk_0a0da4(0x10);
    return;
  default:
    return;
  }
}

/** Compare byte 2 ascending, lookup byte 3 descending, then record id ascending.
 * The loads and lookup calls at func_02100298 establish this ordering. */
s32 func_02100298(const Unk100208Record *a, const Unk100208Record *b)
{
    s32 result = a->unk_0002 - b->unk_0002;
    if (result == 0) {
        const Unk100208Lookup *first = func_020a1428(a->id);
        const Unk100208Lookup *second = func_020a1428(b->id);
        result = second->unk_0003 - first->unk_0003;
    }
    if (result == 0) {
        result = a->id - b->id;
    }
    return result;
}

/** Compare byte 2 ascending, lookup byte 3 descending, then record id ascending.
 * The loads and lookup calls at func_021002e8 establish this ordering. */
s32 func_021002e8(const Unk100208Record *a, const Unk100208Record *b)
{
    s32 result = a->unk_0002 - b->unk_0002;
    if (result == 0) {
        const Unk100208Lookup *first = func_020a1428(a->id);
        const Unk100208Lookup *second = func_020a1428(b->id);
        result = second->unk_0003 - first->unk_0003;
    }
    if (result == 0) {
        result = a->id - b->id;
    }
    return result;
}

/** Order zero field-0x0c records last, then table-21 values and ids ascending.
 * Table selection and halfword indexing are observed at 0x02100338. */
s32 func_02100338(const Unk100208Record *a, const Unk100208Record *b)
{
    const u16 *table;
    s32 result;
    if (a->unk_000c == 0) return 1;
    if (b->unk_000c == 0) return -1;
    table = func_0204fde0(func_020445d0(21, 0));
    result = table[a->id] - table[b->id];
    if (result == 0) result = a->id - b->id;
    return result;
}

/** Compare byte 3 descending, breaking ties by ascending id (0x02100398 loads). */
s32 Unk100208_Unk_100398(const Unk100208Record *a, const Unk100208Record *b)
{
    s32 result = b->unk_0003 - a->unk_0003;
    if (result == 0) result = a->id - b->id;
    return result;
}

/** Compare signed field 4 descending, then id ascending (0x021003b8 loads). */
s32 Unk100208_Unk_1003b8(const Unk100208Record *a, const Unk100208Record *b)
{
    s32 result = b->unk_0004 - a->unk_0004;
    if (result == 0) result = a->id - b->id;
    return result;
}

/** Compare lookup byte 3 descending, then id ascending (0x021003d8 calls/loads). */
s32 Unk100208_Unk_1003d8(const Unk100208Record *a, const Unk100208Record *b)
{
    const Unk100208Lookup *first = func_020a1428(a->id);
    const Unk100208Lookup *second = func_020a1428(b->id);
    s32 result = second->unk_0003 - first->unk_0003;
    if (result == 0) result = a->id - b->id;
    return result;
}
