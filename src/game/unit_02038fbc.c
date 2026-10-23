/* Resource-backed grid and element-table helpers. */
#include "types.h"


void func_02008848(void *destination, int value, u32 size);
void func_020516d0(void *resource);
/* Release the backing resource and clear all 0x8c bytes; a null owner is allowed. */
void Unk038fbc_Unk_039138(u32 *arg0)
{
  if (arg0 == (u32 *)0x0) {
    return;
  }
  func_020516d0((void *)*arg0);
  func_02008848(arg0,0,0x8c);
}


/* Partial node layout: the getter only observes the word at offset eight. */
typedef struct Unk038fbcNode {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} Unk038fbcNode;

/* Return the word at node offset eight, or zero for a null node (ldr +8). */
u32 Unk038fbc_GetNodeUnk08(Unk038fbcNode *node)
{
    if (node != 0) {
        return node->unk_08;
    }
    return 0;
}

/* Return header width times height (bytes +10/+11), or zero without a resource. */
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


/* Release a loaded resource, clear the first eight owner bytes, and report success. */
u32 Unk038fbc_Unk_038fbc(int *arg0)
{
  if (arg0 == (int *)0x0) {
    return 0;
  }
  if (*arg0 != 0) {
    func_020516d0((void *)*arg0);
    func_02008848(arg0,0,8);
    return 1;
  }
  return 0;
}


u32 Unk038fbc_Unk_039248(u32 arg0);
/* Translate absolute coordinates using header origin +8/+9; reject out-of-grid cells. */
u8 *Unk038fbc_Unk_039160(u8 **o, int x, int y)
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

/* Select a table entry by kind and index; header counts at +12 bound the index. */
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

/* Return the serialized stride for kinds 0..12, or zero for unknown kinds. */
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
