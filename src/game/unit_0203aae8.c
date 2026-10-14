/* src/game/unit_0203aae8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk03aae8_Nop_03ae0c(void) { }

extern u8 data_0215de34[];
/* decompiler-derived */
u32 Unk03aae8_Unk_03ad14(void)
{
  return *(u32 *)(((int)data_0215de34) + 4);
}

int func_0203ac00();
int func_0209500c();
/* decompiler-derived */
u32 Unk03aae8_Unk_03aef0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  func_0209500c((int)v1,0);
  return 1;
}

int func_0203acf4();
int func_02050074();
/* decompiler-derived */
u32 Unk03aae8_Unk_03b878(void)
{
  int value;
  value = func_0203ac00(0);
  func_02050074(0,value + -1);
  func_0203acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk03aae8_Unk_03af50(void)
{
  short v1;
  int value1;
  u32 value2;
  value1 = Unk03aae8_Unk_03ad14();
  value2 = *(u32 *)(value1 + 0xe8);
  v1 = func_0203ac00(0);
  Unk02dcfc_Unk_02df00(value2,(int)v1);
  return 3;
}



/* decompiler-derived */
u32 func_0203ac9c(int arg0)
{
  int tmp1;
  int tmp2;
  tmp2 = *(int *)(((int)data_0215de34) + 4);
  tmp1 = *(int *)(tmp2 + 0x1c) - (arg0 + 1);
  switch(*(u8 *)(tmp2 + tmp1 + 0x20)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    return *(u32 *)(tmp2 + tmp1 * 4 + 0x3c);
  }
  return 0;
}
