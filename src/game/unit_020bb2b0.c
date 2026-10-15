/* src/game/unit_020bb2b0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_020a1428(void);
/* forwards to `func_020a1428` */
void Unk0bb2b0_Thunk_020a1428(void) { func_020a1428(); }

void func_020a1740(void);
/* forwards to `func_020a1740` */
void Unk0bb2b0_Thunk_020a1740(void) { func_020a1740(); }

int Unk02e000_GetRecordUnk1c();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
/* decompiler-derived */
u32 Unk0bb2b0_Unk_0bb42c(void)
{
  u16 value;
  value = func_0203ac00(0);
  Unk02e000_GetRecordUnk1c(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}


int func_0202eab8();
/* decompiler-derived */
u32 Unk0bb2b0_Unk_0bb450(void)
{
  u16 value1;
  int value2;
  int value3;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = Unk02e000_GetRecordUnk1c(value1);
  func_0202eab8(value1,value2 + value3);
  return 1;
}
