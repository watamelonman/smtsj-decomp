/*
 * src/game/unit_02096754.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_GetWorkArea();
int Unk02e000_Thunk_0202e788();
int func_02096898();
int func_0209846c();

int Unk096754_Unk_0970b4(void);
int Unk096754_Unk_0970c4(void);
int Unk096754_Unk_097100(void);
int Unk096754_Unk_097110(void);
void Unk096754_Unk_097204(u32 arg0);
int Unk096754_Unk_0969f0(void);

typedef struct Unk096754Area {
    u8 pad_0000[0x12];
    s16 unk_12;
    s16 unk_14;
    u8 pad_0016[0x6];
    s16 unk_1c;
    s16 unk_1e;
} Unk096754Area;

#ifndef FIELD
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))
#endif
int Unk02e000_GetAreaRecord();
int func_02096a60(int id);
int func_02096754(u32 i)
{
    u8 *base;
    s8 *t;
    int j;
    if (i >= 3) {
        return 0;
    }
    base = (u8 *)Unk02e000_GetWorkArea();
    t = (s8 *)(base + 852);
    for (j = 0; j < 3; j++) {
        if (t[j] >= 0 && i == j) {
            return Unk02e000_GetAreaRecord();
        }
    }
    return 0;
}

int func_02096898(void)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    int n = 0;
    int j;
    for (j = 0; j < 12; j++) {
        if (FIELD(s8, base + j + 768, 72) < 0) {
            break;
        }
        n++;
    }
    return n;
}

void Unk096754_CopyAreaPos(void)
{
    Unk096754Area *a = (Unk096754Area *)Unk02e000_Thunk_0202e788();
    a->unk_1c = a->unk_12;
    a->unk_1e = a->unk_14;
}

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
  value1 = Unk02e000_GetWorkArea();
  value2 = func_02096898();
  return value2 < (int)(u32)*(u8 *)(value1 + 0x357);
}


int Unk02e000_HasField36();
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
  value1 = Unk02e000_GetWorkArea(value1);
  value1 = value1 + 0x74;
  value3 = 0;
  do {
    value2 = Unk02e000_HasField36(value1);
    if (value2 == 0) {
      return value3;
    }
    value3 = value3 + 1;
    value1 = value1 + 0x3c;
  } while (value3 < 0xc);
  return -1;
}

int func_02096a60(int id)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    int j;
    for (j = 0; j < 12; j++) {
        s32 v = FIELD(s8, base + j + 768, 72);
        if (v >= 0 && id == FIELD(u16, base + v * 60, 170)) {
            return 1;
        }
    }
    return 0;
}

int func_02096ab0(int i)
{
    u8 *base = (u8 *)Unk02e000_GetWorkArea();
    u16 v;
    if (i < 0 || i >= 12) {
        return 1;
    }
    v = FIELD(u16, base + i * 60, 168);
    if (v == 1 || v == 7) {
        return 0;
    }
    return 1;
}

int func_02096b44(int id)
{
    if (Unk096754_Unk_0969f0() == 0) {
        return 0;
    }
    return func_02096a60(id) != 1;
}

void func_02096f28(void)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    FIELD(s16, p, 108) = 0;
    Unk096754_CopyAreaPos();
    FIELD(s16, p, 28) = FIELD(s16, p, 18);
    FIELD(s16, p, 30) = FIELD(s16, p, 20);
}

void func_020970d4(int v)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    s32 m = FIELD(s16, p, 18);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 28) = m;
}

void func_02097120(int v)
{
    u8 *p = (u8 *)Unk02e000_Thunk_0202e788();
    s32 m = FIELD(s16, p, 20);
    if (v <= m) {
        if (v < 1) {
            v = 1;
        }
        m = v;
    }
    FIELD(s16, p, 30) = m;
}
