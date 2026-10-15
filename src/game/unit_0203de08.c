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

int Unk03aae8_Unk_03acf4();
int func_02035b08();
int Unk02e000_TestFlag();
int func_0203dfe0(void)
{
    u8 a = func_0203ac00(0);
    u8 b = func_0203ac00(1);
    if (Unk02e000_TestFlag(func_02035b08(a, b))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
