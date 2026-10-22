/* Work-area accessors reconstructed from the ARM instructions at 0x0202ee5c. */
#include "types.h"


u8 *Unk02e000_GetWorkArea(void);
u8 *Unk02e000_Unk_02e774(void);
u8 *Unk02e000_Thunk_0202e788(void);

/* Records are 36 bytes at work + 0x16fc; byte 0x0b bit 0 is shared
 * by the getter and setter below, as established by their ARM loads/stores. */
typedef struct Unk02ee5cRec {
    u8 pad_0000[0xb];
    u8 flag_000b_0 : 1;
    u8 pad_000c[0x18];
} Unk02ee5cRec;                 /* 36 bytes; same table as unit_0202e000 (work+0x16FC, ids 1..491) */

int Unk0e651c_Unk_0e666c(u32 flag);
/* ARM 0x0202ee5c: normalize v into record byte 0x0b bit 0; ids above 491 fail.
 * Callers must supply ids 1..491; the original does not reject zero. */
int Unk02ee5c_SetRecordFlag0b(u32 id, int v)
{
    Unk02ee5cRec *e;
    if (id > 491) {
        return 0;
    }
    e = (Unk02ee5cRec *)(Unk02e000_Unk_02e774() + 0x16fc) + (id - 1);
    e->flag_000b_0 = (u8)(v != 0);
    return 1;
}

/* ARM 0x0202eec0: read record byte 0x0b bit 0 as a boolean.
 * Valid ids are 1..491; ids above 491 return zero. */
int Unk02ee5c_GetRecordFlagB(u32 id)
{
    if (id > 491) {
        return 0;
    }
    {
        Unk02ee5cRec *r = &((Unk02ee5cRec *)((u8 *)Unk02e000_Unk_02e774() + 0x16fc))[id - 1];
        return r->flag_000b_0 ? 1 : 0;
    }
}

/* ARM 0x0202ef0c supports the tier name: byte 0x70 maps to 4, 1, or 5
 * at the inclusive boundaries 95 and 160. */
int Unk02ee5c_GetTierFromField70(void)
{
    u8 v = Unk02e000_Thunk_0202e788()[0x70];
    if (v >= 160) {
        return 5;
    }
    if (v <= 95) {
        return 4;
    }
    return 1;
}

/* ARM 0x0202ef34: flags 0x404..0x406 inhibit updates to byte 0x70.
 * The sum narrows to signed 16 bits before clamping to 0..255. */
void Unk02ee5c_AddClamped70(int d)
{
    u8 *w;
    s16 v;
    if (Unk0e651c_Unk_0e666c(0x404) != 0) {
        return;
    }
    if (Unk0e651c_Unk_0e666c(0x405) != 0) {
        return;
    }
    if (Unk0e651c_Unk_0e666c(0x406) != 0) {
        return;
    }
    w = Unk02e000_Thunk_0202e788();
    v = w[112] + d;
    if (v > 255) {
        v = 255;
    }
    if (v < 0) {
        v = 0;
    }
    w[112] = v;
}

/* ARM 0x0202f044: return the borrowed six-byte region at work offset 0x368. */
u8 *Unk02ee5c_Unk_02f044(void)
{
    return Unk02e000_GetWorkArea() + 0x368;
}

void func_02008848(void *destination, int value, u32 size);
/* ARM 0x0202f054: clear the six-byte region, then initialize byte 1 to 100. */
void Unk02ee5c_Unk_02f054(void)
{
    u8 *value = Unk02ee5c_Unk_02f044();
    func_02008848(value, 0, 6);
    value[1] = 100;
}
