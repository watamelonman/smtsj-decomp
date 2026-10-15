/* src/game/unit_020a6174.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk0a6174_Unk_0a6aac(int arg0,int arg1)
{
  return arg0 + arg1 * 0x10;
}


/* decompiler-derived */
int Unk0a6174_Unk_0a6ab4(int arg0,int arg1)
{
  return arg0 + 0x100 + arg1 * 0x10;
}

int func_02035c90();
/* decompiler-derived */
int Unk0a6174_Unk_0a6a88(int arg0,u32 arg1,u32 arg2)
{
  int value;
  if (arg0 != 0) {
    value = func_02035c90(arg1,arg2);
    return arg0 + value * 2;
  }
  return 0;
}



