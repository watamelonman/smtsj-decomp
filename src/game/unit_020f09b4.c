/* src/game/unit_020f09b4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020f0b94(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void func_020f0b10(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
int func_020feed4();
/* decompiler-derived */
void func_020f09b4(int arg0)
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

int func_020e8374();
int func_020f8478();
int func_020fda58();
int func_020febe8();
/* decompiler-derived */
void func_020f0b64(int arg0)
{
  u32 tmp1;
  func_020febe8(1);
  func_020fda58(0);
  tmp1 = func_020e8374(*(u32 *)(arg0 + 0x4c));
  func_020f8478(arg0 + 0x50,tmp1);
  return;
}
