/* src/game/unit_02068f18.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



int Unk068f18_CompareKeyAsc(u8 *a, u8 *b)
{
    int d = b[2] - a[2];
    if (d == 0) {
        d = a[3] - b[3];
    }
    if (d == 0) {
        d = *(u16 *)a - *(u16 *)b;
    }
    return d;
}

int Unk068f18_CompareKeyDesc(u8 *a, u8 *b)
{
    int d = a[2] - b[2];
    if (d == 0) {
        d = b[3] - a[3];
    }
    if (d == 0) {
        d = *(u16 *)b - *(u16 *)a;
    }
    return d;
}

/* decompiler-derived */
int Unk068f18_Unk_069afc(int arg0,int arg1,int arg2,int arg3)
{
  int value;
  value = (arg0 + arg2) * 0x1000000 >> 0x18;
  if (arg1 + arg3 < value) {
    value = (arg1 + arg3) * 0x1000000 >> 0x18;
  }
  if (99 < value) {
    value = 99;
  }
  return value;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetWorkArea();

int Unk068f18_Unk_06a1a8(u8 *p, int key)
{
    int r;
    u8 *w;
    s8 i;
    if (p[178] == 0) {
        return -1;
    }
    r = -1;
    w = (u8 *)Unk02e000_GetWorkArea();
    for (i = 0; i < p[178]; i++) {
        s8 k = FIELD(s8, w + i + 0x300, 72);
        if (k >= 0 && key == FIELD(u16, FIELD(u8 *, p + k * 4, 288), 54)) {
            r = k;
            break;
        }
    }
    return r;
}
