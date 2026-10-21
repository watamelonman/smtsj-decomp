#include "types.h"

/* 8-byte entry of the table returned by func_02056110 (meaning unknown). */
typedef struct Unk126178Entry {
    u32 unk_00;
    u32 unk_04;
} Unk126178Entry;

/* Header returned by func_02056110; the entry array starts at +8 (size unknown). */
typedef struct Unk126178Table {
    u8 pad_0000[8];
    Unk126178Entry entries[1];
} Unk126178Table;

/* Selector object holding the entry index at +8. */
typedef struct Unk126178Sel {
    u8 pad_0000[8];
    u32 index;
} Unk126178Sel;

/* 16-byte item drawn by func_021261d8: id, x/y offset, extra word. */
typedef struct Unk126178Item {
    u32 unk_00;
    u16 x;
    u16 y;
    u32 unk_08;
    u8 pad_000c[4];
} Unk126178Item;

/* Work object shared by both functions of this TU (layout from field use only). */
typedef struct Unk126178Work {
    s32 count;
    u32 unk_04;
    u8 pad_0008[4];
    u32 unk_0c;
    void *unk_10;
    u32 unk_14;
    u32 unk_18;
} Unk126178Work;

/* Argument block passed by pointer to func_0205bf18. */
typedef struct Unk126178Args {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    Unk126178Entry *entry;
} Unk126178Args;

/* Temporary built by func_020569e4 and consumed by func_02056954 (size from stack frame). */
typedef struct Unk126178Tmp {
    u32 unk_00;
    u32 unk_04;
} Unk126178Tmp;

Unk126178Table *func_02056110(u32 a);
void func_0205bf18(Unk126178Entry *entries, Unk126178Args *args);
void func_020569e4(Unk126178Tmp *t, u32 a, u32 b, u32 c, u32 d, u32 e);
void func_02056b94(Unk126178Tmp *t, s32 x, s32 y);
void func_02056bbc(Unk126178Tmp *t, u32 a);
void func_02056bd0(Unk126178Tmp *t, u32 a);
void func_02056954(u32 a, Unk126178Tmp *t, u32 b, u32 c);

/* Looks up the entry selected by w->unk_10->index in the table of w->unk_04 and passes it,
 * together with w->unk_14 and w->unk_18, to func_0205bf18. The two fields are read into locals
 * first; that is what gives the ROM's load order. */
void func_02126178(Unk126178Work *w)
{
    Unk126178Table *tbl = func_02056110(w->unk_04);
    Unk126178Entry *entries = tbl->entries;
    Unk126178Entry *e = &entries[((Unk126178Sel *)w->unk_10)->index];
    u32 b = w->unk_18;
    u32 a = w->unk_14;
    Unk126178Args args;
    args.unk_00 = e->unk_00;
    args.unk_04 = a;
    args.unk_08 = b;
    args.unk_0c = 0;
    args.unk_10 = 0;
    args.unk_14 = 0;
    args.entry = e;
    func_0205bf18(entries, &args);
}

/* For each of w->count items, builds a temporary from the item, offsets it by (x, y),
 * applies a and b, and submits it to w->unk_04. */
void func_021261d8(Unk126178Work *w, s32 x, s32 y, u32 a, u32 b)
{
    Unk126178Tmp tmp;
    s32 i;
    for (i = 0; i < w->count; i++) {
        Unk126178Item *it = &((Unk126178Item *)w->unk_10)[i];
        func_020569e4(&tmp, w->unk_04, it->unk_00, it->unk_08, w->unk_0c, 0);
        func_02056b94(&tmp, it->x + x, it->y + y);
        func_02056bbc(&tmp, a);
        func_02056bd0(&tmp, b);
        func_02056954(w->unk_04, &tmp, 1, 0);
    }
}
