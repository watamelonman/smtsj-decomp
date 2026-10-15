/* src/game/unit_0203cc58.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int func_0209993c();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int Unk096754_Unk_097110();
int Unk0979d8_Unk_0981a4();

int func_0203cc58(void)
{
    int k = func_0203ac00(0);
    int r = 0;
    if (k == 0) {
        r = Unk096754_Unk_097110();
    } else if (k >= 1 && k <= 3) {
        r = Unk0979d8_Unk_0981a4((u8)(k - 1));
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

/* decompiler-derived */
u32 Unk03cc58_Unk_03cd34(void)
{
  func_0203ac00(0);
  func_0209993c();
  Unk03aae8_Unk_03acf4();
  return 1;
}

int func_0203cd50();
/* decompiler-derived */
void Unk03cc58_Unk_03ce10(void)
{
  u32 value1;
  u32 value2;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  func_0203cd50(value1,value2,0);
}


/* decompiler-derived */
void Unk03cc58_Unk_03ce3c(void)
{
  u32 value1;
  u32 value2;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  func_0203cd50(value1,value2,1);
}
