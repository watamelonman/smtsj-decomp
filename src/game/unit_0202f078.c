/*
 * src/game/unit_0202f078.c: work-area accessors and small flag helpers at
 * 0x0202f078..0x0202f2a8. The offsets below come from the delinked ARM
 * instructions; no string or caller in the binary establishes a gameplay
 * meaning for them, so the symbols stay neutral.
 */
#include "types.h"

/* Callees defined in other game units. */
u8 *Unk02e000_Unk_02e774(void);
u8 *Unk02e000_GetWorkArea(void);
void func_02008848(void *destination, int value, u32 size);

/* Status byte at +2 of the block returned by Unk02e000_Unk_02e774; the work
 * area returned by Unk02e000_GetWorkArea starts four bytes later. */
typedef struct Unk02f078Head {
    u8 pad_0000[2];
    u8 unk_0002;
} Unk02f078Head;

/* Six-byte work block at work+0x36E; only byte 1 is written by this unit. */
typedef struct Unk02f078Block {
    u8 pad_0000[1];
    u8 unk_0001;
    u8 pad_0002[4];
} Unk02f078Block;

/* Tail of the work area containing the byte at 0x361 and the block at 0x36E. */
typedef struct Unk02f078WorkTail {
    u8 pad_0000[0x361];
    u8 unk_0361;
    u8 pad_0362[0xc];
    Unk02f078Block block_036e;
} Unk02f078WorkTail;

/* ARM 0x0202f0d8: read the status byte at +2 of the save block. */
u8 Unk02f078_Unk_02f0d8(void)
{
    return ((Unk02f078Head *)Unk02e000_Unk_02e774())->unk_0002;
}

/* ARM 0x0202f220: read work byte 0x361 as an unsigned value. */
u8 Unk02f078_Unk_02f220(void)
{
    return ((Unk02f078WorkTail *)Unk02e000_GetWorkArea())->unk_0361;
}

/* ARM 0x0202f078: return the six-byte work block at work+0x36E.
 * Ownership stays with the work area; callers treat it as a scratch buffer. */
Unk02f078Block *Unk02f078_Unk_02f078(void)
{
    return &((Unk02f078WorkTail *)Unk02e000_GetWorkArea())->block_036e;
}

/* ARM 0x0202f0b0: store an arbitrary value in the status byte at +2. */
void Unk02f078_Unk_02f0b0(u8 value)
{
    ((Unk02f078Head *)Unk02e000_Unk_02e774())->unk_0002 = value;
}

/* ARM 0x0202f0c4: clear the status byte at +2. */
void Unk02f078_Unk_02f0c4(void)
{
    ((Unk02f078Head *)Unk02e000_Unk_02e774())->unk_0002 = 0;
}

/* ARM 0x0202f20c: write work byte 0x361. */
void Unk02f078_Unk_02f20c(u8 value)
{
    ((Unk02f078WorkTail *)Unk02e000_GetWorkArea())->unk_0361 = value;
}

/* ARM 0x0202f0e8: report whether the status byte at +2 is nonzero. */
int Unk02f078_Unk_02f0e8(void)
{
    return ((Unk02f078Head *)Unk02e000_Unk_02e774())->unk_0002 != 0;
}

/* ARM 0x0202f08c: zero-fill the six-byte block at work+0x36E, then mark its
 * second byte 100 so later code can tell the block has been prepared. */
void Unk02f078_Unk_02f08c(void)
{
    Unk02f078Block *p = Unk02f078_Unk_02f078();

    func_02008848(p, 0, 6);
    p->unk_0001 = 100;
}

/* ARM 0x0202f190: allowed-pair predicate over two small ids. Id 0 is always
 * accepted; a zero second id is accepted only when the first id is zero.
 * The comparisons and switch at 0x0202f190..0x0202f208 establish this
 * predicate name; no caller establishes what the ids represent. Returns 0 or 1. */
int Unk02f078_IsAllowed_02f190(int a, int b)
{
    if (a == 0) {
        return 1;
    }
    if (b == 0) {
        return 0;
    }
    switch (a) {
    case 2:
        return 1;
    case 5:
        if (b != 2) {
            return 1;
        }
        break;
    case 1:
        if (b == 3 || b == 4) {
            return 1;
        }
        break;
    case 3:
        if (b == 4) {
            return 1;
        }
        break;
    }
    return 0;
}

/* ARM 0x0202f230: set byte i of the table at save+0x5E12 to 3 unless it
 * already has bit 1 set. Indices outside 0..63 are ignored without acquiring
 * the save block. The ldrb/tst #2/strbeq sequence at 0x0202f254..0x0202f260
 * establishes the entry operation; other bits are replaced, not preserved. */
void Unk02f078_InitEntry5e12(int i)
{
    if (i >= 64) {
        return;
    }
    if (i < 0) {
        return;
    }
    {
        u8 *p = Unk02e000_Unk_02e774() + 0x5e12;
        if ((p[i] & 2) == 0) {
            p[i] = 3;
        }
    }
}

/* ARM 0x0202f268: return bit 0 of byte i in the table at save+0x5E12.
 * Indices outside 0..63 yield zero without acquiring the save block.
 * The byte load and tst #1 at 0x0202f294..0x0202f298 establish the name.
 * Returns an int 0 or 1 rather than the full entry byte. */
int Unk02f078_GetEntry5e12Bit0(int i)
{
    if (i >= 64) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }
    if ((Unk02e000_Unk_02e774() + i)[0x5e12] & 1) {
        return 1;
    }
    return 0;
}

/* ARM 0x0202f104: test bit i of the 37-bit flag array at work+0x380.
 * Ids outside 1..36 return zero without acquiring the work area. The byte
 * load at 0x0202f138 and masked test at 0x0202f140 establish the name.
 * Bit numbers are used directly (bit 0 is not exposed); returns int 0 or 1. */
int Unk02f078_TestFlag380(int i)
{
    if (i <= 0) {
        return 0;
    }
    if (i >= 37) {
        return 0;
    }
    if ((Unk02e000_GetWorkArea() + (i >> 3))[0x380] & (u8)(1 << (i & 7))) {
        return 1;
    }
    return 0;
}

/* ARM 0x0202f14c: set bit i of the flag array at work+0x380.
 * Ids outside 1..36 are ignored without acquiring the work area; already-set
 * bits are left untouched. The conditional add/store at 0x0202f184..0x0202f188
 * establishes the name. Addition is safe because the tested bit is clear. */
void Unk02f078_SetFlag380(int i)
{
    u8 mask;
    u8 *p;
    if (i <= 0) {
        return;
    }
    if (i >= 37) {
        return;
    }
    mask = 1 << (i & 7);
    p = Unk02e000_GetWorkArea() + 0x380;
    if ((mask & p[i >> 3]) == 0) {
        p[i >> 3] += mask;
    }
}
