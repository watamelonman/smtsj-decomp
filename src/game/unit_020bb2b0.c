/* src/game/unit_020bb2b0.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


u8 *func_020a1428(u32 id);
#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
u8 *Unk0bac80_Thunk_02044ec4(u32 id);
u32 Unk0bac80_Unk_0badc0(void);
u32 func_020bb2b0(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bac80_Thunk_02044ec4(FIELD(u32, Unk0bac80_Unk_0badc0(), 64)) + 256, 216));
    return 1;
}

/* forwards to `func_020a1428` */
u8 *Unk0bb2b0_Thunk_020a1428(u32 id) { return func_020a1428(id); }

u8 *func_020a1740(u32 id);
/* forwards to `func_020a1740` */
u8 *Unk0bb2b0_Thunk_020a1740(u32 id) { return func_020a1740(id); }

int Unk02e000_GetRecordUnk1c();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
u32 func_020bb2ec(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u8, Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0)), 2));
    return 1;
}

u32 func_020bb314(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0)), 12));
    return 1;
}

u32 func_020bb33c(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0)), 20));
    return 1;
}

u32 func_020bb364(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0)), 14));
    return 1;
}

u32 func_020bb38c(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0)), 16));
    return 1;
}

u32 func_020bb3b4(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u16, Unk0bb2b0_Thunk_020a1740((u16)func_0203ac00(0)), 18));
    return 1;
}

u32 func_020bb3dc(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u8, Unk0bb2b0_Thunk_020a1428((u16)func_0203ac00(0)), 4));
    return 1;
}

u32 func_020bb404(void)
{
    Unk03aae8_Unk_03acf4(FIELD(u8, Unk0bb2b0_Thunk_020a1428((u16)func_0203ac00(0)), 5));
    return 1;
}

/* decompiler-derived */
u32 Unk0bb2b0_Unk_0bb42c(void)
{
  u16 value;
  value = func_0203ac00(0);
  Unk02e000_GetRecordUnk1c(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}


int func_0202eab8();
/* decompiler-derived */
u32 Unk0bb2b0_Unk_0bb450(void)
{
  u16 value1;
  int value2;
  int value3;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  value3 = Unk02e000_GetRecordUnk1c(value1);
  func_0202eab8(value1,value2 + value3);
  return 1;
}

u32 func_020bb490(void)
{
    u32 v = FIELD(u32, Unk0bb2b0_Thunk_020a1428((u16)func_0203ac00(0)), 36);
    Unk03aae8_Unk_03acf4((v << 4) >> 25);
    return 1;
}
