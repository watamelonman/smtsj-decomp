/* src/game/unit_0209727c.c: matched functions. */
#include "types.h"

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

u8 *Unk09727c_GetAreaSub24(void)
{
    return Unk02e000_Thunk_0202e788()->unk_0024;
}

u8 *Unk09727c_GetAreaSub5a(void)
{
    return Unk02e000_Thunk_0202e788()->unk_005a;
}

u8 *Unk09727c_GetAreaSub48(void)
{
    return Unk02e000_Thunk_0202e788()->unk_0048;
}

int func_020445d0();
void func_0204fe18();
int func_0204fde0();
typedef struct Unk09727cPair {
    u16 lo : 10;
    u16 hi : 6;
} Unk09727cPair;

void func_02097340(Unk09727cPair *out, void *area);
int func_02097308(int i)
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

int func_020974a4(int i)
{
    Unk09727cPair buf[20];
    func_02097340(buf, Unk02e000_Thunk_0202e788());
    return buf[i].lo;
}

int func_020974dc(int i)
{
    Unk09727cPair buf[20];
    func_02097340(buf, Unk02e000_Thunk_0202e788());
    return buf[i].hi;
}
