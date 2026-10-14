/* src/game/unit_021159f8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_021159f8();
/* decompiler-derived */
u32 func_02115c68(u32 arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_021159f8(*(u16 *)(tmp1 + 0x35c),arg0,arg1);
  if (tmp1 == 1) {
    tmp2 = 2;
  }
  return tmp2;
}
