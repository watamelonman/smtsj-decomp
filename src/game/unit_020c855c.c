/* src/game/unit_020c855c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
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
    if (*(int *)(arg0 + 0x30) != 0) {
      *(u32 *)(arg0 + 0x1c) = 1;
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
    if (*(int *)(arg0 + 0x30) == 0) {
      return 0;
    }
    value = value + 1;
    arg0 = arg0 + 0x60;
  } while (value < 4);
  return 1;
}


int func_0202e0cc();
int func_02057fd8();
int func_020c92f0();
/* decompiler-derived */
void func_020c9890(u32 arg0,u32 arg1)
{
  u32 tmp1;
  u32 tmp2;
  u32 tmp3;
  int tmp4;
  func_0202e0cc();
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
void func_020c9c5c(int arg0,int arg1)
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
void func_020c855c(int arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x1a8) = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x1ac) = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x1b0) = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x1b4) = 1;
  }
  return;
}
