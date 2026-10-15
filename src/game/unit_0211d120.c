/* src/game/unit_0211d120.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02053000();
/* decompiler-derived */
void func_0211d288(int arg0)
{
  func_02053000(*(u32 *)(arg0 + 4));
  *(u32 *)(arg0 + 4) = 0;
  return;
}

int func_020493e0();
int func_0204faf0();
int func_020655b4();
int func_02065628();
int func_0206569c();
int func_02065b10();
int func_020a1428();
/* decompiler-derived */
void func_0211d198(u16 *arg0)
{
  int tmp1;
  func_02065628(1);
  func_020655b4(1);
  if (*(int *)(arg0 + 2) != 0) {
    tmp1 = func_020a1428(*arg0);
    func_0204faf0(6,*arg0);
    func_0204faf0(7,*(u8 *)(tmp1 + 2));
    func_020493e0(8);
    func_0206569c();
    return;
  }
  func_02065b10(1,*arg0);
  return;
}
