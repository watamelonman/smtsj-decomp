/* src/game/unit_020afc28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_020afc28(int arg0,int arg1)
{
  *(int *)(arg0 + 0x20) = *(int *)(arg0 + 0x20) + arg1;
  return;
}

int func_020492ec();
int func_0204a67c();
/* decompiler-derived */
void func_020afdd0(u32 arg0,u32 arg1,int arg2)
{
  int tmp1;
  tmp1 = func_0204a67c();
  if (arg2 != 0) {
    tmp1 = -tmp1;
  }
  func_020492ec(arg1,tmp1);
  return;
}
