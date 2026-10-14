/*
 * src/game/unit_020f3db4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0202e774();
int func_02044428();
int func_02044534();
int func_020f3ec8();

u32 func_020f44a8(u32 arg0);
void func_020f3dc8(void);
void func_020f3dd8(void);
int func_020f4528(u32 arg0);
void func_020f4550(u8 *arg0);
int func_020f3db4(void);
void func_020f44d0(u8 *arg0,u8 arg1);
void func_020f4490(u32 arg0,int arg1);

/* decompiler-derived */
u32 func_020f44a8(u32 arg0)
{
  return arg0 & 3;
}

/* decompiler-derived */
void func_020f3dc8(void)
{
  func_02044428(8);
  return;
}

/* decompiler-derived */
void func_020f3dd8(void)
{
  func_02044534(8);
  return;
}

/* decompiler-derived */
int func_020f4528(u32 arg0)
{
  return (arg0 & 4) != 0;
}

/* decompiler-derived */
void func_020f4550(u8 *arg0)
{
  *arg0 = *arg0 | 4;
  return;
}

/* decompiler-derived */
int func_020f3db4(void)
{
  int tmp1;
  tmp1 = func_0202e774();
  return tmp1 + 0x5e52;
}

/* decompiler-derived */
void func_020f44d0(u8 *arg0,u8 arg1)
{
  *arg0 = *arg0 & 4 | arg1;
  return;
}

/* decompiler-derived */
void func_020f4490(u32 arg0,int arg1)
{
  int tmp1;
  tmp1 = func_020f3ec8();
  func_020f44a8(*(u8 *)(tmp1 + arg1));
  return;
}
