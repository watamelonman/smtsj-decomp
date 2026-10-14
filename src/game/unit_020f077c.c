/* src/game/unit_020f077c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020f08dc(void) { }

extern u32 data_02176dfc[];
int func_02008848();
int func_020f0800();
/* decompiler-derived */
void func_020f07d4(u32 arg0)
{
  func_02008848(arg0,0,0xf4);
  *data_02176dfc = arg0;
  func_020f0800(arg0);
  return;
}
