/* src/game/unit_02047fb4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0209d13c();
/* decompiler-derived */
u32 func_020480b4(void)
{
  int tmp1;
  tmp1 = func_0209d13c();
  if (tmp1 != 0) {
    Unk044904_Unk_045080(tmp1);
    Unk0f81a4_Unk_0f81a4();
    return 2;
  }
  return 0;
}


/* decompiler-derived */
u32 func_020481a0(u16 *arg0)
{
  int tmp1;
  tmp1 = Unk044904_Unk_045080();
  if (*(int *)(tmp1 + 0x48) != 0) {
    *(u8 *)(tmp1 + 0x54) = 0;
    *(u32 *)(tmp1 + 0x48) = 0;
    *arg0 = 2;
  }
  return 1;
}
