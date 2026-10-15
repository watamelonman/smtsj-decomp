/* src/game/unit_020387bc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020516d0();
/* decompiler-derived */
u32 Unk0387bc_Unk_038820(int arg0)
{
  if (arg0 != 0) {
    func_020516d0(arg0);
    return 1;
  }
  return 0;
}

int func_02008848();
/* decompiler-derived */
u32 Unk0387bc_Unk_038cbc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0xc);
    return 1;
  }
  return 0;
}


/* decompiler-derived */
u32 Unk0387bc_Unk_038d58(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0x14);
    return 1;
  }
  return 0;
}


u32 func_0204fe18();
u8 *Unk0387bc_GetEntry32(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[1]) <= i) {
        return 0;
    }
    return (u8 *)p[2] + i * 32;
}

u8 *Unk0387bc_GetEntry36(u32 *p, u32 i)
{
    if (p == 0) {
        return 0;
    }
    if (func_0204fe18(p[3]) <= i) {
        return 0;
    }
    return (u8 *)p[4] + i * 36;
}

/* decompiler-derived */
u32 Unk0387bc_Unk_038e40(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0xc);
    return 1;
  }
  return 0;
}



/* decompiler-derived */
u32 Unk0387bc_Unk_038edc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,0x14);
    return 1;
  }
  return 0;
}

extern u8 data_02142064[];
int func_020387bc();
int func_0204fe68();
/* decompiler-derived */
u32 Unk0387bc_Unk_038f7c(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = func_020387bc(((int)data_02142064));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fe68(value,0);
    arg0[1] = value;
    return 1;
  }
  return 0;
}

extern u8 data_02142024[];
int func_0204fdac();
int func_0204fde0();
/* decompiler-derived */
u32 Unk0387bc_Unk_038c74(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = func_020387bc(((int)data_02142024));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,0);
    arg0[1] = value;
    value = func_0204fde0();
    arg0[2] = value;
    return 1;
  }
  return 0;
}

extern u8 data_02142048[];
/* decompiler-derived */
u32 Unk0387bc_Unk_038df8(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = func_020387bc(((int)data_02142048));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,0);
    arg0[1] = value;
    value = func_0204fde0();
    arg0[2] = value;
    return 1;
  }
  return 0;
}

extern u32 data_02141f98[];
int func_0205ad2c();
int Unk05b82c_CreateEntry();
/* decompiler-derived */
void Unk0387bc_Unk_03883c(int *arg0,int arg1,int arg2)
{
  func_0205ad2c(*data_02141f98);
  arg0[1] = arg2;
  *arg0 = arg1;
  Unk05b82c_CreateEntry(arg0);
  *(u16 *)(arg1 + 4) = *(u16 *)(arg0[5] + 0x28);
  *(u16 *)(arg1 + 6) = *(u16 *)(arg0[5] + 0x2a);
}

extern u8 data_02142034[];
/* decompiler-derived */
u32 Unk0387bc_Unk_038cf8(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = func_020387bc(((int)data_02142034));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,1);
    arg0[1] = value;
    value = func_0204fde0();
    arg0[2] = value;
    value = func_0204fdac(*arg0,0);
    arg0[3] = value;
    value = func_0204fde0();
    arg0[4] = value;
    return 1;
  }
  return 0;
}

extern u8 data_02142054[];
/* decompiler-derived */
u32 Unk0387bc_Unk_038e7c(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = func_020387bc(((int)data_02142054));
  if (value != 0) {
    *arg0 = value;
    value = func_0204fdac(value,1);
    arg0[1] = value;
    value = func_0204fde0();
    arg0[2] = value;
    value = func_0204fdac(*arg0,0);
    arg0[3] = value;
    value = func_0204fde0();
    arg0[4] = value;
    return 1;
  }
  return 0;
}

