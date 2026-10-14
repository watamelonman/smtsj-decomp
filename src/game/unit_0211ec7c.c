/* src/game/unit_0211ec7c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_0211ef08(void) { }

int func_0202e0cc();
int func_0205b82c();
/* decompiler-derived */
u32 func_0211efec(void)
{
  func_0202e0cc();
  func_0205b82c(0xd2);
  return 1;
}

int func_0205dde4();
int func_0211eda0();
/* decompiler-derived */
void func_0211ee8c(int arg0)
{
  func_0205dde4(*(u32 *)(arg0 + 4));
  func_0211eda0(*(u32 *)(arg0 + 8));
  return;
}


/* decompiler-derived */
void func_0211ef0c(int arg0)
{
  u32 tmp1;
  tmp1 = *(int *)(arg0 + 0x18) + 1;
  *(u32 *)(arg0 + 0x18) = tmp1;
  if (*(u32 *)(arg0 + 0x14) < tmp1) {
    *(u32 *)(arg0 + 0x10) = 3;
  }
  return;
}

int func_0211ee10();
/* decompiler-derived */
void func_0211ef2c(int arg0)
{
  *(int *)(arg0 + 0x1c) = *(int *)(arg0 + 0x1c) + -1;
  func_0211ee10(arg0,0);
  if (0 < *(int *)(arg0 + 0x1c)) {
    return;
  }
  *(u32 *)(arg0 + 0x10) = 0;
  *(u32 *)(arg0 + 0x14) = 0;
  *(u32 *)(arg0 + 0x18) = 0;
  *(u32 *)(arg0 + 0x1c) = 0;
  *(u16 *)(arg0 + 0x24) = 0;
  *(u32 *)(arg0 + 0x20) = 0;
  return;
}
