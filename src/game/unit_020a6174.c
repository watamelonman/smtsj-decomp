/* src/game/unit_020a6174.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_020a6aac(int arg0,int arg1)
{
  return arg0 + arg1 * 0x10;
}


/* decompiler-derived */
int func_020a6ab4(int arg0,int arg1)
{
  return arg0 + 0x100 + arg1 * 0x10;
}

int func_02035c90();
/* decompiler-derived */
int func_020a6a88(int arg0,u32 arg1,u32 arg2)
{
  int tmp1;
  if (arg0 != 0) {
    tmp1 = func_02035c90(arg1,arg2);
    return arg0 + tmp1 * 2;
  }
  return 0;
}



