/* src/game/unit_020eeb20.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u32 data_02176de4[];
int Unk0f8448_GetUnkField10();
void Unk0e8228_Unk_0e8d90();
void func_020eeb20(u32 a)
{
    u32 w = *data_02176de4;
    Unk0e8228_Unk_0e8d90(FIELD(u32, w, 68), Unk0f8448_GetUnkField10(a));
}

/* empty callback */
void Unk0eeb20_Nop_0eecb8(void) { }

extern u32 data_02176de8[];
int func_02008848();
int func_020eec4c();
/* decompiler-derived */
void Unk0eeb20_Unk_0eec20(u32 arg0)
{
  func_02008848(arg0,0,0x50);
  *data_02176de8 = arg0;
  func_020eec4c(arg0);
}

extern u32 data_02176de4[];
int func_020f7d7c();
int func_020f7e48();
/* decompiler-derived */
void Unk0eeb20_Unk_0eeb44(void)
{
  int value;
  value = *data_02176de4;
  func_020f7e48(*(u32 *)(value + 0x40),0,7);
  func_020f7d7c(*(u32 *)(value + 0x40),0x22);
}

int func_020ea3cc();
/* decompiler-derived */
void Unk0eeb20_Unk_0eeb74(void)
{
  u32 value;
  value = Unk0f8448_GetUnkField10();
  switch(value) {
  case 0:
    func_020ea3cc(9);
    return;
  case 1:
    func_020ea3cc(10);
    return;
  case 2:
    func_020ea3cc(0xb);
    return;
  case 3:
    func_020ea3cc(8);
    return;
  default:
    return;
  }
}
