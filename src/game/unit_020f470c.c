/* src/game/unit_020f470c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void func_020f4874(void) { }

void func_020f7248(void);
/* forwards to `func_020f7248` */
void func_020f494c(void) { func_020f7248(); }

int func_020f7210();
int func_020f82e0();
/* decompiler-derived */
void func_020f4908(int arg0)
{
  int tmp1;
  tmp1 = func_020f7210();
  if (tmp1 == 0) {
    return;
  }
  func_020f82e0(arg0 + 0x54);
  return;
}

extern u32 data_02176e00[];
int func_02008848();
int func_020f4790();
/* decompiler-derived */
void func_020f4764(u32 arg0)
{
  func_02008848(arg0,0,0xf8);
  *data_02176e00 = arg0;
  func_020f4790(arg0);
  return;
}

int func_020d1d94();
int func_020ea630();
int func_020f4b80();
/* decompiler-derived */
void func_020f4c20(u32 arg0)
{
  int tmp1;
  u32 tmp2;
  tmp1 = Unk0e8228_Unk_0e8bac();
  if (tmp1 == 0) {
    return;
  }
  func_020f4b80(arg0);
  tmp2 = func_020ea630(8);
  func_020d1d94(tmp2,0xffffffff);
  return;
}
