/* src/game/unit_020e675c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk0e675c_Unk_0e675c(u8 *arg0,u8 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}


/* decompiler-derived */
int Unk0e675c_Unk_0e676c(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}


/* decompiler-derived */
int Unk0e675c_Unk_0e677c(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}


/* decompiler-derived */
int Unk0e675c_Unk_0e678c(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

int func_020445d0();
int func_0204fde0();
int func_0204fe18();
/* decompiler-derived */
void Unk0e675c_Unk_0e68cc(void)
{
  u32 value;
  value = func_020445d0(0x17,2);
  func_0204fde0();
  func_0204fe18(value);
}


/* decompiler-derived */
int Unk0e675c_Unk_0e684c(u32 arg0)
{
  int value;
  if (5 < arg0) {
    arg0 = 5;
  }
  func_020445d0(0x21,2);
  value = func_0204fde0();
  return value + arg0 * 4;
}

