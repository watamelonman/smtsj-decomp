/*
 * src/game/unit_020e5fb8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk094fe0_Thunk_0202e8cc();
void Unk0e5fb8_Unk_0e61e8(u32 arg0,u32 arg1,u32 arg2);
void Unk0e5fb8_Unk_0e626c(u32 arg0,u32 arg1);
void Unk0e5fb8_Unk_0e62a4(u32 arg0,u32 arg1);
int Unk0e5fb8_Get2Bits();
int Unk0e5fb8_Get2BitsB00();
int Unk0e5fb8_Get2BitsD00();
int Unk0e5fb8_Get2BitsD80();
int Unk0e5fb8_Get2BitsD80Hi();

int Unk0e5fb8_Unk_0e6158(int arg0);
int Unk0e5fb8_Unk_0e61b0(int arg0);
int Unk0e5fb8_Unk_0e61bc(int arg0);
void Unk0e5fb8_Unk_0e6254(u32 arg0);
void Unk0e5fb8_Unk_0e628c(u32 arg0);
void Unk0e5fb8_Unk_0e62c8(u32 arg0);
void Unk0e5fb8_Unk_0e6348(u32 arg0);
void Unk0e5fb8_Unk_0e63c8(u32 arg0);
void Unk0e5fb8_Unk_0e6448(u32 arg0);
void Unk0e5fb8_Unk_0e64c8(u32 arg0);
void Unk0e5fb8_Unk_0e61c8(u32 arg0,u32 arg1);

u32 Unk0e5fb8_GetBits(u32 a, int b, int n)
{
    u32 bits = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (Unk094fe0_TestBit(a, b + i) != 0) {
            bits |= 1 << i;
        }
    }
    return bits;
}

void Unk0e5fb8_SetBits(int a, int n, u32 bits)
{
    int i;
    for (i = 0; i < n; i++) {
        Unk094fe0_Call_0209502c(a + i, (bits >> i) & 1);
    }
}

int Unk0e5fb8_GetOffset800(int row, u32 col)
{
    int base = row * 10;
    if (col >= 10) {
        col = 0;
    }
    return col + (base + 0x800);
}

/* decompiler-derived */
int Unk0e5fb8_Unk_0e6158(int arg0)
{
  return arg0 + 0x8e0;
}

/* Table offset of entry `i` (256 entries of 2 bytes at 0x900); out of range maps to 0. */
int Unk0e5fb8_GetOffset900(u32 i)
{
    if (i >= 256) {
        i = 0;
    }
    return 0x900 + (i << 1);
}

/* Table offset of entry `i` (256 entries of 2 bytes at 0xb00); out of range maps to 0. */
int Unk0e5fb8_GetOffsetB00(u32 i)
{
    if (i >= 256) {
        i = 0;
    }
    return 0xb00 + (i << 1);
}

/* Table offset of entry `i` (64 entries of 2 bytes at 0xd00); out of range maps to 0. */
int Unk0e5fb8_GetOffsetD00(u32 i)
{
    if (i >= 64) {
        i = 0;
    }
    return 0xd00 + (i << 1);
}

/* Table offset of entry `i` (128 entries of 4 bytes at 0xd80); out of range maps to 0. */
int Unk0e5fb8_GetOffsetD80(u32 i)
{
    if (i >= 128) {
        i = 0;
    }
    return 0xd80 + (i << 2);
}

/* decompiler-derived */
int Unk0e5fb8_Unk_0e61b0(int arg0)
{
  return arg0 + 0x2ff;
}

/* decompiler-derived */
int Unk0e5fb8_Unk_0e61bc(int arg0)
{
  return arg0 + 0x37f;
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e6254(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e626c(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e628c(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e62a4(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e62c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2Bits(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e6348(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsB00(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e63c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsD00(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e6448(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsD80(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e64c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsD80Hi(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e61c8(u32 arg0,u32 arg1)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e61e8(value,arg0,arg1);
}



int Unk094fe0_Unk_09502c();
int Unk0e5fb8_GetOffset800();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e622c(u32 arg0,u32 arg1,u32 arg2)
{
  u32 value;
  value = Unk0e5fb8_GetOffset800(arg1,arg2);
  Unk094fe0_Unk_09502c(arg0,value,1);
}

int Unk094fe0_Call_0209502c();
int Unk0e5fb8_GetOffset900();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e631c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffset900();
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}

int Unk0e5fb8_GetOffsetB00();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e639c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetB00();
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}

int Unk0e5fb8_GetOffsetD00();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e641c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetD00();
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}


int Unk0e5fb8_GetOffsetD80();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e649c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetD80();
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}

int Unk094fe0_TestBit();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e626c(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_Unk_0e6158(arg1);
  Unk094fe0_TestBit(arg0,tmp1);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e61e8(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_GetOffset800(arg1,arg2);
  Unk094fe0_TestBit(arg0,tmp1);
}

void Unk0e5fb8_Unk_0e620c(u32 a, u32 b)
{
    Unk0e5fb8_Unk_0e622c(Unk094fe0_Thunk_0202e8cc(), a, b);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e62a4(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_Unk_0e6158(arg1);
  Unk094fe0_Unk_09502c(arg0,tmp1,1);
}

int Unk0e5fb8_Get2Bits(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffset900(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

int Unk094fe0_TestBit();
int Unk0e5fb8_Get2BitsB00(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetB00(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

int Unk0e5fb8_Get2BitsD00(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetD00(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

int Unk0e5fb8_Get2BitsD80(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetD80(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

int Unk0e5fb8_Get2BitsD80Hi(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetD80(b);
    int lo = Unk094fe0_TestBit(a, o + 2);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 3) << 1));
}
