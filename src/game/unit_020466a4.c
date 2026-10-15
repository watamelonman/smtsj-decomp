/* src/game/unit_020466a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020aa24c();
int func_020f8098();
/* decompiler-derived */
u32 Unk0466a4_Unk_0466a4(u16 *arg0)
{
  u32 *v1;
  u32 value1;
  int value2;
  Unk044904_Unk_044fd8();
  v1 = (u32 *)func_020aa24c();
  if (v1 == (u32 *)0x0) {
    *arg0 = 2;
  }
  else {
    value1 = Unk044904_Unk_045080();
    value2 = func_020f8098(value1,1,*v1);
    if (value2 != 0) {
      *arg0 = 3;
    }
  }
  return 2;
}
