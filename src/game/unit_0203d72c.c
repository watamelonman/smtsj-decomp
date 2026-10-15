/* src/game/unit_0203d72c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int func_0209ea18();
int Unk03aae8_Unk_03ad14();
static inline void Unk03d72c_SetSubState(u32 v, u8 *sub)
{
    FIELD(u32, sub, 0x18) = v;
}
void Unk09d42c_Unk_09e2f4();
void Unk09ee4c_Unk_09efb4();
void func_0209ee80();
void Unk09ee4c_Unk_09ef50();
int Unk03d72c_Unk_03d72c(void)
{
    Unk09d42c_Unk_09e2f4((s16)func_0203ac00(0));
    Unk03d72c_SetSubState(15, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

int Unk03d72c_Unk_03d7dc(void)
{
    int a = func_0203ac00(0);
    int b = func_0203ac00(1);
    Unk09ee4c_Unk_09efb4(a, b, func_0203ac00(2));
    Unk03d72c_SetSubState(15, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

/* decompiler-derived */
u32 Unk03d72c_Unk_03d828(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  func_0209ea18((int)v1,(int)v2);
  return 3;
}

int func_0209ebd0();
/* decompiler-derived */
u32 Unk03d72c_Unk_03d85c(void)
{
  short v1;
  short v2;
  v1 = func_0203ac00(0);
  v2 = func_0203ac00(1);
  func_0209ebd0((int)v1,(int)v2);
  return 3;
}

int func_02095258();
int Unk03d72c_Unk_03d890(void)
{
    func_0209ee80((s16)func_0203ac00(0));
    Unk03d72c_SetSubState(15, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

int Unk03d72c_Unk_03d8c0(void)
{
    Unk09ee4c_Unk_09ef50((s16)func_0203ac00(0));
    Unk03d72c_SetSubState(15, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

/* decompiler-derived */
u32 Unk03d72c_Unk_03d8f0(void)
{
  u8 value1;
  u8 value2;
  u16 value3;
  value1 = func_0203ac00(0);
  value3 = func_0203ac00(1);
  value2 = func_0203ac00(2);
  func_02095258(value1,value3,value2);
  return 3;
}

int Unk02e000_GetWorkArea();
int Unk02f2a8_Unk_035b08();
int func_0209e564();
/* decompiler-derived */
u32 Unk03d72c_Unk_03d75c(void)
{
  int value1;
  int value2;
  u32 value3;
  u32 value4;
  u32 value5;
  u32 value6;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = func_0203ac00(2);
  value4 = func_0203ac00(3);
  value5 = func_0203ac00(4);
  if (value1 < 0 || value2 < 0) {
    value1 = Unk02e000_GetWorkArea();
    value6 = (u32)*(u16 *)(value1 + 0x35c);
  }
  else {
    value6 = Unk02f2a8_Unk_035b08(value1,value2);
  }
  func_0209e564(value6,value3,value4,value5);
  return 3;
}
