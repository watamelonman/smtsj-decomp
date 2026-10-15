/* src/game/unit_021218d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02121970();
int func_02122494();
/* decompiler-derived */
u32 Unk1218d0_Unk_122590(u32 arg0,u32 *arg1)
{
  func_02122494(arg1,*arg1,arg0,0xffffffff);
  func_02121970(arg1);
  return *arg1;
}

int Unk044904_FindInactiveSlot();
/* decompiler-derived */
u32 Unk1218d0_Unk_122544(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  u32 value3;
  value1 = Unk044904_Get_data_0215ee98();
  value2 = Unk044904_FindInactiveSlot();
  value3 = *(u16 *)(value1 + 0x3c) | 0x20000;
  *(u16 *)(value1 + 0x3c) = *(u16 *)(value1 + 0x3c) + 1;
  func_02122494(value2,value3,arg0,arg1);
  func_02121970(value2);
  return value3;
}

