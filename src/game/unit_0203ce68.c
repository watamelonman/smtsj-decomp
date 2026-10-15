/* src/game/unit_0203ce68.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02097ddc();
int Unk096754_Unk_096a14();
int Unk03ce68_Unk_03cf48(void)
{
    int v = Unk096754_Unk_096a14(func_0203ac00(0));
    int r = 1;
    if (v == -1) {
        r = 0;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

/* decompiler-derived */
u32 Unk03ce68_Unk_03cfb4(void)
{
  func_02097ddc();
  return 1;
}

int func_02096f28();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cfc4(void)
{
  func_02096f28();
  return 1;
}

int func_0203ac00();
int Unk03aae8_Unk_03acf4();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cf78(void)
{
  func_0203ac00(0);
  Unk03aae8_Unk_03acf4(1);
  return 1;
}

int Unk02ee5c_GetTierFromField70();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cff4(void)
{
  func_0203ac00(0);
  Unk02ee5c_GetTierFromField70();
  Unk03aae8_Unk_03acf4();
  return 1;
}

int Unk0981dc_Unk_0981dc();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cf94(void)
{
  u8 value;
  value = func_0203ac00(0);
  Unk0981dc_Unk_0981dc(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}

int func_0202ef34();
/* decompiler-derived */
u32 Unk03ce68_Unk_03d010(void)
{
  short v1;
  func_0203ac00(0);
  v1 = func_0203ac00(1);
  func_0202ef34((int)v1);
  return 1;
}



/* decompiler-derived */
u32 Unk03ce68_Unk_03d038(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0;
  case 1:
    return 4;
  case 2:
    return 1;
  case 3:
    return 2;
  case 4:
    return 3;
  default:
    return 0;
  }
}
