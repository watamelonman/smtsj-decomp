/* src/game/unit_020caea8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0202b730();
/* decompiler-derived */
void func_020caf78(void)
{
  func_0202b730(0x400);
  return;
}


/* decompiler-derived */
void func_020caf88(void)
{
  func_0202b730(0);
  return;
}

int func_020445f4();
int func_0204fed8();
/* decompiler-derived */
void func_020cb044(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_020445f4(10,0);
  func_0204fed8(tmp1,arg0);
  return;
}


/* decompiler-derived */
void func_020cb064(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_020445f4(10,1);
  func_0204fed8(tmp1,arg0);
  return;
}

int func_020a0d30();
/* decompiler-derived */
void func_020caf98(u32 arg0)
{
  func_0202b730(0x400);
  func_020a0d30(arg0);
  func_0202b730(0);
  return;
}

extern u32 data_02176bc0[];
int func_02053000();
/* decompiler-derived */
u32 func_020caf48(void)
{
  if (*data_02176bc0 != 0) {
    func_02053000();
    *data_02176bc0 = 0;
  }
  return 1;
}
