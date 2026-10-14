/*
 * src/game/unit_0203c474.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02dcfc_Unk_02df00();
int func_0202df88();
int func_0203ac00();
int func_0203ad14();
int func_0203ad24();
int func_0203ad98();
int func_0205e484();
int func_0205e590();
int func_02065544();
int func_0206569c();
int func_02065bc0();
int func_020a269c();
int func_020a273c();
int func_020a277c();
int func_020a27e0();
int func_020a2820();
int func_020a2884();
int func_020a28b0();
int ScanVisor_Thunk_020fc6b8();
int func_020a2920();

u32 Unk03c474_Unk_03c4c8(void);
u32 Unk03c474_Unk_03c4dc(void);
u32 Unk03c474_Unk_03c4f0(void);
u32 Unk03c474_Unk_03c504(void);
u32 Unk03c474_Unk_03c518(void);
u32 Unk03c474_Unk_03c52c(void);
u32 Unk03c474_Unk_03c558(void);
u32 Unk03c474_Unk_03c5a4(void);
u32 Unk03c474_Unk_03c5b8(void);
u32 Unk03c474_Unk_03c5cc(void);
u32 Unk03c474_Unk_03c5e0(void);
u32 Unk03c474_Unk_03c5f4(void);
u32 Unk03c474_Unk_03c540(void);
u32 Unk03c474_Unk_03c56c(void);
u32 Unk03c474_Unk_03c588(void);
u32 Unk03c474_Unk_03c4a0(void);
u32 Unk03c474_Unk_03c474(void);
u32 Unk03c474_Unk_03c638(void);

/* decompiler-derived */
u32 Unk03c474_Unk_03c4c8(void)
{
  func_020a2884(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c4dc(void)
{
  func_020a2884(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c4f0(void)
{
  func_020a2820(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c504(void)
{
  func_020a2820(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c518(void)
{
  func_020a27e0(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c52c(void)
{
  func_020a27e0(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c558(void)
{
  ScanVisor_Thunk_020fc6b8(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5a4(void)
{
  func_020a269c(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5b8(void)
{
  func_020a269c(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5cc(void)
{
  func_020a273c(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5e0(void)
{
  func_020a273c(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c5f4(void)
{
  func_020a28b0(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c540(void)
{
  ScanVisor_Thunk_020fc6b8(1);
  func_0202df88();
  return 3;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c56c(void)
{
  func_020a277c(1);
  func_020a2920(1);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c588(void)
{
  func_020a277c(0);
  func_020a2920(0);
  return 1;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c4a0(void)
{
  int tmp1;
  func_0203ac00(0);
  func_0205e590();
  tmp1 = func_0203ad14();
  Unk02dcfc_Unk_02df00(*(u32 *)(tmp1 + 0xe8),1);
  return 3;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c474(void)
{
  u32 tmp1;
  int tmp2;
  tmp1 = func_0203ac00(0);
  func_0205e484(tmp1,0);
  tmp2 = func_0203ad14();
  Unk02dcfc_Unk_02df00(*(u32 *)(tmp2 + 0xe8),1);
  return 3;
}

/* decompiler-derived */
u32 Unk03c474_Unk_03c638(void)
{
  u32 tmp1;
  int tmp2;
  int tmp3;
  tmp1 = func_0203ac00(0);
  tmp2 = func_0203ad14();
  tmp2 = *(int *)(tmp2 + 0xe8);
  if (*(int *)(tmp2 + 0x28) == 0) {
    func_0203ad24(tmp2);
    *(u32 *)(tmp2 + 0x28) = 1;
  }
  tmp1 = func_0203ad98(tmp2,tmp1);
  tmp3 = func_02065544();
  if (tmp3 == 0) {
    func_02065bc0();
  }
  func_0206569c(tmp1);
  *(u32 *)(tmp2 + 0x18) = 0x1c;
  return 3;
}
