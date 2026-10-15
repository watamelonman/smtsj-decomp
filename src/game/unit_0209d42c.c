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
void Unk09d42c_Unk_09e2f4(u32 arg0)
{
  int *v1;
  int value1;
  u32 value2;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  value1 = func_0202e788();
  value2 = func_0203611c(*(u32 *)(value1 + 0x358),arg0);
  *(u32 *)(*v1 + 0x18) = value2;
  *(u32 *)(*v1 + 0x14) = 4;
  v1[0x1cfa] = 1;
}


/* decompiler-derived */
void Unk09d42c_Unk_09e2a4(u32 arg0)
{
  int *v1;
  int value1;
  u32 value2;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  value1 = func_0202e788();
  value2 = func_0203611c(*(u32 *)(value1 + 0x358),arg0);
  *(u32 *)(*v1 + 0x18) = value2;
  *(u32 *)(*v1 + 0x14) = 2;
  *(u32 *)(*v1 + 0xc) = 0;
  v1[0x1cfa] = 0;
}


