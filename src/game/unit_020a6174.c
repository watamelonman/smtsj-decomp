/* src/game/unit_020a6174.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_02008848();
int Unk0a6174_FindFree0c(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][12] == 0) {
            return j;
        }
    }
    return -1;
}

int Unk0a6174_FindFree10d(u8 *p)
{
    int j;
    for (j = 0; j < 16; j++) {
        if (((u8 (*)[16])p)[j][269] == 0) {
            return j;
        }
    }
    return -1;
}

typedef struct Unk0a6174Slot {
    u8 pad_00[2];
    u8 weight;
    u8 pad_03;
} Unk0a6174Slot;
int func_02050074();

Unk0a6174Slot *func_020a6548(Unk0a6174Slot *p)
{
    u32 sum = 0;
    u8 acc;
    u32 r;
    int i;
    for (i = 0; i < 8; i++) {
        sum += p[i].weight;
    }
    if ((s32)sum <= 0) {
        return 0;
    }
    acc = 0;
    r = (u32)func_02050074(1, 65535) % sum;
    for (i = 0; i < 8; i++) {
        acc += p[i].weight;
        if (r < acc) {
            return &p[i];
        }
    }
    return 0;
}

void Unk0a6174_ClearBuffers(u8 *a, u8 *b)
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



