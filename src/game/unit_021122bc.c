/* src/game/unit_021122bc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_021122bc();
/* decompiler-derived */
u32 func_021124c8(void)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_021122bc(*(u16 *)(tmp1 + 0x35c));
  if (tmp1 == 1) {
    tmp2 = 2;
  }
  return tmp2;
}

int func_02112438();
/* decompiler-derived */
u32 func_02112460(void)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 1;
  tmp1 = func_0202e788();
  tmp1 = func_02112438(*(u16 *)(tmp1 + 0x35c));
  if (tmp1 == 1) {
    tmp1 = func_0202e788();
    tmp1 = func_021122bc(*(u16 *)(tmp1 + 0x35c));
    if (tmp1 == 0) {
      tmp2 = 0;
    }
  }
  return tmp2;
}
