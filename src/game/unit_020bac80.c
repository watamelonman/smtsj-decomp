/*
 * src/game/unit_020bac80.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0202ef0c();
int func_0203acf4();
int func_0203ad14();
int func_02044e80();
void func_02044ec4(void);
int func_0204fdac();

void func_020bae28(void);
u32 func_020badc0(void);
u32 func_020bae08(void);
int func_020bae18(void);
u32 func_020bae50(void);
u32 func_020bb298(void);
void func_020badd0(u32 arg0);
void func_020badec(u32 arg0);

/* forwards to `func_02044ec4` */
void func_020bae28(void) { func_02044ec4(); }

/* decompiler-derived */
u32 func_020badc0(void)
{
  int tmp1;
  tmp1 = func_0203ad14();
  return *(u32 *)(tmp1 + 0xe8);
}

/* decompiler-derived */
u32 func_020bae08(void)
{
  int tmp1;
  tmp1 = func_020badc0();
  return *(u32 *)(tmp1 + 0x68);
}

/* decompiler-derived */
int func_020bae18(void)
{
  int tmp1;
  tmp1 = func_02044e80();
  return tmp1 + 0x8c;
}

/* decompiler-derived */
u32 func_020bae50(void)
{
  func_0202ef0c();
  func_0203acf4();
  return 1;
}

/* decompiler-derived */
u32 func_020bb298(void)
{
  int tmp1;
  tmp1 = func_020badc0();
  func_0203acf4(*(u32 *)(tmp1 + 0x40));
  return 1;
}

/* decompiler-derived */
void func_020badd0(u32 arg0)
{
  int tmp1;
  tmp1 = func_020badc0();
  func_0204fdac(*(u32 *)(tmp1 + 0x54),arg0);
  return;
}

/* decompiler-derived */
void func_020badec(u32 arg0)
{
  int tmp1;
  tmp1 = func_020badc0();
  func_0204fdac(*(u32 *)(tmp1 + 0x60),arg0);
  return;
}
