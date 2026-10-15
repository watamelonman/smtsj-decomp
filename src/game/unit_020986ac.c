/*
 * src/game/unit_020986ac.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774();
void Unk0986ac_SetFlagBit();
int Unk0986ac_TestFlagBit(int bit);

void Unk0986ac_Nop_099230(void);
int Unk0986ac_Unk_098978(int arg0);
int Unk0986ac_Thunk_02098714(int bit);
void Unk0986ac_Unk_09894c(u32 arg0);
void Unk0986ac_Unk_09895c(u32 arg0);
int Unk0986ac_Unk_0986ac(void);
int Unk0986ac_Unk_0986c0(int arg0);

/* empty callback */
void Unk0986ac_Nop_099230(void) { }

/* decompiler-derived */
int Unk0986ac_Unk_098978(int arg0)
{
  return arg0 + -0x6f;
}

/* forwards to `Unk0986ac_TestFlagBit` */
int Unk0986ac_Thunk_02098714(int bit) { return Unk0986ac_TestFlagBit(bit); }

/* decompiler-derived */
void Unk0986ac_Unk_09894c(u32 arg0)
{
  Unk0986ac_SetFlagBit(arg0,1);
}

/* decompiler-derived */
void Unk0986ac_Unk_09895c(u32 arg0)
{
  Unk0986ac_SetFlagBit(arg0,0);
}

/* decompiler-derived */
int Unk0986ac_Unk_0986ac(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5c80;
}

/* decompiler-derived */
int Unk0986ac_Unk_0986c0(int arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  return value + (arg0 >> 3);
}



int func_0204fed8();
void func_02061f10();
void Unk0986ac_SetFlagBit(int bit, int on)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    u8 m = 1 << (bit & 7);
    if (on) {
        *p |= m;
    } else {
        *p &= ~m;
    }
}

int Unk0986ac_TestFlagBit(int bit)
{
    u8 *p = (u8 *)Unk0986ac_Unk_0986c0(bit);
    return (*p & (u8)(1 << (bit & 7))) != 0;
}

/* decompiler-derived */
void Unk0986ac_Unk_098990(u8 arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  *(u8 *)(value + 0xd) = arg0;
}

int Unk02e000_Unk_02e0cc();
int Unk05b82c_Unk_05b82c();
/* decompiler-derived */
u32 Unk0986ac_Unk_099300(void)
{
  Unk02e000_Unk_02e0cc();
  Unk05b82c_Unk_05b82c(0xbf);
  return 1;
}

int func_02099d78();
int Unk09974c_HasFlagsMid();
int Unk09974c_GetFlagsMidMinus1();
/* decompiler-derived */
u32 Unk0986ac_Unk_098918(void)
{
  int value1;
  int value2;
  u32 value3;
  value3 = 0;
  value1 = func_02099d78();
  if ((value1 != 0) && (value2 = Unk09974c_HasFlagsMid(), value2 != 0)) {
    value3 = Unk09974c_GetFlagsMidMinus1(value1);
  }
  return value3;
}

/* decompiler-derived */
u8 Unk0986ac_Unk_098980(void)
{
  int tmp1;
  tmp1 = Unk0986ac_Unk_0986ac();
  return *(u8 *)(tmp1 + 0xd);
}

void Unk0986ac_Unk_0989a4(int a, u8 *p, int c)
{
    func_02061f10(a, -1, 0, 0, func_0204fed8(FIELD(u32, p, 4), c));
}

typedef struct Unk0986acPair {
    s8 a;
    s8 b;
} Unk0986acPair;

u32 Unk0986ac_FindEmpty(const Unk0986acPair *t)
{
    u32 j;
    for (j = 0; j < 23; j++) {
        if (t[j].a == 0) {
            return j;
        }
    }
    return 23;
}

void Unk0986ac_Unk_098aa8(u8 *p)
{
    s32 n = FIELD(s32, p, 56);
    if (n <= 0) {
        FIELD(s32, p, 64) = 0;
        FIELD(u8, p, 68) = 0;
        return;
    }
    FIELD(s32, p, 64) = (FIELD(s32, p, 60) - 16) * n + 16;
    FIELD(u8, p, 68) = n * 31;
}

int Unk0986ac_IsMode012(u8 *p)
{
    u32 v = FIELD(u32, p, 44);
    int r = 0;
    switch (v) {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        r = 1;
        break;
    }
    return r;
}

void func_0209911c();
void func_02099174();
int func_020a246c();
void Unk0986ac_Unk_099234(u8 *p);
void Unk0986ac_Unk_099234(u8 *p)
{
    FIELD(s32, p, 56) -= 1;
    Unk0986ac_Unk_098aa8(p);
    if (FIELD(s32, p, 56) > 0) {
        return;
    }
    FIELD(s32, p, 24) = 0;
    FIELD(s32, p, 40) = 0;
    FIELD(s32, p, 56) = 0;
    FIELD(s32, p, 64) = 0;
    FIELD(u8, p, 68) = 0;
}

void Unk0986ac_Unk_099274(u8 *p)
{
    FIELD(s32, p, 20) = FIELD(s32, p, 24);
    FIELD(s32, p, 24) = -1;
    switch (FIELD(s32, p, 20)) {
    case 2:
        func_0209911c(p);
        break;
    case 3:
        Unk0986ac_Nop_099230();
        break;
    }
}

void Unk0986ac_Unk_0992b0(u8 *p)
{
    switch (FIELD(u32, p, 20)) {
    case 0:
        break;
    case 1:
        if (func_020a246c() == 1) {
            FIELD(s32, p, 24) = 2;
        }
        break;
    case 2:
        func_02099174(p);
        break;
    case 3:
        break;
    case 4:
        Unk0986ac_Unk_099234(p);
        break;
    }
}
