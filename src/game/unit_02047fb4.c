/* src/game/unit_02047fb4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk09d060_Unk_09d13c();
/* decompiler-derived */
u32 Unk047fb4_Unk_0480b4(void)
{
  int value;
  value = Unk09d060_Unk_09d13c();
  if (value != 0) {
    Unk044904_Unk_045080(value);
    Unk0f81a4_Unk_0f81a4();
    return 2;
  }
  return 0;
}


/* decompiler-derived */
u32 Unk047fb4_Unk_0481a0(u16 *arg0)
{
  int value;
  value = Unk044904_Unk_045080();
  if (*(int *)(value + 0x48) != 0) {
    *(u8 *)(value + 0x54) = 0;
    *(u32 *)(value + 0x48) = 0;
    *arg0 = 2;
  }
  return 1;
}
