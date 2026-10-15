/* src/game/unit_020b0b5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk0b0b5c_Unk_0b0d28(int *arg0,int *arg1)
{
  return *arg1 - *arg0;
}


/* decompiler-derived */
int Unk0b0b5c_Unk_0b0d38(int *arg0,int *arg1)
{
  return *arg0 - *arg1;
}

int func_02049d80();
int func_0204ab98();
/* decompiler-derived */
int Unk0b0b5c_Unk_0b0c78(u32 arg0,int arg1)
{
  int value1;
  int value2;
  value1 = func_02049d80(arg0,0);
  value2 = func_0204ab98(arg0);
  if (value1 - value2 < arg1) {
    arg1 = value1 - value2;
  }
  return arg1;
}

int func_0204ab14();
/* decompiler-derived */
int Unk0b0b5c_Unk_0b0cf4(u32 arg0,int arg1)
{
  int value1;
  int value2;
  value1 = func_02049d80(arg0,1);
  value2 = func_0204ab14(arg0);
  if (value1 - value2 < arg1) {
    arg1 = value1 - value2;
  }
  return arg1;
}
