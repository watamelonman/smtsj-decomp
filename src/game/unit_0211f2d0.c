/* src/game/unit_0211f2d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_0211f320(int *arg0)
{
  if (*arg0 != 0) {
    arg0[4] = 3;
  }
  return;
}


/* decompiler-derived */
void func_0211f308(int *arg0,int arg1)
{
  if (*arg0 != 0) {
    arg0[5] = arg1;
    arg0[4] = 1;
  }
  return;
}


/* decompiler-derived */
void func_0211f664(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0xb;
  arg0[2] = 0;
  *(u16 *)(arg0 + 3) = 0;
  return;
}

extern u32 data_02176e78[];
int func_02061424();
/* decompiler-derived */
void func_0211f37c(void)
{
  if (*data_02176e78 == 0) {
    return;
  }
  func_02061424();
  return;
}

int func_0211f3c8();
/* decompiler-derived */
void func_0211f354(void)
{
  int tmp1;
  if (*data_02176e78 != 0) {
    return;
  }
  tmp1 = func_0211f3c8();
  *data_02176e78 = tmp1;
  return;
}

int func_02008848();
int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void func_0211f2d0(int *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_0205ddb4(arg0[1]);
  func_020629c4(arg0[2]);
  func_02008848(arg0,0,0x28);
  return;
}
