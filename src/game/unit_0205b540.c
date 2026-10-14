/* src/game/unit_0205b540.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u8 data_0216a730[];
/* decompiler-derived */
u32 func_0205b7e0(void)
{
  return ((int)data_0216a730);
}


/* decompiler-derived */
u32 func_0205b7c0(void)
{
  return *(u32 *)(((int)data_0216a730) + 0x400);
}


/* decompiler-derived */
u32 func_0205b7d0(void)
{
  return *(u32 *)(((int)data_0216a730) + 0xc14);
}

extern u8 data_02143bdc[];
int func_02013c14();
int func_0205aa08();
int func_0205b598();
/* decompiler-derived */
void func_0205b7ec(void)
{
  int tmp1;
  tmp1 = func_0205aa08();
  if (tmp1 == 0) {
    return;
  }
  func_02013c14(tmp1 + 0x2c,0x20,((int)data_02143bdc));
  *(u8 *)(tmp1 + 0x58) = 1;
  func_0205b598(tmp1,0,0);
  return;
}
