/* src/game/unit_020f4c50.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f4c50Work {
    u8 pad_0000[0x10];
    u32 unk_0010;
} Unk0f4c50Work;




/* empty callback */
void Unk0f4c50_Nop_0f4cf8(void) { }


/* empty callback */
void Unk0f4c50_Nop_0f4d5c(void) { }


/* empty callback */
void Unk0f4c50_Nop_0f4d60(void) { }


/* decompiler-derived */
void Unk0f4c50_Unk_0f4cd4(u32 *arg0)
{
  *arg0 = 0x23;
  arg0[1] = 0;
  arg0[2] = 9;
  arg0[3] = 1;
  return;
}

int Unk0d1c98_Unk_0d1d94();
int func_020d1e94();
int func_020ea630();
/* decompiler-derived */
void Unk0f4c50_Unk_0f51b0(Unk0f4c50Work *arg0, int arg1){
  u32 tmp1;
  if (arg1 != 0) {
    tmp1 = func_020ea630(arg0->unk_0010);
    Unk0d1c98_Unk_0d1d94(tmp1,0xffffffff);
    return;
  }
  func_020d1e94(1);
  return;
}

extern u32 data_02176e04[];
int func_02008848();
/* decompiler-derived */
void Unk0f4c50_Unk_0f4ca8(u32 arg0)
{
  func_02008848(arg0,0,0x14);
  *data_02176e04 = arg0;
  Unk0f4c50_Unk_0f4cd4((u32 *)arg0);
}
