/* src/game/unit_0203d930.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202dfa0();
/* decompiler-derived */
u32 func_0203da00(void)
{
  func_0202dfa0();
  return 3;
}

int func_0203ac00();
int func_02065544();
int func_020656ac();
int func_02065c10();
int func_020a0da4();
int func_020caf98();
/* decompiler-derived */
u32 func_0203d998(void)
{
  u32 tmp1;
  int tmp2;
  int tmp3;
  tmp1 = func_0203ac00(0);
  tmp2 = Unk03aae8_Unk_03ad14();
  tmp3 = *(int *)(tmp2 + 0xe8);
  Unk0d297c_Unk_0d2b70(tmp1);
  Unk10a034_Unk_10af40(tmp1);
  tmp2 = func_02065544();
  if (tmp2 == 0) {
    func_02065c10();
  }
  tmp1 = Unk0d297c_Unk_0d2f98(1);
  func_020656ac(tmp1,0xffffffff);
  *(u32 *)(tmp3 + 0x18) = 0x1e;
  func_020caf98(1);
  func_020a0da4(0x28);
  return 3;
}
