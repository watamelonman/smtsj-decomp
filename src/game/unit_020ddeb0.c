/* src/game/unit_020ddeb0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u8 data_0213c640[];
/* decompiler-derived */
u8 Unk0ddeb0_Unk_0ddfd8(int arg0)
{
  return *(u8 *)(((int)data_0213c640) + arg0);
}

int func_020445d0();
int func_0204fde0();
/* decompiler-derived */
u32 Unk0ddeb0_Unk_0ddfe8(int arg0)
{
  int value;
  if (arg0 < 0) {
    arg0 = 0;
  }
  if (0xe < arg0) {
    arg0 = 0xe;
  }
  func_020445d0(0xf,0);
  value = func_0204fde0();
  return *(u32 *)(value + arg0 * 4);
}

int func_02059f70();
int func_02060dd4();
/* decompiler-derived */
void Unk0ddeb0_Unk_0ddeb0(u32 *arg0,u32 arg1,u32 arg2,u32 arg3,
                  u32 arg4,u32 arg5)
{
  u8 auStack_24 [16];
  u32 uStack_14;
  uStack_14 = arg3;
  func_02060dd4(auStack_24,arg0,0,arg3,arg4);
  func_02059f70(*arg0,0,arg1,arg2,auStack_24,0,arg5);
}

void func_02061f10();
void func_020ddf0c(u32 a)
{
    u16 t[1] = {0};
    func_02061f10(a, -1, 0, 0, t);
}

u32 Unk0ddeb0_GetRes15Word0(void)
{
    return ((u32 *)func_0204fde0(func_020445d0(15, 1)))[0];
}

u32 Unk0ddeb0_GetRes15Word1(void)
{
    return ((u32 *)func_0204fde0(func_020445d0(15, 1)))[1];
}
