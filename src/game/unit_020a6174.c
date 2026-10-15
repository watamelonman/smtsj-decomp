/* src/game/unit_020a6174.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02008848();
int func_020a6174(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][12] == 0) {
            return j;
        }
    }
    return -1;
}

int func_020a61f8(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][269] == 0) {
            return j;
        }
    }
    return -1;
}

void func_020a69d0(u8 *a, u8 *b)
{
    if (a == 0 || b == 0) {
        return;
    }
    func_02008848(a, 0, 0xe14);
    func_02008848(b, 0, 512);
}

/* decompiler-derived */
int Unk0a6174_Unk_0a6aac(int arg0,int arg1)
{
  return arg0 + arg1 * 0x10;
}


/* decompiler-derived */
int Unk0a6174_Unk_0a6ab4(int arg0,int arg1)
{
  return arg0 + 0x100 + arg1 * 0x10;
}

int Unk02f2a8_GridIndex45();
/* decompiler-derived */
int Unk0a6174_Unk_0a6a88(int arg0,u32 arg1,u32 arg2)
{
  int value;
  if (arg0 != 0) {
    value = Unk02f2a8_GridIndex45(arg1,arg2);
    return arg0 + value * 2;
  }
  return 0;
}



