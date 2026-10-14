/*
 * src/game/unit_0202e000.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_02140ac8[];
extern u32 data_0215dd24[];
int func_0202e0cc();
void func_0202e788(void);
int func_0205a9d0();

void func_0202e3e0(void);
u32 func_0202e0c0(void);
void func_0202e798(void);
void func_0202e0f4(u32 arg0);
u32 func_0202e104(void);
u32 func_0202e170(void);
void func_0202e0ac(void);
int func_0202e774(void);
int func_0202e8b8(void);
int func_0202e8f0(void);

/* empty callback */
void func_0202e3e0(void) { }

/* decompiler-derived */
u32 func_0202e0c0(void)
{
  return ((int)data_02140ac8);
}

/* forwards to `func_0202e788` */
void func_0202e798(void) { func_0202e788(); }

/* decompiler-derived */
void func_0202e0f4(u32 arg0)
{
  *data_0215dd24 = arg0;
  return;
}

/* decompiler-derived */
u32 func_0202e104(void)
{
  return *data_0215dd24;
}

/* decompiler-derived */
u32 func_0202e170(void)
{
  return *(u32 *)(((int)data_0215dd24) + 4);
}

/* decompiler-derived */
void func_0202e0ac(void)
{
  func_0205a9d0(0xa0);
  func_0202e0cc();
  return;
}

/* decompiler-derived */
int func_0202e774(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x98;
}

/* decompiler-derived */
int func_0202e8b8(void)
{
  int tmp1;
  tmp1 = func_0202e774();
  return tmp1 + 0xafc;
}

/* decompiler-derived */
int func_0202e8f0(void)
{
  return *(int *)(((int)data_0215dd24) + 4) + 0x90;
}
