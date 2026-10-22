/* src/game/unit_02090e60.c: list screen helpers (work layout below).
 *
 * Matched so far: func_02092624 (per-frame draw), Unk090e60_Unk_0937a0 (text list rebuild)
 * and func_020934c8 (entry refresh).
 * The remaining functions in this translation unit are still linked from the delinked
 * original; see docs/functions/game-unit-02090e60.md for the hard-function notes.
 */
#include "types.h"

typedef struct Unk090e60Group {
    u16 unk_00;
    u16 unk_02[12];
    u16 unk_1a;
} Unk090e60Group;

/* Six byte pairs; the copy forwarded through Unk06a224_Thunk_020d6cac lands in
 * CampStatus_Copy168, which takes the same CampStatusPairs6 shape. */
typedef struct Unk090e60Pair {
    u8 unk_00;
    u8 unk_01;
} Unk090e60Pair;

typedef struct Unk090e60Bytes {
    Unk090e60Pair p[6];
} Unk090e60Bytes;

/* Record metadata returned by func_020a1428 (same layout as Unk100810Meta). */
typedef struct Unk090e60Meta {
    u16 id;
    u8 unk_02;
    u8 unk_03;
    u8 pad_04[0x10];
    u16 unk_14;
    u16 unk_16;
    u8 pad_18[2];
    u8 stats[5];
    u8 pad_1f[15];
    Unk090e60Bytes bytes_2e;
} Unk090e60Meta;

/* 60-byte working record consumed by func_0209786c (same layout as Unk100810Result). */
typedef struct Unk090e60Result {
    u16 unk_00;
    u16 unk_02;
    u8 stats[5];
    u8 pad_09;
    s16 unk_0a;
    s16 unk_0c;
    u8 pad_0e[6];
    u16 unk_14;
    u16 unk_16;
    u8 stats_18[5];
    u8 pad_1d;
    s16 unk_1e;
    s16 unk_20;
    u8 pad_22[6];
    Unk090e60Bytes bytes_28;
    u16 unk_34;
    u16 id;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3a[2];
} Unk090e60Result;

/* Entry pointed to by +0x120[]: +0x36 is compared with group record ids, +0x39 is summed
 * by func_020935b8. */
typedef struct Unk090e60Entry {
    u8 pad_0000[0x36];
    u16 unk_0036;
    u8 unk_0038;
    u8 unk_0039;
} Unk090e60Entry;

/* Shared work area (Unk02e000_GetWorkArea): +0x348 holds twelve signed slots into +0x120[]. */
/* Text list owner (+0x108, +0x110..+0x11c, +0x150): word 0 is the text handle passed to
 * func_02059f70; the signed byte at +0x40 gates the per-row draw helpers. */
typedef struct Unk090e60List {
    u32 unk_0000;
    u8 pad_0004[0x3c];
    s8 unk_0040;
} Unk090e60List;

/* 24-byte draw clip copied from func_0205e318's result; +0x0e is the bar height. */
typedef struct Unk090e60Clip {
    u8 pad_0000[0xe];
    s16 unk_000e;
    u8 pad_0010[0x8];
} Unk090e60Clip;

/* Slot record pointed to by +0x15c[]; a zero first halfword marks an empty slot. */
typedef struct Unk090e60Slot {
    u16 unk_0000;
} Unk090e60Slot;

typedef struct Unk090e60Area {
    u8 pad_0000[0x348];
    s8 unk_0348[12];
} Unk090e60Area;

/* Work layout shared by the screen functions in this unit. */
typedef struct Unk090e60Work {
    u8 pad_0000[0x94];
    Unk090e60Group *unk_0094;
    u8 pad_0098[0x14];
    Unk090e60Pair *unk_00ac;
    u8 pad_00b0[0x1c];
    Unk090e60Result unk_00cc;
    Unk090e60List *unk_0108;
    void *unk_010c;
    Unk090e60List *unk_0110;
    Unk090e60List *unk_0114;
    Unk090e60List *unk_0118;
    Unk090e60List *unk_011c;
    Unk090e60Entry *unk_0120[12];
    Unk090e60List *unk_0150;
    s16 unk_0154;
    s16 unk_0156;
    u8 pad_0158[0x4];
    Unk090e60Slot *unk_015c[24]; /* Twenty-four slots: func_02092624 loops i < 24. */
    u8 pad_01bc[0x134];
    u32 unk_02f0;
    s16 unk_02f4;
    u8 pad_02f6[0x2];
    u16 unk_02f8[30];
    u8 unk_0334[30];
    u8 unk_0352;
    s8 unk_0353;
    u8 unk_0354[30];
    u8 unk_0372[30];
    s32 unk_0390;
    u8 pad_0394[0x4];
    s32 unk_0398;
    s32 unk_039c;
    s32 unk_03a0;
    s32 unk_03a4;
    u8 pad_03a8[0x8];
    u32 unk_03b0;
    u8 pad_03b4[0x2c];
    s8 unk_03e0;
    u8 pad_03e1[0x6];
    u8 unk_03e7;
    u8 pad_03e8[0x16];
    u16 unk_03fe;
    u8 pad_0400[0xc];
    u32 *unk_040c[12];
} Unk090e60Work;

void Unk090e60_Unk_0937a0(Unk090e60Work *work, u8 group, int arg2, int arg3);
void func_0205c6f8(u32 value);
void Unk065e88_SetFlag3a(u32 *entry, int flag);
int Unk02f078_GetEntry5e12Bit0(u8 index);
void func_0205cac0(u32 value);
void Unk06a224_Unk_06adc0(int id);

Unk090e60Area *Unk02e000_GetWorkArea(void);
u32 func_020445f4(u32 group, u32 index);
void func_02063920(void);
u32 Unk0a163c_Unk_0a1814(u32 id);
int func_02063a30(u32 id);
void func_02061f10(Unk090e60List *list, int a, int b, int c, int d);
Unk090e60Meta *func_020a1428(u32 id);
void func_02008848(void *dest, int value, u32 size);
void Unk06a224_Thunk_020d6cac(Unk090e60Bytes *bytes);
void func_02069324(Unk090e60Work *work, Unk090e60Result *record, int group);
int Unk068f18_Unk_06a1a8(Unk090e60Work *work, int key);
void func_02069b24(Unk090e60Work *work, Unk090e60Result *record, void *slot, int level);
void func_0209786c(Unk090e60Result *record);
u32 func_0204fed8(u32 a, u32 b);
int Unk02e000_GetRecordFlag1(u16 id);
/* Shared ticker (see CampStatus.c); +0x18 feeds the blink alpha of func_02069ec8. */
typedef struct Unk090e60Ticker {
    u8 pad_0000[0x18];
    s32 unk_0018;
} Unk090e60Ticker;
extern Unk090e60Ticker data_0215f05c;
extern char data_0214c6a0[]; /* "%d" */
extern char data_0214c6a4[]; /* "%d" */
extern char data_0214c6a8[]; /* "%d" */
void func_02057e18(u32 alpha);
void func_02057fd8(void);
void func_02057df8(void);
void func_02057eb8(s32 value);
void func_02057524(u32 mode);
void func_02057534(void);
void func_02057dcc(u32 a, u32 b, u32 c, u32 d);
void func_02057d54(u32 color, int x, int y, int width, int height, int flags);
void func_0205dee8(int screen, u32 obj, int frame, int x, int y, float sx, float sy, int rot, float alpha, int prio);
void func_0205e048(int screen, u32 obj, Unk090e60Clip *clip, int x, int y, float sx, float sy, int rot, float alpha, int prio, int extra);
const Unk090e60Clip *func_0205e318(u32 obj, int index);
void func_02008904(const void *src, void *dst, u32 size);
void func_02058e9c(int screen, u32 res, int x, int y, float scale, int a, int b);
void func_02060dd4(void *out, Unk090e60List *list, int a, int b, int c);
void func_02059f70(u32 text, u32 arg1, s32 x, s32 y, void *options, u32 arg5, u32 arg6);
void func_020a9fd8(u32 mode, s32 x, s32 y, u32 arg3, u32 arg4, u32 arg5, const char *fmt, u32 value);
float func_02069ec8(s32 phase);
void func_0206a124(Unk090e60Work *work);
void func_02069f50(Unk090e60Work *work);
void func_02067c88(void *owner);
void func_02067564(Unk090e60List *owner, const void *descriptor, u16 id, int arg, s16 value);
void func_020674a4(Unk090e60List *owner, const void *descriptor, u16 id, int arg, s16 value);
void func_02067634(Unk090e60List *owner, const void *descriptor, const Unk090e60Entry *entry, int arg, s16 value);
void func_020679a0(Unk090e60List *owner, const Unk090e60Entry *entry, int arg, int value, u16 offset);
void func_02067888(Unk090e60List *owner, u16 id, int arg, int value, u16 offset);
void func_02067b28(Unk090e60Work *owner, int value, int x, int y);
int Unk096754_Unk_096ab0(int index);

/* Per-frame draw for the list screen. Draws the frame (+0x3b0 cells), then by state +0x390:
 * states 0/5/6/11 draw the scroll bar, the twelve rows from +0x39c (ids +0x2f8) and the
 * twelve ids of the current group (+0x94 table) with their entry or record labels, plus a
 * fade-in rectangle in states 5/6 from +0x3e7; states 1/2 draw the 24-slot grid (+0x15c)
 * and its cursor (+0x154/+0x156); states 3/4/7 draw the dimming rectangle.
 * Evidence: the jump table at 0x020926a4 and the call sequence through 0x020934ac. */
void func_02092624(Unk090e60Work *work)
{
    u8 text[16];
    Unk090e60Clip clip;
    s32 start;
    s32 i;
    s32 j;
    s32 k;
    s32 scroll;
    s32 row;
    s32 y;
    s32 ty;
    Unk090e60Meta *meta;
    Unk090e60Area *area;
    u8 group;
    int found;
    u32 n; /* entry count in the scroll-bar block, then a row index copy (shared in the ROM) */
    u32 bar;
    s16 height;
    u8 alpha;

    if (work->unk_02f0 != 0) {
        return;
    }
    if (work->unk_03b0 == 0) {
        return;
    }
    func_02057e18(31);
    func_02057fd8();
    func_02057df8();
    func_0205dee8(1, work->unk_03b0, 1, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
    func_0206a124(work);

    switch (work->unk_0390) {
    case 0:
    case 5:
    case 6:
    case 11:
        func_02057fd8();
        func_02057df8();
        func_02060dd4(text, work->unk_0108, 0, 2, 25);
        func_02059f70(work->unk_0108->unk_0000, 0, 2, 3, text, 0, 2);
        func_02057df8();
        func_0205dee8(1, work->unk_03b0, 91, 0, 0, 1.0f, 1.0f, 0, 1.0f, 2);
        func_02057fd8();
        func_0205dee8(1, work->unk_03b0, 90, 0, 0, 1.0f, 1.0f, 0, 1.0f, 10);
        if (work->unk_0352 > 12) {
            func_0205dee8(2, work->unk_03b0, 102, 0, 0, 1.0f, 1.0f, 0, 1.0f, 0);
            func_02008904(func_0205e318(work->unk_03b0, 0x1cf), &clip, sizeof(clip));
            n = work->unk_0352;
            height = clip.unk_000e;
            if (n < 12) {
                n = 12;
            }
            bar = (0xc000 / n) * height;
            y = ((height - (bar >> 12)) * (((u32)work->unk_039c << 12) / (n - 12))) >> 12;
            clip.unk_000e = bar >> 12;
            func_0205e048(2, work->unk_03b0, &clip, 0, y, 1.0f, 1.0f, 0, 1.0f, 4, 0);
        }
        start = work->unk_039c;
        func_02057fd8();
        func_02057df8();
        func_0205dee8(2, work->unk_03b0, 16, 0, (1 - (work->unk_03a4 - work->unk_039c)) * -11,
                      1.0f, 1.0f, 0, 1.0f, 6);
        func_02057fd8();
        scroll = work->unk_03a4 - work->unk_039c;
        func_0205dee8(2, work->unk_03b0, 15, 0, (1 - scroll) * -11,
                      1.0f, 1.0f, 0, func_02069ec8(data_0215f05c.unk_0018), 7);
        func_02057e18(31);
        func_02067c88(work->unk_010c);

        /* k and n are per-iteration copies of i (the ROM keeps three registers). */
        for (k = n = i = start; i < start + 12; k = n = ++i) {
            func_02057eb8(5);
            func_02057fd8();
            if (work->unk_02f8[k] == 0) {
                break;
            }
            row = k - start;
            func_02057df8();
            func_0205dee8(2, work->unk_03b0, row % 2 == 0 ? 94 : 93, 0, row / 2 * 22,
                          1.0f, 1.0f, 0, 1.0f, 2);
            func_02057fd8();
            y = row * 11;
            func_0205dee8(1, work->unk_03b0, 92, 0, y, 1.0f, 1.0f, 0, 1.0f, 4);
            func_02057e18(31);
            meta = func_020a1428(work->unk_02f8[n]);
            func_02057fd8();
            if (work->unk_0372[n] != 0) {
                func_02060dd4(text, work->unk_0114, 0, row, 10);
                func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
                func_02059f70(work->unk_0114->unk_0000, 0, 36, (s16)(y + 35), text, 0, 10);
            } else if (work->unk_0334[n] == 0) {
                func_02060dd4(text, work->unk_0118, 0, row, 5);
                ty = y + 34;
                func_02067564(work->unk_0118, text, meta->id, 4, (s16)ty);
                func_02060dd4(text, work->unk_0114, 0, row, 10);
                func_02067564(work->unk_0114, text, meta->id, 36, (s16)ty);
                func_02057df8();
                func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
                func_020a9fd8(1, 112, (s16)(y + 35), 2, 2, 10, data_0214c6a0, meta->unk_03);
            } else {
                func_02060dd4(text, work->unk_0118, 0, row, 5);
                ty = y + 34;
                func_020674a4(work->unk_0118, text, meta->id, 4, (s16)ty);
                func_02060dd4(text, work->unk_0114, 0, row, 10);
                func_020674a4(work->unk_0114, text, meta->id, 36, (s16)ty);
                func_02057df8();
                func_020a9fd8(1, 112, (s16)(y + 35), 2, 2, 10, data_0214c6a4, meta->unk_03);
            }
        }
        func_02057fd8();
        func_02057df8();
        func_0205dee8(2, work->unk_03b0, 95, 0, (k - start - 1) * 11, 1.0f, 1.0f, 0, 1.0f, 4);

        area = Unk02e000_GetWorkArea();
        group = work->unk_0354[work->unk_02f4];
        for (i = 0; i < 12; i++) {
            if (work->unk_0094[group].unk_02[i] != 0) {
                func_02057eb8(5);
                func_02057fd8();
                func_02057df8();
                func_02058e9c(2, 0x162f + i, 0, 0, 1.0f, 0, 3);
                meta = func_020a1428(work->unk_0094[group].unk_02[i]);
                func_02060dd4(text, work->unk_0110, 0, i, 10);
                found = 0;
                for (j = 0; j < 12; j++) {
                    if (work->unk_0120[area->unk_0348[j]]->unk_0036 == work->unk_0094[group].unk_02[i]) {
                        found = 1;
                        break;
                    }
                }
                if (found != 0) {
                    func_02057fd8();
                    if (Unk096754_Unk_096ab0(area->unk_0348[j]) == 0) {
                        func_0205dee8(2, work->unk_03b0, 99, 0, i * 11, 1.0f, 1.0f, 0, 1.0f, 2);
                    } else {
                        func_0205dee8(2, work->unk_03b0, i % 2 == 0 ? 97 : 98, 0, i / 2 * 22,
                                      1.0f, 1.0f, 0, 1.0f, 2);
                    }
                    func_02057fd8();
                    func_0205dee8(1, work->unk_03b0, 96, 0, i * 11, 1.0f, 1.0f, 0, 1.0f, 5);
                    func_02057e18(31);
                    func_02057fd8();
                    if (work->unk_0110->unk_0040 == 0) {
                        func_02067634(work->unk_0110, text, work->unk_0120[area->unk_0348[j]], 173,
                                      (s16)(i * 11 + 34));
                    }
                    if (work->unk_011c->unk_0040 == 0) {
                        func_020679a0(work->unk_011c, work->unk_0120[area->unk_0348[j]], 141,
                                      (s16)(i * 11 + 34), (u16)i);
                    }
                    if (Unk096754_Unk_096ab0(area->unk_0348[j]) == 0) {
                        func_02057dcc(0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff, 0x7b7b7bff);
                    } else {
                        func_02057df8();
                    }
                    func_020a9fd8(1, 249, (s16)(i * 11 + 35), 2, 2, 10, data_0214c6a8,
                                  work->unk_0120[area->unk_0348[j]]->unk_0038);
                } else {
                    func_02057fd8();
                    func_0205dee8(2, work->unk_03b0, i % 2 == 0 ? 97 : 98, 0, i / 2 * 22,
                                  1.0f, 1.0f, 0, 1.0f, 2);
                    func_02057fd8();
                    func_0205dee8(1, work->unk_03b0, 96, 0, i * 11, 1.0f, 1.0f, 0, 1.0f, 5);
                    func_02057e18(31);
                    if (Unk02e000_GetRecordFlag1(work->unk_0094[group].unk_02[i]) != 0) {
                        if (work->unk_0110->unk_0040 == 0) {
                            func_02067564(work->unk_0110, text, meta->id, 173, (s16)(i * 11 + 34));
                        }
                        if (work->unk_011c->unk_0040 == 0) {
                            func_02067888(work->unk_011c, meta->id, 141, (s16)(i * 11 + 34), (u16)i);
                        }
                        func_02067b28(work, meta->unk_03, 249, (s16)(i * 11 + 35));
                    } else {
                        if (work->unk_0110->unk_0040 == 0) {
                            func_02067564(work->unk_0110, text, 0, 173, (s16)(i * 11 + 34));
                        }
                        if (work->unk_011c->unk_0040 == 0) {
                            func_02067888(work->unk_011c, meta->id, 141, (s16)(i * 11 + 34), (u16)i);
                        }
                        func_02067b28(work, meta->unk_03, 249, (s16)(i * 11 + 35));
                    }
                }
            } else {
                func_02057df8();
                func_0205dee8(2, work->unk_03b0, 100, 0, (i - 1) * 11, 1.0f, 1.0f, 0, 1.0f, 4);
                break;
            }
        }
        if ((u32)(work->unk_0390 - 5) <= 1) {
            func_02057524(6);
            func_02057fd8();
            alpha = work->unk_03e7 * 24 / 16;
            if (alpha >= 1) {
                func_02057e18(alpha);
                func_02057d54(0, 0, 0, 256, 192, 21);
                func_02057e18(31);
            }
            func_02057534();
        }
        break;
    case 1:
    case 2:
        func_02069f50(work);
        func_02057fd8();
        func_02057df8();
        func_02060dd4(text, work->unk_0108, 0, 3, 25);
        func_02059f70(work->unk_0108->unk_0000, 0, 2, 3, text, 0, 2);
        func_02057df8();
        func_02057fd8();
        func_02057df8();
        for (i = 0; i < 24; i++) {
            if (work->unk_015c[i] == 0) {
                if (i == 0) {
                    func_02060dd4(text, work->unk_0150, 0, i, 10);
                    func_02059f70(work->unk_0150->unk_0000, 0, i % 2 * 107 + 30, i / 2 * 11 + 43,
                                  text, 0, 10);
                }
            } else if (work->unk_015c[i]->unk_0000 != 0) {
                func_02060dd4(text, work->unk_0150, 0, i, 10);
                func_02059f70(work->unk_0150->unk_0000, 0, i % 2 * 107 + 30, i / 2 * 11 + 43,
                              text, 0, 10);
            }
        }
        func_02057fd8();
        func_02057df8();
        func_0205dee8(2, work->unk_03b0, 14, work->unk_0154 % 2 * 107,
                      (work->unk_0154 - work->unk_0156) / 2 * 11, 1.0f, 1.0f, 0, 1.0f, 6);
        func_02057fd8();
        func_0205dee8(2, work->unk_03b0, 13, work->unk_0154 % 2 * 107,
                      (work->unk_0154 - work->unk_0156) / 2 * 11, 1.0f, 1.0f, 0,
                      func_02069ec8(data_0215f05c.unk_0018), 7);
        func_02057e18(31);
        func_02067c88(work->unk_010c);
        break;
    case 3:
    case 4:
    case 7:
        func_02067c88(work->unk_010c);
        func_02057524(6);
        func_02057fd8();
        func_02057e18(24);
        func_02057d54(0, 0, 0, 256, 192, 21);
        func_02057e18(31);
        func_02057534();
        break;
    }
    func_02057e18(31);
}

/* Rebuild the four text lists (+0x114, +0x118, +0x110, +0x11c) with func_02063920 /
 * func_02063a30 and hand each to func_02061f10. The first two lists cover the twelve slots
 * from +0x39c (an id from +0x2f8, or id 0 when the +0x372 flag is set); the last two cover
 * the twelve ids of `group`. An id counts (and bumps +0x353) when one of the work area's
 * twelve entries carries it or Unk02e000_GetRecordFlag1 accepts it; otherwise id 0 is shown.
 * The last func_02063a30 result goes to func_02061f10 (left unset when no id is visited,
 * as in the ROM). The final two parameters are unused.
 * Evidence: loads, loop bounds and calls in 0x020937a0..0x020939f0. */
void Unk090e60_Unk_0937a0(Unk090e60Work *work, u8 group, int arg2, int arg3)
{
    s32 i;
    int text;
    Unk090e60Area *area;
    u32 names;
    s32 start;
    int found;
    s32 j;
    u16 id;

    area = Unk02e000_GetWorkArea();
    names = func_020445f4(18, 0);

    func_02063920();
    start = work->unk_039c;
    for (j = i = start; i < start + 12; j = ++i) {
        if (work->unk_0372[j] != 0) {
            text = func_02063a30(Unk0a163c_Unk_0a1814(0));
        } else {
            text = func_02063a30(Unk0a163c_Unk_0a1814(work->unk_02f8[j]));
        }
    }
    func_02061f10(work->unk_0114, -1, 0, 0, text);

    func_02063920();
    for (i = start; i < start + 12; i++) {
        if (work->unk_02f8[i] != 0) {
            text = func_02063a30(func_0204fed8(names, func_020a1428(work->unk_02f8[i])->unk_02));
        }
    }
    func_02061f10(work->unk_0118, -1, 0, 0, text);

    work->unk_0353 = 0;
    func_02063920();
    for (i = 0; i < 12; i++) {
        id = work->unk_0094[group].unk_02[i];
        if (id != 0) {
            found = 0;
            for (j = 0; j < 12; j++) {
                if (work->unk_0120[area->unk_0348[j]]->unk_0036 == work->unk_0094[group].unk_02[i]) {
                    found = 1;
                }
            }
            if (found != 0 || Unk02e000_GetRecordFlag1(id) != 0) {
                text = func_02063a30(Unk0a163c_Unk_0a1814(work->unk_0094[group].unk_02[i]));
                work->unk_0353 = work->unk_0353 + 1;
            } else {
                text = func_02063a30(Unk0a163c_Unk_0a1814(0));
            }
        }
    }
    func_02061f10(work->unk_0110, -1, 0, 0, text);

    func_02063920();
    for (i = 0; i < 12; i++) {
        if (work->unk_0094[group].unk_02[i] != 0) {
            text = func_02063a30(func_0204fed8(names, func_020a1428(work->unk_0094[group].unk_02[i])->unk_02));
        }
    }
    func_02061f10(work->unk_011c, -1, 0, 0, text);
}

/* Clear +0x353, rebuild the current group, and refresh the twelve entry flags.
 * Evidence: the indexed +0x354 loads and twelve +0x40c pointers below. The
 * signed flag at +0x3e0 gates and is cleared before the helper call with id 14.
 * The second parameter is unused; the final two pass through to the builder. */
void func_020934c8(Unk090e60Work *work, int mode, int arg2, int arg3)
{
    s32 i;
    s32 start;

    work->unk_0353 = 0;
    Unk090e60_Unk_0937a0(work, work->unk_0354[work->unk_02f4], arg2, arg3);

    start = work->unk_039c;
    if (start - work->unk_03a0 != 0) {
        i = 0;
        do {
            func_0205c6f8(*work->unk_040c[i]);
            Unk065e88_SetFlag3a(work->unk_040c[i], 0);
            i++;
        } while (i < 12);

        for (i = start; i < start + 12; i++) {
            if (i < work->unk_0398 &&
                Unk02f078_GetEntry5e12Bit0(work->unk_0354[i]) != 0) {
                Unk065e88_SetFlag3a(work->unk_040c[i - start], 1);
                func_0205cac0(*work->unk_040c[i - start]);
            }
        }
    }

    if (work->unk_03e0 == 0) {
        return;
    }
    work->unk_03e0 = 0;
    Unk06a224_Unk_06adc0(14);
}
