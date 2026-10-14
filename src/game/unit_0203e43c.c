/*
 * src/game/unit_0203e43c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_0215e85e[];
int func_0202e788();
int func_0203fa08();
void func_0203fa84(void);
int func_0205410c();

void func_02041d64(void);
int func_0203f2ac(int arg0);
void func_0203fa28(void);
void func_0203f2bc(void);
void func_0203fa3c(char arg0);

/* forwards to `func_0203fa84` */
void func_02041d64(void) { func_0203fa84(); }

/* decompiler-derived */
int func_0203f2ac(int arg0)
{
  return ((int)data_0215e85e) + arg0;
}

/* decompiler-derived */
void func_0203fa28(void)
{
  int tmp1;
  tmp1 = func_0202e788();
  func_0203fa08(*(u8 *)(tmp1 + 0x360));
  return;
}

/* decompiler-derived */
void func_0203f2bc(void)
{
  int tmp1;
  tmp1 = func_0205410c();
  *(u8 *)(tmp1 + 0x10) = *(u8 *)(tmp1 + 0x10) | 2;
  return;
}

/* decompiler-derived */
void func_0203fa3c(char arg0)
{
  int tmp1;
  tmp1 = func_0202e788();
  *(char *)(tmp1 + 0x360) = arg0 * '\n';
  return;
}
