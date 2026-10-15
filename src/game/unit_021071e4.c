/* src/game/unit_021071e4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020bc9f4();
int func_020bcacc();
/* decompiler-derived */
void func_02107c34(int arg0)
{
  func_020bc9f4(0x13,0);
  func_020bcacc(0x12,0);
  *(u8 *)(arg0 + 0x29) = 4;
  return;
}

int func_02108aec();
/* decompiler-derived */
int func_021087f4(u32 arg0,int arg1,int arg2,int arg3,short arg4)
{
  int tmp1;
  tmp1 = func_02108aec();
  if (tmp1 != 0) {
    return (arg3 - arg1) + (arg4 - arg2) * 3;
  }
  return 0;
}

