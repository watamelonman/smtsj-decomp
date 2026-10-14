/* src/game/unit_0203ca38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202df40();
int func_0203ac00();
int func_0203acf4();
int func_020980e8();
int func_020fc6e4();
int func_020fc7b8();
/* decompiler-derived */
u32 func_0203ca38(void)
{
  int tmp1;
  int tmp2;
  tmp1 = func_0203ac00(0);
  func_020980e8();
  func_0203acf4();
  if ((tmp1 != 0) && (tmp2 = func_020fc6e4(), tmp2 != 0)) {
    func_0202df40();
    func_020fc7b8(tmp1);
    return 3;
  }
  return 1;
}
