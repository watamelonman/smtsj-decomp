/* src/game/unit_020f470c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0f470c_Nop_0f4874(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void Unk0f470c_Thunk_020f7248(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
/* decompiler-derived */
void Unk0f470c_Unk_0f4908(int arg0)
{
  int value;
  value = func_020f7210();
  if (value == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x54);
}

extern u32 data_02176e00[];
int func_02008848();
int func_020f4790();
/* decompiler-derived */
void Unk0f470c_Unk_0f4764(u32 arg0)
{
  func_02008848(arg0,0,0xf8);
  *data_02176e00 = arg0;
  func_020f4790(arg0);
}

int func_020d1d94();
int func_020ea630();
int func_020f4b80();
/* decompiler-derived */
void Unk0f470c_Unk_0f4c20(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0e8228_Unk_0e8bac();
  if (value1 == 0) {
    return;
  }
  func_020f4b80(arg0);
  value2 = func_020ea630(8);
  func_020d1d94(value2,0xffffffff);
}

