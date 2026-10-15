/* src/game/unit_0203d494.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0201ea6c();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int func_02097f68();
int func_02098050();
/* decompiler-derived */
u32 Unk03d494_Unk_03d5c8(void)
{
  int value1;
  u32 value2;
  value1 = func_0203ac00(0);
  value2 = 0;
  if (value1 == 0) {
    value2 = func_02098050(2);
  }
  else if (value1 == 1) {
    func_02097f68(2);
    value2 = func_0201ea6c();
  }
  Unk03aae8_Unk_03acf4(value2);
  return 1;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
u8 *Unk02e000_GetWorkArea();
void func_0209e33c();
u32 Unk03aae8_Unk_03ad14();

int Unk03d494_Unk_03d618(void)
{
    s16 a, b, c;
    u8 *o;
    func_0203ac00(0);
    a = func_0203ac00(1);
    b = func_0203ac00(2);
    c = func_0203ac00(3);
    func_0209e33c(FIELD(u16, Unk02e000_GetWorkArea() + 0x300, 92), a, b, c);
    o = FIELD(u8 *, Unk03aae8_Unk_03ad14(), 232);
    FIELD(u32, o, 24) = 15;
    return 3;
}
