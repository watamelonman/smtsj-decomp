/*
 * src/game/unit_020e651c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk094fe0_Thunk_0202e8cc();
int Unk094fe0_Call_0209502c();
int Unk0e5fb8_SetBits();
int Unk0e5fb8_Unk_0e61b0();
int Unk0e5fb8_Unk_0e61bc();
int func_020e6684();
int func_020e66d8();

void Unk0e651c_Unk_0e654c(void);
void Unk0e651c_Unk_0e6560(void);
void Unk0e651c_Unk_0e666c(u32 arg0);
void Unk0e651c_Unk_0e66c0(u32 arg0);
void Unk0e651c_Unk_0e66f0(u32 arg0,u32 arg1);

/* decompiler-derived */
void Unk0e651c_Unk_0e654c(void)
{
  u32 value;
  value = Unk0e5fb8_Unk_0e61b0();
  Unk094fe0_Call_0209502c(value,1);
}

/* decompiler-derived */
void Unk0e651c_Unk_0e6560(void)
{
  u32 value;
  value = Unk0e5fb8_Unk_0e61bc();
  Unk094fe0_Call_0209502c(value,1);
}

/* decompiler-derived */
void Unk0e651c_Unk_0e666c(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e6684(value,arg0);
}

/* decompiler-derived */
void Unk0e651c_Unk_0e66c0(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e66d8(value,arg0);
}

/* decompiler-derived */
void Unk0e651c_Unk_0e66f0(u32 arg0,u32 arg1)
{
  Unk0e5fb8_SetBits(0xfb0,5,arg1);
}


int Unk0e5fb8_GetOffsetD80();
/* decompiler-derived */
void Unk0e651c_Unk_0e651c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetD80();
  Unk094fe0_Call_0209502c(value + 2,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 3,(int)(arg1 & 2) >> 1);
}

int func_020e6594(u32 a, u32 b, u32 c);
int func_020e65ec(u32 a, u32 b, u32 c);
int Unk094fe0_TestBit200();
void Unk094fe0_Unk_095204();
int Unk094fe0_TestBit();
int func_020e6574(u32 a, u32 b)
{
    return func_020e6594(Unk094fe0_Thunk_0202e8cc(), a, b);
}

int func_020e6594(u32 a, u32 b, u32 c)
{
    if (c >= 64) {
        return 0;
    }
    return Unk094fe0_TestBit200(a, c + b * 128);
}

void func_020e65b0(u32 b, u32 c, u32 v)
{
    if (c >= 64) {
        return;
    }
    Unk094fe0_Unk_095204(c + b * 128, v);
}

int func_020e65cc(u32 a, u32 b)
{
    return func_020e65ec(Unk094fe0_Thunk_0202e8cc(), a, b);
}

int func_020e65ec(u32 a, u32 b, u32 c)
{
    int o;
    int lo;
    if (c >= 32) {
        return 0;
    }
    o = b * 128 + 64 + c * 2;
    lo = Unk094fe0_TestBit200(a, o);
    return (u8)(lo | (Unk094fe0_TestBit200(a, o + 1) << 1));
}

void func_020e6630(u32 b, u32 c, int v)
{
    int o;
    if (c >= 32) {
        return;
    }
    o = b * 128 + 64 + c * 2;
    Unk094fe0_Unk_095204(o, v & 1);
    Unk094fe0_Unk_095204(o + 1, (v & 2) >> 1);
}

int func_020e6684(u32 a, u32 b)
{
    if (b > 0x7ff) {
        return 0;
    }
    return Unk094fe0_TestBit(a, b);
}

void func_020e66a4(u32 i, u32 v)
{
    if (i > 0x7ff) {
        return;
    }
    Unk094fe0_Call_0209502c(i, v);
}
