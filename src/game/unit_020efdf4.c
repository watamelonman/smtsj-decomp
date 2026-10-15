/* src/game/unit_020efdf4.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_020f8264();
int func_020f8478();
/* decompiler-derived */
void Unk0efdf4_Unk_0eff1c(u32 arg0)
{
  func_020f8478(arg0,0);
  func_020f8264(arg0);
}

extern u32 data_02176df4[];
int func_020f7d7c();
int func_020f7e48();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u32 data_02176df4[];
int Unk0f8448_GetUnkField10();
void Unk0e8228_Unk_0e8d90();
void func_020eff38(u32 a)
{
    u32 w = *data_02176df4;
    Unk0e8228_Unk_0e8d90(FIELD(u32, w, 76), Unk0f8448_GetUnkField10(a));
}

/* decompiler-derived */
void Unk0efdf4_Unk_0eff5c(void)
{
  int value;
  value = *data_02176df4;
  func_020f7e48(*(u32 *)(value + 0x40),0,7);
  func_020f7d7c(*(u32 *)(value + 0x40),0x22);
}
