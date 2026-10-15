/* src/game/unit_0212449c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02044534();
int func_0205bb68();
int func_0205c368();
int func_0205c3dc();
int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void func_0212449c(int *arg0)
{
  u32 tmp1;
  int tmp2;
  func_020629c4(arg0[6]);
  tmp2 = 0;
  do {
    if (arg0[tmp2 + 2] != 0) {
      func_0205c3dc();
      arg0[tmp2 + 2] = 0;
    }
    tmp2 = tmp2 + 1;
  } while (tmp2 < 4);
  if (arg0[1] != 0) {
    func_0205c368();
    arg0[1] = 0;
  }
  if (*arg0 != 0) {
    func_0205ddb4();
    *arg0 = 0;
  }
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 4);
  if (arg0[9] == 0) {
    return;
  }
  func_02044534(0x1e);
  return;
}
