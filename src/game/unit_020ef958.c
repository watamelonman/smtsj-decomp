/* src/game/unit_020ef958.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020efab0(void) { }

extern u32 data_02176df4[];
int func_02008848();
int func_020ef9dc();
/* decompiler-derived */
void func_020ef9b0(u32 arg0)
{
  func_02008848(arg0,0,0xf4);
  *data_02176df4 = arg0;
  func_020ef9dc(arg0);
  return;
}
