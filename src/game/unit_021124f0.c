/* src/game/unit_021124f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* returns 1 */
int Unk1124f0_GetConst1(void) { return 1; }

extern u8 data_0213cb24[];
/* decompiler-derived */
int Unk1124f0_Unk_11259c(int arg0)
{
  return ((int)data_0213cb24) + arg0 * 8;
}

int func_0209a884();
/* decompiler-derived */
void Unk1124f0_Unk_112538(void)
{
  int value;
  value = GetGameState();
  if (value == 0) {
    return;
  }
  func_0209a884(value + 0x38e8,value + 4);
}

int func_0202e788();
int func_021124f0();
/* decompiler-derived */
u32 Unk1124f0_Unk_112564(u32 arg0,u32 arg1)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = func_0202e788();
  value1 = func_021124f0(*(u16 *)(value1 + 0x35c),arg0,arg1);
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}

int func_02115bf4();
int func_02116f84();
/* decompiler-derived */
int Unk1124f0_Unk_1125ac(u32 arg0,u32 arg1,u32 arg2)
{
  int value1;
  int value2;
  value1 = func_02115bf4();
  value2 = func_02116f84(arg0,arg1,arg2);
  return value1 != 0 && value2 != 0;
}
