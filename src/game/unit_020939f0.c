/* src/game/unit_020939f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_02057678(void);
/* forwards to `func_02057678` */
void Unk0939f0_Thunk_02057678(void) { func_02057678(); }

extern u32 data_02175d8c[];
/* decompiler-derived */
void Unk0939f0_Set_data_02175d8c(u32 arg0)
{
  *data_02175d8c = arg0;
}


/* decompiler-derived */
u32 Unk0939f0_Get_data_02175d8c(void)
{
  return *data_02175d8c;
}

extern u32 data_02175d90[];
/* decompiler-derived */
void Unk0939f0_Clear_data_02175d90(void)
{
  *data_02175d90 = 0;
}

int func_02070440();
/* decompiler-derived */
void Unk0939f0_Unk_093dbc(int arg0)
{
  func_02070440(arg0 + 0xc,arg0 + 0x60,arg0 + 0x5c,arg0 + 100,arg0 + 0x2c,
                arg0 + 0x3c,arg0 + 0x4c);
}
