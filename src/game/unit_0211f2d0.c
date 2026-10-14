/* src/game/unit_0211f2d0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk11f2d0_Unk_11f320(int *arg0)
{
  if (*arg0 != 0) {
    arg0[4] = 3;
  }
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f308(int *arg0,int arg1)
{
  if (*arg0 != 0) {
    arg0[5] = arg1;
    arg0[4] = 1;
  }
}


/* decompiler-derived */
void Unk11f2d0_Unk_11f664(u32 *arg0)
{
  *arg0 = 0;
  arg0[1] = 0xb;
  arg0[2] = 0;
  *(u16 *)(arg0 + 3) = 0;
}

extern u32 data_02176e78[];
int func_02061424();
/* decompiler-derived */
void Unk11f2d0_Unk_11f37c(void)
{
  if (*data_02176e78 == 0) {
    return;
  }
  func_02061424();
}

int func_0211f3c8();
/* decompiler-derived */
void Unk11f2d0_Unk_11f354(void)
{
  int value;
  if (*data_02176e78 != 0) {
    return;
  }
  value = func_0211f3c8();
  *data_02176e78 = value;
}

int func_02008848();
int func_0205ddb4();
int func_020629c4();
/* decompiler-derived */
void Unk11f2d0_Unk_11f2d0(int *arg0)
{
  if (*arg0 == 0) {
    return;
  }
  func_0205ddb4(arg0[1]);
  func_020629c4(arg0[2]);
  func_02008848(arg0,0,0x28);
}
