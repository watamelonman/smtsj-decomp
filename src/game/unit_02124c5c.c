/* src/game/unit_02124c5c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_02124e9c(void);
/* forwards to `func_02124e9c` */
void Unk124c5c_Thunk_02124e9c(void) { func_02124e9c(); }

int func_02124c5c();
int func_02124ce8();
/* decompiler-derived */
void Unk124c5c_Unk_124cb0(void)
{
  func_02124c5c();
  func_02124ce8(2);
}

extern u32 data_02176e88[];
int func_02061424();
/* decompiler-derived */
void Unk124c5c_Unk_124d54(void)
{
  func_02061424(*data_02176e88);
}

/* decompiler-derived */
void Unk124c5c_Unk_124e50(u32 arg0)
{
  if (*data_02176e88 != 0) {
    *(u32 *)(*data_02176e88 + 0x14) = arg0;
  }
}
