/* Accessors for the table at data_0216bac8; record meanings remain unknown. */
#include "types.h"


extern u32 data_0216bac4[];
extern u8 data_0216baec[];
u32 Unk06dddc_GetEntryUnk24(int i)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return *(u32 *)(data_0216baec + i * 328);
}

/* Return the table count word (load at 0x0206dfa0); no ownership transfer. */
u32 Unk06dddc_Get_data_0216bac4(void)
{
  return *data_0216bac4;
}

extern u8 data_0216bac8[];
/* Return a borrowed 328-byte record; the caller supplies a valid index.
 * Evidence: 0x0206e058 adds index * 0x148 to data_0216bac8. */
u8 *Unk06dddc_Unk_06e058(int arg0)
{
  return data_0216bac8 + arg0 * 0x148;
}

extern u8 data_0216baf0[];
/* Read the word at record offset +0x28; valid index required.
 * Evidence: 0x0206dfb0 indexes data_0216baf0 with stride 0x148. */
u32 Unk06dddc_Unk_06dfb0(int arg0)
{
  return *(u32 *)(data_0216baf0 + arg0 * 0x148);
}

int func_020086bc();
/* decompiler-derived */
void Unk06dddc_Unk_06dee8(int arg0,u32 arg1)
{
  func_020086bc(arg1,arg0 * 0x148 + data_0216bac8 + 0x2c,0x90);
}

extern u8 data_0216bc04[];
/* Read the signed halfword at subrecord offset +4; both indices must be valid.
 * Evidence: 0x0206dfc8 loads the pointer at record +0x13c and uses stride 0x14. */
int Unk06dddc_Unk_06dfc8(int arg0,int arg1)
{
  return (int)*(short *)(arg1 * 0x14 + *(u8 **)(data_0216bc04 + arg0 * 0x148) + 4);
}

/* Read the word at subrecord offset +0; both indices must be valid.
 * Evidence: 0x0206dfec loads the pointer at record +0x13c and uses stride 0x14. */
u32 Unk06dddc_Unk_06dfec(int arg0,int arg1)
{
  return *(u32 *)(*(u8 **)(data_0216bc04 + arg0 * 0x148) + arg1 * 0x14);
}

/* Return the borrowed bytes at subrecord offset +8; both indices must be valid.
 * Evidence: 0x0206e010 loads the pointer at record +0x13c and uses stride 0x14. */
u8 *Unk06dddc_Unk_06e010(int arg0,int arg1)
{
  return arg1 * 0x14 + *(u8 **)(data_0216bc04 + arg0 * 0x148) + 8;
}

/* Read the signed halfword at subrecord offset +6; both indices must be valid.
 * Evidence: 0x0206e034 loads the pointer at record +0x13c and uses stride 0x14. */
int Unk06dddc_Unk_06e034(int arg0,int arg1)
{
  return (int)*(short *)(arg1 * 0x14 + *(u8 **)(data_0216bc04 + arg0 * 0x148) + 6);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u32 data_0216bac4[];
extern u8 data_0216baec[];
extern u8 data_0216baf0[];
u8 *Unk06dddc_Unk_06e058(int arg0);
int func_020152cc();

u8 Unk06dddc_Unk_06e06c(int k)
{
    int i;
    for (i = 0; i < (s32)data_0216bac4[0]; i++) {
        if (func_020152cc(Unk06dddc_Unk_06e058((u8)i) + 1, k) == 0) {
            return i;
        }
    }
    return 255;
}

/* Return borrowed record bytes starting at +1, preserving the null check.
 * Evidence: 0x0206e0c4 calls the record accessor, then conditionally adds one.
 * The caller supplies a valid record index. */
u8 *Unk06dddc_Unk_06e0c4(u32 a)
{
    u8 *p = Unk06dddc_Unk_06e058(a);
    if (p != 0) {
        return p + 1;
    }
    return 0;
}
