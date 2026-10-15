/* src/game/unit_020a9a90.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020a9a90(void) { }

int func_0202e0cc();
int func_0205ad8c();
/* decompiler-derived */
u16 func_020a9a94(int arg0,int arg1)
{
  int tmp1;
  func_0202e0cc();
  tmp1 = func_0205ad8c();
  return *(u16 *)
          (arg1 * 0xc + *(int *)(*(int *)(arg0 * 0x18 + tmp1 + 0x14) + 0x54) + 4);
}

