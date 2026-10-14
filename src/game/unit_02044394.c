/* src/game/unit_02044394.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02051610();
int func_02052fe0();
int func_0205f460();
int func_0205f4b0();
/* decompiler-derived */
void func_02044394(u32 *arg0)
{
  int tmp1;
  u32 tmp2;
  if ((arg0[3] != 0) && (tmp1 = func_0205f460(*arg0), tmp1 != 0)) {
    tmp2 = func_02052fe0();
    arg0[1] = tmp2;
    tmp1 = func_0205f4b0(*arg0,arg0[1],tmp1);
    if (tmp1 != 0) {
      return;
    }
  }
  tmp2 = func_02051610(*arg0);
  arg0[1] = tmp2;
  return;
}
