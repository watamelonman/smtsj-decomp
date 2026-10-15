/* src/game/unit_020bbd6c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203acf4();
/* decompiler-derived */
u32 Unk0bbd6c_Unk_0bbec0(void)
{
  func_0203acf4(0);
  return 1;
}

int func_0203ac00();
/* decompiler-derived */
u32 Unk0bbd6c_Unk_0bbdd0(void)
{
  int value1;
  u32 value2;
  value1 = Unk0bac80_Unk_0badc0();
  value2 = func_0203ac00(0);
  *(u32 *)(value1 + 0x48) = value2;
  return 3;
}


/* decompiler-derived */
u32 Unk0bbd6c_Unk_0bbdf0(void)
{
  u16 value1;
  int value2;
  value2 = Unk0bac80_Unk_0badc0();
  value1 = func_0203ac00(0);
  *(u16 *)(value2 + 100) = value1;
  return 3;
}

int func_020fdaa8();
/* decompiler-derived */
u32 Unk0bbd6c_Unk_0bbe10(void)
{
  u32 value;
  value = func_0203ac00(0);
  func_020fdaa8(1,value);
  return 1;
}


/* decompiler-derived */
u32 Unk0bbd6c_Unk_0bbe30(void)
{
  u32 value;
  value = func_0203ac00(0);
  func_020fdaa8(2,value);
  return 1;
}
