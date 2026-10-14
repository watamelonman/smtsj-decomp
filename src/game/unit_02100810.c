/* src/game/unit_02100810.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020662b8();
/* decompiler-derived */
void func_02107154(int arg0,int arg1)
{
  if (arg1 != 0) {
    *(u32 *)(arg0 + 0x20cc) = 1;
    func_020662b8(*(u32 *)(arg0 + 0x1f38));
    func_020662b8(*(u32 *)(arg0 + 0x1f3c),1);
    return;
  }
  *(u32 *)(arg0 + 0x20cc) = 0;
  func_020662b8(*(u32 *)(arg0 + 0x1f38));
  func_020662b8(*(u32 *)(arg0 + 0x1f3c),0);
  return;
}

int func_020445f4();
int func_0204fed8();
int func_02061f10();
int func_02063920();
int func_02063a30();
/* decompiler-derived */
void func_02104f18(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = func_020445f4(0xc);
  func_02063920();
  func_0204fed8(tmp1,arg2);
  func_02063a30();
  func_0204fed8(tmp1,0xcc);
  func_02063a30();
  func_0204fed8(tmp1,0xcd);
  tmp1 = func_02063a30();
  func_02061f10(arg0,0xffffffff,0,0,tmp1);
  return;
}

int func_020537b8();
/* decompiler-derived */
void func_021070d8(int arg0)
{
  int tmp1;
  tmp1 = func_020537b8(0,0x40);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x20bc) = 1;
  }
  tmp1 = func_020537b8(0,0x80);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x20c0) = 1;
  }
  tmp1 = func_020537b8(0,0x20);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x20c4) = 1;
  }
  tmp1 = func_020537b8(0,0x10);
  if (tmp1 != 0) {
    *(u32 *)(arg0 + 0x20c8) = 1;
  }
  return;
}
