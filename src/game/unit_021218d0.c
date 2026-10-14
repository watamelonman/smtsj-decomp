/* src/game/unit_021218d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02121970();
int func_02122494();
/* decompiler-derived */
u32 func_02122590(u32 arg0,u32 *arg1)
{
  func_02122494(arg1,*arg1,arg0,0xffffffff);
  func_02121970(arg1);
  return *arg1;
}

int func_020457a8();
/* decompiler-derived */
u32 func_02122544(u32 arg0,u32 arg1)
{
  int tmp1;
  u32 tmp2;
  u32 tmp3;
  tmp1 = Unk044904_Get_data_0215ee98();
  tmp2 = func_020457a8();
  tmp3 = *(u16 *)(tmp1 + 0x3c) | 0x20000;
  *(u16 *)(tmp1 + 0x3c) = *(u16 *)(tmp1 + 0x3c) + 1;
  func_02122494(tmp2,tmp3,arg0,arg1);
  func_02121970(tmp2);
  return tmp3;
}
