/*
 * src/game/unit_020e5fb8.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_02094fe0();
int func_020e626c();

int func_020e6158(int arg0);
int func_020e61b0(int arg0);
int func_020e61bc(int arg0);
void func_020e6254(u32 arg0);

/* decompiler-derived */
int func_020e6158(int arg0)
{
  return arg0 + 0x8e0;
}

/* decompiler-derived */
int func_020e61b0(int arg0)
{
  return arg0 + 0x2ff;
}

/* decompiler-derived */
int func_020e61bc(int arg0)
{
  return arg0 + 0x37f;
}

/* decompiler-derived */
void func_020e6254(u32 arg0)
{
  u32 tmp1;
  tmp1 = func_02094fe0();
  func_020e626c(tmp1,arg0);
  return;
}
