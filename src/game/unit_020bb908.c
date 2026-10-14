/* src/game/unit_020bb908.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int func_0203acf4();
int func_0204fde0();
int func_0204fe18();
int func_02050074();
int func_020bc0b4();
/* decompiler-derived */
u32 func_020bb908(void)
{
  int tmp1;
  u32 tmp2;
  int tmp3;
  int tmp4;
  tmp1 = func_0203ac00(0);
  if (tmp1 < 0xf) {
    func_020bc0b4();
    tmp2 = Unk0bac80_Unk_0badec(0);
    tmp1 = func_0204fe18();
    tmp1 = func_02050074(0,tmp1 + -1);
    tmp3 = func_0204fde0(tmp2);
    tmp4 = Unk0bac80_Unk_0badc0();
    *(int *)(tmp4 + 0x68) = tmp1 * 0x24 + tmp3;
    func_0203acf4(tmp1);
  }
  else {
    func_0203acf4(0);
  }
  return 1;
}


/* decompiler-derived */
u32 func_020bb978(void)
{
  int tmp1;
  u32 tmp2;
  int tmp3;
  int tmp4;
  tmp1 = func_0203ac00(0);
  if (tmp1 < 0xf) {
    func_020bc0b4();
    tmp2 = Unk0bac80_Unk_0badec(1);
    tmp1 = func_0204fe18();
    tmp1 = func_02050074(0,tmp1 + -1);
    tmp3 = func_0204fde0(tmp2);
    tmp4 = Unk0bac80_Unk_0badc0();
    *(int *)(tmp4 + 0x68) = tmp1 * 0x24 + tmp3;
    func_0203acf4(tmp1);
  }
  else {
    func_0203acf4(0);
  }
  return 1;
}
