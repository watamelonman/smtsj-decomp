/* src/game/unit_0203d930.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02dcfc_SetField64();
int Unk03aae8_Unk_03ad14();
static inline void Unk03d930_SetSubState(u32 v, u8 *sub)
{
    FIELD(u32, sub, 0x18) = v;
}
u8 *Unk095560_GetManager();
void Unk09ee4c_Unk_09ef80();
void Unk09d42c_Unk_09e2a4();
int Unk03d930_Unk_03d930(void)
{
    if (FIELD(u32, Unk095560_GetManager(), 0x3bc) == 0) {
        return 0;
    }
    Unk09ee4c_Unk_09ef80(90);
    Unk03d930_SetSubState(15, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

int Unk03d930_Unk_03d968(void)
{
    Unk09d42c_Unk_09e2a4((s16)func_0203ac00(0));
    Unk03d930_SetSubState(15, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

/* decompiler-derived */
u32 Unk03d930_Unk_03da00(void)
{
  Unk02dcfc_SetField64();
  return 3;
}

int func_0203ac00();
int func_02065544();
int func_020656ac();
int func_02065c10();
int Unk0a0ce4_Unk_0a0da4();
int Unk0caea8_Unk_0caf98();
/* decompiler-derived */
u32 Unk03d930_Unk_03d998(void)
{
  u32 value1;
  int value2;
  int value3;
  value1 = func_0203ac00(0);
  value2 = Unk03aae8_Unk_03ad14();
  value3 = *(int *)(value2 + 0xe8);
  Unk0d297c_Unk_0d2b70(value1);
  Unk10a034_Unk_10af40(value1);
  value2 = func_02065544();
  if (value2 == 0) {
    func_02065c10();
  }
  value1 = Unk0d297c_Unk_0d2f98(1);
  func_020656ac(value1,0xffffffff);
  *(u32 *)(value3 + 0x18) = 0x1e;
  Unk0caea8_Unk_0caf98(1);
  Unk0a0ce4_Unk_0a0da4(0x28);
  return 3;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
void func_020d2b98();
int Unk10a034_Unk_10af40();
int Unk0d297c_Unk_0d2f98();

int Unk03d930_Unk_03da10(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    u8 *o;
    func_020d2b98(a, (u8)b);
    Unk10a034_Unk_10af40(a);
    if (func_02065544() == 0) {
        func_02065c10();
    }
    func_020656ac(Unk0d297c_Unk_0d2f98(24), -1);
    o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 30;
    Unk0caea8_Unk_0caf98(1);
    Unk0a0ce4_Unk_0a0da4(40);
    return 3;
}
