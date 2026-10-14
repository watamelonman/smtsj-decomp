/* src/game/unit_02125d84.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02053000();
int func_02056cac();
/* decompiler-derived */
void func_02125f0c(int *arg0)
{
  int tmp1;
  tmp1 = 0;
  if (0 < *arg0) {
    do {
      func_02056cac(arg0[1]);
      tmp1 = tmp1 + 1;
    } while (tmp1 < *arg0);
  }
  func_02053000(arg0[5]);
  arg0[5] = 0;
  func_02053000(arg0[4]);
  arg0[4] = 0;
  return;
}
