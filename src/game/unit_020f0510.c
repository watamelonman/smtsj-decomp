/* src/game/unit_020f0510.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176df8[];
int func_020f7d14();
int func_020f7e48();
/* decompiler-derived */
void Unk0f0510_Unk_0f06a4(void)
{
  int value;
  value = *data_02176df8;
  func_020f7d14(*(u32 *)(value + 4));
  func_020f7e48(*(u32 *)(value + 0x40),0,1);
}
