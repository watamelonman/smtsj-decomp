/* src/game/unit_020981dc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk096754_GetAreaRecordIf();
/* decompiler-derived */
u16 Unk0981dc_Unk_0981dc(void)
{
  u16 value1;
  int value2;
  value2 = Unk096754_GetAreaRecordIf();
  if (value2 == 0) {
    value1 = 0;
  }
  else {
    value1 = *(u16 *)(value2 + 0x36);
  }
  return value1;
}

int func_0209786c();
/* decompiler-derived */
void Unk0981dc_Unk_0981f4(u32 arg0,u32 arg1,u8 arg2)
{
  int value;
  value = Unk096754_GetAreaRecordIf();
  if (value != 0) {
    switch(arg1) {
    case 0:
      *(u8 *)(value + 0xe) = arg2;
      break;
    case 1:
      *(u8 *)(value + 0xf) = arg2;
      break;
    case 2:
      *(u8 *)(value + 0x10) = arg2;
      break;
    case 3:
      *(u8 *)(value + 0x11) = arg2;
      break;
    case 4:
      *(u8 *)(value + 0x12) = arg2;
    }
    func_0209786c();
    return;
  }
}

int func_020982c0();
typedef struct Unk0981dcRec {
    u8 pad_00[14];
    s8 unk_0e;
    s8 unk_0f;
    s8 unk_10;
    s8 unk_11;
    s8 unk_12;
} Unk0981dcRec;

s8 func_02098258(int a, int i)
{
    Unk0981dcRec *r = (Unk0981dcRec *)Unk096754_GetAreaRecordIf(a);
    if (r == 0) {
        return 0;
    }
    switch (i) {
    case 0:
        return r->unk_0e;
    case 1:
        return r->unk_0f;
    case 2:
        return r->unk_10;
    case 3:
        return r->unk_11;
    case 4:
        return r->unk_12;
    }
    return 0;
}

int Unk0981dc_Unk_098324(int a, int b)
{
    if (b != 0) {
        s8 *pa = (s8 *)func_020982c0(a);
        if (((s8 *)func_020982c0(b))[1] <= pa[1]) {
            return 0;
        }
    }
    return 1;
}
