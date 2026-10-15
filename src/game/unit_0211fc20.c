/* src/game/unit_0211fc20.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e7c[];
/* decompiler-derived */
void Unk11fc20_Clear_data_02176e7c(void)
{
  *data_02176e7c = 0;
}

int func_02061424();
/* decompiler-derived */
void Unk11fc20_Unk_11fc48(void)
{
  if (*data_02176e7c == 0) {
    return;
  }
  func_02061424();
}

int func_0211fcb0();
/* decompiler-derived */
void Unk11fc20_Unk_11fc20(void)
{
  int value;
  if (*data_02176e7c != 0) {
    return;
  }
  value = func_0211fcb0();
  *data_02176e7c = value;
}


/* decompiler-derived */
int Unk11fc20_Unk_120944(int arg0)
{
  int value1;
  int value2;
  value1 = 0;
  value2 = 0;
  do {
    value2 = value2 + 1;
    if (*(int *)(arg0 + 0x1a8) != 0) {
      value1 = value1 + 1;
    }
    arg0 = arg0 + 0x2c;
  } while (value2 < 0x20);
  return value1;
}


int func_02120bd4();
/* decompiler-derived */
void func_0212143c(int arg0,int arg1,u32 arg2)
{
  func_02120bd4(4,0,*(u32 *)(arg0 + 0xc),*(u32 *)(arg0 + 0x10),0x3000,
                arg1 << 0xc,arg2,0,0);
  return;
}

int func_020a0da4();
/* decompiler-derived */
void func_0211fd38(u32 *arg0)
{
  arg0[3] = 100;
  *arg0 = 0;
  arg0[6] = 0;
  arg0[7] = 1;
  arg0[10] = 0x40000;
  arg0[0xb] = 0xb8000;
  arg0[0x11] = 0x4000;
  func_020a0da4(8);
  return;
}


/* decompiler-derived */
void func_02120b88(u32 arg0,u32 arg1,int arg2,int arg3,int arg4,
                  int arg5,u32 arg6,u32 arg7,u32 arg8)
{
  func_02120bd4(arg0,arg1,arg2 << 0xc,arg3 << 0xc,arg4 << 0xc,arg5 << 0xc,arg6,
                arg7,arg8);
  return;
}

