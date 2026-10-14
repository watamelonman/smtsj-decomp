/* src/game/unit_020c855c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk0c855c_Unk_0ca690(int arg0)
{
  return arg0 + 0x6180;
}


/* decompiler-derived */
void Unk0c855c_Unk_0ca58c(u32 *arg0)
{
  *arg0 = 0;
  arg0[5] = 0;
  arg0[6] = 0;
  arg0[7] = 0;
}

int func_020c98ec();
/* decompiler-derived */
void Unk0c855c_Unk_0c9b90(int arg0,int arg1,u32 arg2)
{
  func_020c98ec(arg1 * 0x60 + arg0,arg2,0);
}


/* decompiler-derived */
void Unk0c855c_Unk_0c9d8c(int arg0)
{
  int value;
  value = 0;
  do {
    value = value + 1;
    if (*(int *)(arg0 + 0x30) != 0) {
      *(u32 *)(arg0 + 0x1c) = 1;
    }
    arg0 = arg0 + 0x60;
  } while (value < 4);
}


/* decompiler-derived */
u32 Unk0c855c_Unk_0c9bac(int arg0)
{
  int value;
  value = 0;
  do {
    if (*(int *)(arg0 + 0x30) == 0) {
      return 0;
    }
    value = value + 1;
    arg0 = arg0 + 0x60;
  } while (value < 4);
  return 1;
}
