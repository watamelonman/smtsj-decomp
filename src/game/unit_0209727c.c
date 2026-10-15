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

s8 func_0209727c(int i)
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

u8 *func_020972d8(void)
{
    return Unk02e000_Thunk_0202e788()->unk_0024;
}

u8 *func_020972e8(void)
{
    return Unk02e000_Thunk_0202e788()->unk_005a;
}

u8 *func_020972f8(void)
{
    return Unk02e000_Thunk_0202e788()->unk_0048;
}
