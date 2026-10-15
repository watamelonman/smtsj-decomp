/* src/game/unit_020466a4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020aa24c();
int func_020f8098();
/* decompiler-derived */
u32 func_020466a4(u16 *arg0)
{
  u32 *v1;
  u32 tmp2;
  int tmp3;
  Unk044904_Unk_044fd8();
  v1 = (u32 *)func_020aa24c();
  if (v1 == (u32 *)0x0) {
    *arg0 = 2;
  }
  else {
    tmp2 = Unk044904_Unk_045080();
    tmp3 = func_020f8098(tmp2,1,*v1);
    if (tmp3 != 0) {
      *arg0 = 3;
    }
  }
  return 2;
}
