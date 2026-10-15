/* src/game/unit_0210b4d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
int func_0210b4d0();
/* decompiler-derived */
u32 Unk10b4d0_Unk_10b794(void)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = func_0210b4d0(*(u16 *)(value1 + 0x35c));
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}


/* decompiler-derived */
u8 Unk10b4d0_Unk_10b71c(u32 arg0)
{
  int value1;
  u8 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = func_0210b4d0(*(u16 *)(value1 + 0x35c));
  switch(arg0) {
  case 0x10:
    if (value1 != 0) {
      value2 = 2;
    }
    break;
  case 0x11:
    if (value1 == 0) {
      value2 = 2;
    }
    break;
  case 0x12:
    if (value1 == 0) {
      value2 = 3;
    }
    else {
      value2 = 1;
    }
    break;
  case 0x13:
    if (value1 == 0) {
      value2 = 1;
    }
    else {
      value2 = 3;
    }
  }
  return value2;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

int func_0210b7bc(void)
{
    int r = 0;
    if (func_0210b4d0(FIELD(u16, Unk02e000_GetWorkArea(), 860)) == 1) {
        r = 1;
    }
    return r;
}
