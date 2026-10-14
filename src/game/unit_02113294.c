/* src/game/unit_02113294.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020a0da4();
/* decompiler-derived */
void Unk113294_Unk_1156c4(u8 *arg0)
{
  func_020a0da4(0xb);
  *(u32 *)(arg0 + 0xd0) = 0xffffffff;
  *(u32 *)(arg0 + 0x1c) = 3;
  *arg0 = 3;
}


/* decompiler-derived */
void Unk113294_Unk_115698(u8 *arg0)
{
  func_020a0da4(0xb);
  *(u32 *)(arg0 + 0xd0) = 0xffffffff;
  *(u32 *)(arg0 + 0x1c) = 2;
  *arg0 = 3;
}



/* get u32 at +0x20 */
u32 func_02115650(void *obj) { return FIELD(u32, obj, 0x20); }

int func_021150e8();
/* decompiler-derived */
void func_02115110(void)
{
  func_021150e8(1,0x35);
  return;
}

int func_020655b4();
int func_02065604();
int func_02065bc0();
/* decompiler-derived */
void func_021156ec(void)
{
  func_02065bc0();
  func_02065604(1);
  func_020655b4(1);
  return;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void func_021150c8(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_020445f4(0x2a,arg0);
  func_0204fed8(tmp1,arg1);
  return;
}


/* decompiler-derived */
void func_02115124(int arg0)
{
  func_021150e8(*(u8 *)(arg0 + 8) + 1,*(u32 *)(arg0 + 0x10) & 0xffff);
  return;
}
