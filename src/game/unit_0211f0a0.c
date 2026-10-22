/* src/game/unit_0211f0a0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* 24-byte draw entry consumed by func_0205e048. Field layout is taken from
 * that function's accesses (index at +0, position at +8/+10, size at +12/+14). */
typedef struct Unk11f0a0Entry {
    u32 index;
    u32 unk_04;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 flags;
    u32 unk_14;
} Unk11f0a0Entry;

/* Object passed as the first argument; layout from observed field accesses. */
typedef struct Unk11f0a0Work {
    u32 unk_00;
    void *unk_04;
    u32 unk_08;
    s32 unk_0c;
    u8 pad_10[0x10];
    float unk_20;
    s16 unk_24;
} Unk11f0a0Work;

void func_02008904(void *dst, void *src, u32 size);
Unk11f0a0Entry *func_0205e318(void *mgr, int i);
void func_0205e048(u32 flags, void *mgr, Unk11f0a0Entry *e, int a, int b,
                   float c, float d, int e2, float f, int g, int h);
void func_02057524(int a);
void func_020580ec(int a);
void func_02057df8(void);
void func_02057e18(int a);
void func_02057e30(int a);
void func_02057fd8(void);
void func_02060b60(int screen, u32 obj, int x, int y, int z, int prio);
void func_020572d8(void);

/* Draws three sprite entries around x=128 using the object's width and alpha,
 * then optionally draws a horizontal line centred on the middle entry.
 * Returns without drawing when the object is not fully initialised. */
void func_0211f0a0(Unk11f0a0Work *p)
{
    u32 i;

    if (p->unk_00 == 0 || p->unk_08 == 0 || p->unk_0c == 0 || p->unk_24 == 0) {
        return;
    }
    if (p->unk_20 == 0.0f) {
        return;
    }

    func_02057524(4);
    func_020580ec(0);
    func_02057df8();
    func_02057e18(31);
    func_02057fd8();

    Unk11f0a0Entry entries[3] = {0};

    for (i = 0; i < 3; i++) {
        func_02008904(func_0205e318(p->unk_04, i), &entries[i], 24);
    }

    {
        s16 h = p->unk_24;
        if (h > 0) {
            entries[1].x = 128;
            entries[1].w = h;
            func_0205e048(0x01000001, p->unk_04, &entries[1], 0, 0, 1.0f, 1.0f,
                          0, p->unk_20, 20, 0);
        }
    }

    entries[2].x = 128 - p->unk_24 / 2;
    func_0205e048(0x02000001, p->unk_04, &entries[2], 0, 0, 1.0f, 1.0f, 0,
                  p->unk_20, 20, 0);

    entries[0].x = 128 + p->unk_24 / 2;
    func_0205e048(1, p->unk_04, &entries[0], 0, 0, 1.0f, 1.0f, 0,
                  p->unk_20, 20, 0);

    func_02057df8();
    func_02057e18(31);
    func_02057e30(0);

    if (p->unk_0c == 2) {
        func_02060b60(0x05000001, p->unk_08, 128,
                      entries[1].y + entries[1].h / 2, 0, 21);
    }

    func_020580ec(1);
    func_020572d8();
}
