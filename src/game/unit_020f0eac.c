/* src/game/unit_020f0eac.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_020f1000(u16 *arg0,u16 *arg1)
{
  int tmp1;
  tmp1 = (u32)arg0[1] - (u32)arg1[1];
  if (tmp1 == 0) {
    tmp1 = (u32)*arg0 - (u32)*arg1;
  }
  return tmp1;
}

extern u32 data_02176dfc[];
int func_020f7d7c();
int func_020f7e48();
/* decompiler-derived */
void func_020f0f2c(void)
{
  int tmp1;
  tmp1 = *data_02176dfc;
  func_020f7e48(*(u32 *)(tmp1 + 0x40),0,7);
  func_020f7d7c(*(u32 *)(tmp1 + 0x40),0x22);
  return;
}

int func_02044ec4();
int func_020e85a0();
int func_020e86a0();
int func_020e8c80();
int func_020f8478();
/* decompiler-derived */
void func_020f0eac(void)
{
  int tmp1;
  int tmp2;
  tmp2 = *data_02176dfc;
  func_020e8c80();
  func_02044ec4();
  tmp1 = Unk0e8228_Unk_0e82ac();
  if (tmp1 == 0) {
    func_020f8478(tmp2 + 0x50,0);
  }
  tmp1 = func_020e85a0();
  if (tmp1 != 0) {
    Unk0e8228_Unk_0e8d18(1);
    func_020e86a0();
  }
  func_020f7e48(*(u32 *)(tmp2 + 0x40),0,2);
  return;
}
