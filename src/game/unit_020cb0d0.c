/* src/game/unit_020cb0d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_020cb190(int arg0,int arg1)
{
  return (u32)*(u16 *)(arg0 + 0x20) - (u32)*(u16 *)(arg1 + 0x20);
}

int func_020445d0();
int func_0204fde0();
int func_0204fe18();
/* decompiler-derived */
void func_020cb1f8(void)
{
  u32 tmp1;
  tmp1 = func_020445d0(0xb,0);
  func_0204fde0();
  func_0204fe18(tmp1);
  return;
}

int func_020cb1a0();
/* decompiler-derived */
u32 func_020cb304(void)
{
  int tmp1;
  tmp1 = func_020cb1a0();
  if ((tmp1 != 0) && (*(char *)(tmp1 + 0x23) == '\a')) {
    return 1;
  }
  return 0;
}
