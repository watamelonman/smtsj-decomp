/* src/game/unit_020a5680.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176b14[];
/* decompiler-derived */
void func_020a5718(void)
{
  *data_02176b14 = 0;
  return;
}

extern u8 data_0213c3e0[];
/* decompiler-derived */
int func_020a5e78(int arg0)
{
  return (int)*(short *)(((int)data_0213c3e0) + arg0 * 2);
}

int func_020a5e28();
/* decompiler-derived */
void func_020a6150(void)
{
  int tmp1;
  tmp1 = func_020a5e28();
  if (tmp1 == 0) {
    return;
  }
  *(u8 *)(tmp1 + 0x38) = 1;
  *(u8 *)(tmp1 + 0x39) = 0;
  return;
}


int func_020a1854();
int func_020a59f4();
/* decompiler-derived */
int func_020a5c14(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_020a1854();
  tmp2 = func_020a59f4(tmp1,arg1,arg2);
  return tmp2 != 0;
}

int func_0205c41c();
int func_0205ca88();
/* decompiler-derived */
void func_020a611c(void)
{
  u32 *v1;
  int tmp2;
  v1 = (u32 *)func_020a5e28();
  if (v1 == (u32 *)0x0) {
    return;
  }
  tmp2 = func_0205ca88(*v1);
  func_0205c41c(*v1,tmp2 + -1);
  *(u8 *)(v1 + 0xe) = 0;
  return;
}
