/* src/game/unit_020ee904.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176de4[];
int func_020f7e48();
int func_020f8478();
/* decompiler-derived */
void func_020eeadc(void)
{
  int tmp1;
  int tmp2;
  tmp2 = *data_02176de4;
  tmp1 = Unk0e8228_Unk_0e82ac();
  if (tmp1 == 0) {
    func_020f8478(tmp2 + 0x50,0);
  }
  Unk0e8228_Unk_0e8d18(1);
  func_020f7e48(*(u32 *)(tmp2 + 0x40),0,8);
  return;
}
