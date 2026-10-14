/* src/game/unit_02109dcc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0205c3dc();
/* decompiler-derived */
void func_02109f70(int arg0)
{
  if (*(int *)(arg0 + 0x10) == 0) {
    return;
  }
  func_0205c3dc();
  *(u32 *)(arg0 + 0x10) = 0;
  return;
}

int func_0205c704();
int func_02061424();
/* decompiler-derived */
void func_02109dcc(int arg0)
{
  func_0205c704(*(u32 *)(arg0 + 0x10));
  if (**(int **)(arg0 + 4) != 0) {
    return;
  }
  func_02061424(arg0);
  return;
}
