/* src/game/unit_020ce578.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0ce578Work {
    u8 pad_0000[0x4];
    u32 unk_0004;
    u8 pad_0008[0x4];
    s32 unk_000c;
    u32 unk_0010;
    u8 pad_0014[0xc4];
    u32 unk_00d8;
} Unk0ce578Work;




/* empty callback */
void Unk0ce578_Nop_0ce5e4(void) { }

int func_020d3138();
/* decompiler-derived */
void Unk0ce578_Unk_0cec98(Unk0ce578Work *arg0){
  u32 tmp1;
  tmp1 = func_020d3138();
  Unk122e1c_Unk_122f88(arg0->unk_0010,0,tmp1);
  return;
}

void Unk0ce578_SetState();
int Unk122e1c_Unk_123294();
/* decompiler-derived */
void Unk0ce578_Unk_0cf29c(Unk0ce578Work *arg0, u32 arg1){
  Unk122e1c_Unk_123294(arg0->unk_0010);
  arg0->unk_00d8 = arg1;
  arg0->unk_0004 = 1;
  Unk0ce578_SetState(arg0,3);
  return;
}

extern u8 data_02176bd0[];
int Unk095560_Unk_0956c8();
int Unk0bc1a8_Unk_0bc9b4();
int Unk0de678_Unk_0de870();
int Unk122a78_Unk_122aa0();
int Unk1241ec_Unk_124258();
/* decompiler-derived */
void Unk0ce578_Unk_0ce5e8(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    Unk0bc1a8_Unk_0bc9b4(0x14,0);
    Unk1241ec_Unk_124258();
    Unk122a78_Unk_122aa0();
  }
  Unk0de678_Unk_0de870();
  Unk095560_Unk_0956c8();
  *(u32 *)(((int)data_02176bd0) + 4) = 0;
  return;
}

int Unk0a0ce4_Unk_0a0da4();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

void Unk0ce578_SetState(Unk0ce578Work *p, int k)
{
    if (k == 2) {
        Unk0ce578_Unk_0cec98(p);
    }
    FIELD(int, p, 0) = k;
}

/* decompiler-derived */
void Unk0ce578_Unk_0cf258(Unk0ce578Work *arg0, int arg1){
  int tmp1;
  if ((arg1 == 2) && (tmp1 = func_020d3138(), tmp1 == 0)) {
    return;
  }
  Unk0a0ce4_Unk_0a0da4(5);
  arg0->unk_0004 = 4;
  Unk0ce578_SetState(arg0,9);
  arg0->unk_000c = arg1;
  return;
}


