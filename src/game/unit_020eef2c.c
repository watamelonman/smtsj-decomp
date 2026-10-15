/* src/game/unit_020eef2c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0eef2c_Nop_0eef80(void) { }


/* empty callback */
void Unk0eef2c_Nop_0ef06c(void) { }

int func_02057df8();
int func_02057e18();
/* decompiler-derived */
void Unk0eef2c_Unk_0ef070(int arg0)
{
  if (*(int *)(arg0 + 4) == 1) {
    return;
  }
  func_02057e18(0x1f);
  func_02057df8();
  return;
}


/* decompiler-derived */
void Unk0eef2c_Unk_0eef58(u32 *arg0)
{
  *arg0 = 0x21;
  arg0[1] = 1;
  arg0[2] = 0;
  arg0[3] = 0;
  arg0[4] = 0xffffff0f;
  arg0[5] = 0;
  return;
}
