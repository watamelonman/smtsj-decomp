/* src/game/unit_02068f18.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_02069afc(int arg0,int arg1,int arg2,int arg3)
{
  int tmp1;
  tmp1 = (arg0 + arg2) * 0x1000000 >> 0x18;
  if (arg1 + arg3 < tmp1) {
    tmp1 = (arg1 + arg3) * 0x1000000 >> 0x18;
  }
  if (99 < tmp1) {
    tmp1 = 99;
  }
  return tmp1;
}
