/*
 * src/game/unit_020cb32c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0205e484();
int func_020cb3dc();
int func_020cb4e4();
int func_020cb564();
int func_02122a78();
int func_02122aa0();
int func_021241ec();
int func_02124214();
int func_0212424c();
int func_02124258();

void func_020cba74(void);
void func_020cccc0(void);
void func_020cb35c(u32 arg0);
void func_020cb57c(u32 arg0);
u32 func_020cb32c(void);
u32 func_020cb344(void);
void func_020cb54c(void);

/* empty callback */
void func_020cba74(void) { }

/* empty callback */
void func_020cccc0(void) { }

/* decompiler-derived */
void func_020cb35c(u32 arg0)
{
  func_0205e484(arg0,0x1e);
  return;
}

/* decompiler-derived */
void func_020cb57c(u32 arg0)
{
  func_020cb564(arg0,0);
  return;
}

/* decompiler-derived */
u32 func_020cb32c(void)
{
  func_02122a78();
  func_0212424c();
  func_021241ec();
  return 1;
}

/* decompiler-derived */
u32 func_020cb344(void)
{
  func_02124214();
  func_02124258();
  func_02122aa0();
  return 1;
}

/* decompiler-derived */
void func_020cb54c(void)
{
  u8 tmp1;
  tmp1 = func_020cb3dc();
  func_020cb4e4(tmp1,0);
  return;
}
