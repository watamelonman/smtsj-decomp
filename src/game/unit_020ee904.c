/* src/game/unit_020ee904.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176de4[];
int func_020f7e48();
int func_020f8478();
/* decompiler-derived */
void Unk0ee904_Unk_0eeadc(void)
{
  int value1;
  int value2;
  value2 = *data_02176de4;
  value1 = Unk0e8228_Unk_0e82ac();
  if (value1 == 0) {
    func_020f8478(value2 + 0x50,0);
  }
  Unk0e8228_Unk_0e8d18(1);
  func_020f7e48(*(u32 *)(value2 + 0x40),0,8);
}
