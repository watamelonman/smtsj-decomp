/* src/game/unit_0203aae8.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* empty callback */
void Unk03aae8_Nop_03ae0c(void) { }

extern u8 data_0215de34[];
/* decompiler-derived */
u32 Unk03aae8_Unk_03ad14(void)
{
  return *(u32 *)(((int)data_0215de34) + 4);
}

int func_0203ac00();
int Unk094fe0_Call_0209502c();
/* decompiler-derived */
u32 Unk03aae8_Unk_03aef0(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,0);
  return 1;
}

int Unk03aae8_Unk_03acf4();
int func_02050074();
int Unk094fe0_Call_020950b4();
int Unk03aae8_Unk_03af14(void)
{
    if (Unk094fe0_Call_020950b4((s16)func_0203ac00(0))) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

/* decompiler-derived */
u32 Unk03aae8_Unk_03b878(void)
{
  int value;
  value = func_0203ac00(0);
  func_02050074(0,value + -1);
  Unk03aae8_Unk_03acf4();
  return 1;
}


/* decompiler-derived */
u32 Unk03aae8_Unk_03af50(void)
{
  short v1;
  int value1;
  u32 value2;
  value1 = Unk03aae8_Unk_03ad14();
  value2 = *(u32 *)(value1 + 0xe8);
  v1 = func_0203ac00(0);
  Unk02dcfc_Unk_02df00(value2,(int)v1);
  return 3;
}



/* decompiler-derived */
u32 Unk03aae8_Unk_03ac9c(int arg0)
{
  int value1;
  int value2;
  value2 = *(int *)(((int)data_0215de34) + 4);
  value1 = *(int *)(value2 + 0x1c) - (arg0 + 1);
  switch(*(u8 *)(value2 + value1 + 0x20)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    return *(u32 *)(value2 + value1 * 4 + 0x3c);
  }
  return 0;
}


int func_020b8660();
/* decompiler-derived */
u32 Unk03aae8_Unk_03ae68(void)
{
  short v1;
  v1 = func_0203ac00(0);
  Unk094fe0_Call_0209502c((int)v1,1);
  switch((int)v1) {
  case 0x733:
    func_020b8660(0);
    break;
  case 0x734:
    func_020b8660(1);
    break;
  case 0x735:
    func_020b8660(2);
    break;
  case 0x736:
    func_020b8660(3);
    break;
  case 0x737:
    func_020b8660(4);
  }
  return 1;
}

/* decompiler-derived */
int Unk03aae8_Unk_03acf4(u32 arg0)
{
  int tmp1;
  tmp1 = (int)(data_0215de34);
  *(u8 *)(*(int *)(data_0215de34 + 4) + 0x3b) = 0;
  *(u32 *)(*(int *)(tmp1 + 4) + 0xa8) = arg0;
}

int Unk03aae8_Unk_03b89c(void)
{
    u32 a = func_0203ac00(0);
    int b = func_0203ac00(1);
    if (a > (u32)func_02050074(0, b - 1)) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}

int Unk03aae8_Unk_03b93c(void)
{
    int v = func_0203ac00(0);
    int lo = func_0203ac00(1);
    int hi = func_0203ac00(2);
    if (lo <= v && v <= hi) {
        Unk03aae8_Unk_03acf4(1);
    } else {
        Unk03aae8_Unk_03acf4(0);
    }
    return 1;
}
