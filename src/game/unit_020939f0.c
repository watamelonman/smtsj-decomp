/* Work-area helpers; offsets and call contracts follow the original ARM code. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0939f0Work {
    s32 unk_0000;
    s32 unk_0004;
    u32 unk_0008;
    u8 unk_000c;
    u8 unk_000d;
    u8 unk_000e;
    u8 pad_000f[0x1d];
    s32 unk_002c;
    s32 unk_0030;
    s32 unk_0034;
    s32 unk_0038;
    u32 unk_003c;
    u32 unk_0040;
    u32 unk_0044;
    u8 pad_0048[0x4];
    u32 unk_004c;
    u32 unk_0050;
    u32 unk_0054;
    u8 pad_0058[0x4];
    u32 unk_005c;
    u32 unk_0060;
    u32 unk_0064;
    u32 unk_0068;
    u8 unk_006c;
    u8 unk_006d;
    u8 pad_006e[2];
} Unk0939f0Work;

/* Shared block has one leading record, sixteen indexed records and two tails. */
typedef struct Unk0939f0Group {
    Unk0939f0Work first;
    Unk0939f0Work entries[16];
    Unk0939f0Work tail[2];
} Unk0939f0Group;

void func_02057678(void);
/* The original thunk forwards without arguments to func_02057678. */
void Unk0939f0_Thunk_02057678(void) { func_02057678(); }

extern u32 data_02175d8c[];
/* Store the shared word; the original writes directly to data_02175d8c. */
void Unk0939f0_Set_data_02175d8c(u32 arg0)
{
  *data_02175d8c = arg0;
}


/* Return the shared word, as shown by the load from data_02175d8c. */
u32 Unk0939f0_Get_data_02175d8c(void)
{
  return *data_02175d8c;
}

extern u32 data_02175d90[];
void Unk0939f0_Unk_093f0c(Unk0939f0Work *work);
/* Clear fields +8, +0x6c and +0x68 before the original initializer call.
 * o borrows a writable work area of at least 0x70 bytes. */
void Unk0939f0_Reset(Unk0939f0Work *o)
{
    o->unk_0008 = 0;
    o->unk_006c = 0;
    o->unk_0068 = 0;
    Unk0939f0_Unk_093f0c(o);
}

/* Clear the shared handle word; evidence: zero store to data_02175d90. */
void Unk0939f0_Clear_data_02175d90(void)
{
  *data_02175d90 = 0;
}

void func_02070440(u8 *field_0c, u32 *field_60, u32 *field_5c,
                   u32 *field_64, s32 *field_2c, u32 *field_3c, u32 *field_4c);
typedef struct Unk0939f0Ent {
    u8 pad_00[112];
} Unk0939f0Ent;
typedef struct Unk0939f0Ents {
    Unk0939f0Ent e[19];
} Unk0939f0Ents;
void func_02093b6c(int kind, Unk0939f0Ent *entry);

/* Visit 19 writable 0x70-byte entries with kinds 0, sixteen 1s, 2, 3.
 * Evidence: the original loop bound, pointer stride and helper arguments. */
void Unk0939f0_Unk_093b14(Unk0939f0Ents *p)
{
    int i;
    Unk0939f0Ent *e;
    func_02093b6c(0, &p->e[0]);
    for (i = 0, e = &p->e[1]; i < 16; i++, e++) {
        func_02093b6c(1, e);
    }
    func_02093b6c(2, &p->e[17]);
    func_02093b6c(3, &p->e[18]);
}

/* Borrow seven fields for func_02070440 in the original argument order.
 * Evidence: ARM address additions +0xc, +0x60, +0x5c, +0x64, +0x2c,
 * +0x3c and +0x4c; no ownership is transferred. */
void Unk0939f0_Unk_093dbc(Unk0939f0Work *work)
{
    func_02070440(&work->unk_000c, &work->unk_0060, &work->unk_005c,
                 &work->unk_0064, &work->unk_002c, &work->unk_003c,
                 &work->unk_004c);
}


s32 func_0200219c(s32 numerator, s32 denominator);
/* Derive three increments from the +0x2c coordinates; original divisor is 0xd000.
 * The borrowed work area is changed only while the shared handle is nonzero. */
void Unk0939f0_Unk_093ea8(Unk0939f0Work *work)
{
  u32 tmp1;
  if (*data_02175d90 == 0) {
    return;
  }
  tmp1 = func_0200219c(0xff000 - work->unk_002c,0xd000);
  work->unk_003c = tmp1;
  tmp1 = func_0200219c(0xff000 - work->unk_0030,0xd000);
  work->unk_0040 = tmp1;
  tmp1 = func_0200219c(0xff000 - work->unk_0034,0xd000);
  work->unk_0044 = tmp1;
  work->unk_006c = 4;
  return;
}

void func_020086a0(u32 value, void *destination, u32 size);
/* Initialize the borrowed record using the original fill and fixed-point defaults.
 * Evidence: fill at +0xc and stores through +0x64; state at +0x6c is retained. */
void Unk0939f0_Unk_093f0c(Unk0939f0Work *work)
{
  func_020086a0(0, &work->unk_000c, 0x20);
  work->unk_000c = 0xff;
  work->unk_000d = 0xff;
  work->unk_000e = 0xff;
  work->unk_002c = 0xff000;
  work->unk_0030 = 0xff000;
  work->unk_0034 = 0xff000;
  work->unk_003c = 0xff;
  work->unk_0040 = 0xff;
  work->unk_0044 = 0xff;
  work->unk_004c = 0xff;
  work->unk_0050 = 0xff;
  work->unk_0054 = 0xff;
  work->unk_0060 = 0;
  work->unk_005c = 0;
  work->unk_0064 = 0;
  return;
}

void func_02061424(u32 handle);
/* Forward the shared handle to func_02061424; the original loads
 * data_02175d90 immediately before the tail call. Meaning remains unknown. */
void Unk0939f0_Unk_093da4(void)
{
  func_02061424(*data_02175d90);
}

/* Select a borrowed record by kind and byte identifier; evidence: original
 * switch, sixteen +0x6d comparisons, and 0x70-byte record stride. */
Unk0939f0Work *func_02093d14(u32 kind, s32 id)
{
    switch (kind) {
    case 0: return (Unk0939f0Work *)*data_02175d90;
    case 1: {
        s32 i;
        Unk0939f0Work *cursor;
        Unk0939f0Work *base = (Unk0939f0Work *)*data_02175d90;
        cursor = base;
        for (i = 0; i < 16; i++, cursor++) {
            if (id == cursor[1].unk_006d) return &((Unk0939f0Group *)base)->entries[i];
        }
    }
    /* Original unsuccessful scan falls through to the kind-2 record. */
    case 2: return (Unk0939f0Work *)*data_02175d90 + 17;
    case 3: return (Unk0939f0Work *)*data_02175d90 + 18;
    }
    return 0;
}

void func_0206d950(s16 *value, s16 increment, s32 limit);
/* Advance three fixed-point coordinates through the original signed-halfword
 * helper, bounded by 255; the record remains owned by the caller. */
void func_02093dfc(Unk0939f0Work *work)
{
    s16 value = 0;
    value = work->unk_002c >> 12;
    func_0206d950(&value, work->unk_003c >> 12, 255);
    work->unk_002c = value << 12;
    value = work->unk_0030 >> 12;
    func_0206d950(&value, work->unk_0040 >> 12, 255);
    work->unk_0030 = value << 12;
    value = work->unk_0034 >> 12;
    func_0206d950(&value, work->unk_0044 >> 12, 255);
    work->unk_0034 = value << 12;
}

/* Borrowed prefix view: only the four words read by the original are exposed. */
typedef struct Unk0939f0Query {
    u8 pad_0000[216];
    s32 unk_00d8;
    u8 pad_00dc[28];
    s32 unk_00f8;
    u8 pad_00fc[28];
    s32 unk_0118;
    u8 pad_011c[28];
    s32 unk_0138;
} Unk0939f0Query;
extern s32 data_0216bac4[];
Unk0939f0Query *Unk06dddc_Unk_06e058(s32 index);
/* Test the selected positive word in the borrowed query result; evidence:
 * original count bound and switch loads at +0xd8, +0xf8, +0x118, +0x138. */
s32 func_0209432c(u32 kind, s32 index)
{
    if (*data_0216bac4 - 1 - index < 0) return 0;
    switch (kind) {
    case 0: if (Unk06dddc_Unk_06e058(index)->unk_00d8 > 0) return 1; break;
    case 1: if (Unk06dddc_Unk_06e058(index)->unk_00f8 > 0) return 1; break;
    case 2: if (Unk06dddc_Unk_06e058(index)->unk_0118 > 0) return 1; break;
    case 3: if (Unk06dddc_Unk_06e058(index)->unk_0138 > 0) return 1; break;
    }
    return 0;
}

/* Combine the original state-byte tests for the shared group and identifier.
 * Evidence: +0x6c, +0xdc, +0x7dc and +0x84c loads; index zero is excluded. */
s32 func_02094584(s32 id)
{
    s32 i;
    s32 result;
    Unk0939f0Work *cursor;
    Unk0939f0Work *base = (Unk0939f0Work *)*data_02175d90;
    if (base == 0) return 0;
    result = 0;
    if (base->unk_006c != 0) result = 1;
    cursor = base;
    for (i = 0; i < 16; i++, cursor++) {
        if (id == cursor[1].unk_006d) break;
        if (i == 15) { i = -1; break; }
    }
    if (i > 0 && ((Unk0939f0Group *)base)->entries[i].unk_006c != 0) result = 1;
    if (base[17].unk_006c != 0) result = 1;
    if (base[18].unk_006c != 0) result = 1;
    return result;
}

/* Query a selected state byte without transferring the shared storage.
 * Evidence: original kind switch and identifier scan over sixteen records. */
s32 func_0209461c(u32 kind, s32 id)
{
    s32 i;
    Unk0939f0Work *cursor;
    Unk0939f0Work *base = (Unk0939f0Work *)*data_02175d90;
    if (base == 0) return 0;
    switch (kind) {
    case 0: return base->unk_006c != 0;
    case 1: {
        cursor = base;
        for (i = 0; i < 16; i++, cursor++) {
            if (id == cursor[1].unk_006d) return ((Unk0939f0Group *)base)->entries[i].unk_006c != 0;
            if (i == 15) return 0;
        }
    }
    /* Retain the original fallthrough if the bounded scan exhausts. */
    case 2: if (base[17].unk_006c == 0) return 0; return 1;
    case 3: return base[18].unk_006c != 0;
    }
    return 0;
}

Unk0939f0Work *func_020611dc(void (*visit)(Unk0939f0Ents *), u32 a,
    u32 b, void (*clear)(void), u32 size, u32 kind, u32 c, u32 d);
void func_02008848(void *destination, u32 value, u32 size);
/* Allocate and initialize nineteen records, publishing the shared handle only
 * after initialization. Evidence: original 0x850 allocation and 0x70 stride. */
void func_02093a1c(void)
{
    s32 i;
    Unk0939f0Work *base;
    Unk0939f0Work *cursor;
    base = func_020611dc(Unk0939f0_Unk_093b14, 0, 0,
        Unk0939f0_Clear_data_02175d90, 0x850, 3, 0, 0);
    if (base == 0) return;
    func_02008848(base, 0, 0x850);
    Unk0939f0_Unk_093f0c(base);
    for (i = 0, cursor = base + 1; i < 16; i++, cursor++) {
        Unk0939f0_Unk_093f0c(cursor);
    }
    Unk0939f0_Unk_093f0c(base + 17);
    Unk0939f0_Unk_093f0c(base + 18);
    *data_02175d90 = (u32)base;
    {
        Unk0939f0Work *state_cursor;
        s32 j;
        base->unk_006c = 0;
        for (j = 0, state_cursor = base; j < 16; j++, state_cursor++)
            state_cursor[1].unk_006c = 0;
    }
    base[17].unk_006c = 0;
    base[18].unk_006c = 0;
}

void func_020086bc(const void *source, void *destination, u32 size);
const void *Unk06e4d8_Unk_06e4d8(s32 id);
const void *Unk06e4d8_Unk_06e4f0(s32 id);
const void *Unk06e4d8_Unk_06e508(s32 id);
const void *Unk06e4d8_Unk_06e520(s32 id);
void func_0207112c(u8 *bytes, u32 *field_5c, u32 *field_64,
                   u32 *field_3c, u32 *field_4c);
/* Advance the borrowed record's timed state machine. Evidence: original state
 * switch at +0x6c, timing words +0/+4/+8 and kind-selected 32-byte copies. */
void func_02093b6c(int kind, Unk0939f0Ent *entry)
{
    Unk0939f0Work *work = (Unk0939f0Work *)entry;
    u8 saved[8];
    switch (work->unk_006c) {
    case 1:
        if ((s32)work->unk_0008 < work->unk_0000) break;
        switch (kind) {
        case 0:
            func_020086bc(&work->unk_000c, saved, 8);
            func_020086bc(Unk06e4d8_Unk_06e4d8(work->unk_006d), &work->unk_000c, 32);
            func_020086bc(saved, &work->unk_000c, 8);
            break;
        case 1:
            func_020086bc(Unk06e4d8_Unk_06e4f0(work->unk_006d), &work->unk_000c, 32);
            break;
        case 2:
            func_020086bc(Unk06e4d8_Unk_06e508(work->unk_006d), &work->unk_000c, 32);
            break;
        case 3:
            func_020086bc(Unk06e4d8_Unk_06e520(work->unk_006d), &work->unk_000c, 32);
            break;
        }
        work->unk_002c = work->unk_000c << 12;
        work->unk_0030 = work->unk_000d << 12;
        work->unk_0034 = work->unk_000e << 12;
        work->unk_0038 = work->pad_000f[0] << 12;
        func_0207112c(&work->unk_000c, &work->unk_005c, &work->unk_0064,
                      &work->unk_003c, &work->unk_004c);
        work->unk_006c = 2;
    case 2:
        Unk0939f0_Unk_093dbc(work);
        if ((s32)work->unk_0008 < work->unk_0004) break;
        if (work->unk_0068 == 1) work->unk_006c = 3;
        else Unk0939f0_Reset(work);
        break;
    case 3:
        Unk0939f0_Unk_093ea8(work);
    case 4:
        func_02093dfc(work);
        if ((s32)work->unk_0008 < work->unk_0004 + 13) break;
        work->unk_006c = 5;
    case 5:
        Unk0939f0_Reset(work);
        break;
    }
    work->unk_0008++;
}

/* Return the selected duration, adding thirteen ticks for a nonwhite triplet.
 * Evidence: original byte packing at +0xd4/+0xd5/+0xd6 (stride 0x20),
 * comparison against 0xffffff00 and query duration words. */
s32 func_020943dc(u32 kind, s32 index)
{
    u32 packed;
    s32 duration;
    if (!func_0209432c(kind, index)) return 0;
    if (*data_02175d90 == 0) return 0;
    switch (kind) {
    case 0:
        packed = (((u8 *)Unk06dddc_Unk_06e058(index))[0xd4] << 24) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0xd5] << 16) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0xd6] << 8);
        duration = Unk06dddc_Unk_06e058(index)->unk_00d8;
        if (packed != 0xffffff00) return duration + 13;
        return duration;
    case 1:
        packed = (((u8 *)Unk06dddc_Unk_06e058(index))[0xf4] << 24) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0xf5] << 16) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0xf6] << 8);
        duration = Unk06dddc_Unk_06e058(index)->unk_00f8;
        if (packed != 0xffffff00) return duration + 13;
        return duration;
    case 2:
        packed = (((u8 *)Unk06dddc_Unk_06e058(index))[0x114] << 24) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0x115] << 16) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0x116] << 8);
        duration = Unk06dddc_Unk_06e058(index)->unk_0118;
        if (packed != 0xffffff00) return duration + 13;
        return duration;
    case 3:
        packed = (((u8 *)Unk06dddc_Unk_06e058(index))[0x134] << 24) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0x135] << 16) |
                 (((u8 *)Unk06dddc_Unk_06e058(index))[0x136] << 8);
        duration = Unk06dddc_Unk_06e058(index)->unk_0138;
        if (packed != 0xffffff00) return duration + 13;
        return duration;
    }
    return 0;
}

extern u8 data_0216bb9c[];
extern u8 data_0216bb9d[];
extern u8 data_0216bb9e[];
extern s32 data_0216bba0[];
extern u8 data_0216bbbc[];
extern u8 data_0216bbbd[];
extern u8 data_0216bbbe[];
extern s32 data_0216bbc0[];
extern u8 data_0216bbdc[];
extern u8 data_0216bbdd[];
extern u8 data_0216bbde[];
extern s32 data_0216bbe0[];
extern u8 data_0216bbfc[];
extern u8 data_0216bbfd[];
extern u8 data_0216bbfe[];
extern s32 data_0216bc00[];
/* Set up active records from the indexed table. Evidence: original four
 * availability checks, 0x148-byte table stride and sixteen-slot state scan.
 * The shared group must already exist; records remain borrowed. */
void func_02093f70(s32 index)
{
    Unk0939f0Work *work;
    s32 z, y, x;
    u32 packed;
    if (func_0209432c(0, index)) {
        if (func_0209461c(0, index)) {
            work = func_02093d14(0, 0);
            x = work->unk_002c >> 12;
            y = work->unk_0030 >> 12;
            z = work->unk_0034 >> 12;
            Unk0939f0_Unk_093f0c(work);
            work->unk_000c = x;
            work->unk_000d = y;
            work->unk_000e = z;
        }
        func_02093d14(0, 0)->unk_0008 = 0;
        func_02093d14(0, 0)->unk_006c = 1;
        func_02093d14(0, 0)->unk_006d = index;
        packed = (data_0216bb9c[index * 0x148] << 24) |
                 (data_0216bb9d[index * 0x148] << 16) |
                 (data_0216bb9e[index * 0x148] << 8);
        func_02093d14(0, 0)->unk_0004 = *(s32 *)((u8 *)data_0216bba0 + index * 0x148);
        if (packed != 0xffffff00)
            func_02093d14(0, 0)->unk_0068 = 1;
        else
            func_02093d14(0, 0)->unk_0068 = 2;
    }
    if (func_0209432c(1, index)) {
        s32 i;
        Unk0939f0Work *cursor;
        Unk0939f0Work *base = (Unk0939f0Work *)*data_02175d90;
        cursor = base;
        for (i = 0; i < 16; i++, cursor++) {
            if (cursor[1].unk_006c == 0) {
                ((Unk0939f0Group *)base)->entries[i].unk_006d = index;
                break;
            }
        }
        func_02093d14(1, index)->unk_0008 = 0;
        func_02093d14(1, index)->unk_006c = 1;
        packed = (data_0216bbbc[index * 0x148] << 24) |
                 (data_0216bbbd[index * 0x148] << 16) |
                 (data_0216bbbe[index * 0x148] << 8);
        func_02093d14(1, index)->unk_0004 = *(s32 *)((u8 *)data_0216bbc0 + index * 0x148);
        if (packed != 0xffffff00)
            func_02093d14(1, index)->unk_0068 = 1;
        else
            func_02093d14(1, index)->unk_0068 = 2;
    }
    if (func_0209432c(2, index)) {
        func_02093d14(2, 0)->unk_0008 = 0;
        func_02093d14(2, 0)->unk_006c = 1;
        func_02093d14(2, 0)->unk_006d = index;
        packed = (data_0216bbdc[index * 0x148] << 24) |
                 (data_0216bbdd[index * 0x148] << 16) |
                 (data_0216bbde[index * 0x148] << 8);
        func_02093d14(2, 0)->unk_0004 = *(s32 *)((u8 *)data_0216bbe0 + index * 0x148);
        if (packed != 0xffffff00)
            func_02093d14(2, 0)->unk_0068 = 1;
        else
            func_02093d14(2, 0)->unk_0068 = 2;
    }
    if (func_0209432c(3, index)) {
        func_02093d14(3, 0)->unk_0008 = 0;
        func_02093d14(3, 0)->unk_006c = 1;
        func_02093d14(3, 0)->unk_006d = index;
        packed = (data_0216bbfc[index * 0x148] << 24) |
                 (data_0216bbfd[index * 0x148] << 16) |
                 (data_0216bbfe[index * 0x148] << 8);
        func_02093d14(3, 0)->unk_0004 = *(s32 *)((u8 *)data_0216bc00 + index * 0x148);
        if (packed != 0xffffff00)
            func_02093d14(3, 0)->unk_0068 = 1;
        else
            func_02093d14(3, 0)->unk_0068 = 2;
    }
}
