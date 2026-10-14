/* src/game/unit_0209d060.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void func_0209d060(int *arg0)
{
  *arg0 = *arg0 + 1;
  return;
}

extern u32 data_02176274[];
/* decompiler-derived */
void func_0209d070(void)
{
  *data_02176274 = 0;
  return;
}


/* decompiler-derived */
void func_0209d1b0(void)
{
  if ((u32 *)*data_02176274 != (u32 *)0x0) {
    *(u32 *)*data_02176274 = 0;
  }
  return;
}

int func_02061424();
int func_020d1d4c();
/* decompiler-derived */
void func_0209d10c(void)
{
  if (*data_02176274 != 0) {
    func_02061424();
    *data_02176274 = 0;
  }
  func_020d1d4c();
  return;
}

