/* src/game/unit_0206dddc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_0216bac4[];
extern u8 data_0216baec[];
u32 func_0206dddc(int i)
{
    if ((s32)data_0216bac4[0] - 1 - i < 0) {
        return 0;
    }
    return *(u32 *)(data_0216baec + i * 328);
}

/* decompiler-derived */
u32 Unk06dddc_Get_data_0216bac4(void)
{
  return *data_0216bac4;
}

extern u8 data_0216bac8[];
/* decompiler-derived */
int Unk06dddc_Unk_06e058(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8);
}

extern u8 data_0216baf0[];
/* decompiler-derived */
u32 Unk06dddc_Unk_06dfb0(int arg0)
{
  return *(u32 *)(((int)data_0216baf0) + arg0 * 0x148);
}

int func_020086bc();
/* decompiler-derived */
void Unk06dddc_Unk_06dee8(int arg0,u32 arg1)
{
  func_020086bc(arg1,arg0 * 0x148 + data_0216bac8 + 0x2c,0x90);
}

extern u8 data_0216bc04[];
/* decompiler-derived */
int Unk06dddc_Unk_06dfc8(int arg0,int arg1)
{
  return (int)*(short *)(arg1 * 0x14 + *(int *)(data_0216bc04 + arg0 * 0x148) + 4);
}

/* decompiler-derived */
u32 Unk06dddc_Unk_06dfec(int arg0,int arg1)
{
  return *(u32 *)(*(int *)(data_0216bc04 + arg0 * 0x148) + arg1 * 0x14);
}

/* decompiler-derived */
int Unk06dddc_Unk_06e010(int arg0,int arg1)
{
  return arg1 * 0x14 + *(int *)(data_0216bc04 + arg0 * 0x148) + 8;
}

/* decompiler-derived */
int Unk06dddc_Unk_06e034(int arg0,int arg1)
{
  return (int)*(short *)(arg1 * 0x14 + *(int *)(data_0216bc04 + arg0 * 0x148) + 6);
}

u8 *Unk06dddc_Unk_06e0c4(u32 a)
{
    u8 *p = (u8 *)Unk06dddc_Unk_06e058(a);
    if (p != 0) {
        return p + 1;
    }
    return 0;
}
