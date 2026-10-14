/* src/game/unit_0202ee5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
/* decompiler-derived */
int func_0202f044(void)
{
  int tmp1;
  tmp1 = func_0202e788();
  return tmp1 + 0x368;
}

int func_02008848();
/* decompiler-derived */
void func_0202f054(void)
{
  int tmp1;
  tmp1 = func_0202f044();
  func_02008848(tmp1,0,6);
  *(u8 *)(tmp1 + 1) = 100;
  return;
}
