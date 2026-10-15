/* src/game/unit_021122bc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_021122bc();
/* decompiler-derived */
u32 Unk1122bc_Unk_1124c8(void)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = func_0202e788();
  value1 = func_021122bc(*(u16 *)(value1 + 0x35c));
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}

int func_02112438();
/* decompiler-derived */
u32 Unk1122bc_Unk_112460(void)
{
  int value1;
  u32 value2;
  value2 = 1;
  value1 = func_0202e788();
  value1 = func_02112438(*(u16 *)(value1 + 0x35c));
  if (value1 == 1) {
    value1 = func_0202e788();
    value1 = func_021122bc(*(u16 *)(value1 + 0x35c));
    if (value1 == 0) {
      value2 = 0;
    }
  }
  return value2;
}
