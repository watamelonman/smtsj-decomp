/* src/game/unit_020b6570.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176b88[];
/* decompiler-derived */
u32 Unk0b6570_Get_data_02176b88(void)
{
  return *data_02176b88;
}

int func_020df7c4();
/* decompiler-derived */
void Unk0b6570_Unk_0b65d0(int arg0)
{
  int tmp1;
  *(u32 *)(arg0 + 8) = 1;
  *(u32 *)(arg0 + 0xc) = 2;
  tmp1 = func_020df7c4();
  if (tmp1 == 0) {
    return;
  }
  *(u32 *)(arg0 + 8) = 2;
  *(u32 *)(arg0 + 0xc) = 3;
  return;
}

int func_02058548();
int func_020588ec();
int func_02058a1c();
/* decompiler-derived */
void Unk0b6570_Unk_0b7838(int arg0)
{
  int tmp1;
  func_02058548();
  tmp1 = 0;
  do {
    func_02058a1c(arg0 + 0x208c,tmp1);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 0x80);
  func_020588ec(arg0 + 0x208c,0);
  func_020588ec(arg0 + 0x208c,1);
  func_020588ec(arg0 + 0x208c,2);
  return;
}
