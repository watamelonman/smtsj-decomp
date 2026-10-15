/* src/game/unit_0203dbbc.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int Unk03aae8_Unk_03ad14();
static inline void Unk03dbbc_SetSubState(u32 v, u8 *sub)
{
    FIELD(u32, sub, 0x18) = v;
}
void Unk04bb9c_GetCtxUnka20();
void Unk04bb9c_Unk_04c404();
int Unk03dbbc_Unk_03dbbc(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    Unk04bb9c_GetCtxUnka20();
    Unk02e000_GetWorkArea();
    Unk04bb9c_Unk_04c404(a, b);
    Unk03dbbc_SetSubState(17, FIELD(u8 *, Unk03aae8_Unk_03ad14(), 0xe8));
    return 3;
}

/* decompiler-derived */
u32 Unk03dbbc_Unk_03dc48(void)
{
  func_0203ac00(0);
  return 3;
}

int func_0204c4cc();
/* decompiler-derived */
u32 Unk03dbbc_Unk_03dc0c(void)
{
  short v1;
  short v2;
  func_0203ac00(0);
  v1 = func_0203ac00(1);
  v2 = func_0203ac00(2);
  func_0204c4cc((int)v1,(int)v2);
  return 3;
}

int Unk02e000_GetWorkArea();
int func_0204c8f4();
/* decompiler-derived */
u32 Unk03dbbc_Unk_03dccc(void)
{
  u8 value1;
  u8 value2;
  int value3;
  value3 = Unk02e000_GetWorkArea();
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  func_0204c8f4(value1,value2,*(u16 *)(value3 + 0x35c));
  return 3;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_0203ac00();
int Unk02e000_GetWorkArea();
int func_0204c98c();
void func_0204c804();
void func_0204c564();
int Unk02f2a8_Unk_035b08();

int Unk03dbbc_Unk_03dd98(void)
{
    s16 a = func_0203ac00(0);
    s16 b = func_0203ac00(1);
    s16 c = func_0203ac00(2);
    s16 d = func_0203ac00(3);
    func_0204c564(c, d, (s16)Unk02f2a8_Unk_035b08(a, b));
    return 3;
}
