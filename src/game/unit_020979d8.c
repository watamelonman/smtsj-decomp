/* src/game/unit_020979d8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02096754();
/* decompiler-derived */
u8 func_02098124(void)
{
  u8 tmp1;
  int tmp2;
  tmp2 = func_02096754();
  if (tmp2 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = *(u8 *)(tmp2 + 0x38);
  }
  return tmp1;
}


/* decompiler-derived */
int func_0209813c(void)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = (int)*(short *)(tmp1 + 0x1e);
  }
  return tmp1;
}


/* decompiler-derived */
int func_02098154(void)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = (int)*(short *)(tmp1 + 10);
  }
  return tmp1;
}


/* decompiler-derived */
int func_0209818c(void)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = (int)*(short *)(tmp1 + 0x20);
  }
  return tmp1;
}


/* decompiler-derived */
int func_020981a4(void)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 == 0) {
    tmp1 = 0;
  }
  else {
    tmp1 = (int)*(short *)(tmp1 + 0xc);
  }
  return tmp1;
}

int func_02097b54();
/* decompiler-derived */
void func_0209816c(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 == 0) {
    return;
  }
  func_02097b54(tmp1,arg1);
  return;
}

int func_02097b84();
/* decompiler-derived */
void func_020981bc(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_02096754();
  if (tmp1 == 0) {
    return;
  }
  func_02097b84(tmp1,arg1);
  return;
}


int func_020979d8();
/* decompiler-derived */
u32 func_020979fc(int arg0)
{
  if (arg0 != 0) {
    *(u16 *)(arg0 + 0x34) = 0;
    func_020979d8();
    return 1;
  }
  return 0;
}

int func_020970d4();
/* decompiler-derived */
void func_02097f00(u32 arg0)
{
  func_020970d4();
  func_0209816c(0,arg0);
  func_0209816c(1,arg0);
  func_0209816c(2,arg0);
  return;
}

int func_02097120();
/* decompiler-derived */
void func_02097f34(u32 arg0)
{
  func_02097120();
  func_020981bc(0,arg0);
  func_020981bc(1,arg0);
  func_020981bc(2,arg0);
  return;
}


