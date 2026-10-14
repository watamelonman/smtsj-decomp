/*
 * src/game/unit_020e1648.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02176c78[];
int func_020e8014();
int func_020e8030();

u32 func_020e5240(int arg0,int arg1);
u32 func_020e1688(void);
int func_020e2da0(int arg0);
void func_020e2cb0(int arg0);
void func_020e5434(void);
int func_020e1648(void);
int func_020e2c90(int arg0,int arg1);

/* decompiler-derived */
u32 func_020e5240(int arg0,int arg1)
{
  return *(u32 *)(arg0 + arg1 * 4 + 0xc);
}

/* decompiler-derived */
u32 func_020e1688(void)
{
  return *data_02176c78;
}

/* decompiler-derived */
int func_020e2da0(int arg0)
{
  return arg0 + 0xd2 + *(int *)(arg0 + 0x7c) * 8;
}

/* decompiler-derived */
void func_020e2cb0(int arg0)
{
  *(u32 *)(arg0 + 0xec0) = (u32)(*(int *)(arg0 + 0xec0) == 0);
  return;
}

/* decompiler-derived */
void func_020e5434(void)
{
  func_020e8014(0);
  func_020e8030(0);
  return;
}

/* decompiler-derived */
int func_020e1648(void)
{
  return *(int *)(((int)data_02176c78) + 4) == 0;
}

/* decompiler-derived */
int func_020e2c90(int arg0,int arg1)
{
  int tmp1;
  tmp1 = (u32)*(u16 *)(arg0 + 6) - (u32)*(u16 *)(arg1 + 6);
  if (tmp1 == 0) {
    tmp1 = (u32)*(u16 *)(arg0 + 4) - (u32)*(u16 *)(arg1 + 4);
  }
  return tmp1;
}
