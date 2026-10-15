/*
 * src/game/unit_02096754.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0202e788();
int Unk02e000_Thunk_0202e788();
int func_02096898();
int func_0209846c();

int Unk096754_Unk_0970b4(void);
int Unk096754_Unk_0970c4(void);
int Unk096754_Unk_097100(void);
int Unk096754_Unk_097110(void);
void Unk096754_Unk_097204(u32 arg0);
int Unk096754_Unk_0969f0(void);

/* decompiler-derived */
int Unk096754_Unk_0970b4(void)
{
  int value;
  value = Unk02e000_Thunk_0202e788();
  return (int)*(short *)(value + 0x1c);
}

/* decompiler-derived */
int Unk096754_Unk_0970c4(void)
{
  int value;
  value = Unk02e000_Thunk_0202e788();
  return (int)*(short *)(value + 0x12);
}

/* decompiler-derived */
int Unk096754_Unk_097100(void)
{
  int value;
  value = Unk02e000_Thunk_0202e788();
  return (int)*(short *)(value + 0x1e);
}

/* decompiler-derived */
int Unk096754_Unk_097110(void)
{
  int value;
  value = Unk02e000_Thunk_0202e788();
  return (int)*(short *)(value + 0x14);
}

/* decompiler-derived */
void Unk096754_Unk_097204(u32 arg0)
{
  u32 value;
  value = Unk02e000_Thunk_0202e788();
  func_0209846c(arg0,value);
}

/* decompiler-derived */
int Unk096754_Unk_0969f0(void)
{
  int value1;
  int value2;
  value1 = func_0202e788();
  value2 = func_02096898();
  return value2 < (int)(u32)*(u8 *)(value1 + 0x357);
}


int func_0202e904();
/* decompiler-derived */
int Unk096754_Unk_096a14(void)
{
  int value1;
  int value2;
  int value3;
  value1 = Unk096754_Unk_0969f0();
  if (value1 == 0) {
    return -1;
  }
  value1 = func_0202e788(value1);
  value1 = value1 + 0x74;
  value3 = 0;
  do {
    value2 = func_0202e904(value1);
    if (value2 == 0) {
      return value3;
    }
    value3 = value3 + 1;
    value1 = value1 + 0x3c;
  } while (value3 < 0xc);
  return -1;
}


