/* src/game/unit_020e7ac4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk0e7ac4_Nop_0e7b7c(void) { }

extern u32 data_02176cdc[];
int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void Unk0e7ac4_Unk_0e7f0c(int arg0)
{
  func_0205bb68();
  if (*(int *)(arg0 + 0x54) != 0) {
    func_0205ddb4();
    *(u32 *)(arg0 + 0x54) = 0;
  }
  *data_02176cdc = 0;
  return;
}

