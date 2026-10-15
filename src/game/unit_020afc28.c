/* src/game/unit_020afc28.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0afc28Work {
    u8 pad_0000[0x20];
    s32 unk_0020;
} Unk0afc28Work;




/* decompiler-derived */
void Unk0afc28_Unk_0afc28(Unk0afc28Work *arg0, int arg1){
  arg0->unk_0020 = arg0->unk_0020 + arg1;
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

typedef struct Unk0afc28Pos {
    u8 pad_0000[0x4];
    s8 x;                       /* +0x04 */
    u8 pad_0005;
    s8 y;                       /* +0x06 */
} Unk0afc28Pos;

int func_020b0914(Unk0afc28Pos *p)
{
    if (p->x == 0 && p->y == 0) {
        return -1;
    }
    return 0;
}
