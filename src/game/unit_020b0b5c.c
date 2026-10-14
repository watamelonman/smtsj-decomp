/* src/game/unit_020b0b5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_020b0d28(int *arg0,int *arg1)
{
  return *arg1 - *arg0;
}


/* decompiler-derived */
int func_020b0d38(int *arg0,int *arg1)
{
  return *arg0 - *arg1;
}

int func_02049d80();
int func_0204ab98();
/* decompiler-derived */
int func_020b0c78(u32 arg0,int arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = func_02049d80(arg0,0);
  tmp2 = func_0204ab98(arg0);
  if (tmp1 - tmp2 < arg1) {
    arg1 = tmp1 - tmp2;
  }
  return arg1;
}

int func_0204ab14();
/* decompiler-derived */
int func_020b0cf4(u32 arg0,int arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = func_02049d80(arg0,1);
  tmp2 = func_0204ab14(arg0);
  if (tmp1 - tmp2 < arg1) {
    arg1 = tmp1 - tmp2;
  }
  return arg1;
}
