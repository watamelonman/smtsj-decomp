/* src/game/unit_020964f8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
u32 Unk0964f8_Unk_0964f8(void)
{
  ImageObj_Unk_0773bc();
  return 1;
}

int func_0202dd84();
int func_0202de40();
int func_0202de98();
int func_02077314();
/* decompiler-derived */
u32 Unk0964f8_Unk_096508(void)
{
  int value1;
  int value2;
  value1 = Unk095560_GetManager();
  value2 = func_0202dd84();
  if (((value2 == 0) && (value2 = func_0202de40(), value2 == 0)) &&
     (value2 = func_0202de98(), value2 == 0)) {
    *(u32 *)(value1 + 0x3b8) = 0;
  }
  func_02077314();
  return 1;
}
