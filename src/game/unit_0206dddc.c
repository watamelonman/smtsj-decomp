/* src/game/unit_0206dddc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_0216bac4[];
/* decompiler-derived */
u32 func_0206dfa0(void)
{
  return *data_0216bac4;
}

extern u8 data_0216bac8[];
/* decompiler-derived */
int func_0206e058(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8);
}

extern u8 data_0216baf0[];
/* decompiler-derived */
u32 func_0206dfb0(int arg0)
{
  return *(u32 *)(((int)data_0216baf0) + arg0 * 0x148);
}
