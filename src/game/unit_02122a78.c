/* src/game/unit_02122a78.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0205bb68();
extern u32 data_0213cd70[];
void Unk05b82c_Unk_05b82c();
void Unk122a78_Unk_122a78(void)
{
    u32 i;
    for (i = 0; i < 3; i++) {
        Unk05b82c_Unk_05b82c(data_0213cd70[i]);
    }
}

/* decompiler-derived */
void Unk122a78_Unk_122aa0(void)
{
  u32 value;
  value = 0;
  do {
    func_0205bb68();
    value = value + 1;
  } while (value < 3);
}
