/* src/game/unit_0211f2d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk11f2d0Work {
    u8 pad_0000[0x10];
    s32 unk_0010;
    u32 unk_0014;
    u32 unk_0018;
    u32 unk_001c;
    u32 unk_0020;
    s32 unk_0024;
    s32 unk_0028;
    s32 unk_002c;
    s32 unk_0030;
} Unk11f2d0Work;

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
  if (((Unk11f2d0Work *)arg0)->unk_0024 != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(((Unk11f2d0Work *)arg0)->unk_0014,((Unk11f2d0Work *)arg0)->unk_001c,1,0);
  *(u32 **)(arg0 + 0x24) = v1;
  func_0205c408(*v1,0);
  func_0205c6e0(**(u32 **)(arg0 + 0x24));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f58c(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_0028 != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(((Unk11f2d0Work *)arg0)->unk_0014,((Unk11f2d0Work *)arg0)->unk_001c,1,0);
  *(u32 **)(arg0 + 0x28) = v1;
  func_0205c408(*v1,1);
  func_0205c6e0(**(u32 **)(arg0 + 0x28));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f5d4(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_002c != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(((Unk11f2d0Work *)arg0)->unk_0014,((Unk11f2d0Work *)arg0)->unk_001c,1,0);
  *(u32 **)(arg0 + 0x2c) = v1;
  func_0205c408(*v1,2);
  func_0205c6e0(**(u32 **)(arg0 + 0x2c));
  return;
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f61c(int arg0)
{
  u32 *v1;
  if (((Unk11f2d0Work *)arg0)->unk_0030 != 0) {
    return;
  }
  v1 = (u32 *)
           func_02065fac(((Unk11f2d0Work *)arg0)->unk_0018,((Unk11f2d0Work *)arg0)->unk_0020,0,0);
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
  if (((Unk11f2d0Work *)arg0)->unk_0024 != 0) {
    func_02061424();
    ((Unk11f2d0Work *)arg0)->unk_0024 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0028 != 0) {
    func_02061424();
    ((Unk11f2d0Work *)arg0)->unk_0028 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_002c != 0) {
    func_02061424();
    ((Unk11f2d0Work *)arg0)->unk_002c = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0030 != 0) {
    func_02061424();
    ((Unk11f2d0Work *)arg0)->unk_0030 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_001c != 0) {
    func_0205c368();
    ((Unk11f2d0Work *)arg0)->unk_001c = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0020 != 0) {
    func_0205c368();
    ((Unk11f2d0Work *)arg0)->unk_0020 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0010 != 0) {
    func_0205ddb4();
    ((Unk11f2d0Work *)arg0)->unk_0010 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0014 != 0) {
    func_0205ddb4();
    ((Unk11f2d0Work *)arg0)->unk_0014 = 0;
  }
  if (((Unk11f2d0Work *)arg0)->unk_0018 != 0) {
    func_0205ddb4();
    ((Unk11f2d0Work *)arg0)->unk_0018 = 0;
  }
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 5);
  *data_02176e78 = 0;
  return;
}
