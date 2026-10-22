/* src/game/unit_02072238.c: battle panel list construction and drawing helpers. */
#include "types.h"

/* A record referenced from the slot table at +0x120. Only the id and the byte copied to the
   panel are used by this unit. */
typedef struct Unk072238Slot {
    u8 pad_0000[54];
    u16 id;             /* +0x36 */
    u8 unk_0038;        /* +0x38 */
} Unk072238Slot;

/* Definition returned by func_020a1428 for an id; the original reads the id and the byte at +3. */
typedef struct Unk072238Def {
    u16 id;             /* +0x0 */
    u8 pad_0002[1];
    u8 unk_0003;        /* +0x3 */
} Unk072238Def;

/* Per-row state of the panel; `ids` and `flags` share indices 0..count-1. */
typedef struct Unk072238Panel {
    u8 pad_0000[40];
    s16 selected;       /* +0x28 */
    u8 pad_002a[160];
    u16 ids[12];        /* +0xca */
    u8 flags[12];       /* +0xe2 */
} Unk072238Panel;

/* Object passed as the first argument by Unk065e88_SetMode; layout from the observed accesses.
   The slot array size is guessed from the 12-entry panel arrays; only indices 0..11 are used. */
typedef struct Unk072238Work {
    u8 pad_0000[178];
    u8 count;           /* +0xb2 */
    u8 pad_00b3[97];
    void *list;         /* +0x114 */
    u8 pad_0118[8];
    Unk072238Slot *slots[12]; /* +0x120 */
    u8 pad_0150[8];
    s16 unk_0158;       /* +0x158 */
    u8 pad_015a[166];
    Unk072238Panel panel;     /* +0x200 */
    u8 pad_02ee[10];
    u8 data[60];        /* +0x2f8 */
    u8 pad_0334[30];
    u8 unk_0352;        /* +0x352 */
    u8 pad_0353[142];
    u8 unk_03e1;        /* +0x3e1 */
    u16 unk_03e2;       /* +0x3e2 */
} Unk072238Work;

/* Work area returned by Unk02e000_GetWorkArea; keys map a slot index to an entry id. */
typedef struct Unk072238Area {
    u8 pad_0000[840];
    s8 keys[12];        /* +0x348 */
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
