/*
 * src/game/unit_020e8228.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

void func_02045c38(void);
int func_02057524();
void func_02057534(void);
int func_02057eb8();
int func_020a29a0();
int func_020e8e8c();

void func_020e93d4(void);
void func_020e8e60(void);
void func_020e8f68(void);
void func_020e8cd8(void);
void func_020e8e50(void);
void func_020e8e6c(void);
void func_020e8e7c(void);
void func_020e8eac(int arg0);

/* empty callback */
void func_020e93d4(void) { }

/* forwards to `func_02057534` */
void func_020e8e60(void) { func_02057534(); }

/* forwards to `func_02045c38` */
void func_020e8f68(void) { func_02045c38(); }

/* decompiler-derived */
void func_020e8cd8(void)
{
  func_020a29a0(0xffffffff);
  return;
}

/* decompiler-derived */
void func_020e8e50(void)
{
  func_02057524(4);
  return;
}

/* decompiler-derived */
void func_020e8e6c(void)
{
  func_02057eb8(2);
  return;
}

/* decompiler-derived */
void func_020e8e7c(void)
{
  func_02057eb8(0xffffffff);
  return;
}

/* decompiler-derived */
void func_020e8eac(int arg0)
{
  func_020e8e8c(arg0 + 8);
  return;
}
