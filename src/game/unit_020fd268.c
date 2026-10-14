/* src/game/unit_020fd268.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e1c[];
/* decompiler-derived */
u32 Unk0fd268_Get_data_02176e1c(void)
{
  return *data_02176e1c;
}

int func_02061424();
/* decompiler-derived */
void Unk0fd268_Unk_0fd3ac(void)
{
  int value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value == 0) {
    return;
  }
  func_02061424();
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd47c(void)
{
  int value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    *(u32 *)(value + 0x2c) = 0;
  }
}


/* decompiler-derived */
void Unk0fd268_Unk_0fd494(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0fd268_Get_data_02176e1c();
  if (value != 0) {
    *(u32 *)(value + 0x30) = arg0;
    *(u32 *)(value + 0x34) = arg1;
  }
}

int func_020fd4c4();
/* decompiler-derived */
void Unk0fd268_Unk_0fd380(u32 arg0)
{
  int value1;
  u32 value2;
  value1 = Unk0fd268_Get_data_02176e1c();
  if (value1 != 0) {
    return;
  }
  value2 = func_020fd4c4(arg0);
  *data_02176e1c = value2;
}
