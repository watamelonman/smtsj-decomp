/* src/game/unit_0203de08.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02dcfc_SetCode24();
int func_0204b6f4();
/* decompiler-derived */
u32 Unk03de08_Unk_03dfcc(void)
{
  func_0204b6f4();
  Unk02dcfc_SetCode24();
  return 3;
}

int Unk02e000_GetWorkArea();
int func_0203ac00();
int func_0204b74c();
/* decompiler-derived */
u32 Unk03de08_Unk_03df88(void)
{
  short v1;
  short v2;
  int value;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  value = Unk02e000_GetWorkArea();
  func_0204b74c((int)v1,(int)v2,*(u16 *)(value + 0x35c));
  return 1;
}


/* decompiler-derived */
u32 Unk03de08_Unk_03df3c(void)
{
  short v1;
  short v2;
  int value;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  value = Unk02e000_GetWorkArea();
  func_0204b74c((int)v1,(int)v2,*(u16 *)(value + 0x35c));
  func_0204b6f4();
  Unk02dcfc_SetCode24();
  return 3;
}
