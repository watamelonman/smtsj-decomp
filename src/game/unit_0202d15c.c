/*
 * src/game/unit_0202d15c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_0213d898[];
int func_02095754();

u32 func_0202d934(void);
u32 func_0202d944(void);
void func_0202d81c(void);
void func_0202d91c(u32 arg0,u32 arg1);

/* decompiler-derived */
u32 func_0202d934(void)
{
  int tmp1;
  tmp1 = func_02095754();
  return *(u32 *)(tmp1 + 4);
}

/* decompiler-derived */
u32 func_0202d944(void)
{
  u32 *v1;
  v1 = (u32 *)func_02095754();
  return *v1;
}

/* decompiler-derived */
void func_0202d81c(void)
{
  *data_0213d898 = 0xffffffff;
  return;
}

/* decompiler-derived */
void func_0202d91c(u32 arg0,u32 arg1)
{
  u32 *v1;
  v1 = (u32 *)func_02095754();
  *v1 = arg1;
  v1[1] = arg0;
  return;
}
