/* src/game/unit_020bb6e8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
u8 *Unk0bac80_Thunk_02044ec4(u32 id);
void Unk03aae8_Unk_03acf4();
typedef struct Unk0bb6e8Flags {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Unk0bb6e8Flags;
u32 Unk0bb6e8_GetFlag282b1(void)
{
    if (((Unk0bb6e8Flags *)(Unk0bac80_Thunk_02044ec4(func_0203ac00(0)) + 642))->b1) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 Unk0bb6e8_SetFlag282b1(void)
{
    int a = func_0203ac00(0);
    int on = func_0203ac00(1) != 0;
    ((Unk0bb6e8Flags *)(Unk0bac80_Thunk_02044ec4(a) + 642))->b1 = on;
    return 1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetRecordFlag0();
void func_0202ec48();
u32 Unk0bac80_Unk_0badc0(void);
int Unk0e5fb8_Unk_0e6254();
u32 func_020bb770(void)
{
    if (Unk02e000_GetRecordFlag0((u16)func_0203ac00(0)) != 0) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

u32 func_020bb7ac(void)
{
    int on = func_0203ac00(1) != 0;
    func_0202ec48((u16)func_0203ac00(0), on);
    return 1;
}

u32 func_020bb880(void)
{
    u32 v = FIELD(u32, Unk0bac80_Unk_0badc0(), 68);
    Unk03aae8_Unk_03acf4((v << 19) >> 24);
    return 1;
}

/* decompiler-derived */
u32 Unk0bb6e8_Unk_0bb8a0(void)
{
  int value;
  value = func_0203ac00(0);
  if (value < 0xf) {
    Unk0e5fb8_Unk_0e628c();
  }
  return 1;
}

u32 func_020bb8c0(void)
{
    int a = func_0203ac00(0);
    if (a < 15) {
        if (Unk0e5fb8_Unk_0e6254(a) != 0) {
            Unk03aae8_Unk_03acf4(1);
        } else {
            Unk03aae8_Unk_03acf4(0);
        }
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
