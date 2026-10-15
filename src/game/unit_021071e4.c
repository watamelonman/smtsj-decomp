/* src/game/unit_021071e4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk1071e4Work {
    u8 pad_0000[0x29];
    u8 unk_0029;
} Unk1071e4Work;



int func_020bc9f4();
int func_020bcacc();
/* decompiler-derived */
void Unk1071e4_Unk_107c34(Unk1071e4Work *arg0){
  func_020bc9f4(0x13,0);
  func_020bcacc(0x12,0);
  arg0->unk_0029 = 4;
  return;
}

int func_02108aec();
/* decompiler-derived */
int Unk1071e4_Unk_1087f4(u32 arg0,int arg1,int arg2,int arg3,short arg4)
{
  int tmp1;
  tmp1 = func_02108aec();
  if (tmp1 != 0) {
    return (arg3 - arg1) + (arg4 - arg2) * 3;
  }
  return 0;
}



