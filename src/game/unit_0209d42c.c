/* src/game/unit_0209d42c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk09d42c_Unk_09d600(int arg0)
{
  if (arg0 == 0xff) {
    arg0 = 0;
  }
  return arg0;
}

extern u8 data_02176278[];
/* decompiler-derived */
int Unk09d42c_Unk_09d4e0(void)
{
  return *(int *)(((int)data_02176278) + 0x800) == *(int *)(((int)data_02176278) + 0x804);
}


int func_0202e788();
int func_0203611c();
/* decompiler-derived */
void func_0209e2f4(u32 arg0)
{
  int *v1;
  int tmp2;
  u32 tmp3;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  tmp2 = func_0202e788();
  tmp3 = func_0203611c(*(u32 *)(tmp2 + 0x358),arg0);
  *(u32 *)(*v1 + 0x18) = tmp3;
  *(u32 *)(*v1 + 0x14) = 4;
  v1[0x1cfa] = 1;
  return;
}


/* decompiler-derived */
void func_0209e2a4(u32 arg0)
{
  int *v1;
  int tmp2;
  u32 tmp3;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  tmp2 = func_0202e788();
  tmp3 = func_0203611c(*(u32 *)(tmp2 + 0x358),arg0);
  *(u32 *)(*v1 + 0x18) = tmp3;
  *(u32 *)(*v1 + 0x14) = 2;
  *(u32 *)(*v1 + 0xc) = 0;
  v1[0x1cfa] = 0;
  return;
}


