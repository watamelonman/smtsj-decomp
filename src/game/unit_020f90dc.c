/* src/game/unit_020f90dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0f90dc_Nop_0f9ce4(void) { }


/* decompiler-derived */
int Unk0f90dc_Unk_0f9128(int *arg0,int *arg1)
{
  return (u32)*(u8 *)(*arg0 + 1) - (u32)*(u8 *)(*arg1 + 1);
}

int func_02053000();
int func_020f91fc();
/* decompiler-derived */
void Unk0f90dc_Unk_0fa4cc(int arg0)
{
  func_020f91fc();
  Unk0d297c_Unk_0d2e88();
  func_02053000(*(u32 *)(arg0 + 0x50));
  *(u32 *)(arg0 + 0x50) = 0;
  func_02053000(*(u32 *)(arg0 + 0xf8));
  *(u32 *)(arg0 + 0xf8) = 0;
  func_02053000(*(u32 *)(arg0 + 0xec));
  *(u32 *)(arg0 + 0xec) = 0;
  func_02053000(*(u32 *)(arg0 + 0xf4));
  *(u32 *)(arg0 + 0xf4) = 0;
  return;
}
