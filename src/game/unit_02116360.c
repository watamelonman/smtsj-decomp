/* src/game/unit_02116360.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_021163a4();
/* decompiler-derived */
void func_02116404(int arg0,u32 arg1,u32 arg2)
{
  int tmp1;
  if (arg0 == 0) {
    return;
  }
  tmp1 = func_0202e788();
  func_021163a4(arg0,*(u16 *)(tmp1 + 0x35c),arg1,arg2);
  return;
}

int func_02116360();
/* decompiler-derived */
u32 func_02116438(u32 arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_02116360(*(u16 *)(tmp1 + 0x35c),arg0,arg1);
  if (tmp1 == 1) {
    tmp2 = 2;
  }
  return tmp2;
}
