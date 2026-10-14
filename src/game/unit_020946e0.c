/*
 * src/game/unit_020946e0.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02175d94[];
int func_02008848();
int func_02052ff0();
void func_02053000(void);
int func_02057628();
int func_02057678();

int func_020948fc(int arg0);
void func_02094904(void);
u32 func_0209494c(void);
void func_02094ae0(int *arg0);
u32 func_020946e0(void);
void func_02094c50(int *arg0);
void func_02094a64(u32 arg0);

/* decompiler-derived */
int func_020948fc(int arg0)
{
  return arg0 + 4;
}

/* forwards to `func_02053000` */
void func_02094904(void) { func_02053000(); }

/* decompiler-derived */
u32 func_0209494c(void)
{
  return ((int)data_02175d94);
}

/* decompiler-derived */
void func_02094ae0(int *arg0)
{
  int tmp1;
  tmp1 = func_0209494c();
  *arg0 = (int)*(short *)(tmp1 + 0x10);
  return;
}

/* decompiler-derived */
u32 func_020946e0(void)
{
  u32 tmp1;
  tmp1 = func_02052ff0(0xc);
  func_02008848(tmp1,0,0xc);
  return tmp1;
}

/* decompiler-derived */
void func_02094c50(int *arg0)
{
  short *v1;
  int tmp2;
  v1 = (short *)func_0209494c();
  *arg0 = (int)*v1;
  tmp2 = func_0209494c();
  arg0[1] = (int)*(short *)(tmp2 + 2);
  return;
}

/* decompiler-derived */
void func_02094a64(u32 arg0)
{
  int tmp1;
  tmp1 = func_0209494c();
  func_02057678(arg0,*(u32 *)(tmp1 + 4),*(u32 *)(tmp1 + 8));
  func_02057628(arg0,0,0);
  return;
}
