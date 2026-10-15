/* src/game/unit_020a23f4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_020fd428(void);
/* forwards to `func_020fd428` */
void Unk0a23f4_Thunk_020fd428(void) { func_020fd428(); }

void func_020fd450(void);
/* forwards to `func_020fd450` */
void Unk0a23f4_Thunk_020fd450(void) { func_020fd450(); }

int func_02061424();
/* decompiler-derived */
void Unk0a23f4_Unk_0a2414(void)
{
  int value;
  value = ScanVisor_Get_data_02176b04();
  if (value == 0) {
    return;
  }
  func_02061424();
}

extern u32 data_02176b04[];
/* decompiler-derived */
int Unk0a23f4_IsSet_data_02176b04(void)
{
  return *data_02176b04 != 0;
}

int func_020a2d0c();
/* decompiler-derived */
void Unk0a23f4_Unk_0a23f4(u32 arg0)
{
  int value;
  value = ScanVisor_Get_data_02176b04();
  if (value != 0) {
    return;
  }
  func_020a2d0c(arg0);
}

