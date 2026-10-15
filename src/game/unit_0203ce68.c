/* src/game/unit_0203ce68.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk0979d8_ResetAllEntries();
int Unk096754_Unk_096a14();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
u8 *Unk02e000_Thunk_0202e788();
int Unk09727c_GetAreaS8();
int func_02098258();
u32 Unk03ce68_Unk_03d038(u32 arg0);

int func_0203ce68(void)
{
    int k = func_0203ac00(0);
    u16 *w;
    int r;
    func_0203ac00(1);
    w = (u16 *)Unk02e000_Thunk_0202e788();
    r = 0;
    switch (k) {
    case 0: r = w[0]; break;
    case 1: r = w[1]; break;
    case 2: r = w[2]; break;
    case 3: r = w[3]; break;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

int Unk03ce68_Unk_03cf48(void)
{
    int v = Unk096754_Unk_096a14(func_0203ac00(0));
    int r = 1;
    if (v == -1) {
        r = 0;
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

/* decompiler-derived */
u32 Unk03ce68_Unk_03cfb4(void)
{
  Unk0979d8_ResetAllEntries();
  return 1;
}

int Unk096754_ResetAreaPos();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cfc4(void)
{
  Unk096754_ResetAreaPos();
  return 1;
}

int func_0203ac00();
int Unk03aae8_Unk_03acf4();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cf78(void)
{
  func_0203ac00(0);
  Unk03aae8_Unk_03acf4(1);
  return 1;
}

int Unk02ee5c_GetTierFromField70();
u8 *Unk02e000_Thunk_0202e788();
int Unk03ce68_Unk_03cfd4(void)
{
    func_0203ac00(0);
    Unk03aae8_Unk_03acf4(Unk02e000_Thunk_0202e788()[0x70]);
    return 1;
}

/* decompiler-derived */
u32 Unk03ce68_Unk_03cff4(void)
{
  func_0203ac00(0);
  Unk02ee5c_GetTierFromField70();
  Unk03aae8_Unk_03acf4();
  return 1;
}

int Unk0981dc_Unk_0981dc();
/* decompiler-derived */
u32 Unk03ce68_Unk_03cf94(void)
{
  u8 value;
  value = func_0203ac00(0);
  Unk0981dc_Unk_0981dc(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}

int Unk02ee5c_AddClamped70();
/* decompiler-derived */
u32 Unk03ce68_Unk_03d010(void)
{
  short v1;
  func_0203ac00(0);
  v1 = func_0203ac00(1);
  Unk02ee5c_AddClamped70((int)v1);
  return 1;
}



/* decompiler-derived */
u32 Unk03ce68_Unk_03d038(u32 arg0)
{
  switch(arg0) {
  case 0:
    return 0;
  case 1:
    return 4;
  case 2:
    return 1;
  case 3:
    return 2;
  case 4:
    return 3;
  default:
    return 0;
  }
}

int func_0203d088(void)
{
    int k = func_0203ac00(0);
    u32 y = Unk03ce68_Unk_03d038(func_0203ac00(1));
    int r = 0;
    if (k == 0) {
        r = Unk09727c_GetAreaS8(y);
    } else if (k >= 1 && k <= 3) {
        r = func_02098258((u8)(k - 1), y);
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}
