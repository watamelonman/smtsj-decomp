/* src/game/unit_020bb908.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int func_0204fde0();
int func_0204fe18();
int func_02050074();
int func_020bc0b4();
/* decompiler-derived */
u32 Unk0bb908_Unk_0bb908(void)
{
  int value1;
  u32 value2;
  int value3;
  int value4;
  value1 = func_0203ac00(0);
  if (value1 < 0xf) {
    func_020bc0b4();
    value2 = Unk0bac80_Unk_0badec(0);
    value1 = func_0204fe18();
    value1 = func_02050074(0,value1 + -1);
    value3 = func_0204fde0(value2);
    value4 = Unk0bac80_Unk_0badc0();
    *(int *)(value4 + 0x68) = value1 * 0x24 + value3;
    Unk03aae8_Unk_03acf4(value1);
  }
  else {
    Unk03aae8_Unk_03acf4(0);
  }
  return 1;
}


/* decompiler-derived */
u32 Unk0bb908_Unk_0bb978(void)
{
  int value1;
  u32 value2;
  int value3;
  int value4;
  value1 = func_0203ac00(0);
  if (value1 < 0xf) {
    func_020bc0b4();
    value2 = Unk0bac80_Unk_0badec(1);
    value1 = func_0204fe18();
    value1 = func_02050074(0,value1 + -1);
    value3 = func_0204fde0(value2);
    value4 = Unk0bac80_Unk_0badc0();
    *(int *)(value4 + 0x68) = value1 * 0x24 + value3;
    Unk03aae8_Unk_03acf4(value1);
  }
  else {
    Unk03aae8_Unk_03acf4(0);
  }
  return 1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u32 Unk0bac80_Unk_0bae08(void);
u32 Unk0bb908_Unk_0bb9e8(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p, 4));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 Unk0bb908_Unk_0bba14(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p, 0));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 Unk0bb908_Unk_0bba40(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p, 2));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 Unk0bb908_Unk_0bba6c(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(s16, p + i * 10, 6));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 Unk0bb908_Unk_0bbab4(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 10, 8));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 Unk0bb908_Unk_0bbafc(void)
{
    u8 *p = (u8 *)Unk0bac80_Unk_0bae08();
    int i = func_0203ac00(0);
    if (i >= 3) {
        i = 0;
    }
    if (p != 0) {
        Unk03aae8_Unk_03acf4(FIELD(u16, p + i * 10, 10));
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
