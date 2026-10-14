/*
 * src/game/unit_0202f078.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_02008848();
int func_0202e774();
int func_0202e788();

u8 func_0202f0d8(void);
u8 func_0202f220(void);
int func_0202f078(void);
void func_0202f0b0(u8 arg0);
void func_0202f0c4(void);
void func_0202f20c(u8 arg0);
int func_0202f0e8(void);
void func_0202f08c(void);

/* decompiler-derived */
u8 func_0202f0d8(void)
{
  int tmp1;
  tmp1 = func_0202e774();
  return *(u8 *)(tmp1 + 2);
}

/* decompiler-derived */
u8 func_0202f220(void)
{
  int tmp1;
  tmp1 = func_0202e788();
  return *(u8 *)(tmp1 + 0x361);
}

/* decompiler-derived */
int func_0202f078(void)
{
  int tmp1;
  tmp1 = func_0202e788();
  return tmp1 + 0x36e;
}

/* decompiler-derived */
void func_0202f0b0(u8 arg0)
{
  int tmp1;
  tmp1 = func_0202e774();
  *(u8 *)(tmp1 + 2) = arg0;
  return;
}

/* decompiler-derived */
void func_0202f0c4(void)
{
  int tmp1;
  tmp1 = func_0202e774();
  *(u8 *)(tmp1 + 2) = 0;
  return;
}

/* decompiler-derived */
void func_0202f20c(u8 arg0)
{
  int tmp1;
  tmp1 = func_0202e788();
  *(u8 *)(tmp1 + 0x361) = arg0;
  return;
}

/* decompiler-derived */
int func_0202f0e8(void)
{
  int tmp1;
  tmp1 = func_0202e774();
  return *(char *)(tmp1 + 2) != '\0';
}

/* decompiler-derived */
void func_0202f08c(void)
{
  int tmp1;
  tmp1 = func_0202f078();
  func_02008848(tmp1,0,6);
  *(u8 *)(tmp1 + 1) = 100;
  return;
}
