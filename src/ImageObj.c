/*
 * src/ImageObj.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0217231c[];
int func_020775a0();
int func_02077620();
int func_02077640();
int func_02077ddc();
int func_02079238();

u32 func_02077218(void);
void func_020775d8(void);
void func_0207784c(u32 arg0);
void func_02077880(int arg0);
void func_020778d4(int arg0);
u32 func_020778e8(int arg0);
void func_0207916c(int arg0);
void func_020772f8(void);

/* decompiler-derived */
u32 func_02077218(void)
{
  return *data_0217231c;
}

/* decompiler-derived */
void func_020775d8(void)
{
  func_02077620();
  func_020775a0();
  func_02077640();
  return;
}

/* decompiler-derived */
void func_0207784c(u32 arg0)
{
  func_02079238(0,arg0);
  return;
}

/* decompiler-derived */
void func_02077880(int arg0)
{
  func_02079238(1,arg0 + 1);
  return;
}

/* decompiler-derived */
void func_020778d4(int arg0)
{
  func_02079238(2,arg0 + 3);
  return;
}

/* decompiler-derived */
u32 func_020778e8(int arg0)
{
  int tmp1;
  tmp1 = func_02077218();
  return *(u32 *)(tmp1 + arg0 * 4 + 4);
}

/* decompiler-derived */
void func_0207916c(int arg0)
{
  if (*(int *)(arg0 + 4) == 1) {
    *(int *)(arg0 + 0x1c) = 0x100 - *(int *)(arg0 + 0x2c);
  }
  return;
}

/* decompiler-derived */
void func_020772f8(void)
{
  func_02077ddc();
  *data_0217231c = 0;
  return;
}
