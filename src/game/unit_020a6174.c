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

