/* src/game/unit_0210b4d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_0210b4d0();
/* decompiler-derived */
u32 func_0210b794(void)
{
  int tmp1;
  u32 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_0210b4d0(*(u16 *)(tmp1 + 0x35c));
  if (tmp1 == 1) {
    tmp2 = 2;
  }
  return tmp2;
}


/* decompiler-derived */
u8 func_0210b71c(u32 arg0)
{
  int tmp1;
  u8 tmp2;
  tmp2 = 0;
  tmp1 = func_0202e788();
  tmp1 = func_0210b4d0(*(u16 *)(tmp1 + 0x35c));
  switch(arg0) {
  case 0x10:
    if (tmp1 != 0) {
      tmp2 = 2;
    }
    break;
  case 0x11:
    if (tmp1 == 0) {
      tmp2 = 2;
    }
    break;
  case 0x12:
    if (tmp1 == 0) {
      tmp2 = 3;
    }
    else {
      tmp2 = 1;
    }
    break;
  case 0x13:
    if (tmp1 == 0) {
      tmp2 = 1;
    }
    else {
      tmp2 = 3;
    }
  }
  return tmp2;
}
