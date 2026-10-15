/* src/game/unit_0206ea70.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk06ea70_Unk_06edf4(int *arg0,int *arg1,int *arg2,u16 *arg3)
{
  u32 value1;
  int value2;
  value2 = 0;
  do {
    value1 = (u32)*arg3;
    value2 = value2 + 1;
    *arg0 = (value1 & 0x1f) << 0xf;
    *arg1 = ((int)value1 >> 5 & 0x1fU) << 0xf;
    *arg2 = ((int)value1 >> 10 & 0x1fU) << 0xf;
    arg0 = arg0 + 1;
    arg1 = arg1 + 1;
    arg2 = arg2 + 1;
    arg3 = arg3 + 1;
  } while (value2 < 0x100);
}

extern u8 data_02170ccc[];
int func_02053000();
/* decompiler-derived */
void func_0206f4e4(void)
{
  func_02053000(*(u32 *)(data_02170ccc + 4));
  *(u32 *)(data_02170ccc + 4) = 0;
}
