/* src/game/unit_020e675c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int func_020e675c(u8 *arg0,u8 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}


/* decompiler-derived */
int func_020e676c(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}


/* decompiler-derived */
int func_020e677c(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}


/* decompiler-derived */
int func_020e678c(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

int func_020445d0();
int func_0204fde0();
int func_0204fe18();
/* decompiler-derived */
void func_020e68cc(void)
{
  u32 tmp1;
  tmp1 = func_020445d0(0x17,2);
  func_0204fde0();
  func_0204fe18(tmp1);
  return;
}


/* decompiler-derived */
int func_020e684c(u32 arg0)
{
  int tmp1;
  if (5 < arg0) {
    arg0 = 5;
  }
  func_020445d0(0x21,2);
  tmp1 = func_0204fde0();
  return tmp1 + arg0 * 4;
}
