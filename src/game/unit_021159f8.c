/* src/game/unit_021159f8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
int func_021159f8();
int func_02035b08();
int func_02115bcc(int x)
{
    int r = 0;
    if (x == func_02035b08(8, 3)) {
        r = 1;
    }
    return r;
}

/* decompiler-derived */
u32 Unk1159f8_Unk_115c68(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = func_021159f8(*(u16 *)(value1 + 0x35c),arg0,arg1);
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}
