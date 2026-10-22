/* src/game/unit_02090e60.c: list screen helpers (work layout below).
 *
 * Matched so far: func_020937a0 (text list rebuild) and func_020934c8 (entry refresh).
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
    u8 pad_0038[0x1];
    u8 unk_0039;
} Unk090e60Entry;

/* Shared work area (Unk02e000_GetWorkArea): +0x348 holds twelve signed slots into +0x120[]. */
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
    u8 pad_0108[0x8];
    void *unk_0110;
    void *unk_0114;
    void *unk_0118;
    void *unk_011c;
    Unk090e60Entry *unk_0120[12];
    u8 pad_0150[0x4];
    s16 unk_0154;
    s16 unk_0156;
    u8 pad_0158[0x4];
    void *unk_015c[12]; /* Guessed extent. */
    u8 pad_018c[0x168];
    s16 unk_02f4;
    u8 pad_02f6[0x2];
    u16 unk_02f8[30];
    u8 pad_0334[0x1f];
    s8 unk_0353;
    u8 unk_0354[30];
    u8 unk_0372[30];
    u8 pad_0390[0x8];
    s32 unk_0398;
    s32 unk_039c;
    s32 unk_03a0;
    u8 pad_03a4[0x3c];
    s8 unk_03e0;
    u8 pad_03e1[0x1d];
    u16 unk_03fe;
    u8 pad_0400[0xc];
    u32 *unk_040c[12];
} Unk090e60Work;

void func_020937a0(Unk090e60Work *work, u8 group, int arg2, int arg3);
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
void func_02061f10(void *list, int a, int b, int c, int d);
Unk090e60Meta *func_020a1428(u32 id);
void func_02008848(void *dest, int value, u32 size);
void Unk06a224_Thunk_020d6cac(Unk090e60Bytes *bytes);
void func_02069324(Unk090e60Work *work, Unk090e60Result *record, int group);
int Unk068f18_Unk_06a1a8(Unk090e60Work *work, int key);
void func_02069b24(Unk090e60Work *work, Unk090e60Result *record, void *slot, int level);
void func_0209786c(Unk090e60Result *record);
u32 func_0204fed8(u32 a, u32 b);
int Unk02e000_GetRecordFlag1(u16 id);

/* Rebuild the four text lists (+0x114, +0x118, +0x110, +0x11c) with func_02063920 /
 * func_02063a30 and hand each to func_02061f10. The first two lists cover the twelve slots
 * from +0x39c (an id from +0x2f8, or id 0 when the +0x372 flag is set); the last two cover
 * the twelve ids of `group`. An id counts (and bumps +0x353) when one of the work area's
 * twelve entries carries it or Unk02e000_GetRecordFlag1 accepts it; otherwise id 0 is shown.
 * The last func_02063a30 result goes to func_02061f10 (left unset when no id is visited,
 * as in the ROM). The final two parameters are unused.
 * Evidence: loads, loop bounds and calls in 0x020937a0..0x020939f0. */
void func_020937a0(Unk090e60Work *work, u8 group, int arg2, int arg3)
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
    func_020937a0(work, work->unk_0354[work->unk_02f4], arg2, arg3);

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
