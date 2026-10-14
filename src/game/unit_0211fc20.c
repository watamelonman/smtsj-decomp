/* src/game/unit_0211fc20.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e7c[];
/* decompiler-derived */
void Unk11fc20_Clear_data_02176e7c(void)
{
  *data_02176e7c = 0;
}

int func_02061424();
/* decompiler-derived */
void Unk11fc20_Unk_11fc48(void)
{
  if (*data_02176e7c == 0) {
    return;
  }
  func_02061424();
}

int func_0211fcb0();
/* decompiler-derived */
void Unk11fc20_Unk_11fc20(void)
{
  int value;
  if (*data_02176e7c != 0) {
    return;
  }
  value = func_0211fcb0();
  *data_02176e7c = value;
}


/* decompiler-derived */
int Unk11fc20_Unk_120944(int arg0)
{
  int value1;
  int value2;
  value1 = 0;
  value2 = 0;
  do {
    value2 = value2 + 1;
    if (*(int *)(arg0 + 0x1a8) != 0) {
      value1 = value1 + 1;
    }
    arg0 = arg0 + 0x2c;
  } while (value2 < 0x20);
  return value1;
}
