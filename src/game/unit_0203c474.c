/*
 * src/game/unit_0203c474.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0202df00();
int func_0202df88();
int func_0203ac00();
int func_0203ad14();
int func_0205e590();
int func_020a269c();
int func_020a273c();
int func_020a277c();
int func_020a27e0();
int func_020a2820();
int func_020a2884();
int func_020a28b0();
int func_020a28e8();
int func_020a2920();

u32 func_0203c4c8(void);
u32 func_0203c4dc(void);
u32 func_0203c4f0(void);
u32 func_0203c504(void);
u32 func_0203c518(void);
u32 func_0203c52c(void);
u32 func_0203c558(void);
u32 func_0203c5a4(void);
u32 func_0203c5b8(void);
u32 func_0203c5cc(void);
u32 func_0203c5e0(void);
u32 func_0203c5f4(void);
u32 func_0203c540(void);
u32 func_0203c56c(void);
u32 func_0203c588(void);
u32 func_0203c4a0(void);

/* decompiler-derived */
u32 func_0203c4c8(void)
{
  func_020a2884(1);
  return 1;
}

/* decompiler-derived */
u32 func_0203c4dc(void)
{
  func_020a2884(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c4f0(void)
{
  func_020a2820(1);
  return 1;
}

/* decompiler-derived */
u32 func_0203c504(void)
{
  func_020a2820(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c518(void)
{
  func_020a27e0(1);
  return 1;
}

/* decompiler-derived */
u32 func_0203c52c(void)
{
  func_020a27e0(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c558(void)
{
  func_020a28e8(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c5a4(void)
{
  func_020a269c(1);
  return 1;
}

/* decompiler-derived */
u32 func_0203c5b8(void)
{
  func_020a269c(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c5cc(void)
{
  func_020a273c(1);
  return 1;
}

/* decompiler-derived */
u32 func_0203c5e0(void)
{
  func_020a273c(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c5f4(void)
{
  func_020a28b0(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c540(void)
{
  func_020a28e8(1);
  func_0202df88();
  return 3;
}

/* decompiler-derived */
u32 func_0203c56c(void)
{
  func_020a277c(1);
  func_020a2920(1);
  return 1;
}

/* decompiler-derived */
u32 func_0203c588(void)
{
  func_020a277c(0);
  func_020a2920(0);
  return 1;
}

/* decompiler-derived */
u32 func_0203c4a0(void)
{
  int tmp1;
  func_0203ac00(0);
  func_0205e590();
  tmp1 = func_0203ad14();
  func_0202df00(*(u32 *)(tmp1 + 0xe8),1);
  return 3;
}
