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
