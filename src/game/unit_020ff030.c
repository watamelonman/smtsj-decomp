/* src/game/unit_020ff030.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020ff030(void) { }

int func_02057524();
int func_02057ddc();
int func_02057e18();
int func_02057eb8();
/* decompiler-derived */
void func_020ff0ec(int arg0)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057524(4);
  if (*(int *)(arg0 + 0x18) < 0) {
    return;
  }
  func_02057eb8();
  return;
}

int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void func_020ffa60(int *arg0)
{
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  func_020629c4(arg0[1]);
  if (arg0[1] != 0) {
    arg0[1] = 0;
  }
  return;
}

