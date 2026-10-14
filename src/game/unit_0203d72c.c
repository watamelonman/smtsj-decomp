/* src/game/unit_0203d72c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int func_0209ea18();
/* decompiler-derived */
u32 func_0203d828(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  func_0209ea18((int)v1,(int)v2);
  return 3;
}

int func_0209ebd0();
/* decompiler-derived */
u32 func_0203d85c(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  func_0209ebd0((int)v1,(int)v2);
  return 3;
}

int func_02095258();
/* decompiler-derived */
u32 func_0203d8f0(void)
{
  u8 tmp1;
  u8 tmp2;
  u16 tmp3;
  tmp1 = func_0203ac00(0);
  tmp3 = func_0203ac00(1);
  tmp2 = func_0203ac00(2);
  func_02095258(tmp1,tmp3,tmp2);
  return 3;
}

int func_0202e788();
int func_02035b08();
int func_0209e564();
/* decompiler-derived */
u32 func_0203d75c(void)
{
  int tmp1;
  int tmp2;
  u32 tmp3;
  u32 tmp4;
  u32 tmp5;
  u32 tmp6;
  tmp1 = func_0203ac00(0);
  tmp2 = func_0203ac00(1);
  tmp3 = func_0203ac00(2);
  tmp4 = func_0203ac00(3);
  tmp5 = func_0203ac00(4);
  if (tmp1 < 0 || tmp2 < 0) {
    tmp1 = func_0202e788();
    tmp6 = (u32)*(u16 *)(tmp1 + 0x35c);
  }
  else {
    tmp6 = func_02035b08(tmp1,tmp2);
  }
  func_0209e564(tmp6,tmp3,tmp4,tmp5);
  return 3;
}
