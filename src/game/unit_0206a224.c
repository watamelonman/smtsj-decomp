/* src/game/unit_0206a224.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_020d6cac(void);
/* forwards to `func_020d6cac` */
void func_0206ad34(void) { func_020d6cac(); }

extern u8 data_0216b9b0[];
/* decompiler-derived */
u32 func_0206a224(void)
{
  return *(u32 *)(((int)data_0216b9b0) + 8);
}


/* decompiler-derived */
void func_0206a244(u32 arg0)
{
  *(u32 *)(((int)data_0216b9b0) + 8) = arg0;
  return;
}
