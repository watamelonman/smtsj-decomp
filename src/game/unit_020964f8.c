/* src/game/unit_020964f8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
u32 Unk0964f8_Unk_0964f8(void)
{
  ImageObj_Unk_0773bc();
  return 1;
}

int Unk02dcfc_GetState();
int Unk02dcfc_GetField54();
int Unk02dcfc_GetField58();
int func_02077314();
/* decompiler-derived */
u32 Unk0964f8_Unk_096508(void)
{
  int value1;
  int value2;
  value1 = Unk095560_GetManager();
  value2 = Unk02dcfc_GetState();
  if (((value2 == 0) && (value2 = Unk02dcfc_GetField54(), value2 == 0)) &&
     (value2 = Unk02dcfc_GetField58(), value2 == 0)) {
    *(u32 *)(value1 + 0x3b8) = 0;
  }
  func_02077314();
  return 1;
}
