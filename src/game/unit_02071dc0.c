/* src/game/unit_02071dc0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0205bb68();
/* decompiler-derived */
void func_02071e08(void)
{
  u32 tmp1;
  tmp1 = 0;
  do {
    func_0205bb68();
    tmp1 = tmp1 + 1;
  } while (tmp1 < 9);
  return;
}

int func_0205b82c();
int func_02071dc0();
/* decompiler-derived */
void func_02071de4(void)
{
  u32 tmp1;
  func_02071dc0();
  tmp1 = 0;
  do {
    func_0205b82c(tmp1);
    tmp1 = tmp1 + 1;
  } while (tmp1 < 9);
  return;
}

extern u8 data_02171d14[];
int func_02071e24();
/* decompiler-derived */
void func_02072200(void)
{
  int tmp1;
  int tmp2;
  tmp1 = ((int)data_02171d14);
  tmp2 = 0;
  if (0 < *(int *)(((int)data_02171d14) + 0x600)) {
    do {
      func_0205bb68();
      tmp2 = tmp2 + 1;
    } while (tmp2 < *(int *)(tmp1 + 0x600));
  }
  func_02071e24();
  return;
}
