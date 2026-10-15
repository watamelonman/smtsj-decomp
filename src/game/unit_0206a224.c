/* src/game/unit_0206a224.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk06a224Work {
    u8 pad_0000[0x440];
    u32 unk_0440;
    u32 unk_0444;
    u32 unk_0448;
    u32 unk_044c;
} Unk06a224Work;



void func_020d6cac(void);
/* forwards to `func_020d6cac` */
void Unk06a224_Thunk_020d6cac(void) { func_020d6cac(); }

/* Globals block at 0x0216b9b0; fields named by their accessors. */
typedef struct Unk06a224Globals {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk06a224Globals;

extern Unk06a224Globals data_0216b9b0;

u32 Unk06a224_Unk_06a224(void)
{
    return data_0216b9b0.unk_08;
}

u32 Unk06a224_GetUnk00(void)
{
    return data_0216b9b0.unk_00;
}

void Unk06a224_Unk_06a244(u32 arg0)
{
    data_0216b9b0.unk_08 = arg0;
}

void Unk06a224_SetUnk00(u32 arg0)
{
    data_0216b9b0.unk_00 = arg0;
}


int func_020537b8();
/* decompiler-derived */
void Unk06a224_Unk_06ae28(Unk06a224Work *arg0){
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    arg0->unk_0440 = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    arg0->unk_0444 = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    arg0->unk_0448 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    arg0->unk_044c = 1;
  }
  return;
}

