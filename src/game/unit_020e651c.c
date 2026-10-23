/*
 * src/game/unit_020e651c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

u32 Unk094fe0_Thunk_0202e8cc(void);
void Unk094fe0_Call_0209502c(u32 index, u32 value);
void Unk0e5fb8_SetBits(u32 index, int count, u32 value);
u32 Unk0e5fb8_GetBits(u32 data, int index, int count);
int Unk0e5fb8_Unk_0e61b0(int index);
int Unk0e5fb8_Unk_0e61bc(int index);
int Unk0e651c_TestBitChecked(u32 data, u32 index);
u8 func_020e66d8(u32 data, u32 unused);

void Unk0e651c_Unk_0e654c(int index);
void Unk0e651c_Unk_0e6560(int index);
void Unk0e651c_Unk_0e666c(u32 arg0);
void Unk0e651c_Unk_0e66c0(u32 arg0);
void Unk0e651c_Unk_0e66f0(u32 arg0,u32 arg1);

/* Forward the caller index to the 0xe61b0 offset helper and set its bit to one. */
void Unk0e651c_Unk_0e654c(int index)
{
  u32 value;
  value = Unk0e5fb8_Unk_0e61b0(index);
  Unk094fe0_Call_0209502c(value,1);
}

/* Forward the caller index to the 0xe61bc offset helper and set its bit to one. */
void Unk0e651c_Unk_0e6560(int index)
{
  u32 value;
  value = Unk0e5fb8_Unk_0e61bc(index);
  Unk094fe0_Call_0209502c(value,1);
}

/* Test the requested bit in the current data block through the checked helper. */
void Unk0e651c_Unk_0e666c(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e651c_TestBitChecked(value,arg0);
}

/* Forward the current data block and caller argument to the fixed-field reader. */
void Unk0e651c_Unk_0e66c0(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e66d8(value,arg0);
}

/* Read five bits at 0xFB0 and narrow to a byte, as shown by the GetBits call. */
u8 func_020e66d8(u32 data, u32 unused)
{
    return (u8)Unk0e5fb8_GetBits(data, 0xfb0, 5);
}

/* Write five bits at 0xFB0; the SetBits call establishes the field width and offset. */
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

int Unk0e651c_TestFlagIn(u32 a, u32 b, u32 c);
int Unk0e651c_Get2BitsIn(u32 a, u32 b, u32 c);
int Unk094fe0_TestBit200(u32 data, u32 index);
void Unk094fe0_Unk_095204(u32 index, u32 value);
int Unk094fe0_TestBit();
int Unk0e651c_TestFlag(u32 a, u32 b)
{
    return Unk0e651c_TestFlagIn(Unk094fe0_Thunk_0202e8cc(), a, b);
}

/* TestBit200 call: each row has 128 bits; only columns 0..63 are accepted. */
int Unk0e651c_TestFlagIn(u32 a, u32 b, u32 c)
{
    if (c >= 64) {
        return 0;
    }
    return Unk094fe0_TestBit200(a, c + b * 128);
}

/* Matching 128-bit row layout: ignore columns >=64 and forward the bit value. */
void Unk0e651c_SetFlag(u32 b, u32 c, u32 v)
{
    if (c >= 64) {
        return;
    }
    Unk094fe0_Unk_095204(c + b * 128, v);
}

int Unk0e651c_Get2Bits(u32 a, u32 b)
{
    return Unk0e651c_Get2BitsIn(Unk094fe0_Thunk_0202e8cc(), a, b);
}

int Unk0e651c_Get2BitsIn(u32 a, u32 b, u32 c)
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

void Unk0e651c_Set2Bits(u32 b, u32 c, int v)
{
    int o;
    if (c >= 32) {
        return;
    }
    o = b * 128 + 64 + c * 2;
    Unk094fe0_Unk_095204(o, v & 1);
    Unk094fe0_Unk_095204(o + 1, (v & 2) >> 1);
}

int Unk0e651c_TestBitChecked(u32 a, u32 b)
{
    if (b > 0x7ff) {
        return 0;
    }
    return Unk094fe0_TestBit(a, b);
}

void Unk0e651c_SetBitChecked(u32 i, u32 v)
{
    if (i > 0x7ff) {
        return;
    }
    Unk094fe0_Call_0209502c(i, v);
}
