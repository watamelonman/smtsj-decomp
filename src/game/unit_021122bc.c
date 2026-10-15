/* src/game/unit_021122bc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02e000_GetWorkArea();
int Unk1122bc_Unk_1122bc();
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02f2a8_Unk_035b08();
int Unk0e651c_Unk_0e666c();
int Unk1122bc_Unk_1122bc(int x)
{
    if (x == Unk02f2a8_Unk_035b08(8, 4)) {
        if (Unk0e651c_Unk_0e666c(0x159) == 1) {
            return 1;
        }
    }
    return 0;
}

int Unk1122bc_IsCurrent(int x)
{
    int r = 0;
    if (x == Unk02f2a8_Unk_035b08(8, 4)) {
        r = 1;
    }
    return r;
}

/* decompiler-derived */
u32 Unk1122bc_Unk_1124c8(void)
{
  int value1;
  u32 value2;
  value2 = 0;
  value1 = Unk02e000_GetWorkArea();
  value1 = Unk1122bc_Unk_1122bc(*(u16 *)(value1 + 0x35c));
  if (value1 == 1) {
    value2 = 2;
  }
  return value2;
}

int Unk1122bc_IsCurrent();
/* decompiler-derived */
u32 Unk1122bc_Unk_112460(void)
{
  int value1;
  u32 value2;
  value2 = 1;
  value1 = Unk02e000_GetWorkArea();
  value1 = Unk1122bc_IsCurrent(*(u16 *)(value1 + 0x35c));
  if (value1 == 1) {
    value1 = Unk02e000_GetWorkArea();
    value1 = Unk1122bc_Unk_1122bc(*(u16 *)(value1 + 0x35c));
    if (value1 == 0) {
      value2 = 0;
    }
  }
  return value2;
}

int Unk1122bc_Unk_1124a0(void)
{
    int r = 1;
    if (Unk1122bc_Unk_1122bc(FIELD(u16, Unk02e000_GetWorkArea(), 860)) == 1) {
        r = 0;
    }
    return r;
}
