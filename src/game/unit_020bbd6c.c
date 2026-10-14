/* src/game/unit_020bbd6c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203acf4();
/* decompiler-derived */
u32 func_020bbec0(void)
{
  func_0203acf4(0);
  return 1;
}

int func_0203ac00();
/* decompiler-derived */
u32 func_020bbdd0(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk0bac80_Unk_0badc0();
  tmp2 = func_0203ac00(0);
  *(u32 *)(tmp1 + 0x48) = tmp2;
  return 3;
}


/* decompiler-derived */
u32 func_020bbdf0(void)
{
  u16 tmp1;
  int tmp2;
  tmp2 = Unk0bac80_Unk_0badc0();
  tmp1 = func_0203ac00(0);
  *(u16 *)(tmp2 + 100) = tmp1;
  return 3;
}

int func_020fdaa8();
/* decompiler-derived */
u32 func_020bbe10(void)
{
  u32 tmp1;
  tmp1 = func_0203ac00(0);
  func_020fdaa8(1,tmp1);
  return 1;
}


/* decompiler-derived */
u32 func_020bbe30(void)
{
  u32 tmp1;
  tmp1 = func_0203ac00(0);
  func_020fdaa8(2,tmp1);
  return 1;
}
