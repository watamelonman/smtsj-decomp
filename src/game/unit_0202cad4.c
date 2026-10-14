/* src/game/unit_0202cad4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk065e88_Unk_065eac();
/* decompiler-derived */
void func_0202cee0(void)
{
  Unk065e88_Unk_065eac();
  return;
}

void func_0206148c(void);
/* forwards to `func_0206148c` */
void func_0202d150(void) { func_0206148c(); }

extern u8 data_0213d338[];
/* decompiler-derived */
void func_0202cbdc(u32 arg0)
{
  *(u32 *)(((int)data_0213d338) + 8) = arg0;
  return;
}

int func_02065e88();
int func_020e13ac();
/* decompiler-derived */
void func_0202ce80(void)
{
  func_02065e88();
  func_020e13ac(0);
  return;
}

int func_0202e75c();
/* decompiler-derived */
void func_0202ce94(void)
{
  int tmp1;
  int tmp2;
  u32 tmp3;
  tmp1 = Unk0e1648_Unk_0e1648();
  if (tmp1 == 0) {
    return;
  }
  tmp3 = 0;
  tmp1 = 0;
  do {
    tmp2 = func_0202e75c(tmp1);
    tmp1 = tmp1 + 1;
    if (tmp3 < *(u32 *)(tmp2 + 0x38)) {
      tmp3 = *(u32 *)(tmp2 + 0x38);
    }
  } while (tmp1 < 2);
  Unk02e000_Set_data_0215dd24(tmp3);
  func_0202cbdc(1);
  return;
}
