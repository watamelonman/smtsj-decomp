/* src/game/unit_020ce578.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0ce578_Nop_0ce5e4(void) { }

int func_020d3138();
/* decompiler-derived */
void Unk0ce578_Unk_0cec98(int arg0)
{
  u32 tmp1;
  tmp1 = func_020d3138();
  Unk122e1c_Unk_122f88(*(u32 *)(arg0 + 0x10),0,tmp1);
  return;
}

int func_020cf238();
int func_02123294();
/* decompiler-derived */
void Unk0ce578_Unk_0cf29c(int arg0,u32 arg1)
{
  func_02123294(*(u32 *)(arg0 + 0x10));
  *(u32 *)(arg0 + 0xd8) = arg1;
  *(u32 *)(arg0 + 4) = 1;
  func_020cf238(arg0,3);
  return;
}

extern u8 data_02176bd0[];
int func_020956c8();
int func_020bc9b4();
int func_020de870();
int func_02122aa0();
int func_02124258();
/* decompiler-derived */
void Unk0ce578_Unk_0ce5e8(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    func_020bc9b4(0x14,0);
    func_02124258();
    func_02122aa0();
  }
  func_020de870();
  func_020956c8();
  *(u32 *)(((int)data_02176bd0) + 4) = 0;
  return;
}

int func_020a0da4();
/* decompiler-derived */
void Unk0ce578_Unk_0cf258(int arg0,int arg1)
{
  int tmp1;
  if ((arg1 == 2) && (tmp1 = func_020d3138(), tmp1 == 0)) {
    return;
  }
  func_020a0da4(5);
  *(u32 *)(arg0 + 4) = 4;
  func_020cf238(arg0,9);
  *(int *)(arg0 + 0xc) = arg1;
  return;
}


