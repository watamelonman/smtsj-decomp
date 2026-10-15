/* src/game/unit_02115fbc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
/* decompiler-derived */
u32 func_02116134(void)
{
  int tmp1;
  int tmp2;
  tmp1 = Unk044904_Unk_045080();
  tmp2 = func_0203ac00(0);
  *(u32 *)(tmp1 + 0x4c) = 1;
  if (tmp2 == 0) {
    *(u32 *)(tmp1 + 0x50) = 1;
  }
  else {
    *(u32 *)(tmp1 + 0x50) = 0;
  }
  return 1;
}

extern u8 data_02151b24[];
int func_02013c14();
int func_0203ac9c();
/* decompiler-derived */
u32 func_021160f8(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk044904_Unk_045080();
  tmp2 = func_0203ac9c(0);
  func_02013c14(tmp1 + 0x54,0x20,((int)data_02151b24),tmp2);
  *(u32 *)(tmp1 + 0x48) = 1;
  return 3;
}
