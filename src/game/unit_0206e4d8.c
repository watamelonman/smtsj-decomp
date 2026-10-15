/* src/game/unit_0206e4d8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02170cc8[];
/* decompiler-derived */
u32 func_0206e670(void)
{
  return *data_02170cc8;
}

extern u8 data_0216bac8[];
/* decompiler-derived */
int func_0206e4d8(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xbc;
}


/* decompiler-derived */
int func_0206e4f0(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xdc;
}


/* decompiler-derived */
int func_0206e508(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xfc;
}


/* decompiler-derived */
int func_0206e520(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0x11c;
}

int func_02061424();
/* decompiler-derived */
void func_0206e680(void)
{
  func_02061424(*data_02170cc8);
  *data_02170cc8 = 0;
  return;
}



int func_02070440();
/* decompiler-derived */
void func_0206e6a4(int arg0)
{
  func_02070440(arg0 + 0xc,arg0 + 0x60,arg0 + 0x5c,arg0 + 100,arg0 + 0x2c,
                arg0 + 0x3c,arg0 + 0x4c);
  return;
}

int func_020086a0();
/* decompiler-derived */
void func_0206e814(int arg0)
{
  func_020086a0(0,arg0 + 0xc,0x20);
  *(u32 *)(arg0 + 0x2c) = 0;
  *(u32 *)(arg0 + 0x30) = 0;
  *(u32 *)(arg0 + 0x34) = 0;
  *(u32 *)(arg0 + 0x3c) = 0;
  *(u32 *)(arg0 + 0x4c) = 0;
  *(u32 *)(arg0 + 0x60) = 0;
  *(u32 *)(arg0 + 0x5c) = 0;
  *(u32 *)(arg0 + 100) = 0;
  return;
}
