/* Work-area views and packed-pair construction; offsets verified against ARM code. */
#include "types.h"

/** Borrowed work-area prefix; field meanings beyond their offsets are unknown. */
/* Work area returned by func_0202e788 (unit_0202e000). */
typedef struct Unk02e000WorkArea {
    u8 pad_0000[0x16];
    s8 unk_0016[5];             /* +0x16 */
    u8 pad_001b[0x9];
    u8 unk_0024[0x24];          /* +0x24 sub-block */
    u8 unk_0048[0x12];          /* +0x48 sub-block */
    u8 unk_005a[2];             /* +0x5A sub-block */
} Unk02e000WorkArea;

Unk02e000WorkArea *Unk02e000_Thunk_0202e788(void);

/* ARM loads at +0x16..+0x1a support this signed-byte accessor; other indices return zero. */
s8 Unk09727c_GetAreaS8(int i)
{
    Unk02e000WorkArea *a = Unk02e000_Thunk_0202e788();
    switch (i) {
    case 0:
        return a->unk_0016[0];
    case 1:
        return a->unk_0016[1];
    case 2:
        return a->unk_0016[2];
    case 3:
        return a->unk_0016[3];
    case 4:
        return a->unk_0016[4];
    }
    return 0;
}

/* ARM adds +0x24 to the shared area; caller borrows the returned sub-block. */
u8 *Unk09727c_GetAreaSub24(void)
{
    return Unk02e000_Thunk_0202e788()->unk_0024;
}

/* ARM adds +0x5a to the shared area; caller borrows the returned sub-block. */
u8 *Unk09727c_GetAreaSub5a(void)
{
    return Unk02e000_Thunk_0202e788()->unk_005a;
}

/* ARM adds +0x48 to the shared area; caller borrows the returned sub-block. */
u8 *Unk09727c_GetAreaSub48(void)
{
    return Unk02e000_Thunk_0202e788()->unk_0048;
}

int func_020445d0(int kind, int index);
int func_0204fe18(int handle);
u16 *func_0204fde0(int handle);
/** One halfword, with a 10-bit value and a 6-bit selector (ARM shifts prove widths). */
typedef struct Unk09727cPair {
    u16 lo : 10;
    u16 hi : 6;
} Unk09727cPair;

void func_02099f7c(Unk02e000WorkArea *area, Unk09727cPair *out);
void func_0209846c(u16 *ids, Unk02e000WorkArea *area);
int func_02096548(u16 *ids, int index);
int Unk02f078_IsAllowed_02f190(int current, int candidate);
void func_02097340(Unk09727cPair *out, Unk02e000WorkArea *area);
/* Reads resource (48, 0) as halfwords; index 18 is the fixed value 100 in ARM. */
int Unk09727c_Unk_097308(int i)
{
    int t = func_020445d0(48, 0);
    u16 *a;
    func_0204fe18(t);
    a = (u16 *)func_0204fde0(t);
    if (i == 18) {
        return 100;
    }
    return a[i];
}

/* Builds 19 pairs in caller storage. ARM calls establish adjustment order;
 * selector meanings remain unknown, so retain the original neutral symbol. */
void func_02097340(Unk09727cPair *out, Unk02e000WorkArea *area)
{
    u16 ids[6];
    int i;
    for (i = 0; i < 19; i++) {
        /* Preserve the selector while replacing the low ten bits. */
        u16 *packed = (u16 *)&out[i];
        int value = Unk09727c_Unk_097308(i);
        *packed = (*packed & ~0x3ff) | (value & 0x3ff);
        out[i].hi = 0;
    }
    func_02099f7c(area, out);
    if (out[6].hi != 2 && out[6].hi != 3) {
        out[6].hi = 1;
    }
    func_0209846c(ids, area);
    for (int j = 0; j < 19; j++) {
        int candidate = func_02096548(ids, j);
        if (Unk02f078_IsAllowed_02f190(out[j].hi, candidate)) {
            out[j].hi = (u16)candidate;
        }
    }
    for (i = 0; i < 19; i++) {
        if (out[i].hi == 5) {
            out[i].lo = (u16)(out[i].lo / 2);
            if (out[i].lo > 50) {
                out[i].lo = 50;
            }
        }
    }
}

/* ARM extracts the low 10 bits after building pairs; index must be 0..18. */
int Unk09727c_GetPairLo(int i)
{
    Unk09727cPair buf[20];
    func_02097340(buf, Unk02e000_Thunk_0202e788());
    return buf[i].lo;
}

/* ARM extracts the high 6 bits after building pairs; index must be 0..18. */
int Unk09727c_GetPairHi(int i)
{
    Unk09727cPair buf[20];
    func_02097340(buf, Unk02e000_Thunk_0202e788());
    return buf[i].hi;
}
