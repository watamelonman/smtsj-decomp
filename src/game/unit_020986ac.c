/*
 * src/game/unit_020986ac.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int Unk02e000_Unk_02e774();
int func_020986d4();
void func_02098714(void);

void Unk0986ac_Nop_099230(void);
int Unk0986ac_Unk_098978(int arg0);
void Unk0986ac_Thunk_02098714(void);
void Unk0986ac_Unk_09894c(u32 arg0);
void Unk0986ac_Unk_09895c(u32 arg0);
int Unk0986ac_Unk_0986ac(void);
int Unk0986ac_Unk_0986c0(int arg0);

/* empty callback */
void Unk0986ac_Nop_099230(void) { }

/* decompiler-derived */
int Unk0986ac_Unk_098978(int arg0)
{
  return arg0 + -0x6f;
}

/* forwards to `func_02098714` */
void Unk0986ac_Thunk_02098714(void) { func_02098714(); }

/* decompiler-derived */
void Unk0986ac_Unk_09894c(u32 arg0)
{
  func_020986d4(arg0,1);
  return;
}

/* decompiler-derived */
void Unk0986ac_Unk_09895c(u32 arg0)
{
  func_020986d4(arg0,0);
  return;
}

/* decompiler-derived */
int Unk0986ac_Unk_0986ac(void)
{
  int tmp1;
  tmp1 = Unk02e000_Unk_02e774();
  return tmp1 + 0x5c80;
}

/* decompiler-derived */
int Unk0986ac_Unk_0986c0(int arg0)
{
  int tmp1;
  tmp1 = Unk0986ac_Unk_0986ac();
  return tmp1 + (arg0 >> 3);
}
