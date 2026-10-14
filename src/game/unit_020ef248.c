/* src/game/unit_020ef248.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020ef4b4(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void func_020ef6f0(void) { func_020f7248(); }

extern u32 data_02176df0[];
int func_02008848();
int func_020ef3f0();
/* decompiler-derived */
void func_020ef2a0(u32 arg0)
{
  func_02008848(arg0,0,0x10c);
  *data_02176df0 = arg0;
  func_020ef3f0(arg0);
  return;
}

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void func_020ef548(int arg0)
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

int func_02044ec4();
int func_020e8c80();
int func_020f7d14();
int func_020f7e48();
/* decompiler-derived */
void func_020ef878(void)
{
  int tmp1;
  tmp1 = *data_02176df0;
  func_020e8c80();
  func_02044ec4();
  func_020f7d14(*(u32 *)(tmp1 + 4));
  func_020f7e48(*(u32 *)(tmp1 + 0x40),0,1);
  return;
}
