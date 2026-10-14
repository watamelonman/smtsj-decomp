/* src/game/unit_0209d42c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_0209d600(int arg0)
{
  if (arg0 == 0xff) {
    arg0 = 0;
  }
  return arg0;
}

extern u8 data_02176278[];
/* decompiler-derived */
int func_0209d4e0(void)
{
  return *(int *)(((int)data_02176278) + 0x800) == *(int *)(((int)data_02176278) + 0x804);
}
