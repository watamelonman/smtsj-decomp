/*
 * src/game/unit_020ea208.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02176ddc[];
int func_020572d8();
int func_02057eb8();
int func_02099bac();
int func_020cb044();
int func_020e8374();
int func_020e849c();
int func_020e8f38();

void func_020ead3c(void);
u32 func_020eb2f8(void);
void func_020eaca0(void);
u32 func_020ea72c(void);
void func_020ead4c(void);

/* decompiler-derived */
void func_020ead3c(void)
{
  func_020e8f38();
  func_020cb044();
  return;
}

/* decompiler-derived */
u32 func_020eb2f8(void)
{
  return *data_02176ddc;
}

/* decompiler-derived */
void func_020eaca0(void)
{
  func_02057eb8(0xffffffff);
  func_020572d8();
  return;
}

/* decompiler-derived */
u32 func_020ea72c(void)
{
  int tmp1;
  u32 tmp2;
  tmp1 = func_020eb2f8();
  if (tmp1 == 0) {
    tmp2 = 0;
  }
  else {
    tmp2 = *(u32 *)(tmp1 + 0x1d4);
  }
  return tmp2;
}

/* decompiler-derived */
void func_020ead4c(void)
{
  func_020e8374(8);
  func_020e849c();
  func_02099bac();
  return;
}
