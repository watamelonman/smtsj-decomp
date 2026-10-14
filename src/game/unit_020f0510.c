/* src/game/unit_020f0510.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176df8[];
int func_020f7d14();
int func_020f7e48();
/* decompiler-derived */
void func_020f06a4(void)
{
  int tmp1;
  tmp1 = *data_02176df8;
  func_020f7d14(*(u32 *)(tmp1 + 4));
  func_020f7e48(*(u32 *)(tmp1 + 0x40),0,1);
  return;
}
