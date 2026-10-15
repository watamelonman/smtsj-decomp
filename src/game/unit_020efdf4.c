/* src/game/unit_020efdf4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020f8264();
int func_020f8478();
/* decompiler-derived */
void Unk0efdf4_Unk_0eff1c(u32 arg0)
{
  func_020f8478(arg0,0);
  func_020f8264(arg0);
}

extern u32 data_02176df4[];
int func_020f7d7c();
int func_020f7e48();
/* decompiler-derived */
void Unk0efdf4_Unk_0eff5c(void)
{
  int value;
  value = *data_02176df4;
  func_020f7e48(*(u32 *)(value + 0x40),0,7);
  func_020f7d7c(*(u32 *)(value + 0x40),0x22);
}
