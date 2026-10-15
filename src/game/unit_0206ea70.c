/* src/game/unit_0206ea70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_0206edf4(int *arg0,int *arg1,int *arg2,u16 *arg3)
{
  u32 tmp1;
  int tmp2;
  tmp2 = 0;
  do {
    tmp1 = (u32)*arg3;
    tmp2 = tmp2 + 1;
    *arg0 = (tmp1 & 0x1f) << 0xf;
    *arg1 = ((int)tmp1 >> 5 & 0x1fU) << 0xf;
    *arg2 = ((int)tmp1 >> 10 & 0x1fU) << 0xf;
    arg0 = arg0 + 1;
    arg1 = arg1 + 1;
    arg2 = arg2 + 1;
    arg3 = arg3 + 1;
  } while (tmp2 < 0x100);
  return;
}

