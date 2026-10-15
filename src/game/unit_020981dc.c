/* src/game/unit_020981dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02096754();
/* decompiler-derived */
u16 Unk0981dc_Unk_0981dc(void)
{
  u16 value1;
  int value2;
  value2 = func_02096754();
  if (value2 == 0) {
    value1 = 0;
  }
  else {
    value1 = *(u16 *)(value2 + 0x36);
  }
  return value1;
}

int func_0209786c();
/* decompiler-derived */
void Unk0981dc_Unk_0981f4(u32 arg0,u32 arg1,u8 arg2)
{
  int value;
  value = func_02096754();
  if (value != 0) {
    switch(arg1) {
    case 0:
      *(u8 *)(value + 0xe) = arg2;
      break;
    case 1:
      *(u8 *)(value + 0xf) = arg2;
      break;
    case 2:
      *(u8 *)(value + 0x10) = arg2;
      break;
    case 3:
      *(u8 *)(value + 0x11) = arg2;
      break;
    case 4:
      *(u8 *)(value + 0x12) = arg2;
    }
    func_0209786c();
    return;
  }
}
