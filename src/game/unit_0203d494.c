/* src/game/unit_0203d494.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0201ea6c();
int func_0203ac00();
int func_0203acf4();
int func_02097f68();
int func_02098050();
/* decompiler-derived */
u32 func_0203d5c8(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_0203ac00(0);
  tmp2 = 0;
  if (tmp1 == 0) {
    tmp2 = func_02098050(2);
  }
  else if (tmp1 == 1) {
    func_02097f68(2);
    tmp2 = func_0201ea6c();
  }
  func_0203acf4(tmp2);
  return 1;
}
