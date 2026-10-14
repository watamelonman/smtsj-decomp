/* src/game/unit_020e5cb8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02050074();
/* decompiler-derived */
u32 func_020e5d80(int arg0,u32 arg1)
{
  u32 tmp1;
  int tmp2;
  tmp2 = 0;
  if (0 < arg0) {
    do {
      tmp1 = func_02050074(1,99);
      if (tmp1 < arg1) {
        return 1;
      }
      tmp2 = tmp2 + 1;
    } while (tmp2 < arg0);
  }
  return 0;
}
