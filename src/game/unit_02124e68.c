/* src/game/unit_02124e68.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk124e68_Nop_124f48(void) { }

int func_02057524();
int func_02057534();
int func_02125024();
/* decompiler-derived */
void Unk124e68_Unk_124fbc(u32 *arg0)
{
  if (arg0[3] == 0) {
    return;
  }
  func_02057524(arg0[5]);
  func_02125024(*arg0,*(u8 *)(arg0 + 2),0x16);
  func_02057534();
}


/* decompiler-derived */
void Unk124e68_Unk_124ff0(u32 *arg0)
{
  if (arg0[4] == 0) {
    return;
  }
  func_02057524(arg0[5]);
  func_02125024(*arg0,*(u8 *)(arg0 + 2),0x16);
  func_02057534();
}
