/* src/game/unit_020b6570.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0b6570Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
} Unk0b6570Work;



extern u32 data_02176b88[];
/* decompiler-derived */
u32 Unk0b6570_Get_data_02176b88(void)
{
  return *data_02176b88;
}

int func_020df7c4();
/* decompiler-derived */
void Unk0b6570_Unk_0b65d0(Unk0b6570Work *arg0){
  int tmp1;
  arg0->unk_0008 = 1;
  arg0->unk_000c = 2;
  tmp1 = func_020df7c4();
  if (tmp1 == 0) {
    return;
  }
  arg0->unk_0008 = 2;
  arg0->unk_000c = 3;
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
