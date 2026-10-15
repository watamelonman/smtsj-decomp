/* src/game/unit_02100414.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_02100414(u16 *arg0,u16 *arg1)
{
  int tmp1;
  tmp1 = *(int *)(arg1 + 4) - *(int *)(arg0 + 4);
  if (tmp1 == 0) {
    tmp1 = (u32)*arg0 - (u32)*arg1;
  }
  return tmp1;
}
