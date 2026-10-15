/* src/game/unit_020f0eac.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* decompiler-derived */
int Unk0f0eac_Unk_0f1000(u16 *arg0,u16 *arg1)
{
  int value;
  value = (u32)arg0[1] - (u32)arg1[1];
  if (value == 0) {
    value = (u32)*arg0 - (u32)*arg1;
  }
  return value;
}

extern u32 data_02176dfc[];
int func_020f7d7c();
int func_020f7e48();
/* decompiler-derived */
void Unk0f0eac_Unk_0f0f2c(void)
{
  int value;
  value = *data_02176dfc;
  func_020f7e48(*(u32 *)(value + 0x40),0,7);
  func_020f7d7c(*(u32 *)(value + 0x40),0x22);
}

int func_02044ec4();
int Unk0e8228_IsField4One();
int func_020e86a0();
int Unk0e8228_Unk_0e8c80();
int func_020f8478();
/* decompiler-derived */
void Unk0f0eac_Unk_0f0eac(void)
{
  int value1;
  int value2;
  value2 = *data_02176dfc;
  Unk0e8228_Unk_0e8c80();
  func_02044ec4();
  value1 = Unk0e8228_Unk_0e82ac();
  if (value1 == 0) {
    func_020f8478(value2 + 0x50,0);
  }
  value1 = Unk0e8228_IsField4One();
  if (value1 != 0) {
    Unk0e8228_Unk_0e8d18(1);
    func_020e86a0();
  }
  func_020f7e48(*(u32 *)(value2 + 0x40),0,2);
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
extern u32 data_02176dfc[];
int Unk0f8448_GetUnkField10();
void Unk0e8228_Unk_0e8d90();
void func_020f0f08(u32 a)
{
    u32 w = *data_02176dfc;
    Unk0e8228_Unk_0e8d90(FIELD(u32, w, 76), Unk0f8448_GetUnkField10(a));
}

int func_020f0fe0(u8 *a, u8 *b)
{
    int d = a[4] - b[4];
    if (d == 0) {
        d = FIELD(u16, a, 0) - FIELD(u16, b, 0);
    }
    return d;
}
