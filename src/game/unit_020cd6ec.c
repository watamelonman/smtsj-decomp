/* src/game/unit_020cd6ec.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020ce3ec(void) { }

int func_020a0da4();
/* decompiler-derived */
void func_020ce280(u8 *arg0,u32 arg1)
{
  func_020a0da4(5);
  arg0[2] = 4;
  *arg0 = 0xc;
  *(u32 *)(arg0 + 8) = arg1;
  return;
}

int func_02123294();
/* decompiler-derived */
void func_020ce2ac(u8 *arg0,u32 arg1)
{
  func_02123294(*(u32 *)(arg0 + 0x1c));
  *(u32 *)(arg0 + 0xf0) = arg1;
  arg0[2] = 1;
  *arg0 = 3;
  return;
}
