/* src/game/unit_020efff4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020f0260(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void func_020f0498(void) { func_020f7248(); }

extern u32 data_02176df8[];
int func_02008848();
int func_020f019c();
/* decompiler-derived */
void func_020f004c(u32 arg0)
{
  func_02008848(arg0,0,0x110);
  *data_02176df8 = arg0;
  func_020f019c(arg0);
  return;
}

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void func_020f0300(int arg0)
{
  int tmp1;
  tmp1 = func_020f7210();
  if (tmp1 == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x50);
  if (*(int *)(arg0 + 8) != 10) {
    return;
  }
  func_020feed4();
  return;
}

