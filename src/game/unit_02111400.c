/* src/game/unit_02111400.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_02112254(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

extern u8 data_02151560[];
int func_02051610();
/* decompiler-derived */
void func_02111458(int arg0)
{
  u32 tmp1;
  tmp1 = func_02051610(((int)data_02151560));
  *(u32 *)(arg0 + 0x18) = tmp1;
  return;
}

int func_0201fba8();
int func_0208dc78();
int func_0208f020();
int func_0208f038();
int func_0208f044();
/* decompiler-derived */
u32 func_02111508(u32 arg0,u32 arg1,u32 arg2)
{
  func_0208f020();
  func_0208f044(arg0,arg1,arg2);
  func_0208f038();
  func_0201fba8();
  func_0208dc78();
  return 0;
}
