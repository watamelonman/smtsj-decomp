/* src/game/unit_0202ee5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
/* decompiler-derived */
int Unk02ee5c_Unk_02f044(void)
{
  int value;
  value = Unk02e000_GetWorkArea();
  return value + 0x368;
}

int func_02008848();
/* decompiler-derived */
void Unk02ee5c_Unk_02f054(void)
{
  int value;
  value = Unk02ee5c_Unk_02f044();
  func_02008848(value,0,6);
  *(u8 *)(value + 1) = 100;
}
