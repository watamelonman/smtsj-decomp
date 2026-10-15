/* src/game/unit_02068f18.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk068f18_Unk_069afc(int arg0,int arg1,int arg2,int arg3)
{
  int value;
  value = (arg0 + arg2) * 0x1000000 >> 0x18;
  if (arg1 + arg3 < value) {
    value = (arg1 + arg3) * 0x1000000 >> 0x18;
  }
  if (99 < value) {
    value = 99;
  }
  return value;
}
