/* src/game/unit_02038fbc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02008848();
int func_020516d0();
/* decompiler-derived */
void Unk038fbc_Unk_039138(u32 *arg0)
{
  if (arg0 == (u32 *)0x0) {
    return;
  }
  func_020516d0(*arg0);
  func_02008848(arg0,0,0x8c);
}


typedef struct Unk038fbcNode {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk038fbcNode;

u32 Unk038fbc_GetNodeUnk08(Unk038fbcNode *node)
{
    if (node != 0) {
        return node->unk_08;
    }
    return 0;
}

/* decompiler-derived */
int Unk038fbc_Unk_0391d8(int *arg0)
{
  int value;
  if (arg0 == (int *)0x0) {
    return 0;
  }
  value = *arg0;
  if (value != 0) {
    return (int)(short)(u16)*(u8 *)(value + 10) * (int)(short)(u16)*(u8 *)(value + 0xb);
  }
  return 0;
}


/* decompiler-derived */
u32 Unk038fbc_Unk_038fbc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0(*arg0);
    func_02008848(arg0,0,8);
    return 1;
  }
  return 0;
}


u32 Unk038fbc_Unk_039248(u32 arg0);
u8 *func_02039160(u8 **o, int x, int y)
{
    u8 *h;
    int dx, dy;
    if (o == 0) {
        return 0;
    }
    h = o[0];
    if (h != 0) {
        dx = x - h[8];
        dy = y - h[9];
        if (dx >= 0 && dx < h[10] && dy >= 0 && dy < h[11]) {
            return o[2] + (h[10] * dy + dx) * 8;
        }
    }
    return 0;
}

u8 *Unk038fbc_GetElement(u32 *p, u32 i, u32 j)
{
    if (p == 0) {
        return 0;
    }
    if (((u8 *)p[0] + i)[12] <= j) {
        return 0;
    }
    {
        u8 *base = (u8 *)(p + i)[3];
        return base + j * Unk038fbc_Unk_039248(i);
    }
}

/* decompiler-derived */
u32 Unk038fbc_Unk_039248(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0x20;
  case 1:
    return 4;
  case 2:
    return 8;
  case 3:
    return 4;
  case 4:
    return 4;
  case 5:
    return 8;
  case 6:
    return 4;
  case 7:
    return 4;
  case 8:
    return 8;
  case 9:
    return 8;
  case 10:
    return 8;
  case 0xb:
    return 4;
  case 0xc:
    return 4;
  default:
    return 0;
  }
}
