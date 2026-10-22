/* src/game/unit_020c855c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0c855cWork {
    u8 pad_0000[0x1c];
    u32 unk_001c;
    u8 pad_0020[0x10];
    s32 unk_0030;
    u8 pad_0034[0x6];
    u16 unk_003a;
    u8 pad_003c[0x16c];
    u32 unk_01a8;
    u32 unk_01ac;
    u32 unk_01b0;
    u32 unk_01b4;
} Unk0c855cWork;

int Unk0c855c_Unk_0ca690(int arg0)
{
  return arg0 + 0x6180;
}


/* decompiler-derived */
void Unk0c855c_Unk_0ca58c(u32 *arg0)
{
  *arg0 = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  arg0[7] = 0;
}

int func_020c98ec();
/* decompiler-derived */
void Unk0c855c_Unk_0c9b90(int arg0,int arg1,u32 arg2)
{
  func_020c98ec(arg1 * 0x60 + arg0,arg2,0);
}


/* decompiler-derived */
void Unk0c855c_Unk_0c9d8c(int arg0)
{
  int value;
  value = 0;
  do {
    value = value + 1;
    if (((Unk0c855cWork *)arg0)->unk_0030 != 0) {
      ((Unk0c855cWork *)arg0)->unk_001c = 1;
    }
    arg0 = arg0 + 0x60;
  } while (value < 4);
}


/* decompiler-derived */
u32 Unk0c855c_Unk_0c9bac(int arg0)
{
  int value;
  value = 0;
  do {
    if (((Unk0c855cWork *)arg0)->unk_0030 == 0) {
      return 0;
    }
    value = value + 1;
    arg0 = arg0 + 0x60;
  } while (value < 4);
  return 1;
}


int Unk02e000_Unk_02e0cc();
int func_02057fd8();
int func_020c92f0();
/* decompiler-derived */
void Unk0c855c_Unk_0c9890(u32 arg0,u32 arg1)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  Unk02e000_Unk_02e0cc();
  tmp1 = func_02057fd8();
  tmp2 = func_02057fd8();
  tmp3 = func_02057fd8();
  tmp4 = 0;
  do {
    func_020c92f0(arg0,arg1,tmp4,tmp1,tmp2,tmp3);
    tmp4 = tmp4 + 1;
  } while (tmp4 < 4);
  return;
}


/* decompiler-derived */
void Unk0c855c_Unk_0c9c5c(int arg0,int arg1)
{
  int tmp1;
  int tmp2;
  tmp1 = 0;
  tmp2 = arg0;
  do {
    if (*(int *)(tmp2 + 4) == 3) {
      Unk0c855c_Unk_0c9b90(arg0,tmp1,2);
    }
    tmp1 = tmp1 + 1;
    tmp2 = tmp2 + 0x60;
  } while (tmp1 < 4);
  if (arg1 < 0) {
    return;
  }
  Unk0c855c_Unk_0c9b90(arg0,arg1,3);
  return;
}

int func_020537b8();
/* decompiler-derived */
void Unk0c855c_Unk_0c855c(int arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01a8 = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01ac = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01b0 = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    ((Unk0c855cWork *)arg0)->unk_01b4 = 1;
  }
  return;
}

extern u8 data_0213c54c[];
int Unk0ca69c_Unk_0ca6a4();
/* decompiler-derived */
void Unk0c855c_Unk_0c92c0(int arg0)
{
  Unk0ca69c_Unk_0ca6a4(*(u8 *)(data_0213c54c + (u32)((Unk0c855cWork *)arg0)->unk_003a));
}

extern u8 data_0213c51c[];
/* decompiler-derived */
u32 Unk0c855c_Unk_0c92dc(int arg0)
{
  return *(u32 *)(data_0213c51c + (u32)((Unk0c855cWork *)arg0)->unk_003a * 4);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u32 CampStatus_Unk_0d353c();
void func_020616c0();
void func_020ca2e4();
void func_020c9ee0();
void func_0205bb68();
void Unk0c855c_InitCallbacks(u32 *p)
{
    p[0] = 32;
    p[1] = 0;
    p[3] = 0;
    p[4] = (u32)func_020ca2e4;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = (u32)func_020c9ee0;
}

void Unk0c855c_Unk_0ca648(int k)
{
    int j;
    switch (k) {
    case 0:
        func_0205bb68();
        break;
    case 1:
        func_0205bb68();
        break;
    case 2:
        for (j = 0; j < 12; j++) {
            func_0205bb68();
        }
        break;
    }
}
