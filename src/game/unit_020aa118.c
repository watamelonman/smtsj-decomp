/*
 * src/game/unit_020aa118.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0204509c();
void func_020af8d8(void);

void func_020ae054(void);
void func_020af9e8(void);
void func_020ab454(void);
int func_020ab4b8(void);

/* empty callback */
void func_020ae054(void) { }

/* forwards to `func_020af8d8` */
void func_020af9e8(void) { func_020af8d8(); }

/* decompiler-derived */
void func_020ab454(void)
{
  int tmp1;
  tmp1 = func_0204509c();
  *(u32 *)(tmp1 + 0x18) = 0;
  return;
}

/* decompiler-derived */
int func_020ab4b8(void)
{
  int tmp1;
  tmp1 = func_0204509c();
  return *(int *)(tmp1 + 0x18) != 0;
}
