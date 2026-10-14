/*
 * src/game/unit_020e5fb8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk094fe0_Thunk_0202e8cc();
int func_020e61e8();
int func_020e626c();
int func_020e62a4();
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
  func_020e626c(value,arg0);
}

/* decompiler-derived */
void Unk0e5fb8_Unk_0e628c(u32 arg0)
{
  u32 value;
  value = Unk094fe0_Thunk_0202e8cc();
  func_020e62a4(value,arg0);
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
  func_020e61e8(value,arg0,arg1);
}



int func_0209502c();
int func_020e613c();
/* decompiler-derived */
void func_020e622c(u32 arg0,u32 arg1,u32 arg2)
{
  u32 tmp1;
  tmp1 = func_020e613c(arg1,arg2);
  func_0209502c(arg0,tmp1,1);
  return;
}

int func_0209500c();
int func_020e6160();
/* decompiler-derived */
void func_020e631c(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020e6160();
  func_0209500c(tmp1,arg1 & 1);
  func_0209500c(tmp1 + 1,(int)(arg1 & 2) >> 1);
  return;
}

int func_020e6174();
/* decompiler-derived */
void func_020e639c(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020e6174();
  func_0209500c(tmp1,arg1 & 1);
  func_0209500c(tmp1 + 1,(int)(arg1 & 2) >> 1);
  return;
}

int func_020e6188();
/* decompiler-derived */
void func_020e641c(u32 arg0,u32 arg1)
{
  int tmp1;
  tmp1 = func_020e6188();
  func_0209500c(tmp1,arg1 & 1);
  func_0209500c(tmp1 + 1,(int)(arg1 & 2) >> 1);
  return;
}
