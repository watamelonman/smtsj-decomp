/*
 * src/game/unit_0205ae50.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u8 data_0216a184[];
int func_02053000();
int func_0205ad9c();
int func_0205ae60();
int func_0205b36c();

void func_0205b228(int arg0);
void func_0205ae50(void);
void func_0205b388(void);
void func_0205afd8(u32 arg0);
int func_0205b358(int arg0);
u32 func_0205af3c(int arg0);

/* decompiler-derived */
void func_0205b228(int arg0)
{
  *(u8 *)(arg0 + 0x59) = 1;
  return;
}

/* decompiler-derived */
void func_0205ae50(void)
{
  func_0205ad9c();
  func_0205ae60();
  return;
}

/* decompiler-derived */
void func_0205b388(void)
{
  func_0205ad9c();
  func_0205b36c();
  return;
}

/* decompiler-derived */
void func_0205afd8(u32 arg0)
{
  *(u32 *)(((int)data_0216a184) + 0x5a8) = arg0 & 0xfffffffc;
  return;
}

/* decompiler-derived */
int func_0205b358(int arg0)
{
  return *(char *)(arg0 + 0x59) != '\0';
}

/* decompiler-derived */
u32 func_0205af3c(int arg0)
{
  func_02053000(*(u32 *)(arg0 + 0x10));
  *(u32 *)(arg0 + 0x10) = 0;
  *(u32 *)(arg0 + 8) = 0;
  *(u32 *)(arg0 + 0xc) = 0;
  return 1;
}
