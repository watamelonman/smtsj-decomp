/* src/game/unit_02038fbc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02008848();
int func_020516d0();
/* decompiler-derived */
void func_02039138(u32 *arg0)
{
  if (arg0 == (u32 *)0x0) {
    return;
  }
  func_020516d0(*arg0);
  func_02008848(arg0,0,0x8c);
  return;
}


/* decompiler-derived */
int func_020391d8(int *arg0)
{
  int tmp1;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  tmp1 = *arg0;
  if (tmp1 != 0) {
    return (int)(short)(u16)*(u8 *)(tmp1 + 10) * (int)(short)(u16)*(u8 *)(tmp1 + 0xb);
  }
  return 0;
}


/* decompiler-derived */
u32 func_02038fbc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,8);
    return 1;
  }
  return 0;
}


/* decompiler-derived */
u32 func_02039248(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x20;
  case 1:
    return 4;
  case 2:
    return 8;
  case 3:
    return 4;
  case 4:
    return 4;
  case 5:
    return 8;
  case 6:
    return 4;
  case 7:
    return 4;
  case 8:
    return 8;
  case 9:
    return 8;
  case 10:
    return 8;
  case 0xb:
    return 4;
  case 0xc:
    return 4;
  default:
    return 0;
  }
}
