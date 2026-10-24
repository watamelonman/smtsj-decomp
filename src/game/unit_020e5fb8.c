/*
 * src/game/unit_020e5fb8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

/* Writes one bit through the shared context. */
void Unk094fe0_Call_0209502c(int bit, int value);


/* Supplies the shared bit-storage context; no caller arguments are consumed. */
int Unk094fe0_Thunk_0202e8cc(void);
void Unk0e5fb8_Unk_0e61e8(u32 arg0,u32 arg1,u32 arg2);
void Unk0e5fb8_Unk_0e626c(u32 arg0,u32 arg1);
void Unk0e5fb8_Unk_0e62a4(u32 arg0,u32 arg1);
int Unk0e5fb8_Get2Bits(u32 a, u32 b);
int Unk0e5fb8_Get2BitsB00(u32 a, u32 b);
int Unk0e5fb8_Get2BitsD00(u32 a, u32 b);
int Unk0e5fb8_Get2BitsD80(u32 a, u32 b);
int Unk0e5fb8_Get2BitsD80Hi(u32 a, u32 b);

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

/* Reads a bit from the caller-owned context without taking ownership. */
int Unk094fe0_TestBit(u32 context, u32 bit);

/* Packs n consecutive context bits starting at bit index b, LSB first.
 * ARM at 0x020e60b4 loops TestBit(a, b + i) and ORs 1 << i per set bit.
 * n <= 0 returns 0; n > 32 is not meaningful for the u32 result. */
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

/* Writes the low n bits of `bits` to the shared context at bit indices a..a+n-1,
 * LSB first. Inverse of GetBits; ARM at 0x020e6100 calls 0x0209502c per bit. */
void Unk0e5fb8_SetBits(int a, int n, u32 bits)
{
    int i;
    for (i = 0; i < n; i++) {
        Unk094fe0_Call_0209502c(a + i, (bits >> i) & 1);
    }
}

/* Returns bit index 0x800 + 10 * row + col; unsigned columns >= 10 use zero.
 * Evidence: ARM at 0x020e613c and TestBit caller 0x020e61e8. Rows must
 * keep signed multiplication and addition representable; no row check exists. */
int Unk0e5fb8_GetOffset800(int row, u32 col)
{
    int base = row * 10;
    if (col >= 10) {
        col = 0;
    }
    return col + (base + 0x800);
}

/* Adds bit-index base 0x8e0 without bounds checking (ARM at 0x020e6158). */
int Unk0e5fb8_Unk_0e6158(int arg0)
{
  return arg0 + 0x8e0;
}

/* Returns a bit index: base 0x900, stride 2, 256 entries.
 * Unsigned out-of-range indices select entry zero. Evidence: Get2Bits passes
 * this offset to Unk094fe0_TestBit; the ARM helper compares, shifts, then adds. */
int Unk0e5fb8_GetOffset900(u32 i)
{
    if (i >= 256) {
        i = 0;
    }
    return 0x900 + (i << 1);
}

/* Returns a bit index: base 0xb00, stride 2, 256 entries.
 * Unsigned out-of-range indices select entry zero. Evidence: Get2BitsB00 passes
 * this offset to Unk094fe0_TestBit; the ARM helper compares, shifts, then adds. */
int Unk0e5fb8_GetOffsetB00(u32 i)
{
    if (i >= 256) {
        i = 0;
    }
    return 0xb00 + (i << 1);
}

/* Returns a bit index: base 0xd00, stride 2, 64 entries.
 * Unsigned out-of-range indices select entry zero. Evidence: Get2BitsD00 passes
 * this offset to Unk094fe0_TestBit; the ARM helper compares, shifts, then adds. */
int Unk0e5fb8_GetOffsetD00(u32 i)
{
    if (i >= 64) {
        i = 0;
    }
    return 0xd00 + (i << 1);
}

/* Returns a bit index: base 0xd80, stride 4, 128 entries.
 * Unsigned out-of-range indices select entry zero. Evidence: Get2BitsD80 passes
 * this offset to Unk094fe0_TestBit; the ARM helper compares, shifts, then adds. */
int Unk0e5fb8_GetOffsetD80(u32 i)
{
    if (i >= 128) {
        i = 0;
    }
    return 0xd80 + (i << 2);
}

/* Adds 0x2ff without bounds checking; ARM at 0x020e61b0 adds 0xff then 0x200. */
int Unk0e5fb8_Unk_0e61b0(int arg0)
{
  return arg0 + 0x2ff;
}

/* Adds 0x37f without bounds checking; ARM at 0x020e61bc adds 0x7f then 0x300. */
int Unk0e5fb8_Unk_0e61bc(int arg0)
{
  return arg0 + 0x37f;
}

/* Forwards the shared context and unchecked relative bit index to 0x020e626c.
 * Evidence: ARM at 0x020e6254 preserves r0 across the context thunk call,
 * then supplies it in r1. The callee uses the 0x8e0 bit-index base. */
void Unk0e5fb8_Unk_0e6254(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e626c(value,arg0);
}

/* Forwards the shared context and unchecked index to the bit-setting helper
 * at 0x020e62a4. Evidence: ARM at 0x020e628c saves r0 across the thunk call. */
void Unk0e5fb8_Unk_0e628c(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e62a4(value,arg0);
}

/* Forwards the shared context and index to Get2Bits (base 0x900).
 * Evidence: ARM at 0x020e62c8 saves r0 and supplies it as r1 after the thunk. */
void Unk0e5fb8_Unk_0e62c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2Bits(value,arg0);
}

/* Forwards the shared context and index to Get2BitsB00 (base 0xb00).
 * Evidence: ARM at 0x020e6348 saves r0 and supplies it as r1 after the thunk. */
void Unk0e5fb8_Unk_0e6348(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsB00(value,arg0);
}

/* Forwards the shared context and index to Get2BitsD00 (base 0xd00).
 * Evidence: ARM at 0x020e63c8 saves r0 and supplies it as r1 after the thunk. */
void Unk0e5fb8_Unk_0e63c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsD00(value,arg0);
}

/* Forwards the shared context and index to Get2BitsD80 (low pair).
 * Evidence: ARM at 0x020e6448 saves r0 and supplies it as r1 after the thunk. */
void Unk0e5fb8_Unk_0e6448(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsD80(value,arg0);
}

/* Forwards the shared context and index to Get2BitsD80Hi (high pair).
 * Evidence: ARM at 0x020e64c8 saves r0 and supplies it as r1 after the thunk. */
void Unk0e5fb8_Unk_0e64c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Get2BitsD80Hi(value,arg0);
}

/* Forwards the shared context, row and column to 0x020e61e8.
 * Evidence: ARM at 0x020e61c8 preserves both arguments across the thunk
 * and supplies them as r1/r2. The callee reads the GetOffset800 bit index. */
void Unk0e5fb8_Unk_0e61c8(u32 arg0,u32 arg1)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e61e8(value,arg0,arg1);
}



/* Mutates a bit in the caller-owned context; bit indices are not byte offsets. */
void Unk094fe0_Unk_09502c(u32 context, int bit, int value);
int Unk0e5fb8_GetOffset800(int row, u32 col);
/* Sets the row/column bit in the supplied context. ARM at 0x020e622c
 * calls GetOffset800, then 0x0209502c with value 1. Row arithmetic must
 * be representable; unsigned columns >= 10 select column zero. */
void Unk0e5fb8_Unk_0e622c(u32 arg0,u32 arg1,u32 arg2)
{
  u32 value;
  value = Unk0e5fb8_GetOffset800(arg1,arg2);
  Unk094fe0_Unk_09502c(arg0,value,1);
}

int Unk0e5fb8_GetOffset900(u32 index);
/* Writes the low two value bits to the shared-context pair at base 0x900.
 * ARM at 0x020e631c passes the index to GetOffset900 (indices >= 256
 * select zero), then writes masks 1 and 2 to consecutive bit indices. */
void Unk0e5fb8_Unk_0e631c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffset900(arg0);
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}

int Unk0e5fb8_GetOffsetB00(u32 index);
/* Writes the low two value bits to the shared-context pair at base 0xb00.
 * ARM at 0x020e639c uses GetOffsetB00; unsigned indices >= 256 select
 * zero. The second masked bit is shifted arithmetically as in the original. */
void Unk0e5fb8_Unk_0e639c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetB00(arg0);
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}

int Unk0e5fb8_GetOffsetD00(u32 index);
/* Writes the low two value bits to the shared-context pair at base 0xd00.
 * ARM at 0x020e641c uses GetOffsetD00; unsigned indices >= 64 select
 * zero. Higher value bits are ignored. */
void Unk0e5fb8_Unk_0e641c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetD00(arg0);
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}


/* Writes the low two value bits to the low pair of the four-bit entry at base 0xd80.
 * ARM at 0x020e649c uses GetOffsetD80; unsigned indices >= 128 select zero. */
void Unk0e5fb8_Unk_0e649c(u32 arg0,u32 arg1)
{
  int value;
  value = Unk0e5fb8_GetOffsetD80(arg0);
  Unk094fe0_Call_0209502c(value,arg1 & 1);
  Unk094fe0_Call_0209502c(value + 1,(int)(arg1 & 2) >> 1);
}

/* Reads the bit at unchecked index + 0x8e0 from the supplied context.
 * Evidence: ARM at 0x020e626c calls 0x020e6158 then TestBit. Retains the
 * existing void interface; the instructions do not establish a return contract. */
void Unk0e5fb8_Unk_0e626c(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_Unk_0e6158(arg1);
  Unk094fe0_TestBit(arg0,tmp1);
}

/* Reads the row/column bit from the supplied context without ownership.
 * ARM at 0x020e61e8 calls GetOffset800 then TestBit. Row arithmetic must
 * be representable; unsigned columns >= 10 select zero. Keeps the void interface. */
void Unk0e5fb8_Unk_0e61e8(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_GetOffset800(arg1,arg2);
  Unk094fe0_TestBit(arg0,tmp1);
}

/* Supplies the shared context to the row/column setter 0x020e622c.
 * Evidence: ARM at 0x020e620c preserves both arguments across the thunk.
 * Row/column validity follows GetOffset800; storage remains thunk-owned. */
void Unk0e5fb8_Unk_0e620c(u32 a, u32 b)
{
    Unk0e5fb8_Unk_0e622c(Unk094fe0_Thunk_0202e8cc(), a, b);
}

/* Sets the bit at unchecked index + 0x8e0 in the supplied context.
 * Evidence: ARM at 0x020e62a4 calls 0x020e6158 and passes value 1 to
 * 0x0209502c. The signed index addition must be representable. */
void Unk0e5fb8_Unk_0e62a4(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_Unk_0e6158(arg1);
  Unk094fe0_Unk_09502c(arg0,tmp1,1);
}

/* Returns the 2-bit value (0..3) stored at entry b of the 0x900 table, low bit first.
 * ARM at 0x020e62e0: GetOffset900 (b >= 256 selects 0), two TestBit calls, u8 result. */
int Unk0e5fb8_Get2Bits(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffset900(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

/* Returns the 2-bit value (0..3) at entry b of the 0xb00 table, low bit first.
 * ARM at 0x020e6360: GetOffsetB00 (b >= 256 selects 0), two TestBit calls, u8 result. */
int Unk0e5fb8_Get2BitsB00(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetB00(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

/* Returns the 2-bit value (0..3) at entry b of the 0xd00 table, low bit first.
 * ARM at 0x020e63e0: GetOffsetD00 (b >= 64 selects 0), two TestBit calls, u8 result. */
int Unk0e5fb8_Get2BitsD00(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetD00(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

/* Returns the low 2-bit pair (bits 0..1) of four-bit entry b in the 0xd80 table.
 * ARM at 0x020e6460: GetOffsetD80 (b >= 128 selects 0); written by 0x020e649c. */
int Unk0e5fb8_Get2BitsD80(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetD80(b);
    int lo = Unk094fe0_TestBit(a, o);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 1) << 1));
}

/* Returns the high 2-bit pair (bits 2..3) of four-bit entry b in the 0xd80 table.
 * ARM at 0x020e64e0: GetOffsetD80 (b >= 128 selects 0), then TestBit at +2 and +3. */
int Unk0e5fb8_Get2BitsD80Hi(u32 a, u32 b)
{
    int o = Unk0e5fb8_GetOffsetD80(b);
    int lo = Unk094fe0_TestBit(a, o + 2);
    return (u8)(lo | (Unk094fe0_TestBit(a, o + 3) << 1));
}
