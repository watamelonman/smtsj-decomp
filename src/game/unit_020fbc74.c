/* src/game/unit_020fbc74.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_02061424();
/* decompiler-derived */
u32 Unk0fbc74_Unk_0fbdc4(int *arg0)
{
  if (*arg0 == 4) {
    func_02061424(arg0);
    return 1;
  }
  return 0;
}

int func_02061f10();
/* decompiler-derived */
void Unk0fbc74_Unk_0fbcd4(int *arg0,int arg1)
{
  u32 value;
  if (arg0[10] == arg1) {
    return;
  }
  value = Unk0d297c_Unk_0d2f18(arg1);
  func_02061f10(arg0[0xd],0xffffffff,0,0,value);
  if (*arg0 == 4) {
    arg0[10] = arg1;
    arg0[0xb] = arg1;
    *arg0 = 5;
    return;
  }
  arg0[0xb] = arg1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void Unk0a0ce4_Unk_0a0da4();
int Unk0fbc74_Unk_0fbd30(u8 *p)
{
    if (FIELD(u32, p, 0) != 4) {
        return 0;
    }
    if (FIELD(u16, p, 56) == 0) {
        return 1;
    }
    FIELD(u16, p, 56) = 0;
    FIELD(u32, p, 0) = 7;
    Unk0a0ce4_Unk_0a0da4(2);
    return 0;
}

int func_020fbd74(u8 *p)
{
    u16 old;
    if (FIELD(u32, p, 0) != 4) {
        return 0;
    }
    old = FIELD(u16, p, 56);
    FIELD(u16, p, 56) = old + 10;
    if (FIELD(u16, p, 56) >= FIELD(int, p, 60)) {
        FIELD(u16, p, 56) = 0;
    }
    if (FIELD(u16, p, 56) != old) {
        FIELD(u32, p, 0) = 7;
        return 1;
    }
    return 0;
}
