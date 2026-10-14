/* src/game/unit_020fd9f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_020fdc0c(int arg0)
{
  *(u32 *)(arg0 + 0x14) = 0xffffffff;
  return;
}

extern u32 data_02176e20[];
/* decompiler-derived */
u32 func_020fdb04(void)
{
  return *data_02176e20;
}

int func_020572d8();
int func_02057eb8();
/* decompiler-derived */
void func_020fe2b0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
  return;
}

int func_02061424();
/* decompiler-derived */
void func_020fda14(void)
{
  int tmp1;
  tmp1 = func_020fdb04();
  if (tmp1 == 0) {
    return;
  }
  func_02061424();
  return;
}

int func_020fdb14();
/* decompiler-derived */
void func_020fd9f0(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_020fdb04();
  if (tmp1 != 0) {
    return;
  }
  tmp2 = func_020fdb14();
  *data_02176e20 = tmp2;
  return;
}


/* decompiler-derived */
void func_020fe33c(int arg0)
{
  if (*(int *)(arg0 + 0x24) == 0) {
    return;
  }
  func_02061424();
  *(u32 *)(arg0 + 0x24) = 0;
  return;
}
