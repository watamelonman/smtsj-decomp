/* Record-bank and grid helpers matched against the original ARM code. */
#include "types.h"


#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02008848(void *destination, int value, u32 size);
/* The +0x0c occupancy load in the original selects the first unused 16-byte record. */
int Unk0a6174_FindFree0c(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][12] == 0) {
            return j;
        }
    }
    return -1;
}

/* The +0x10d occupancy load scans the second bank of sixteen records. */
int Unk0a6174_FindFree10d(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][269] == 0) {
            return j;
        }
    }
    return -1;
}

/* Four-byte weighted entries; the selection routine consumes exactly eight. */
typedef struct Unk0a6174Slot {
    u8 pad_00[2];
    u8 weight;
    u8 pad_03;
} Unk0a6174Slot;
int func_02050074(int lower, int upper);

/* Select an entry using the eight byte weights; zero total weight returns null. */
Unk0a6174Slot *Unk0a6174_Unk_0a6548(Unk0a6174Slot *p)
{
    u32 sum = 0;
    u8 acc;
    u32 r;
    int i;
    for (i = 0; i < 8; i++) {
        sum += p[i].weight;
    }
    if ((s32)sum <= 0) {
        return 0;
    }
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < 8; i++) {
        acc += p[i].weight;
        if (r < acc) {
            return &p[i];
        }
    }
    return 0;
}

/* Original clear calls establish buffer sizes 0xe14 and 0x200; both must exist. */
void Unk0a6174_ClearBuffers(u8 *a, u8 *b)
{
    if (a == 0 || b == 0) {
        return;
    }
    func_02008848(a, 0, 0xe14);
    func_02008848(b, 0, 512);
}

/* Original shifted add computes an unchecked 16-byte record address. */
int Unk0a6174_Unk_0a6aac(int arg0,int arg1)
{
  return arg0 + arg1 * 0x10;
}

/* Original +0x100 and shifted add address the second record bank. */
int Unk0a6174_Unk_0a6ab4(int arg0,int arg1)
{
  return arg0 + 0x100 + arg1 * 0x10;
}

int Unk02f2a8_GridIndex45(u32 x, u32 y);
/* Original GridIndex45 call indexes two-byte cells; a null base returns zero. */
int Unk0a6174_Unk_0a6a88(int arg0,u32 arg1,u32 arg2)
{
  int value;
  if (arg0 != 0) {
    value = Unk02f2a8_GridIndex45(arg1,arg2);
    return arg0 + value * 2;
  }
  return 0;
}



/* Original stores at +0..+0xd fill a free first-bank record; index must be 0..15.
 * The occupancy byte at +0xc rejects an already occupied record without mutation. */
int func_020a61a0(u8 *base, u32 value, u16 a, u16 b,
                  u8 c, u8 d, s8 e, s8 f, int g, int index)
{
    u8 *record = base + index * 16;
    if (record[12] != 0) {
        return 0;
    }
    record[12] = 1;
    FIELD(u32, record, 0) = value;
    FIELD(u16, record, 4) = a;
    FIELD(u16, record, 6) = b;
    record[8] = c;
    record[9] = d;
    record[10] = e;
    record[11] = f;
    record[13] = g;
    return 1;
}


int Unk02f2a8_IsInGrid45x40(u32 x, u32 y);
int Unk094fe0_Call_020950b4(int id);

/* Original grid bounds call and signed occupancy byte reject invalid/used cells. */
int func_020a6280(u8 *grid, u32 x, u32 y, s8 kind, u8 index)
{
    u8 *cell;
    if (grid == 0) return 0;
    if (!Unk02f2a8_IsInGrid45x40(x, y)) return 0;
    cell = grid + Unk02f2a8_GridIndex45(x, y) * 2;
    if (*(s8 *)cell != 0) return 0;
    cell[0] = kind;
    cell[1] = index;
    return 1;
}

/* Eight four-byte entries use a nonzero halfword key and byte weight at +3. */
typedef struct Unk0a6174KeySlot {
    u16 key;
    u8 other;
    u8 weight;
} Unk0a6174KeySlot;

/* Original +0/+3 loads stop at the first zero key (at most eight entries).
 * The caller owns the entries; the cumulative byte weight wraps modulo 256. */
Unk0a6174KeySlot *func_020a63cc(Unk0a6174KeySlot *p)
{
    u32 sum = 0;
    u8 acc;
    u32 r;
    int i;
    for (i = 0; i < 8; i++) {
        if (p[i].key == 0) break;
        sum += p[i].weight;
    }
    if ((s32)sum <= 0) return 0;
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < 8; i++) {
        if (p[i].key == 0) break;
        acc += p[i].weight;
        if (r < acc) return &p[i];
    }
    return 0;
}

/* Original signed IDs at +12/+16 enable boolean provider checks when nonnegative. */
int func_020a6848(u8 *p)
{
    int result = 1;
    int expected;
    if (FIELD(s16, p, 12) > -1) {
        expected = FIELD(u16, p, 14) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 12))) result = 0;
    }
    if (FIELD(s16, p, 16) > -1) {
        expected = FIELD(u16, p, 18) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 16))) result = 0;
    }
    return result;
}

/* Original +16/+20 IDs gate checks; the stored result is normalized twice. */
int func_020a68b4(u8 *p)
{
    int result = 1;
    int expected;
    if (FIELD(s16, p, 16) > -1) {
        expected = FIELD(u16, p, 18) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 16))) result = 0;
    }
    if (FIELD(s16, p, 20) > -1) {
        expected = FIELD(u16, p, 22) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 20))) result = 0;
    }
    {
        u32 normalized = 0;
        if (result) normalized = 1;
        return normalized != 0;
    }
}

/* Original checks require at least one enabled ID as well as both comparisons. */
int func_020a6934(u8 *p)
{
    int enabled;
    int result;
    int expected;
    expected = 0;
    enabled = 0;
    result = 1;
    if (FIELD(s16, p, 16) > -1) {
        enabled = 1;
        if (FIELD(u16, p, 18) != 0) expected = 1;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 16))) result = 0;
    }
    if (FIELD(s16, p, 20) > -1) {
        enabled = 1;
        expected = FIELD(u16, p, 22) != 0;
        if (expected != Unk094fe0_Call_020950b4(FIELD(s16, p, 20))) result = 0;
    }
    {
        u32 normalized = 0;
        u32 present = 0;
        if (enabled) present = 1;
        if (present && result) normalized = 1;
        return normalized != 0;
    }
}

/* Original kind byte selects a 16-byte bank record to clear before clearing the cell.
 * Coordinates and the cell's bank index must be valid; buffers are borrowed. */
void func_020a6a08(u8 *grid, u8 *records, u32 x, u32 y)
{
    u8 *cell;
    if (grid == 0) return;
    cell = (u8 *)Unk0a6174_Unk_0a6a88((int)grid, x, y);
    switch (*(s8 *)cell) {
    case 1:
        func_02008848((void *)Unk0a6174_Unk_0a6aac((int)records, cell[1]), 0, 16);
        break;
    case 2:
        func_02008848((void *)Unk0a6174_Unk_0a6ab4((int)records, cell[1]), 0, 16);
        break;
    }
    func_02008848(cell, 0, 2);
}

/* Original occupancy/coordinate loads rebuild the grid from two banks of 16 records.
 * The caller provides a writable 0xe14-byte grid and a readable 0x200-byte bank. */
void func_020a7ca4(u8 *grid, u8 *records)
{
    int i;
    u8 *record;
    func_02008848(grid, 0, 0xe14);
    record = records;
    for (i = 0; i < 16; i++, record += 16) {
        if (record[12] != 0) func_020a6280(grid, record[10], record[11], 1, (u8)i);
    }
    {
        int j;
        u8 *second = records + 256;
        for (j = 0; j < 16; j++, second += 16) {
            if (second[13] != 0) func_020a6280(grid, second[11], second[12], 2, (u8)j);
        }
    }
}
