/* src/game/unit_020bd5f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u8 data_0213c4d4[];
int func_02057ddc();
/* decompiler-derived */
u32 func_020bd614(int arg0)
{
  func_02057ddc(*(u32 *)(((int)data_0213c4d4) + arg0 * 4));
  return 0;
}

int func_020c8008();
/* decompiler-derived */
void func_020c1ad8(void)
{
  func_020c8008(0,0,0,0);
  return;
}

extern u32 data_02176bb0[];
int func_020c1b94();
/* decompiler-derived */
void func_020c20f0(void)
{
  if (*data_02176bb0 == 0) {
    return;
  }
  func_020c1b94();
  return;
}


/* decompiler-derived */
int func_020c7588(u16 *arg0,u16 *arg1)
{
  int tmp1;
  tmp1 = (u32)arg0[1] - (u32)arg1[1];
  if (tmp1 == 0) {
    tmp1 = (u32)*arg0 - (u32)*arg1;
  }
  return tmp1;
}
