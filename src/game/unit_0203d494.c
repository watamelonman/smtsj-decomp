/* src/game/unit_0203d494.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0201ea6c();
int func_0203ac00();
int func_0203acf4();
int func_02097f68();
int func_02098050();
/* decompiler-derived */
u32 Unk03d494_Unk_03d5c8(void)
{
  int value1;
  u32 value2;
  value1 = func_0203ac00(0);
  value2 = 0;
  if (value1 == 0) {
    value2 = func_02098050(2);
  }
  else if (value1 == 1) {
    func_02097f68(2);
    value2 = func_0201ea6c();
  }
  func_0203acf4(value2);
  return 1;
}
