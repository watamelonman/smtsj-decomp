/* src/game/unit_0209e72c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_0209e72c(u32 arg0)
{
  int tmp1;
  tmp1 = GetGameState();
  if (tmp1 == 0) {
    return;
  }
  *(u32 *)(tmp1 + 0x73d0) = arg0;
  *(u32 *)(tmp1 + 0x73cc) = 0xc;
  *(u32 *)(tmp1 + 0x73e8) = 7;
  return;
}


/* decompiler-derived */
void func_0209e8f0(void)
{
  int tmp1;
  tmp1 = GetGameState();
  if (tmp1 == 0) {
    return;
  }
  *(u32 *)(tmp1 + 0x73e4) = 0;
  *(u32 *)(tmp1 + 0x73d8) = 1;
  *(u32 *)(tmp1 + 0x73e8) = 0xb;
  return;
}

int func_0202e968();
/* decompiler-derived */
void func_0209e920(u32 arg0)
{
  int *v1;
  v1 = (int *)GetGameState();
  if (v1 == (int *)0x0) {
    return;
  }
  v1[0x1cf3] = 6;
  *(u32 *)(*v1 + 4) = 0;
  *(char *)(v1 + 0x1d20) = (char)arg0;
  func_0202e968(arg0,1);
  v1[0x1cfa] = 0xd;
  return;
}

int func_0203480c();
/* decompiler-derived */
void func_0209e89c(void)
{
  int tmp1;
  tmp1 = GetGameState();
  if (tmp1 == 0) {
    return;
  }
  func_0203480c(tmp1 + 4,0);
  Unk09974c_Unk_09974c(tmp1 + 0x7550);
  Unk11f2d0_Unk_11f2d0(tmp1 + 0x7598);
  *(u32 *)(tmp1 + 0x73e4) = 1;
  *(u32 *)(tmp1 + 0x73d8) = 0;
  *(u32 *)(tmp1 + 0x73e8) = 10;
  return;
}
