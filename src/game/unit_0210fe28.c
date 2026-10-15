/* src/game/unit_0210fe28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk10fe28Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u8 pad_000c[0xc];
    u32 unk_0018;
} Unk10fe28Work;



int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk10fe28_Unk_10fe28(Unk10fe28Work *arg0){
  u32 tmp1;
  tmp1 = func_0204fe68(arg0->unk_0018,1);
  func_0204fed8(tmp1,arg0->unk_0008);
  return;
}

int func_02053000();
int func_0210ff80();
/* decompiler-derived */
void Unk10fe28_Unk_1113e0(Unk10fe28Work *arg0){
  func_0210ff80();
  func_02053000(arg0->unk_0018);
  arg0->unk_0018 = 0;
  return;
}
