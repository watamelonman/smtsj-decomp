/* src/game/unit_020fbc74.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02061424();
/* decompiler-derived */
u32 func_020fbdc4(int *arg0)
{
  if (*arg0 == 4) {
    func_02061424(arg0);
    return 1;
  }
  return 0;
}

int func_02061f10();
/* decompiler-derived */
void func_020fbcd4(int *arg0,int arg1)
{
  u32 tmp1;
  if (arg0[10] == arg1) {
    return;
  }
  tmp1 = Unk0d297c_Unk_0d2f18(arg1);
  func_02061f10(arg0[0xd],0xffffffff,0,0,tmp1);
  if (*arg0 == 4) {
    arg0[10] = arg1;
    arg0[0xb] = arg1;
    *arg0 = 5;
    return;
  }
  arg0[0xb] = arg1;
  return;
}
