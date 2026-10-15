/* src/game/unit_020e5cb8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02050074();
/* decompiler-derived */
u32 Unk0e5cb8_Unk_0e5d80(int arg0,u32 arg1)
{
  u32 value1;
  int value2;
  value2 = 0;
  if (0 < arg0) {
    do {
      value1 = func_02050074(1,99);
      if (value1 < arg1) {
        return 1;
      }
      value2 = value2 + 1;
    } while (value2 < arg0);
  }
  return 0;
}
