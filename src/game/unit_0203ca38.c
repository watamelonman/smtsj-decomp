/* src/game/unit_0203ca38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02dcfc_SetOwnerCode22();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int Unk0979d8_AddField344();
int func_020fc6e4();
int Unk0fc584_Unk_0fc7b8();
/* decompiler-derived */
u32 Unk03ca38_Unk_03ca38(void)
{
  int value1;
  int value2;
  value1 = func_0203ac00(0);
  Unk0979d8_AddField344();
  Unk03aae8_Unk_03acf4();
  if ((value1 != 0) && (value2 = func_020fc6e4(), value2 != 0)) {
    Unk02dcfc_SetOwnerCode22();
    Unk0fc584_Unk_0fc7b8(value1);
    return 3;
  }
  return 1;
}
