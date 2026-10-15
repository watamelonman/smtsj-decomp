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
int func_020e62e0();
int func_020e6360();
int func_020e63e0();
int func_020e6460();
int func_020e64e0();

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

/* decompiler-derived */
int Unk0e5fb8_Unk_0e6158(int arg0)
{
  return arg0 + 0x8e0;
}

/* Table offset of entry `i` (256 entries of 2 bytes at 0x900); out of range maps to 0. */
int func_020e6160(u32 i)
{
    if (i >= 256) {
        i = 0;
    }
    return 0x900 + (i << 1);
}

/* Table offset of entry `i` (256 entries of 2 bytes at 0xb00); out of range maps to 0. */
int func_020e6174(u32 i)
{
    if (i >= 256) {
        i = 0;
    }
    return 0xb00 + (i << 1);
}

/* Table offset of entry `i` (64 entries of 2 bytes at 0xd00); out of range maps to 0. */
int func_020e6188(u32 i)
{
    if (i >= 64) {
        i = 0;
    }
    return 0xd00 + (i << 1);
}

/* Table offset of entry `i` (128 entries of 4 bytes at 0xd80); out of range maps to 0. */
int func_020e619c(u32 i)
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
  func_020e62e0(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e6348(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e6360(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e63c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e63e0(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e6448(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e6460(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e64c8(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e64e0(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e61c8(u32 arg0,u32 arg1)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  Unk0e5fb8_Unk_0e61e8(value,arg0,arg1);
}



int func_0209502c();
int func_020e613c();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e622c(u32 arg0,u32 arg1,u32 arg2)
{
  u32 value;
  value = func_020e613c(arg1,arg2);
  func_0209502c(arg0,value,1);
}

int func_0209500c();
int func_020e6160();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e631c(u32 arg0,u32 arg1)
{
  int value;
  value = func_020e6160();
  func_0209500c(value,arg1 & 1);
  func_0209500c(value + 1,(int)(arg1 & 2) >> 1);
}

int func_020e6174();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e639c(u32 arg0,u32 arg1)
{
  int value;
  value = func_020e6174();
  func_0209500c(value,arg1 & 1);
  func_0209500c(value + 1,(int)(arg1 & 2) >> 1);
}

int func_020e6188();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e641c(u32 arg0,u32 arg1)
{
  int value;
  value = func_020e6188();
  func_0209500c(value,arg1 & 1);
  func_0209500c(value + 1,(int)(arg1 & 2) >> 1);
}


int func_020e619c();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e649c(u32 arg0,u32 arg1)
{
  int value;
  value = func_020e619c();
  func_0209500c(value,arg1 & 1);
  func_0209500c(value + 1,(int)(arg1 & 2) >> 1);
}

int func_020950b4();
/* decompiler-derived */
void Unk0e5fb8_Unk_0e626c(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_Unk_0e6158(arg1);
  func_020950b4(arg0,tmp1);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e61e8(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = func_020e613c(arg1,arg2);
  func_020950b4(arg0,tmp1);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e62a4(u32 arg0,u32 arg1)
{
  u32 tmp1;
  tmp1 = Unk0e5fb8_Unk_0e6158(arg1);
  func_0209502c(arg0,tmp1,1);
}
