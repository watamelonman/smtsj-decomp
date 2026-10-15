/* src/game/unit_0205b540.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u8 data_0216a730[];
int func_02008848();
void func_0205b540(void)
{
    func_02008848(data_0216a730, 0, 0xc18);
}

void func_0205b560(u32 a, u32 b, u32 c)
{
    func_0205b540();
    FIELD(u32, data_0216a730, 0xc0c) = a;
    FIELD(u32, data_0216a730, 0xc10) = b + c;
    FIELD(u32, data_0216a730, 0xc14) = b;
    FIELD(u32, data_0216a730, 0x404) = a;
    FIELD(u32, data_0216a730, 0x408) = b + c;
}

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
