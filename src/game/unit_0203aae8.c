/* src/game/unit_0203aae8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_0203ae0c(void) { }

extern u8 data_0215de34[];
/* decompiler-derived */
u32 func_0203ad14(void)
{
  return *(u32 *)(((int)data_0215de34) + 4);
}

int func_0203ac00();
int func_0209500c();
/* decompiler-derived */
u32 func_0203aef0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0209500c((int)v1,0);
  return 1;
}

int func_0203acf4();
int func_02050074();
/* decompiler-derived */
u32 func_0203b878(void)
{
  int tmp1;
  tmp1 = func_0203ac00(0);
  func_02050074(0,tmp1 + -1);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 func_0203af50(void)
{
  short v1;
  int tmp2;
  u32 tmp3;
  tmp2 = func_0203ad14();
  tmp3 = *(u32 *)(tmp2 + 0xe8);
  v1 = func_0203ac00(0);
  Unk02dcfc_Unk_02df00(tmp3,(int)v1);
  return 3;
}
