/*
 * src/game/unit_0209974c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0209993c();

int func_02099860(u16 *arg0,u16 *arg1);
int func_02099870(u16 *arg0,u16 *arg1);
int func_02099880(int arg0,int arg1);
int func_02099890(u16 *arg0,u16 *arg1);
int func_020998a0(u16 *arg0,u16 *arg1);
int func_020998b0(u16 *arg0,u16 *arg1);
int func_020998d8(void);

/* decompiler-derived */
int func_02099860(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int func_02099870(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int func_02099880(int arg0,int arg1)
{
  return (u32)*(u16 *)(arg0 + 0x20) - (u32)*(u16 *)(arg1 + 0x20);
}

/* decompiler-derived */
int func_02099890(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int func_020998a0(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int func_020998b0(u16 *arg0,u16 *arg1)
{
  return (u32)*arg0 - (u32)*arg1;
}

/* decompiler-derived */
int func_020998d8(void)
{
  int tmp1;
  tmp1 = func_0209993c();
  return 0 < tmp1;
}
