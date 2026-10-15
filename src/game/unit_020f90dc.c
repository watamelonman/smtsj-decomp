/* src/game/unit_020f90dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0f90dcWork {
    u8 pad_0000[0x50];
    u32 unk_0050;
    u8 pad_0054[0x98];
    u32 unk_00ec;
    u8 pad_00f0[0x4];
    u32 unk_00f4;
    u32 unk_00f8;
} Unk0f90dcWork;




#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_020cb1a0();
int Unk02e000_Thunk_0202e788();
int Unk02e000_GetAreaRecord();
int func_020f90dc(int a, u32 b)
{
    u8 *e;
    int v;
    int r = 0;
    e = (u8 *)func_020cb1a0(b);
    if (a < 0) {
        v = FIELD(s16, Unk02e000_Thunk_0202e788(), 30);
    } else {
        v = FIELD(s16, Unk02e000_GetAreaRecord(a), 32);
    }
    if (v >= e[34]) {
        r = 1;
    }
    return r;
}

/* empty callback */
void Unk0f90dc_Nop_0f9ce4(void) { }


/* decompiler-derived */
int Unk0f90dc_Unk_0f9128(int *arg0,int *arg1)
{
  return (u32)*(u8 *)(*arg0 + 1) - (u32)*(u8 *)(*arg1 + 1);
}

int func_02053000();
int func_020f91fc();
/* decompiler-derived */
void Unk0f90dc_Unk_0fa4cc(Unk0f90dcWork *arg0){
  func_020f91fc();
  Unk0d297c_Unk_0d2e88();
  func_02053000(arg0->unk_0050);
  arg0->unk_0050 = 0;
  func_02053000(arg0->unk_00f8);
  arg0->unk_00f8 = 0;
  func_02053000(arg0->unk_00ec);
  arg0->unk_00ec = 0;
  func_02053000(arg0->unk_00f4);
  arg0->unk_00f4 = 0;
  return;
}
