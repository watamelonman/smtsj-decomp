/* src/game/unit_0203ca38.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"

int func_0203ac00(int index);
/* Called both with and without an argument in this TU; keep the implicit
   parameter list so both call forms compile. */
int Unk03aae8_Unk_03acf4();
int Unk0979d8_AddField344(void);
int Unk0fc584_IsBelow64(void);
int Unk0fc584_Unk_0fc7b8(int value);
int Unk02dcfc_SetOwnerCode22(void);

/* Runs the mode-specific setup for the active mode and returns 3 when both the
   mode lookup and the distance check succeed, otherwise 1. */
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

u8 *Unk02e000_Thunk_0202e788(void);
int Unk0979d8_Unk_098124(int index);
int Unk0979d8_Unk_09813c(int index);
int Unk0979d8_Unk_098154(int index);
int Unk096754_Unk_0970b4(void);
int Unk096754_Unk_0970c4(void);

/* Feeds the active mode's field-110 value (mode 0) or the mode-indexed table
   value (modes 1-3) to the setter, then returns 1. */
int Unk03ca38_Unk_03ca80(void)
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

/* Same dispatch as Unk03ca80 but reads the second mode-indexed table, then
   returns 1. */
int Unk03ca38_Unk_03cad4(void)
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

/* Same dispatch as Unk03ca80 but reads the third mode-indexed table, then
   returns 1. */
int Unk03ca38_Unk_03cb28(void)
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

int Unk096754_ClampField1c(int value);
int Unk0979d8_Unk_09816c(int index, int value);
int Unk0979d8_Unk_097f00(int value);
int Unk0979d8_ClampAllField1e(int value);

/* Dispatch on the active mode: clamp the value from func_0203ac00(1) through
   the per-mode setter (modes 1-3 share one setter), then report success. */
int func_0203cb7c(void)
{
    int k = func_0203ac00(0);
    int v = func_0203ac00(1);
    switch (k) {
    case 0:
        Unk096754_ClampField1c((s16)v);
        break;
    case 1:
    case 2:
    case 3:
        Unk0979d8_Unk_09816c((u8)(k - 1), (s16)v);
        break;
    case 4:
        Unk0979d8_Unk_097f00((s16)v);
        break;
    case 5:
        Unk0979d8_ClampAllField1e((s16)v);
        break;
    }
    return 1;
}

int Unk096754_Unk_097100(void);
int Unk0979d8_Unk_09818c(int index);

/* Same dispatch as Unk03ca80 but reads the fourth mode-indexed table, then
   returns 1. */
int Unk03ca38_Unk_03cc04(void)
{
    int k = func_0203ac00(0);
    int r = 0;
    if (k == 0) {
        r = Unk096754_Unk_097100();
    } else if (k >= 1 && k <= 3) {
        r = Unk0979d8_Unk_09818c((u8)(k - 1));
    }
    Unk03aae8_Unk_03acf4(r);
    return 1;
}
