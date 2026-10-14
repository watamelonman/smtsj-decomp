/* src/game/unit_020feba0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_020fed7c(u32 *arg0,u32 arg1)
{
  switch(arg1) {
  case 0:
    *arg0 = 0xffffffbe;
    arg0[2] = 0;
    goto switchD_020fed80_default;
  case 1:
    arg0[2] = 0x14;
    goto switchD_020fed80_default;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    goto switchD_020fed80_default;
  }
  *arg0 = 0;
  arg0[5] = 100;
switchD_020fed80_default:
  arg0[3] = arg1;
  return;
}
