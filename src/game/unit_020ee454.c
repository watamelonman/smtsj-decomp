/* src/game/unit_020ee454.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020ee608(void) { }

extern u32 data_02176de4[];
int func_02008848();
int func_020ee52c();
/* decompiler-derived */
void func_020ee500(u32 arg0)
{
  func_02008848(arg0,0,0xf4);
  *data_02176de4 = arg0;
  func_020ee52c(arg0);
  return;
}
