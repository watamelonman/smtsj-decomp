/* src/ImageBg.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176ca4[];
/* decompiler-derived */
u32 func_020e5570(void)
{
  return *data_02176ca4;
}


/* decompiler-derived */
int func_020e54b8(void)
{
  return *data_02176ca4 != 0;
}

int func_020e5638();
/* decompiler-derived */
void func_020e56f4(void)
{
  func_020e5638();
  *data_02176ca4 = 0;
  return;
}

int func_02061424();
/* decompiler-derived */
void func_020e5530(void)
{
  int tmp1;
  tmp1 = func_020e5570();
  if (tmp1 == 0) {
    func_020e5638();
    return;
  }
  func_02061424();
  return;
}


/* decompiler-derived */
void func_020e5550(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020e5570();
  if (tmp1 != 0) {
    *(u32 *)(tmp1 + 0xc) = arg0;
    *(u32 *)(tmp1 + 0x10) = arg1;
  }
  return;
}

int func_020e7790();
/* decompiler-derived */
void func_020e550c(void)
{
  int tmp1;
  tmp1 = func_020e5570();
  if (tmp1 == 0) {
    return;
  }
  *(u32 *)(tmp1 + 4) = 0;
  func_020e7790(0);
  return;
}
