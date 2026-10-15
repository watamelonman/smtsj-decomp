/* src/game/unit_0203ca38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202df40();
int func_0203ac00();
int func_0203acf4();
int func_020980e8();
int func_020fc6e4();
int func_020fc7b8();
/* decompiler-derived */
u32 Unk03ca38_Unk_03ca38(void)
{
  int value1;
  int value2;
  value1 = func_0203ac00(0);
  func_020980e8();
  func_0203acf4();
  if ((value1 != 0) && (value2 = func_020fc6e4(), value2 != 0)) {
    func_0202df40();
    func_020fc7b8(value1);
    return 3;
  }
  return 1;
}
