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


int func_020537b8();
/* decompiler-derived */
void func_0206ae28(int arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x440) = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x444) = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x448) = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x44c) = 1;
  }
  return;
}
