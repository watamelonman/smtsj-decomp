/* src/game/unit_02100414.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk100414_Unk_100414(u16 *arg0,u16 *arg1)
{
  int value;
  value = *(int *)(arg1 + 4) - *(int *)(arg0 + 4);
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}
