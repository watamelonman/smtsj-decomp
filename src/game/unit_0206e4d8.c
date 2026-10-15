/* src/game/unit_0206e4d8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02170cc8[];
/* decompiler-derived */
u32 Unk06e4d8_Get_data_02170cc8(void)
{
  return *data_02170cc8;
}

extern u8 data_0216bac8[];
/* decompiler-derived */
int Unk06e4d8_Unk_06e4d8(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xbc;
}


/* decompiler-derived */
int Unk06e4d8_Unk_06e4f0(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xdc;
}


/* decompiler-derived */
int Unk06e4d8_Unk_06e508(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0xfc;
}


/* decompiler-derived */
int Unk06e4d8_Unk_06e520(int arg0)
{
  return arg0 * 0x148 + ((int)data_0216bac8) + 0x11c;
}

int func_02061424();
/* decompiler-derived */
void Unk06e4d8_Unk_06e680(void)
{
  func_02061424(*data_02170cc8);
  *data_02170cc8 = 0;
}



int func_02070440();
/* decompiler-derived */
void Unk06e4d8_Unk_06e6a4(int arg0)
{
  func_02070440(arg0 + 0xc,arg0 + 0x60,arg0 + 0x5c,arg0 + 100,arg0 + 0x2c,
                arg0 + 0x3c,arg0 + 0x4c);
}

int func_020086a0();
/* decompiler-derived */
void Unk06e4d8_Unk_06e814(int arg0)
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
}
