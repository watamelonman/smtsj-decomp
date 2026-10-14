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
}

/* decompiler-derived */
void Unk0986ac_Unk_09895c(u32 arg0)
{
  func_020986d4(arg0,0);
}

/* decompiler-derived */
int Unk0986ac_Unk_0986ac(void)
{
  int value;
  value = Unk02e000_Unk_02e774();
  return value + 0x5c80;
}

/* decompiler-derived */
int Unk0986ac_Unk_0986c0(int arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  return value + (arg0 >> 3);
}



/* decompiler-derived */
void Unk0986ac_Unk_098990(u8 arg0)
{
  int value;
  value = Unk0986ac_Unk_0986ac();
  *(u8 *)(value + 0xd) = arg0;
}

int func_0202e0cc();
int func_0205b82c();
/* decompiler-derived */
u32 Unk0986ac_Unk_099300(void)
{
  func_0202e0cc();
  func_0205b82c(0xbf);
  return 1;
}

int func_02099d78();
int func_0209a114();
int func_0209a12c();
/* decompiler-derived */
u32 Unk0986ac_Unk_098918(void)
{
  int value1;
  int value2;
  u32 value3;
  value3 = 0;
  value1 = func_02099d78();
  if ((value1 != 0) && (value2 = func_0209a114(), value2 != 0)) {
    value3 = func_0209a12c(value1);
  }
  return value3;
}

