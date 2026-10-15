/* src/game/unit_0205b540.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u8 data_0216a730[];
/* decompiler-derived */
u32 Unk05b540_GetAddr_data_0216a730(void)
{
  return ((int)data_0216a730);
}


/* decompiler-derived */
u32 Unk05b540_Unk_05b7c0(void)
{
  return *(u32 *)(((int)data_0216a730) + 0x400);
}


/* decompiler-derived */
u32 Unk05b540_Unk_05b7d0(void)
{
  return *(u32 *)(((int)data_0216a730) + 0xc14);
}

extern u8 data_02143bdc[];
int func_02013c14();
int func_0205aa08();
int func_0205b598();
/* decompiler-derived */
void Unk05b540_Unk_05b7ec(void)
{
  int value;
  value = func_0205aa08();
  if (value == 0) {
    return;
  }
  func_02013c14(value + 0x2c,0x20,((int)data_02143bdc));
  *(u8 *)(value + 0x58) = 1;
  func_0205b598(value,0,0);
}
