/* src/game/unit_0210fe28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void func_0210fe28(int arg0)
{
  u32 tmp1;
  tmp1 = func_0204fe68(*(u32 *)(arg0 + 0x18),1);
  func_0204fed8(tmp1,*(u32 *)(arg0 + 8));
  return;
}

int func_02053000();
int func_0210ff80();
/* decompiler-derived */
void func_021113e0(int arg0)
{
  func_0210ff80();
  func_02053000(*(u32 *)(arg0 + 0x18));
  *(u32 *)(arg0 + 0x18) = 0;
  return;
}
