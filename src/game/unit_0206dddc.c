/* src/game/unit_0206dddc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_0216bac4[];
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

