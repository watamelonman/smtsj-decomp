/* src/game/unit_02044394.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02051610();
int func_02052fe0();
int func_0205f460();
int func_0205f4b0();
/* decompiler-derived */
void Unk044394_Unk_044394(u32 *arg0)
{
  int value1;
  u32 value2;
  if ((arg0[3] != 0) && (value1 = func_0205f460(*arg0), value1 != 0)) {
    value2 = func_02052fe0();
    arg0[1] = value2;
    value1 = func_0205f4b0(*arg0,arg0[1],value1);
    if (value1 != 0) {
      return;
    }
  }
  value2 = func_02051610(*arg0);
  arg0[1] = value2;
}
