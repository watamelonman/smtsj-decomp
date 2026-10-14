/* src/game/unit_020a5680.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176b14[];
/* decompiler-derived */
void func_020a5718(void)
{
  *data_02176b14 = 0;
  return;
}

extern u8 data_0213c3e0[];
/* decompiler-derived */
int func_020a5e78(int arg0)
{
  return (int)*(short *)(((int)data_0213c3e0) + arg0 * 2);
}

int func_020a5e28();
/* decompiler-derived */
void func_020a6150(void)
{
  int tmp1;
  tmp1 = func_020a5e28();
  if (tmp1 == 0) {
    return;
  }
  *(u8 *)(tmp1 + 0x38) = 1;
  *(u8 *)(tmp1 + 0x39) = 0;
  return;
}
