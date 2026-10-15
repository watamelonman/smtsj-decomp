/* src/game/unit_02112714.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


extern u32 data_02176e54[];
/* decompiler-derived */
u32 Unk112714_Get_data_02176e54(void)
{
  return *data_02176e54;
}

int Unk0bc1a8_IsSlotEmpty();
/* decompiler-derived */
int Unk112714_Unk_112714(void)
{
  int value;
  value = Unk0bc1a8_IsSlotEmpty(0x27);
  return value != 0;
}
