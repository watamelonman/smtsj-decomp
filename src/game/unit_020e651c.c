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

/* Ring of 5 entries: 0x02176cb0..0x02176cc4 is 0x14 bytes, and the cursor wraps modulo 5. */
extern s32 data_02176cac;
extern u32 data_02176cb0[5];
extern u32 data_02176cc4[5];

/* Record (index, value) in a 5-entry ring buffer and advance the cursor. The caller
   Unk094fe0_Unk_09502c passes the bit index and value it is about to write. */
void func_020e6708(u32 index, u32 value)
{
    data_02176cb0[data_02176cac] = index;
    data_02176cc4[data_02176cac] = value;
    data_02176cac++;
    data_02176cac %= 5;
}


int Unk0e5fb8_GetOffsetD80();
/* Split a 2-bit value into bits D80+2 and D80+3: bit 0 goes to the first, bit 1 to the second.
   The first argument is unused. */
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
/* Test flag (row a, column b) in the current data block via Unk0e651c_TestFlagIn. */
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

/* Read 2-bit field (row a, slot b) from the current data block via Unk0e651c_Get2BitsIn. */
int Unk0e651c_Get2Bits(u32 a, u32 b)
{
    return Unk0e651c_Get2BitsIn(Unk094fe0_Thunk_0202e8cc(), a, b);
}

/* Read the 2-bit field in slot c (0..31) of row b: bits 64 + c*2 and the next one of the 128-bit row.
   Out-of-range slots read as zero. */
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

/* Write the low 2 bits of v into slot c (0..31) of row b, same layout as Unk0e651c_Get2BitsIn.
   Out-of-range slots are ignored. */
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

/* Test bit b of data block a; indices above 0x7FF (2048 bits) read as zero. */
int Unk0e651c_TestBitChecked(u32 a, u32 b)
{
    if (b > 0x7ff) {
        return 0;
    }
    return Unk094fe0_TestBit(a, b);
}

/* Set bit i to v through Unk094fe0_Call_0209502c; indices above 0x7FF are ignored. */
void Unk0e651c_SetBitChecked(u32 i, u32 v)
{
    if (i > 0x7ff) {
        return;
    }
    Unk094fe0_Call_0209502c(i, v);
}
