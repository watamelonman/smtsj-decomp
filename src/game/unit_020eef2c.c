#include "types.h"

/* Six-word work block; offsets and signed counters follow the original accesses. */
typedef struct Unk0eef2cWork {
    u32 unk_0000;
    s32 unk_0004;
    s32 unk_0008;
    s32 unk_000c;
    s32 unk_0010;
    s32 unk_0014;
} Unk0eef2cWork;

extern Unk0eef2cWork *data_02176dec;
void func_02008848(void *dest, s32 value, u32 size);
void func_02057e18(s32 value);
void func_02057df8(void);
void Unk0bc1a8_Unk_0bc9b4(u32 id, s32 value);
void func_020f7de4(u32 id, s32 value);
void Unk0eef2c_Unk_0eef58(Unk0eef2cWork *work);

/* Clears and publishes a caller-owned 24-byte block before setting its defaults. */
void Unk0eef2c_Unk_0eef2c(Unk0eef2cWork *work)
{
    func_02008848(work, 0, 0x18);
    data_02176dec = work;
    Unk0eef2c_Unk_0eef58(work);
}

/* Establishes the six observed defaults, including the signed -241 offset. */
void Unk0eef2c_Unk_0eef58(Unk0eef2cWork *work)
{
    work->unk_0000 = 0x21;
    work->unk_0004 = 1;
    work->unk_0008 = 0;
    work->unk_000c = 0;
    work->unk_0010 = -241;
    work->unk_0014 = 0;
}

/* Empty callback slot, evidenced by the original single return instruction. */
void Unk0eef2c_Nop_0eef80(void) { }

/* Advances states 4, 6 and 7 by one tick; division truncates toward zero. */
void func_020eef84(Unk0eef2cWork *work)
{
    switch (work->unk_0004) {
    case 0: break;
    case 1: break;
    case 2: break;
    case 3: break;
    case 4:
        work->unk_0010 = (--work->unk_0008 * -241) / 10;
        if (work->unk_0008 < 1) {
            work->unk_0010 = 0;
            work->unk_0004 = 10;
        }
        break;
    case 5: break;
    case 6:
    case 7:
        work->unk_0010 = ((10 - --work->unk_0008) * -241) / 10;
        if (work->unk_0008 < 1) {
            if (work->unk_0004 == 7) Unk0bc1a8_Unk_0bc9b4(work->unk_0000, 0);
            else func_020f7de4(work->unk_0000, 0);
        }
        break;
    case 8: break;
    case 9: break;
    case 10: break;
    }
}

/* Empty callback slot, evidenced by the original single return instruction. */
void Unk0eef2c_Nop_0ef06c(void) { }

/* State 1 suppresses the paired calls; other states submit constant 31. */
void Unk0eef2c_Unk_0ef070(Unk0eef2cWork *work)
{
    if (work->unk_0004 == 1) return;
    func_02057e18(31);
    func_02057df8();
}
