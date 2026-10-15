/* src/game/unit_020afc28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
void Unk0afc28_Unk_0afc28(int arg0,int arg1)
{
  *(int *)(arg0 + 0x20) = *(int *)(arg0 + 0x20) + arg1;
  return;
}

int func_020492ec();
int func_0204a67c();
/* decompiler-derived */
void Unk0afc28_Unk_0afdd0(u32 arg0,u32 arg1,int arg2)
{
  int tmp1;
  tmp1 = func_0204a67c();
  if (arg2 != 0) {
    tmp1 = -tmp1;
  }
  func_020492ec(arg1,tmp1);
  return;
}



/* decompiler-derived */
u32 Unk0afc28_Unk_0afcd4(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 8;
  case 1:
    return 9;
  case 2:
    return 10;
  case 3:
    return 0xb;
  case 4:
    return 0xc;
  case 5:
    return 0xd;
  case 6:
    return 0xe;
  case 7:
    return 0xf;
  default:
    return 0x1a;
  }
}


