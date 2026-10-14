/* src/game/unit_0202cad4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk065e88_Unk_065eac();
/* decompiler-derived */
void Unk02cad4_Unk_02cee0(void)
{
  Unk065e88_Unk_065eac();
}

void func_0206148c(void);
/* forwards to `func_0206148c` */
void Unk02cad4_Thunk_0206148c(void) { func_0206148c(); }

extern u8 data_0213d338[];
/* decompiler-derived */
void Unk02cad4_Unk_02cbdc(u32 arg0)
{
  *(u32 *)(((int)data_0213d338) + 8) = arg0;
}

int func_02065e88();
int func_020e13ac();
/* decompiler-derived */
void Unk02cad4_Unk_02ce80(void)
{
  func_02065e88();
  func_020e13ac(0);
}

int func_0202e75c();
/* decompiler-derived */
void Unk02cad4_Unk_02ce94(void)
{
  int value1;
  int value2;
  u32 value3;
  value1 = Unk0e1648_Unk_0e1648();
  if (value1 == 0) {
    return;
  }
  value3 = 0;
  value1 = 0;
  do {
    value2 = func_0202e75c(value1);
    value1 = value1 + 1;
    if (value3 < *(u32 *)(value2 + 0x38)) {
      value3 = *(u32 *)(value2 + 0x38);
    }
  } while (value1 < 2);
  Unk02e000_Set_data_0215dd24(value3);
  Unk02cad4_Unk_02cbdc(1);
}
