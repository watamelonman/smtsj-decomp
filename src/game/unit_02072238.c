/* src/game/unit_02072238.c: battle panel list construction and drawing helpers. */
#include "types.h"

/* A record referenced from the slot table at +0x120. Only the id and the byte copied to the
   panel are used by this unit. */
typedef struct Unk072238Slot {
    u8 pad_0000[52];
    u8 unk_0034;        /* +0x34 replaces the definition byte +3 in func_02075fd0 */
    u8 pad_0035;
    u16 id;             /* +0x36 */
    u8 unk_0038;        /* +0x38 */
    u8 pad_0039[3];
} Unk072238Slot;

/* Definition view used by the id list and pair classifier; category is read at +5. */
typedef struct Unk072238Def {
    u16 id;             /* +0x0 */
    u8 unk_0002;        /* +0x2 class key matched by the rule tables */
    u8 unk_0003;        /* +0x3 */
    u8 pad_0004;
    u8 category;
} Unk072238Def;

/* Second view of the same definition record (+2 class key, +3 rank), used where the
   original reloads those bytes instead of reusing the Unk072238Def loads (func_02075fd0). */
typedef struct Unk072238Rank {
    u8 pad_0000[2];
    u8 key;             /* +0x2 */
    u8 rank;            /* +0x3 */
} Unk072238Rank;

/* Per-row state of the panel; `ids` and `flags` share indices 0..count-1. */
typedef struct Unk072238Panel {
    u8 pad_0000[36];
    int unk_0024;
    s16 selected;       /* +0x28 */
    s16 second;
    u16 result_id;
    s16 unk_002e;
    u8 pad_0030[4];
    u32 state;
    u8 mode;
    /* Guessed capacity: the 12 slot pointers bound the count-by-count table. */
    u8 matrix[144];
    u8 pad_00c9;
    u16 ids[12];        /* +0xca */
    u8 flags[12];       /* +0xe2 */
} Unk072238Panel;

/* Display resource wrapper: resource is passed to the drawing helpers; the initialized word is +0x24. */
typedef struct Unk072238Display {
    void *resource;
    u8 pad_0004[32];
    int unk_0024;
} Unk072238Display;

/* Object passed as the first argument by Unk065e88_SetMode; layout from the observed accesses.
   The slot array size is guessed from the 12-entry panel arrays; only indices 0..11 are used. */
/* Rule tables walked by func_02075fd0 (pointers at Work +0x88..+0x9c, counts at +0xb6..+0xc0). */
typedef struct Unk072238Rule4 {
    u8 a, b;            /* +0x0/+0x1 class keys (either order) */
    u8 result;          /* +0x2 resulting class key (+0x88 table) */
    u8 kind;            /* +0x3 rule condition (+0x88 table) */
} Unk072238Rule4;

typedef struct Unk072238RuleBits {
    u32 key : 8;        /* bits 0-7 class key */
    u32 id : 16;        /* bits 8-23 definition id */
    u32 kind : 8;       /* bits 24-31 rule kind 1..3 */
} Unk072238RuleBits;

typedef struct Unk072238Rule6 {
    u16 a, b;           /* +0x0/+0x2 definition ids (either order) */
    u16 unk_4;
} Unk072238Rule6;

typedef struct Unk072238Rule8 {
    u16 id;             /* +0x0 definition id */
    u8 pad_2[5];
    u8 key;             /* +0x7 class key */
} Unk072238Rule8;

typedef struct Unk072238Work {
    u8 pad_0000[132];
    u8 *unk_0084;       /* +0x84 base value added in func_02075fd0 */
    Unk072238Rule4 *rules_088;
    Unk072238Rule4 *rules_08c;
    Unk072238RuleBits *rules_090;
    u8 pad_0094[4];
    Unk072238Rule6 *rules_098;
    Unk072238Rule8 *rules_09c;
    u8 pad_00a0[18];
    u8 count;           /* +0xb2 */
    u8 pad_00b3[3];
    u16 n_088;          /* +0xb6 */
    u16 n_08c;          /* +0xb8 */
    u16 n_090;          /* +0xba */
    u8 pad_00bc[2];
    u16 n_098;          /* +0xbe */
    u16 n_09c;          /* +0xc0 */
    u8 pad_00c2[78];
    void *names;
    void *list;         /* +0x114 */
    u8 pad_0118[8];
    Unk072238Slot *slots[12]; /* +0x120 */
    void *row_list;
    s16 row;
    s16 row_base;
    s16 unk_0158;       /* +0x158 */
    u8 pad_015a[2];
    u16 *rows[24]; /* Initializer walks all 24 pointers; null rows are permitted. */
    u8 pad_01bc[68];
    Unk072238Panel panel;     /* +0x200 */
    u8 pad_02f0[8];
    u8 data[60];        /* +0x2f8 */
    u8 pad_0334[30];
    u8 unk_0352;        /* +0x352 */
    u8 pad_0353[101];
    Unk072238Display *handles[8];
    u8 pad_03d8[8];
    u8 mode;
    u8 unk_03e1;        /* +0x3e1 */
    u16 unk_03e2;       /* +0x3e2 */
    u8 pad_03e4[16];
    int unk_03f4;
} Unk072238Work;

/* Work area returned by Unk02e000_GetWorkArea; keys map a slot index to an entry id. */
typedef struct Unk072238Area {
    u8 pad_0000[120];
    Unk072238Slot records[12]; /* +0x78, 60 bytes each */
    s8 keys[12];        /* +0x348 */
    u8 pad_0354[3];
    u8 entry_count;
} Unk072238Area;

void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
void func_0205dee8(int a, void *p, int x, int y, int z, float f0, float f1, int z2, float f2, int z3);
void func_02057df8(void);
void func_02057fd8(void);
void func_02057e18(int a);
void func_02067c88(void *p);
int Unk096754_Unk_096ab0(int a);
int Unk068f18_Unk_06a1a8(u8 *p, int key);
u8 *Unk02e000_GetWorkArea(void);
void func_02063920(void);
void func_02008848(void *dst, int value, u32 size);
void func_02008644(u32 value, void *dst, u32 size);
int func_02067ef4(void *p, u16 a, u16 b);
int func_020a1428(int id);
/* Declared non-void because the original passes this call's result register straight to
   func_02063a30; the implementation in unit_020a163c.c itself returns nothing. */
u32 Unk0a163c_Unk_0a1814(u32 id);
int func_02063a30(u32 id);
void func_02061f10(void *list, int a, int b, int c, u32 d);
void func_02067418(void *p, u16 *ids);
int func_02068cf8(Unk072238Work *p, u16 *ids, int n, u8 *data);
s16 Unk06a224_CountUsedSlots(void);
void Unk06a224_SetUnk00(u32 a);
void Unk06a224_Unk_06a244(u32 a);

/* Rebuilds the panel's id list from the current area entry and refreshes the used-slot count.
   The id list is a variable-length array sized by the current area's entry count. */
void func_02072238(Unk072238Work *p)
{
    Unk072238Area *w;
    u16 i;

    p->unk_03e1 = 1;
    p->unk_03e2 = 0;
    w = (Unk072238Area *)Unk02e000_GetWorkArea();
    {
        u16 ids[FIELD(u8, w, 855)];

        func_02008644(0, ids, FIELD(u8, w, 855) * 2);
        for (i = 0; i < FIELD(u8, w, 855); i++) {
            s8 key = w->keys[i];
            if (key >= 0) {
                ids[i] = p->slots[key]->id;
            }
        }
        func_02008644(0, p->data, 60);
        p->unk_0352 = func_02068cf8(p, ids, FIELD(u8, w, 855), p->data);
        if (p->unk_0352 != 0) {
            Unk06a224_SetUnk00(1);
        } else {
            Unk06a224_SetUnk00(0);
        }
        p->unk_0158 = Unk06a224_CountUsedSlots();
        if (p->unk_0158 > 0) {
            Unk06a224_Unk_06a244(1);
        } else {
            Unk06a224_Unk_06a244(0);
        }
        p->unk_0158++;
    }
}

/* empty callback */
void Unk072238_Nop_07236c(void) { }

/* empty callback */
void Unk072238_Nop_072370(void) { }

/* Builds the id->row table for the battle panel and copies each row's display byte. */
void func_020769f8(Unk072238Work *p)
{
    Unk072238Area *w;
    Unk072238Def *def;
    int id;
    int i;
    u32 count;

    w = (Unk072238Area *)Unk02e000_GetWorkArea();
    func_02063920();
    func_02008848(p->panel.flags, 0, 12);
    for (i = 0; i < p->count; i++) {
        int sel = p->panel.selected;
        u16 a = p->slots[w->keys[sel]]->id;
        u16 b = p->slots[w->keys[i]]->id;
        int idx;

        id = func_02067ef4(p, a, b);
        def = (Unk072238Def *)func_020a1428(id);
        count = func_02063a30(Unk0a163c_Unk_0a1814(def->id));
        p->panel.ids[i] = id;
        idx = Unk068f18_Unk_06a1a8((u8 *)p, id);
        if (idx >= 0) {
            int sel2 = p->panel.selected;
            if (id == p->slots[w->keys[sel2]]->id || id == p->slots[w->keys[i]]->id) {
                p->panel.flags[i] = p->slots[idx]->unk_0038;
                continue;
            }
        }
        p->panel.flags[i] = def->unk_0003;
    }
    func_02061f10(p->list, -1, 0, 0, count);
    func_02067418(p, p->panel.ids);
}

/* empty callback */
void Unk072238_Nop_076b4c(void) { }

/* Picks the colour/threshold band for `v` and submits a text draw call. */
void func_02076b50(void *p, u32 v, int a, int b)
{
    if (v >= 45) {
        func_02057dcc(0x5a3129ff, 0x5a3129ff, 0x5a3129ff, 0x5a3129ff);
        func_0205dee8(1, p, v - 28, a, b, 1.0f, 1.0f, 0, 1.0f, 10);
        return;
    }
    if (v >= 36) {
        func_02057dcc(0xff7b63ff, 0xff7b63ff, 0xff7b63ff, 0xff7b63ff);
        func_0205dee8(1, p, v - 19, a, b, 1.0f, 1.0f, 0, 1.0f, 10);
        return;
    }
    if (v >= 27) {
        func_02057dcc(0x18525aff, 0x18525aff, 0x18525aff, 0x18525aff);
        func_0205dee8(1, p, v - 10, a, b, 1.0f, 1.0f, 0, 1.0f, 10);
        return;
    }
    if (v >= 18) {
        func_02057dcc(0x39dccbff, 0x39dccbff, 0x39dccbff, 0x39dccbff);
        func_0205dee8(1, p, v - 1, a, b, 1.0f, 1.0f, 0, 1.0f, 10);
        return;
    }
    if (v >= 9) {
        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
        func_0205dee8(1, p, v + 8, a, b, 1.0f, 1.0f, 0, 1.0f, 10);
        return;
    }
    func_02057df8();
    func_0205dee8(1, p, v + 17, a, b, 1.0f, 1.0f, 0, 1.0f, 10);
}

/* Draws the area-record list (one row per entry) with the shared panel helpers. */
void func_02076d8c(u8 *p)
{
    u8 *w;
    int half;
    u32 i;
    int y;
    u32 n;

    func_02057fd8();
    w = Unk02e000_GetWorkArea();
    n = FIELD(u8, w, 855);
    half = ((s32)n - 6) / 2;
    func_02057df8();
    func_0205dee8(1, FIELD(void *, p, 944), half + 38, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    i = 0;
    if (i < n) {
        y = i;
        do {
            s8 key = FIELD(s8, w + i + 768, 72);
            if (Unk096754_Unk_096ab0(key) == 0) {
                func_0205dee8(2, FIELD(void *, p, 944), half + 62, 0, y, 1.0f, 1.0f, 0, 1.0f, 2);
            } else {
                func_0205dee8(2, FIELD(void *, p, 944), (i & 1) == 0 ? half + 54 : half + 58, 0,
                              (i >> 1) * 22, 1.0f, 1.0f, 0, 1.0f, 2);
            }
            y += 11;
            i++;
        } while (i < n);
    }
    func_02057fd8();
    func_0205dee8(1, FIELD(void *, p, 944), half + 50, 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
    func_02057e18(31);
    func_02057fd8();
    func_02057df8();
    func_0205dee8(1, FIELD(void *, p, 944), 37, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
    half = (FIELD(u8, w, 855) - 6) / 2;
    func_02057dcc(0xa5d6ff00, 0xa5d6ff00, 0xa5d6ff00, 0xa5d6ff00);
    func_0205dee8(1, FIELD(void *, p, 944), half + 42, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
    func_02057dcc(0xa5d6ff00, 0xa5d6ff00, 0xa5d6ff00, 0xa5d6ff00);
    func_0205dee8(1, FIELD(void *, p, 944), half + 46, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
    func_02067c88(FIELD(void *, p, 268));
}

/* Draws the same area-record list as func_02076d8c, marking the selected row. */
void func_02076fcc(u8 *p)
{
    u8 *w;
    int half;
    u32 i;
    int y;
    u32 n;

    func_02057fd8();
    w = Unk02e000_GetWorkArea();
    n = FIELD(u8, w, 855);
    half = ((s32)n - 6) / 2;
    func_02057df8();
    func_0205dee8(1, FIELD(void *, p, 944), 72, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    i = 0;
    if (i < n) {
        y = i;
        do {
            if (i == FIELD(s16, p, 552)) {
                func_0205dee8(2, FIELD(void *, p, 944), 81, 0, y, 1.0f, 1.0f, 0, 1.0f, 2);
            } else if (Unk096754_Unk_096ab0(FIELD(s8, w + i + 768, 72)) == 0) {
                func_0205dee8(2, FIELD(void *, p, 944), 80, 0, y, 1.0f, 1.0f, 0, 1.0f, 2);
            } else {
                func_0205dee8(2, FIELD(void *, p, 944), (i & 1) == 0 ? 78 : 79, 0,
                              (i >> 1) * 22, 1.0f, 1.0f, 0, 1.0f, 2);
            }
            y += 11;
            i++;
        } while (i < n);
    }
    func_02057fd8();
    func_0205dee8(1, FIELD(void *, p, 944), half + 74, 0, 0, 1.0f, 1.0f, 0, 1.0f, 4);
    func_02057e18(31);
    func_02057fd8();
    func_02057df8();
    func_0205dee8(1, FIELD(void *, p, 944), 71, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
    func_02057dcc(0xa5d6ff00, 0xa5d6ff00, 0xa5d6ff00, 0xa5d6ff00);
    func_0205dee8(1, FIELD(void *, p, 944), (FIELD(u8, w, 855) - 6) / 2 + 42, 0, 0,
                  1.0f, 1.0f, 0, 1.0f, 10);
    func_02067c88(FIELD(void *, p, 268));
}

Unk072238Slot *Unk02e000_GetAreaRecord(int n);
void func_02067370(void *p);
int Unk06a224_Unk_06a224(void);
int Unk0e651c_Unk_0e666c(int n);
void * func_020445f4(int a, int b);
u32 func_0204fed8(void *p, int id);
void Unk065e88_Unk_0672fc(void *p, int a, int b);
/* Pair classifier (defined below, before func_02072374): returns classes 0..8. */
int func_02075fd0(Unk072238Work *p, int a, int b);
u16 func_020685b0(Unk072238Work *p, u32 key, u32 rank);
u16 func_02068658(Unk072238Work *p, u32 key, u32 rank);
u16 func_02068bf8(Unk072238Work *p, const u16 *ids, int count);
int Unk03e43c_Unk_03fa28(void);
int Unk06a224_Unk_06a9fc(int id);
/* Deferred draw dispatcher: reads panel.state after guarding +0x220 and +0x3b0;
   calls the two row-list draw helpers. Still supplied by the original delink. */
void func_0207498c(Unk072238Work *p);
/* Deferred update dispatcher: resets through func_02072374, polls input, and dispatches
   panel.state through 15. Still supplied by the original delink. */
void func_0207283c(Unk072238Work *p);
/* Deferred result-record builder: combines the two selected ids with func_02067ef4,
   builds the 60-byte record, and optionally refreshes it. Still supplied by the delink. */
void func_020765b0(Unk072238Work *p, int refresh);
int func_020698e0(void *p, u16 *ids, int n, int result);
void func_0205c408(void *p, int n);
void func_0205c6e0(void *p);
void func_0205c6f8(void *p);
void Unk065e88_SetFlag3a(void *p, int n);
void Unk06a224_Unk_06adc0(int n);

/* Classifies the pair (a, b) for the pair table built by func_02072374: 8 for the same
   definition, 6 when no result exists, 5/4/7 and 1..3 for the rule tables at +0x98/+0x8c/+0x9c
   and +0x90, 0 for a plain class-table result. */
int func_02075fd0(Unk072238Work *p, int a, int b)
{
    u16 result = 0;
    Unk072238Def *da;
    Unk072238Def *db;
    u16 pair[2];
    int i;
    int phase;
    int ia, ib;
    u8 ra, rb;
    int rank, key;

    da = (Unk072238Def *)func_020a1428(a);
    db = (Unk072238Def *)func_020a1428(b);
    if (da->id == db->id) {
        return 8;
    }
    pair[0] = a;
    pair[1] = b;
    if (func_02068bf8(p, pair, 2)) {
        return 6;
    }
    for (i = 0; i < p->n_098; i++) {
        if ((da->id == p->rules_098[i].a && db->id == p->rules_098[i].b) ||
            (db->id == p->rules_098[i].a && da->id == p->rules_098[i].b)) {
            return 5;
        }
    }
    for (i = 0; i < p->n_09c; i++) {
        if (da->id == p->rules_09c[i].id && db->unk_0002 != p->rules_09c[i].key) {
            return da->unk_0002 == db->unk_0002 ? 6 : 7;
        }
        if (db->id == p->rules_09c[i].id && da->unk_0002 != p->rules_09c[i].key) {
            return da->unk_0002 == db->unk_0002 ? 6 : 7;
        }
    }
    for (i = 0; i < p->n_08c; i++) {
        if ((da->unk_0002 == p->rules_08c[i].a && db->unk_0002 == p->rules_08c[i].b) ||
            (db->unk_0002 == p->rules_08c[i].a && da->unk_0002 == p->rules_08c[i].b)) {
            return 4;
        }
    }
    for (i = 0; i < p->n_090; i++) {
        if ((da->unk_0002 == p->rules_090[i].key && db->id == p->rules_090[i].id) ||
            (db->unk_0002 == p->rules_090[i].key && da->id == p->rules_090[i].id)) {
            u32 kind = p->rules_090[i].kind;
            u16 r;
            u8 lv;
            if (kind == 1) {
                if (da->id == p->rules_090[i].id) {
                    lv = ((Unk072238Rank *)db)->rank + 1; key = ((Unk072238Rank *)db)->key;
                } else {
                    lv = ((Unk072238Rank *)da)->rank + 1; key = ((Unk072238Rank *)da)->key;
                }
                r = func_020685b0(p, key, lv);
                if (r == 0 || r == da->id || r == db->id) return 6;
                return 1;
            }
            if (kind == 2) {
                if (da->id == p->rules_090[i].id) {
                    lv = ((Unk072238Rank *)db)->rank + 1; key = ((Unk072238Rank *)db)->key;
                } else {
                    lv = ((Unk072238Rank *)da)->rank + 1; key = ((Unk072238Rank *)da)->key;
                }
                r = func_020685b0(p, key, lv);
                if (r == 0) return 0;
                r = func_020685b0(p, key, (u8)(((Unk072238Def *)func_020a1428(r))->unk_0003 + 1));
                if (r == 0 || r == da->id || r == db->id) return 6;
                return 2;
            }
            if (kind == 3) {
                if (da->id == p->rules_090[i].id) {
                    lv = ((Unk072238Rank *)db)->rank - 1; key = ((Unk072238Rank *)db)->key;
                } else {
                    lv = ((Unk072238Rank *)da)->rank - 1; key = ((Unk072238Rank *)da)->key;
                }
                r = func_02068658(p, key, lv);
                if (r == 0 || r == da->id || r == db->id) return 6;
                return 3;
            }
        }
    }
    phase = Unk03e43c_Unk_03fa28();
    ia = Unk068f18_Unk_06a1a8((u8 *)p, da->id);
    ib = Unk068f18_Unk_06a1a8((u8 *)p, db->id);
    ra = da->unk_0003;
    rb = db->unk_0003;
    if (ia >= 0) {
        ra = ((Unk072238Area *)Unk02e000_GetWorkArea())->records[ia].unk_0034;
    }
    if (ib >= 0) {
        rb = ((Unk072238Area *)Unk02e000_GetWorkArea())->records[ib].unk_0034;
    }
    for (i = 0; i < p->n_088; i++) {
        if ((da->unk_0002 == p->rules_088[i].a && db->unk_0002 == p->rules_088[i].b) ||
            (db->unk_0002 == p->rules_088[i].a && da->unk_0002 == p->rules_088[i].b)) {
            u8 kind = p->rules_088[i].kind;
            if ((kind == 1 && phase == 8) || (kind == 9 && phase == 0) || kind == 0) {
                u8 key = p->rules_088[i].result;
                u8 rank;
                int sum;
                if (Unk06a224_Unk_06a9fc(177) && key == 17) key = 41;
                if (Unk06a224_Unk_06a9fc(178) && key == 15) key = 39;
                if (Unk06a224_Unk_06a9fc(179) && key == 12) key = 40;
                if (Unk06a224_Unk_06a9fc(184)) {
                    sum = ra + rb;
                    if (sum % 2 == 1) rank = *p->unk_0084 + (sum + 1) / 2;
                    else rank = *p->unk_0084 + sum / 2;
                } else {
                    sum = da->unk_0003 + db->unk_0003;
                    if (sum % 2 == 1) rank = *p->unk_0084 + (sum + 1) / 2;
                    else rank = *p->unk_0084 + sum / 2;
                }
                if (Unk06a224_Unk_06a9fc(183)) rank += 3;
                result = func_020685b0(p, key, rank);
                break;
            }
        }
    }
    return result == 0 ? 6 : 0;
}

/* Initializes the count-by-count pair table and display wrappers. The calls to
   func_02067ef4/func_02075fd0 and the nested slot-id walk establish the pair-table role.
   Requires a nonempty area whose first count keys refer to valid slots, as in the original;
   the last text handle from that walk is forwarded to the list without a zero-count fallback. */
void func_02072374(Unk072238Work *p)
{
    Unk072238Area *w;
    int i;
    u32 text; /* Empty areas forward an indeterminate handle, exactly as in the original. */
    void *first, *other;
    p->unk_03e2 = 0;
    p->panel.selected = 0;
    p->panel.second = 0;
    p->panel.result_id = 0;
    p->panel.unk_002e = 0;
    p->panel.state = 0;
    p->panel.unk_0024 = 0;
    p->mode = 0;
    p->unk_03f4 = 0;
    p->panel.mode = 0;
    p->row = 0;
    p->row_base = 0;
    p->count = 0;
    w = (Unk072238Area *)Unk02e000_GetWorkArea();
    for (i = 0; i < w->entry_count; i++)
        if (w->keys[i] >= 0)
            p->count++;
    for (i = 0; i < 12; i++)
        p->slots[i] = Unk02e000_GetAreaRecord(i);
    func_02067370(p);
    func_02063920();
    for (i = 0; i < p->count; i++) {
        Unk072238Def *def = (Unk072238Def *)func_020a1428(p->slots[w->keys[i]]->id);
        text = func_02063a30(Unk0a163c_Unk_0a1814(def->id));
    }
    func_02061f10(p->names, -1, 0, 0, text);
    if (Unk06a224_Unk_06a224()) {
        if (p->unk_0158 <= 0 || !Unk0e651c_Unk_0e666c(0x702))
            Unk06a224_Unk_06a244(0);
        else {
            func_02063920();
            first = func_020445f4(12, 17);
            other = func_020445f4(24, 0);
            for (i = 0; i < 24; i++) {
                u16 *row = p->rows[i];
                if (!row) {
                    if (i == 0)
                        text = func_02063a30(func_0204fed8(first, 5));
                } else if (*row)
                    text = func_02063a30(func_0204fed8(other, *row));
            }
            func_02061f10(p->row_list, -1, 0, 0, text);
        }
    }
    Unk065e88_Unk_0672fc(p, 17, 6);
    for (i = 0; i < p->count; i++) {
        Unk072238Def *def;
        int j;
        for (j = 0; j < p->count; j++) {
            def = (Unk072238Def *)func_020a1428(
                func_02067ef4(p, p->slots[w->keys[i]]->id, p->slots[w->keys[j]]->id));
            p->panel.matrix[i *p->count + j]
                = func_02075fd0(p, p->slots[w->keys[i]]->id, p->slots[w->keys[j]]->id);
            if (!def->id)
                p->panel.matrix[i *p->count + j] += 9;
            else {
                u16 pair[2];
                pair[0] = p->slots[w->keys[i]]->id;
                pair[1] = p->slots[w->keys[j]]->id;
                if (!func_020698e0(p, pair, 2, def->id))
                    p->panel.matrix[i *p->count + j] += 9;
                if (def->category == 4)
                    p->panel.matrix[i *p->count + j] += 18;
                else if (def->category == 5)
                    p->panel.matrix[i *p->count + j] += 36;
            }
        }
    }
    func_0205c408(p->handles[0]->resource, 0);
    func_0205c6e0(p->handles[0]->resource);
    Unk065e88_SetFlag3a(p->handles[0], 1);
    p->handles[0]->unk_0024 = 18;
    func_0205c408(p->handles[1]->resource, 1);
    func_0205c6e0(p->handles[1]->resource);
    Unk065e88_SetFlag3a(p->handles[1], 1);
    p->handles[1]->unk_0024 = 18;
    func_0205c408(p->handles[2]->resource, 2);
    func_0205c6e0(p->handles[2]->resource);
    Unk065e88_SetFlag3a(p->handles[2], 0);
    p->handles[2]->unk_0024 = 18;
    func_0205c408(p->handles[5]->resource, 5);
    func_0205c6e0(p->handles[5]->resource);
    Unk065e88_SetFlag3a(p->handles[5], 0);
    p->handles[5]->unk_0024 = 18;
    func_0205c408(p->handles[6]->resource, 6);
    func_0205c6f8(p->handles[6]->resource);
    Unk065e88_SetFlag3a(p->handles[6], 0);
    p->handles[6]->unk_0024 = 18;
    func_0205c408(p->handles[7]->resource, 7);
    func_0205c6f8(p->handles[7]->resource);
    Unk065e88_SetFlag3a(p->handles[7], 0);
    p->handles[7]->unk_0024 = 18;
    Unk06a224_Unk_06adc0(2);
}
