/* src/game/unit_0203b988.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int func_0204fb14();
/* decompiler-derived */
u32 Unk03b988_Unk_03b9b8(void)
{
  u16 value;
  value = func_0203ac00(0);
  func_0204fb14(value);
  Unk03aae8_Unk_03acf4();
  return 1;
}

int func_0204faf0();
/* decompiler-derived */
u32 Unk03b988_Unk_03b988(void)
{
  u16 value1;
  u32 value2;
  value1 = func_0203ac00(0);
  value2 = func_0203ac00(1);
  func_0204faf0(value1,value2);
  return 1;
}

int func_02095818();
int Unk0de678_Unk_0df348();
void Unk02dcfc_SetCode25();
int Unk116598_Unk_116738();
void Unk0e651c_Unk_0e66f0();
int Unk03b988_Unk_03bab4(void)
{
    int x = func_0203ac00(0);
    switch (func_02095818()) {
    case 2:
        Unk02dcfc_SetCode25(Unk0de678_Unk_0df348(x));
        break;
    case 3:
        Unk02dcfc_SetCode25(Unk116598_Unk_116738(x));
        break;
    }
    return 3;
}

int Unk03b988_Call_0e66f0(void)
{
    int a = func_0203ac00(0);
    Unk0e651c_Unk_0e66f0(func_0203ac00(1), (u8)(a - 1));
    return 1;
}
