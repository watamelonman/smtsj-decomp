/*
 * src/game/unit_020cb32c.c: matched functions (see docs). Bodies marked 'decompiler-derived' were
 * lifted from Ghidra output and cleaned; field meanings are not known yet.
 */
typedef unsigned int u32; typedef signed int s32; typedef unsigned short u16; typedef signed short s16;
typedef unsigned char u8; typedef signed char s8; typedef unsigned long long u64; typedef signed long long s64;
#define FIELD(T, p, off) (*(T *)((u8 *)(p) + (off)))

int func_0205e484();
int func_020cb3dc();
int func_020cb4e4();
int func_020cb564();
int func_02122a78();
int func_02122aa0();
int Unk1241ec_Unk_1241ec();
int Unk1241ec_Unk_124214();
int Unk1241ec_Thunk_02124338();
int func_02124258();

void Unk0cb32c_Nop_0cba74(void);
void Unk0cb32c_Nop_0cccc0(void);
void Unk0cb32c_Unk_0cb35c(u32 arg0);
void Unk0cb32c_Unk_0cb57c(u32 arg0);
u32 Unk0cb32c_Unk_0cb32c(void);
u32 Unk0cb32c_Unk_0cb344(void);
void Unk0cb32c_Unk_0cb54c(void);

/* empty callback */
void Unk0cb32c_Nop_0cba74(void) { }

/* empty callback */
void Unk0cb32c_Nop_0cccc0(void) { }

/* decompiler-derived */
void Unk0cb32c_Unk_0cb35c(u32 arg0)
{
  func_0205e484(arg0,0x1e);
}

/* decompiler-derived */
void Unk0cb32c_Unk_0cb57c(u32 arg0)
{
  func_020cb564(arg0,0);
}

/* decompiler-derived */
u32 Unk0cb32c_Unk_0cb32c(void)
{
  func_02122a78();
  Unk1241ec_Thunk_02124338();
  Unk1241ec_Unk_1241ec();
  return 1;
}

/* decompiler-derived */
u32 Unk0cb32c_Unk_0cb344(void)
{
  Unk1241ec_Unk_124214();
  func_02124258();
  func_02122aa0();
  return 1;
}

/* decompiler-derived */
void Unk0cb32c_Unk_0cb54c(void)
{
  u8 value;
  value = func_020cb3dc();
  func_020cb4e4(value,0);
}


int func_020cca80();
/* decompiler-derived */
void func_020ccaa8(int *arg0,int arg1)
{
  if (arg1 == 2) {
    func_020cca80();
  }
  *arg0 = arg1;
  return;
}

int func_020956c8();
int func_020bc9b4();
int func_020de870();
/* decompiler-derived */
void func_020cba78(void)
{
  int tmp1;
  tmp1 = Unk0de678_Get_data_021508d4();
  if (tmp1 == 0) {
    func_020bc9b4(0xf,0);
    Unk0cb32c_Unk_0cb344();
  }
  func_020de870();
  func_020956c8();
  return;
}
