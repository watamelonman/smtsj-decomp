/*
 * src/game/unit_020e651c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_02094fe0();
int func_0209500c();
int func_020e6100();
int func_020e61b0();
int func_020e61bc();
int func_020e6684();
int func_020e66d8();

void func_020e654c(void);
void func_020e6560(void);
void func_020e666c(u32 arg0);
void func_020e66c0(u32 arg0);
void func_020e66f0(u32 arg0,u32 arg1);

/* decompiler-derived */
void func_020e654c(void)
{
  u32 tmp1;
  tmp1 = func_020e61b0();
  func_0209500c(tmp1,1);
  return;
}

/* decompiler-derived */
void func_020e6560(void)
{
  u32 tmp1;
  tmp1 = func_020e61bc();
  func_0209500c(tmp1,1);
  return;
}

/* decompiler-derived */
void func_020e666c(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_02094fe0();
  func_020e6684(tmp1,arg0);
  return;
}

/* decompiler-derived */
void func_020e66c0(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_02094fe0();
  func_020e66d8(tmp1,arg0);
  return;
}

/* decompiler-derived */
void func_020e66f0(u32 arg0,u32 arg1)
{
  func_020e6100(0xfb0,5,arg1);
  return;
}
