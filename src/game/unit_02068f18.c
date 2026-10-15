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
