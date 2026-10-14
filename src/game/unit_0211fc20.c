/* src/game/unit_0211fc20.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e7c[];
/* decompiler-derived */
void func_0211fd24(void)
{
  *data_02176e7c = 0;
  return;
}

int func_02061424();
/* decompiler-derived */
void func_0211fc48(void)
{
  if (*data_02176e7c == 0) {
    return;
  }
  func_02061424();
  return;
}

int func_0211fcb0();
/* decompiler-derived */
void func_0211fc20(void)
{
  int tmp1;
  if (*data_02176e7c != 0) {
    return;
  }
  tmp1 = func_0211fcb0();
  *data_02176e7c = tmp1;
  return;
}


/* decompiler-derived */
int func_02120944(int arg0)
{
  int tmp1;
  int tmp2;
  tmp1 = 0;
  tmp2 = 0;
  do {
    tmp2 = tmp2 + 1;
    if (*(int *)(arg0 + 0x1a8) != 0) {
      tmp1 = tmp1 + 1;
    }
    arg0 = arg0 + 0x2c;
  } while (tmp2 < 0x20);
  return tmp1;
}
