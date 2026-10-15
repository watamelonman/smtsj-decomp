/* src/game/unit_0209ee4c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_02118c6c(void);
/* forwards to `func_02118c6c` */
void Unk09ee4c_Thunk_02118c6c(void) { func_02118c6c(); }

extern u8 data_0213c190[];
/* decompiler-derived */
int Unk09ee4c_Unk_0a03b8(int arg0)
{
  return arg0 * 0x18 + ((int)data_0213c190);
}

int func_020a2ae8();
/* decompiler-derived */
void Unk09ee4c_Unk_09ef50(u32 arg0)
{
  int value;
  value = GetGameState();
  if (value == 0) {
    return;
  }
  func_020a2ae8(arg0,2);
  *(u32 *)(value + 0x73e8) = 0x14;
}


/* decompiler-derived */
void Unk09ee4c_Unk_09ee4c(void)
{
  int *v1;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  v1[0x1d00] = 0;
  *(u32 *)(*v1 + 0x5c) = 1;
  v1[0x1cfa] = 0x12;
}

int Unk11f2d0_Unk_11f308();
/* decompiler-derived */
void Unk09ee4c_Unk_09ef80(u32 arg0)
{
  int value;
  value = GetGameState();
  if (value == 0) {
    return;
  }
  Unk11f2d0_Unk_11f308(value + 0x7598,arg0);
  *(u32 *)(value + 0x73e8) = 0x15;
}

