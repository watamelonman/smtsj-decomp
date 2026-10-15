/* src/game/unit_020fc584.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e14[];
/* decompiler-derived */
u32 func_020fc8ac(void)
{
  return *data_02176e14;
}

int func_020572d8();
int func_02057eb8();
/* decompiler-derived */
void func_020fcfd0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
  return;
}

int func_02061424();
/* decompiler-derived */
void func_020fc6a0(void)
{
  int tmp1;
  tmp1 = func_020fc8ac();
  if (tmp1 == 0) {
    return;
  }
  func_02061424();
  return;
}


/* decompiler-derived */
u32 func_020fc894(void)
{
  u32 *v1;
  u32 tmp2;
  v1 = (u32 *)func_020fc8ac();
  if (v1 == (u32 *)0x0) {
    tmp2 = 0;
  }
  else {
    tmp2 = *v1;
  }
  return tmp2;
}


/* decompiler-derived */
void func_020fc84c(u32 arg0)
{
  int tmp1;
  tmp1 = func_020fc8ac();
  if (tmp1 != 0) {
    *(u32 *)(tmp1 + 0x2c) = arg0;
    *(u32 *)(tmp1 + 0x30) = 1;
  }
  return;
}

int func_02057524();
int func_02057ddc();
int func_02057e18();
/* decompiler-derived */
void func_020fcfb0(void)
{
  func_02057e18(0x1f);
  func_02057ddc(0xffffffff);
  func_02057524(4);
  return;
}


int func_020fc6e4();
/* decompiler-derived */
void func_020fc824(void)
{
  int tmp1;
  tmp1 = func_020fc6e4();
  if (tmp1 == 0) {
    return;
  }
  tmp1 = func_020fc8ac();
  *(u32 *)(tmp1 + 0x28) = 0;
  *(u32 *)(tmp1 + 0x20) = *(u32 *)(tmp1 + 0x24);
  return;
}

int func_020fc8bc();
/* decompiler-derived */
void func_020fc674(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_020fc8ac();
  if (tmp1 != 0) {
    return;
  }
  tmp2 = func_020fc8bc(arg0);
  *data_02176e14 = tmp2;
  return;
}


int func_0205bb68();
int func_0205ddb4();
/* decompiler-derived */
void func_020fc9fc(int *arg0)
{
  if (*arg0 == 0) {
    if (arg0[2] != 0) {
      func_0205ddb4();
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  else {
    if (arg0[2] != 0) {
      func_0205ddb4();
      arg0[2] = 0;
    }
    func_0205bb68();
  }
  *data_02176e14 = 0;
  return;
}

