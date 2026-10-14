/* src/game/unit_020939f0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


void func_02057678(void);
/* forwards to `func_02057678` */
void func_020939f0(void) { func_02057678(); }

extern u32 data_02175d8c[];
/* decompiler-derived */
void func_020939fc(u32 arg0)
{
  *data_02175d8c = arg0;
  return;
}


/* decompiler-derived */
u32 func_02093a0c(void)
{
  return *data_02175d8c;
}

extern u32 data_02175d90[];
/* decompiler-derived */
void func_02093b00(void)
{
  *data_02175d90 = 0;
  return;
}

int func_02070440();
/* decompiler-derived */
void func_02093dbc(int arg0)
{
  func_02070440(arg0 + 0xc,arg0 + 0x60,arg0 + 0x5c,arg0 + 100,arg0 + 0x2c,
                arg0 + 0x3c,arg0 + 0x4c);
  return;
}
