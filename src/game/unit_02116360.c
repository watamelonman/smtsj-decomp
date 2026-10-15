/* src/game/unit_02116360.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_021163a4();
/* decompiler-derived */
void Unk116360_Unk_116404(int arg0,u32 arg1,u32 arg2)
{
  int value;
  if (arg0 == 0) {
    return;
  }
  value = func_0202e788();
  func_021163a4(arg0,*(u16 *)(value + 0x35c),arg1,arg2);
}

int func_02116360();
/* decompiler-derived */
u32 Unk116360_Unk_116438(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = func_0202e788();
  value1 = func_02116360(*(u16 *)(value1 + 0x35c),arg0,arg1);
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}
