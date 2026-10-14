/* src/game/unit_020981dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02096754();
/* decompiler-derived */
u16 func_020981dc(void)
{
  u16 tmp1;
  int tmp2;
  tmp2 = func_02096754();
  if (tmp2 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = *(u16 *)(tmp2 + 0x36);
  }
  return tmp1;
}

int func_0209786c();
/* decompiler-derived */
void func_020981f4(u32 arg0,u32 arg1,u8 arg2)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 != 0) {
    switch(arg1) {
    case 0:
      *(u8 *)(tmp1 + 0xe) = arg2;
      break;
    case 1:
      *(u8 *)(tmp1 + 0xf) = arg2;
      break;
    case 2:
      *(u8 *)(tmp1 + 0x10) = arg2;
      break;
    case 3:
      *(u8 *)(tmp1 + 0x11) = arg2;
      break;
    case 4:
      *(u8 *)(tmp1 + 0x12) = arg2;
    }
    func_0209786c();
    return;
  }
  return;
}
