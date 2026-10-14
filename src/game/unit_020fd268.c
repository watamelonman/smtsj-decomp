/* src/game/unit_020fd268.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e1c[];
/* decompiler-derived */
u32 func_020fd4b4(void)
{
  return *data_02176e1c;
}

int func_02061424();
/* decompiler-derived */
void func_020fd3ac(void)
{
  int tmp1;
  tmp1 = func_020fd4b4();
  if (tmp1 == 0) {
    return;
  }
  func_02061424();
  return;
}


/* decompiler-derived */
void func_020fd47c(void)
{
  int tmp1;
  tmp1 = func_020fd4b4();
  if (tmp1 != 0) {
    *(u32 *)(tmp1 + 0x2c) = 0;
  }
  return;
}


/* decompiler-derived */
void func_020fd494(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020fd4b4();
  if (tmp1 != 0) {
    *(u32 *)(tmp1 + 0x30) = arg0;
    *(u32 *)(tmp1 + 0x34) = arg1;
  }
  return;
}

int func_020fd4c4();
/* decompiler-derived */
void func_020fd380(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_020fd4b4();
  if (tmp1 != 0) {
    return;
  }
  tmp2 = func_020fd4c4(arg0);
  *data_02176e1c = tmp2;
  return;
}
