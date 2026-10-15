/* src/game/unit_02115fbc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
/* decompiler-derived */
u32 Unk115fbc_Unk_116134(void)
{
  int value1;
  int value2;
  value1 = Unk044904_Unk_045080();
  value2 = func_0203ac00(0);
  *(u32 *)(value1 + 0x4c) = 1;
  if (value2 == 0) {
    *(u32 *)(value1 + 0x50) = 1;
  }
  else {
    *(u32 *)(value1 + 0x50) = 0;
  }
  return 1;
}

extern u8 data_02151b24[];
int func_02013c14();
int Unk03aae8_Unk_03ac9c();
/* decompiler-derived */
u32 Unk115fbc_Unk_1160f8(void)
{
  int value1;
  u32 value2;
  value1 = Unk044904_Unk_045080();
  value2 = Unk03aae8_Unk_03ac9c(0);
  func_02013c14(value1 + 0x54,0x20,((int)data_02151b24),value2);
  *(u32 *)(value1 + 0x48) = 1;
  return 3;
}
