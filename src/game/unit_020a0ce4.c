/*
 * src/game/unit_020a0ce4.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

extern u32 data_02176afc[];
int func_020445d0();
int func_0204fde0();
int func_02052528();
int func_02053048();
int func_0205e590();
int func_020a1318();
int func_020b72a8();

void func_020a0e94(void);
void func_020a0eb4(void);
void func_020a0eb8(void);
u32 func_020a0d94(void);
void func_020a0e34(void);
void func_020a0e98(void);
int func_020a0ce4(int arg0);

/* empty callback */
void func_020a0e94(void) { }

/* empty callback */
void func_020a0eb4(void) { }

/* empty callback */
void func_020a0eb8(void) { }

/* decompiler-derived */
u32 func_020a0d94(void)
{
  return *data_02176afc;
}

/* decompiler-derived */
void func_020a0e34(void)
{
  func_02053048();
  func_020b72a8();
  return;
}

/* decompiler-derived */
void func_020a0e98(void)
{
  func_02052528(0xffffffff);
  func_0205e590(0);
  func_020a1318();
  return;
}

/* decompiler-derived */
int func_020a0ce4(int arg0)
{
  int tmp1;
  func_020445d0(0,0);
  tmp1 = func_0204fde0();
  return tmp1 + arg0 * 0x20;
}
