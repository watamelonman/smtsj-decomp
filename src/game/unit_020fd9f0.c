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



/* decompiler-derived */
void func_020fdb80(int arg0)
{
  *(u32 *)(arg0 + 0xc) = 0xffffffe5;
  *(u32 *)(arg0 + 0x14) = 1;
  *(u32 *)(arg0 + 0x28) = 1;
  *(u32 *)(arg0 + 0x2c) = 1;
  *(u32 *)(arg0 + 0x30) = 0;
  *(u32 *)(arg0 + 0x34) = 0;
  *(u32 *)(arg0 + 0x38) = 0;
  *(u32 *)(arg0 + 0x3c) = 0;
  *(u32 *)(arg0 + 0x24) = 0;
  *(u32 *)(arg0 + 0x40) = 0;
  return;
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
int func_02057e58();
/* decompiler-derived */
void func_020fe278(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057e58(2,0x30,10);
  func_02057eb8(2);
  func_02057524(4);
  return;
}

