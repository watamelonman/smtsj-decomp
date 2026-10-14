/* src/game/unit_0206fb70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0206d68c();
/* decompiler-derived */
void func_020717c0(int arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_0206d68c(2,arg1,100);
  *(int *)(arg0 + 0x120) = *(int *)(arg0 + 0x120) + tmp1;
  return;
}

int func_0200219c();
int func_02007e94();
/* decompiler-derived */
void func_0206fb70(int arg0,int arg1,int arg2,int arg3)
{
  if (arg1 - arg0 == 0) {
    func_02007e94();
  }
  func_0200219c((arg3 - arg2) * 0x1000,(arg1 - arg0) * 0x1000);
  return;
}

