/* src/game/unit_0211f2d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk11f2d0_Unk_11f320(int *arg0)
{
  if (*arg0 != 0) {
    arg0[4] = 3;
  }
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f308(int *arg0,int arg1)
{
  if (*arg0 != 0) {
    arg0[5] = arg1;
    arg0[4] = 1;
  }
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f664(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0xb;
  arg0[2] = 0;
  *(u16 *)(arg0 + 3) = 0;
}

extern u32 data_02176e78[];
int func_02061424();
/* decompiler-derived */
void Unk11f2d0_Unk_11f37c(void)
{
  if (*data_02176e78 == 0) {
    return;
  }
  func_02061424();
}

int func_0211f3c8();
/* decompiler-derived */
void Unk11f2d0_Unk_11f354(void)
{
  int value;
  if (*data_02176e78 != 0) {
    return;
  }
  value = func_0211f3c8();
  *data_02176e78 = value;
}

int func_02008848();
int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void Unk11f2d0_Unk_11f2d0(int *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_0205ddb4(arg0[1]);
  func_020629c4(arg0[2]);
  func_02008848(arg0,0,0x28);
}


int func_0205c408();
int func_0205c6e0();
int func_02065fac();
/* decompiler-derived */
void Unk11f2d0_Unk_11f544(int arg0)
{
  u32 *v1;
  if (*(int *)(arg0 + 0x24) != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(*(u32 *)(arg0 + 0x14),*(u32 *)(arg0 + 0x1c),1,0);
  *(u32 **)(arg0 + 0x24) = v1;
  func_0205c408(*v1,0);
  func_0205c6e0(**(u32 **)(arg0 + 0x24));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f58c(int arg0)
{
  u32 *v1;
  if (*(int *)(arg0 + 0x28) != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(*(u32 *)(arg0 + 0x14),*(u32 *)(arg0 + 0x1c),1,0);
  *(u32 **)(arg0 + 0x28) = v1;
  func_0205c408(*v1,1);
  func_0205c6e0(**(u32 **)(arg0 + 0x28));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f5d4(int arg0)
{
  u32 *v1;
  if (*(int *)(arg0 + 0x2c) != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(*(u32 *)(arg0 + 0x14),*(u32 *)(arg0 + 0x1c),1,0);
  *(u32 **)(arg0 + 0x2c) = v1;
  func_0205c408(*v1,2);
  func_0205c6e0(**(u32 **)(arg0 + 0x2c));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f61c(int arg0)
{
  u32 *v1;
  if (*(int *)(arg0 + 0x30) != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(*(u32 *)(arg0 + 0x18),*(u32 *)(arg0 + 0x20),0,0);
  *(u32 **)(arg0 + 0x30) = v1;
  func_0205c408(*v1,0);
  func_0205c6e0(**(u32 **)(arg0 + 0x30));
  return;
}

int func_0205bb68();
int func_0205c368();
/* decompiler-derived */
void Unk11f2d0_Unk_11f43c(int arg0)
{
  u32 tmp1;
  if (*(int *)(arg0 + 0x24) != 0) {
    func_02061424();
    *(u32 *)(arg0 + 0x24) = 0;
  }
  if (*(int *)(arg0 + 0x28) != 0) {
    func_02061424();
    *(u32 *)(arg0 + 0x28) = 0;
  }
  if (*(int *)(arg0 + 0x2c) != 0) {
    func_02061424();
    *(u32 *)(arg0 + 0x2c) = 0;
  }
  if (*(int *)(arg0 + 0x30) != 0) {
    func_02061424();
    *(u32 *)(arg0 + 0x30) = 0;
  }
  if (*(int *)(arg0 + 0x1c) != 0) {
    func_0205c368();
    *(u32 *)(arg0 + 0x1c) = 0;
  }
  if (*(int *)(arg0 + 0x20) != 0) {
    func_0205c368();
    *(u32 *)(arg0 + 0x20) = 0;
  }
  if (*(int *)(arg0 + 0x10) != 0) {
    func_0205ddb4();
    *(u32 *)(arg0 + 0x10) = 0;
  }
  if (*(int *)(arg0 + 0x14) != 0) {
    func_0205ddb4();
    *(u32 *)(arg0 + 0x14) = 0;
  }
  if (*(int *)(arg0 + 0x18) != 0) {
    func_0205ddb4();
    *(u32 *)(arg0 + 0x18) = 0;
  }
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 5);
  *data_02176e78 = 0;
  return;
}
