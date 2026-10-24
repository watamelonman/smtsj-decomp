/* Work-state helpers; field offsets and table stride follow the original ARM accesses. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06e4d8Work {
    s32 unk_0000;
    s32 unk_0004;
    s32 unk_0008;
    u8 unk_000c[0x20]; /* cleared and passed as one block */
    s32 unk_002c; /* 20.12 fixed point, integer part 0..255 */
    s32 unk_0030;
    s32 unk_0034;
    u8 pad_0038[0x4];
    u32 unk_003c;
    u32 unk_0040;
    u32 unk_0044;
    u8 pad_0048[0x4];
    u32 unk_004c;
    u8 pad_0050[0xc];
    u32 unk_005c;
    u32 unk_0060;
    u32 unk_0064;
    u32 unk_0068;
    u8 unk_006c;
    u8 pad_006d[0x3];
} Unk06e4d8Work; /* 0x70 bytes: allocated with size 112 in Unk06e4d8_Unk_06e538 */

extern Unk06e4d8Work *data_02170cc8;
/* Return the nullable work address stored at data_02170cc8 (original LDR pair).
 * The caller borrows the work; this accessor does not transfer ownership. */
u32 Unk06e4d8_Get_data_02170cc8(void)
{
  return (u32)data_02170cc8;
}

extern u8 data_0216bac8[];
/* Return the borrowed address at +0xbc in a caller-validated table slot.
 * Evidence: original MLA uses stride 0x148 from data_0216bac8, then ADD 0xbc. */
int Unk06e4d8_Unk_06e4d8(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xbc;
}


/* Return the borrowed address at +0xdc in a caller-validated table slot.
 * Evidence: original MLA uses stride 0x148 from data_0216bac8, then ADD 0xdc. */
int Unk06e4d8_Unk_06e4f0(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xdc;
}


/* Return the borrowed address at +0xfc in a caller-validated table slot.
 * Evidence: original MLA uses stride 0x148 from data_0216bac8, then ADD 0xfc. */
int Unk06e4d8_Unk_06e508(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xfc;
}


/* Return the borrowed address at +0x11c in a caller-validated table slot.
 * Evidence: original MLA uses stride 0x148 from data_0216bac8, then ADD 0x11c. */
int Unk06e4d8_Unk_06e520(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0x11c;
}

int func_02061424(u32 work_address);
extern u32 data_0216bac4[];
u8 *Unk06dddc_Unk_06e058();
void Unk06e4d8_Unk_06e814(Unk06e4d8Work *w);
void *func_020611dc();
void func_0206e5bc(Unk06e4d8Work *w);
void func_02008848();

/* Create the singleton: func_020611dc allocates a 0x70-byte work block with func_0206e5bc as its
 * per-frame callback; the block is zeroed, published in data_02170cc8 and left in state 0. */
void Unk06e4d8_Unk_06e538(void)
{
    Unk06e4d8Work *w = func_020611dc(func_0206e5bc, 0, 0, 0, 112, 3, 0, 0);
    if (w == 0) {
        return;
    }
    func_02008848(w, 0, 112);
    data_02170cc8 = w;
    w->unk_006c = 0;
}

/* Reset a non-null work block: original stores clear +0x08, +0x6c and
 * +0x68 before tail-calling Unk06e4d8_Unk_06e814 to clear the remaining state. */
void Unk06e4d8_Reset(Unk06e4d8Work *w)
{
    w->unk_0008 = 0;
    w->unk_006c = 0;
    w->unk_0068 = 0;
    Unk06e4d8_Unk_06e814(w);
}

void Unk06e4d8_Unk_06e6a4(Unk06e4d8Work *w);
void func_0206e6e4(Unk06e4d8Work *w);
void func_0206d950(s16 *value, s32 step, s32 limit);
int func_0200219c(int num, int den);

/* Per-frame step of the work's state machine (state byte at +0x6c); frame counter +0x08 always advances.
 * State 1 waits for +0x00 frames, state 2 runs Unk06e4d8_Unk_06e6a4 until +0x04 frames, then holds in
 * state 3 when +0x68 == 1, else resets. State 4 steps the three channels and moves to 5 after +0x04 + 13 frames.
 * Evidence: original jump table on the +0x6c byte with signed frame compares. */
void func_0206e5bc(Unk06e4d8Work *w)
{
    switch (w->unk_006c) {
    case 0:
        break;
    case 1:
        if (w->unk_0008 < w->unk_0000) {
            break;
        }
        w->unk_006c = 2;
    case 2:
        Unk06e4d8_Unk_06e6a4(w);
        if (w->unk_0008 < w->unk_0004) {
            break;
        }
        if (w->unk_0068 == 1) {
            w->unk_006c = 3;
            break;
        }
        Unk06e4d8_Reset(w);
        break;
    case 3:
        return;
    case 4:
        func_0206e6e4(w);
        if (w->unk_0008 < w->unk_0004 + 13) {
            break;
        }
        w->unk_006c = 5;
    case 5:
        Unk06e4d8_Reset(w);
        break;
    }
    w->unk_0008++;
}

/* Pass the stored work address to func_02061424, then clear the global slot.
 * Evidence: original BL followed by a zero STR; no null check is performed. */
void Unk06e4d8_Unk_06e680(void)
{
  func_02061424((u32)data_02170cc8);
  data_02170cc8 = 0;
}



int func_02070440();
/* Hand the work's +0x0c block and its +0x60/+0x5c/+0x64/+0x2c/+0x3c/+0x4c fields to func_02070440 by address
 * (purpose of the callee unknown). */
void Unk06e4d8_Unk_06e6a4(Unk06e4d8Work *w)
{
    func_02070440(w->unk_000c, &w->unk_0060, &w->unk_005c, &w->unk_0064, &w->unk_002c,
                  &w->unk_003c, &w->unk_004c);
}

/* Step the three 20.12 values at +0x2c/+0x30/+0x34 by the steps at +0x3c/+0x40/+0x44 (integer part),
 * clamped at 255 by func_0206d950. */
void func_0206e6e4(Unk06e4d8Work *w)
{
    s16 v = 0;
    v = w->unk_002c >> 12;
    func_0206d950(&v, (s16)(w->unk_003c >> 12), 255);
    w->unk_002c = v << 12;
    v = w->unk_0030 >> 12;
    func_0206d950(&v, (s16)(w->unk_0040 >> 12), 255);
    w->unk_0030 = v << 12;
    v = w->unk_0034 >> 12;
    func_0206d950(&v, (s16)(w->unk_0044 >> 12), 255);
    w->unk_0034 = v << 12;
}

/* For the singleton, compute the per-frame steps +0x3c/+0x40/+0x44 as (0xff000 - value) / 0xd000
 * (func_0200219c divide) for the three values, then enter state 4. Does nothing without a singleton. */
void func_0206e790(void)
{
    if (data_02170cc8 == 0) {
        return;
    }
    data_02170cc8->unk_003c = func_0200219c(0xff000 - data_02170cc8->unk_002c, 0xd000);
    data_02170cc8->unk_0040 = func_0200219c(0xff000 - data_02170cc8->unk_0030, 0xd000);
    data_02170cc8->unk_0044 = func_0200219c(0xff000 - data_02170cc8->unk_0034, 0xd000);
    data_02170cc8->unk_006c = 4;
}

int func_020086a0();
/* Clear the 0x20-byte block at +0x0c (func_020086a0 fill with 0) and zero the value/step fields. */
void Unk06e4d8_Unk_06e814(Unk06e4d8Work *w)
{
    func_020086a0(0, w->unk_000c, 0x20);
    w->unk_002c = 0;
    w->unk_0030 = 0;
    w->unk_0034 = 0;
    w->unk_003c = 0;
    w->unk_004c = 0;
    w->unk_0060 = 0;
    w->unk_005c = 0;
    w->unk_0064 = 0;
}

/* While the singleton exists and is active (+0x6c != 0), pack the integer parts of the three 20.12
 * values into bytes 3/2/1 of the result; otherwise return -1. */
s32 Unk06e4d8_Unk_06e854(void)
{
    Unk06e4d8Work *w;
    if (Unk06e4d8_Get_data_02170cc8() != 0 && ((u8 *)Unk06e4d8_Get_data_02170cc8())[108] != 0) {
        w = data_02170cc8;
        return (((s32)w->unk_002c >> 12) << 24) | (((s32)w->unk_0030 >> 12) << 16) | (((s32)w->unk_0034 >> 12) << 8);
    }
    return -1;
}

/* Return 1 when slot i is below the count at data_0216bac4 and the +0xd8 word of the record returned by
 * Unk06dddc_Unk_06e058(i) is positive, else 0. */
int Unk06e4d8_Unk_06ea0c(int i)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return FIELD(s32, Unk06dddc_Unk_06e058(i), 0xd8) > 0;
}

/* Report whether the singleton exists and its byte at +0x6c is nonzero.
 * Evidence: original two accessor calls, LDRB +0x6c and boolean normalization. */
int Unk06e4d8_GetFlag6c(void)
{
    if (Unk06e4d8_Get_data_02170cc8() == 0) {
        return 0;
    }
    return ((Unk06e4d8Work *)Unk06e4d8_Get_data_02170cc8())->unk_006c != 0;
}
