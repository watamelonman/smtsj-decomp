/* src/game/unit_0203d930.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02dcfc_SetField64();
/* decompiler-derived */
u32 Unk03d930_Unk_03da00(void)
{
  Unk02dcfc_SetField64();
  return 3;
}

int func_0203ac00();
int func_02065544();
int func_020656ac();
int func_02065c10();
int func_020a0da4();
int Unk0caea8_Unk_0caf98();
/* decompiler-derived */
u32 Unk03d930_Unk_03d998(void)
{
  u32 value1;
  int value2;
  int value3;
  value1 = func_0203ac00(0);
  value2 = Unk03aae8_Unk_03ad14();
  value3 = *(int *)(value2 + 0xe8);
  Unk0d297c_Unk_0d2b70(value1);
  Unk10a034_Unk_10af40(value1);
  value2 = func_02065544();
  if (value2 == 0) {
    func_02065c10();
  }
  value1 = Unk0d297c_Unk_0d2f98(1);
  func_020656ac(value1,0xffffffff);
  *(u32 *)(value3 + 0x18) = 0x1e;
  Unk0caea8_Unk_0caf98(1);
  func_020a0da4(0x28);
  return 3;
}
