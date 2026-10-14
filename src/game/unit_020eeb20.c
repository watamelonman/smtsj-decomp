/* src/game/unit_020eeb20.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020eecb8(void) { }

extern u32 data_02176de8[];
int func_02008848();
int func_020eec4c();
/* decompiler-derived */
void func_020eec20(u32 arg0)
{
  func_02008848(arg0,0,0x50);
  *data_02176de8 = arg0;
  func_020eec4c(arg0);
  return;
}

extern u32 data_02176de4[];
int func_020f7d7c();
int func_020f7e48();
/* decompiler-derived */
void func_020eeb44(void)
{
  int tmp1;
  tmp1 = *data_02176de4;
  func_020f7e48(*(u32 *)(tmp1 + 0x40),0,7);
  func_020f7d7c(*(u32 *)(tmp1 + 0x40),0x22);
  return;
}

int func_020ea3cc();
/* decompiler-derived */
void func_020eeb74(void)
{
  u32 tmp1;
  tmp1 = Unk0f8448_GetUnkField10();
  switch(tmp1) {
  case 0:
    func_020ea3cc(9);
    return;
  case 1:
    func_020ea3cc(10);
    return;
  case 2:
    func_020ea3cc(0xb);
    return;
  case 3:
    func_020ea3cc(8);
    return;
  default:
    return;
  }
}
