/* src/game/unit_020939f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_02057678(void);
/* forwards to `func_02057678` */
void Unk0939f0_Thunk_02057678(void) { func_02057678(); }

extern u32 data_02175d8c[];
/* decompiler-derived */
void Unk0939f0_Set_data_02175d8c(u32 arg0)
{
  *data_02175d8c = arg0;
}


/* decompiler-derived */
u32 Unk0939f0_Get_data_02175d8c(void)
{
  return *data_02175d8c;
}

extern u32 data_02175d90[];
/* decompiler-derived */
void Unk0939f0_Clear_data_02175d90(void)
{
  *data_02175d90 = 0;
}

int func_02070440();
/* decompiler-derived */
void Unk0939f0_Unk_093dbc(int arg0)
{
  func_02070440(arg0 + 0xc,arg0 + 0x60,arg0 + 0x5c,arg0 + 100,arg0 + 0x2c,
                arg0 + 0x3c,arg0 + 0x4c);
}


int func_0200219c();
/* decompiler-derived */
void func_02093ea8(int arg0)
{
  u32 tmp1;
  if (*data_02175d90 == 0) {
    return;
  }
  tmp1 = func_0200219c(0xff000 - *(int *)(arg0 + 0x2c),0xd000);
  *(u32 *)(arg0 + 0x3c) = tmp1;
  tmp1 = func_0200219c(0xff000 - *(int *)(arg0 + 0x30),0xd000);
  *(u32 *)(arg0 + 0x40) = tmp1;
  tmp1 = func_0200219c(0xff000 - *(int *)(arg0 + 0x34),0xd000);
  *(u32 *)(arg0 + 0x44) = tmp1;
  *(u8 *)(arg0 + 0x6c) = 4;
  return;
}

int func_020086a0();
/* decompiler-derived */
void func_02093f0c(int arg0)
{
  func_020086a0(0,arg0 + 0xc,0x20);
  *(u8 *)(arg0 + 0xc) = 0xff;
  *(u8 *)(arg0 + 0xd) = 0xff;
  *(u8 *)(arg0 + 0xe) = 0xff;
  *(u32 *)(arg0 + 0x2c) = 0xff000;
  *(u32 *)(arg0 + 0x30) = 0xff000;
  *(u32 *)(arg0 + 0x34) = 0xff000;
  *(u32 *)(arg0 + 0x3c) = 0xff;
  *(u32 *)(arg0 + 0x40) = 0xff;
  *(u32 *)(arg0 + 0x44) = 0xff;
  *(u32 *)(arg0 + 0x4c) = 0xff;
  *(u32 *)(arg0 + 0x50) = 0xff;
  *(u32 *)(arg0 + 0x54) = 0xff;
  *(u32 *)(arg0 + 0x60) = 0;
  *(u32 *)(arg0 + 0x5c) = 0;
  *(u32 *)(arg0 + 100) = 0;
  return;
}

