/* src/game/unit_020e7290.c: matched functions; decompiler-derived bodies are cleaned Ghidra output. */
#include "types.h"



/* Object passed as first arg in this file; layout from observed accesses. */
typedef struct Unk0e7290Work {
    u8 pad_0000[0x8];
    u32 unk_0008;
    u32 unk_000c;
    u8 pad_0010[0x7c];
    u32 unk_008c;
} Unk0e7290Work;

extern u8 *data_02176cd8;
/* decompiler-derived */
void Unk0e7290_Clear_data_02176cd8(void)
{
  data_02176cd8 = 0;
}

int func_02061424();
/* decompiler-derived */
u32 Unk0e7290_Unk_0e7734(void)
{
  int value;
  value = (u32)data_02176cd8;
  if (value == 0) {
    return 0;
  }
  if (*(int *)(value + 0x10) == 5 || *(int *)(value + 0x10) == 0) {
    func_02061424(value);
    return 1;
  }
  return 0;
}

extern u8 data_02150bf0[];
int func_02013c3c();
int func_020445d0();
int func_0204fde0();
/* decompiler-derived */
void Unk0e7290_Unk_0e77a8(u32 arg0,int arg1)
{
  int value1;
  int value2;
  value1 = func_020445d0(0x22,0);
  value2 = func_0204fde0();
  if (arg1 < 1) {
    arg1 = 1;
  }
  func_02013c3c(arg0,((int)data_02150bf0),*(int *)(value1 + 0xc) * (arg1 + -1) + value2);
}

int func_02053000();
/* decompiler-derived */
u32 Unk0e7290_Unk_0e747c(int arg0)
{
  char *v1;
  int v2;
  int value1;
  int value2;
  value1 = 0;
  v2 = 1;
  value2 = arg0;
  do {
    v1 = (char *)(value2 + 0xed);
    value1 = value1 + 1;
    value2 = value2 + 0x5c;
    if (*v1 == '\0') {
      v2 = 0;
    }
  } while (value1 < 4);
  if (v2) {
    func_02053000(((Unk0e7290Work *)arg0)->unk_008c);
    ((Unk0e7290Work *)arg0)->unk_008c = 0;
    ((Unk0e7290Work *)arg0)->unk_0008 = ((Unk0e7290Work *)arg0)->unk_000c;
    ((Unk0e7290Work *)arg0)->unk_000c = 0;
    return 1;
  }
  return 0;
}

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif

void Unk0e7290_Set_0e7770(u32 a, u32 b)
{
    if (data_02176cd8 != 0) {
        FIELD(u32, data_02176cd8, 0) = a;
        FIELD(u32, data_02176cd8, 4) = b;
    }
}

/* decompiler-derived */
void Unk0e7290_Unk_0e7790(u32 arg0)
{
  if (data_02176cd8 != 0) {
    *(u32 *)(data_02176cd8 + 0x204) = arg0;
  }
}

int Unk0e7290_Unk_0e77f0(u32 a)
{
    u32 k;
    if (data_02176cd8 == 0) {
        return 0;
    }
    k = FIELD(u32, data_02176cd8, 16);
    if (k != 5 && k != 0) {
        return 0;
    }
    FIELD(u32, data_02176cd8, 8) = 0;
    FIELD(u32, data_02176cd8, 12) = a;
    FIELD(u32, data_02176cd8, 16) = 0;
    return 1;
}
