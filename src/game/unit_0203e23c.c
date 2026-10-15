/* src/game/unit_0203e23c.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk03aae8_Unk_03acf4();
int func_0209eff8();
void func_0202eda8();
int Unk096754_Unk_0969f0();
int func_02096a60();
int func_02096af4();
void func_02096958();
void Unk0986ac_Unk_098978();
int Unk0986ac_Thunk_02098714();
int Unk03e23c_Unk_03e260(void)
{
    int a = func_0203ac00(0);
    func_0202eda8((u16)a, func_0203ac00(1));
    return 1;
}

int Unk03e23c_Unk_03e290(void)
{
    if (Unk096754_Unk_0969f0()) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

int Unk03e23c_Unk_03e2bc(void)
{
    if (func_02096a60((u16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

int Unk03e23c_Unk_03e36c(void)
{
    if (func_02096af4((u16)func_0203ac00(0)) >= 0) {
        func_02096958();
    }
    return 1;
}

int Unk03e23c_Unk_03e398(void)
{
    Unk0986ac_Unk_098978(func_0203ac00(0));
    if (Unk0986ac_Thunk_02098714()) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* decompiler-derived */
u32 Unk03e23c_Unk_03e3d0(void)
{
  func_0209eff8();
  Unk03aae8_Unk_03acf4();
  return 1;
}

int Unk02e000_GetRecordUnk1f();
int func_0203ac00();
/* decompiler-derived */
u32 Unk03e23c_Unk_03e23c(void)
{
  u16 value;
  value = func_0203ac00(0);
  Unk02e000_GetRecordUnk1f(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}
