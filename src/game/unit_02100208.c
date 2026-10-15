/* src/game/unit_02100208.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk100208Work {
    u8 pad_0000[0x2];
    s32 unk_0002;
} Unk100208Work;

int Unk100208_Unk_100398(u16 *arg0,u16 *arg1)
{
  int value;
  value = (u32)*(u8 *)((int)arg1 + 3) - (u32)*(u8 *)((int)arg0 + 3);
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}


/* decompiler-derived */
int Unk100208_Unk_1003b8(u16 *arg0,u16 *arg1)
{
  int value;
  value = ((Unk100208Work *)arg1)->unk_0002 - ((Unk100208Work *)arg0)->unk_0002;
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}

int func_020a1428();
/* decompiler-derived */
int Unk100208_Unk_1003d8(u16 *arg0,u16 *arg1)
{
  int value1;
  int value2;
  value1 = func_020a1428(*arg0);
  value2 = func_020a1428(*arg1);
  value1 = (u32)*(u8 *)(value2 + 3) - (u32)*(u8 *)(value1 + 3);
  if (value1 == 0) {
    value1 = (u32)*arg0 - (u32)*arg1;
  }
  return value1;
}

int Unk0a0ce4_Unk_0a0da4();
/* decompiler-derived */
void Unk100208_Unk_100208(u32 arg0)
{
  switch(arg0) {
  case 0:
    Unk0a0ce4_Unk_0a0da4(1);
    return;
  case 1:
    Unk0a0ce4_Unk_0a0da4(4);
    return;
  case 2:
    Unk0a0ce4_Unk_0a0da4(2);
    return;
  case 3:
    Unk0a0ce4_Unk_0a0da4(0);
    return;
  case 4:
    Unk0a0ce4_Unk_0a0da4(0xb);
    return;
  case 5:
    Unk0a0ce4_Unk_0a0da4(9);
    return;
  case 6:
    Unk0a0ce4_Unk_0a0da4(10);
    return;
  case 7:
    Unk0a0ce4_Unk_0a0da4(0x10);
    return;
  default:
    return;
  }
}
