/* src/game/unit_0203ca38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"


int Unk02dcfc_SetOwnerCode22();
int func_0203ac00();
int Unk03aae8_Unk_03acf4();
int Unk0979d8_AddField344();
int Unk0fc584_IsBelow64();
int Unk0fc584_Unk_0fc7b8();
/* decompiler-derived */
u32 Unk03ca38_Unk_03ca38(void)
{
  int value1;
  int value2;
  value1 = func_0203ac00(0);
  Unk0979d8_AddField344();
  Unk03aae8_Unk_03acf4();
  if ((value1 != 0) && (value2 = Unk0fc584_IsBelow64(), value2 != 0)) {
    Unk02dcfc_SetOwnerCode22();
    Unk0fc584_Unk_0fc7b8(value1);
    return 3;
  }
  return 1;
}

int func_0203ac00();
int Unk03aae8_Unk_03acf4();
u8 *Unk02e000_Thunk_0202e788();
int Unk0979d8_Unk_098124();
int Unk0979d8_Unk_09813c();
int Unk0979d8_Unk_098154();
int Unk096754_Unk_0970b4();
int Unk096754_Unk_0970c4();

int func_0203ca80(void)
{
    int k = func_0203ac00(0);
    int r = 0;
    if (k == 0) {
        r = Unk02e000_Thunk_0202e788()[110];
    } else if (k >= 1 && k <= 3) {
        r = Unk0979d8_Unk_098124((u8)(k - 1));
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

int func_0203cad4(void)
{
    int k = func_0203ac00(0);
    int r = 0;
    if (k == 0) {
        r = Unk096754_Unk_0970b4();
    } else if (k >= 1 && k <= 3) {
        r = Unk0979d8_Unk_09813c((u8)(k - 1));
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}

int func_0203cb28(void)
{
    int k = func_0203ac00(0);
    int r = 0;
    if (k == 0) {
        r = Unk096754_Unk_0970c4();
    } else if (k >= 1 && k <= 3) {
        r = Unk0979d8_Unk_098154((u8)(k - 1));
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}
