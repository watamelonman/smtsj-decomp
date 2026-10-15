/* src/game/unit_0211d520.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
u32 Unk11d520_Unk_11da60(int arg0)
{
  return *(u32 *)(*(int *)(arg0 + 0xa8) + *(int *)(arg0 + 0x18) * 4);
}

int func_0204fe68();
int func_0204fed8();
/* decompiler-derived */
void Unk11d520_Unk_11d520(int arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = func_0204fe68(*(u32 *)(arg0 + 0x26c),arg2);
  func_0204fed8(tmp1,arg1);
  return;
}


/* decompiler-derived */
void Unk11d520_Unk_11d838(int arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = func_0204fe68(*(u32 *)(arg0 + 0x26c),4);
  func_0204fed8(tmp1,arg1);
  return;
}

extern u8 data_02151d18[];
/* decompiler-derived */
int Unk11d520_Unk_11d858(int arg0,u32 arg1)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_0204fe68(*(u32 *)(arg0 + 0x270),0);
  tmp2 = func_0204fed8(tmp1,arg1);
  if (tmp2 == 0) {
    tmp2 = ((int)data_02151d18);
  }
  return tmp2;
}
