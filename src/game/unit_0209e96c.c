/* src/game/unit_0209e96c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0204fde0();
int func_02052d7c();
/* decompiler-derived */
void func_0209e9cc(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = GetGameState();
  if (tmp1 == 0) {
    return;
  }
  Unk095560_Unk_095764(0);
  tmp2 = func_0204fde0();
  *(u32 *)(tmp1 + 0x7430) = tmp2;
  *(u32 *)(tmp1 + 0x7434) = 0;
  *(u32 *)(tmp1 + 0x7438) = 0;
  func_02052d7c(*(u32 *)(tmp1 + 0x7430),*(u32 *)(tmp1 + 0x7434));
  *(u32 *)(tmp1 + 0x73e8) = 0xe;
  return;
}

int func_0204fe18();
/* decompiler-derived */
void func_0209e96c(u32 arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  u32 tmp3;
  tmp1 = GetGameState();
  if (tmp1 == 0) {
    return;
  }
  tmp2 = Unk095560_Unk_095764(arg0);
  tmp3 = func_0204fde0();
  *(u32 *)(tmp1 + 0x7430) = tmp3;
  tmp2 = func_0204fe18(tmp2);
  *(u32 *)(tmp1 + 0x7434) = tmp2;
  *(u32 *)(tmp1 + 0x7438) = arg1;
  func_02052d7c(*(u32 *)(tmp1 + 0x7430),*(u32 *)(tmp1 + 0x7434));
  *(u32 *)(tmp1 + 0x73e8) = 0xe;
  return;
}
