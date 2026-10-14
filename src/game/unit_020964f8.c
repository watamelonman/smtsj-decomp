/* src/game/unit_020964f8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
u32 func_020964f8(void)
{
  ImageObj_Unk_0773bc();
  return 1;
}

int func_0202dd84();
int func_0202de40();
int func_0202de98();
int func_02077314();
/* decompiler-derived */
u32 func_02096508(void)
{
  int tmp1;
  int tmp2;
  tmp1 = Unk095560_GetManager();
  tmp2 = func_0202dd84();
  if (((tmp2 == 0) && (tmp2 = func_0202de40(), tmp2 == 0)) &&
     (tmp2 = func_0202de98(), tmp2 == 0)) {
    *(u32 *)(tmp1 + 0x3b8) = 0;
  }
  func_02077314();
  return 1;
}
