/* src/game/unit_0203bba4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202e788();
int func_0203acf4();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bcc0(void)
{
  int value;
  value = func_0202e788();
  func_0203acf4(*(u32 *)(value + 0x358));
  return 1;
}

int func_0203ac00();
int func_020b8660();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bbd0(void)
{
  u8 value;
  value = func_0203ac00(0);
  func_020b8660(value);
  return 1;
}

int func_0202df28();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bd18(void)
{
  short v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_07784c((int)v1);
  func_0202df28();
  return 3;
}


/* decompiler-derived */
u32 Unk03bba4_Unk_03bd7c(void)
{
  short v1;
  v1 = func_0203ac00(0);
  ImageObj_Unk_077880((int)v1);
  func_0202df28();
  return 3;
}

int ImageObj_Unk_07782c();
int func_020a2920();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bcd8(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_07782c((int)v1,(int)v2);
  func_0202df28();
  func_020a2920(0);
  return 3;
}


int ImageObj_Unk_077860();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bd3c(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  ImageObj_Unk_077860((int)v1,(int)v2);
  func_0202df28();
  func_020a2920(0);
  return 3;
}

int func_0202deb0();
int Unk03aae8_Unk_03ad14();
int func_0209e418();
/* decompiler-derived */
u32 Unk03bba4_Unk_03bbec(void)
{
  u16 value1;
  u16 value2;
  u16 value3;
  int value4;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = func_0203ac00(2);
  func_0209e418(value1,value2,value3);
  value4 = Unk03aae8_Unk_03ad14();
  func_0202deb0(*(u32 *)(value4 + 0xe8));
  return 3;
}
