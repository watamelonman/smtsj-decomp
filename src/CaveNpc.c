/* src/CaveNpc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020fff3c(void) { }

extern u8 data_02151180[];
int func_0205ba98();
/* decompiler-derived */
void func_021000d0(int arg0)
{
  u32 tmp1;
  if (*(int *)(arg0 + 0x2c) != 0) {
    return;
  }
  tmp1 = func_0205ba98(0x2000,0x200,((int)data_02151180),0x11e);
  *(u32 *)(arg0 + 0x2c) = tmp1;
  return;
}
