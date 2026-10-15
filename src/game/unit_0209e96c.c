/* src/game/unit_0209e96c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0204fde0();
int func_02052d7c();
/* decompiler-derived */
void Unk09e96c_Unk_09e9cc(void)
{
  int value1;
  u32 value2;
  value1 = GetGameState();
  if (value1 == 0) {
    return;
  }
  Unk095560_Unk_095764(0);
  value2 = func_0204fde0();
  *(u32 *)(value1 + 0x7430) = value2;
  *(u32 *)(value1 + 0x7434) = 0;
  *(u32 *)(value1 + 0x7438) = 0;
  func_02052d7c(*(u32 *)(value1 + 0x7430),*(u32 *)(value1 + 0x7434));
  *(u32 *)(value1 + 0x73e8) = 0xe;
}

int func_0204fe18();
/* decompiler-derived */
void Unk09e96c_Unk_09e96c(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  u32 value3;
  value1 = GetGameState();
  if (value1 == 0) {
    return;
  }
  value2 = Unk095560_Unk_095764(arg0);
  value3 = func_0204fde0();
  *(u32 *)(value1 + 0x7430) = value3;
  value2 = func_0204fe18(value2);
  *(u32 *)(value1 + 0x7434) = value2;
  *(u32 *)(value1 + 0x7438) = arg1;
  func_02052d7c(*(u32 *)(value1 + 0x7430),*(u32 *)(value1 + 0x7434));
  *(u32 *)(value1 + 0x73e8) = 0xe;
}
