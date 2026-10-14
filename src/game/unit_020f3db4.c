/*
 * src/game/unit_020f3db4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774();
int func_02044428();
int func_02044534();
int func_020f3ec8();

u32 Unk0f3db4_Unk_0f44a8(u32 arg0);
void Unk0f3db4_Unk_0f3dc8(void);
void Unk0f3db4_Unk_0f3dd8(void);
int Unk0f3db4_Unk_0f4528(u32 arg0);
void Unk0f3db4_Unk_0f4550(u8 *arg0);
int Unk0f3db4_Unk_0f3db4(void);
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1);
void Unk0f3db4_Unk_0f4490(u32 arg0,int arg1);

/* decompiler-derived */
u32 Unk0f3db4_Unk_0f44a8(u32 arg0)
{
  return arg0 & 3;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f3dc8(void)
{
  func_02044428(8);
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f3dd8(void)
{
  func_02044534(8);
}

/* decompiler-derived */
int Unk0f3db4_Unk_0f4528(u32 arg0)
{
  return (arg0 & 4) != 0;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4550(u8 *arg0)
{
  *arg0 = *arg0 | 4;
}

/* decompiler-derived */
int Unk0f3db4_Unk_0f3db4(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5e52;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f44d0(u8 *arg0,u8 arg1)
{
  *arg0 = *arg0 & 4 | arg1;
}

/* decompiler-derived */
void Unk0f3db4_Unk_0f4490(u32 arg0,int arg1)
{
  int value;
  value = func_020f3ec8();
  Unk0f3db4_Unk_0f44a8(*(u8 *)(value + arg1));
}
